package python_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/python"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte("print(1)"), python.GetLanguage())
	assert.Equal(
		"(module (expression_statement (call function: (identifier) arguments: (argument_list (integer)))))",
		n.String(),
	)
}
