package bash_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/bash"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte("echo 1"), bash.GetLanguage())
	assert.Equal(
		"(program (command (command_name (word)) (word)))",
		n.String(),
	)
}
