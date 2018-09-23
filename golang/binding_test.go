package golang_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/golang"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(golang.GetLanguage())

	sourceCode := []byte("package main")
	tree := parser.Parse(sourceCode)

	assert.Equal(
		"(source_file (package_clause (package_identifier)))",
		tree.RootNode().String(),
	)
}
