#include "parser.h"
#include <wctype.h>

#include "allocator.h"
#include "ekstring.h"
#include "tag.h"
#include "uthash.h"
#include "vc_vector.h"

typedef enum TokenType {
  START_TAG_NAME,
  SCRIPT_START_TAG_NAME,
  STYLE_START_TAG_NAME,
  END_TAG_NAME,
  ERRONEOUS_END_TAG_NAME,
  SELF_CLOSING_TAG_DELIMITER,
  IMPLICIT_END_TAG,
  RAW_TEXT,
  RAW_TEXT_EXPR,
  RAW_TEXT_AWAIT,
  RAW_TEXT_EACH,
  COMMENT,
} TokenType;

typedef struct {
  vc_vector *tags;
  za_Allocator *A;
  struct hashmap_s *m;
} Scanner;

unsigned serialize(Scanner *scanner, char *buffer) {
  uint16_t tag_count =
      scanner->tags->count > UINT16_MAX ? UINT16_MAX : scanner->tags->count;

  uint16_t serialized_tag_count = 0;

  unsigned i = sizeof(tag_count);
  memcpy(&buffer[i], &tag_count, sizeof(tag_count));
  i += sizeof(tag_count);

  for (; serialized_tag_count < tag_count; serialized_tag_count++) {
    Tag *tag = vc_vector_at((scanner->tags), serialized_tag_count);
    if (tag->type == CUSTOM) {
      unsigned name_length = tag->custom_tag_name.length;
      if (name_length > UINT8_MAX)
        name_length = UINT8_MAX;
      if (i + 2 + name_length >= TREE_SITTER_SERIALIZATION_BUFFER_SIZE)
        break;
      buffer[i++] = (char)(tag->type);
      buffer[i++] = name_length;
      strncpy(&buffer[i], tag->custom_tag_name.buf, name_length);
      i += name_length;
    } else {
      if (i + 1 >= TREE_SITTER_SERIALIZATION_BUFFER_SIZE)
        break;
      buffer[i++] = (char)(tag->type);
    }
  }

  memcpy(&buffer[0], &serialized_tag_count, sizeof(serialized_tag_count));
  return i;
}

void deserialize(Scanner *scanner, const char *buffer, unsigned length) {
  vc_vector_clear(scanner->tags);
  if (length > 0) {
    unsigned i = 0;
    uint16_t tag_count, serialized_tag_count;

    memcpy(&serialized_tag_count, &buffer[i], sizeof(serialized_tag_count));
    i += sizeof(serialized_tag_count);

    memcpy(&tag_count, &buffer[i], sizeof(tag_count));
    i += sizeof(tag_count);

    vc_vector_resize(scanner->tags, tag_count, initTag(scanner->A));
    for (unsigned j = 0; j < serialized_tag_count; j++) {
      Tag *tag = vc_vector_at(scanner->tags, j);
      tag->type = (TagType)(buffer[i++]);
      if (tag->type == CUSTOM) {
        uint16_t name_length = (uint8_t)(buffer[i++]);
        tag->custom_tag_name =
            init_string_str(scanner->A, &buffer[i], name_length);
        i += name_length;
      }
    }
  }
}

ekstring scan_tag_name(Scanner *scanner, TSLexer *lexer) {
  ekstring tag_name = NaS(scanner->A);
  while (iswalnum(lexer->lookahead) || lexer->lookahead == '-' ||
         lexer->lookahead == ':' || lexer->lookahead == '.') {
    tag_name = concat_string_char(tag_name, (lexer->lookahead));
    lexer->advance(lexer, false);
  }
  return tag_name;
}

bool scan_comment(TSLexer *lexer) {
  if (lexer->lookahead != '-')
    return false;
  lexer->advance(lexer, false);
  if (lexer->lookahead != '-')
    return false;
  lexer->advance(lexer, false);

  unsigned dashes = 0;
  while (lexer->lookahead) {
    switch (lexer->lookahead) {
    case '-':
      ++dashes;
      break;
    case '>':
      if (dashes >= 2) {
        lexer->result_symbol = COMMENT;
        lexer->advance(lexer, false);
        lexer->mark_end(lexer);
        return true;
      }
    default:
      dashes = 0;
    }
    lexer->advance(lexer, false);
  }
  return false;
}

