package markdown_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/markdown"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("# This is a header"), markdown.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(document (atx_heading (atx_h1_marker) (heading_content (text))))",
		n.String(),
	)
}
