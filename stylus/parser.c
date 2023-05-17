#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 24
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 22
#define ALIAS_COUNT 0
#define TOKEN_COUNT 13
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum {
  aux_sym_tbd_token1 = 1,
  anon_sym_url = 2,
  anon_sym_LPAREN = 3,
  anon_sym_RPAREN = 4,
  aux_sym_import_keyword_token1 = 5,
  anon_sym_COMMA = 6,
  anon_sym_ATimport = 7,
  anon_sym_ATrequire = 8,
  anon_sym_SEMI = 9,
  sym_string = 10,
  sym_comment_block = 11,
  sym_comment_line = 12,
  sym_doc = 13,
  sym_tbd = 14,
  sym_url = 15,
  sym_import_keyword = 16,
  sym_import_keywords = 17,
  sym_import = 18,
  aux_sym_doc_repeat1 = 19,
  aux_sym_tbd_repeat1 = 20,
  aux_sym_import_keywords_repeat1 = 21,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_tbd_token1] = "tbd_token1",
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
  [sym_url] = "url",
  [sym_import_keyword] = "import_keyword",
  [sym_import_keywords] = "import_keywords",
  [sym_import] = "import",
  [aux_sym_doc_repeat1] = "doc_repeat1",
  [aux_sym_tbd_repeat1] = "tbd_repeat1",
  [aux_sym_import_keywords_repeat1] = "import_keywords_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_tbd_token1] = aux_sym_tbd_token1,
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
  [sym_url] = sym_url,
  [sym_import_keyword] = sym_import_keyword,
  [sym_import_keywords] = sym_import_keywords,
  [sym_import] = sym_import,
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
  [sym_import] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(27);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(3);
      if (lookahead == '(') ADVANCE(37);
      if (lookahead == ')') ADVANCE(38);
      if (lookahead == ',') ADVANCE(42);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == ';') ADVANCE(45);
      if (lookahead == '@') ADVANCE(10);
      if (lookahead == 'u') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(3);
      if (lookahead == '(') ADVANCE(37);
      if (lookahead == 'u') ADVANCE(18);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(46);
      if (lookahead == '\\') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(46);
      if (lookahead == '\\') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == ')') ADVANCE(38);
      if (lookahead == ',') ADVANCE(42);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(24);
      END_STATE();
    case 6:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '/') ADVANCE(49);
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
      if (lookahead == 'e') ADVANCE(44);
      END_STATE();
    case 10:
      if (lookahead == 'i') ADVANCE(13);
      if (lookahead == 'r') ADVANCE(8);
      END_STATE();
    case 11:
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 12:
      if (lookahead == 'l') ADVANCE(35);
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
      if (lookahead == 't') ADVANCE(43);
      END_STATE();
    case 21:
      if (lookahead == 'u') ADVANCE(11);
      END_STATE();
    case 22:
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(2);
      if (lookahead == '"') ADVANCE(47);
      if (lookahead == '\\') ADVANCE(22);
      END_STATE();
    case 23:
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(3);
      if (lookahead == '\'') ADVANCE(48);
      if (lookahead == '\\') ADVANCE(23);
      END_STATE();
    case 24:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(50);
      END_STATE();
    case 25:
      if (eof) ADVANCE(27);
      if (lookahead == '\n') SKIP(25)
      if (lookahead == '"') ADVANCE(29);
      if (lookahead == '\'') ADVANCE(32);
      if (lookahead == '/') ADVANCE(33);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(31);
      if (lookahead != 0) ADVANCE(28);
      END_STATE();
    case 26:
      if (eof) ADVANCE(27);
      if (lookahead == '\n') SKIP(26)
      if (lookahead == '"') ADVANCE(29);
      if (lookahead == '\'') ADVANCE(32);
      if (lookahead == '/') ADVANCE(33);
      if (lookahead == ';') ADVANCE(45);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(30);
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
      if (lookahead == '"') ADVANCE(46);
      if (lookahead == '\\') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '"') ADVANCE(29);
      if (lookahead == '\'') ADVANCE(32);
      if (lookahead == '/') ADVANCE(33);
      if (lookahead == ';') ADVANCE(45);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(30);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(28);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '"') ADVANCE(29);
      if (lookahead == '\'') ADVANCE(32);
      if (lookahead == '/') ADVANCE(33);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(31);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(28);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '\'') ADVANCE(46);
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
      ACCEPT_TOKEN(anon_sym_url);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_url);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym_import_keyword_token1);
      if (lookahead == 'l') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_import_keyword_token1);
      if (lookahead == 'r') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_import_keyword_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_ATimport);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_ATrequire);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '"') ADVANCE(46);
      if (lookahead == '\\') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '\'') ADVANCE(46);
      if (lookahead == '\\') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_comment_block);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_comment_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(50);
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
  [9] = {.lex_state = 25},
  [10] = {.lex_state = 25},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 4},
  [14] = {.lex_state = 4},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 4},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 4},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_url] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [aux_sym_import_keyword_token1] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_ATimport] = ACTIONS(1),
    [anon_sym_ATrequire] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [sym_comment_block] = ACTIONS(1),
    [sym_comment_line] = ACTIONS(1),
  },
  [1] = {
    [sym_doc] = STATE(22),
    [sym_tbd] = STATE(2),
    [sym_import] = STATE(2),
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
      sym_import,
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
      sym_import,
      aux_sym_doc_repeat1,
  [48] = 2,
    ACTIONS(26), 1,
      ts_builtin_sym_end,
    ACTIONS(28), 7,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      anon_sym_SEMI,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [61] = 4,
    ACTIONS(30), 1,
      ts_builtin_sym_end,
    ACTIONS(32), 1,
      aux_sym_tbd_token1,
    STATE(7), 1,
      aux_sym_tbd_repeat1,
    ACTIONS(34), 5,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [78] = 3,
    ACTIONS(36), 1,
      ts_builtin_sym_end,
    ACTIONS(40), 1,
      anon_sym_SEMI,
    ACTIONS(38), 6,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [93] = 4,
    ACTIONS(42), 1,
      ts_builtin_sym_end,
    ACTIONS(44), 1,
      aux_sym_tbd_token1,
    STATE(7), 1,
      aux_sym_tbd_repeat1,
    ACTIONS(47), 5,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [110] = 3,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    ACTIONS(53), 1,
      anon_sym_SEMI,
    ACTIONS(51), 6,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [125] = 2,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    ACTIONS(57), 6,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [137] = 2,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    ACTIONS(51), 6,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      anon_sym_ATrequire,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [149] = 5,
    ACTIONS(59), 1,
      anon_sym_url,
    ACTIONS(61), 1,
      anon_sym_LPAREN,
    ACTIONS(63), 1,
      sym_string,
    STATE(6), 1,
      sym_url,
    STATE(15), 1,
      sym_import_keywords,
  [165] = 3,
    ACTIONS(65), 1,
      anon_sym_RPAREN,
    ACTIONS(67), 1,
      aux_sym_import_keyword_token1,
    STATE(12), 2,
      sym_import_keyword,
      aux_sym_import_keywords_repeat1,
  [176] = 3,
    ACTIONS(70), 1,
      anon_sym_RPAREN,
    ACTIONS(72), 1,
      aux_sym_import_keyword_token1,
    STATE(14), 2,
      sym_import_keyword,
      aux_sym_import_keywords_repeat1,
  [187] = 3,
    ACTIONS(72), 1,
      aux_sym_import_keyword_token1,
    ACTIONS(74), 1,
      anon_sym_RPAREN,
    STATE(12), 2,
      sym_import_keyword,
      aux_sym_import_keywords_repeat1,
  [198] = 3,
    ACTIONS(59), 1,
      anon_sym_url,
    ACTIONS(76), 1,
      sym_string,
    STATE(8), 1,
      sym_url,
  [208] = 2,
    ACTIONS(80), 1,
      anon_sym_COMMA,
    ACTIONS(78), 2,
      anon_sym_RPAREN,
      aux_sym_import_keyword_token1,
  [216] = 1,
    ACTIONS(82), 2,
      anon_sym_url,
      sym_string,
  [221] = 1,
    ACTIONS(84), 2,
      anon_sym_RPAREN,
      aux_sym_import_keyword_token1,
  [226] = 1,
    ACTIONS(86), 2,
      anon_sym_url,
      sym_string,
  [231] = 1,
    ACTIONS(88), 1,
      sym_string,
  [235] = 1,
    ACTIONS(90), 1,
      anon_sym_RPAREN,
  [239] = 1,
    ACTIONS(92), 1,
      ts_builtin_sym_end,
  [243] = 1,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 48,
  [SMALL_STATE(5)] = 61,
  [SMALL_STATE(6)] = 78,
  [SMALL_STATE(7)] = 93,
  [SMALL_STATE(8)] = 110,
  [SMALL_STATE(9)] = 125,
  [SMALL_STATE(10)] = 137,
  [SMALL_STATE(11)] = 149,
  [SMALL_STATE(12)] = 165,
  [SMALL_STATE(13)] = 176,
  [SMALL_STATE(14)] = 187,
  [SMALL_STATE(15)] = 198,
  [SMALL_STATE(16)] = 208,
  [SMALL_STATE(17)] = 216,
  [SMALL_STATE(18)] = 221,
  [SMALL_STATE(19)] = 226,
  [SMALL_STATE(20)] = 231,
  [SMALL_STATE(21)] = 235,
  [SMALL_STATE(22)] = 239,
  [SMALL_STATE(23)] = 243,
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
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_url, 4),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_url, 4),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tbd, 1),
  [32] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [34] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tbd, 1),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 2),
  [38] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import, 2),
  [40] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tbd_repeat1, 2),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_tbd_repeat1, 2), SHIFT_REPEAT(7),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_tbd_repeat1, 2),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 3),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import, 3),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 4),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import, 4),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_keywords_repeat1, 2),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_keywords_repeat1, 2), SHIFT_REPEAT(16),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keyword, 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keywords, 2),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keyword, 2),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keywords, 3),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [92] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
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
