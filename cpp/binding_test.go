package cpp_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/cpp"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(cpp.GetLanguage())

	sourceCode := []byte("int a = 2;")
	tree := parser.ParseString(nil, sourceCode)

	assert.Equal(
		"(translation_unit (declaration type: (primitive_type) declarator: (init_declarator declarator: (identifier) value: (number_literal))))",
		tree.RootNode().String(),
	)
}
