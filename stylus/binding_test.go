package stylus_test

import (
	"context"
	"testing"

	sitter "github.com/codepen/go-tree-sitter"
	"github.com/codepen/go-tree-sitter/stylus"
	"github.com/stretchr/testify/assert"
)

func TestStylusGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("@import \"hello\";"), stylus.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(doc (import_statement (quoted_import_reference (import_reference))))",
		n.String(),
	)
}
