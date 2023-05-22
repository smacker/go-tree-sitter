#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 34
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 26
#define ALIAS_COUNT 0
#define TOKEN_COUNT 16
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum {
  aux_sym_tbd_token1 = 1,
  sym_import_reference = 2,
  anon_sym_SQUOTE = 3,
  anon_sym_DQUOTE = 4,
  anon_sym_url = 5,
  anon_sym_LPAREN = 6,
  anon_sym_RPAREN = 7,
  aux_sym_import_keyword_token1 = 8,
  anon_sym_COMMA = 9,
  anon_sym_ATimport = 10,
  anon_sym_ATrequire = 11,
  anon_sym_SEMI = 12,
  sym_string = 13,
  sym_comment_block = 14,
  sym_comment_line = 15,
  sym_doc = 16,
  sym_tbd = 17,
  sym_quoted_import_reference = 18,
  sym_url = 19,
  sym_import_keyword = 20,
  sym_import_keywords = 21,
  sym_import_statement = 22,
  aux_sym_doc_repeat1 = 23,
  aux_sym_tbd_repeat1 = 24,
  aux_sym_import_keywords_repeat1 = 25,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_tbd_token1] = "tbd_token1",
  [sym_import_reference] = "import_reference",
  [anon_sym_SQUOTE] = "'",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_url] = "url",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [aux_sym_import_keyword_token1] = "import_keyword_token1",
  [anon_sym_COMMA] = ",",
  [anon_sym_ATimport] = "@import",
  [anon_sym_ATrequire] = "@require",
  [anon_sym_SEMI] = ";",
  [sym_string] = "string",
  [sym_comment_block] = "comment_block",
  [sym_comment_line] = "comment_line",
  [sym_doc] = "doc",
  [sym_tbd] = "tbd",
  [sym_quoted_import_reference] = "quoted_import_reference",
  [sym_url] = "url",
  [sym_import_keyword] = "import_keyword",
  [sym_import_keywords] = "import_keywords",
  [sym_import_statement] = "import_statement",
  [aux_sym_doc_repeat1] = "doc_repeat1",
  [aux_sym_tbd_repeat1] = "tbd_repeat1",
  [aux_sym_import_keywords_repeat1] = "import_keywords_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_tbd_token1] = aux_sym_tbd_token1,
  [sym_import_reference] = sym_import_reference,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_url] = anon_sym_url,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [aux_sym_import_keyword_token1] = aux_sym_import_keyword_token1,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_ATimport] = anon_sym_ATimport,
  [anon_sym_ATrequire] = anon_sym_ATrequire,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [sym_string] = sym_string,
  [sym_comment_block] = sym_comment_block,
  [sym_comment_line] = sym_comment_line,
  [sym_doc] = sym_doc,
  [sym_tbd] = sym_tbd,
  [sym_quoted_import_reference] = sym_quoted_import_reference,
  [sym_url] = sym_url,
  [sym_import_keyword] = sym_import_keyword,
  [sym_import_keywords] = sym_import_keywords,
  [sym_import_statement] = sym_import_statement,
  [aux_sym_doc_repeat1] = aux_sym_doc_repeat1,
  [aux_sym_tbd_repeat1] = aux_sym_tbd_repeat1,
  [aux_sym_import_keywords_repeat1] = aux_sym_import_keywords_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_tbd_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_import_reference] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_url] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_import_keyword_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATimport] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATrequire] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_block] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_line] = {
    .visible = true,
    .named = true,
  },
  [sym_doc] = {
    .visible = true,
    .named = true,
  },
  [sym_tbd] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_import_reference] = {
    .visible = true,
    .named = true,
  },
  [sym_url] = {
    .visible = true,
    .named = true,
  },
  [sym_import_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_import_keywords] = {
    .visible = true,
    .named = true,
  },
  [sym_import_statement] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_doc_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tbd_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_import_keywords_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 9,
  [30] = 25,
  [31] = 24,
  [32] = 28,
  [33] = 27,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(27);
      if (lookahead == '"') ADVANCE(38);
      if (lookahead == '\'') ADVANCE(37);
      if (lookahead == '(') ADVANCE(41);
      if (lookahead == ')') ADVANCE(42);
      if (lookahead == ',') ADVANCE(46);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == ';') ADVANCE(49);
      if (lookahead == '@') ADVANCE(10);
      if (lookahead == 'u') ADVANCE(44);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(38);
      if (lookahead == '\'') ADVANCE(37);
      if (lookahead == '(') ADVANCE(41);
      if (lookahead == 'u') ADVANCE(18);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(50);
      if (lookahead == '\\') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(50);
      if (lookahead == '\\') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == ')') ADVANCE(42);
      if (lookahead == ',') ADVANCE(46);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(24);
      END_STATE();
    case 6:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '/') ADVANCE(53);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 7:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(16);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 10:
      if (lookahead == 'i') ADVANCE(13);
      if (lookahead == 'r') ADVANCE(8);
      END_STATE();
    case 11:
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 12:
      if (lookahead == 'l') ADVANCE(39);
      END_STATE();
    case 13:
      if (lookahead == 'm') ADVANCE(15);
      END_STATE();
    case 14:
      if (lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 15:
      if (lookahead == 'p') ADVANCE(14);
      END_STATE();
    case 16:
      if (lookahead == 'q') ADVANCE(21);
      END_STATE();
    case 17:
      if (lookahead == 'r') ADVANCE(20);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 19:
      if (lookahead == 'r') ADVANCE(9);
      END_STATE();
    case 20:
      if (lookahead == 't') ADVANCE(47);
      END_STATE();
    case 21:
      if (lookahead == 'u') ADVANCE(11);
      END_STATE();
    case 22:
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(2);
      if (lookahead == '"') ADVANCE(51);
      if (lookahead == '\\') ADVANCE(22);
      END_STATE();
    case 23:
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(3);
      if (lookahead == '\'') ADVANCE(52);
      if (lookahead == '\\') ADVANCE(23);
      END_STATE();
    case 24:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(54);
      END_STATE();
    case 25:
      if (eof) ADVANCE(27);
      if (lookahead == '\n') SKIP(25)
      if (lookahead == '"') ADVANCE(31);
      if (lookahead == '\'') ADVANCE(32);
      if (lookahead == '/') ADVANCE(33);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(30);
      if (lookahead != 0) ADVANCE(28);
      END_STATE();
    case 26:
      if (eof) ADVANCE(27);
      if (lookahead == '\n') SKIP(26)
      if (lookahead == '"') ADVANCE(31);
      if (lookahead == '\'') ADVANCE(32);
      if (lookahead == '/') ADVANCE(33);
      if (lookahead == ';') ADVANCE(49);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(29);
      if (lookahead != 0) ADVANCE(28);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '"') ADVANCE(31);
      if (lookahead == '\'') ADVANCE(32);
      if (lookahead == '/') ADVANCE(33);
      if (lookahead == ';') ADVANCE(49);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(29);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(28);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '"') ADVANCE(31);
      if (lookahead == '\'') ADVANCE(32);
      if (lookahead == '/') ADVANCE(33);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(30);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(28);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '"') ADVANCE(50);
      if (lookahead == '\\') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '\'') ADVANCE(50);
      if (lookahead == '\\') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(24);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == 'i') ADVANCE(13);
      if (lookahead == 'r') ADVANCE(8);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_import_reference);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(35);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\'') ADVANCE(36);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_import_reference);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\'') ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_url);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_url);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym_import_keyword_token1);
      if (lookahead == 'l') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym_import_keyword_token1);
      if (lookahead == 'r') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_import_keyword_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_ATimport);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_ATrequire);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '"') ADVANCE(50);
      if (lookahead == '\\') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '\'') ADVANCE(50);
      if (lookahead == '\\') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_comment_block);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_comment_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(54);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 25},
  [2] = {.lex_state = 25},
  [3] = {.lex_state = 25},
  [4] = {.lex_state = 26},
  [5] = {.lex_state = 25},
  [6] = {.lex_state = 26},
  [7] = {.lex_state = 25},
  [8] = {.lex_state = 26},
  [9] = {.lex_state = 26},
  [10] = {.lex_state = 25},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 25},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 4},
  [15] = {.lex_state = 4},
  [16] = {.lex_state = 4},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 4},
  [21] = {.lex_state = 4},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 35},
  [28] = {.lex_state = 35},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 35},
  [33] = {.lex_state = 35},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_url] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [aux_sym_import_keyword_token1] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_ATimport] = ACTIONS(1),
    [anon_sym_ATrequire] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [sym_comment_block] = ACTIONS(1),
    [sym_comment_line] = ACTIONS(1),
  },
  [1] = {
    [sym_doc] = STATE(22),
    [sym_tbd] = STATE(2),
    [sym_import_statement] = STATE(2),
    [aux_sym_doc_repeat1] = STATE(2),
    [aux_sym_tbd_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_tbd_token1] = ACTIONS(5),
    [anon_sym_ATimport] = ACTIONS(7),
    [anon_sym_ATrequire] = ACTIONS(7),
    [sym_string] = ACTIONS(9),
    [sym_comment_block] = ACTIONS(9),
    [sym_comment_line] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(5), 1,
      aux_sym_tbd_token1,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    STATE(5), 1,
      aux_sym_tbd_repeat1,
    ACTIONS(7), 2,
      anon_sym_ATimport,
      anon_sym_ATrequire,
    ACTIONS(13), 3,
      sym_string,
      sym_comment_block,
      sym_comment_line,
    STATE(3), 3,
      sym_tbd,
      sym_import_statement,
      aux_sym_doc_repeat1,
  [24] = 6,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      aux_sym_tbd_token1,
    STATE(5), 1,
      aux_sym_tbd_repeat1,
    ACTIONS(20), 2,
      anon_sym_ATimport,
      anon_sym_ATrequire,
    ACTIONS(23), 3,
      sym_string,
      sym_comment_block,
      sym_comment_line,
    STATE(3), 3,
      sym_tbd,
      sym_import_statement,
      aux_sym_doc_repeat1,
  [48] = 3,
    ACTIONS(26), 1,
      ts_builtin_sym_end,
    ACTIONS(30), 1,
      anon_sym_SEMI,
    ACTIONS(28), 6,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [63] = 4,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
    ACTIONS(34), 1,
      aux_sym_tbd_token1,
    STATE(7), 1,
      aux_sym_tbd_repeat1,
    ACTIONS(36), 5,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [80] = 3,
    ACTIONS(38), 1,
      ts_builtin_sym_end,
    ACTIONS(42), 1,
      anon_sym_SEMI,
    ACTIONS(40), 6,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [95] = 4,
    ACTIONS(44), 1,
      ts_builtin_sym_end,
    ACTIONS(46), 1,
      aux_sym_tbd_token1,
    STATE(7), 1,
      aux_sym_tbd_repeat1,
    ACTIONS(49), 5,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [112] = 2,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
    ACTIONS(53), 7,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      anon_sym_SEMI,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [125] = 2,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    ACTIONS(57), 7,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      anon_sym_SEMI,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [138] = 2,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
    ACTIONS(61), 6,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [150] = 6,
    ACTIONS(63), 1,
      anon_sym_SQUOTE,
    ACTIONS(65), 1,
      anon_sym_DQUOTE,
    ACTIONS(67), 1,
      anon_sym_url,
    ACTIONS(69), 1,
      anon_sym_LPAREN,
    STATE(13), 1,
      sym_import_keywords,
    STATE(4), 2,
      sym_quoted_import_reference,
      sym_url,
  [170] = 2,
    ACTIONS(38), 1,
      ts_builtin_sym_end,
    ACTIONS(40), 6,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [182] = 4,
    ACTIONS(63), 1,
      anon_sym_SQUOTE,
    ACTIONS(65), 1,
      anon_sym_DQUOTE,
    ACTIONS(67), 1,
      anon_sym_url,
    STATE(6), 2,
      sym_quoted_import_reference,
      sym_url,
  [196] = 3,
    ACTIONS(71), 1,
      anon_sym_RPAREN,
    ACTIONS(73), 1,
      aux_sym_import_keyword_token1,
    STATE(14), 2,
      sym_import_keyword,
      aux_sym_import_keywords_repeat1,
  [207] = 3,
    ACTIONS(76), 1,
      anon_sym_RPAREN,
    ACTIONS(78), 1,
      aux_sym_import_keyword_token1,
    STATE(16), 2,
      sym_import_keyword,
      aux_sym_import_keywords_repeat1,
  [218] = 3,
    ACTIONS(78), 1,
      aux_sym_import_keyword_token1,
    ACTIONS(80), 1,
      anon_sym_RPAREN,
    STATE(14), 2,
      sym_import_keyword,
      aux_sym_import_keywords_repeat1,
  [229] = 1,
    ACTIONS(82), 3,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_url,
  [235] = 3,
    ACTIONS(84), 1,
      anon_sym_SQUOTE,
    ACTIONS(86), 1,
      anon_sym_DQUOTE,
    STATE(23), 1,
      sym_quoted_import_reference,
  [245] = 1,
    ACTIONS(88), 3,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_url,
  [251] = 2,
    ACTIONS(92), 1,
      anon_sym_COMMA,
    ACTIONS(90), 2,
      anon_sym_RPAREN,
      aux_sym_import_keyword_token1,
  [259] = 1,
    ACTIONS(94), 2,
      anon_sym_RPAREN,
      aux_sym_import_keyword_token1,
  [264] = 1,
    ACTIONS(96), 1,
      ts_builtin_sym_end,
  [268] = 1,
    ACTIONS(98), 1,
      anon_sym_RPAREN,
  [272] = 1,
    ACTIONS(100), 1,
      anon_sym_DQUOTE,
  [276] = 1,
    ACTIONS(100), 1,
      anon_sym_SQUOTE,
  [280] = 1,
    ACTIONS(102), 1,
      anon_sym_LPAREN,
  [284] = 1,
    ACTIONS(104), 1,
      sym_import_reference,
  [288] = 1,
    ACTIONS(106), 1,
      sym_import_reference,
  [292] = 1,
    ACTIONS(55), 1,
      anon_sym_RPAREN,
  [296] = 1,
    ACTIONS(108), 1,
      anon_sym_SQUOTE,
  [300] = 1,
    ACTIONS(108), 1,
      anon_sym_DQUOTE,
  [304] = 1,
    ACTIONS(110), 1,
      sym_import_reference,
  [308] = 1,
    ACTIONS(112), 1,
      sym_import_reference,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 48,
  [SMALL_STATE(5)] = 63,
  [SMALL_STATE(6)] = 80,
  [SMALL_STATE(7)] = 95,
  [SMALL_STATE(8)] = 112,
  [SMALL_STATE(9)] = 125,
  [SMALL_STATE(10)] = 138,
  [SMALL_STATE(11)] = 150,
  [SMALL_STATE(12)] = 170,
  [SMALL_STATE(13)] = 182,
  [SMALL_STATE(14)] = 196,
  [SMALL_STATE(15)] = 207,
  [SMALL_STATE(16)] = 218,
  [SMALL_STATE(17)] = 229,
  [SMALL_STATE(18)] = 235,
  [SMALL_STATE(19)] = 245,
  [SMALL_STATE(20)] = 251,
  [SMALL_STATE(21)] = 259,
  [SMALL_STATE(22)] = 264,
  [SMALL_STATE(23)] = 268,
  [SMALL_STATE(24)] = 272,
  [SMALL_STATE(25)] = 276,
  [SMALL_STATE(26)] = 280,
  [SMALL_STATE(27)] = 284,
  [SMALL_STATE(28)] = 288,
  [SMALL_STATE(29)] = 292,
  [SMALL_STATE(30)] = 296,
  [SMALL_STATE(31)] = 300,
  [SMALL_STATE(32)] = 304,
  [SMALL_STATE(33)] = 308,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doc, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doc, 1),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_doc_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_doc_repeat1, 2), SHIFT_REPEAT(5),
  [20] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_doc_repeat1, 2), SHIFT_REPEAT(11),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_doc_repeat1, 2), SHIFT_REPEAT(3),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 2),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 2),
  [30] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tbd, 1),
  [34] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [36] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tbd, 1),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 3),
  [40] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 3),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tbd_repeat1, 2),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_tbd_repeat1, 2), SHIFT_REPEAT(7),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_tbd_repeat1, 2),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_url, 4),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_url, 4),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_import_reference, 3),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_import_reference, 3),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 4),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 4),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_keywords_repeat1, 2),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_keywords_repeat1, 2), SHIFT_REPEAT(20),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keywords, 3),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keywords, 2),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keyword, 1),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keyword, 2),
  [96] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_stylus(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
