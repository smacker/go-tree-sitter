package main

import (
	// Import necessary packages
	"archive/tar"
	"compress/gzip"
	"fmt"
	"io"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
)

// Constants for the Tree Sitter version and download URL
const (
	sitterVersion = "0.25.9"
	sitterURL     = "https://github.com/tree-sitter/tree-sitter/archive/refs/tags/v" + sitterVersion + ".tar.gz"
)

func main() {
	// Get the current working directory
	currentDir, err := os.Getwd()
	if err != nil {
		log.Fatalf("Error getting current directory: %v", err)
	}

	// Construct the directory path for the downloaded Tree Sitter files
	treeSitterDir := "tree-sitter-" + sitterVersion
	parentPath := filepath.Join(currentDir, "tmpts", treeSitterDir)

	// Download and extract the Tree Sitter source code
	if err := downloadAndExtractSitter(sitterURL, sitterVersion); err != nil {
		log.Fatalf("Error: %v", err)
	}

	// Copy necessary files to tmpts directory
	copyFiles(filepath.Join(parentPath, "lib", "include", "tree_sitter"), filepath.Join(currentDir, "tmpts"), "*.h")
	copyFiles(filepath.Join(parentPath, "lib", "src"), filepath.Join(currentDir, "tmpts"), "*.c")
	copyFiles(filepath.Join(parentPath, "lib", "src"), filepath.Join(currentDir, "tmpts"), "*.h")
	copyFiles(filepath.Join(parentPath, "lib", "src", "unicode"), filepath.Join(currentDir, "tmpts"), "*.h")
	copyFiles(filepath.Join(parentPath, "lib", "src", "portable"), filepath.Join(currentDir, "tmpts"), "*.h")

	// Remove the original extracted directory
	err = os.RemoveAll(parentPath)
	if err != nil {
		log.Fatalf("Error removing extracted treesitter directory: %v", err)
	}

	// Modify include paths in the copied files
	if err := modifyIncludePaths(filepath.Join(currentDir, "tmpts")); err != nil {
		log.Fatalf("Error modifying include paths: %v", err)
	}

	// Clean up unnecessary files
	cleanup(filepath.Join(currentDir, "tmpts"))

	// Copy and report files from tmpts to two levels up in the directory structure
	err = copyAndReportFiles(filepath.Join(currentDir, "tmpts"), filepath.Join(currentDir, "..", ".."))
	if err != nil {
		log.Fatalf("Error copying and reporting files: %v", err)
	}

	err = os.RemoveAll(filepath.Join(currentDir, "tmpts"))
	if err != nil {
		log.Fatalf("Error removing tmpts directory: %v", err)
	}

	fmt.Printf("\n\nDone!\n")
}

// Function to copy and report files from source to destination directory
func copyAndReportFiles(srcDir, dstDir string) error {
	// Walk through the source directory
	return filepath.Walk(srcDir, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		}
		if info.IsDir() {
			return nil
		}

		// Calculate relative file path and destination file path
		relPath, err := filepath.Rel(srcDir, path)
		if err != nil {
			return err
		}
		dstFilePath := filepath.Join(dstDir, relPath)

		// Check if file exists at destination and print appropriate message
		if _, err := os.Stat(dstFilePath); err == nil {
			fmt.Printf("%-39s %s\n", filepath.Base(dstFilePath), "[replaced]")
		} else if os.IsNotExist(err) {
			fmt.Printf("%-39s %s\n", filepath.Base(dstFilePath), "[new file]")
		}

		// Copy the file to destination
		return copyFile(path, dstFilePath)
	})
}

// Function to copy files matching a pattern from source to destination directory
func copyFiles(srcDir, dstDir, pattern string) {
	files, err := ioutil.ReadDir(srcDir)
	if err != nil {
		log.Fatal(err)
	}

	// Iterate through files and copy if they match the pattern
	for _, file := range files {
		if matched, _ := filepath.Match(pattern, file.Name()); matched {
			srcFilePath := filepath.Join(srcDir, file.Name())
			dstFilePath := filepath.Join(dstDir, file.Name())
			copyFile(srcFilePath, dstFilePath)
		}
	}
}

// Function to copy a single file from source to destination
func copyFile(src, dst string) error {
	// Read the file from source
	input, err := ioutil.ReadFile(src)
	if err != nil {
		return err
	}

	// Write the file to destination
	err = ioutil.WriteFile(dst, input, 0o644)
	if err != nil {
		return err
	}
	return nil
}

// Function to modify include paths in .c and .h files
func modifyIncludePaths(path string) error {
	// Walk through the directory and modify files
	return filepath.Walk(path, func(filePath string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		}

		// Skip directories and non .c/.h files
		if info.IsDir() || (filepath.Ext(filePath) != ".c" && filepath.Ext(filePath) != ".h") {
			return nil
		}

		// Read the file content
		content, err := os.ReadFile(filePath)
		if err != nil {
			return err
		}

		// Modify the content and write back
		modifiedContent := strings.ReplaceAll(string(content), `"tree_sitter/`, `"`)
		modifiedContent = strings.ReplaceAll(modifiedContent, `"unicode/`, `"`)
		modifiedContent = strings.ReplaceAll(modifiedContent, `"portable/`, `"`)
		return os.WriteFile(filePath, []byte(modifiedContent), info.Mode())
	})
}

// Function to download and extract Tree Sitter from the given URL
func downloadAndExtractSitter(url, version string) error {
	// Send HTTP request to download the file
	resp, err := http.Get(url)
	if err != nil {
		return err
	}
	defer resp.Body.Close()

	// Prepare gzip reader
	gzr, err := gzip.NewReader(resp.Body)
	if err != nil {
		return err
	}
	defer gzr.Close()

	// Prepare tar reader and extract files
	tr := tar.NewReader(gzr)
	for {
		header, err := tr.Next()
		if err == io.EOF {
			break
		}
		if err != nil {
			return err
		}

		// Process files within specified directories
		if !strings.HasPrefix(header.Name, "tree-sitter-"+version+"/lib/src") && !strings.HasPrefix(header.Name, "tree-sitter-"+version+"/lib/include") {
			continue
		}

		relPath := strings.TrimPrefix(header.Name, version+"/")
		target := filepath.Join("tmpts", relPath)

		// Create directories and files as needed
		switch header.Typeflag {
		case tar.TypeDir:
			if err := os.MkdirAll(target, 0o755); err != nil {
				return err
			}
		case tar.TypeReg:
			outFile, err := os.Create(target)
			if err != nil {
				return err
			}
			if _, err := io.Copy(outFile, tr); err != nil {
				outFile.Close()
				return err
			}
			outFile.Close()
		}
	}

	return nil
}

// Function to clean up the specified directory
func cleanup(path string) {
	// Walk through the directory and remove unnecessary files
	err := filepath.Walk(path, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		}
		if info.IsDir() {
			return nil
		}
		if filepath.Ext(path) != ".h" && filepath.Ext(path) != ".c" || filepath.Base(path) == "lib.c" {
			return os.Remove(path)
		}
		return nil
	})
	if err != nil {
		// Handle the error
	}
}

// Function to run a command and pipe its output
func runCmd(name string, args ...string) error {
	cmd := exec.Command(name, args...)
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	return cmd.Run()
}
