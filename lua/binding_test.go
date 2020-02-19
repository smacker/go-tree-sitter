package lua_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/lua"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte(`print("Hello World!")`), lua.GetLanguage())
	assert.Equal(
		"(program (function_call (identifier) (arguments (string))))",
		n.String(),
	)
}
