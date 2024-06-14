package tree_sitter_markdown_inline_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	tree_sitter_markdown_inline "github.com/smacker/go-tree-sitter/markdown/tree-sitter-markdown-inline"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("# Hello world!\n- Here is a picture: ![picture](https://example.com/picture.png)"), tree_sitter_markdown_inline.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(inline (image (image_description) (link_destination)))",
		n.String(),
	)
}
