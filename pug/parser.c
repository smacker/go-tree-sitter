#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 52
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 40
#define ALIAS_COUNT 0
#define TOKEN_COUNT 24
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_extends = 1,
  anon_sym_ = 2,
  anon_sym_include = 3,
  anon_sym_link = 4,
  anon_sym_script = 5,
  anon_sym_DOT = 6,
  anon_sym_style = 7,
  aux_sym_path_token1 = 8,
  anon_sym_SLASH = 9,
  anon_sym_LPAREN = 10,
  anon_sym_COMMA = 11,
  anon_sym_RPAREN = 12,
  anon_sym_EQ = 13,
  sym_attribute_name = 14,
  sym_attribute_value = 15,
  anon_sym_SQUOTE = 16,
  aux_sym_quoted_attribute_value_token1 = 17,
  anon_sym_DQUOTE = 18,
  aux_sym_quoted_attribute_value_token2 = 19,
  aux_sym_tbd_token1 = 20,
  sym__newline = 21,
  sym__indent = 22,
  sym__dedent = 23,
  sym_source_file = 24,
  sym_extends_statement = 25,
  sym_include_statement = 26,
  sym_link_tag = 27,
  sym_script_tag = 28,
  sym_style_tag = 29,
  sym_path = 30,
  sym__attributes = 31,
  sym_attribute = 32,
  sym_quoted_attribute_value = 33,
  sym_tbd = 34,
  aux_sym_source_file_repeat1 = 35,
  aux_sym_path_repeat1 = 36,
  aux_sym_path_repeat2 = 37,
  aux_sym__attributes_repeat1 = 38,
  aux_sym_tbd_repeat1 = 39,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_extends] = "extends",
  [anon_sym_] = " ",
  [anon_sym_include] = "include",
  [anon_sym_link] = "link",
  [anon_sym_script] = "script",
  [anon_sym_DOT] = ".",
  [anon_sym_style] = "style",
  [aux_sym_path_token1] = "path_token1",
  [anon_sym_SLASH] = "/",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_EQ] = "=",
  [sym_attribute_name] = "attribute_name",
  [sym_attribute_value] = "attribute_value",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_quoted_attribute_value_token1] = "attribute_value",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_quoted_attribute_value_token2] = "attribute_value",
  [aux_sym_tbd_token1] = "tbd_token1",
  [sym__newline] = "_newline",
  [sym__indent] = "_indent",
  [sym__dedent] = "_dedent",
  [sym_source_file] = "source_file",
  [sym_extends_statement] = "extends_statement",
  [sym_include_statement] = "include_statement",
  [sym_link_tag] = "link_tag",
  [sym_script_tag] = "script_tag",
  [sym_style_tag] = "style_tag",
  [sym_path] = "path",
  [sym__attributes] = "_attributes",
  [sym_attribute] = "attribute",
  [sym_quoted_attribute_value] = "quoted_attribute_value",
  [sym_tbd] = "tbd",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_path_repeat1] = "path_repeat1",
  [aux_sym_path_repeat2] = "path_repeat2",
  [aux_sym__attributes_repeat1] = "_attributes_repeat1",
  [aux_sym_tbd_repeat1] = "tbd_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_extends] = anon_sym_extends,
  [anon_sym_] = anon_sym_,
  [anon_sym_include] = anon_sym_include,
  [anon_sym_link] = anon_sym_link,
  [anon_sym_script] = anon_sym_script,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_style] = anon_sym_style,
  [aux_sym_path_token1] = aux_sym_path_token1,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_attribute_name] = sym_attribute_name,
  [sym_attribute_value] = sym_attribute_value,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_quoted_attribute_value_token1] = sym_attribute_value,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_quoted_attribute_value_token2] = sym_attribute_value,
  [aux_sym_tbd_token1] = aux_sym_tbd_token1,
  [sym__newline] = sym__newline,
  [sym__indent] = sym__indent,
  [sym__dedent] = sym__dedent,
  [sym_source_file] = sym_source_file,
  [sym_extends_statement] = sym_extends_statement,
  [sym_include_statement] = sym_include_statement,
  [sym_link_tag] = sym_link_tag,
  [sym_script_tag] = sym_script_tag,
  [sym_style_tag] = sym_style_tag,
  [sym_path] = sym_path,
  [sym__attributes] = sym__attributes,
  [sym_attribute] = sym_attribute,
  [sym_quoted_attribute_value] = sym_quoted_attribute_value,
  [sym_tbd] = sym_tbd,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_path_repeat1] = aux_sym_path_repeat1,
  [aux_sym_path_repeat2] = aux_sym_path_repeat2,
  [aux_sym__attributes_repeat1] = aux_sym__attributes_repeat1,
  [aux_sym_tbd_repeat1] = aux_sym_tbd_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_extends] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_include] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_link] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_script] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_style] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_path_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_attribute_name] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_value] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_token2] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_tbd_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [sym__indent] = {
    .visible = false,
    .named = true,
  },
  [sym__dedent] = {
    .visible = false,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_extends_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_include_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_link_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_script_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_style_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_path] = {
    .visible = true,
    .named = true,
  },
  [sym__attributes] = {
    .visible = false,
    .named = true,
  },
  [sym_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_attribute_value] = {
    .visible = true,
    .named = true,
  },
  [sym_tbd] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_path_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_path_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__attributes_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tbd_repeat1] = {
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
  [17] = 14,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 11,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 25,
  [29] = 29,
  [30] = 30,
  [31] = 27,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(31);
      if (lookahead == '"') ADVANCE(56);
      if (lookahead == '\'') ADVANCE(53);
      if (lookahead == '(') ADVANCE(45);
      if (lookahead == ')') ADVANCE(48);
      if (lookahead == ',') ADVANCE(46);
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == '/') ADVANCE(44);
      if (lookahead == '=') ADVANCE(50);
      if (lookahead == 'e') ADVANCE(43);
      if (lookahead == 'i') ADVANCE(42);
      if (lookahead == 'l') ADVANCE(41);
      if (lookahead == 's') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(33);
      if (lookahead == ')') ADVANCE(49);
      if (lookahead == ',') ADVANCE(47);
      if (lookahead == '=') ADVANCE(50);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(1)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(51);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(56);
      if (lookahead == '\'') ADVANCE(53);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(52);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(56);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0) ADVANCE(58);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(53);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(54);
      if (lookahead != 0) ADVANCE(55);
      END_STATE();
    case 5:
      if (lookahead == ')') ADVANCE(49);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(51);
      END_STATE();
    case 6:
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == '/') ADVANCE(44);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      END_STATE();
    case 7:
      if (lookahead == 'c') ADVANCE(15);
      END_STATE();
    case 8:
      if (lookahead == 'd') ADVANCE(21);
      END_STATE();
    case 9:
      if (lookahead == 'd') ADVANCE(11);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(34);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(18);
      END_STATE();
    case 13:
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 14:
      if (lookahead == 'k') ADVANCE(35);
      END_STATE();
    case 15:
      if (lookahead == 'l') ADVANCE(24);
      END_STATE();
    case 16:
      if (lookahead == 'l') ADVANCE(10);
      END_STATE();
    case 17:
      if (lookahead == 'n') ADVANCE(14);
      END_STATE();
    case 18:
      if (lookahead == 'n') ADVANCE(8);
      END_STATE();
    case 19:
      if (lookahead == 'p') ADVANCE(23);
      END_STATE();
    case 20:
      if (lookahead == 'r') ADVANCE(13);
      END_STATE();
    case 21:
      if (lookahead == 's') ADVANCE(32);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(12);
      END_STATE();
    case 23:
      if (lookahead == 't') ADVANCE(36);
      END_STATE();
    case 24:
      if (lookahead == 'u') ADVANCE(9);
      END_STATE();
    case 25:
      if (lookahead == 'y') ADVANCE(16);
      END_STATE();
    case 26:
      if (eof) ADVANCE(31);
      if (lookahead == '\n') SKIP(26)
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == 'i') ADVANCE(67);
      if (lookahead == 'l') ADVANCE(66);
      if (lookahead == 's') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(65);
      if (lookahead != 0) ADVANCE(59);
      END_STATE();
    case 27:
      if (eof) ADVANCE(31);
      if (lookahead == '\n') SKIP(27)
      if (lookahead == '(') ADVANCE(45);
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == 'i') ADVANCE(67);
      if (lookahead == 'l') ADVANCE(66);
      if (lookahead == 's') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(60);
      if (lookahead != 0) ADVANCE(59);
      END_STATE();
    case 28:
      if (eof) ADVANCE(31);
      if (lookahead == '\n') SKIP(28)
      if (lookahead == 'e') ADVANCE(43);
      if (lookahead == 'i') ADVANCE(42);
      if (lookahead == 'l') ADVANCE(41);
      if (lookahead == 's') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      if (lookahead != 0) ADVANCE(59);
      END_STATE();
    case 29:
      if (eof) ADVANCE(31);
      if (lookahead == '\n') SKIP(29)
      if (lookahead == '(') ADVANCE(45);
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == 'i') ADVANCE(67);
      if (lookahead == 'l') ADVANCE(66);
      if (lookahead == 's') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(61);
      if (lookahead != 0) ADVANCE(59);
      END_STATE();
    case 30:
      if (eof) ADVANCE(31);
      if (lookahead == '\n') SKIP(30)
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == 'i') ADVANCE(67);
      if (lookahead == 'l') ADVANCE(66);
      if (lookahead == 's') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(62);
      if (lookahead != 0) ADVANCE(59);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_extends);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead == ' ') ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_link);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_style);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym_path_token1);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_path_token1);
      if (lookahead == 'c') ADVANCE(20);
      if (lookahead == 't') ADVANCE(25);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_path_token1);
      if (lookahead == 'i') ADVANCE(17);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_path_token1);
      if (lookahead == 'n') ADVANCE(7);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym_path_token1);
      if (lookahead == 'x') ADVANCE(22);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(51);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(51);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(52);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(55);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(55);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(58);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '(') ADVANCE(45);
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == 'i') ADVANCE(67);
      if (lookahead == 'l') ADVANCE(66);
      if (lookahead == 's') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(60);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(59);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '(') ADVANCE(45);
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == 'i') ADVANCE(67);
      if (lookahead == 'l') ADVANCE(66);
      if (lookahead == 's') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(61);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(59);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == 'i') ADVANCE(67);
      if (lookahead == 'l') ADVANCE(66);
      if (lookahead == 's') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(62);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(59);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == 'c') ADVANCE(20);
      if (lookahead == 't') ADVANCE(25);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == 'e') ADVANCE(43);
      if (lookahead == 'i') ADVANCE(42);
      if (lookahead == 'l') ADVANCE(41);
      if (lookahead == 's') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(59);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == 'i') ADVANCE(67);
      if (lookahead == 'l') ADVANCE(66);
      if (lookahead == 's') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(59);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == 'i') ADVANCE(17);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == 'n') ADVANCE(7);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_tbd_token1);
      if (lookahead == 'x') ADVANCE(22);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 26},
  [2] = {.lex_state = 26},
  [3] = {.lex_state = 26},
  [4] = {.lex_state = 27},
  [5] = {.lex_state = 27},
  [6] = {.lex_state = 28},
  [7] = {.lex_state = 29},
  [8] = {.lex_state = 28},
  [9] = {.lex_state = 26},
  [10] = {.lex_state = 26},
  [11] = {.lex_state = 30},
  [12] = {.lex_state = 30},
  [13] = {.lex_state = 30},
  [14] = {.lex_state = 30},
  [15] = {.lex_state = 26},
  [16] = {.lex_state = 26},
  [17] = {.lex_state = 26},
  [18] = {.lex_state = 26},
  [19] = {.lex_state = 26},
  [20] = {.lex_state = 26},
  [21] = {.lex_state = 26},
  [22] = {.lex_state = 26},
  [23] = {.lex_state = 26},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 5},
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 5},
  [28] = {.lex_state = 5},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 5},
  [32] = {.lex_state = 6},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 6},
  [35] = {.lex_state = 6},
  [36] = {.lex_state = 5},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 6},
  [39] = {.lex_state = 4},
  [40] = {.lex_state = 3},
  [41] = {.lex_state = 5},
  [42] = {.lex_state = 6},
  [43] = {.lex_state = 0, .external_lex_state = 2},
  [44] = {.lex_state = 0, .external_lex_state = 2},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0, .external_lex_state = 2},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 1},
  [50] = {.lex_state = 0, .external_lex_state = 2},
  [51] = {.lex_state = 1},
};

