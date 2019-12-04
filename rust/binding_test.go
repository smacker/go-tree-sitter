package rust_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/rust"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()
	parser.SetLanguage(rust.GetLanguage())

	sourceCode := []byte("mod one;")
	tree := parser.Parse(sourceCode)

	assert.Equal(
		"(source_file (mod_item name: (identifier)))",
		tree.RootNode().String(),
	)
}
