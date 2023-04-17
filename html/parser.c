#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 100
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 45
#define ALIAS_COUNT 0
#define TOKEN_COUNT 28
#define EXTERNAL_TOKEN_COUNT 9
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_LT_BANG = 1,
  aux_sym_doctype_token1 = 2,
  anon_sym_GT = 3,
  sym__doctype = 4,
  anon_sym_LBRACE_LBRACE_LBRACE = 5,
  anon_sym_RBRACE_RBRACE_RBRACE = 6,
  sym_tribracket_content = 7,
  anon_sym_LT = 8,
  anon_sym_SLASH_GT = 9,
  anon_sym_LT_SLASH = 10,
  anon_sym_EQ = 11,
  sym_attribute_name = 12,
  sym_attribute_value = 13,
  sym_entity = 14,
  anon_sym_SQUOTE = 15,
  aux_sym_quoted_attribute_value_token1 = 16,
  anon_sym_DQUOTE = 17,
  aux_sym_quoted_attribute_value_token2 = 18,
  sym_text = 19,
  sym__start_tag_name = 20,
  sym__script_start_tag_name = 21,
  sym__style_start_tag_name = 22,
  sym__end_tag_name = 23,
  sym_erroneous_end_tag_name = 24,
  sym__implicit_end_tag = 25,
  sym_raw_text = 26,
  sym_comment = 27,
  sym_fragment = 28,
  sym_doctype = 29,
  sym__node = 30,
  sym_tribracket = 31,
  sym_element = 32,
  sym_script_element = 33,
  sym_style_element = 34,
  sym_start_tag = 35,
  sym_script_start_tag = 36,
  sym_style_start_tag = 37,
  sym_self_closing_tag = 38,
  sym_end_tag = 39,
  sym_erroneous_end_tag = 40,
  sym_attribute = 41,
  sym_quoted_attribute_value = 42,
  aux_sym_fragment_repeat1 = 43,
  aux_sym_start_tag_repeat1 = 44,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LT_BANG] = "<!",
  [aux_sym_doctype_token1] = "doctype_token1",
  [anon_sym_GT] = ">",
  [sym__doctype] = "doctype",
  [anon_sym_LBRACE_LBRACE_LBRACE] = "{{{",
  [anon_sym_RBRACE_RBRACE_RBRACE] = "}}}",
  [sym_tribracket_content] = "tribracket_content",
  [anon_sym_LT] = "<",
  [anon_sym_SLASH_GT] = "/>",
  [anon_sym_LT_SLASH] = "</",
  [anon_sym_EQ] = "=",
  [sym_attribute_name] = "attribute_name",
  [sym_attribute_value] = "attribute_value",
  [sym_entity] = "entity",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_quoted_attribute_value_token1] = "attribute_value",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_quoted_attribute_value_token2] = "attribute_value",
  [sym_text] = "text",
  [sym__start_tag_name] = "tag_name",
  [sym__script_start_tag_name] = "tag_name",
  [sym__style_start_tag_name] = "tag_name",
  [sym__end_tag_name] = "tag_name",
  [sym_erroneous_end_tag_name] = "erroneous_end_tag_name",
  [sym__implicit_end_tag] = "_implicit_end_tag",
  [sym_raw_text] = "raw_text",
  [sym_comment] = "comment",
  [sym_fragment] = "fragment",
  [sym_doctype] = "doctype",
  [sym__node] = "_node",
  [sym_tribracket] = "tribracket",
  [sym_element] = "element",
  [sym_script_element] = "script_element",
  [sym_style_element] = "style_element",
  [sym_start_tag] = "start_tag",
  [sym_script_start_tag] = "start_tag",
  [sym_style_start_tag] = "start_tag",
  [sym_self_closing_tag] = "self_closing_tag",
  [sym_end_tag] = "end_tag",
  [sym_erroneous_end_tag] = "erroneous_end_tag",
  [sym_attribute] = "attribute",
  [sym_quoted_attribute_value] = "quoted_attribute_value",
  [aux_sym_fragment_repeat1] = "fragment_repeat1",
  [aux_sym_start_tag_repeat1] = "start_tag_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LT_BANG] = anon_sym_LT_BANG,
  [aux_sym_doctype_token1] = aux_sym_doctype_token1,
  [anon_sym_GT] = anon_sym_GT,
  [sym__doctype] = sym__doctype,
  [anon_sym_LBRACE_LBRACE_LBRACE] = anon_sym_LBRACE_LBRACE_LBRACE,
  [anon_sym_RBRACE_RBRACE_RBRACE] = anon_sym_RBRACE_RBRACE_RBRACE,
  [sym_tribracket_content] = sym_tribracket_content,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_SLASH_GT] = anon_sym_SLASH_GT,
  [anon_sym_LT_SLASH] = anon_sym_LT_SLASH,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_attribute_name] = sym_attribute_name,
  [sym_attribute_value] = sym_attribute_value,
  [sym_entity] = sym_entity,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_quoted_attribute_value_token1] = sym_attribute_value,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_quoted_attribute_value_token2] = sym_attribute_value,
  [sym_text] = sym_text,
  [sym__start_tag_name] = sym__start_tag_name,
  [sym__script_start_tag_name] = sym__start_tag_name,
  [sym__style_start_tag_name] = sym__start_tag_name,
  [sym__end_tag_name] = sym__start_tag_name,
  [sym_erroneous_end_tag_name] = sym_erroneous_end_tag_name,
  [sym__implicit_end_tag] = sym__implicit_end_tag,
  [sym_raw_text] = sym_raw_text,
  [sym_comment] = sym_comment,
  [sym_fragment] = sym_fragment,
  [sym_doctype] = sym_doctype,
  [sym__node] = sym__node,
  [sym_tribracket] = sym_tribracket,
  [sym_element] = sym_element,
  [sym_script_element] = sym_script_element,
  [sym_style_element] = sym_style_element,
  [sym_start_tag] = sym_start_tag,
  [sym_script_start_tag] = sym_start_tag,
  [sym_style_start_tag] = sym_start_tag,
  [sym_self_closing_tag] = sym_self_closing_tag,
  [sym_end_tag] = sym_end_tag,
  [sym_erroneous_end_tag] = sym_erroneous_end_tag,
  [sym_attribute] = sym_attribute,
  [sym_quoted_attribute_value] = sym_quoted_attribute_value,
  [aux_sym_fragment_repeat1] = aux_sym_fragment_repeat1,
  [aux_sym_start_tag_repeat1] = aux_sym_start_tag_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LT_BANG] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_doctype_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [sym__doctype] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE_LBRACE_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE_RBRACE_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_tribracket_content] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_SLASH] = {
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
  [sym_entity] = {
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
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym__start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__script_start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__style_start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__end_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym_erroneous_end_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__implicit_end_tag] = {
    .visible = false,
    .named = true,
  },
  [sym_raw_text] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_doctype] = {
    .visible = true,
    .named = true,
  },
  [sym__node] = {
    .visible = false,
    .named = true,
  },
  [sym_tribracket] = {
    .visible = true,
    .named = true,
  },
  [sym_element] = {
    .visible = true,
    .named = true,
  },
  [sym_script_element] = {
    .visible = true,
    .named = true,
  },
  [sym_style_element] = {
    .visible = true,
    .named = true,
  },
  [sym_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_script_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_style_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_self_closing_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_end_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_erroneous_end_tag] = {
    .visible = true,
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
  [aux_sym_fragment_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_start_tag_repeat1] = {
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

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(61);
      if (lookahead == '"') ADVANCE(81);
      if (lookahead == '&') ADVANCE(3);
      if (lookahead == '\'') ADVANCE(78);
      if (lookahead == '/') ADVANCE(45);
      if (lookahead == '<') ADVANCE(71);
      if (lookahead == '=') ADVANCE(74);
      if (lookahead == '>') ADVANCE(65);
      if (lookahead == '{') ADVANCE(47);
      if (lookahead == '}') ADVANCE(49);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(52);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(81);
      if (lookahead == '\'') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(76);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(81);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(82);
      if (lookahead != 0) ADVANCE(83);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(55);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(79);
      if (lookahead != 0) ADVANCE(80);
      END_STATE();
    case 5:
      if (lookahead == '/') ADVANCE(45);
      if (lookahead == '=') ADVANCE(74);
      if (lookahead == '>') ADVANCE(65);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(75);
      END_STATE();
    case 6:
      if (lookahead == ';') ADVANCE(77);
      END_STATE();
    case 7:
      if (lookahead == ';') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(6);
      END_STATE();
    case 8:
      if (lookahead == ';') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(7);
      END_STATE();
    case 9:
      if (lookahead == ';') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == ';') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      END_STATE();
    case 11:
      if (lookahead == ';') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(6);
      END_STATE();
    case 12:
      if (lookahead == ';') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 13:
      if (lookahead == ';') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(12);
      END_STATE();
    case 14:
      if (lookahead == ';') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(13);
      END_STATE();
    case 15:
      if (lookahead == ';') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(14);
      END_STATE();
    case 16:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(6);
      END_STATE();
    case 17:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 18:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 19:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 20:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 21:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 22:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(21);
      END_STATE();
    case 23:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(22);
      END_STATE();
    case 24:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 25:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 26:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 27:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 28:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 29:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(28);
      END_STATE();
    case 30:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 31:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 32:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(31);
      END_STATE();
    case 33:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(32);
      END_STATE();
    case 34:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 35:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(34);
      END_STATE();
    case 36:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 37:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 38:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(37);
      END_STATE();
    case 39:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(38);
      END_STATE();
    case 40:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      END_STATE();
    case 41:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 42:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 43:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 44:
      if (lookahead == ';') ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 45:
      if (lookahead == '>') ADVANCE(72);
      END_STATE();
    case 46:
      if (lookahead == '{') ADVANCE(67);
      END_STATE();
    case 47:
      if (lookahead == '{') ADVANCE(46);
      END_STATE();
    case 48:
      if (lookahead == '}') ADVANCE(68);
      END_STATE();
    case 49:
      if (lookahead == '}') ADVANCE(48);
      END_STATE();
    case 50:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(54);
      END_STATE();
    case 51:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 52:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(50);
      END_STATE();
    case 53:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(51);
      END_STATE();
    case 54:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(56);
      END_STATE();
    case 55:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 56:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(53);
      END_STATE();
    case 57:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(86);
      END_STATE();
    case 58:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(64);
      END_STATE();
    case 59:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 60:
      if (eof) ADVANCE(61);
      if (lookahead == '&') ADVANCE(3);
      if (lookahead == '<') ADVANCE(71);
      if (lookahead == '{') ADVANCE(85);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(60)
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(86);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(64);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_LBRACE);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE_RBRACE);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_tribracket_content);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(70);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_tribracket_content);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(70);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(62);
      if (lookahead == '/') ADVANCE(73);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(75);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(76);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(79);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(80);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(83);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '{') ADVANCE(67);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(86);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(86);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(86);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 60, .external_lex_state = 2},
  [2] = {.lex_state = 60, .external_lex_state = 3},
  [3] = {.lex_state = 60, .external_lex_state = 3},
  [4] = {.lex_state = 60, .external_lex_state = 3},
  [5] = {.lex_state = 60, .external_lex_state = 3},
  [6] = {.lex_state = 60, .external_lex_state = 2},
  [7] = {.lex_state = 60, .external_lex_state = 3},
  [8] = {.lex_state = 60, .external_lex_state = 2},
  [9] = {.lex_state = 60, .external_lex_state = 3},
  [10] = {.lex_state = 60, .external_lex_state = 2},
  [11] = {.lex_state = 60, .external_lex_state = 3},
  [12] = {.lex_state = 60, .external_lex_state = 2},
  [13] = {.lex_state = 60, .external_lex_state = 3},
  [14] = {.lex_state = 60, .external_lex_state = 3},
  [15] = {.lex_state = 60, .external_lex_state = 2},
  [16] = {.lex_state = 60, .external_lex_state = 2},
  [17] = {.lex_state = 60, .external_lex_state = 3},
  [18] = {.lex_state = 60, .external_lex_state = 3},
  [19] = {.lex_state = 60, .external_lex_state = 2},
  [20] = {.lex_state = 60, .external_lex_state = 3},
  [21] = {.lex_state = 60, .external_lex_state = 3},
  [22] = {.lex_state = 60, .external_lex_state = 3},
  [23] = {.lex_state = 60, .external_lex_state = 2},
  [24] = {.lex_state = 60, .external_lex_state = 3},
  [25] = {.lex_state = 60, .external_lex_state = 2},
  [26] = {.lex_state = 60, .external_lex_state = 2},
  [27] = {.lex_state = 60, .external_lex_state = 3},
  [28] = {.lex_state = 60, .external_lex_state = 2},
  [29] = {.lex_state = 60, .external_lex_state = 3},
  [30] = {.lex_state = 60, .external_lex_state = 3},
  [31] = {.lex_state = 60, .external_lex_state = 2},
  [32] = {.lex_state = 60, .external_lex_state = 2},
  [33] = {.lex_state = 60, .external_lex_state = 2},
  [34] = {.lex_state = 60, .external_lex_state = 3},
  [35] = {.lex_state = 60, .external_lex_state = 3},
  [36] = {.lex_state = 60, .external_lex_state = 2},
  [37] = {.lex_state = 5, .external_lex_state = 4},
  [38] = {.lex_state = 5, .external_lex_state = 4},
  [39] = {.lex_state = 5, .external_lex_state = 4},
  [40] = {.lex_state = 5, .external_lex_state = 4},
  [41] = {.lex_state = 5, .external_lex_state = 4},
  [42] = {.lex_state = 5, .external_lex_state = 2},
  [43] = {.lex_state = 5, .external_lex_state = 2},
  [44] = {.lex_state = 5, .external_lex_state = 4},
  [45] = {.lex_state = 1, .external_lex_state = 2},
  [46] = {.lex_state = 1, .external_lex_state = 2},
  [47] = {.lex_state = 5, .external_lex_state = 2},
  [48] = {.lex_state = 5, .external_lex_state = 2},
  [49] = {.lex_state = 5, .external_lex_state = 2},
  [50] = {.lex_state = 5, .external_lex_state = 4},
  [51] = {.lex_state = 0, .external_lex_state = 5},
  [52] = {.lex_state = 0, .external_lex_state = 5},
  [53] = {.lex_state = 5, .external_lex_state = 4},
  [54] = {.lex_state = 0, .external_lex_state = 5},
  [55] = {.lex_state = 0, .external_lex_state = 6},
  [56] = {.lex_state = 5, .external_lex_state = 4},
  [57] = {.lex_state = 0, .external_lex_state = 5},
  [58] = {.lex_state = 0, .external_lex_state = 6},
  [59] = {.lex_state = 5, .external_lex_state = 2},
  [60] = {.lex_state = 4, .external_lex_state = 2},
  [61] = {.lex_state = 4, .external_lex_state = 2},
  [62] = {.lex_state = 0, .external_lex_state = 5},
  [63] = {.lex_state = 0, .external_lex_state = 5},
  [64] = {.lex_state = 2, .external_lex_state = 2},
  [65] = {.lex_state = 0, .external_lex_state = 2},
  [66] = {.lex_state = 2, .external_lex_state = 2},
  [67] = {.lex_state = 0, .external_lex_state = 2},
  [68] = {.lex_state = 0, .external_lex_state = 7},
  [69] = {.lex_state = 0, .external_lex_state = 2},
  [70] = {.lex_state = 0, .external_lex_state = 2},
  [71] = {.lex_state = 0, .external_lex_state = 5},
  [72] = {.lex_state = 0, .external_lex_state = 5},
  [73] = {.lex_state = 5, .external_lex_state = 2},
  [74] = {.lex_state = 5, .external_lex_state = 2},
  [75] = {.lex_state = 5, .external_lex_state = 2},
  [76] = {.lex_state = 0, .external_lex_state = 7},
  [77] = {.lex_state = 0, .external_lex_state = 2},
  [78] = {.lex_state = 0, .external_lex_state = 2},
  [79] = {.lex_state = 0, .external_lex_state = 2},
  [80] = {.lex_state = 0, .external_lex_state = 2},
  [81] = {.lex_state = 0, .external_lex_state = 2},
  [82] = {.lex_state = 0, .external_lex_state = 8},
  [83] = {.lex_state = 58, .external_lex_state = 2},
  [84] = {.lex_state = 0, .external_lex_state = 2},
  [85] = {.lex_state = 0, .external_lex_state = 2},
  [86] = {.lex_state = 0, .external_lex_state = 2},
  [87] = {.lex_state = 0, .external_lex_state = 2},
  [88] = {.lex_state = 69, .external_lex_state = 2},
  [89] = {.lex_state = 0, .external_lex_state = 9},
  [90] = {.lex_state = 0, .external_lex_state = 2},
  [91] = {.lex_state = 0, .external_lex_state = 2},
  [92] = {.lex_state = 0, .external_lex_state = 2},
  [93] = {.lex_state = 69, .external_lex_state = 2},
  [94] = {.lex_state = 0, .external_lex_state = 2},
  [95] = {.lex_state = 0, .external_lex_state = 8},
  [96] = {.lex_state = 58, .external_lex_state = 2},
  [97] = {.lex_state = 0, .external_lex_state = 2},
  [98] = {.lex_state = 0, .external_lex_state = 9},
  [99] = {.lex_state = 0, .external_lex_state = 2},
};