bool scan_raw_text(Scanner *scanner, TSLexer *lexer) {
  if (scanner->tags->count == 0)
    return false;

  lexer->mark_end(lexer);

  Tag *lastTag = (Tag *)vc_vector_back(scanner->tags);
  const ekstring end_delimiter =
      lastTag->type == SCRIPT ? init_string_str(scanner->A, "</script", 8)
                              : init_string_str(scanner->A, "</style", 7);

  unsigned delimiter_index = 0;

  while (lexer->lookahead) {
    if ((char)(lexer->lookahead) ==
        end_delimiter.buf[delimiter_index]) {
      delimiter_index++;
      if (delimiter_index == end_delimiter.length)
        break;
      lexer->advance(lexer, false);
    } else {
      delimiter_index = 0;
      lexer->advance(lexer, false);
      lexer->mark_end(lexer);
    }
  }

  lexer->result_symbol = RAW_TEXT;
  return true;
}

bool scan_implicit_end_tag(Scanner *scanner, TSLexer *lexer) {
  vc_vector *tags = scanner->tags;
  Tag *parent = tags->count == 0 ? NULL : vc_vector_back(tags);

  bool is_closing_tag = false;
  if (lexer->lookahead == '/') {
    is_closing_tag = true;
    lexer->advance(lexer, false);
  } else if (parent && is_void(parent)) {
    vc_vector_pop_back(tags);
    lexer->result_symbol = IMPLICIT_END_TAG;
    return true;
  }

  ekstring tag_name = scan_tag_name(scanner, lexer);
  if (tag_name.length == 0) {
    return false;
  }

  Tag *next_tag = for_name(scanner->A, scanner->m, &tag_name);

  if (is_closing_tag) {
    if (tags->count != 0 && compareTags(vc_vector_back(tags), next_tag)) {
      return false;
    }

    if (findTag(tags, next_tag)) {
      vc_vector_pop_back(tags);
      lexer->result_symbol = IMPLICIT_END_TAG;
      return true;
    }
  } else if (parent && !can_contain(parent, next_tag)) {
    vc_vector_pop_back(tags);
    lexer->result_symbol = IMPLICIT_END_TAG;
    return true;
  }

  return false;
}

bool scan_start_tag_name(Scanner *scanner, TSLexer *lexer) {
  ekstring tag_name = scan_tag_name(scanner, lexer);
  if (tag_name.length == 0)
    return false;

  Tag *tag = for_name(scanner->A, scanner->m, &tag_name);
  vc_vector_push_back(scanner->tags, tag);
  switch (tag->type) {
  case SCRIPT:
    lexer->result_symbol = SCRIPT_START_TAG_NAME;
    break;
  case STYLE:
    lexer->result_symbol = STYLE_START_TAG_NAME;
    break;
  default:
    lexer->result_symbol = START_TAG_NAME;
    break;
  }
  return true;
}

bool scan_end_tag_name(Scanner *scanner, TSLexer *lexer) {
  ekstring tag_name = scan_tag_name(scanner, lexer);
  if (tag_name.length == 0) {
    return false;
  }
  Tag *tag = for_name(scanner->A, scanner->m, &tag_name);
  vc_vector *tags = scanner->tags;
  if (tags->count > 0 && compareTags(vc_vector_back(tags), tag)) {
    vc_vector_pop_back(tags);
    lexer->result_symbol = END_TAG_NAME;
  } else {
    lexer->result_symbol = ERRONEOUS_END_TAG_NAME;
  }
  return true;
}

bool scan_self_closing_tag_delimiter(Scanner *scanner, TSLexer *lexer) {
  vc_vector *tags = scanner->tags;
  lexer->advance(lexer, false);
  if (lexer->lookahead == '>') {
    lexer->advance(lexer, false);
    if (tags->count) {
      vc_vector_pop_back(tags);
      lexer->result_symbol = SELF_CLOSING_TAG_DELIMITER;
    }
    return true;
  }
  return false;
}

bool scan_word(Scanner *scanner, TSLexer *lexer, ekstring word) {
  char c = lexer->lookahead;
  int i = 0;
  while (c == word.buf[i++]) {
    lexer->advance(lexer, false);
    c = lexer->lookahead;
  }
  return (c == '{' || iswspace(c));
}

