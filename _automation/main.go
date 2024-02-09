//go:build tools
// +build tools

package main

import (
	"archive/zip"
	"bytes"
	"context"
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"io/ioutil"
	"net/http"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
	"sync"
	"text/tabwriter"
)

var defaultLogger *Logger

func init() {
	defaultLogger = NewLogger()
}

const grammarsJson = "./_automation/grammars.json"

type GrammarVersion struct {
	Reference string `json:"reference"`
	Revision  string `json:"revision"`
}

type Grammar struct {
	Language string   `json:"language"`
	URL      string   `json:"url"`
	Files    []string `json:"files"`
	*GrammarVersion
}

func (g *Grammar) ContentURL() string {
	return fmt.Sprintf(
		"https://raw.githubusercontent.com/%s",
		strings.TrimPrefix(g.URL, "https://github.com/"),
	)
}

func (g *Grammar) FetchNewVersion() *GrammarVersion {

	//attempt to retrieve tag from latest RELEASE in this grammar's repo
	tag, rev, err := fetchLatestReleaseTagAndRev(g.URL)
	if err == nil {
		if tag != g.Reference {
			return &GrammarVersion{
				Reference: tag,
				Revision:  rev,
			}
		}
	} else {

		//error retrieving tag from latest RELEASE or there are not any.
		// fallback to fetching the latest commit
		rev := fetchLastCommit(g.URL, g.Reference)
		if rev != g.Revision {
			return &GrammarVersion{
				Reference: g.Reference,
				Revision:  rev,
			}
		}
	}
	return nil
}

func root(args []string) error {
	if len(args) < 1 {
		return fmt.Errorf("sub-command expected")
	}

	ctx := context.Background()
	s := NewUpdateService()

	switch args[0] {
	case "check-updates":
		fs := flag.NewFlagSet("check-updates", flag.ExitOnError)
		flagsParse(fs, args[1:])

		s.CheckUpdates(ctx)
	case "update":
		if len(args) < 2 {
			return fmt.Errorf("language argument is missing")
		}

		fs := flag.NewFlagSet("update", flag.ExitOnError)
		force := fs.Bool("force", false, "re-download grammar even if revision is the same")
		flagsParse(fs, args[2:])

		s.Update(ctx, args[1], *force)
	case "update-all":
		fs := flag.NewFlagSet("update-all", flag.ExitOnError)
		flagsParse(fs, args[1:])

		s.UpdateAll(ctx)
	case "run-tests":
		return runTests(ctx)
	default:
		return fmt.Errorf("unknown sub-command")
	}

	return nil
}

func main() {
	if err := root(os.Args[1:]); err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
}

func runTests(ctx context.Context) error {
	logger := getLogger(ctx)

	curDir, _ := os.Getwd()
	searchDir := filepath.Join(curDir, "*")
	// Search for all binding_test.go files in subdirectories.
	pattern := filepath.Join(searchDir, "binding_test.go")
	files, err := filepath.Glob(pattern)
	if err != nil {
		logAndExit(logger, "Failed to find test files: "+err.Error())
	}
	if len(files) == 0 {
		logAndExit(logger, "No binding_test.go files found")
	}

	for _, file := range files {
		// Run `go test -v` for each found test file.
		cmd := exec.Command("go", "test", "-v", file)
		cmd.Dir = filepath.Dir(file) // Set working directory to the test file's directory.
		output, err := cmd.CombinedOutput()
		if err != nil {
			logger.Error(fmt.Sprintf("Tests failed for %s: %s", file, err.Error()))
			fmt.Printf("%s\n", string(output))
			continue
		}
		fmt.Printf("Tests passed for %s\n", file)
		fmt.Printf("%s\n", string(output))
	}
	return nil
}

type UpdateService struct {
	grammars    []*Grammar
	grammarsMap map[string]*Grammar
}

