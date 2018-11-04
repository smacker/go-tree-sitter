package bash_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/bash"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(bash.GetLanguage())

	sourceCode := []byte("echo 1")
	tree := parser.Parse(sourceCode)

	assert.Equal(
		"(program (command (command_name (word)) (word)))",
		tree.RootNode().String(),
	)
}
