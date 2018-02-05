#ifndef TREE_SITTER_BINDINGS_H_
#define TREE_SITTER_BINDINGS_H_

#include "tree_sitter/runtime.h"

TSNode parse_javascript(TSDocument *document, const char *input);
char* readValue(TSDocument *document, TSNode node);

#endif