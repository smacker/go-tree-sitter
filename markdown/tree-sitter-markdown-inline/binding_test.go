package markdown_inline_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/markdown/tree-sitter-markdown-inline"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("# This is a heading"), markdown_inline.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(inline)",
		n.String(),
	)
}
