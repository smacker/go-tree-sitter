package main

import (
	"fmt"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/javascript"
)

func main() {
	input := []byte("function hello() { console.log('hello') }; function goodbye(){}")

	doc := sitter.NewDocument()
	defer doc.Close()

	doc.SetLanguage(javascript.GetLanguage())
	doc.SetInputBytes(input)
	doc.Parse()

	n := doc.RootNode()

	fmt.Println("AST:", n)
	fmt.Println("Root type:", n.Type())
	fmt.Println("Root children:", n.ChildCount())

	fmt.Println()
	fmt.Println("Functions in input:")
	iter := sitter.NewIterator(n, sitter.DFSMode)
	iter.ForEach(func(n *sitter.Node) error {
		if n.Type() == "function" {
			fmt.Println("-", n.Value())
		}
		return nil
	})

	// reuse tree
	fmt.Println()
	fmt.Println("Edit input")
	doc.Edit(62, 0, []byte(" console.log('goodbye') "))

	fmt.Println("Functions in input:")
	iter = sitter.NewIterator(n, sitter.DFSMode)
	iter.ForEach(func(n *sitter.Node) error {
		if n.Type() == "function" {
			var textChange string
			if n.HasChanges() {
				textChange = "has change"
			} else {
				textChange = "no changes"
			}
			fmt.Println("-", n.Value(), ">", textChange)
		}
		return nil
	})

	doc.Parse()
	n = doc.RootNode()
	fmt.Println()
	fmt.Println("New AST:", n)
}