func NewUpdateService() *UpdateService {
	b, err := os.ReadFile(grammarsJson)
	if err != nil {
		logAndExit(defaultLogger, err.Error(), "file", grammarsJson)
	}

	var grammars []*Grammar
	err = json.Unmarshal(b, &grammars)
	if err != nil {
		logAndExit(defaultLogger, fmt.Sprintf("unmarshaling grammars file error: %w", err), "file", grammarsJson)
	}

	grammarsMap := make(map[string]*Grammar, len(grammars))
	for _, g := range grammars {
		grammarsMap[g.Language] = g
	}

	return &UpdateService{grammars, grammarsMap}
}

func (s *UpdateService) CheckUpdates(ctx context.Context) {
	newVersions := s.fetchNewVersions()
	w := tabwriter.NewWriter(os.Stdout, 0, 0, 3, ' ', 0)
	for i, g := range s.grammars {
		nextVersion := newVersions[i]
		fmt.Fprintf(w, "%s\t%s\t", g.Language, g.Reference)
		if nextVersion == nil {
			fmt.Fprintf(w, "(up-to-date)")
		} else if g.Reference == nextVersion.Reference {
			fmt.Fprintf(w, "(update available: %s -> %s)", g.Revision, nextVersion.Revision)
		} else {
			fmt.Fprintf(w, "(update available: %s -> %s)", g.Reference, nextVersion.Reference)
		}
		fmt.Fprintln(w)
	}
	w.Flush()
}

func (s *UpdateService) fetchNewVersions() []*GrammarVersion {
	results := make([]*GrammarVersion, len(s.grammars))
	wg := sync.WaitGroup{}
	wg.Add(len(s.grammars))

	for i, g := range s.grammars {
		go func(i int, g *Grammar) {
			defer wg.Done()
			results[i] = g.FetchNewVersion()
		}(i, g)
	}

	wg.Wait()

	return results
}

func (s *UpdateService) Update(ctx context.Context, language string, force bool) {
	logger := getLogger(ctx).With("language", language)

	grammar, ok := s.grammarsMap[language]
	if !ok {
		logAndExit(logger, "grammar not found")
	}

	logger = logger.With("reference", grammar.Reference)
	ctx = context.WithValue(ctx, loggerCtxKey, logger)

	v := grammar.FetchNewVersion()
	if v == nil {
		if !force {
			logAndExit(logger, "grammar is not outdated")
		} else {
			logger.Warn("re-downloading up-to-date grammar")
		}
	} else {
		grammar.Reference = v.Reference
		grammar.Revision = v.Revision
	}

	s.downloadGrammar(ctx, grammar)
	s.writeGrammarsFile(ctx)
}

func (s *UpdateService) UpdateAll(ctx context.Context) {
	newVersions := s.fetchNewVersions()

	wg := sync.WaitGroup{}
	for i, g := range s.grammars {
		v := newVersions[i]
		if v == nil {
			continue
		}

		wg.Add(1)
		g.Reference = v.Reference
		g.Revision = v.Revision

		go func(g *Grammar) {
			defer wg.Done()

			s.downloadGrammar(ctx, g)
		}(g)
	}

	wg.Wait()

	s.writeGrammarsFile(ctx)
}

func (s *UpdateService) downloadGrammar(ctx context.Context, g *Grammar) {
	logger := getLogger(ctx).With("language", g.Language, "reference", g.Reference)
	logger.Info("downloading")

	ctx = context.WithValue(ctx, loggerCtxKey, logger)
	s.makeDir(ctx, g.Language)

	switch g.Language {
	case "ocaml":
		s.downloadOcaml(ctx, g)
	case "typescript":
		s.downloadTypescript(ctx, g)
	case "yaml":
		s.downloadYaml(ctx, g)
	case "swift":
		s.downloadSwift(ctx, g)
	default:
		s.defaultGrammarDownload(ctx, g)
	}

	logger.Info("successfully downloaded")
}

func (s *UpdateService) makeDir(ctx context.Context, path string) {
	err := os.MkdirAll(path, 0755)
	if err != nil {
		logAndExit(getLogger(ctx), err.Error(), "path", path)
	}
}

