package css_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/css"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte(`p { color: red; }`), css.GetLanguage())
	assert.Equal(
		"(stylesheet (rule_set (selectors (tag_name)) (block (declaration (property_name) (plain_value)))))",
		n.String(),
	)
}
