package yaml_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/yaml"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("a: 42"), yaml.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(stream (document (block_node (block_mapping (block_mapping_pair key: (flow_node (plain_scalar (string_scalar))) value: (flow_node (plain_scalar (integer_scalar))))))))",
		n.String(),
	)
}