func (s *UpdateService) defaultGrammarDownload(ctx context.Context, g *Grammar) {
	url := g.ContentURL()

	s.downloadFile(
		ctx,
		fmt.Sprintf("%s/%s/src/tree_sitter/parser.h", url, g.Revision),
		fmt.Sprintf("%s/parser.h", g.Language),
		nil,
	)

	for _, f := range g.Files {
		s.downloadFile(
			ctx,
			fmt.Sprintf("%s/%s/src/%s", url, g.Revision, f),
			fmt.Sprintf("%s/%s", g.Language, f),
			map[string]string{
				`<tree_sitter/parser.h>`: `"parser.h"`,
				`"tree_sitter/parser.h"`: `"parser.h"`,
			},
		)
	}
}

func (s *UpdateService) downloadFile(ctx context.Context, url, toPath string, replaceMap map[string]string) {
	b := s.fetchFile(ctx, url)

	for old, new := range replaceMap {
		b = bytes.ReplaceAll(b, []byte(old), []byte(new))
	}

	err := os.WriteFile(toPath, b, 0644)
	if err != nil {
		logAndExit(getLogger(ctx), err.Error(), "path", toPath)
	}
}

func (s *UpdateService) fetchFile(ctx context.Context, url string) []byte {
	logger := getLogger(ctx).With("url", url)
	logger.Debug("fetching")

	resp, err := http.Get(url)
	if err != nil {
		logAndExit(logger, err.Error())
	}
	defer resp.Body.Close()

	if resp.StatusCode != 200 {
		logAndExit(logger, "incorrect response status code", "statusCode", resp.StatusCode)
	}

	b, err := io.ReadAll(resp.Body)
	if err != nil {
		logAndExit(logger, err.Error())
	}
	return b
}

func (s *UpdateService) writeGrammarsFile(ctx context.Context) {
	b, err := json.MarshalIndent(s.grammars, "", "  ")
	if err != nil {
		logAndExit(getLogger(ctx), fmt.Sprintf("marshaling grammars file error: %w", err))
	}
	err = os.WriteFile(grammarsJson, b, 0644)
	if err != nil {
		logAndExit(getLogger(ctx), err.Error(), "file", grammarsJson)
	}
}

// ocaml is special since its folder structure is different from the other ones
func (s *UpdateService) downloadOcaml(ctx context.Context, g *Grammar) {
	fileMapping := map[string]string{
		"parser.c":   "ocaml/src/parser.c",
		"scanner.cc": "ocaml/src/scanner.cc",
		"scanner.h":  "common/scanner.h",
	}

	url := g.ContentURL()
	s.downloadFile(
		ctx,
		fmt.Sprintf("%s/%s/ocaml/src/tree_sitter/parser.h", url, g.Revision),
		fmt.Sprintf("%s/parser.h", g.Language),
		nil,
	)

	for _, f := range g.Files {
		fp, ok := fileMapping[f]
		if !ok {
			logAndExit(getLogger(ctx), "mapping for file not found", "file", f)
		}

		s.downloadFile(
			ctx,
			fmt.Sprintf("%s/%s/%s", url, g.Revision, fp),
			fmt.Sprintf("%s/%s", g.Language, f),
			map[string]string{
				`<tree_sitter/parser.h>`:   `"parser.h"`,
				`"../../common/scanner.h"`: `"scanner.h"`,
			},
		)
	}
}

// typescript is special as it contains 2 different grammars
func (s *UpdateService) downloadTypescript(ctx context.Context, g *Grammar) {
	url := g.ContentURL()

	langs := []string{"typescript", "tsx"}
	for _, lang := range langs {
		s.makeDir(ctx, fmt.Sprintf("%s/%s", g.Language, lang))

		s.downloadFile(
			ctx,
			fmt.Sprintf("%s/%s/common/scanner.h", url, g.Revision),
			fmt.Sprintf("%s/%s/scanner.h", g.Language, lang),
			map[string]string{
				`<tree_sitter/parser.h>`: `"parser.h"`,
			},
		)
		s.downloadFile(
			ctx,
			fmt.Sprintf("%s/%s/%s/src/tree_sitter/parser.h", url, g.Revision, lang),
			fmt.Sprintf("%s/%s/parser.h", g.Language, lang),
			nil,
		)

		for _, f := range g.Files {
			s.downloadFile(
				ctx,
				fmt.Sprintf("%s/%s/%s/src/%s", url, g.Revision, lang, f),
				fmt.Sprintf("%s/%s/%s", g.Language, lang, f),
				map[string]string{
					`<tree_sitter/parser.h>`:   `"parser.h"`,
					`"../../common/scanner.h"`: `"scanner.h"`,
				},
			)
		}
	}
}

