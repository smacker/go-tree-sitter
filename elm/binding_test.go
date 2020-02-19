package elm_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/elm"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte("import Html exposing (text)"), elm.GetLanguage())
	assert.Equal(
		"(file (import_clause (import) (upper_case_qid (upper_case_identifier)) (exposing_list (exposing) (left_parenthesis) (exposed_value (lower_case_identifier)) (right_parenthesis))))",
		n.String(),
	)
}
