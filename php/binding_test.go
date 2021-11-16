package php_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/php"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("<?php print(1);"), php.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(program (php_tag) (expression_statement (print_intrinsic (parenthesized_expression (integer)))))",
		n.String(),
	)
}