// Add this function to your UpdateService methods
func (s *UpdateService) downloadSwift(ctx context.Context, g *Grammar) {
	logger := getLogger(ctx).With("language", "swift")
	logger.Info("downloading Swift parser")

	// Fetch the latest release information
	//latestReleaseURL := fmt.Sprintf("%s/releases/latest", g.URL)
	tag, _, err := fetchLatestReleaseTagAndRev(g.URL)

	if err != nil {
		logAndExit(logger, "Failed to get latest tag: "+err.Error())
	}

	// Construct the download URL for generated-src.zip from the latest release
	downloadURL := fmt.Sprintf("%s/releases/download/%s/generated-parser-src.zip", g.URL, tag)
	logger.Info("Download URL: " + downloadURL)

	// Download the zip file
	zipResp, err := http.Get(downloadURL)
	if err != nil {
		logAndExit(logger, "Failed to download generated-src.zip: "+err.Error())
	}
	defer zipResp.Body.Close()

	zipFile, err := os.CreateTemp("", "generated-parser-src-*.zip")
	if err != nil {
		logAndExit(logger, "Failed to create temp file for zip: "+err.Error())
	}
	defer os.Remove(zipFile.Name()) // Clean up

	_, err = io.Copy(zipFile, zipResp.Body)
	if err != nil {
		logAndExit(logger, "Failed to save generated-src.zip: "+err.Error())
	}

	// Unzip the downloaded file
	if err := unzip(zipFile.Name(), "./swift"); err != nil {
		logAndExit(logger, "Failed to unzip generated-src.zip: "+err.Error())
	}

	// Additional file processing
	swiftParserDir := "./swift"
	treeSitterDir := filepath.Join(swiftParserDir, "tree_sitter")

	// Move .c and .h files to the swift/ directory
	if err := filepath.Walk(treeSitterDir, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		}
		if strings.HasSuffix(info.Name(), ".c") || strings.HasSuffix(info.Name(), ".h") {
			destPath := filepath.Join(swiftParserDir, info.Name())
			return os.Rename(path, destPath)
		}
		return nil
	}); err != nil {
		logAndExit(logger, "Failed to move files: "+err.Error())
	}

	// Fix include paths in source files
	if err := fixIncludePaths(swiftParserDir); err != nil {
		logAndExit(logger, "Failed to fix include paths: "+err.Error())
	}

	os.RemoveAll(treeSitterDir)
	grammarsJson := filepath.Join(swiftParserDir, "grammar.json")
	nodeTypesJson := filepath.Join(swiftParserDir, "node-types.json")
	os.Remove(grammarsJson)
	os.Remove(nodeTypesJson)

	logger.Info("Swift parser downloaded and prepared successfully.")
}

// fixIncludePaths updates include paths in .c and .h files within the specified directory.
func fixIncludePaths(dir string) error {
	files, err := ioutil.ReadDir(dir)
	if err != nil {
		return err
	}

	for _, file := range files {
		if strings.HasSuffix(file.Name(), ".c") || strings.HasSuffix(file.Name(), ".h") {
			filePath := filepath.Join(dir, file.Name())
			if err := updateFileContents(filePath); err != nil {
				return err
			}
		}
	}
	return nil
}

// updateFileContents reads a file and replaces include directives with corrected paths.
func updateFileContents(filePath string) error {
	input, err := ioutil.ReadFile(filePath)
	if err != nil {
		return err
	}

	lines := strings.Split(string(input), "\n")
	for i, line := range lines {
		if strings.Contains(line, `<tree_sitter/`) {
			lines[i] = strings.Replace(line, `<tree_sitter/`, `<`, 1)
		} else if strings.Contains(line, `"tree_sitter/`) {
			lines[i] = strings.Replace(line, `"tree_sitter/`, `"`, 1)
		}
	}
	output := strings.Join(lines, "\n")
	return ioutil.WriteFile(filePath, []byte(output), 0644)
}

