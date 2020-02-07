package typescript_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/typescript/typescript"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte("let a : number = 1;"), typescript.GetLanguage())
	assert.Equal(
		"(program (lexical_declaration (variable_declarator name: (identifier) type: (type_annotation (predefined_type)) value: (number))))",
		n.String(),
	)
}
