package dart

import (
	"context"
	"testing"

	sitter "github.com/codepen/go-tree-sitter"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	code := `
	import 'package:flutter/material.dart';

	void main() {
		runApp(MyApp());
	}

	class MyApp extends StatelessWidget {
		const MyApp({Key key}) : super(key: key);

		@override
		Widget build(BuildContext context) {
			return Container();
		}
	}

	Future<void> hello() async {
											 // <- keyword
	}`

	n, err := sitter.ParseCtx(context.Background(), []byte(code), GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(program (import_or_export (library_import (import_specification (configurable_uri (uri (string_literal)))))) (function_signature (void_type) name: (identifier) (formal_parameter_list)) (function_body (block (expression_statement (identifier) (selector (argument_part (arguments (argument (identifier) (selector (argument_part (arguments)))))))))) (class_definition name: (identifier) superclass: (superclass (type_identifier)) body: (class_body (declaration (constant_constructor_signature (const_builtin) (qualified (type_identifier)) (formal_parameter_list (optional_formal_parameters (formal_parameter (type_identifier) name: (identifier))))) (initializers (initializer_list_entry (super) (arguments (named_argument (label (identifier)) (identifier)))))) (marker_annotation name: (identifier)) (method_signature (function_signature (type_identifier) name: (identifier) (formal_parameter_list (formal_parameter (type_identifier) name: (identifier))))) (function_body (block (return_statement (identifier) (selector (argument_part (arguments)))))))) (function_signature (type_identifier) (type_arguments (void_type)) name: (identifier) (formal_parameter_list)) (function_body (block (comment))))",
		n.String(),
	)
}