// unzip extracts the contents of a zip file to a specified destination directory
func unzip(src, dest string) error {
	r, err := zip.OpenReader(src)
	if err != nil {
		return err
	}
	defer r.Close()

	os.MkdirAll(dest, 0755)

	for _, f := range r.File {
		fpath := filepath.Join(dest, f.Name)

		// Check for ZipSlip (Directory traversal)
		if !strings.HasPrefix(fpath, filepath.Clean(dest)+string(os.PathSeparator)) {
			return fmt.Errorf("%s: illegal file path", fpath)
		}

		if f.FileInfo().IsDir() {
			os.MkdirAll(fpath, os.ModePerm)
			continue
		}

		if err := os.MkdirAll(filepath.Dir(fpath), 0755); err != nil {
			return err
		}

		outFile, err := os.OpenFile(fpath, os.O_WRONLY|os.O_CREATE|os.O_TRUNC, f.Mode())
		if err != nil {
			return err
		}

		rc, err := f.Open()
		if err != nil {
			return err
		}

		_, err = io.Copy(outFile, rc)

		// Close the file without deferring to ensure we can handle the error
		outFile.Close()
		rc.Close()

		if err != nil {
			return err
		}
	}
	return nil
}

// for yaml grammar scanner.cc includes schema.generated.cc file
// it causes cgo to compile schema.generated.cc twice and throw duplicate symbols error
func (s *UpdateService) downloadYaml(ctx context.Context, g *Grammar) {
	s.defaultGrammarDownload(ctx, g)

	f1 := fmt.Sprintf("%s/schema.generated.cc", g.Language)
	f2 := fmt.Sprintf("%s/scanner.cc", g.Language)

	f1b, _ := os.ReadFile(f1)
	f2b, _ := os.ReadFile(f2)
	os.Remove(f1)

	// combine both files into one
	b := bytes.Join([][]byte{
		[]byte(`#include "parser.h"`),
		f1b,
		f2b,
	}, []byte("\n"))
	// remove include expression
	b = bytes.ReplaceAll(b, []byte(`#include "./schema.generated.cc"`), []byte(""))

	_ = os.WriteFile(fmt.Sprintf("%s/scanner.cc", g.Language), b, 0644)
}

func logAndExit(logger *Logger, msg string, args ...interface{}) {
	logger.Error(msg, args...)
	os.Exit(1)
}

// Git
// // fetchLastTag fetches the latest tag and its corresponding revision (commit SHA) from the specified repository.
// func fetchLastTag(repository string) (string, string, error) {
// 	// Execute the 'git ls-remote' command to list remote tags, sorted by version number.
// 	cmd := exec.Command("git", "ls-remote", "--tags", "--sort", "-v:refname", repository) //, "v*")
// 	b, err := cmd.Output()
// 	if err != nil {
// 		// Return the error to the caller.
// 		return "", "", fmt.Errorf("failed to execute git command: %w", err)
// 	}

// 	// Split the output to get the first line, which contains the latest tag.
// 	lines := strings.Split(string(b), "\n")
// 	if len(lines) == 0 || lines[0] == "" {
// 		// Return an error if the output is unexpectedly empty.
// 		return "", "", fmt.Errorf("no tags found in the repository")
// 	}

// 	line := lines[0]
// 	parts := strings.Split(line, "\t")
// 	if len(parts) < 2 {
// 		// Return an error if the line format is not as expected.
// 		return "", "", fmt.Errorf("unexpected format of git command output")
// 	}

// 	// Extract the tag name, trimming the "refs/tags/" prefix and any "^{}" suffix.
// 	refParts := strings.Split(parts[1], "/")
// 	if len(refParts) < 3 {
// 		// Return an error if the ref path format is not as expected.
// 		return "", "", fmt.Errorf("unexpected format of git ref path")
// 	}
// 	tag := strings.TrimRight(refParts[len(refParts)-1], "^{}")

// 	// The revision (commit SHA) is the first part of the line.
// 	rev := parts[0]

// 	return tag, rev, nil
// }

