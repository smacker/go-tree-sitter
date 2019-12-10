package tsx_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/typescript/tsx"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(tsx.GetLanguage())

	sourceCode := []byte("<foo />")
	tree := parser.Parse(sourceCode)

	assert.Equal(
		"(program (expression_statement (jsx_self_closing_element name: (identifier))))",
		tree.RootNode().String(),
	)
}
