package scala_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/scala"
	"github.com/stretchr/testify/assert"
)

const code = `package com.foo.bar`

const expected = `(compilation_unit (package_clause (package_identifier (identifier) (identifier) (identifier))))`

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte(code), scala.GetLanguage())
	assert.Equal(
		expected,
		n.String(),
	)
}
