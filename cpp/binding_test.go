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
	tree := parser.Parse(sourceCode)

	assert.Equal(
		"(translation_unit (declaration (primitive_type) (init_declarator (identifier) (number_literal))))",
		tree.RootNode().String(),
	)
}
