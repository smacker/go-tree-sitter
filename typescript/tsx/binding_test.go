package tsx_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/typescript/tsx"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("<foo />"), tsx.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(program (expression_statement (jsx_self_closing_element name: (identifier))))",
		n.String(),
	)
}
