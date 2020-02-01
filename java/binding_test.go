package java_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/java"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(java.GetLanguage())

	sourceCode := []byte("import java.io.*;")
	tree := parser.ParseString(nil, sourceCode)

	assert.Equal(
		"(program (import_declaration (identifier) (identifier) (asterisk)))",
		tree.RootNode().String(),
	)
}
