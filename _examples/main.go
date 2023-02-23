package main

import (
	"fmt"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/javascript"
)

func main() {
	input := []byte("function hello() { console.log('hello') }; function goodbye(){}")

	parser := sitter.NewParser()
	parser.SetLanguage(javascript.GetLanguage())

	tree := parser.Parse(nil, input)

	n := tree.RootNode()

	fmt.Println("AST:", n)
	fmt.Println("Root type:", n.Type())
	fmt.Println("Root children:", n.ChildCount())

	fmt.Println("\nFunctions in input:")
	q, _ := sitter.NewQuery([]byte("(function_declaration) @func"), javascript.GetLanguage())
	qc := sitter.NewQueryCursor()
	qc.Exec(q, n)

	var funcs []*sitter.Node
	for {
		m, ok := qc.NextMatch()
		if !ok {
			break
		}

		for _, c := range m.Captures {
			funcs = append(funcs, c.Node)
			fmt.Println("-", funcName(input, c.Node))
		}
	}

	fmt.Println("\nEdit input")
	input = []byte("function hello() { console.log('hello') }; function goodbye(){ console.log('goodbye') }")
	// reuse tree
	tree.Edit(sitter.EditInput{
		StartIndex:  62,
		OldEndIndex: 63,
		NewEndIndex: 87,
		StartPoint: sitter.Point{
			Row:    0,
			Column: 62,
		},
		OldEndPoint: sitter.Point{
			Row:    0,
			Column: 63,
		},
		NewEndPoint: sitter.Point{
			Row:    0,
			Column: 87,
		},
	})

	for _, f := range funcs {
		var textChange string
		if f.HasChanges() {
			textChange = "has change"
		} else {
			textChange = "no changes"
		}
		fmt.Println("-", funcName(input, f), ">", textChange)
	}

	newTree := parser.Parse(tree, input)
	n = newTree.RootNode()
	fmt.Println("\nNew AST:", n)
}

func funcName(content []byte, n *sitter.Node) string {
	if n == nil {
		return ""
	}

	if n.Type() != "function_declaration" {
		return ""
	}

	return n.ChildByFieldName("name").Content(content)
}
