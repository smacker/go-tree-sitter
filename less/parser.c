#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 20
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 19
#define ALIAS_COUNT 0
#define TOKEN_COUNT 11
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum {
  aux_sym_tbd_token1 = 1,
  aux_sym_import_keyword_token1 = 2,
  anon_sym_COMMA = 3,
  anon_sym_LPAREN = 4,
  anon_sym_RPAREN = 5,
  anon_sym_ATimport = 6,
  anon_sym_SEMI = 7,
  sym_string = 8,
  sym_comment_block = 9,
  sym_comment_line = 10,
  sym_doc = 11,
  sym_tbd = 12,
  sym_import_keyword = 13,
  sym_import_keywords = 14,
  sym_import = 15,
  aux_sym_doc_repeat1 = 16,
  aux_sym_tbd_repeat1 = 17,
  aux_sym_import_keywords_repeat1 = 18,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_tbd_token1] = "tbd_token1",
  [aux_sym_import_keyword_token1] = "import_keyword_token1",
  [anon_sym_COMMA] = ",",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_ATimport] = "@import",
  [anon_sym_SEMI] = ";",
  [sym_string] = "string",
  [sym_comment_block] = "comment_block",
  [sym_comment_line] = "comment_line",
  [sym_doc] = "doc",
  [sym_tbd] = "tbd",
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
  [aux_sym_import_keyword_token1] = aux_sym_import_keyword_token1,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_ATimport] = anon_sym_ATimport,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [sym_string] = sym_string,
  [sym_comment_block] = sym_comment_block,
  [sym_comment_line] = sym_comment_line,
  [sym_doc] = sym_doc,
  [sym_tbd] = sym_tbd,
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
  [aux_sym_import_keyword_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COMMA] = {
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
  [anon_sym_ATimport] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(16);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '\'') ADVANCE(2);
      if (lookahead == '(') ADVANCE(25);
      if (lookahead == ')') ADVANCE(26);
      if (lookahead == ',') ADVANCE(24);
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == ';') ADVANCE(28);
      if (lookahead == '@') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '\'') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '/') ADVANCE(14);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '/') ADVANCE(32);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == 'i') ADVANCE(7);
      END_STATE();
    case 7:
      if (lookahead == 'm') ADVANCE(9);
      END_STATE();
    case 8:
      if (lookahead == 'o') ADVANCE(10);
      END_STATE();
    case 9:
      if (lookahead == 'p') ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == 'r') ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == 't') ADVANCE(27);
      END_STATE();
    case 12:
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(1);
      if (lookahead == '"') ADVANCE(30);
      if (lookahead == '\\') ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(2);
      if (lookahead == '\'') ADVANCE(31);
      if (lookahead == '\\') ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(33);
      END_STATE();
    case 15:
      if (eof) ADVANCE(16);
      if (lookahead == '\n') SKIP(15)
      if (lookahead == '"') ADVANCE(18);
      if (lookahead == '\'') ADVANCE(20);
      if (lookahead == '/') ADVANCE(21);
      if (lookahead == '@') ADVANCE(22);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(19);
      if (lookahead != 0) ADVANCE(17);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '"') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(1);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '"') ADVANCE(18);
      if (lookahead == '\'') ADVANCE(20);
      if (lookahead == '/') ADVANCE(21);
      if (lookahead == '@') ADVANCE(22);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '\'') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '/') ADVANCE(14);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == 'i') ADVANCE(7);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_import_keyword_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_ATimport);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '"') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(1);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '\'') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_comment_block);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_comment_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(33);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 15},
  [2] = {.lex_state = 15},
  [3] = {.lex_state = 15},
  [4] = {.lex_state = 15},
  [5] = {.lex_state = 15},
  [6] = {.lex_state = 15},
  [7] = {.lex_state = 15},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym_import_keyword_token1] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_ATimport] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [sym_comment_block] = ACTIONS(1),
    [sym_comment_line] = ACTIONS(1),
  },
  [1] = {
    [sym_doc] = STATE(14),
    [sym_tbd] = STATE(2),
    [sym_import] = STATE(2),
    [aux_sym_doc_repeat1] = STATE(2),
    [aux_sym_tbd_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_tbd_token1] = ACTIONS(5),
    [anon_sym_ATimport] = ACTIONS(7),
    [sym_string] = ACTIONS(9),
    [sym_comment_block] = ACTIONS(9),
    [sym_comment_line] = ACTIONS(9),
  },
  [2] = {
    [sym_tbd] = STATE(3),
    [sym_import] = STATE(3),
    [aux_sym_doc_repeat1] = STATE(3),
    [aux_sym_tbd_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(11),
    [aux_sym_tbd_token1] = ACTIONS(5),
    [anon_sym_ATimport] = ACTIONS(7),
    [sym_string] = ACTIONS(13),
    [sym_comment_block] = ACTIONS(13),
    [sym_comment_line] = ACTIONS(13),
  },
  [3] = {
    [sym_tbd] = STATE(3),
    [sym_import] = STATE(3),
    [aux_sym_doc_repeat1] = STATE(3),
    [aux_sym_tbd_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(15),
    [aux_sym_tbd_token1] = ACTIONS(17),
    [anon_sym_ATimport] = ACTIONS(20),
    [sym_string] = ACTIONS(23),
    [sym_comment_block] = ACTIONS(23),
    [sym_comment_line] = ACTIONS(23),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(26), 1,
      ts_builtin_sym_end,
    ACTIONS(28), 1,
      aux_sym_tbd_token1,
    STATE(5), 1,
      aux_sym_tbd_repeat1,
    ACTIONS(30), 4,
      anon_sym_ATimport,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [16] = 4,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
    ACTIONS(34), 1,
      aux_sym_tbd_token1,
    STATE(5), 1,
      aux_sym_tbd_repeat1,
    ACTIONS(37), 4,
      anon_sym_ATimport,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [32] = 2,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    ACTIONS(41), 5,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [43] = 2,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    ACTIONS(45), 5,
      aux_sym_tbd_token1,
      anon_sym_ATimport,
      sym_string,
      sym_comment_block,
      sym_comment_line,
  [54] = 3,
    ACTIONS(47), 1,
      aux_sym_import_keyword_token1,
    ACTIONS(49), 1,
      anon_sym_RPAREN,
    STATE(9), 2,
      sym_import_keyword,
      aux_sym_import_keywords_repeat1,
  [65] = 3,
    ACTIONS(47), 1,
      aux_sym_import_keyword_token1,
    ACTIONS(51), 1,
      anon_sym_RPAREN,
    STATE(10), 2,
      sym_import_keyword,
      aux_sym_import_keywords_repeat1,
  [76] = 3,
    ACTIONS(53), 1,
      aux_sym_import_keyword_token1,
    ACTIONS(56), 1,
      anon_sym_RPAREN,
    STATE(10), 2,
      sym_import_keyword,
      aux_sym_import_keywords_repeat1,
  [87] = 3,
    ACTIONS(58), 1,
      anon_sym_LPAREN,
    ACTIONS(60), 1,
      sym_string,
    STATE(16), 1,
      sym_import_keywords,
  [97] = 2,
    ACTIONS(64), 1,
      anon_sym_COMMA,
    ACTIONS(62), 2,
      aux_sym_import_keyword_token1,
      anon_sym_RPAREN,
  [105] = 1,
    ACTIONS(66), 2,
      aux_sym_import_keyword_token1,
      anon_sym_RPAREN,
  [110] = 1,
    ACTIONS(68), 1,
      ts_builtin_sym_end,
  [114] = 1,
    ACTIONS(70), 1,
      anon_sym_SEMI,
  [118] = 1,
    ACTIONS(72), 1,
      sym_string,
  [122] = 1,
    ACTIONS(74), 1,
      sym_string,
  [126] = 1,
    ACTIONS(76), 1,
      anon_sym_SEMI,
  [130] = 1,
    ACTIONS(78), 1,
      sym_string,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 16,
  [SMALL_STATE(6)] = 32,
  [SMALL_STATE(7)] = 43,
  [SMALL_STATE(8)] = 54,
  [SMALL_STATE(9)] = 65,
  [SMALL_STATE(10)] = 76,
  [SMALL_STATE(11)] = 87,
  [SMALL_STATE(12)] = 97,
  [SMALL_STATE(13)] = 105,
  [SMALL_STATE(14)] = 110,
  [SMALL_STATE(15)] = 114,
  [SMALL_STATE(16)] = 118,
  [SMALL_STATE(17)] = 122,
  [SMALL_STATE(18)] = 126,
  [SMALL_STATE(19)] = 130,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doc, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doc, 1),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_doc_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_doc_repeat1, 2), SHIFT_REPEAT(4),
  [20] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_doc_repeat1, 2), SHIFT_REPEAT(11),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_doc_repeat1, 2), SHIFT_REPEAT(3),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tbd, 1),
  [28] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [30] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tbd, 1),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tbd_repeat1, 2),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_tbd_repeat1, 2), SHIFT_REPEAT(5),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_tbd_repeat1, 2),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 3),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import, 3),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 4),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import, 4),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_keywords_repeat1, 2), SHIFT_REPEAT(12),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_keywords_repeat1, 2),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keyword, 1),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keyword, 2),
  [68] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keywords, 2),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_keywords, 3),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_less(void) {
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
