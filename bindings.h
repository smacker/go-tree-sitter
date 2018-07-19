#ifndef TREE_SITTER_BINDINGS_H_
#define TREE_SITTER_BINDINGS_H_

#include "tree_sitter/runtime.h"

//char *readValue(TSDocument *document, TSNode node);

TSInput ts_string_input_make(const char *);

TSLogger stderr_logger_new(bool include_lexing);

#endif