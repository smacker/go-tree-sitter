package javascript_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/javascript"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("let a = 1"), javascript.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(program (lexical_declaration (variable_declarator name: (identifier) value: (number))))",
		n.String(),
	)
}
