package csharp_test

import (
	"github.com/smacker/go-tree-sitter/csharp"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(csharp.GetLanguage())

	sourceCode := []byte("using static System.Math;")
	tree := parser.ParseString(nil, sourceCode)

	assert.Equal(
		"(compilation_unit (using_directive (qualified_name (identifier) (identifier))))",
		tree.RootNode().String(),
	)
}
