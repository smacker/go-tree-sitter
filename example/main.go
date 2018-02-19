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

	fmt.Println("\nFunctions in input:")
	iter := sitter.NewIterator(n, sitter.DFSMode)
	var funcs []*sitter.Node
	iter.ForEach(func(n *sitter.Node) error {
		if n.Type() == "function" {
			fmt.Println("-", n.Value())
			funcs = append(funcs, n)
		}
		return nil
	})

	fmt.Println("\nEdit input")
	// reuse tree
	doc.Edit(62, 0, []byte(" console.log('goodbye') "))

	for _, f := range funcs {
		var textChange string
		if f.HasChanges() {
			textChange = "has change"
		} else {
			textChange = "no changes"
		}
		fmt.Println("-", f.Value(), ">", textChange)
	}

	doc.Parse()
	n = doc.RootNode()
	fmt.Println("\nNew AST:", n)
}
