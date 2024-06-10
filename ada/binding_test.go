package ada_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/ada"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("A := 42;"), ada.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(compilation (compilation_unit (assignment_statement variable_name: (identifier) (expression (term (numeric_literal))))))",
		n.String(),
	)
}
