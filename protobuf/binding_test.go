package protobuf_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/protobuf"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	code := `
syntax = "proto3";

message Thing {
  string name = 1;
  repeated uint32 scores = 2;
}
`
	n, err := sitter.ParseCtx(context.Background(), []byte(code), protobuf.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(source_file (syntax) (message (message_name (identifier)) (message_body (field (type) (identifier) (field_number (int_lit (decimal_lit)))) (field (type) (identifier) (field_number (int_lit (decimal_lit)))))))",
		n.String(),
	)
}
