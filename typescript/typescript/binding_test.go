package typescript_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/typescript/typescript"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(typescript.GetLanguage())

	sourceCode := []byte("let a : number = 1;")
	tree := parser.ParseString(nil, sourceCode)

	assert.Equal(
		"(program (lexical_declaration (variable_declarator name: (identifier) type: (type_annotation (predefined_type)) value: (number))))",
		tree.RootNode().String(),
	)
}
