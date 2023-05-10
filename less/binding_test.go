package less_test

import (
	"context"
	"testing"

	sitter "github.com/codepen/go-tree-sitter"
	"github.com/codepen/go-tree-sitter/less"
	"github.com/stretchr/testify/assert"
)

func TestLessGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("@import \"hello\";"), less.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(doc (import (string)))",
		n.String(),
	)
}
