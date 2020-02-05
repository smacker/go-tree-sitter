package java_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/java"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte("import java.io.*;"), java.GetLanguage())
	assert.Equal(
		"(program (import_declaration (identifier) (identifier) (asterisk)))",
		n.String(),
	)
}
