package hcl_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/hcl"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte(`image_id = "abc123"`), hcl.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(source_file (body (attribute (identifier) (expression (expr_term (template_expr (quoted_template)))) (MISSING \"\n\"))))",
		n.String(),
	)
}
