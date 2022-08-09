package markdown_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/markdown/tree-sitter-markdown"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("# This is a heading"), markdown.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(document (section (atx_heading (atx_h1_marker) heading_content: (inline) (MISSING _line_ending))))",
		n.String(),
	)
}
