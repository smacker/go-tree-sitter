package ruby_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/ruby"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("puts 1"), ruby.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(program (call method: (identifier) arguments: (argument_list (integer))))",
		n.String(),
	)
}
