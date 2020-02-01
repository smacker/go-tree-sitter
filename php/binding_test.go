package php_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/php"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(php.GetLanguage())

	sourceCode := []byte("<?php print(1);")
	tree := parser.ParseString(nil, sourceCode)

	assert.Equal(
		"(program (expression_statement (print_intrinsic (parenthesized_expression (integer)))))",
		tree.RootNode().String(),
	)
}
