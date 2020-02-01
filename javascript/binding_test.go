package javascript_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/javascript"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(javascript.GetLanguage())

	sourceCode := []byte("let a = 1")
	tree := parser.ParseString(nil, sourceCode)

	assert.Equal(
		"(program (lexical_declaration (variable_declarator name: (identifier) value: (number))))",
		tree.RootNode().String(),
	)
}
