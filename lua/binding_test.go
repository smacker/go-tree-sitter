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
		"(program (function_call prefix: (identifier) (function_call_paren) args: (function_arguments (string)) (function_call_paren)))",
		n.String(),
	)
}
