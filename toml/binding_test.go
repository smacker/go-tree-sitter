package toml_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/toml"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte(`key = "value"`), toml.GetLanguage())
	assert.Equal(
		"(document (pair (bare_key) (string)))",
		n.String(),
	)
}
