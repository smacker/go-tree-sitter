package ruby_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/ruby"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(ruby.GetLanguage())

	sourceCode := []byte("puts 1")
	tree := parser.ParseString(nil, sourceCode)

	assert.Equal(
		"(program (method_call method: (identifier) arguments: (argument_list (integer))))",
		tree.RootNode().String(),
	)
}
