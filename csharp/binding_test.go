package csharp_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/csharp"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte("using static System.Math;"), csharp.GetLanguage())
	assert.Equal(
		"(compilation_unit (using_directive (qualified_name (identifier) (identifier))))",
		n.String(),
	)
}
