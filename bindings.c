#include "tree_sitter/runtime.h"
#include <string.h>
#include <stdio.h>

char *readValue(TSDocument *document, TSNode node)
{
    uint32_t start = ts_node_start_byte(node);
    uint32_t end = ts_node_end_byte(node);
    uint32_t length = end - start;
    uint32_t rest;
    TSInput input = ts_document_input(document);
    input.seek(input.payload, start);

    const char *str = input.read(input.payload, &rest);
    char *substr = malloc(length + 1);
    strncpy(substr, str, length);
    substr[length] = '\0';

    return substr;
}

static void log(void *payload, TSLogType type, const char *msg)
{
    bool include_lexing = (bool)payload;
    switch (type)
    {
    case TSLogTypeParse:
        fprintf(stderr, "* %s\n", msg);
        break;
    case TSLogTypeLex:
        if (include_lexing)
            fprintf(stderr, "  %s\n", msg);
        break;
    }
}

TSLogger stderr_logger_new(bool include_lexing)
{
    TSLogger result;
    result.payload = (void *)include_lexing;
    result.log = log;
    return result;
}