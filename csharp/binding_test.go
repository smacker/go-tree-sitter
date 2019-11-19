package csharp_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/csharp"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(csharp.GetLanguage())

	sourceCode := []byte(`
	using System;
	using System.Collections.Generic;

	class Test {}
	`)
	tree := parser.Parse(sourceCode)

	assert.Equal(
		"(compilation_unit (using_directive (identifier_name)) (using_directive (qualified_name (qualified_name (identifier_name) (identifier_name)) (identifier_name))) (class_declaration (identifier_name) (class_body)))",
		tree.RootNode().String(),
	)
}
