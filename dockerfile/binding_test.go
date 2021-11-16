package dockerfile_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/dockerfile"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("FROM microsoft/nanoserver"), dockerfile.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(source_file (from_instruction (image_spec name: (image_name))) (MISSING \"\n\"))",
		n.String(),
	)
}