enum {
  ts_external_token__start_tag_name = 0,
  ts_external_token__script_start_tag_name = 1,
  ts_external_token__style_start_tag_name = 2,
  ts_external_token__end_tag_name = 3,
  ts_external_token_erroneous_end_tag_name = 4,
  ts_external_token_SLASH_GT = 5,
  ts_external_token__implicit_end_tag = 6,
  ts_external_token_raw_text = 7,
  ts_external_token_comment = 8,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__start_tag_name] = sym__start_tag_name,
  [ts_external_token__script_start_tag_name] = sym__script_start_tag_name,
  [ts_external_token__style_start_tag_name] = sym__style_start_tag_name,
  [ts_external_token__end_tag_name] = sym__end_tag_name,
  [ts_external_token_erroneous_end_tag_name] = sym_erroneous_end_tag_name,
  [ts_external_token_SLASH_GT] = anon_sym_SLASH_GT,
  [ts_external_token__implicit_end_tag] = sym__implicit_end_tag,
  [ts_external_token_raw_text] = sym_raw_text,
  [ts_external_token_comment] = sym_comment,
};

static const bool ts_external_scanner_states[10][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__start_tag_name] = true,
    [ts_external_token__script_start_tag_name] = true,
    [ts_external_token__style_start_tag_name] = true,
    [ts_external_token__end_tag_name] = true,
    [ts_external_token_erroneous_end_tag_name] = true,
    [ts_external_token_SLASH_GT] = true,
    [ts_external_token__implicit_end_tag] = true,
    [ts_external_token_raw_text] = true,
    [ts_external_token_comment] = true,
  },
  [2] = {
    [ts_external_token_comment] = true,
  },
  [3] = {
    [ts_external_token__implicit_end_tag] = true,
    [ts_external_token_comment] = true,
  },
  [4] = {
    [ts_external_token_SLASH_GT] = true,
    [ts_external_token_comment] = true,
  },
  [5] = {
    [ts_external_token_raw_text] = true,
    [ts_external_token_comment] = true,
  },
  [6] = {
    [ts_external_token__start_tag_name] = true,
    [ts_external_token__script_start_tag_name] = true,
    [ts_external_token__style_start_tag_name] = true,
    [ts_external_token_comment] = true,
  },
  [7] = {
    [ts_external_token__end_tag_name] = true,
    [ts_external_token_erroneous_end_tag_name] = true,
    [ts_external_token_comment] = true,
  },
  [8] = {
    [ts_external_token_erroneous_end_tag_name] = true,
    [ts_external_token_comment] = true,
  },
  [9] = {
    [ts_external_token__end_tag_name] = true,
    [ts_external_token_comment] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LT_BANG] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [sym__doctype] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE_RBRACE_RBRACE] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_SLASH_GT] = ACTIONS(1),
    [anon_sym_LT_SLASH] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_entity] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym__start_tag_name] = ACTIONS(1),
    [sym__script_start_tag_name] = ACTIONS(1),
    [sym__style_start_tag_name] = ACTIONS(1),
    [sym__end_tag_name] = ACTIONS(1),
    [sym_erroneous_end_tag_name] = ACTIONS(1),
    [sym__implicit_end_tag] = ACTIONS(1),
    [sym_raw_text] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_fragment] = STATE(80),
    [sym_doctype] = STATE(6),
    [sym__node] = STATE(6),
    [sym_tribracket] = STATE(6),
    [sym_element] = STATE(6),
    [sym_script_element] = STATE(6),
    [sym_style_element] = STATE(6),
    [sym_start_tag] = STATE(4),
    [sym_script_start_tag] = STATE(52),
    [sym_style_start_tag] = STATE(54),
    [sym_self_closing_tag] = STATE(12),
    [sym_erroneous_end_tag] = STATE(6),
    [aux_sym_fragment_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_LT_BANG] = ACTIONS(7),
    [anon_sym_LBRACE_LBRACE_LBRACE] = ACTIONS(9),
    [anon_sym_LT] = ACTIONS(11),
    [anon_sym_LT_SLASH] = ACTIONS(13),
    [sym_entity] = ACTIONS(15),
    [sym_text] = ACTIONS(17),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_LT_BANG,
    ACTIONS(21), 1,
      anon_sym_LBRACE_LBRACE_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LT,
    ACTIONS(25), 1,
      anon_sym_LT_SLASH,
    ACTIONS(27), 1,
      sym_entity,
    ACTIONS(29), 1,
      sym_text,
    ACTIONS(31), 1,
      sym__implicit_end_tag,
    STATE(3), 1,
      sym_start_tag,
    STATE(11), 1,
      sym_self_closing_tag,
    STATE(21), 1,
      sym_end_tag,
    STATE(51), 1,
      sym_script_start_tag,
    STATE(57), 1,
      sym_style_start_tag,
    STATE(7), 8,
      sym_doctype,
      sym__node,
      sym_tribracket,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_fragment_repeat1,
  [50] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_LT_BANG,
    ACTIONS(21), 1,
      anon_sym_LBRACE_LBRACE_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LT,
    ACTIONS(25), 1,
      anon_sym_LT_SLASH,
    ACTIONS(33), 1,
      sym_entity,
    ACTIONS(35), 1,
      sym_text,
    ACTIONS(37), 1,
      sym__implicit_end_tag,
    STATE(3), 1,
      sym_start_tag,
    STATE(11), 1,
      sym_self_closing_tag,
    STATE(24), 1,
      sym_end_tag,
    STATE(51), 1,
      sym_script_start_tag,
    STATE(57), 1,
      sym_style_start_tag,
    STATE(2), 8,
      sym_doctype,
      sym__node,
      sym_tribracket,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_fragment_repeat1,
  [100] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_LT_BANG,
    ACTIONS(21), 1,
      anon_sym_LBRACE_LBRACE_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LT,
    ACTIONS(39), 1,
      anon_sym_LT_SLASH,
    ACTIONS(41), 1,
      sym_entity,
    ACTIONS(43), 1,
      sym_text,
    ACTIONS(45), 1,
      sym__implicit_end_tag,
    STATE(3), 1,
      sym_start_tag,
    STATE(11), 1,
      sym_self_closing_tag,
    STATE(19), 1,
      sym_end_tag,
    STATE(51), 1,
      sym_script_start_tag,
    STATE(57), 1,
      sym_style_start_tag,
    STATE(5), 8,
      sym_doctype,
      sym__node,
      sym_tribracket,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_fragment_repeat1,
  [150] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_LT_BANG,
    ACTIONS(21), 1,
      anon_sym_LBRACE_LBRACE_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LT,
    ACTIONS(27), 1,
      sym_entity,
    ACTIONS(29), 1,
      sym_text,
    ACTIONS(39), 1,
      anon_sym_LT_SLASH,
    ACTIONS(47), 1,
      sym__implicit_end_tag,
    STATE(3), 1,
      sym_start_tag,
    STATE(11), 1,
      sym_self_closing_tag,
    STATE(33), 1,
      sym_end_tag,
    STATE(51), 1,
      sym_script_start_tag,
    STATE(57), 1,
      sym_style_start_tag,
    STATE(7), 8,
      sym_doctype,
      sym__node,
      sym_tribracket,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_fragment_repeat1,
  [200] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      anon_sym_LBRACE_LBRACE_LBRACE,
    ACTIONS(11), 1,
      anon_sym_LT,
    ACTIONS(13), 1,
      anon_sym_LT_SLASH,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    ACTIONS(51), 1,
      sym_entity,
    ACTIONS(53), 1,
      sym_text,
    STATE(4), 1,
      sym_start_tag,
    STATE(12), 1,
      sym_self_closing_tag,
    STATE(52), 1,
      sym_script_start_tag,
    STATE(54), 1,
      sym_style_start_tag,
    STATE(8), 8,
      sym_doctype,
      sym__node,
      sym_tribracket,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_fragment_repeat1,
  [247] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(55), 1,
      anon_sym_LT_BANG,
    ACTIONS(58), 1,
      anon_sym_LBRACE_LBRACE_LBRACE,
    ACTIONS(61), 1,
      anon_sym_LT,
    ACTIONS(64), 1,
      anon_sym_LT_SLASH,
    ACTIONS(67), 1,
      sym_entity,
    ACTIONS(70), 1,
      sym_text,
    ACTIONS(73), 1,
      sym__implicit_end_tag,
    STATE(3), 1,
      sym_start_tag,
    STATE(11), 1,
      sym_self_closing_tag,
    STATE(51), 1,
      sym_script_start_tag,
    STATE(57), 1,
      sym_style_start_tag,
    STATE(7), 8,
      sym_doctype,
      sym__node,
      sym_tribracket,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_fragment_repeat1,
  [294] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(73), 1,
      ts_builtin_sym_end,
    ACTIONS(75), 1,
      anon_sym_LT_BANG,
    ACTIONS(78), 1,
      anon_sym_LBRACE_LBRACE_LBRACE,
    ACTIONS(81), 1,
      anon_sym_LT,
    ACTIONS(84), 1,
      anon_sym_LT_SLASH,
    ACTIONS(87), 1,
      sym_entity,
    ACTIONS(90), 1,
      sym_text,
    STATE(4), 1,
      sym_start_tag,
    STATE(12), 1,
      sym_self_closing_tag,
    STATE(52), 1,
      sym_script_start_tag,
    STATE(54), 1,
      sym_style_start_tag,
    STATE(8), 8,
      sym_doctype,
      sym__node,
      sym_tribracket,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_fragment_repeat1,
  [341] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(93), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [356] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(93), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [371] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(97), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [386] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(97), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [401] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(101), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [416] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(107), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(105), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [431] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(109), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [446] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(101), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [461] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(113), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [476] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(117), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [491] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(121), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [506] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(125), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [521] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(129), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [536] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(133), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [551] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(137), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [566] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(121), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [581] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(141), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [596] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(107), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(105), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [611] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(145), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [626] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(145), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [641] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(151), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(149), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [656] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(109), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [671] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(117), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [686] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(125), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [701] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(129), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [716] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(137), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [731] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(141), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [746] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 2,
      anon_sym_LT,
      sym_text,
    ACTIONS(133), 5,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      anon_sym_LBRACE_LBRACE_LBRACE,
      anon_sym_LT_SLASH,
      sym_entity,
  [761] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_GT,
    ACTIONS(155), 1,
      anon_sym_SLASH_GT,
    ACTIONS(157), 1,
      sym_attribute_name,
    STATE(41), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [778] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(157), 1,
      sym_attribute_name,
    ACTIONS(159), 1,
      anon_sym_GT,
    ACTIONS(161), 1,
      anon_sym_SLASH_GT,
    STATE(39), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [795] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(165), 1,
      sym_attribute_name,
    ACTIONS(163), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(39), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [810] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_GT,
    ACTIONS(157), 1,
      sym_attribute_name,
    ACTIONS(168), 1,
      anon_sym_SLASH_GT,
    STATE(38), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [827] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(157), 1,
      sym_attribute_name,
    ACTIONS(159), 1,
      anon_sym_GT,
    ACTIONS(170), 1,
      anon_sym_SLASH_GT,
    STATE(39), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [844] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(172), 1,
      anon_sym_GT,
    ACTIONS(174), 1,
      sym_attribute_name,
    STATE(49), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [858] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(174), 1,
      sym_attribute_name,
    ACTIONS(176), 1,
      anon_sym_GT,
    STATE(49), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [872] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(180), 1,
      anon_sym_EQ,
    ACTIONS(178), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [884] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(182), 1,
      sym_attribute_value,
    ACTIONS(184), 1,
      anon_sym_SQUOTE,
    ACTIONS(186), 1,
      anon_sym_DQUOTE,
    STATE(73), 1,
      sym_quoted_attribute_value,
  [900] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(188), 1,
      sym_attribute_value,
    ACTIONS(190), 1,
      anon_sym_SQUOTE,
    ACTIONS(192), 1,
      anon_sym_DQUOTE,
    STATE(50), 1,
      sym_quoted_attribute_value,
  [916] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(174), 1,
      sym_attribute_name,
    ACTIONS(194), 1,
      anon_sym_GT,
    STATE(42), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [930] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(174), 1,
      sym_attribute_name,
    ACTIONS(196), 1,
      anon_sym_GT,
    STATE(43), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [944] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(163), 1,
      anon_sym_GT,
    ACTIONS(198), 1,
      sym_attribute_name,
    STATE(49), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [958] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [967] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 1,
      anon_sym_LT_SLASH,
    ACTIONS(205), 1,
      sym_raw_text,
    STATE(34), 1,
      sym_end_tag,
  [980] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_LT_SLASH,
    ACTIONS(209), 1,
      sym_raw_text,
    STATE(23), 1,
      sym_end_tag,
  [993] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(211), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1002] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_LT_SLASH,
    ACTIONS(213), 1,
      sym_raw_text,
    STATE(25), 1,
      sym_end_tag,
  [1015] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(215), 1,
      sym__start_tag_name,
    ACTIONS(217), 1,
      sym__script_start_tag_name,
    ACTIONS(219), 1,
      sym__style_start_tag_name,
  [1028] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(221), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [1037] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 1,
      anon_sym_LT_SLASH,
    ACTIONS(223), 1,
      sym_raw_text,
    STATE(35), 1,
      sym_end_tag,
  [1050] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      sym__script_start_tag_name,
    ACTIONS(219), 1,
      sym__style_start_tag_name,
    ACTIONS(225), 1,
      sym__start_tag_name,
  [1063] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(227), 1,
      anon_sym_EQ,
    ACTIONS(178), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1074] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(229), 1,
      anon_sym_SQUOTE,
    ACTIONS(231), 1,
      aux_sym_quoted_attribute_value_token1,
  [1084] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(233), 1,
      anon_sym_SQUOTE,
    ACTIONS(235), 1,
      aux_sym_quoted_attribute_value_token1,
  [1094] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(237), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1102] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(239), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1110] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(229), 1,
      anon_sym_DQUOTE,
    ACTIONS(241), 1,
      aux_sym_quoted_attribute_value_token2,
  [1120] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_LT_SLASH,
    STATE(31), 1,
      sym_end_tag,
  [1130] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(233), 1,
      anon_sym_DQUOTE,
    ACTIONS(243), 1,
      aux_sym_quoted_attribute_value_token2,
  [1140] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_LT_SLASH,
    STATE(32), 1,
      sym_end_tag,
  [1150] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(245), 1,
      sym__end_tag_name,
    ACTIONS(247), 1,
      sym_erroneous_end_tag_name,
  [1160] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 1,
      anon_sym_LT_SLASH,
    STATE(18), 1,
      sym_end_tag,
  [1170] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 1,
      anon_sym_LT_SLASH,
    STATE(20), 1,
      sym_end_tag,
  [1180] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(249), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1188] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(251), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1196] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1204] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(211), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1212] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(221), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1220] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(247), 1,
      sym_erroneous_end_tag_name,
    ACTIONS(253), 1,
      sym__end_tag_name,
  [1230] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(255), 1,
      anon_sym_GT,
  [1237] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(257), 1,
      anon_sym_SQUOTE,
  [1244] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(259), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1251] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(261), 1,
      ts_builtin_sym_end,
  [1258] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(263), 1,
      anon_sym_GT,
  [1265] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(265), 1,
      sym_erroneous_end_tag_name,
  [1272] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(267), 1,
      aux_sym_doctype_token1,
  [1279] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(269), 1,
      anon_sym_RBRACE_RBRACE_RBRACE,
  [1286] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(271), 1,
      anon_sym_GT,
  [1293] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_GT,
  [1300] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(275), 1,
      anon_sym_GT,
  [1307] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(277), 1,
      sym_tribracket_content,
  [1314] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(245), 1,
      sym__end_tag_name,
  [1321] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(279), 1,
      anon_sym_GT,
  [1328] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(281), 1,
      anon_sym_SQUOTE,
  [1335] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(281), 1,
      anon_sym_DQUOTE,
  [1342] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(283), 1,
      sym_tribracket_content,
  [1349] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(285), 1,
      sym__doctype,
  [1356] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(247), 1,
      sym_erroneous_end_tag_name,
  [1363] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(287), 1,
      aux_sym_doctype_token1,
  [1370] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(257), 1,
      anon_sym_DQUOTE,
  [1377] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(253), 1,
      sym__end_tag_name,
  [1384] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(289), 1,
      sym__doctype,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 50,
  [SMALL_STATE(4)] = 100,
  [SMALL_STATE(5)] = 150,
  [SMALL_STATE(6)] = 200,
  [SMALL_STATE(7)] = 247,
  [SMALL_STATE(8)] = 294,
  [SMALL_STATE(9)] = 341,
  [SMALL_STATE(10)] = 356,
  [SMALL_STATE(11)] = 371,
  [SMALL_STATE(12)] = 386,
  [SMALL_STATE(13)] = 401,
  [SMALL_STATE(14)] = 416,
  [SMALL_STATE(15)] = 431,
  [SMALL_STATE(16)] = 446,
  [SMALL_STATE(17)] = 461,
  [SMALL_STATE(18)] = 476,
  [SMALL_STATE(19)] = 491,
  [SMALL_STATE(20)] = 506,
  [SMALL_STATE(21)] = 521,
  [SMALL_STATE(22)] = 536,
  [SMALL_STATE(23)] = 551,
  [SMALL_STATE(24)] = 566,
  [SMALL_STATE(25)] = 581,
  [SMALL_STATE(26)] = 596,
  [SMALL_STATE(27)] = 611,
  [SMALL_STATE(28)] = 626,
  [SMALL_STATE(29)] = 641,
  [SMALL_STATE(30)] = 656,
  [SMALL_STATE(31)] = 671,
  [SMALL_STATE(32)] = 686,
  [SMALL_STATE(33)] = 701,
  [SMALL_STATE(34)] = 716,
  [SMALL_STATE(35)] = 731,
  [SMALL_STATE(36)] = 746,
  [SMALL_STATE(37)] = 761,
  [SMALL_STATE(38)] = 778,
  [SMALL_STATE(39)] = 795,
  [SMALL_STATE(40)] = 810,
  [SMALL_STATE(41)] = 827,
  [SMALL_STATE(42)] = 844,
  [SMALL_STATE(43)] = 858,
  [SMALL_STATE(44)] = 872,
  [SMALL_STATE(45)] = 884,
  [SMALL_STATE(46)] = 900,
  [SMALL_STATE(47)] = 916,
  [SMALL_STATE(48)] = 930,
  [SMALL_STATE(49)] = 944,
  [SMALL_STATE(50)] = 958,
  [SMALL_STATE(51)] = 967,
  [SMALL_STATE(52)] = 980,
  [SMALL_STATE(53)] = 993,
  [SMALL_STATE(54)] = 1002,
  [SMALL_STATE(55)] = 1015,
  [SMALL_STATE(56)] = 1028,
  [SMALL_STATE(57)] = 1037,
  [SMALL_STATE(58)] = 1050,
  [SMALL_STATE(59)] = 1063,
  [SMALL_STATE(60)] = 1074,
  [SMALL_STATE(61)] = 1084,
  [SMALL_STATE(62)] = 1094,
  [SMALL_STATE(63)] = 1102,
  [SMALL_STATE(64)] = 1110,
  [SMALL_STATE(65)] = 1120,
  [SMALL_STATE(66)] = 1130,
  [SMALL_STATE(67)] = 1140,
  [SMALL_STATE(68)] = 1150,
  [SMALL_STATE(69)] = 1160,
  [SMALL_STATE(70)] = 1170,
  [SMALL_STATE(71)] = 1180,
  [SMALL_STATE(72)] = 1188,
  [SMALL_STATE(73)] = 1196,
  [SMALL_STATE(74)] = 1204,
  [SMALL_STATE(75)] = 1212,
  [SMALL_STATE(76)] = 1220,
  [SMALL_STATE(77)] = 1230,
  [SMALL_STATE(78)] = 1237,
  [SMALL_STATE(79)] = 1244,
  [SMALL_STATE(80)] = 1251,
  [SMALL_STATE(81)] = 1258,
  [SMALL_STATE(82)] = 1265,
  [SMALL_STATE(83)] = 1272,
  [SMALL_STATE(84)] = 1279,
  [SMALL_STATE(85)] = 1286,
  [SMALL_STATE(86)] = 1293,
  [SMALL_STATE(87)] = 1300,
  [SMALL_STATE(88)] = 1307,
  [SMALL_STATE(89)] = 1314,
  [SMALL_STATE(90)] = 1321,
  [SMALL_STATE(91)] = 1328,
  [SMALL_STATE(92)] = 1335,
  [SMALL_STATE(93)] = 1342,
  [SMALL_STATE(94)] = 1349,
  [SMALL_STATE(95)] = 1356,
  [SMALL_STATE(96)] = 1363,
  [SMALL_STATE(97)] = 1370,
  [SMALL_STATE(98)] = 1377,
  [SMALL_STATE(99)] = 1384,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fragment, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fragment, 1),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(99),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(93),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(55),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(95),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(7),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(7),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(94),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(88),
  [81] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(58),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(82),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(8),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(8),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 3),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 3),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 1),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 1),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 4),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 4),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doctype, 4),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_doctype, 4),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_end_tag, 3),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_end_tag, 3),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 4),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 4),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 3),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 3),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 3),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 3),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag, 3),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_erroneous_end_tag, 3),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 2),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 2),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 2),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 2),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tribracket, 3),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tribracket, 3),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 3),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 3),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2),
  [165] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2), SHIFT_REPEAT(44),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [198] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2), SHIFT_REPEAT(59),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 3),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 3),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 4),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 4),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [261] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_html_external_scanner_create(void);
void tree_sitter_html_external_scanner_destroy(void *);
bool tree_sitter_html_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_html_external_scanner_serialize(void *, char *);
void tree_sitter_html_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_html(void) {
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
      tree_sitter_html_external_scanner_create,
      tree_sitter_html_external_scanner_destroy,
      tree_sitter_html_external_scanner_scan,
      tree_sitter_html_external_scanner_serialize,
      tree_sitter_html_external_scanner_deserialize,
    },
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