enum {
  ts_external_token__newline = 0,
  ts_external_token__indent = 1,
  ts_external_token__dedent = 2,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__newline] = sym__newline,
  [ts_external_token__indent] = sym__indent,
  [ts_external_token__dedent] = sym__dedent,
};

static const bool ts_external_scanner_states[3][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__newline] = true,
    [ts_external_token__indent] = true,
    [ts_external_token__dedent] = true,
  },
  [2] = {
    [ts_external_token__newline] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_extends] = ACTIONS(1),
    [anon_sym_include] = ACTIONS(1),
    [anon_sym_link] = ACTIONS(1),
    [anon_sym_script] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_style] = ACTIONS(1),
    [aux_sym_path_token1] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [sym__indent] = ACTIONS(1),
    [sym__dedent] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(48),
    [sym_extends_statement] = STATE(3),
    [sym_include_statement] = STATE(3),
    [sym_link_tag] = STATE(3),
    [sym_script_tag] = STATE(3),
    [sym_style_tag] = STATE(3),
    [sym_tbd] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [aux_sym_tbd_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_extends] = ACTIONS(5),
    [anon_sym_include] = ACTIONS(7),
    [anon_sym_link] = ACTIONS(9),
    [anon_sym_script] = ACTIONS(11),
    [anon_sym_style] = ACTIONS(13),
    [aux_sym_tbd_token1] = ACTIONS(15),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    ACTIONS(19), 1,
      anon_sym_extends,
    ACTIONS(22), 1,
      anon_sym_include,
    ACTIONS(25), 1,
      anon_sym_link,
    ACTIONS(28), 1,
      anon_sym_script,
    ACTIONS(31), 1,
      anon_sym_style,
    ACTIONS(34), 1,
      aux_sym_tbd_token1,
    STATE(10), 1,
      aux_sym_tbd_repeat1,
    STATE(2), 7,
      sym_extends_statement,
      sym_include_statement,
      sym_link_tag,
      sym_script_tag,
      sym_style_tag,
      sym_tbd,
      aux_sym_source_file_repeat1,
  [34] = 9,
    ACTIONS(5), 1,
      anon_sym_extends,
    ACTIONS(7), 1,
      anon_sym_include,
    ACTIONS(9), 1,
      anon_sym_link,
    ACTIONS(11), 1,
      anon_sym_script,
    ACTIONS(13), 1,
      anon_sym_style,
    ACTIONS(15), 1,
      aux_sym_tbd_token1,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    STATE(10), 1,
      aux_sym_tbd_repeat1,
    STATE(2), 7,
      sym_extends_statement,
      sym_include_statement,
      sym_link_tag,
      sym_script_tag,
      sym_style_tag,
      sym_tbd,
      aux_sym_source_file_repeat1,
  [68] = 5,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    ACTIONS(43), 1,
      anon_sym_DOT,
    ACTIONS(45), 1,
      anon_sym_LPAREN,
    STATE(12), 1,
      sym__attributes,
    ACTIONS(41), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [89] = 5,
    ACTIONS(45), 1,
      anon_sym_LPAREN,
    ACTIONS(47), 1,
      ts_builtin_sym_end,
    ACTIONS(51), 1,
      anon_sym_DOT,
    STATE(13), 1,
      sym__attributes,
    ACTIONS(49), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [110] = 4,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    ACTIONS(57), 1,
      aux_sym_path_token1,
    STATE(8), 1,
      aux_sym_path_repeat2,
    ACTIONS(55), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [128] = 4,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
    ACTIONS(63), 1,
      anon_sym_LPAREN,
    STATE(19), 1,
      sym__attributes,
    ACTIONS(61), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [146] = 4,
    ACTIONS(65), 1,
      ts_builtin_sym_end,
    ACTIONS(69), 1,
      aux_sym_path_token1,
    STATE(8), 1,
      aux_sym_path_repeat2,
    ACTIONS(67), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [164] = 4,
    ACTIONS(72), 1,
      ts_builtin_sym_end,
    ACTIONS(76), 1,
      aux_sym_tbd_token1,
    STATE(9), 1,
      aux_sym_tbd_repeat1,
    ACTIONS(74), 5,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
  [181] = 4,
    ACTIONS(79), 1,
      ts_builtin_sym_end,
    ACTIONS(83), 1,
      aux_sym_tbd_token1,
    STATE(9), 1,
      aux_sym_tbd_repeat1,
    ACTIONS(81), 5,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
  [198] = 2,
    ACTIONS(85), 1,
      ts_builtin_sym_end,
    ACTIONS(87), 7,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_DOT,
      anon_sym_style,
      aux_sym_tbd_token1,
  [211] = 3,
    ACTIONS(89), 1,
      ts_builtin_sym_end,
    ACTIONS(93), 1,
      anon_sym_DOT,
    ACTIONS(91), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [226] = 3,
    ACTIONS(95), 1,
      ts_builtin_sym_end,
    ACTIONS(99), 1,
      anon_sym_DOT,
    ACTIONS(97), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [241] = 2,
    ACTIONS(101), 1,
      ts_builtin_sym_end,
    ACTIONS(103), 7,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_DOT,
      anon_sym_style,
      aux_sym_tbd_token1,
  [254] = 2,
    ACTIONS(105), 1,
      ts_builtin_sym_end,
    ACTIONS(107), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [266] = 2,
    ACTIONS(109), 1,
      ts_builtin_sym_end,
    ACTIONS(111), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [278] = 2,
    ACTIONS(101), 1,
      ts_builtin_sym_end,
    ACTIONS(103), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [290] = 2,
    ACTIONS(113), 1,
      ts_builtin_sym_end,
    ACTIONS(115), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [302] = 2,
    ACTIONS(117), 1,
      ts_builtin_sym_end,
    ACTIONS(119), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [314] = 2,
    ACTIONS(121), 1,
      ts_builtin_sym_end,
    ACTIONS(123), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [326] = 2,
    ACTIONS(125), 1,
      ts_builtin_sym_end,
    ACTIONS(127), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [338] = 2,
    ACTIONS(129), 1,
      ts_builtin_sym_end,
    ACTIONS(131), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [350] = 2,
    ACTIONS(85), 1,
      ts_builtin_sym_end,
    ACTIONS(87), 6,
      anon_sym_extends,
      anon_sym_include,
      anon_sym_link,
      anon_sym_script,
      anon_sym_style,
      aux_sym_tbd_token1,
  [362] = 3,
    ACTIONS(133), 1,
      anon_sym_,
    ACTIONS(137), 1,
      anon_sym_EQ,
    ACTIONS(135), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_attribute_name,
  [374] = 4,
    ACTIONS(139), 1,
      anon_sym_RPAREN,
    ACTIONS(141), 1,
      sym_attribute_name,
    STATE(29), 1,
      sym_attribute,
    STATE(31), 1,
      aux_sym__attributes_repeat1,
  [387] = 2,
    ACTIONS(143), 1,
      anon_sym_,
    ACTIONS(145), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_attribute_name,
  [396] = 4,
    ACTIONS(141), 1,
      sym_attribute_name,
    ACTIONS(147), 1,
      anon_sym_RPAREN,
    STATE(29), 1,
      sym_attribute,
    STATE(36), 1,
      aux_sym__attributes_repeat1,
  [409] = 4,
    ACTIONS(141), 1,
      sym_attribute_name,
    ACTIONS(149), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      aux_sym__attributes_repeat1,
    STATE(29), 1,
      sym_attribute,
  [422] = 3,
    ACTIONS(151), 1,
      anon_sym_,
    ACTIONS(153), 1,
      anon_sym_COMMA,
    ACTIONS(155), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [433] = 2,
    ACTIONS(157), 1,
      anon_sym_,
    ACTIONS(159), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_attribute_name,
  [442] = 4,
    ACTIONS(141), 1,
      sym_attribute_name,
    ACTIONS(161), 1,
      anon_sym_RPAREN,
    STATE(29), 1,
      sym_attribute,
    STATE(36), 1,
      aux_sym__attributes_repeat1,
  [455] = 3,
    ACTIONS(163), 1,
      anon_sym_DOT,
    STATE(32), 1,
      aux_sym_path_repeat1,
    ACTIONS(165), 2,
      aux_sym_path_token1,
      anon_sym_SLASH,
  [466] = 4,
    ACTIONS(168), 1,
      sym_attribute_value,
    ACTIONS(170), 1,
      anon_sym_SQUOTE,
    ACTIONS(172), 1,
      anon_sym_DQUOTE,
    STATE(37), 1,
      sym_quoted_attribute_value,
  [479] = 3,
    STATE(20), 1,
      sym_path,
    STATE(35), 1,
      aux_sym_path_repeat1,
    ACTIONS(174), 2,
      aux_sym_path_token1,
      anon_sym_SLASH,
  [490] = 3,
    ACTIONS(176), 1,
      anon_sym_DOT,
    STATE(32), 1,
      aux_sym_path_repeat1,
    ACTIONS(178), 2,
      aux_sym_path_token1,
      anon_sym_SLASH,
  [501] = 4,
    ACTIONS(180), 1,
      anon_sym_RPAREN,
    ACTIONS(182), 1,
      sym_attribute_name,
    STATE(29), 1,
      sym_attribute,
    STATE(36), 1,
      aux_sym__attributes_repeat1,
  [514] = 2,
    ACTIONS(185), 1,
      anon_sym_,
    ACTIONS(187), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_attribute_name,
  [523] = 3,
    STATE(22), 1,
      sym_path,
    STATE(35), 1,
      aux_sym_path_repeat1,
    ACTIONS(174), 2,
      aux_sym_path_token1,
      anon_sym_SLASH,
  [534] = 2,
    ACTIONS(189), 1,
      anon_sym_SQUOTE,
    ACTIONS(191), 1,
      aux_sym_quoted_attribute_value_token1,
  [541] = 2,
    ACTIONS(189), 1,
      anon_sym_DQUOTE,
    ACTIONS(193), 1,
      aux_sym_quoted_attribute_value_token2,
  [548] = 1,
    ACTIONS(180), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [553] = 2,
    ACTIONS(195), 1,
      aux_sym_path_token1,
    STATE(6), 1,
      aux_sym_path_repeat2,
  [560] = 1,
    ACTIONS(197), 1,
      sym__newline,
  [564] = 1,
    ACTIONS(199), 1,
      sym__newline,
  [568] = 1,
    ACTIONS(201), 1,
      anon_sym_SQUOTE,
  [572] = 1,
    ACTIONS(201), 1,
      anon_sym_DQUOTE,
  [576] = 1,
    ACTIONS(203), 1,
      sym__newline,
  [580] = 1,
    ACTIONS(205), 1,
      ts_builtin_sym_end,
  [584] = 1,
    ACTIONS(207), 1,
      anon_sym_,
  [588] = 1,
    ACTIONS(209), 1,
      sym__newline,
  [592] = 1,
    ACTIONS(211), 1,
      anon_sym_,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 34,
  [SMALL_STATE(4)] = 68,
  [SMALL_STATE(5)] = 89,
  [SMALL_STATE(6)] = 110,
  [SMALL_STATE(7)] = 128,
  [SMALL_STATE(8)] = 146,
  [SMALL_STATE(9)] = 164,
  [SMALL_STATE(10)] = 181,
  [SMALL_STATE(11)] = 198,
  [SMALL_STATE(12)] = 211,
  [SMALL_STATE(13)] = 226,
  [SMALL_STATE(14)] = 241,
  [SMALL_STATE(15)] = 254,
  [SMALL_STATE(16)] = 266,
  [SMALL_STATE(17)] = 278,
  [SMALL_STATE(18)] = 290,
  [SMALL_STATE(19)] = 302,
  [SMALL_STATE(20)] = 314,
  [SMALL_STATE(21)] = 326,
  [SMALL_STATE(22)] = 338,
  [SMALL_STATE(23)] = 350,
  [SMALL_STATE(24)] = 362,
  [SMALL_STATE(25)] = 374,
  [SMALL_STATE(26)] = 387,
  [SMALL_STATE(27)] = 396,
  [SMALL_STATE(28)] = 409,
  [SMALL_STATE(29)] = 422,
  [SMALL_STATE(30)] = 433,
  [SMALL_STATE(31)] = 442,
  [SMALL_STATE(32)] = 455,
  [SMALL_STATE(33)] = 466,
  [SMALL_STATE(34)] = 479,
  [SMALL_STATE(35)] = 490,
  [SMALL_STATE(36)] = 501,
  [SMALL_STATE(37)] = 514,
  [SMALL_STATE(38)] = 523,
  [SMALL_STATE(39)] = 534,
  [SMALL_STATE(40)] = 541,
  [SMALL_STATE(41)] = 548,
  [SMALL_STATE(42)] = 553,
  [SMALL_STATE(43)] = 560,
  [SMALL_STATE(44)] = 564,
  [SMALL_STATE(45)] = 568,
  [SMALL_STATE(46)] = 572,
  [SMALL_STATE(47)] = 576,
  [SMALL_STATE(48)] = 580,
  [SMALL_STATE(49)] = 584,
  [SMALL_STATE(50)] = 588,
  [SMALL_STATE(51)] = 592,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(51),
  [22] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(49),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(7),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_tag, 1),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_tag, 1),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_tag, 1),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_tag, 1),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 3),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_path, 3),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link_tag, 1),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link_tag, 1),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_repeat2, 2),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_path_repeat2, 2),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat2, 2), SHIFT_REPEAT(8),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tbd_repeat1, 2),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_tbd_repeat1, 2),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_tbd_repeat1, 2), SHIFT_REPEAT(9),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tbd, 1),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tbd, 1),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 2),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attributes, 2),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_tag, 2),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_tag, 2),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_tag, 2),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_tag, 2),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attributes, 3),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attributes, 3),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_tag, 4),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_tag, 4),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_tag, 4),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_tag, 4),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_tag, 3),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_tag, 3),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link_tag, 2),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_link_tag, 2),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_extends_statement, 3),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_extends_statement, 3),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_tag, 3),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_tag, 3),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_statement, 3),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_statement, 3),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 1),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [139] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_attribute_value, 2),
  [147] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [153] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__attributes_repeat1, 1),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_attribute_value, 3),
  [161] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2),
  [165] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(32),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__attributes_repeat1, 2),
  [182] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__attributes_repeat1, 2), SHIFT_REPEAT(24),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [189] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [205] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_pug_external_scanner_create(void);
void tree_sitter_pug_external_scanner_destroy(void *);
bool tree_sitter_pug_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_pug_external_scanner_serialize(void *, char *);
void tree_sitter_pug_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_pug(void) {
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
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_pug_external_scanner_create,
      tree_sitter_pug_external_scanner_destroy,
      tree_sitter_pug_external_scanner_scan,
      tree_sitter_pug_external_scanner_serialize,
      tree_sitter_pug_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