bool scan_raw_text_expr(Scanner *scanner, TSLexer *lexer,
                        TokenType extraToken) {
  char c = lexer->lookahead;
  int inner_curly_start = 0;

  while (c) {
    switch (c) {
    case '{': {
      inner_curly_start++;
      break;
    }
    case '}': {
      if (inner_curly_start <= 0) {
        lexer->mark_end(lexer);
        lexer->result_symbol = RAW_TEXT_EXPR;
        return true;
      }
      inner_curly_start--;
      break;
    }
    case '\n':
    case '\t':
    // case ')':
    case ' ': {
      if (extraToken == RAW_TEXT_AWAIT || extraToken == RAW_TEXT_EACH) {
        lexer->mark_end(lexer);
        lexer->advance(lexer, false);
        c = lexer->lookahead;
        if (extraToken == RAW_TEXT_AWAIT && c == 't') {
          ekstring thenWord = init_string_str(scanner->A, "then", 4);
          if (scan_word(scanner, lexer, thenWord)) {
            lexer->result_symbol = RAW_TEXT_AWAIT;
            return true;
          }
        } else if (extraToken == RAW_TEXT_EACH && c == 'a') {
          ekstring asWord = init_string_str(scanner->A, "as", 2);
          if (scan_word(scanner, lexer, asWord)) {
            lexer->result_symbol = RAW_TEXT_EACH;
            return true;
          }
        }
      }
      break;
    }

    case '"':
    case '\'':
    case '`': {
      char quote = c;
      lexer->advance(lexer, false);
      c = lexer->lookahead;
      while (c) {
        if (c == 0)
          return false;
        if (c == '\\') {
          lexer->advance(lexer, false);
        }
        if (c == quote) {
          break;
        }
        lexer->advance(lexer, false);
        c = lexer->lookahead;
      }
      break;
    }
    default:;
    }
    lexer->advance(lexer, false);
    c = lexer->lookahead;
  }

  return false;
}

bool scan(Scanner *scanner, TSLexer *lexer, const bool *valid_symbols) {
  while (iswspace(lexer->lookahead))
    lexer->advance(lexer, true);

  if (valid_symbols[RAW_TEXT_EXPR] && valid_symbols[RAW_TEXT_AWAIT]) {
    bool b = scan_raw_text_expr(scanner, lexer, RAW_TEXT_AWAIT);
    return b;
  }

  if (valid_symbols[RAW_TEXT_EXPR] && valid_symbols[RAW_TEXT_EACH])
    return scan_raw_text_expr(scanner, lexer, RAW_TEXT_EACH);

  if (valid_symbols[RAW_TEXT_EXPR]) {
    char c = lexer->lookahead;
    if (c == '@' || c == '#' || c == ':' || c == '/')
      return false;
    return scan_raw_text_expr(scanner, lexer, RAW_TEXT_EXPR);
  }

  if (valid_symbols[RAW_TEXT] && !valid_symbols[START_TAG_NAME] &&
      !valid_symbols[END_TAG_NAME]) {
    return scan_raw_text(scanner, lexer);
  }

  switch (lexer->lookahead) {
  case '<':
    lexer->mark_end(lexer);
    lexer->advance(lexer, false);

    if (lexer->lookahead == '!') {
      lexer->advance(lexer, false);
      return scan_comment(lexer);
    }

    if (valid_symbols[IMPLICIT_END_TAG]) {
      return scan_implicit_end_tag(scanner, lexer);
    }
    break;

  case '\0':
    if (valid_symbols[IMPLICIT_END_TAG]) {
      bool b = scan_implicit_end_tag(scanner, lexer);
      return b;
    }
    break;

  case '/':
    if (valid_symbols[SELF_CLOSING_TAG_DELIMITER]) {
      return scan_self_closing_tag_delimiter(scanner, lexer);
    }
    break;

  default:
    if ((valid_symbols[START_TAG_NAME] || valid_symbols[END_TAG_NAME]) &&
        !valid_symbols[RAW_TEXT]) {
      return valid_symbols[START_TAG_NAME] ? scan_start_tag_name(scanner, lexer)
                                           : scan_end_tag_name(scanner, lexer);
    }
  }

  return false;
}

void deleter(void *tag, za_Allocator *A) {}
void *tree_sitter_svelte_external_scanner_create() {
  za_Allocator *A = za_New();
  Scanner *scanner = (Scanner *)za_Alloc(A, sizeof(Scanner));
  scanner->A = A;
  scanner->m = (struct hashmap_s *)get_tag_map(A);
  scanner->tags = vc_vector_create(A, 2, sizeof(Tag), deleter);
  return scanner;
}

bool tree_sitter_svelte_external_scanner_scan(void *payload, TSLexer *lexer,
                                              const bool *valid_symbols) {
  return scan((Scanner *)payload, lexer, valid_symbols);
}

unsigned tree_sitter_svelte_external_scanner_serialize(void *payload,
                                                       char *buffer) {
  return serialize((Scanner *)payload, buffer);
}

void tree_sitter_svelte_external_scanner_deserialize(void *payload,
                                                     const char *buffer,
                                                     unsigned length) {
  deserialize((Scanner *)payload, buffer, length);
}

void tree_sitter_svelte_external_scanner_destroy(void *payload) {
  za_Release(((Scanner *)payload)->A);
}
