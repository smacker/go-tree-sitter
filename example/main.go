package main

import (
	"fmt"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/javascript"
)

func main() {
	n := sitter.Parse([]byte("function hello() { console.log('hello') }"), javascript.GetLanguage())
	fmt.Println("AST:", n)
	fmt.Println("Root type:", n.Type())
	fmt.Println("Root children:", n.ChildCount())
	fmt.Println("Root name:", n.Name())
	child1 := n.Child(0)
	fmt.Println("func type:", child1.Type())
	fmt.Println("func children:", child1.ChildCount())
	fmt.Println("func name:", child1.Name())
}
