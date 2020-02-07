package ruby_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/ruby"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte("puts 1"), ruby.GetLanguage())
	assert.Equal(
		"(program (method_call method: (identifier) arguments: (argument_list (integer))))",
		n.String(),
	)
}
