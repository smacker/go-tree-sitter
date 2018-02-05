package main

import (
	"fmt"

	sitter "github.com/smacker/go-tree-sitter"
)

func main() {
	n := sitter.Parse([]byte("function hello() { console.log('hello') }"), "javascript")
	fmt.Println("AST:", n)
	fmt.Println("Root type:", n.Type())
	fmt.Println("Root children:", n.Children())
	fmt.Println("Root name:", n.Name())
	child1 := n.Child(0)
	fmt.Println("func type:", child1.Type())
	fmt.Println("func children:", child1.Children())
	fmt.Println("func name:", child1.Name())
}
