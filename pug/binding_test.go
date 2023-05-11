package pug_test

import (
	"context"
	"testing"

	sitter "github.com/codepen/go-tree-sitter"
	"github.com/codepen/go-tree-sitter/pug"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte(`extends layout.pug`), pug.GetLanguage())
	assert.NoError(err)
	assert.Equal("(source_file (extends_statement (path)))", n.String())
}
