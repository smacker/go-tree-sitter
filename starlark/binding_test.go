package starlark_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/starlark"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	code := `def myfunc(a):
	pass
`

	n, err := sitter.ParseCtx(context.Background(), []byte(code), starlark.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(module (function_definition name: (identifier) parameters: (parameters (identifier)) body: (block (pass_statement))))",
		n.String(),
	)
}
