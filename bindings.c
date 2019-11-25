#include "api.h"
#include <string.h>
#include <stdio.h>

static void stderr_log(void *payload, TSLogType type, const char *msg)
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
    result.log = stderr_log;
    return result;
}
