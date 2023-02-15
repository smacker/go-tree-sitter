package sfapex

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/sfapex"
	"github.com/stretchr/testify/assert"
)

var apexCode = `
public class MyClass {
	public void myMethod() {
		System.debug(a);
	 }
}
`

var output = `(parser_output (class_declaration (modifiers (modifier)) name: (identifier) body: (class_body (method_declaration (modifiers (modifier)) type: (void_type) name: (identifier) parameters: (formal_parameters) body: (block (expression_statement (method_invocation object: (identifier) name: (identifier) arguments: (argument_list (identifier)))))))))`

func TestGrammar(t *testing.T) {
	n, err := sitter.ParseCtx(context.Background(), []byte(apexCode), sfapex.GetLanguage())
	assert.Nil(t, err)
	assert.Equal(t, output, n.String())
}
