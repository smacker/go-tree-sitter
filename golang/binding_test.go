package golang_test

import (
	"context"
	"testing"

	sitter "github.com/codepen/go-tree-sitter"
	"github.com/codepen/go-tree-sitter/golang"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("package main"), golang.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(source_file (package_clause (package_identifier)))",
		n.String(),
	)
}