// fetchLatestReleaseTagAndRev fetches the tag name and revision (commit SHA) of the latest release.
func fetchLatestReleaseTagAndRev(repository string) (string, string, error) {
	// Fetch tags from the remote repository, sorted by version number.
	cmd := exec.Command("git", "ls-remote", "--tags", "--sort=-v:refname", repository)

	// Execute the command and get the output.
	b, err := cmd.Output()
	if err != nil {
		// Log the error and exit if the command execution fails.
		logAndExit(defaultLogger, err.Error())
		return "", "", err
	}

	// Split the output into lines.
	lines := strings.Split(string(b), "\n")

	// Iterate over the lines to find the first valid tag.
	for _, line := range lines {
		if line == "" {
			continue // Skip empty lines.
		}

		// Split each line into parts (SHA and ref path).
		parts := strings.Split(line, "\t")
		if len(parts) < 2 {
			continue // Skip if the line does not have both parts.
		}

		// Extract the tag name, trimming the "refs/tags/" prefix and any potential suffix.
		tag := strings.TrimPrefix(parts[1], "refs/tags/")
		tag = strings.TrimRight(tag, "^{}")

		// Extract the revision (commit SHA).
		rev := parts[0]

		//accomodate swift grammar -- a latest release with this suffix does not contain generated files we need
		if strings.Contains(repository, "-swift") && (strings.HasSuffix(tag, "-with-generated-files")) {
			continue
		}
		return tag, rev, nil
	}

	// Return an error if no valid tags were found.
	return "", "", fmt.Errorf("no tags found in the repository")
}

func fetchLastCommit(repository, branch string) string {
	cmd := exec.Command("git", "ls-remote", "--heads", repository, fmt.Sprint("refs/heads/", branch))
	b, err := cmd.Output()
	if err != nil {
		logAndExit(defaultLogger, err.Error())
	}

	return strings.Split(string(b), "\t")[0]
}

// Logging

type loggerCtxType string

const loggerCtxKey loggerCtxType = "loggerCtx"

func getLogger(ctx context.Context) *Logger {
	v := ctx.Value(loggerCtxKey)
	if v == nil {
		return defaultLogger
	}
	logger, ok := v.(*Logger)
	if !ok {
		return defaultLogger
	}
	return logger
}

// minimal structured logger to avoid external dependencies
// implements subset of golang.org/x/exp/slog interface
type Logger struct {
	level   Level
	records map[string]interface{}
}

func NewLogger() *Logger {
	return &Logger{LevelInfo, make(map[string]interface{})}
}

type Level int

const (
	LevelDebug Level = -4
	LevelInfo  Level = 0
	LevelWarn  Level = 4
	LevelError Level = 8
)

func (l *Logger) With(args ...interface{}) *Logger {
	records := make(map[string]interface{})
	for k, v := range l.records {
		records[k] = v
	}

	i := 0
	for i < len(args)-1 {
		records[args[i].(string)] = args[i+1]
		i += 2
	}

	return &Logger{l.level, records}
}

func (l *Logger) Error(msg string, args ...interface{}) {
	l.log(LevelError, msg, args...)
}

func (l *Logger) Warn(msg string, args ...interface{}) {
	l.log(LevelWarn, msg, args...)
}

func (l *Logger) Info(msg string, args ...interface{}) {
	l.log(LevelInfo, msg, args...)
}

func (l *Logger) Debug(msg string, args ...interface{}) {
	l.log(LevelDebug, msg, args...)
}

func (l *Logger) log(level Level, msg string, args ...interface{}) {
	if level < l.level {
		return
	}

	printArgs := []interface{}{msg}
	for k, v := range l.records {
		printArgs = append(printArgs, fmt.Sprintf("%v=%v", k, v))
	}
	for k, v := range args {
		printArgs = append(printArgs, fmt.Sprintf("%v=%v", k, v))
	}

	fmt.Println(printArgs...)
}

// CLI

func flagsParse(fs *flag.FlagSet, args []string) {
	debug := fs.Bool("debug", false, "enable debug output")
	fs.Parse(args)

	if *debug {
		defaultLogger.level = LevelDebug
	}
}
