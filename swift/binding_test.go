package swift_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/swift"
	"github.com/stretchr/testify/assert"
)

// https://github.com/alex-pinkus/tree-sitter-swift/blob/main/test/corpus/annotations.txt
const code = `class X {
	@A @B
	override let s: String
   }`

const expected = `(source_file (class_declaration name: (type_identifier) body: (class_body (property_declaration (modifiers (attribute (user_type (type_identifier))) (attribute (user_type (type_identifier))) (member_modifier)) (value_binding_pattern) name: (pattern bound_identifier: (simple_identifier)) (type_annotation name: (user_type (type_identifier)))))))`

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte(code), swift.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		expected,
		n.String(),
	)
}
