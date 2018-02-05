#include "tree_sitter/runtime.h"
#include "tree-sitter-javascript/src/parser.c"
#include "tree-sitter-javascript/src/scanner.c"
#include <string.h>
#include <stdio.h>

TSNode parse_javascript(TSDocument *document, const char *input) {
    ts_document_set_language(document, tree_sitter_javascript());
    ts_document_set_input_string(document, input);
    ts_document_parse(document);
    TSNode root_node = ts_document_root_node(document);
    return root_node;
}

char* readValue(TSDocument *document, TSNode node) {
    uint32_t start = ts_node_start_byte(node);
    uint32_t end = ts_node_end_byte(node);
    uint32_t length = end-start;
    uint32_t rest;
    TSInput input = ts_document_input(document);
    input.seek(input.payload, start);
    
    const char* str = input.read(input.payload, &rest);
    char* substr = malloc(length+1);
    strncpy(substr, str, length);
    substr[length] = '\0';

    return substr;
}
