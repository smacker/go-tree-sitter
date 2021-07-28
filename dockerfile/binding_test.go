package dockerfile_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/dockerfile"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte("FROM microsoft/nanoserver"), dockerfile.GetLanguage())
	assert.Equal(
		"(source_file (from_instruction (image_spec name: (image_name))) (MISSING \"\n\"))",
		n.String(),
	)
}
