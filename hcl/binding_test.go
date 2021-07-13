package hcl_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/hcl"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte(`image_id = "abc123"`), hcl.GetLanguage())
	assert.Equal(
		"(source_file (body (attribute (identifier) (expression (expr_term (template_expr (quoted_template)))) (MISSING \"\n\"))))",
		n.String(),
	)
}
