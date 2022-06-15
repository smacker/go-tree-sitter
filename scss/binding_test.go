package scss_test

import (
	"context"
	"testing"

	sitter "github.com/codepen/go-tree-sitter"
	"github.com/codepen/go-tree-sitter/scss"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte(`@import "compass"; $text-color: #555555; body { color: $text-color; }`), scss.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(stylesheet (import_statement (string_value)) (declaration (variable_name) (color_value)) (rule_set (selectors (tag_name)) (block (declaration (property_name) (variable_value)))))",
		n.String(),
	)
}
