package ocaml_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/ocaml"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte(`print_endline "Hello World!"`), ocaml.GetLanguage())
	assert.Equal(
		"(compilation_unit (expression_item (application_expression function: (value_path (value_name)) argument: (string (string_content)))))",
		n.String(),
	)
}
