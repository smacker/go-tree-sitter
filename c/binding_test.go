package c_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/c"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(c.GetLanguage())

	sourceCode := []byte("int a = 2;")
	tree := parser.Parse(sourceCode)

	assert.Equal(
		"(translation_unit (declaration (primitive_type) (init_declarator (identifier) (number_literal))))",
		tree.RootNode().String(),
	)
}
