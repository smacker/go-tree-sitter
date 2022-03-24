package sitter_test

// Example usage of sitter Go API.

import (
	"context"
	"fmt"
	"log"
	"strings"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/golang"
)

// ExampleCursorTraversal recursively prints the tree using TreeCursor.
//
// The cursor provides each node name.
func ExampleCursorTraversal() {
	root := mustParseGo("func f(a, b, c int, d, e int)")

	c := sitter.NewTreeCursor(root)
	defer c.Close()
	var visit func(depth int)
	visit = func(depth int) {
		printNode(c.CurrentNode(), depth, c.CurrentFieldName())
		for ok := c.GoToFirstChild(); ok; ok = c.GoToNextSibling() {
			visit(depth + 1)
		}
	}
	visit(0)

	// Output:
	// source_file [0-29]
	//     function_declaration [0-29]
	//         func [0-4]
	//         name: identifier [5-6]
	//         parameters: parameter_list [6-29]
	//             ( [6-7]
	//             parameter_declaration [7-18]
	//                 name: identifier [7-8]
	//                 , [8-9]
	//                 name: identifier [10-11]
	//                 , [11-12]
	//                 name: identifier [13-14]
	//                 type: type_identifier [15-18]
}

// ExampleChildTraversal recursively prints the tree using Node.Child for traversal.
//
// Node names are supplied by the parent.
// Beware: they are current wrong due to https://github.com/tree-sitter/tree-sitter/issues/1642!
func ExampleChildTraversal() {
	root := mustParseGo("func f(a, b, c int, d, e int)")

	var visit func(n *sitter.Node, name string, depth int)
	visit = func(n *sitter.Node, name string, depth int) {
		printNode(n, depth, name)
		for i := 0; i < int(n.ChildCount()); i++ {
			visit(n.Child(i), n.FieldNameForChild(i), depth+1)
		}

	}
	visit(root, "root", 0)
}

func mustParseGo(src string) *sitter.Node {
	root, err := sitter.ParseCtx(context.Background(), []byte(src), golang.GetLanguage())
	if err != nil {
		log.Fatal(err)
	}
	return root
}

func printNode(n *sitter.Node, depth int, name string) {
	prefix := ""
	if name != "" {
		prefix = name + ": "
	}
	fmt.Printf("%s%s%s [%d-%d]\n", strings.Repeat("    ", depth), prefix, n.Type(), n.StartByte(), n.EndByte())
}
