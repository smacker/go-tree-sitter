package groovy_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/groovy"
	"github.com/stretchr/testify/assert"
)

var gradleGroovyCode = `
plugins {
    id 'application' 
    id 'foo' 
}
`

var testCases = []struct {
	name     string
	input    string
	expected string
}{
	{
		name: "hello-world",
		input: `
      class Example {
         static void main(String[] args) {
            println('Hello World');
         }
      }`,
		expected: "(source_file (class_definition name: (identifier) body: (closure (function_definition (modifier) type: (builtintype) function: (identifier) parameters: (parameter_list (parameter type: (array_type (identifier)) name: (identifier))) body: (closure (function_call function: (identifier) args: (argument_list (string (string_content)))))))))",
	},
	{
		name: "gradle",
		input: `
      plugins {
          id 'application' 
      }

      repositories {
          mavenCentral() 
      }

      application {
          mainClass = 'example.App' 
      }
      `,
		expected: "(source_file (juxt_function_call function: (identifier) args: (argument_list (closure (juxt_function_call function: (identifier) args: (argument_list (string (string_content))))))) (juxt_function_call function: (identifier) args: (argument_list (closure (function_call function: (identifier) args: (argument_list))))) (juxt_function_call function: (identifier) args: (argument_list (closure (assignment (identifier) (string (string_content)))))))",
	},
}

func TestGrammar(t *testing.T) {
	for _, tc := range testCases {
		t.Run(tc.name, func(t *testing.T) {
			n, err := sitter.ParseCtx(context.Background(), []byte(tc.input), groovy.GetLanguage())
			assert.Nil(t, err)
			assert.Equal(t, tc.expected, n.String())
		})
	}
}
