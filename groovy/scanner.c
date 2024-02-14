#include "parser.h"
#include <wctype.h>
#include <stdio.h>

enum TokenType {
  BLOCK_COMMENT_START,
  BLOCK_COMMENT_CONTENT,
  BLOCK_COMMENT_END,

  STRING_DQ_START,
  STRING_DQ_CONTENT,
  STRING_DQ_END,
};


