#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 360
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 119
#define ALIAS_COUNT 8
#define TOKEN_COUNT 62
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 17

enum ts_symbol_identifiers {
  anon_sym_ATimport = 1,
  anon_sym_COMMA = 2,
  anon_sym_SEMI = 3,
  anon_sym_ATmedia = 4,
  anon_sym_ATcharset = 5,
  anon_sym_ATnamespace = 6,
  anon_sym_ATkeyframes = 7,
  aux_sym_keyframes_statement_token1 = 8,
  anon_sym_LBRACE = 9,
  anon_sym_RBRACE = 10,
  sym_from = 11,
  sym_to = 12,
  anon_sym_ATsupports = 13,
  sym_nesting_selector = 14,
  anon_sym_STAR = 15,
  anon_sym_DOT = 16,
  anon_sym_has = 17,
  anon_sym_not = 18,
  anon_sym_is = 19,
  anon_sym_where = 20,
  anon_sym_COLON_COLON = 21,
  anon_sym_POUND = 22,
  anon_sym_LBRACK = 23,
  anon_sym_EQ = 24,
  anon_sym_TILDE_EQ = 25,
  anon_sym_CARET_EQ = 26,
  anon_sym_PIPE_EQ = 27,
  anon_sym_STAR_EQ = 28,
  anon_sym_DOLLAR_EQ = 29,
  anon_sym_RBRACK = 30,
  anon_sym_GT = 31,
  anon_sym_TILDE = 32,
  anon_sym_PLUS = 33,
  anon_sym_PIPE = 34,
  anon_sym_LPAREN = 35,
  anon_sym_RPAREN = 36,
  anon_sym_COLON = 37,
  sym_important = 38,
  anon_sym_LPAREN2 = 39,
  anon_sym_and = 40,
  anon_sym_or = 41,
  anon_sym_only = 42,
  anon_sym_selector = 43,
  aux_sym_color_value_token1 = 44,
  anon_sym_SQUOTE = 45,
  aux_sym_string_value_token1 = 46,
  anon_sym_DQUOTE = 47,
  aux_sym_string_value_token2 = 48,
  aux_sym_integer_value_token1 = 49,
  aux_sym_float_value_token1 = 50,
  sym_unit = 51,
  anon_sym_DASH = 52,
  anon_sym_SLASH = 53,
  sym_identifier = 54,
  sym_at_keyword = 55,
  sym_js_comment = 56,
  sym_comment = 57,
  sym_plain_value = 58,
  sym__descendant_operator = 59,
  sym__pseudo_class_selector_colon = 60,
  sym___error_recovery = 61,
  sym_stylesheet = 62,
  sym_import_statement = 63,
  sym_media_statement = 64,
  sym_charset_statement = 65,
  sym_namespace_statement = 66,
  sym_keyframes_statement = 67,
  sym_keyframe_block_list = 68,
  sym_keyframe_block = 69,
  sym_supports_statement = 70,
  sym_postcss_statement = 71,
  sym_at_rule = 72,
  sym_rule_set = 73,
  sym_selectors = 74,
  sym_block = 75,
  sym__selector = 76,
  sym_universal_selector = 77,
  sym_class_selector = 78,
  sym_pseudo_class_selector = 79,
  sym_pseudo_element_selector = 80,
  sym_id_selector = 81,
  sym_attribute_selector = 82,
  sym_child_selector = 83,
  sym_descendant_selector = 84,
  sym_sibling_selector = 85,
  sym_adjacent_sibling_selector = 86,
  sym_namespace_selector = 87,
  sym_pseudo_class_arguments = 88,
  sym_pseudo_class_with_selector_arguments = 89,
  sym_pseudo_element_arguments = 90,
  sym_declaration = 91,
  sym_last_declaration = 92,
  sym__query = 93,
  sym_feature_query = 94,
  sym_parenthesized_query = 95,
  sym_binary_query = 96,
  sym_unary_query = 97,
  sym_selector_query = 98,
  sym__value = 99,
  sym_parenthesized_value = 100,
  sym_color_value = 101,
  sym_string_value = 102,
  sym_integer_value = 103,
  sym_float_value = 104,
  sym_grid_value = 105,
  sym_call_expression = 106,
  sym_binary_expression = 107,
  sym_arguments = 108,
  aux_sym_stylesheet_repeat1 = 109,
  aux_sym_import_statement_repeat1 = 110,
  aux_sym_keyframe_block_list_repeat1 = 111,
  aux_sym_postcss_statement_repeat1 = 112,
  aux_sym_selectors_repeat1 = 113,
  aux_sym_block_repeat1 = 114,
  aux_sym_pseudo_class_arguments_repeat1 = 115,
  aux_sym_declaration_repeat1 = 116,
  aux_sym_grid_value_repeat1 = 117,
  aux_sym_arguments_repeat1 = 118,
  alias_sym_feature_name = 119,
  alias_sym_function_name = 120,
  alias_sym_id_name = 121,
  alias_sym_keyframes_name = 122,
  alias_sym_keyword_query = 123,
  alias_sym_namespace_name = 124,
  alias_sym_property_name = 125,
  alias_sym_tag_name = 126,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_ATimport] = "@import",
  [anon_sym_COMMA] = ",",
  [anon_sym_SEMI] = ";",
  [anon_sym_ATmedia] = "@media",
  [anon_sym_ATcharset] = "@charset",
  [anon_sym_ATnamespace] = "@namespace",
  [anon_sym_ATkeyframes] = "@keyframes",
  [aux_sym_keyframes_statement_token1] = "at_keyword",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_from] = "from",
  [sym_to] = "to",
  [anon_sym_ATsupports] = "@supports",
  [sym_nesting_selector] = "nesting_selector",
  [anon_sym_STAR] = "*",
  [anon_sym_DOT] = ".",
  [anon_sym_has] = "class_name",
  [anon_sym_not] = "not",
  [anon_sym_is] = "class_name",
  [anon_sym_where] = "class_name",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_POUND] = "#",
  [anon_sym_LBRACK] = "[",
  [anon_sym_EQ] = "=",
  [anon_sym_TILDE_EQ] = "~=",
  [anon_sym_CARET_EQ] = "^=",
  [anon_sym_PIPE_EQ] = "|=",
  [anon_sym_STAR_EQ] = "*=",
  [anon_sym_DOLLAR_EQ] = "$=",
  [anon_sym_RBRACK] = "]",
  [anon_sym_GT] = ">",
  [anon_sym_TILDE] = "~",
  [anon_sym_PLUS] = "+",
  [anon_sym_PIPE] = "|",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [sym_important] = "important",
  [anon_sym_LPAREN2] = "(",
  [anon_sym_and] = "and",
  [anon_sym_or] = "or",
  [anon_sym_only] = "only",
  [anon_sym_selector] = "selector",
  [aux_sym_color_value_token1] = "color_value_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_string_value_token1] = "string_value_token1",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_value_token2] = "string_value_token2",
  [aux_sym_integer_value_token1] = "integer_value_token1",
  [aux_sym_float_value_token1] = "float_value_token1",
  [sym_unit] = "unit",
  [anon_sym_DASH] = "-",
  [anon_sym_SLASH] = "/",
  [sym_identifier] = "attribute_name",
  [sym_at_keyword] = "at_keyword",
  [sym_js_comment] = "js_comment",
  [sym_comment] = "comment",
  [sym_plain_value] = "plain_value",
  [sym__descendant_operator] = "_descendant_operator",
  [sym__pseudo_class_selector_colon] = ":",
  [sym___error_recovery] = "__error_recovery",
  [sym_stylesheet] = "stylesheet",
  [sym_import_statement] = "import_statement",
  [sym_media_statement] = "media_statement",
  [sym_charset_statement] = "charset_statement",
  [sym_namespace_statement] = "namespace_statement",
  [sym_keyframes_statement] = "keyframes_statement",
  [sym_keyframe_block_list] = "keyframe_block_list",
  [sym_keyframe_block] = "keyframe_block",
  [sym_supports_statement] = "supports_statement",
  [sym_postcss_statement] = "postcss_statement",
  [sym_at_rule] = "at_rule",
  [sym_rule_set] = "rule_set",
  [sym_selectors] = "selectors",
  [sym_block] = "block",
  [sym__selector] = "_selector",
  [sym_universal_selector] = "universal_selector",
  [sym_class_selector] = "class_selector",
  [sym_pseudo_class_selector] = "pseudo_class_selector",
  [sym_pseudo_element_selector] = "pseudo_element_selector",
  [sym_id_selector] = "id_selector",
  [sym_attribute_selector] = "attribute_selector",
  [sym_child_selector] = "child_selector",
  [sym_descendant_selector] = "descendant_selector",
  [sym_sibling_selector] = "sibling_selector",
  [sym_adjacent_sibling_selector] = "adjacent_sibling_selector",
  [sym_namespace_selector] = "namespace_selector",
  [sym_pseudo_class_arguments] = "arguments",
  [sym_pseudo_class_with_selector_arguments] = "arguments",
  [sym_pseudo_element_arguments] = "arguments",
  [sym_declaration] = "declaration",
  [sym_last_declaration] = "declaration",
  [sym__query] = "_query",
  [sym_feature_query] = "feature_query",
  [sym_parenthesized_query] = "parenthesized_query",
  [sym_binary_query] = "binary_query",
  [sym_unary_query] = "unary_query",
  [sym_selector_query] = "selector_query",
  [sym__value] = "_value",
  [sym_parenthesized_value] = "parenthesized_value",
  [sym_color_value] = "color_value",
  [sym_string_value] = "string_value",
  [sym_integer_value] = "integer_value",
  [sym_float_value] = "float_value",
  [sym_grid_value] = "grid_value",
  [sym_call_expression] = "call_expression",
  [sym_binary_expression] = "binary_expression",
  [sym_arguments] = "arguments",
  [aux_sym_stylesheet_repeat1] = "stylesheet_repeat1",
  [aux_sym_import_statement_repeat1] = "import_statement_repeat1",
  [aux_sym_keyframe_block_list_repeat1] = "keyframe_block_list_repeat1",
  [aux_sym_postcss_statement_repeat1] = "postcss_statement_repeat1",
  [aux_sym_selectors_repeat1] = "selectors_repeat1",
  [aux_sym_block_repeat1] = "block_repeat1",
  [aux_sym_pseudo_class_arguments_repeat1] = "pseudo_class_arguments_repeat1",
  [aux_sym_declaration_repeat1] = "declaration_repeat1",
  [aux_sym_grid_value_repeat1] = "grid_value_repeat1",
  [aux_sym_arguments_repeat1] = "arguments_repeat1",
  [alias_sym_feature_name] = "feature_name",
  [alias_sym_function_name] = "function_name",
  [alias_sym_id_name] = "id_name",
  [alias_sym_keyframes_name] = "keyframes_name",
  [alias_sym_keyword_query] = "keyword_query",
  [alias_sym_namespace_name] = "namespace_name",
  [alias_sym_property_name] = "property_name",
  [alias_sym_tag_name] = "tag_name",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_ATimport] = anon_sym_ATimport,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_ATmedia] = anon_sym_ATmedia,
  [anon_sym_ATcharset] = anon_sym_ATcharset,
  [anon_sym_ATnamespace] = anon_sym_ATnamespace,
  [anon_sym_ATkeyframes] = anon_sym_ATkeyframes,
  [aux_sym_keyframes_statement_token1] = sym_at_keyword,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_from] = sym_from,
  [sym_to] = sym_to,
  [anon_sym_ATsupports] = anon_sym_ATsupports,
  [sym_nesting_selector] = sym_nesting_selector,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_has] = anon_sym_has,
  [anon_sym_not] = anon_sym_not,
  [anon_sym_is] = anon_sym_has,
  [anon_sym_where] = anon_sym_has,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_TILDE_EQ] = anon_sym_TILDE_EQ,
  [anon_sym_CARET_EQ] = anon_sym_CARET_EQ,
  [anon_sym_PIPE_EQ] = anon_sym_PIPE_EQ,
  [anon_sym_STAR_EQ] = anon_sym_STAR_EQ,
  [anon_sym_DOLLAR_EQ] = anon_sym_DOLLAR_EQ,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_important] = sym_important,
  [anon_sym_LPAREN2] = anon_sym_LPAREN,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_or] = anon_sym_or,
  [anon_sym_only] = anon_sym_only,
  [anon_sym_selector] = anon_sym_selector,
  [aux_sym_color_value_token1] = aux_sym_color_value_token1,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_string_value_token1] = aux_sym_string_value_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_value_token2] = aux_sym_string_value_token2,
  [aux_sym_integer_value_token1] = aux_sym_integer_value_token1,
  [aux_sym_float_value_token1] = aux_sym_float_value_token1,
  [sym_unit] = sym_unit,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [sym_identifier] = sym_identifier,
  [sym_at_keyword] = sym_at_keyword,
  [sym_js_comment] = sym_js_comment,
  [sym_comment] = sym_comment,
  [sym_plain_value] = sym_plain_value,
  [sym__descendant_operator] = sym__descendant_operator,
  [sym__pseudo_class_selector_colon] = anon_sym_COLON,
  [sym___error_recovery] = sym___error_recovery,
  [sym_stylesheet] = sym_stylesheet,
  [sym_import_statement] = sym_import_statement,
  [sym_media_statement] = sym_media_statement,
  [sym_charset_statement] = sym_charset_statement,
  [sym_namespace_statement] = sym_namespace_statement,
  [sym_keyframes_statement] = sym_keyframes_statement,
  [sym_keyframe_block_list] = sym_keyframe_block_list,
  [sym_keyframe_block] = sym_keyframe_block,
  [sym_supports_statement] = sym_supports_statement,
  [sym_postcss_statement] = sym_postcss_statement,
  [sym_at_rule] = sym_at_rule,
  [sym_rule_set] = sym_rule_set,
  [sym_selectors] = sym_selectors,
  [sym_block] = sym_block,
  [sym__selector] = sym__selector,
  [sym_universal_selector] = sym_universal_selector,
  [sym_class_selector] = sym_class_selector,
  [sym_pseudo_class_selector] = sym_pseudo_class_selector,
  [sym_pseudo_element_selector] = sym_pseudo_element_selector,
  [sym_id_selector] = sym_id_selector,
  [sym_attribute_selector] = sym_attribute_selector,
  [sym_child_selector] = sym_child_selector,
  [sym_descendant_selector] = sym_descendant_selector,
  [sym_sibling_selector] = sym_sibling_selector,
  [sym_adjacent_sibling_selector] = sym_adjacent_sibling_selector,
  [sym_namespace_selector] = sym_namespace_selector,
  [sym_pseudo_class_arguments] = sym_arguments,
  [sym_pseudo_class_with_selector_arguments] = sym_arguments,
  [sym_pseudo_element_arguments] = sym_arguments,
  [sym_declaration] = sym_declaration,
  [sym_last_declaration] = sym_declaration,
  [sym__query] = sym__query,
  [sym_feature_query] = sym_feature_query,
  [sym_parenthesized_query] = sym_parenthesized_query,
  [sym_binary_query] = sym_binary_query,
  [sym_unary_query] = sym_unary_query,
  [sym_selector_query] = sym_selector_query,
  [sym__value] = sym__value,
  [sym_parenthesized_value] = sym_parenthesized_value,
  [sym_color_value] = sym_color_value,
  [sym_string_value] = sym_string_value,
  [sym_integer_value] = sym_integer_value,
  [sym_float_value] = sym_float_value,
  [sym_grid_value] = sym_grid_value,
  [sym_call_expression] = sym_call_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym_arguments] = sym_arguments,
  [aux_sym_stylesheet_repeat1] = aux_sym_stylesheet_repeat1,
  [aux_sym_import_statement_repeat1] = aux_sym_import_statement_repeat1,
  [aux_sym_keyframe_block_list_repeat1] = aux_sym_keyframe_block_list_repeat1,
  [aux_sym_postcss_statement_repeat1] = aux_sym_postcss_statement_repeat1,
  [aux_sym_selectors_repeat1] = aux_sym_selectors_repeat1,
  [aux_sym_block_repeat1] = aux_sym_block_repeat1,
  [aux_sym_pseudo_class_arguments_repeat1] = aux_sym_pseudo_class_arguments_repeat1,
  [aux_sym_declaration_repeat1] = aux_sym_declaration_repeat1,
  [aux_sym_grid_value_repeat1] = aux_sym_grid_value_repeat1,
  [aux_sym_arguments_repeat1] = aux_sym_arguments_repeat1,
  [alias_sym_feature_name] = alias_sym_feature_name,
  [alias_sym_function_name] = alias_sym_function_name,
  [alias_sym_id_name] = alias_sym_id_name,
  [alias_sym_keyframes_name] = alias_sym_keyframes_name,
  [alias_sym_keyword_query] = alias_sym_keyword_query,
  [alias_sym_namespace_name] = alias_sym_namespace_name,
  [alias_sym_property_name] = alias_sym_property_name,
  [alias_sym_tag_name] = alias_sym_tag_name,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_ATimport] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATmedia] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATcharset] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATnamespace] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATkeyframes] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_keyframes_statement_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_from] = {
    .visible = true,
    .named = true,
  },
  [sym_to] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_ATsupports] = {
    .visible = true,
    .named = false,
  },
  [sym_nesting_selector] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_has] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_not] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_is] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_where] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
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
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_important] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_only] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_selector] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_color_value_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_value_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_value_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_integer_value_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_float_value_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_unit] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_at_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_js_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_plain_value] = {
    .visible = true,
    .named = true,
  },
  [sym__descendant_operator] = {
    .visible = false,
    .named = true,
  },
  [sym__pseudo_class_selector_colon] = {
    .visible = true,
    .named = false,
  },
  [sym___error_recovery] = {
    .visible = false,
    .named = true,
  },
  [sym_stylesheet] = {
    .visible = true,
    .named = true,
  },
  [sym_import_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_media_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_charset_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_namespace_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_keyframes_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_keyframe_block_list] = {
    .visible = true,
    .named = true,
  },
  [sym_keyframe_block] = {
    .visible = true,
    .named = true,
  },
  [sym_supports_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_postcss_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_at_rule] = {
    .visible = true,
    .named = true,
  },
  [sym_rule_set] = {
    .visible = true,
    .named = true,
  },
  [sym_selectors] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym__selector] = {
    .visible = false,
    .named = true,
  },
  [sym_universal_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_class_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_pseudo_class_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_pseudo_element_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_id_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_child_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_descendant_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_sibling_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_adjacent_sibling_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_namespace_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_pseudo_class_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_pseudo_class_with_selector_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_pseudo_element_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_last_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym__query] = {
    .visible = false,
    .named = true,
  },
  [sym_feature_query] = {
    .visible = true,
    .named = true,
  },
  [sym_parenthesized_query] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_query] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_query] = {
    .visible = true,
    .named = true,
  },
  [sym_selector_query] = {
    .visible = true,
    .named = true,
  },
  [sym__value] = {
    .visible = false,
    .named = true,
  },
  [sym_parenthesized_value] = {
    .visible = true,
    .named = true,
  },
  [sym_color_value] = {
    .visible = true,
    .named = true,
  },
  [sym_string_value] = {
    .visible = true,
    .named = true,
  },
  [sym_integer_value] = {
    .visible = true,
    .named = true,
  },
  [sym_float_value] = {
    .visible = true,
    .named = true,
  },
  [sym_grid_value] = {
    .visible = true,
    .named = true,
  },
  [sym_call_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_arguments] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_stylesheet_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_import_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_keyframe_block_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_postcss_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_selectors_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pseudo_class_arguments_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_grid_value_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arguments_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_feature_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_function_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_id_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_keyframes_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_keyword_query] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_namespace_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_property_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_tag_name] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = alias_sym_tag_name,
  },
  [2] = {
    [1] = anon_sym_has,
  },
  [3] = {
    [0] = sym_plain_value,
  },
  [4] = {
    [0] = alias_sym_keyword_query,
  },
  [5] = {
    [1] = alias_sym_tag_name,
  },
  [6] = {
    [1] = alias_sym_id_name,
  },
  [7] = {
    [0] = alias_sym_function_name,
  },
  [8] = {
    [1] = alias_sym_keyframes_name,
  },
  [9] = {
    [1] = sym_identifier,
  },
  [10] = {
    [2] = anon_sym_has,
  },
  [11] = {
    [2] = alias_sym_tag_name,
  },
  [12] = {
    [2] = alias_sym_id_name,
  },
  [13] = {
    [1] = alias_sym_namespace_name,
  },
  [14] = {
    [0] = alias_sym_property_name,
  },
  [15] = {
    [2] = sym_identifier,
  },
  [16] = {
    [1] = alias_sym_feature_name,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym_namespace_selector, 2,
    sym_namespace_selector,
    sym_identifier,
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 2,
  [4] = 4,
  [5] = 4,
  [6] = 2,
  [7] = 4,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 14,
  [16] = 16,
  [17] = 17,
  [18] = 17,
  [19] = 19,
  [20] = 20,
  [21] = 20,
  [22] = 22,
  [23] = 23,
  [24] = 23,
  [25] = 25,
  [26] = 23,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
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
  [49] = 46,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 52,
  [55] = 55,
  [56] = 52,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 38,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 96,
  [114] = 91,
  [115] = 106,
  [116] = 111,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 92,
  [121] = 93,
  [122] = 109,
  [123] = 123,
  [124] = 94,
  [125] = 98,
  [126] = 100,
  [127] = 103,
  [128] = 108,
  [129] = 129,
  [130] = 130,
  [131] = 97,
  [132] = 99,
  [133] = 133,
  [134] = 105,
  [135] = 110,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 111,
  [140] = 140,
  [141] = 123,
  [142] = 90,
  [143] = 118,
  [144] = 129,
  [145] = 119,
  [146] = 130,
  [147] = 147,
  [148] = 117,
  [149] = 149,
  [150] = 140,
  [151] = 95,
  [152] = 147,
  [153] = 149,
  [154] = 154,
  [155] = 140,
  [156] = 95,
  [157] = 102,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 38,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 179,
  [180] = 180,
  [181] = 179,
  [182] = 182,
  [183] = 182,
  [184] = 180,
  [185] = 40,
  [186] = 38,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 188,
  [195] = 195,
  [196] = 196,
  [197] = 80,
  [198] = 136,
  [199] = 199,
  [200] = 200,
  [201] = 199,
  [202] = 137,
  [203] = 203,
  [204] = 204,
  [205] = 159,
  [206] = 206,
  [207] = 207,
  [208] = 208,
  [209] = 200,
  [210] = 210,
  [211] = 211,
  [212] = 166,
  [213] = 38,
  [214] = 163,
  [215] = 164,
  [216] = 162,
  [217] = 165,
  [218] = 158,
  [219] = 161,
  [220] = 168,
  [221] = 160,
  [222] = 80,
  [223] = 167,
  [224] = 137,
  [225] = 136,
  [226] = 167,
  [227] = 161,
  [228] = 165,
  [229] = 163,
  [230] = 160,
  [231] = 158,
  [232] = 166,
  [233] = 159,
  [234] = 38,
  [235] = 164,
  [236] = 162,
  [237] = 168,
  [238] = 238,
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 238,
  [243] = 243,
  [244] = 239,
  [245] = 239,
  [246] = 246,
  [247] = 246,
  [248] = 240,
  [249] = 241,
  [250] = 250,
  [251] = 251,
  [252] = 252,
  [253] = 253,
  [254] = 254,
  [255] = 255,
  [256] = 256,
  [257] = 257,
  [258] = 253,
  [259] = 259,
  [260] = 260,
  [261] = 261,
  [262] = 262,
  [263] = 263,
  [264] = 264,
  [265] = 265,
  [266] = 265,
  [267] = 263,
  [268] = 268,
  [269] = 265,
  [270] = 270,
  [271] = 270,
  [272] = 268,
  [273] = 273,
  [274] = 262,
  [275] = 275,
  [276] = 105,
  [277] = 277,
  [278] = 278,
  [279] = 279,
  [280] = 280,
  [281] = 281,
  [282] = 281,
  [283] = 275,
  [284] = 281,
  [285] = 109,
  [286] = 129,
  [287] = 287,
  [288] = 288,
  [289] = 279,
  [290] = 290,
  [291] = 291,
  [292] = 292,
  [293] = 293,
  [294] = 294,
  [295] = 295,
  [296] = 296,
  [297] = 295,
  [298] = 295,
  [299] = 299,
  [300] = 296,
  [301] = 301,
  [302] = 302,
  [303] = 303,
  [304] = 304,
  [305] = 305,
  [306] = 136,
  [307] = 304,
  [308] = 308,
  [309] = 309,
  [310] = 309,
  [311] = 311,
  [312] = 302,
  [313] = 313,
  [314] = 314,
  [315] = 315,
  [316] = 316,
  [317] = 317,
  [318] = 318,
  [319] = 319,
  [320] = 318,
  [321] = 313,
  [322] = 318,
  [323] = 316,
  [324] = 324,
  [325] = 325,
  [326] = 326,
  [327] = 327,
  [328] = 316,
  [329] = 317,
  [330] = 316,
  [331] = 317,
  [332] = 316,
  [333] = 317,
  [334] = 334,
  [335] = 335,
  [336] = 327,
  [337] = 315,
  [338] = 325,
  [339] = 315,
  [340] = 340,
  [341] = 314,
  [342] = 317,
  [343] = 343,
  [344] = 344,
  [345] = 345,
  [346] = 313,
  [347] = 344,
  [348] = 340,
  [349] = 314,
  [350] = 350,
  [351] = 340,
  [352] = 340,
  [353] = 314,
  [354] = 340,
  [355] = 314,
  [356] = 340,
  [357] = 314,
  [358] = 316,
  [359] = 317,
};

static TSCharacterRange sym_plain_value_character_set_1[] = {
  {0, 0x08}, {0x0e, 0x1f}, {'"', '\''}, {'+', '+'}, {'-', ':'}, {'<', 'Z'}, {'\\', '\\'}, {'^', 'z'},
  {'|', '|'}, {'~', 0x10ffff},
};

static TSCharacterRange sym_plain_value_character_set_2[] = {
  {0, 0x08}, {0x0e, 0x1f}, {'"', '\''}, {'*', '+'}, {'-', ':'}, {'<', 'Z'}, {'\\', '\\'}, {'^', 'z'},
  {'|', '|'}, {'~', 0x10ffff},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(70);
      ADVANCE_MAP(
        '!', 44,
        '"', 177,
        '#', 98,
        '$', 38,
        '&', 86,
        '\'', 167,
        '(', 114,
        ')', 115,
        '*', 88,
        '+', 111,
        ',', 72,
        '-', 215,
        '.', 90,
        '/', 217,
        ':', 116,
        ';', 73,
        '=', 100,
        '>', 107,
        '@', 42,
        '[', 99,
        ']', 106,
        '^', 40,
        'a', 251,
        'f', 260,
        'h', 240,
        'i', 263,
        'n', 255,
        'o', 253,
        's', 245,
        't', 256,
        'w', 247,
        '{', 79,
        '|', 113,
        '}', 80,
        '~', 109,
        'E', 219,
        'e', 219,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(67);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'd')) ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(188);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '!', 44,
        '"', 177,
        '#', 98,
        '%', 212,
        '\'', 167,
        '(', 118,
        ')', 115,
        '*', 87,
        '+', 111,
        ',', 72,
        '-', 214,
        '.', 59,
        '/', 218,
        ';', 73,
        '[', 99,
        '_', 222,
        '}', 80,
        'E', 209,
        'e', 209,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(210);
      if ((0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '!', 44,
        '"', 177,
        '#', 98,
        '&', 86,
        '\'', 167,
        '(', 118,
        ')', 115,
        '*', 87,
        '+', 32,
        ',', 72,
        '-', 31,
        '.', 90,
        '/', 23,
        ':', 37,
        ';', 73,
        '[', 99,
        '_', 222,
        '}', 80,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      if ((0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '!', 44,
        '"', 177,
        '#', 98,
        '\'', 167,
        '(', 114,
        ')', 115,
        '*', 87,
        '+', 111,
        ',', 72,
        '-', 214,
        '.', 90,
        '/', 218,
        ':', 37,
        ';', 73,
        '>', 107,
        '[', 99,
        '_', 222,
        '|', 112,
        '}', 80,
        '~', 108,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      if ((0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '!', 44,
        '"', 177,
        '#', 98,
        '\'', 167,
        '(', 114,
        '*', 87,
        '+', 111,
        ',', 72,
        '-', 214,
        '.', 59,
        '/', 218,
        ';', 73,
        '[', 99,
        '_', 222,
        'a', 230,
        'o', 234,
        '{', 79,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      if ((0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '!', 44,
        '"', 177,
        '#', 98,
        '\'', 167,
        '(', 118,
        ')', 115,
        '*', 87,
        '+', 111,
        ',', 72,
        '-', 214,
        '.', 90,
        '/', 218,
        ':', 37,
        ';', 73,
        '>', 107,
        '[', 99,
        '_', 222,
        '|', 112,
        '}', 80,
        '~', 108,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      if ((0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 6:
      ADVANCE_MAP(
        '!', 44,
        '"', 177,
        '#', 98,
        '\'', 167,
        '(', 118,
        ')', 115,
        '*', 87,
        '+', 111,
        ',', 72,
        '-', 214,
        '.', 59,
        '/', 218,
        ';', 73,
        '[', 99,
        '_', 222,
        '}', 80,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      if ((0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 7:
      ADVANCE_MAP(
        '!', 44,
        '"', 177,
        '#', 98,
        '\'', 167,
        '(', 118,
        '*', 87,
        '+', 111,
        ',', 72,
        '-', 214,
        '.', 59,
        '/', 218,
        ';', 73,
        '[', 99,
        '_', 222,
        'a', 230,
        'o', 234,
        '{', 79,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      if ((0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        '!', 44,
        '"', 177,
        '#', 98,
        '\'', 167,
        '(', 118,
        '+', 32,
        '-', 31,
        '.', 59,
        '/', 23,
        ';', 73,
        '[', 99,
        '_', 222,
        'n', 231,
        'o', 229,
        's', 226,
        '{', 79,
        'E', 221,
        'e', 221,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      if ((0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 9:
      ADVANCE_MAP(
        '#', 98,
        '$', 38,
        '(', 114,
        ')', 115,
        '*', 39,
        '+', 110,
        ',', 72,
        '.', 89,
        '/', 22,
        ':', 116,
        ';', 73,
        '=', 100,
        '>', 107,
        '[', 99,
        ']', 106,
        '^', 40,
        'a', 48,
        'o', 55,
        '{', 79,
        '|', 113,
        '~', 109,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      END_STATE();
    case 10:
      ADVANCE_MAP(
        '#', 98,
        '$', 38,
        '(', 114,
        '*', 88,
        '+', 110,
        ',', 72,
        '-', 213,
        '.', 89,
        '/', 217,
        ':', 37,
        '=', 100,
        '>', 107,
        '[', 99,
        ']', 106,
        '^', 40,
        '|', 113,
        '~', 109,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      END_STATE();
    case 11:
      ADVANCE_MAP(
        '#', 98,
        '$', 38,
        ')', 115,
        '*', 39,
        '+', 110,
        ',', 72,
        '.', 89,
        '/', 22,
        ':', 116,
        ';', 73,
        '=', 100,
        '>', 107,
        '[', 99,
        ']', 106,
        '^', 40,
        'a', 47,
        'o', 55,
        '{', 79,
        '|', 113,
        '~', 109,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      ADVANCE_MAP(
        '#', 98,
        '$', 38,
        '*', 88,
        '+', 110,
        ',', 72,
        '-', 213,
        '.', 89,
        '/', 217,
        ':', 37,
        '=', 100,
        '>', 107,
        '[', 99,
        ']', 106,
        '^', 40,
        '|', 113,
        '~', 109,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      END_STATE();
    case 13:
      ADVANCE_MAP(
        '#', 98,
        '(', 114,
        ')', 115,
        '*', 87,
        '+', 110,
        ',', 72,
        '-', 213,
        '.', 89,
        '/', 217,
        ':', 116,
        ';', 73,
        '>', 107,
        '[', 99,
        ']', 106,
        'a', 47,
        'o', 55,
        '|', 112,
        '~', 108,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      END_STATE();
    case 14:
      ADVANCE_MAP(
        '#', 98,
        ')', 115,
        '*', 87,
        '+', 110,
        ',', 72,
        '-', 213,
        '.', 89,
        '/', 217,
        ':', 116,
        ';', 73,
        '>', 107,
        '[', 99,
        ']', 106,
        'a', 47,
        'o', 55,
        '|', 112,
        '~', 108,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      END_STATE();
    case 15:
      ADVANCE_MAP(
        '%', 212,
        '(', 118,
        '*', 87,
        '+', 110,
        '-', 216,
        '/', 217,
        ';', 73,
        'n', 202,
        'o', 201,
        's', 198,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 16:
      ADVANCE_MAP(
        '(', 114,
        '*', 87,
        '+', 110,
        '-', 216,
        '/', 217,
        ';', 73,
        'n', 255,
        'o', 254,
        's', 245,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 17:
      ADVANCE_MAP(
        '(', 118,
        '*', 87,
        '+', 110,
        '-', 216,
        '/', 217,
        ';', 73,
        'n', 255,
        'o', 254,
        's', 245,
        '{', 79,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(17);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 18:
      ADVANCE_MAP(
        '(', 118,
        '*', 87,
        '+', 110,
        '-', 216,
        '/', 217,
        ';', 73,
        'n', 255,
        'o', 254,
        's', 245,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 19:
      ADVANCE_MAP(
        '(', 118,
        '-', 64,
        '/', 22,
        ';', 73,
        'n', 255,
        'o', 254,
        's', 245,
        '{', 79,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 20:
      ADVANCE_MAP(
        ')', 115,
        '*', 87,
        '+', 110,
        ',', 72,
        '-', 213,
        '/', 217,
        ';', 73,
        ']', 106,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20);
      END_STATE();
    case 21:
      ADVANCE_MAP(
        ')', 115,
        '*', 87,
        '+', 110,
        ',', 72,
        '-', 213,
        '/', 217,
        ';', 73,
        ']', 106,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20);
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(212);
      END_STATE();
    case 22:
      if (lookahead == '*') ADVANCE(25);
      if (lookahead == '/') ADVANCE(323);
      END_STATE();
    case 23:
      if (lookahead == '*') ADVANCE(25);
      if (lookahead == '/') ADVANCE(320);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(36);
      END_STATE();
    case 24:
      if (lookahead == '*') ADVANCE(24);
      if (lookahead == '/') ADVANCE(324);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 25:
      if (lookahead == '*') ADVANCE(24);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 26:
      if (lookahead == '-') ADVANCE(64);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == 'h') ADVANCE(240);
      if (lookahead == 'i') ADVANCE(263);
      if (lookahead == 'n') ADVANCE(255);
      if (lookahead == 'w') ADVANCE(247);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(26);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 27:
      if (lookahead == '-') ADVANCE(64);
      if (lookahead == '/') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(62);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(270);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(64);
      if (lookahead == '/') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 30:
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(155);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(165);
      END_STATE();
    case 31:
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(222);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      if ((0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 32:
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 33:
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == 'f') ADVANCE(56);
      if (lookahead == 't') ADVANCE(51);
      if (lookahead == '}') ADVANCE(80);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(61);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(33);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      END_STATE();
    case 34:
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == '{') ADVANCE(79);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(34);
      END_STATE();
    case 35:
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == '{') ADVANCE(79);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(34);
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(212);
      END_STATE();
    case 36:
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(36);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(325);
      END_STATE();
    case 37:
      if (lookahead == ':') ADVANCE(97);
      END_STATE();
    case 38:
      if (lookahead == '=') ADVANCE(105);
      END_STATE();
    case 39:
      if (lookahead == '=') ADVANCE(104);
      END_STATE();
    case 40:
      if (lookahead == '=') ADVANCE(102);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(49);
      END_STATE();
    case 42:
      if (lookahead == 'c') ADVANCE(290);
      if (lookahead == 'i') ADVANCE(292);
      if (lookahead == 'k') ADVANCE(280);
      if (lookahead == 'm') ADVANCE(281);
      if (lookahead == 'n') ADVANCE(275);
      if (lookahead == 's') ADVANCE(315);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 43:
      if (lookahead == 'd') ADVANCE(119);
      END_STATE();
    case 44:
      if (lookahead == 'i') ADVANCE(45);
      END_STATE();
    case 45:
      if (lookahead == 'm') ADVANCE(53);
      END_STATE();
    case 46:
      if (lookahead == 'm') ADVANCE(81);
      END_STATE();
    case 47:
      if (lookahead == 'n') ADVANCE(43);
      END_STATE();
    case 48:
      if (lookahead == 'n') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(63);
      END_STATE();
    case 49:
      if (lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 50:
      if (lookahead == 'o') ADVANCE(54);
      END_STATE();
    case 51:
      if (lookahead == 'o') ADVANCE(83);
      END_STATE();
    case 52:
      if (lookahead == 'o') ADVANCE(46);
      END_STATE();
    case 53:
      if (lookahead == 'p') ADVANCE(50);
      END_STATE();
    case 54:
      if (lookahead == 'r') ADVANCE(57);
      END_STATE();
    case 55:
      if (lookahead == 'r') ADVANCE(122);
      END_STATE();
    case 56:
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 57:
      if (lookahead == 't') ADVANCE(41);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(117);
      END_STATE();
    case 59:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      END_STATE();
    case 60:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 61:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      END_STATE();
    case 62:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(63);
      END_STATE();
    case 63:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(165);
      END_STATE();
    case 64:
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 65:
      if ((!eof && set_contains(sym_plain_value_character_set_1, 10, lookahead))) ADVANCE(36);
      END_STATE();
    case 66:
      if ((!eof && set_contains(sym_plain_value_character_set_1, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 67:
      if (eof) ADVANCE(70);
      ADVANCE_MAP(
        '!', 44,
        '"', 177,
        '#', 98,
        '$', 38,
        '&', 86,
        '\'', 167,
        '(', 118,
        ')', 115,
        '*', 88,
        '+', 111,
        ',', 72,
        '-', 215,
        '.', 90,
        '/', 217,
        ':', 116,
        ';', 73,
        '=', 100,
        '>', 107,
        '@', 42,
        '[', 99,
        ']', 106,
        '^', 40,
        'a', 252,
        'f', 261,
        'h', 240,
        'i', 263,
        'n', 255,
        'o', 253,
        's', 245,
        't', 256,
        'w', 247,
        '{', 79,
        '|', 113,
        '}', 80,
        '~', 109,
        'E', 220,
        'e', 220,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(67);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 68:
      if (eof) ADVANCE(70);
      ADVANCE_MAP(
        '"', 177,
        '#', 98,
        '&', 86,
        '\'', 167,
        '(', 114,
        ')', 115,
        '*', 87,
        '+', 110,
        ',', 72,
        '-', 64,
        '.', 89,
        '/', 22,
        ':', 116,
        ';', 73,
        '>', 107,
        '@', 42,
        '[', 99,
        ']', 106,
        '{', 79,
        '|', 112,
        '}', 80,
        '~', 108,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(69);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 69:
      if (eof) ADVANCE(70);
      ADVANCE_MAP(
        '"', 177,
        '#', 98,
        '&', 86,
        '\'', 167,
        ')', 115,
        '*', 87,
        '+', 110,
        ',', 72,
        '-', 64,
        '.', 89,
        '/', 22,
        ':', 116,
        ';', 73,
        '>', 107,
        '@', 42,
        '[', 99,
        ']', 106,
        '{', 79,
        '|', 112,
        '}', 80,
        '~', 108,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(69);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_ATimport);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_ATmedia);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_ATcharset);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_ATnamespace);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_ATkeyframes);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_keyframes_statement_token1);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_from);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_from);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_to);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_to);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_ATsupports);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_nesting_selector);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '=') ADVANCE(104);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_has);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_not);
      if (lookahead == '%') ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_not);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_not);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_is);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_where);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_TILDE_EQ);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_CARET_EQ);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_PIPE_EQ);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_DOLLAR_EQ);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_TILDE);
      if (lookahead == '=') ADVANCE(101);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '=') ADVANCE(103);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(97);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_important);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_LPAREN2);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_and);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_and);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_or);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_or);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_only);
      if (lookahead == '%') ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_only);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_only);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_selector);
      if (lookahead == '%') ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_selector);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_selector);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(131);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(147);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(149);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(154);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(163);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(132);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(134);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(133);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(135);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(140);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(136);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(142);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(145);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(166);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(131);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(150);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(158);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(147);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(146);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(156);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(148);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(160);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(149);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(151);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(162);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(154);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(163);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(166);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(131);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(156);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(158);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(160);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(162);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(163);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_color_value_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '\n') ADVANCE(174);
      if (lookahead == '\\') ADVANCE(168);
      if (lookahead != 0) ADVANCE(176);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '*') ADVANCE(171);
      if (lookahead == '/') ADVANCE(176);
      if (lookahead == '\\') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(174);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '*') ADVANCE(170);
      if (lookahead == '/') ADVANCE(174);
      if (lookahead == '\\') ADVANCE(172);
      if (lookahead == '\n' ||
          lookahead == '\'') ADVANCE(25);
      if (lookahead != 0) ADVANCE(171);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '*') ADVANCE(170);
      if (lookahead == '\\') ADVANCE(172);
      if (lookahead == '\n' ||
          lookahead == '\'') ADVANCE(25);
      if (lookahead != 0) ADVANCE(171);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '*') ADVANCE(170);
      if (lookahead == '\\') ADVANCE(172);
      if (lookahead != 0) ADVANCE(171);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '/') ADVANCE(169);
      if (lookahead == '\\') ADVANCE(175);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(173);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '\'') ADVANCE(174);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '\\') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(174);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '\\') ADVANCE(175);
      if (lookahead != 0) ADVANCE(174);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_string_value_token1);
      if (lookahead == '\\') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(176);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '\n') ADVANCE(184);
      if (lookahead == '\\') ADVANCE(178);
      if (lookahead != 0) ADVANCE(186);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '*') ADVANCE(181);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == '\\') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(184);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '*') ADVANCE(180);
      if (lookahead == '/') ADVANCE(184);
      if (lookahead == '\\') ADVANCE(182);
      if (lookahead == '\n' ||
          lookahead == '"') ADVANCE(25);
      if (lookahead != 0) ADVANCE(181);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '*') ADVANCE(180);
      if (lookahead == '\\') ADVANCE(182);
      if (lookahead == '\n' ||
          lookahead == '"') ADVANCE(25);
      if (lookahead != 0) ADVANCE(181);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '*') ADVANCE(180);
      if (lookahead == '\\') ADVANCE(182);
      if (lookahead != 0) ADVANCE(181);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '/') ADVANCE(179);
      if (lookahead == '\\') ADVANCE(185);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(183);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '"') ADVANCE(184);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '\\') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(184);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '\\') ADVANCE(185);
      if (lookahead != 0) ADVANCE(184);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_string_value_token2);
      if (lookahead == '\\') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(186);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(30);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(63);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(189);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(137);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(143);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_integer_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (lookahead == '/') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_float_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(153);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(164);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 'c') ADVANCE(206);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 'e') ADVANCE(196);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 'e') ADVANCE(200);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 'l') ADVANCE(207);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 'l') ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 'n') ADVANCE(199);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 'o') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 'o') ADVANCE(204);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 'r') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 't') ADVANCE(92);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 't') ADVANCE(203);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (lookahead == 'y') ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(212);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(211);
      if (lookahead == '-') ADVANCE(238);
      if (lookahead == '/') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(210);
      if (lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%') ADVANCE(211);
      if (lookahead == '/') ADVANCE(66);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(210);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_unit);
      if (lookahead == '%' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(212);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(222);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      if ((0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(187);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(25);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(25);
      if (lookahead == '/') ADVANCE(320);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(36);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(195);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(269);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(238);
      if (lookahead == '/') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(222);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'c') ADVANCE(236);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'd') ADVANCE(120);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'e') ADVANCE(223);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'e') ADVANCE(228);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'l') ADVANCE(237);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'l') ADVANCE(225);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'n') ADVANCE(227);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'n') ADVANCE(224);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'o') ADVANCE(235);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'o') ADVANCE(233);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'r') ADVANCE(129);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'r') ADVANCE(123);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 't') ADVANCE(93);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 't') ADVANCE(232);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == 'y') ADVANCE(126);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(239);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(264);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(266);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(121);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(241);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(96);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(249);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(262);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(246);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(267);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(243);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(82);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(269);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(242);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(248);
      if (lookahead == 'r') ADVANCE(124);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(248);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(265);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(84);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(250);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(259);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(130);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(269);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(257);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(244);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(95);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(91);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(94);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(258);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(127);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(194);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(164);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(269);
      if (lookahead == '-' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0xa0 <= lookahead && lookahead <= 0xff)) ADVANCE(271);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(302);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(74);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(278);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(293);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(294);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'a') ADVANCE(295);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'c') ADVANCE(282);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'd') ADVANCE(291);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(316);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(279);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(76);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(310);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(313);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(308);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(309);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'e') ADVANCE(317);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'f') ADVANCE(305);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'f') ADVANCE(306);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'h') ADVANCE(272);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'i') ADVANCE(273);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'm') ADVANCE(298);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'm') ADVANCE(283);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'm') ADVANCE(285);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'm') ADVANCE(286);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'o') ADVANCE(303);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'o') ADVANCE(304);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'p') ADVANCE(296);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'p') ADVANCE(274);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'p') ADVANCE(297);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'p') ADVANCE(300);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'r') ADVANCE(311);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'r') ADVANCE(312);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'r') ADVANCE(314);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'r') ADVANCE(276);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'r') ADVANCE(277);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 's') ADVANCE(85);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 's') ADVANCE(77);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 's') ADVANCE(78);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 's') ADVANCE(299);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 's') ADVANCE(284);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 't') ADVANCE(71);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 't') ADVANCE(75);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 't') ADVANCE(307);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'u') ADVANCE(301);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'y') ADVANCE(288);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == 'y') ADVANCE(289);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == 'k') ADVANCE(287);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(319);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_at_keyword);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_js_comment);
      if (lookahead == '/') ADVANCE(321);
      if (lookahead == '-' ||
          lookahead == '_') ADVANCE(320);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(326);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(323);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_js_comment);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ' ||
          lookahead == '!' ||
          ('(' <= lookahead && lookahead <= '*') ||
          lookahead == ',' ||
          lookahead == ';' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(323);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(320);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_js_comment);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ' ||
          lookahead == '!' ||
          ('(' <= lookahead && lookahead <= '*') ||
          lookahead == ',' ||
          lookahead == ';' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(323);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(326);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_js_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(323);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_plain_value);
      if (lookahead == '/') ADVANCE(66);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(325);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_plain_value);
      if (lookahead == '/') ADVANCE(322);
      if ((!eof && set_contains(sym_plain_value_character_set_2, 10, lookahead))) ADVANCE(326);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 68, .external_lex_state = 2},
  [2] = {.lex_state = 68, .external_lex_state = 2},
  [3] = {.lex_state = 68, .external_lex_state = 2},
  [4] = {.lex_state = 68, .external_lex_state = 2},
  [5] = {.lex_state = 68, .external_lex_state = 2},
  [6] = {.lex_state = 68, .external_lex_state = 2},
  [7] = {.lex_state = 68, .external_lex_state = 2},
  [8] = {.lex_state = 68, .external_lex_state = 2},
  [9] = {.lex_state = 68, .external_lex_state = 2},
  [10] = {.lex_state = 68, .external_lex_state = 2},
  [11] = {.lex_state = 2, .external_lex_state = 2},
  [12] = {.lex_state = 2, .external_lex_state = 2},
  [13] = {.lex_state = 2, .external_lex_state = 2},
  [14] = {.lex_state = 2, .external_lex_state = 2},
  [15] = {.lex_state = 2, .external_lex_state = 2},
  [16] = {.lex_state = 8},
  [17] = {.lex_state = 8},
  [18] = {.lex_state = 8},
  [19] = {.lex_state = 5},
  [20] = {.lex_state = 5},
  [21] = {.lex_state = 5},
  [22] = {.lex_state = 3, .external_lex_state = 3},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 68, .external_lex_state = 2},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 68, .external_lex_state = 2},
  [29] = {.lex_state = 68, .external_lex_state = 2},
  [30] = {.lex_state = 68, .external_lex_state = 2},
  [31] = {.lex_state = 68, .external_lex_state = 2},
  [32] = {.lex_state = 10, .external_lex_state = 3},
  [33] = {.lex_state = 68, .external_lex_state = 2},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 68, .external_lex_state = 2},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 5, .external_lex_state = 3},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 5, .external_lex_state = 3},
  [41] = {.lex_state = 68, .external_lex_state = 2},
  [42] = {.lex_state = 68, .external_lex_state = 2},
  [43] = {.lex_state = 2},
  [44] = {.lex_state = 68, .external_lex_state = 2},
  [45] = {.lex_state = 9, .external_lex_state = 3},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 9, .external_lex_state = 3},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 9, .external_lex_state = 3},
  [51] = {.lex_state = 9, .external_lex_state = 3},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 4},
  [54] = {.lex_state = 2},
  [55] = {.lex_state = 2},
  [56] = {.lex_state = 2},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 9, .external_lex_state = 3},
  [59] = {.lex_state = 9, .external_lex_state = 3},
  [60] = {.lex_state = 9, .external_lex_state = 3},
  [61] = {.lex_state = 9, .external_lex_state = 3},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 9, .external_lex_state = 3},
  [64] = {.lex_state = 9, .external_lex_state = 3},
  [65] = {.lex_state = 9, .external_lex_state = 3},
  [66] = {.lex_state = 9, .external_lex_state = 3},
  [67] = {.lex_state = 9, .external_lex_state = 3},
  [68] = {.lex_state = 9, .external_lex_state = 3},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 9, .external_lex_state = 3},
  [71] = {.lex_state = 9, .external_lex_state = 3},
  [72] = {.lex_state = 9, .external_lex_state = 3},
  [73] = {.lex_state = 9, .external_lex_state = 3},
  [74] = {.lex_state = 9, .external_lex_state = 3},
  [75] = {.lex_state = 9, .external_lex_state = 3},
  [76] = {.lex_state = 9, .external_lex_state = 3},
  [77] = {.lex_state = 9, .external_lex_state = 3},
  [78] = {.lex_state = 9, .external_lex_state = 3},
  [79] = {.lex_state = 9, .external_lex_state = 3},
  [80] = {.lex_state = 3},
  [81] = {.lex_state = 9, .external_lex_state = 3},
  [82] = {.lex_state = 9, .external_lex_state = 3},
  [83] = {.lex_state = 9, .external_lex_state = 3},
  [84] = {.lex_state = 9, .external_lex_state = 3},
  [85] = {.lex_state = 9, .external_lex_state = 3},
  [86] = {.lex_state = 9, .external_lex_state = 3},
  [87] = {.lex_state = 9, .external_lex_state = 3},
  [88] = {.lex_state = 9, .external_lex_state = 3},
  [89] = {.lex_state = 9, .external_lex_state = 3},
  [90] = {.lex_state = 68, .external_lex_state = 2},
  [91] = {.lex_state = 68, .external_lex_state = 2},
  [92] = {.lex_state = 68, .external_lex_state = 2},
  [93] = {.lex_state = 68, .external_lex_state = 2},
  [94] = {.lex_state = 68, .external_lex_state = 2},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 68, .external_lex_state = 2},
  [97] = {.lex_state = 68, .external_lex_state = 2},
  [98] = {.lex_state = 68, .external_lex_state = 2},
  [99] = {.lex_state = 68, .external_lex_state = 2},
  [100] = {.lex_state = 68, .external_lex_state = 2},
  [101] = {.lex_state = 2},
  [102] = {.lex_state = 68, .external_lex_state = 2},
  [103] = {.lex_state = 68, .external_lex_state = 2},
  [104] = {.lex_state = 68, .external_lex_state = 2},
  [105] = {.lex_state = 68, .external_lex_state = 2},
  [106] = {.lex_state = 68, .external_lex_state = 2},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 68, .external_lex_state = 2},
  [109] = {.lex_state = 68, .external_lex_state = 2},
  [110] = {.lex_state = 68, .external_lex_state = 2},
  [111] = {.lex_state = 2},
  [112] = {.lex_state = 2},
  [113] = {.lex_state = 68, .external_lex_state = 2},
  [114] = {.lex_state = 68, .external_lex_state = 2},
  [115] = {.lex_state = 68, .external_lex_state = 2},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 2},
  [118] = {.lex_state = 68, .external_lex_state = 2},
  [119] = {.lex_state = 68, .external_lex_state = 2},
  [120] = {.lex_state = 68, .external_lex_state = 2},
  [121] = {.lex_state = 68, .external_lex_state = 2},
  [122] = {.lex_state = 68, .external_lex_state = 2},
  [123] = {.lex_state = 68, .external_lex_state = 2},
  [124] = {.lex_state = 68, .external_lex_state = 2},
  [125] = {.lex_state = 68, .external_lex_state = 2},
  [126] = {.lex_state = 68, .external_lex_state = 2},
  [127] = {.lex_state = 68, .external_lex_state = 2},
  [128] = {.lex_state = 68, .external_lex_state = 2},
  [129] = {.lex_state = 68, .external_lex_state = 2},
  [130] = {.lex_state = 68, .external_lex_state = 2},
  [131] = {.lex_state = 68, .external_lex_state = 2},
  [132] = {.lex_state = 68, .external_lex_state = 2},
  [133] = {.lex_state = 2},
  [134] = {.lex_state = 68, .external_lex_state = 2},
  [135] = {.lex_state = 68, .external_lex_state = 2},
  [136] = {.lex_state = 1},
  [137] = {.lex_state = 1},
  [138] = {.lex_state = 68, .external_lex_state = 2},
  [139] = {.lex_state = 2},
  [140] = {.lex_state = 2},
  [141] = {.lex_state = 68, .external_lex_state = 2},
  [142] = {.lex_state = 68, .external_lex_state = 2},
  [143] = {.lex_state = 68, .external_lex_state = 2},
  [144] = {.lex_state = 68, .external_lex_state = 2},
  [145] = {.lex_state = 68, .external_lex_state = 2},
  [146] = {.lex_state = 68, .external_lex_state = 2},
  [147] = {.lex_state = 2},
  [148] = {.lex_state = 2},
  [149] = {.lex_state = 2},
  [150] = {.lex_state = 2},
  [151] = {.lex_state = 2},
  [152] = {.lex_state = 2},
  [153] = {.lex_state = 2},
  [154] = {.lex_state = 2},
  [155] = {.lex_state = 2},
  [156] = {.lex_state = 2},
  [157] = {.lex_state = 68, .external_lex_state = 2},
  [158] = {.lex_state = 5},
  [159] = {.lex_state = 5},
  [160] = {.lex_state = 5},
  [161] = {.lex_state = 5},
  [162] = {.lex_state = 5},
  [163] = {.lex_state = 5},
  [164] = {.lex_state = 5},
  [165] = {.lex_state = 5},
  [166] = {.lex_state = 5},
  [167] = {.lex_state = 5},
  [168] = {.lex_state = 5},
  [169] = {.lex_state = 5},
  [170] = {.lex_state = 5},
  [171] = {.lex_state = 5},
  [172] = {.lex_state = 9, .external_lex_state = 3},
  [173] = {.lex_state = 5},
  [174] = {.lex_state = 9, .external_lex_state = 3},
  [175] = {.lex_state = 5},
  [176] = {.lex_state = 9, .external_lex_state = 3},
  [177] = {.lex_state = 9, .external_lex_state = 3},
  [178] = {.lex_state = 5},
  [179] = {.lex_state = 5},
  [180] = {.lex_state = 5},
  [181] = {.lex_state = 5},
  [182] = {.lex_state = 17},
  [183] = {.lex_state = 17},
  [184] = {.lex_state = 5},
  [185] = {.lex_state = 13, .external_lex_state = 3},
  [186] = {.lex_state = 13, .external_lex_state = 3},
  [187] = {.lex_state = 19},
  [188] = {.lex_state = 68, .external_lex_state = 3},
  [189] = {.lex_state = 68, .external_lex_state = 3},
  [190] = {.lex_state = 68, .external_lex_state = 3},
  [191] = {.lex_state = 68, .external_lex_state = 3},
  [192] = {.lex_state = 68, .external_lex_state = 3},
  [193] = {.lex_state = 68, .external_lex_state = 3},
  [194] = {.lex_state = 68, .external_lex_state = 3},
  [195] = {.lex_state = 68, .external_lex_state = 3},
  [196] = {.lex_state = 68, .external_lex_state = 3},
  [197] = {.lex_state = 16},
  [198] = {.lex_state = 15},
  [199] = {.lex_state = 19},
  [200] = {.lex_state = 19},
  [201] = {.lex_state = 19},
  [202] = {.lex_state = 15},
  [203] = {.lex_state = 68, .external_lex_state = 3},
  [204] = {.lex_state = 19},
  [205] = {.lex_state = 17},
  [206] = {.lex_state = 19},
  [207] = {.lex_state = 19},
  [208] = {.lex_state = 19},
  [209] = {.lex_state = 19},
  [210] = {.lex_state = 68, .external_lex_state = 3},
  [211] = {.lex_state = 13},
  [212] = {.lex_state = 17},
  [213] = {.lex_state = 17},
  [214] = {.lex_state = 17},
  [215] = {.lex_state = 17},
  [216] = {.lex_state = 17},
  [217] = {.lex_state = 17},
  [218] = {.lex_state = 17},
  [219] = {.lex_state = 17},
  [220] = {.lex_state = 17},
  [221] = {.lex_state = 17},
  [222] = {.lex_state = 13},
  [223] = {.lex_state = 17},
  [224] = {.lex_state = 21},
  [225] = {.lex_state = 21},
  [226] = {.lex_state = 13},
  [227] = {.lex_state = 13},
  [228] = {.lex_state = 13},
  [229] = {.lex_state = 13},
  [230] = {.lex_state = 13},
  [231] = {.lex_state = 13},
  [232] = {.lex_state = 13},
  [233] = {.lex_state = 13},
  [234] = {.lex_state = 13},
  [235] = {.lex_state = 13},
  [236] = {.lex_state = 13},
  [237] = {.lex_state = 13},
  [238] = {.lex_state = 33},
  [239] = {.lex_state = 13},
  [240] = {.lex_state = 33},
  [241] = {.lex_state = 68},
  [242] = {.lex_state = 33},
  [243] = {.lex_state = 33},
  [244] = {.lex_state = 13},
  [245] = {.lex_state = 13},
  [246] = {.lex_state = 9},
  [247] = {.lex_state = 9},
  [248] = {.lex_state = 33},
  [249] = {.lex_state = 68},
  [250] = {.lex_state = 9},
  [251] = {.lex_state = 9},
  [252] = {.lex_state = 9},
  [253] = {.lex_state = 9},
  [254] = {.lex_state = 9},
  [255] = {.lex_state = 9},
  [256] = {.lex_state = 13},
  [257] = {.lex_state = 9},
  [258] = {.lex_state = 9},
  [259] = {.lex_state = 26},
  [260] = {.lex_state = 13},
  [261] = {.lex_state = 9},
  [262] = {.lex_state = 13},
  [263] = {.lex_state = 9},
  [264] = {.lex_state = 13},
  [265] = {.lex_state = 13},
  [266] = {.lex_state = 13},
  [267] = {.lex_state = 9},
  [268] = {.lex_state = 68},
  [269] = {.lex_state = 13},
  [270] = {.lex_state = 68},
  [271] = {.lex_state = 68},
  [272] = {.lex_state = 68},
  [273] = {.lex_state = 26},
  [274] = {.lex_state = 13},
  [275] = {.lex_state = 68},
  [276] = {.lex_state = 33},
  [277] = {.lex_state = 9},
  [278] = {.lex_state = 68},
  [279] = {.lex_state = 9},
  [280] = {.lex_state = 33},
  [281] = {.lex_state = 68},
  [282] = {.lex_state = 68},
  [283] = {.lex_state = 68},
  [284] = {.lex_state = 68},
  [285] = {.lex_state = 33},
  [286] = {.lex_state = 33},
  [287] = {.lex_state = 68},
  [288] = {.lex_state = 68},
  [289] = {.lex_state = 9},
  [290] = {.lex_state = 68},
  [291] = {.lex_state = 68},
  [292] = {.lex_state = 68},
  [293] = {.lex_state = 9},
  [294] = {.lex_state = 68},
  [295] = {.lex_state = 68},
  [296] = {.lex_state = 68},
  [297] = {.lex_state = 68},
  [298] = {.lex_state = 68},
  [299] = {.lex_state = 68},
  [300] = {.lex_state = 68},
  [301] = {.lex_state = 68},
  [302] = {.lex_state = 68},
  [303] = {.lex_state = 68},
  [304] = {.lex_state = 27},
  [305] = {.lex_state = 68},
  [306] = {.lex_state = 35},
  [307] = {.lex_state = 27},
  [308] = {.lex_state = 68},
  [309] = {.lex_state = 68},
  [310] = {.lex_state = 68},
  [311] = {.lex_state = 68},
  [312] = {.lex_state = 68},
  [313] = {.lex_state = 68},
  [314] = {.lex_state = 183},
  [315] = {.lex_state = 9},
  [316] = {.lex_state = 68},
  [317] = {.lex_state = 68},
  [318] = {.lex_state = 68},
  [319] = {.lex_state = 68},
  [320] = {.lex_state = 68},
  [321] = {.lex_state = 68},
  [322] = {.lex_state = 68},
  [323] = {.lex_state = 68},
  [324] = {.lex_state = 68},
  [325] = {.lex_state = 68},
  [326] = {.lex_state = 68},
  [327] = {.lex_state = 68},
  [328] = {.lex_state = 68},
  [329] = {.lex_state = 68},
  [330] = {.lex_state = 68},
  [331] = {.lex_state = 68},
  [332] = {.lex_state = 68},
  [333] = {.lex_state = 68},
  [334] = {.lex_state = 19},
  [335] = {.lex_state = 68},
  [336] = {.lex_state = 68},
  [337] = {.lex_state = 9},
  [338] = {.lex_state = 68},
  [339] = {.lex_state = 9},
  [340] = {.lex_state = 173},
  [341] = {.lex_state = 183},
  [342] = {.lex_state = 68},
  [343] = {.lex_state = 68},
  [344] = {.lex_state = 68},
  [345] = {.lex_state = 68},
  [346] = {.lex_state = 68},
  [347] = {.lex_state = 68},
  [348] = {.lex_state = 173},
  [349] = {.lex_state = 183},
  [350] = {.lex_state = 68},
  [351] = {.lex_state = 173},
  [352] = {.lex_state = 173},
  [353] = {.lex_state = 183},
  [354] = {.lex_state = 173},
  [355] = {.lex_state = 183},
  [356] = {.lex_state = 173},
  [357] = {.lex_state = 183},
  [358] = {.lex_state = 68},
  [359] = {.lex_state = 68},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_ATimport] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_ATmedia] = ACTIONS(1),
    [anon_sym_ATcharset] = ACTIONS(1),
    [anon_sym_ATnamespace] = ACTIONS(1),
    [anon_sym_ATkeyframes] = ACTIONS(1),
    [aux_sym_keyframes_statement_token1] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_from] = ACTIONS(1),
    [sym_to] = ACTIONS(1),
    [anon_sym_ATsupports] = ACTIONS(1),
    [sym_nesting_selector] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_has] = ACTIONS(1),
    [anon_sym_not] = ACTIONS(1),
    [anon_sym_is] = ACTIONS(1),
    [anon_sym_where] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_TILDE_EQ] = ACTIONS(1),
    [anon_sym_CARET_EQ] = ACTIONS(1),
    [anon_sym_PIPE_EQ] = ACTIONS(1),
    [anon_sym_STAR_EQ] = ACTIONS(1),
    [anon_sym_DOLLAR_EQ] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_important] = ACTIONS(1),
    [anon_sym_LPAREN2] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_or] = ACTIONS(1),
    [anon_sym_only] = ACTIONS(1),
    [anon_sym_selector] = ACTIONS(1),
    [aux_sym_color_value_token1] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [aux_sym_integer_value_token1] = ACTIONS(1),
    [aux_sym_float_value_token1] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_at_keyword] = ACTIONS(1),
    [sym_js_comment] = ACTIONS(3),
    [sym_comment] = ACTIONS(5),
    [sym__descendant_operator] = ACTIONS(1),
    [sym__pseudo_class_selector_colon] = ACTIONS(1),
    [sym___error_recovery] = ACTIONS(1),
  },
  [1] = {
    [sym_stylesheet] = STATE(319),
    [sym_import_statement] = STATE(9),
    [sym_media_statement] = STATE(9),
    [sym_charset_statement] = STATE(9),
    [sym_namespace_statement] = STATE(9),
    [sym_keyframes_statement] = STATE(9),
    [sym_supports_statement] = STATE(9),
    [sym_at_rule] = STATE(9),
    [sym_rule_set] = STATE(9),
    [sym_selectors] = STATE(310),
    [sym__selector] = STATE(192),
    [sym_universal_selector] = STATE(192),
    [sym_class_selector] = STATE(192),
    [sym_pseudo_class_selector] = STATE(192),
    [sym_pseudo_element_selector] = STATE(192),
    [sym_id_selector] = STATE(192),
    [sym_attribute_selector] = STATE(192),
    [sym_child_selector] = STATE(192),
    [sym_descendant_selector] = STATE(192),
    [sym_sibling_selector] = STATE(192),
    [sym_adjacent_sibling_selector] = STATE(192),
    [sym_namespace_selector] = STATE(192),
    [sym_declaration] = STATE(9),
    [sym_string_value] = STATE(192),
    [aux_sym_stylesheet_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(7),
    [anon_sym_ATimport] = ACTIONS(9),
    [anon_sym_ATmedia] = ACTIONS(11),
    [anon_sym_ATcharset] = ACTIONS(13),
    [anon_sym_ATnamespace] = ACTIONS(15),
    [anon_sym_ATkeyframes] = ACTIONS(17),
    [aux_sym_keyframes_statement_token1] = ACTIONS(17),
    [anon_sym_ATsupports] = ACTIONS(19),
    [sym_nesting_selector] = ACTIONS(21),
    [anon_sym_STAR] = ACTIONS(23),
    [anon_sym_DOT] = ACTIONS(25),
    [anon_sym_COLON_COLON] = ACTIONS(27),
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_SQUOTE] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(35),
    [sym_identifier] = ACTIONS(37),
    [sym_at_keyword] = ACTIONS(39),
    [sym_js_comment] = ACTIONS(5),
    [sym_comment] = ACTIONS(5),
    [sym__pseudo_class_selector_colon] = ACTIONS(41),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(53), 1,
      anon_sym_RBRACE,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    STATE(309), 1,
      sym_selectors,
    STATE(320), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(4), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(192), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [94] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    ACTIONS(61), 1,
      anon_sym_RBRACE,
    STATE(309), 1,
      sym_selectors,
    STATE(318), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(5), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(192), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [188] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    ACTIONS(63), 1,
      anon_sym_RBRACE,
    STATE(309), 1,
      sym_selectors,
    STATE(321), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(8), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(192), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [282] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    ACTIONS(65), 1,
      anon_sym_RBRACE,
    STATE(309), 1,
      sym_selectors,
    STATE(346), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(8), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(192), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [376] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    ACTIONS(67), 1,
      anon_sym_RBRACE,
    STATE(309), 1,
      sym_selectors,
    STATE(322), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(7), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(192), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [470] = 23,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(43), 1,
      anon_sym_ATimport,
    ACTIONS(45), 1,
      anon_sym_ATmedia,
    ACTIONS(47), 1,
      anon_sym_ATcharset,
    ACTIONS(49), 1,
      anon_sym_ATnamespace,
    ACTIONS(55), 1,
      anon_sym_ATsupports,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(59), 1,
      sym_at_keyword,
    ACTIONS(69), 1,
      anon_sym_RBRACE,
    STATE(309), 1,
      sym_selectors,
    STATE(313), 1,
      sym_last_declaration,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(51), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(8), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(192), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [564] = 22,
    ACTIONS(71), 1,
      anon_sym_ATimport,
    ACTIONS(74), 1,
      anon_sym_ATmedia,
    ACTIONS(77), 1,
      anon_sym_ATcharset,
    ACTIONS(80), 1,
      anon_sym_ATnamespace,
    ACTIONS(86), 1,
      anon_sym_RBRACE,
    ACTIONS(88), 1,
      anon_sym_ATsupports,
    ACTIONS(91), 1,
      sym_nesting_selector,
    ACTIONS(94), 1,
      anon_sym_STAR,
    ACTIONS(97), 1,
      anon_sym_DOT,
    ACTIONS(100), 1,
      anon_sym_COLON_COLON,
    ACTIONS(103), 1,
      anon_sym_POUND,
    ACTIONS(106), 1,
      anon_sym_LBRACK,
    ACTIONS(109), 1,
      anon_sym_SQUOTE,
    ACTIONS(112), 1,
      anon_sym_DQUOTE,
    ACTIONS(115), 1,
      sym_identifier,
    ACTIONS(118), 1,
      sym_at_keyword,
    ACTIONS(121), 1,
      sym__pseudo_class_selector_colon,
    STATE(309), 1,
      sym_selectors,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(83), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(8), 11,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_postcss_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_block_repeat1,
    STATE(192), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [655] = 22,
    ACTIONS(9), 1,
      anon_sym_ATimport,
    ACTIONS(11), 1,
      anon_sym_ATmedia,
    ACTIONS(13), 1,
      anon_sym_ATcharset,
    ACTIONS(15), 1,
      anon_sym_ATnamespace,
    ACTIONS(19), 1,
      anon_sym_ATsupports,
    ACTIONS(21), 1,
      sym_nesting_selector,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(37), 1,
      sym_identifier,
    ACTIONS(39), 1,
      sym_at_keyword,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(124), 1,
      ts_builtin_sym_end,
    STATE(310), 1,
      sym_selectors,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(17), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(10), 10,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_stylesheet_repeat1,
    STATE(192), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [745] = 22,
    ACTIONS(126), 1,
      ts_builtin_sym_end,
    ACTIONS(128), 1,
      anon_sym_ATimport,
    ACTIONS(131), 1,
      anon_sym_ATmedia,
    ACTIONS(134), 1,
      anon_sym_ATcharset,
    ACTIONS(137), 1,
      anon_sym_ATnamespace,
    ACTIONS(143), 1,
      anon_sym_ATsupports,
    ACTIONS(146), 1,
      sym_nesting_selector,
    ACTIONS(149), 1,
      anon_sym_STAR,
    ACTIONS(152), 1,
      anon_sym_DOT,
    ACTIONS(155), 1,
      anon_sym_COLON_COLON,
    ACTIONS(158), 1,
      anon_sym_POUND,
    ACTIONS(161), 1,
      anon_sym_LBRACK,
    ACTIONS(164), 1,
      anon_sym_SQUOTE,
    ACTIONS(167), 1,
      anon_sym_DQUOTE,
    ACTIONS(170), 1,
      sym_identifier,
    ACTIONS(173), 1,
      sym_at_keyword,
    ACTIONS(176), 1,
      sym__pseudo_class_selector_colon,
    STATE(310), 1,
      sym_selectors,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(140), 2,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
    STATE(10), 10,
      sym_import_statement,
      sym_media_statement,
      sym_charset_statement,
      sym_namespace_statement,
      sym_keyframes_statement,
      sym_supports_statement,
      sym_at_rule,
      sym_rule_set,
      sym_declaration,
      aux_sym_stylesheet_repeat1,
    STATE(192), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [835] = 22,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(179), 1,
      sym_nesting_selector,
    ACTIONS(181), 1,
      anon_sym_DOT,
    ACTIONS(183), 1,
      anon_sym_POUND,
    ACTIONS(185), 1,
      anon_sym_LBRACK,
    ACTIONS(187), 1,
      anon_sym_RPAREN,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(193), 1,
      anon_sym_SQUOTE,
    ACTIONS(195), 1,
      anon_sym_DQUOTE,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(201), 1,
      sym_identifier,
    ACTIONS(203), 1,
      sym_plain_value,
    STATE(39), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(40), 1,
      sym_string_value,
    STATE(170), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(195), 12,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
  [920] = 22,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(181), 1,
      anon_sym_DOT,
    ACTIONS(183), 1,
      anon_sym_POUND,
    ACTIONS(185), 1,
      anon_sym_LBRACK,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(193), 1,
      anon_sym_SQUOTE,
    ACTIONS(195), 1,
      anon_sym_DQUOTE,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(201), 1,
      sym_identifier,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(205), 1,
      sym_nesting_selector,
    ACTIONS(207), 1,
      anon_sym_RPAREN,
    STATE(40), 1,
      sym_string_value,
    STATE(43), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(170), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(193), 12,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
  [1005] = 21,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(181), 1,
      anon_sym_DOT,
    ACTIONS(183), 1,
      anon_sym_POUND,
    ACTIONS(185), 1,
      anon_sym_LBRACK,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(193), 1,
      anon_sym_SQUOTE,
    ACTIONS(195), 1,
      anon_sym_DQUOTE,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(201), 1,
      sym_identifier,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(209), 1,
      sym_nesting_selector,
    STATE(40), 1,
      sym_string_value,
    STATE(47), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(170), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(196), 12,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
  [1087] = 21,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(181), 1,
      anon_sym_DOT,
    ACTIONS(211), 1,
      sym_nesting_selector,
    ACTIONS(213), 1,
      anon_sym_POUND,
    ACTIONS(215), 1,
      anon_sym_LBRACK,
    ACTIONS(217), 1,
      sym_important,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(221), 1,
      anon_sym_SQUOTE,
    ACTIONS(223), 1,
      anon_sym_DQUOTE,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(229), 1,
      sym_identifier,
    ACTIONS(231), 1,
      sym_plain_value,
    STATE(174), 1,
      sym_namespace_selector,
    STATE(185), 1,
      sym_string_value,
    STATE(239), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(210), 11,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
  [1168] = 21,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(181), 1,
      anon_sym_DOT,
    ACTIONS(211), 1,
      sym_nesting_selector,
    ACTIONS(213), 1,
      anon_sym_POUND,
    ACTIONS(215), 1,
      anon_sym_LBRACK,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(221), 1,
      anon_sym_SQUOTE,
    ACTIONS(223), 1,
      anon_sym_DQUOTE,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(229), 1,
      sym_identifier,
    ACTIONS(233), 1,
      sym_important,
    ACTIONS(235), 1,
      sym_plain_value,
    STATE(174), 1,
      sym_namespace_selector,
    STATE(185), 1,
      sym_string_value,
    STATE(245), 8,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
    STATE(210), 11,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
  [1249] = 20,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(237), 1,
      anon_sym_SEMI,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(247), 1,
      anon_sym_LPAREN2,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(255), 1,
      sym_identifier,
    STATE(55), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(113), 1,
      sym_block,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(247), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1324] = 16,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(261), 1,
      sym_important,
    ACTIONS(263), 1,
      anon_sym_LPAREN2,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(269), 1,
      sym_identifier,
    ACTIONS(271), 1,
      sym_plain_value,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(293), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
    STATE(266), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1387] = 16,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(263), 1,
      anon_sym_LPAREN2,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(269), 1,
      sym_identifier,
    ACTIONS(273), 1,
      sym_important,
    ACTIONS(275), 1,
      sym_plain_value,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(293), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
    STATE(269), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1450] = 19,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(279), 1,
      anon_sym_SEMI,
    ACTIONS(281), 1,
      anon_sym_RBRACE,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(287), 1,
      sym_important,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(291), 1,
      sym_plain_value,
    STATE(37), 1,
      aux_sym_declaration_repeat1,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    STATE(175), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1518] = 18,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(291), 1,
      sym_plain_value,
    ACTIONS(293), 1,
      anon_sym_SEMI,
    ACTIONS(295), 1,
      sym_important,
    STATE(46), 1,
      aux_sym_declaration_repeat1,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    STATE(175), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1583] = 18,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(279), 1,
      anon_sym_SEMI,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(291), 1,
      sym_plain_value,
    ACTIONS(297), 1,
      sym_important,
    STATE(49), 1,
      aux_sym_declaration_repeat1,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    STATE(175), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1648] = 8,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(305), 1,
      anon_sym_LPAREN,
    STATE(161), 1,
      sym_arguments,
    ACTIONS(303), 2,
      anon_sym_DOT,
      anon_sym_PLUS,
    ACTIONS(301), 4,
      anon_sym_STAR,
      sym_important,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(307), 7,
      anon_sym_LPAREN2,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(299), 10,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PIPE,
      anon_sym_RPAREN,
  [1692] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(311), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(281), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1753] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(313), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(282), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1814] = 13,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(315), 1,
      sym_nesting_selector,
    ACTIONS(317), 1,
      anon_sym_RPAREN,
    ACTIONS(319), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(190), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [1867] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(321), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(284), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1928] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(325), 1,
      anon_sym_POUND,
    ACTIONS(328), 1,
      anon_sym_LBRACK,
    ACTIONS(331), 1,
      sym_important,
    ACTIONS(334), 1,
      anon_sym_LPAREN2,
    ACTIONS(337), 1,
      anon_sym_SQUOTE,
    ACTIONS(340), 1,
      anon_sym_DQUOTE,
    ACTIONS(343), 1,
      aux_sym_integer_value_token1,
    ACTIONS(346), 1,
      aux_sym_float_value_token1,
    ACTIONS(349), 1,
      sym_identifier,
    ACTIONS(352), 1,
      sym_plain_value,
    STATE(27), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(323), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [1984] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(319), 1,
      sym_identifier,
    ACTIONS(355), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(191), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2034] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(319), 1,
      sym_identifier,
    ACTIONS(357), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(89), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2084] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(319), 1,
      sym_identifier,
    ACTIONS(359), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(88), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2134] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(319), 1,
      sym_identifier,
    ACTIONS(361), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(87), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2184] = 10,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(365), 1,
      anon_sym_RBRACK,
    ACTIONS(367), 1,
      anon_sym_LPAREN,
    STATE(227), 1,
      sym_arguments,
    ACTIONS(301), 2,
      anon_sym_COMMA,
      anon_sym_DASH,
    ACTIONS(303), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(307), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(363), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(299), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [2230] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(319), 1,
      sym_identifier,
    ACTIONS(369), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(86), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2280] = 16,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(371), 1,
      anon_sym_COMMA,
    ACTIONS(376), 1,
      anon_sym_POUND,
    ACTIONS(379), 1,
      anon_sym_LBRACK,
    ACTIONS(382), 1,
      sym_important,
    ACTIONS(385), 1,
      anon_sym_LPAREN2,
    ACTIONS(388), 1,
      anon_sym_SQUOTE,
    ACTIONS(391), 1,
      anon_sym_DQUOTE,
    ACTIONS(394), 1,
      aux_sym_integer_value_token1,
    ACTIONS(397), 1,
      aux_sym_float_value_token1,
    ACTIONS(400), 1,
      sym_identifier,
    ACTIONS(403), 1,
      sym_plain_value,
    STATE(34), 1,
      aux_sym_declaration_repeat1,
    ACTIONS(374), 2,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    STATE(175), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2338] = 13,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(211), 1,
      sym_nesting_selector,
    ACTIONS(406), 1,
      sym_identifier,
    STATE(177), 1,
      sym_namespace_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(210), 12,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_string_value,
  [2390] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    STATE(27), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(408), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2446] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(291), 1,
      sym_plain_value,
    ACTIONS(410), 1,
      anon_sym_SEMI,
    ACTIONS(412), 1,
      anon_sym_RBRACE,
    ACTIONS(414), 1,
      sym_important,
    STATE(34), 1,
      aux_sym_declaration_repeat1,
    STATE(175), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2506] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(418), 8,
      anon_sym_DOT,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(416), 15,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [2540] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(420), 1,
      anon_sym_COMMA,
    ACTIONS(422), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(290), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2600] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(428), 2,
      anon_sym_DOT,
      anon_sym_PLUS,
    ACTIONS(426), 5,
      anon_sym_STAR,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(430), 6,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(424), 10,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PIPE,
      anon_sym_RPAREN,
  [2638] = 13,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(211), 1,
      sym_nesting_selector,
    ACTIONS(432), 1,
      sym_identifier,
    STATE(174), 1,
      sym_namespace_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(210), 12,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_string_value,
  [2690] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(319), 1,
      sym_identifier,
    ACTIONS(434), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(203), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2740] = 17,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(420), 1,
      anon_sym_COMMA,
    ACTIONS(436), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(299), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2800] = 12,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(25), 1,
      anon_sym_DOT,
    ACTIONS(27), 1,
      anon_sym_COLON_COLON,
    ACTIONS(29), 1,
      anon_sym_POUND,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(33), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(319), 1,
      sym_identifier,
    ACTIONS(438), 1,
      sym_nesting_selector,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(83), 13,
      sym__selector,
      sym_universal_selector,
      sym_class_selector,
      sym_pseudo_class_selector,
      sym_pseudo_element_selector,
      sym_id_selector,
      sym_attribute_selector,
      sym_child_selector,
      sym_descendant_selector,
      sym_sibling_selector,
      sym_adjacent_sibling_selector,
      sym_namespace_selector,
      sym_string_value,
  [2850] = 5,
    ACTIONS(444), 1,
      anon_sym_LPAREN,
    STATE(65), 1,
      sym_pseudo_element_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(442), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(440), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [2885] = 16,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(291), 1,
      sym_plain_value,
    ACTIONS(446), 1,
      anon_sym_SEMI,
    ACTIONS(448), 1,
      sym_important,
    STATE(34), 1,
      aux_sym_declaration_repeat1,
    STATE(175), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2942] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    STATE(27), 1,
      aux_sym_postcss_statement_repeat1,
    ACTIONS(450), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [2997] = 5,
    ACTIONS(444), 1,
      anon_sym_LPAREN,
    STATE(70), 1,
      sym_pseudo_element_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(454), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(452), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3032] = 16,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(291), 1,
      sym_plain_value,
    ACTIONS(410), 1,
      anon_sym_SEMI,
    ACTIONS(456), 1,
      sym_important,
    STATE(34), 1,
      aux_sym_declaration_repeat1,
    STATE(175), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3089] = 5,
    ACTIONS(462), 1,
      anon_sym_LPAREN,
    STATE(64), 1,
      sym_pseudo_class_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(460), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(458), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3124] = 5,
    ACTIONS(462), 1,
      anon_sym_LPAREN,
    STATE(61), 1,
      sym_pseudo_class_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(466), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(464), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3159] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(468), 1,
      anon_sym_RPAREN,
    STATE(24), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3213] = 8,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(305), 1,
      anon_sym_LPAREN,
    STATE(161), 1,
      sym_arguments,
    ACTIONS(472), 2,
      anon_sym_and,
      anon_sym_or,
    ACTIONS(470), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
    ACTIONS(301), 6,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    ACTIONS(307), 8,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
  [3253] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(474), 1,
      anon_sym_RPAREN,
    STATE(23), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3307] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(476), 1,
      anon_sym_SEMI,
    STATE(27), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3361] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(478), 1,
      anon_sym_RPAREN,
    STATE(26), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3415] = 15,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(480), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3469] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(484), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(482), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3498] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(488), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(486), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3527] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(492), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(490), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3556] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(496), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(494), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3585] = 14,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    STATE(57), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3636] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(500), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(498), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3665] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(504), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(502), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3694] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(508), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(506), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3723] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(512), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(510), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3752] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(516), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(514), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3781] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(520), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(518), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3810] = 14,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(189), 1,
      sym_important,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(203), 1,
      sym_plain_value,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    STATE(36), 1,
      aux_sym_postcss_statement_repeat1,
    STATE(170), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [3861] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(524), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(522), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3890] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(528), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(526), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3919] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(532), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(530), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3948] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(418), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(416), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [3977] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(536), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(534), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4006] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(540), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(538), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4035] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(544), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(542), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4064] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(548), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(546), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4093] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(552), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(550), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4122] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(556), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(554), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4151] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(305), 1,
      anon_sym_LPAREN,
    STATE(161), 1,
      sym_arguments,
    ACTIONS(307), 8,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(301), 10,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [4186] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(560), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(558), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4215] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(303), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(299), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4244] = 4,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(566), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(562), 17,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4275] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(570), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(568), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4304] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(574), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(572), 18,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4333] = 4,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(578), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(576), 17,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4364] = 4,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(582), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(580), 17,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4395] = 4,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(586), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(584), 17,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4426] = 4,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(590), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(588), 17,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_RPAREN,
  [4457] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(592), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(594), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4485] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(598), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(596), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4513] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(602), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(600), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4541] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(606), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(604), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4569] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(610), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(608), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4597] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(612), 1,
      sym_important,
    ACTIONS(614), 1,
      sym_identifier,
    ACTIONS(616), 1,
      sym_plain_value,
    STATE(265), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4645] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(620), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(618), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4673] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(624), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(622), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4701] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(628), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(626), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4729] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(632), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(630), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4757] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(636), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(634), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4785] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(614), 1,
      sym_identifier,
    ACTIONS(638), 1,
      sym_important,
    ACTIONS(640), 1,
      sym_plain_value,
    STATE(260), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [4833] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(644), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(642), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4861] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(648), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(646), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4889] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(650), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(652), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4917] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(656), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(654), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4945] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(660), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(658), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [4973] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(662), 1,
      sym_important,
    ACTIONS(664), 1,
      sym_plain_value,
    STATE(171), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5021] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(668), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(666), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5049] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(672), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(670), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5077] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(676), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(674), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5105] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(678), 1,
      anon_sym_POUND,
    ACTIONS(680), 1,
      anon_sym_LBRACK,
    ACTIONS(682), 1,
      sym_important,
    ACTIONS(684), 1,
      anon_sym_LPAREN2,
    ACTIONS(686), 1,
      anon_sym_SQUOTE,
    ACTIONS(688), 1,
      anon_sym_DQUOTE,
    ACTIONS(690), 1,
      aux_sym_integer_value_token1,
    ACTIONS(692), 1,
      aux_sym_float_value_token1,
    ACTIONS(694), 1,
      sym_identifier,
    ACTIONS(696), 1,
      sym_plain_value,
    STATE(217), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5153] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(698), 1,
      sym_important,
    ACTIONS(700), 1,
      sym_plain_value,
    STATE(19), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5201] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(620), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(618), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5229] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(598), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(596), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5257] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(660), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(658), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5285] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(614), 1,
      sym_identifier,
    ACTIONS(702), 1,
      sym_important,
    ACTIONS(704), 1,
      sym_plain_value,
    STATE(228), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5333] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(678), 1,
      anon_sym_POUND,
    ACTIONS(680), 1,
      anon_sym_LBRACK,
    ACTIONS(684), 1,
      anon_sym_LPAREN2,
    ACTIONS(686), 1,
      anon_sym_SQUOTE,
    ACTIONS(688), 1,
      anon_sym_DQUOTE,
    ACTIONS(690), 1,
      aux_sym_integer_value_token1,
    ACTIONS(692), 1,
      aux_sym_float_value_token1,
    ACTIONS(694), 1,
      sym_identifier,
    ACTIONS(706), 1,
      sym_important,
    ACTIONS(708), 1,
      sym_plain_value,
    STATE(182), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5381] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(710), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(712), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5409] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(714), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(716), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5437] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(602), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(600), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5465] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(606), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(604), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5493] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(672), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(670), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5521] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(718), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(720), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5549] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(610), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(608), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5577] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(628), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(626), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5605] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(636), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(634), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5633] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(648), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(646), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5661] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(668), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(666), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5689] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(722), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(724), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5717] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(726), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(728), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5745] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(624), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(622), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5773] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(632), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(630), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5801] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(614), 1,
      sym_identifier,
    ACTIONS(730), 1,
      sym_important,
    ACTIONS(732), 1,
      sym_plain_value,
    STATE(256), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [5849] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(656), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(654), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5877] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(676), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(674), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5905] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(738), 1,
      sym_unit,
    ACTIONS(736), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(734), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [5937] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(744), 1,
      sym_unit,
    ACTIONS(742), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(740), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [5969] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(620), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(618), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [5997] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(746), 1,
      sym_important,
    ACTIONS(748), 1,
      sym_plain_value,
    STATE(165), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6045] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(614), 1,
      sym_identifier,
    ACTIONS(750), 1,
      sym_important,
    ACTIONS(752), 1,
      sym_plain_value,
    STATE(244), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6093] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(718), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(720), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6121] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(592), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(594), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6149] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(710), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(712), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6177] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(722), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(724), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6205] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(714), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(716), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6233] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(726), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(728), 11,
      sym__pseudo_class_selector_colon,
      ts_builtin_sym_end,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6261] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(754), 1,
      sym_important,
    ACTIONS(756), 1,
      sym_plain_value,
    STATE(20), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6309] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(678), 1,
      anon_sym_POUND,
    ACTIONS(680), 1,
      anon_sym_LBRACK,
    ACTIONS(684), 1,
      anon_sym_LPAREN2,
    ACTIONS(686), 1,
      anon_sym_SQUOTE,
    ACTIONS(688), 1,
      anon_sym_DQUOTE,
    ACTIONS(690), 1,
      aux_sym_integer_value_token1,
    ACTIONS(692), 1,
      aux_sym_float_value_token1,
    ACTIONS(694), 1,
      sym_identifier,
    ACTIONS(758), 1,
      sym_important,
    ACTIONS(760), 1,
      sym_plain_value,
    STATE(183), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6357] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(614), 1,
      sym_identifier,
    ACTIONS(762), 1,
      sym_important,
    ACTIONS(764), 1,
      sym_plain_value,
    STATE(262), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6405] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(217), 1,
      sym_important,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(231), 1,
      sym_plain_value,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(614), 1,
      sym_identifier,
    STATE(239), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6453] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(261), 1,
      sym_important,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(271), 1,
      sym_plain_value,
    ACTIONS(614), 1,
      sym_identifier,
    STATE(266), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6501] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_LPAREN2,
    ACTIONS(197), 1,
      aux_sym_integer_value_token1,
    ACTIONS(199), 1,
      aux_sym_float_value_token1,
    ACTIONS(243), 1,
      anon_sym_POUND,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    ACTIONS(251), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(766), 1,
      sym_important,
    ACTIONS(768), 1,
      sym_plain_value,
    STATE(21), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6549] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(614), 1,
      sym_identifier,
    ACTIONS(770), 1,
      sym_important,
    ACTIONS(772), 1,
      sym_plain_value,
    STATE(274), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6597] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(614), 1,
      sym_identifier,
    ACTIONS(774), 1,
      sym_important,
    ACTIONS(776), 1,
      sym_plain_value,
    STATE(264), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6645] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(233), 1,
      sym_important,
    ACTIONS(235), 1,
      sym_plain_value,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(614), 1,
      sym_identifier,
    STATE(245), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6693] = 13,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LPAREN2,
    ACTIONS(225), 1,
      aux_sym_integer_value_token1,
    ACTIONS(227), 1,
      aux_sym_float_value_token1,
    ACTIONS(257), 1,
      anon_sym_POUND,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      anon_sym_SQUOTE,
    ACTIONS(267), 1,
      anon_sym_DQUOTE,
    ACTIONS(273), 1,
      sym_important,
    ACTIONS(275), 1,
      sym_plain_value,
    ACTIONS(614), 1,
      sym_identifier,
    STATE(269), 9,
      sym__value,
      sym_parenthesized_value,
      sym_color_value,
      sym_string_value,
      sym_integer_value,
      sym_float_value,
      sym_grid_value,
      sym_call_expression,
      sym_binary_expression,
  [6741] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(644), 8,
      anon_sym_ATimport,
      anon_sym_ATmedia,
      anon_sym_ATcharset,
      anon_sym_ATnamespace,
      anon_sym_ATkeyframes,
      aux_sym_keyframes_statement_token1,
      anon_sym_ATsupports,
      sym_at_keyword,
    ACTIONS(642), 11,
      sym__pseudo_class_selector_colon,
      anon_sym_RBRACE,
      sym_nesting_selector,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [6769] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(780), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(778), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6798] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(784), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(782), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6827] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(788), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(786), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6856] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(792), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(790), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6885] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(796), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(794), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6914] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(800), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(798), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6943] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(804), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(802), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [6972] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(808), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(806), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7001] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(812), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(810), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7030] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(816), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(814), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7059] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(820), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(818), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7088] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(418), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(416), 11,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7117] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(824), 4,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(822), 9,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7149] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(826), 4,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(374), 9,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7181] = 5,
    ACTIONS(365), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(303), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(363), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(299), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7211] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(828), 1,
      anon_sym_SEMI,
    ACTIONS(830), 1,
      anon_sym_RBRACE,
    ACTIONS(430), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(426), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7243] = 5,
    ACTIONS(365), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(428), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(363), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(424), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7273] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_STAR,
    ACTIONS(285), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_SLASH,
    ACTIONS(834), 4,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      sym_identifier,
      sym_plain_value,
    ACTIONS(832), 9,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7305] = 5,
    ACTIONS(838), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(303), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(836), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(299), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7335] = 5,
    ACTIONS(838), 1,
      anon_sym_RBRACK,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(428), 2,
      anon_sym_TILDE,
      anon_sym_PIPE,
    ACTIONS(836), 6,
      anon_sym_EQ,
      anon_sym_TILDE_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_STAR_EQ,
      anon_sym_DOLLAR_EQ,
    ACTIONS(424), 8,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_PLUS,
  [7365] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(410), 1,
      anon_sym_SEMI,
    ACTIONS(412), 1,
      anon_sym_RBRACE,
    ACTIONS(430), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(426), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7397] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(828), 1,
      anon_sym_SEMI,
    ACTIONS(430), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(426), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7426] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(410), 1,
      anon_sym_SEMI,
    ACTIONS(430), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(426), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7455] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(840), 1,
      anon_sym_SEMI,
    ACTIONS(430), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(426), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7484] = 10,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(842), 1,
      anon_sym_SEMI,
    ACTIONS(846), 1,
      anon_sym_LPAREN2,
    ACTIONS(850), 1,
      sym_identifier,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    ACTIONS(844), 2,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(848), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    STATE(263), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [7523] = 10,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(846), 1,
      anon_sym_LPAREN2,
    ACTIONS(850), 1,
      sym_identifier,
    ACTIONS(852), 1,
      anon_sym_SEMI,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    ACTIONS(844), 2,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(848), 2,
      anon_sym_DASH,
      anon_sym_SLASH,
    STATE(267), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [7562] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(446), 1,
      anon_sym_SEMI,
    ACTIONS(430), 7,
      anon_sym_PLUS,
      aux_sym_integer_value_token1,
      aux_sym_float_value_token1,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
      sym_plain_value,
    ACTIONS(426), 8,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_important,
      anon_sym_LPAREN2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [7591] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(430), 1,
      anon_sym_SLASH,
    ACTIONS(426), 4,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_DASH,
    ACTIONS(424), 10,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PLUS,
      anon_sym_PIPE,
  [7619] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(418), 1,
      anon_sym_SLASH,
    ACTIONS(416), 14,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PLUS,
      anon_sym_PIPE,
      anon_sym_DASH,
  [7645] = 9,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(846), 1,
      anon_sym_LPAREN2,
    ACTIONS(850), 1,
      sym_identifier,
    ACTIONS(854), 1,
      anon_sym_SEMI,
    ACTIONS(856), 1,
      anon_sym_LBRACE,
    STATE(96), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(246), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [7680] = 3,
    ACTIONS(858), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(299), 12,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PLUS,
      anon_sym_PIPE,
  [7702] = 3,
    ACTIONS(860), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(299), 12,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PLUS,
      anon_sym_PIPE,
  [7724] = 14,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(862), 1,
      anon_sym_COMMA,
    ACTIONS(864), 1,
      anon_sym_COLON_COLON,
    ACTIONS(866), 1,
      anon_sym_POUND,
    ACTIONS(868), 1,
      anon_sym_LBRACK,
    ACTIONS(870), 1,
      anon_sym_GT,
    ACTIONS(872), 1,
      anon_sym_TILDE,
    ACTIONS(874), 1,
      anon_sym_PLUS,
    ACTIONS(876), 1,
      anon_sym_PIPE,
    ACTIONS(878), 1,
      anon_sym_RPAREN,
    ACTIONS(880), 1,
      sym__descendant_operator,
    ACTIONS(882), 1,
      sym__pseudo_class_selector_colon,
    STATE(301), 1,
      aux_sym_selectors_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [7768] = 12,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(864), 1,
      anon_sym_COLON_COLON,
    ACTIONS(866), 1,
      anon_sym_POUND,
    ACTIONS(868), 1,
      anon_sym_LBRACK,
    ACTIONS(870), 1,
      anon_sym_GT,
    ACTIONS(872), 1,
      anon_sym_TILDE,
    ACTIONS(874), 1,
      anon_sym_PLUS,
    ACTIONS(876), 1,
      anon_sym_PIPE,
    ACTIONS(880), 1,
      sym__descendant_operator,
    ACTIONS(882), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(884), 3,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
  [7808] = 14,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(862), 1,
      anon_sym_COMMA,
    ACTIONS(864), 1,
      anon_sym_COLON_COLON,
    ACTIONS(866), 1,
      anon_sym_POUND,
    ACTIONS(868), 1,
      anon_sym_LBRACK,
    ACTIONS(870), 1,
      anon_sym_GT,
    ACTIONS(872), 1,
      anon_sym_TILDE,
    ACTIONS(874), 1,
      anon_sym_PLUS,
    ACTIONS(876), 1,
      anon_sym_PIPE,
    ACTIONS(880), 1,
      sym__descendant_operator,
    ACTIONS(882), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(886), 1,
      anon_sym_LBRACE,
    STATE(292), 1,
      aux_sym_selectors_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [7852] = 14,
    ACTIONS(420), 1,
      anon_sym_COMMA,
    ACTIONS(436), 1,
      anon_sym_RPAREN,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(864), 1,
      anon_sym_COLON_COLON,
    ACTIONS(866), 1,
      anon_sym_POUND,
    ACTIONS(868), 1,
      anon_sym_LBRACK,
    ACTIONS(870), 1,
      anon_sym_GT,
    ACTIONS(872), 1,
      anon_sym_TILDE,
    ACTIONS(874), 1,
      anon_sym_PLUS,
    ACTIONS(876), 1,
      anon_sym_PIPE,
    ACTIONS(880), 1,
      sym__descendant_operator,
    ACTIONS(882), 1,
      sym__pseudo_class_selector_colon,
    STATE(299), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [7896] = 3,
    ACTIONS(888), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(299), 12,
      sym__descendant_operator,
      sym__pseudo_class_selector_colon,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_DOT,
      anon_sym_COLON_COLON,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_TILDE,
      anon_sym_PLUS,
      anon_sym_PIPE,
  [7918] = 14,
    ACTIONS(420), 1,
      anon_sym_COMMA,
    ACTIONS(422), 1,
      anon_sym_RPAREN,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(864), 1,
      anon_sym_COLON_COLON,
    ACTIONS(866), 1,
      anon_sym_POUND,
    ACTIONS(868), 1,
      anon_sym_LBRACK,
    ACTIONS(870), 1,
      anon_sym_GT,
    ACTIONS(872), 1,
      anon_sym_TILDE,
    ACTIONS(874), 1,
      anon_sym_PLUS,
    ACTIONS(876), 1,
      anon_sym_PIPE,
    ACTIONS(880), 1,
      sym__descendant_operator,
    ACTIONS(882), 1,
      sym__pseudo_class_selector_colon,
    STATE(290), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [7962] = 12,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(864), 1,
      anon_sym_COLON_COLON,
    ACTIONS(866), 1,
      anon_sym_POUND,
    ACTIONS(868), 1,
      anon_sym_LBRACK,
    ACTIONS(870), 1,
      anon_sym_GT,
    ACTIONS(872), 1,
      anon_sym_TILDE,
    ACTIONS(874), 1,
      anon_sym_PLUS,
    ACTIONS(876), 1,
      anon_sym_PIPE,
    ACTIONS(880), 1,
      sym__descendant_operator,
    ACTIONS(882), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(450), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [8001] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(890), 1,
      anon_sym_LPAREN,
    STATE(219), 1,
      sym_arguments,
    ACTIONS(301), 3,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
    ACTIONS(307), 7,
      anon_sym_not,
      anon_sym_LPAREN2,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8028] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(892), 1,
      sym_unit,
    ACTIONS(734), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(736), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8052] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(846), 1,
      anon_sym_LPAREN2,
    ACTIONS(850), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(279), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8078] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(846), 1,
      anon_sym_LPAREN2,
    ACTIONS(850), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(258), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8104] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(846), 1,
      anon_sym_LPAREN2,
    ACTIONS(850), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(289), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8130] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(894), 1,
      sym_unit,
    ACTIONS(740), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(742), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8154] = 12,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(864), 1,
      anon_sym_COLON_COLON,
    ACTIONS(866), 1,
      anon_sym_POUND,
    ACTIONS(868), 1,
      anon_sym_LBRACK,
    ACTIONS(870), 1,
      anon_sym_GT,
    ACTIONS(872), 1,
      anon_sym_TILDE,
    ACTIONS(874), 1,
      anon_sym_PLUS,
    ACTIONS(876), 1,
      anon_sym_PIPE,
    ACTIONS(880), 1,
      sym__descendant_operator,
    ACTIONS(882), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(896), 1,
      anon_sym_RPAREN,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [8192] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(846), 1,
      anon_sym_LPAREN2,
    ACTIONS(850), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(254), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8218] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(782), 5,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(784), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8240] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(846), 1,
      anon_sym_LPAREN2,
    ACTIONS(898), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(293), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8266] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(846), 1,
      anon_sym_LPAREN2,
    ACTIONS(850), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(261), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8292] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(846), 1,
      anon_sym_LPAREN2,
    ACTIONS(850), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(250), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8318] = 6,
    ACTIONS(249), 1,
      anon_sym_selector,
    ACTIONS(846), 1,
      anon_sym_LPAREN2,
    ACTIONS(850), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(241), 2,
      anon_sym_not,
      anon_sym_only,
    STATE(253), 6,
      sym__query,
      sym_feature_query,
      sym_parenthesized_query,
      sym_binary_query,
      sym_unary_query,
      sym_selector_query,
  [8344] = 11,
    ACTIONS(564), 1,
      anon_sym_DOT,
    ACTIONS(864), 1,
      anon_sym_COLON_COLON,
    ACTIONS(866), 1,
      anon_sym_POUND,
    ACTIONS(868), 1,
      anon_sym_LBRACK,
    ACTIONS(870), 1,
      anon_sym_GT,
    ACTIONS(872), 1,
      anon_sym_TILDE,
    ACTIONS(874), 1,
      anon_sym_PLUS,
    ACTIONS(876), 1,
      anon_sym_PIPE,
    ACTIONS(880), 1,
      sym__descendant_operator,
    ACTIONS(882), 1,
      sym__pseudo_class_selector_colon,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [8379] = 8,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(307), 1,
      anon_sym_SLASH,
    ACTIONS(367), 1,
      anon_sym_LPAREN,
    ACTIONS(900), 1,
      anon_sym_COLON,
    STATE(227), 1,
      sym_arguments,
    ACTIONS(301), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(470), 3,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [8408] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(810), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(812), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8429] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(416), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(418), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8450] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(798), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(800), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8471] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(802), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(804), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8492] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(794), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(796), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8513] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(806), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(808), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8534] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(778), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(780), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8555] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(790), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(792), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8576] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(818), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(820), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8597] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(786), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(788), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8618] = 6,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(307), 1,
      anon_sym_SLASH,
    ACTIONS(367), 1,
      anon_sym_LPAREN,
    STATE(227), 1,
      sym_arguments,
    ACTIONS(301), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8643] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(814), 4,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_LPAREN2,
    ACTIONS(816), 6,
      anon_sym_not,
      anon_sym_only,
      anon_sym_selector,
      anon_sym_DASH,
      anon_sym_SLASH,
      sym_identifier,
  [8664] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(742), 1,
      anon_sym_SLASH,
    ACTIONS(902), 1,
      sym_unit,
    ACTIONS(740), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8686] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(736), 1,
      anon_sym_SLASH,
    ACTIONS(904), 1,
      sym_unit,
    ACTIONS(734), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8708] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(816), 1,
      anon_sym_SLASH,
    ACTIONS(814), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8727] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(792), 1,
      anon_sym_SLASH,
    ACTIONS(790), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8746] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(808), 1,
      anon_sym_SLASH,
    ACTIONS(806), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8765] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(800), 1,
      anon_sym_SLASH,
    ACTIONS(798), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8784] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(788), 1,
      anon_sym_SLASH,
    ACTIONS(786), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8803] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(780), 1,
      anon_sym_SLASH,
    ACTIONS(778), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8822] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(812), 1,
      anon_sym_SLASH,
    ACTIONS(810), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8841] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(784), 1,
      anon_sym_SLASH,
    ACTIONS(782), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8860] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(418), 1,
      anon_sym_SLASH,
    ACTIONS(416), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8879] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(804), 1,
      anon_sym_SLASH,
    ACTIONS(802), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8898] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(796), 1,
      anon_sym_SLASH,
    ACTIONS(794), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8917] = 4,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(820), 1,
      anon_sym_SLASH,
    ACTIONS(818), 7,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_RBRACK,
      anon_sym_PLUS,
      anon_sym_RPAREN,
      anon_sym_DASH,
  [8936] = 6,
    ACTIONS(906), 1,
      anon_sym_RBRACE,
    ACTIONS(910), 1,
      aux_sym_integer_value_token1,
    STATE(305), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(908), 2,
      sym_from,
      sym_to,
    STATE(243), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [8958] = 7,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(912), 1,
      anon_sym_COMMA,
    ACTIONS(916), 1,
      anon_sym_RBRACK,
    ACTIONS(918), 1,
      anon_sym_SLASH,
    STATE(295), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(914), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [8982] = 6,
    ACTIONS(910), 1,
      aux_sym_integer_value_token1,
    ACTIONS(920), 1,
      anon_sym_RBRACE,
    STATE(305), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(908), 2,
      sym_from,
      sym_to,
    STATE(238), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [9004] = 7,
    ACTIONS(686), 1,
      anon_sym_SQUOTE,
    ACTIONS(688), 1,
      anon_sym_DQUOTE,
    ACTIONS(890), 1,
      anon_sym_LPAREN,
    ACTIONS(922), 1,
      sym_identifier,
    STATE(219), 1,
      sym_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(336), 2,
      sym_string_value,
      sym_call_expression,
  [9028] = 6,
    ACTIONS(910), 1,
      aux_sym_integer_value_token1,
    ACTIONS(924), 1,
      anon_sym_RBRACE,
    STATE(305), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(908), 2,
      sym_from,
      sym_to,
    STATE(243), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [9050] = 6,
    ACTIONS(926), 1,
      anon_sym_RBRACE,
    ACTIONS(931), 1,
      aux_sym_integer_value_token1,
    STATE(305), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(928), 2,
      sym_from,
      sym_to,
    STATE(243), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [9072] = 7,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(912), 1,
      anon_sym_COMMA,
    ACTIONS(918), 1,
      anon_sym_SLASH,
    ACTIONS(934), 1,
      anon_sym_RBRACK,
    STATE(297), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(914), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9096] = 7,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(912), 1,
      anon_sym_COMMA,
    ACTIONS(918), 1,
      anon_sym_SLASH,
    ACTIONS(936), 1,
      anon_sym_RBRACK,
    STATE(298), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(914), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9120] = 7,
    ACTIONS(856), 1,
      anon_sym_LBRACE,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    ACTIONS(940), 1,
      anon_sym_SEMI,
    STATE(141), 1,
      sym_block,
    STATE(271), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(942), 2,
      anon_sym_and,
      anon_sym_or,
  [9144] = 7,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    ACTIONS(944), 1,
      anon_sym_SEMI,
    STATE(123), 1,
      sym_block,
    STATE(270), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(942), 2,
      anon_sym_and,
      anon_sym_or,
  [9168] = 6,
    ACTIONS(910), 1,
      aux_sym_integer_value_token1,
    ACTIONS(946), 1,
      anon_sym_RBRACE,
    STATE(305), 1,
      sym_integer_value,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(908), 2,
      sym_from,
      sym_to,
    STATE(242), 2,
      sym_keyframe_block,
      aux_sym_keyframe_block_list_repeat1,
  [9190] = 7,
    ACTIONS(686), 1,
      anon_sym_SQUOTE,
    ACTIONS(688), 1,
      anon_sym_DQUOTE,
    ACTIONS(890), 1,
      anon_sym_LPAREN,
    ACTIONS(922), 1,
      sym_identifier,
    STATE(219), 1,
      sym_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(327), 2,
      sym_string_value,
      sym_call_expression,
  [9214] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(948), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9227] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(950), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9240] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(952), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9253] = 6,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    STATE(90), 1,
      sym_block,
    STATE(283), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(942), 2,
      anon_sym_and,
      anon_sym_or,
  [9274] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(954), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9287] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(956), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9300] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(918), 1,
      anon_sym_SLASH,
    ACTIONS(958), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
    ACTIONS(914), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9319] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(470), 6,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9332] = 6,
    ACTIONS(856), 1,
      anon_sym_LBRACE,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    STATE(142), 1,
      sym_block,
    STATE(275), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(942), 2,
      anon_sym_and,
      anon_sym_or,
  [9353] = 3,
    ACTIONS(962), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(960), 4,
      anon_sym_has,
      anon_sym_not,
      anon_sym_is,
      anon_sym_where,
  [9367] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(918), 1,
      anon_sym_SLASH,
    ACTIONS(964), 1,
      anon_sym_RBRACK,
    ACTIONS(914), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9385] = 3,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(942), 2,
      anon_sym_and,
      anon_sym_or,
    ACTIONS(966), 3,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [9399] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(918), 1,
      anon_sym_SLASH,
    ACTIONS(968), 1,
      anon_sym_SEMI,
    ACTIONS(914), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9417] = 5,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    ACTIONS(970), 1,
      anon_sym_SEMI,
    STATE(300), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(942), 2,
      anon_sym_and,
      anon_sym_or,
  [9435] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(918), 1,
      anon_sym_SLASH,
    ACTIONS(972), 1,
      anon_sym_RBRACK,
    ACTIONS(914), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9453] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(918), 1,
      anon_sym_SLASH,
    ACTIONS(974), 1,
      anon_sym_RPAREN,
    ACTIONS(914), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9471] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(918), 1,
      anon_sym_SLASH,
    ACTIONS(976), 1,
      anon_sym_RPAREN,
    ACTIONS(914), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9489] = 5,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    ACTIONS(978), 1,
      anon_sym_SEMI,
    STATE(296), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(942), 2,
      anon_sym_and,
      anon_sym_or,
  [9507] = 5,
    ACTIONS(686), 1,
      anon_sym_SQUOTE,
    ACTIONS(688), 1,
      anon_sym_DQUOTE,
    ACTIONS(980), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(347), 2,
      sym_string_value,
      sym_call_expression,
  [9525] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(918), 1,
      anon_sym_SLASH,
    ACTIONS(982), 1,
      anon_sym_RPAREN,
    ACTIONS(914), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9543] = 6,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    ACTIONS(984), 1,
      anon_sym_SEMI,
    STATE(130), 1,
      sym_block,
    STATE(288), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9563] = 6,
    ACTIONS(856), 1,
      anon_sym_LBRACE,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    ACTIONS(986), 1,
      anon_sym_SEMI,
    STATE(146), 1,
      sym_block,
    STATE(288), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9583] = 5,
    ACTIONS(686), 1,
      anon_sym_SQUOTE,
    ACTIONS(688), 1,
      anon_sym_DQUOTE,
    ACTIONS(988), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    STATE(344), 2,
      sym_string_value,
      sym_call_expression,
  [9601] = 3,
    ACTIONS(992), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(990), 4,
      anon_sym_has,
      anon_sym_not,
      anon_sym_is,
      anon_sym_where,
  [9615] = 5,
    ACTIONS(3), 1,
      sym_js_comment,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(918), 1,
      anon_sym_SLASH,
    ACTIONS(994), 1,
      anon_sym_SEMI,
    ACTIONS(914), 3,
      anon_sym_STAR,
      anon_sym_PLUS,
      anon_sym_DASH,
  [9633] = 5,
    ACTIONS(856), 1,
      anon_sym_LBRACE,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    STATE(98), 1,
      sym_block,
    STATE(288), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9650] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(654), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9661] = 3,
    ACTIONS(900), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(470), 3,
      anon_sym_RPAREN,
      anon_sym_and,
      anon_sym_or,
  [9674] = 4,
    ACTIONS(996), 1,
      anon_sym_COMMA,
    STATE(278), 1,
      aux_sym_selectors_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(884), 2,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
  [9689] = 4,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    STATE(121), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(942), 2,
      anon_sym_and,
      anon_sym_or,
  [9704] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(999), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9715] = 4,
    ACTIONS(1001), 1,
      anon_sym_RPAREN,
    STATE(287), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9730] = 4,
    ACTIONS(1003), 1,
      anon_sym_RPAREN,
    STATE(287), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9745] = 5,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    STATE(125), 1,
      sym_block,
    STATE(288), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9762] = 4,
    ACTIONS(1005), 1,
      anon_sym_RPAREN,
    STATE(287), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9777] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(670), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9788] = 2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(724), 4,
      anon_sym_RBRACE,
      sym_from,
      sym_to,
      aux_sym_integer_value_token1,
  [9799] = 4,
    ACTIONS(408), 1,
      anon_sym_RPAREN,
    STATE(287), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(1007), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [9814] = 4,
    ACTIONS(1010), 1,
      anon_sym_COMMA,
    STATE(288), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(966), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [9829] = 4,
    ACTIONS(856), 1,
      anon_sym_LBRACE,
    STATE(93), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(942), 2,
      anon_sym_and,
      anon_sym_or,
  [9844] = 4,
    ACTIONS(420), 1,
      anon_sym_COMMA,
    ACTIONS(1013), 1,
      anon_sym_RPAREN,
    STATE(294), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9858] = 4,
    ACTIONS(958), 1,
      anon_sym_RBRACK,
    ACTIONS(1015), 1,
      anon_sym_COMMA,
    STATE(291), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9872] = 4,
    ACTIONS(862), 1,
      anon_sym_COMMA,
    ACTIONS(1018), 1,
      anon_sym_LBRACE,
    STATE(278), 1,
      aux_sym_selectors_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9886] = 3,
    ACTIONS(1020), 1,
      anon_sym_RPAREN,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
    ACTIONS(942), 2,
      anon_sym_and,
      anon_sym_or,
  [9898] = 4,
    ACTIONS(450), 1,
      anon_sym_RPAREN,
    ACTIONS(1022), 1,
      anon_sym_COMMA,
    STATE(294), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9912] = 4,
    ACTIONS(912), 1,
      anon_sym_COMMA,
    ACTIONS(1025), 1,
      anon_sym_RBRACK,
    STATE(291), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9926] = 4,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    ACTIONS(1027), 1,
      anon_sym_SEMI,
    STATE(288), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9940] = 4,
    ACTIONS(912), 1,
      anon_sym_COMMA,
    ACTIONS(1029), 1,
      anon_sym_RBRACK,
    STATE(291), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9954] = 4,
    ACTIONS(912), 1,
      anon_sym_COMMA,
    ACTIONS(1031), 1,
      anon_sym_RBRACK,
    STATE(291), 1,
      aux_sym_grid_value_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9968] = 4,
    ACTIONS(420), 1,
      anon_sym_COMMA,
    ACTIONS(1033), 1,
      anon_sym_RPAREN,
    STATE(294), 1,
      aux_sym_pseudo_class_arguments_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9982] = 4,
    ACTIONS(938), 1,
      anon_sym_COMMA,
    ACTIONS(1035), 1,
      anon_sym_SEMI,
    STATE(288), 1,
      aux_sym_import_statement_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [9996] = 4,
    ACTIONS(862), 1,
      anon_sym_COMMA,
    ACTIONS(1037), 1,
      anon_sym_RPAREN,
    STATE(278), 1,
      aux_sym_selectors_repeat1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10010] = 3,
    ACTIONS(1039), 1,
      anon_sym_LBRACE,
    STATE(92), 1,
      sym_keyframe_block_list,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10021] = 3,
    ACTIONS(1041), 1,
      anon_sym_LPAREN,
    STATE(64), 1,
      sym_pseudo_class_with_selector_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10032] = 3,
    ACTIONS(1043), 1,
      aux_sym_color_value_token1,
    ACTIONS(1045), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10043] = 3,
    ACTIONS(1047), 1,
      anon_sym_LBRACE,
    STATE(280), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10054] = 3,
    ACTIONS(734), 1,
      anon_sym_LBRACE,
    ACTIONS(1049), 1,
      sym_unit,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10065] = 3,
    ACTIONS(1045), 1,
      sym_identifier,
    ACTIONS(1051), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10076] = 3,
    ACTIONS(890), 1,
      anon_sym_LPAREN,
    STATE(219), 1,
      sym_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10087] = 3,
    ACTIONS(239), 1,
      anon_sym_LBRACE,
    STATE(114), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10098] = 3,
    ACTIONS(856), 1,
      anon_sym_LBRACE,
    STATE(91), 1,
      sym_block,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10109] = 3,
    ACTIONS(1041), 1,
      anon_sym_LPAREN,
    STATE(61), 1,
      sym_pseudo_class_with_selector_arguments,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10120] = 3,
    ACTIONS(1053), 1,
      anon_sym_LBRACE,
    STATE(120), 1,
      sym_keyframe_block_list,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10131] = 2,
    ACTIONS(1055), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10139] = 2,
    ACTIONS(1057), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10147] = 2,
    ACTIONS(1059), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10155] = 2,
    ACTIONS(1061), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10163] = 2,
    ACTIONS(1061), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10171] = 2,
    ACTIONS(65), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10179] = 2,
    ACTIONS(1063), 1,
      ts_builtin_sym_end,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10187] = 2,
    ACTIONS(63), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10195] = 2,
    ACTIONS(1065), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10203] = 2,
    ACTIONS(69), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10211] = 2,
    ACTIONS(1067), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10219] = 2,
    ACTIONS(1069), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10227] = 2,
    ACTIONS(1071), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10235] = 2,
    ACTIONS(1073), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10243] = 2,
    ACTIONS(1075), 1,
      anon_sym_SEMI,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10251] = 2,
    ACTIONS(1077), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10259] = 2,
    ACTIONS(1077), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10267] = 2,
    ACTIONS(1079), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10275] = 2,
    ACTIONS(1079), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10283] = 2,
    ACTIONS(1081), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10291] = 2,
    ACTIONS(1083), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10299] = 2,
    ACTIONS(1085), 1,
      anon_sym_LPAREN2,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10307] = 2,
    ACTIONS(1087), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10315] = 2,
    ACTIONS(1089), 1,
      anon_sym_SEMI,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10323] = 2,
    ACTIONS(1091), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10331] = 2,
    ACTIONS(1093), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10339] = 2,
    ACTIONS(1095), 1,
      aux_sym_color_value_token1,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10347] = 2,
    ACTIONS(1097), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10355] = 2,
    ACTIONS(1099), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10363] = 2,
    ACTIONS(1067), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10371] = 2,
    ACTIONS(1101), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10379] = 2,
    ACTIONS(1103), 1,
      anon_sym_SEMI,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10387] = 2,
    ACTIONS(1105), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10395] = 2,
    ACTIONS(1107), 1,
      anon_sym_RBRACE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10403] = 2,
    ACTIONS(1109), 1,
      anon_sym_SEMI,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10411] = 2,
    ACTIONS(1111), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10419] = 2,
    ACTIONS(1113), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10427] = 2,
    ACTIONS(1115), 1,
      sym_identifier,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10435] = 2,
    ACTIONS(1117), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10443] = 2,
    ACTIONS(1119), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10451] = 2,
    ACTIONS(1121), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10459] = 2,
    ACTIONS(1123), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10467] = 2,
    ACTIONS(1125), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10475] = 2,
    ACTIONS(1127), 1,
      aux_sym_string_value_token1,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10483] = 2,
    ACTIONS(1129), 1,
      aux_sym_string_value_token2,
    ACTIONS(3), 2,
      sym_js_comment,
      sym_comment,
  [10491] = 2,
    ACTIONS(1083), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
  [10499] = 2,
    ACTIONS(1081), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_js_comment,
      sym_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 94,
  [SMALL_STATE(4)] = 188,
  [SMALL_STATE(5)] = 282,
  [SMALL_STATE(6)] = 376,
  [SMALL_STATE(7)] = 470,
  [SMALL_STATE(8)] = 564,
  [SMALL_STATE(9)] = 655,
  [SMALL_STATE(10)] = 745,
  [SMALL_STATE(11)] = 835,
  [SMALL_STATE(12)] = 920,
  [SMALL_STATE(13)] = 1005,
  [SMALL_STATE(14)] = 1087,
  [SMALL_STATE(15)] = 1168,
  [SMALL_STATE(16)] = 1249,
  [SMALL_STATE(17)] = 1324,
  [SMALL_STATE(18)] = 1387,
  [SMALL_STATE(19)] = 1450,
  [SMALL_STATE(20)] = 1518,
  [SMALL_STATE(21)] = 1583,
  [SMALL_STATE(22)] = 1648,
  [SMALL_STATE(23)] = 1692,
  [SMALL_STATE(24)] = 1753,
  [SMALL_STATE(25)] = 1814,
  [SMALL_STATE(26)] = 1867,
  [SMALL_STATE(27)] = 1928,
  [SMALL_STATE(28)] = 1984,
  [SMALL_STATE(29)] = 2034,
  [SMALL_STATE(30)] = 2084,
  [SMALL_STATE(31)] = 2134,
  [SMALL_STATE(32)] = 2184,
  [SMALL_STATE(33)] = 2230,
  [SMALL_STATE(34)] = 2280,
  [SMALL_STATE(35)] = 2338,
  [SMALL_STATE(36)] = 2390,
  [SMALL_STATE(37)] = 2446,
  [SMALL_STATE(38)] = 2506,
  [SMALL_STATE(39)] = 2540,
  [SMALL_STATE(40)] = 2600,
  [SMALL_STATE(41)] = 2638,
  [SMALL_STATE(42)] = 2690,
  [SMALL_STATE(43)] = 2740,
  [SMALL_STATE(44)] = 2800,
  [SMALL_STATE(45)] = 2850,
  [SMALL_STATE(46)] = 2885,
  [SMALL_STATE(47)] = 2942,
  [SMALL_STATE(48)] = 2997,
  [SMALL_STATE(49)] = 3032,
  [SMALL_STATE(50)] = 3089,
  [SMALL_STATE(51)] = 3124,
  [SMALL_STATE(52)] = 3159,
  [SMALL_STATE(53)] = 3213,
  [SMALL_STATE(54)] = 3253,
  [SMALL_STATE(55)] = 3307,
  [SMALL_STATE(56)] = 3361,
  [SMALL_STATE(57)] = 3415,
  [SMALL_STATE(58)] = 3469,
  [SMALL_STATE(59)] = 3498,
  [SMALL_STATE(60)] = 3527,
  [SMALL_STATE(61)] = 3556,
  [SMALL_STATE(62)] = 3585,
  [SMALL_STATE(63)] = 3636,
  [SMALL_STATE(64)] = 3665,
  [SMALL_STATE(65)] = 3694,
  [SMALL_STATE(66)] = 3723,
  [SMALL_STATE(67)] = 3752,
  [SMALL_STATE(68)] = 3781,
  [SMALL_STATE(69)] = 3810,
  [SMALL_STATE(70)] = 3861,
  [SMALL_STATE(71)] = 3890,
  [SMALL_STATE(72)] = 3919,
  [SMALL_STATE(73)] = 3948,
  [SMALL_STATE(74)] = 3977,
  [SMALL_STATE(75)] = 4006,
  [SMALL_STATE(76)] = 4035,
  [SMALL_STATE(77)] = 4064,
  [SMALL_STATE(78)] = 4093,
  [SMALL_STATE(79)] = 4122,
  [SMALL_STATE(80)] = 4151,
  [SMALL_STATE(81)] = 4186,
  [SMALL_STATE(82)] = 4215,
  [SMALL_STATE(83)] = 4244,
  [SMALL_STATE(84)] = 4275,
  [SMALL_STATE(85)] = 4304,
  [SMALL_STATE(86)] = 4333,
  [SMALL_STATE(87)] = 4364,
  [SMALL_STATE(88)] = 4395,
  [SMALL_STATE(89)] = 4426,
  [SMALL_STATE(90)] = 4457,
  [SMALL_STATE(91)] = 4485,
  [SMALL_STATE(92)] = 4513,
  [SMALL_STATE(93)] = 4541,
  [SMALL_STATE(94)] = 4569,
  [SMALL_STATE(95)] = 4597,
  [SMALL_STATE(96)] = 4645,
  [SMALL_STATE(97)] = 4673,
  [SMALL_STATE(98)] = 4701,
  [SMALL_STATE(99)] = 4729,
  [SMALL_STATE(100)] = 4757,
  [SMALL_STATE(101)] = 4785,
  [SMALL_STATE(102)] = 4833,
  [SMALL_STATE(103)] = 4861,
  [SMALL_STATE(104)] = 4889,
  [SMALL_STATE(105)] = 4917,
  [SMALL_STATE(106)] = 4945,
  [SMALL_STATE(107)] = 4973,
  [SMALL_STATE(108)] = 5021,
  [SMALL_STATE(109)] = 5049,
  [SMALL_STATE(110)] = 5077,
  [SMALL_STATE(111)] = 5105,
  [SMALL_STATE(112)] = 5153,
  [SMALL_STATE(113)] = 5201,
  [SMALL_STATE(114)] = 5229,
  [SMALL_STATE(115)] = 5257,
  [SMALL_STATE(116)] = 5285,
  [SMALL_STATE(117)] = 5333,
  [SMALL_STATE(118)] = 5381,
  [SMALL_STATE(119)] = 5409,
  [SMALL_STATE(120)] = 5437,
  [SMALL_STATE(121)] = 5465,
  [SMALL_STATE(122)] = 5493,
  [SMALL_STATE(123)] = 5521,
  [SMALL_STATE(124)] = 5549,
  [SMALL_STATE(125)] = 5577,
  [SMALL_STATE(126)] = 5605,
  [SMALL_STATE(127)] = 5633,
  [SMALL_STATE(128)] = 5661,
  [SMALL_STATE(129)] = 5689,
  [SMALL_STATE(130)] = 5717,
  [SMALL_STATE(131)] = 5745,
  [SMALL_STATE(132)] = 5773,
  [SMALL_STATE(133)] = 5801,
  [SMALL_STATE(134)] = 5849,
  [SMALL_STATE(135)] = 5877,
  [SMALL_STATE(136)] = 5905,
  [SMALL_STATE(137)] = 5937,
  [SMALL_STATE(138)] = 5969,
  [SMALL_STATE(139)] = 5997,
  [SMALL_STATE(140)] = 6045,
  [SMALL_STATE(141)] = 6093,
  [SMALL_STATE(142)] = 6121,
  [SMALL_STATE(143)] = 6149,
  [SMALL_STATE(144)] = 6177,
  [SMALL_STATE(145)] = 6205,
  [SMALL_STATE(146)] = 6233,
  [SMALL_STATE(147)] = 6261,
  [SMALL_STATE(148)] = 6309,
  [SMALL_STATE(149)] = 6357,
  [SMALL_STATE(150)] = 6405,
  [SMALL_STATE(151)] = 6453,
  [SMALL_STATE(152)] = 6501,
  [SMALL_STATE(153)] = 6549,
  [SMALL_STATE(154)] = 6597,
  [SMALL_STATE(155)] = 6645,
  [SMALL_STATE(156)] = 6693,
  [SMALL_STATE(157)] = 6741,
  [SMALL_STATE(158)] = 6769,
  [SMALL_STATE(159)] = 6798,
  [SMALL_STATE(160)] = 6827,
  [SMALL_STATE(161)] = 6856,
  [SMALL_STATE(162)] = 6885,
  [SMALL_STATE(163)] = 6914,
  [SMALL_STATE(164)] = 6943,
  [SMALL_STATE(165)] = 6972,
  [SMALL_STATE(166)] = 7001,
  [SMALL_STATE(167)] = 7030,
  [SMALL_STATE(168)] = 7059,
  [SMALL_STATE(169)] = 7088,
  [SMALL_STATE(170)] = 7117,
  [SMALL_STATE(171)] = 7149,
  [SMALL_STATE(172)] = 7181,
  [SMALL_STATE(173)] = 7211,
  [SMALL_STATE(174)] = 7243,
  [SMALL_STATE(175)] = 7273,
  [SMALL_STATE(176)] = 7305,
  [SMALL_STATE(177)] = 7335,
  [SMALL_STATE(178)] = 7365,
  [SMALL_STATE(179)] = 7397,
  [SMALL_STATE(180)] = 7426,
  [SMALL_STATE(181)] = 7455,
  [SMALL_STATE(182)] = 7484,
  [SMALL_STATE(183)] = 7523,
  [SMALL_STATE(184)] = 7562,
  [SMALL_STATE(185)] = 7591,
  [SMALL_STATE(186)] = 7619,
  [SMALL_STATE(187)] = 7645,
  [SMALL_STATE(188)] = 7680,
  [SMALL_STATE(189)] = 7702,
  [SMALL_STATE(190)] = 7724,
  [SMALL_STATE(191)] = 7768,
  [SMALL_STATE(192)] = 7808,
  [SMALL_STATE(193)] = 7852,
  [SMALL_STATE(194)] = 7896,
  [SMALL_STATE(195)] = 7918,
  [SMALL_STATE(196)] = 7962,
  [SMALL_STATE(197)] = 8001,
  [SMALL_STATE(198)] = 8028,
  [SMALL_STATE(199)] = 8052,
  [SMALL_STATE(200)] = 8078,
  [SMALL_STATE(201)] = 8104,
  [SMALL_STATE(202)] = 8130,
  [SMALL_STATE(203)] = 8154,
  [SMALL_STATE(204)] = 8192,
  [SMALL_STATE(205)] = 8218,
  [SMALL_STATE(206)] = 8240,
  [SMALL_STATE(207)] = 8266,
  [SMALL_STATE(208)] = 8292,
  [SMALL_STATE(209)] = 8318,
  [SMALL_STATE(210)] = 8344,
  [SMALL_STATE(211)] = 8379,
  [SMALL_STATE(212)] = 8408,
  [SMALL_STATE(213)] = 8429,
  [SMALL_STATE(214)] = 8450,
  [SMALL_STATE(215)] = 8471,
  [SMALL_STATE(216)] = 8492,
  [SMALL_STATE(217)] = 8513,
  [SMALL_STATE(218)] = 8534,
  [SMALL_STATE(219)] = 8555,
  [SMALL_STATE(220)] = 8576,
  [SMALL_STATE(221)] = 8597,
  [SMALL_STATE(222)] = 8618,
  [SMALL_STATE(223)] = 8643,
  [SMALL_STATE(224)] = 8664,
  [SMALL_STATE(225)] = 8686,
  [SMALL_STATE(226)] = 8708,
  [SMALL_STATE(227)] = 8727,
  [SMALL_STATE(228)] = 8746,
  [SMALL_STATE(229)] = 8765,
  [SMALL_STATE(230)] = 8784,
  [SMALL_STATE(231)] = 8803,
  [SMALL_STATE(232)] = 8822,
  [SMALL_STATE(233)] = 8841,
  [SMALL_STATE(234)] = 8860,
  [SMALL_STATE(235)] = 8879,
  [SMALL_STATE(236)] = 8898,
  [SMALL_STATE(237)] = 8917,
  [SMALL_STATE(238)] = 8936,
  [SMALL_STATE(239)] = 8958,
  [SMALL_STATE(240)] = 8982,
  [SMALL_STATE(241)] = 9004,
  [SMALL_STATE(242)] = 9028,
  [SMALL_STATE(243)] = 9050,
  [SMALL_STATE(244)] = 9072,
  [SMALL_STATE(245)] = 9096,
  [SMALL_STATE(246)] = 9120,
  [SMALL_STATE(247)] = 9144,
  [SMALL_STATE(248)] = 9168,
  [SMALL_STATE(249)] = 9190,
  [SMALL_STATE(250)] = 9214,
  [SMALL_STATE(251)] = 9227,
  [SMALL_STATE(252)] = 9240,
  [SMALL_STATE(253)] = 9253,
  [SMALL_STATE(254)] = 9274,
  [SMALL_STATE(255)] = 9287,
  [SMALL_STATE(256)] = 9300,
  [SMALL_STATE(257)] = 9319,
  [SMALL_STATE(258)] = 9332,
  [SMALL_STATE(259)] = 9353,
  [SMALL_STATE(260)] = 9367,
  [SMALL_STATE(261)] = 9385,
  [SMALL_STATE(262)] = 9399,
  [SMALL_STATE(263)] = 9417,
  [SMALL_STATE(264)] = 9435,
  [SMALL_STATE(265)] = 9453,
  [SMALL_STATE(266)] = 9471,
  [SMALL_STATE(267)] = 9489,
  [SMALL_STATE(268)] = 9507,
  [SMALL_STATE(269)] = 9525,
  [SMALL_STATE(270)] = 9543,
  [SMALL_STATE(271)] = 9563,
  [SMALL_STATE(272)] = 9583,
  [SMALL_STATE(273)] = 9601,
  [SMALL_STATE(274)] = 9615,
  [SMALL_STATE(275)] = 9633,
  [SMALL_STATE(276)] = 9650,
  [SMALL_STATE(277)] = 9661,
  [SMALL_STATE(278)] = 9674,
  [SMALL_STATE(279)] = 9689,
  [SMALL_STATE(280)] = 9704,
  [SMALL_STATE(281)] = 9715,
  [SMALL_STATE(282)] = 9730,
  [SMALL_STATE(283)] = 9745,
  [SMALL_STATE(284)] = 9762,
  [SMALL_STATE(285)] = 9777,
  [SMALL_STATE(286)] = 9788,
  [SMALL_STATE(287)] = 9799,
  [SMALL_STATE(288)] = 9814,
  [SMALL_STATE(289)] = 9829,
  [SMALL_STATE(290)] = 9844,
  [SMALL_STATE(291)] = 9858,
  [SMALL_STATE(292)] = 9872,
  [SMALL_STATE(293)] = 9886,
  [SMALL_STATE(294)] = 9898,
  [SMALL_STATE(295)] = 9912,
  [SMALL_STATE(296)] = 9926,
  [SMALL_STATE(297)] = 9940,
  [SMALL_STATE(298)] = 9954,
  [SMALL_STATE(299)] = 9968,
  [SMALL_STATE(300)] = 9982,
  [SMALL_STATE(301)] = 9996,
  [SMALL_STATE(302)] = 10010,
  [SMALL_STATE(303)] = 10021,
  [SMALL_STATE(304)] = 10032,
  [SMALL_STATE(305)] = 10043,
  [SMALL_STATE(306)] = 10054,
  [SMALL_STATE(307)] = 10065,
  [SMALL_STATE(308)] = 10076,
  [SMALL_STATE(309)] = 10087,
  [SMALL_STATE(310)] = 10098,
  [SMALL_STATE(311)] = 10109,
  [SMALL_STATE(312)] = 10120,
  [SMALL_STATE(313)] = 10131,
  [SMALL_STATE(314)] = 10139,
  [SMALL_STATE(315)] = 10147,
  [SMALL_STATE(316)] = 10155,
  [SMALL_STATE(317)] = 10163,
  [SMALL_STATE(318)] = 10171,
  [SMALL_STATE(319)] = 10179,
  [SMALL_STATE(320)] = 10187,
  [SMALL_STATE(321)] = 10195,
  [SMALL_STATE(322)] = 10203,
  [SMALL_STATE(323)] = 10211,
  [SMALL_STATE(324)] = 10219,
  [SMALL_STATE(325)] = 10227,
  [SMALL_STATE(326)] = 10235,
  [SMALL_STATE(327)] = 10243,
  [SMALL_STATE(328)] = 10251,
  [SMALL_STATE(329)] = 10259,
  [SMALL_STATE(330)] = 10267,
  [SMALL_STATE(331)] = 10275,
  [SMALL_STATE(332)] = 10283,
  [SMALL_STATE(333)] = 10291,
  [SMALL_STATE(334)] = 10299,
  [SMALL_STATE(335)] = 10307,
  [SMALL_STATE(336)] = 10315,
  [SMALL_STATE(337)] = 10323,
  [SMALL_STATE(338)] = 10331,
  [SMALL_STATE(339)] = 10339,
  [SMALL_STATE(340)] = 10347,
  [SMALL_STATE(341)] = 10355,
  [SMALL_STATE(342)] = 10363,
  [SMALL_STATE(343)] = 10371,
  [SMALL_STATE(344)] = 10379,
  [SMALL_STATE(345)] = 10387,
  [SMALL_STATE(346)] = 10395,
  [SMALL_STATE(347)] = 10403,
  [SMALL_STATE(348)] = 10411,
  [SMALL_STATE(349)] = 10419,
  [SMALL_STATE(350)] = 10427,
  [SMALL_STATE(351)] = 10435,
  [SMALL_STATE(352)] = 10443,
  [SMALL_STATE(353)] = 10451,
  [SMALL_STATE(354)] = 10459,
  [SMALL_STATE(355)] = 10467,
  [SMALL_STATE(356)] = 10475,
  [SMALL_STATE(357)] = 10483,
  [SMALL_STATE(358)] = 10491,
  [SMALL_STATE(359)] = 10499,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stylesheet, 0, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(200),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(268),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(325),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(201),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(326),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(345),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(350),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(351),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(187),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(209),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(272),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(338),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(199),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(285),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(286),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(148),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(209),
  [77] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(149),
  [80] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(272),
  [83] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(338),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(199),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(192),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(78),
  [97] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(326),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(345),
  [103] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(350),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [109] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(351),
  [112] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(314),
  [115] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(194),
  [118] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [121] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(273),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stylesheet, 1, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0),
  [128] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [131] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(200),
  [134] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [137] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(268),
  [140] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(325),
  [143] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(201),
  [146] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(192),
  [149] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(78),
  [152] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(326),
  [155] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(345),
  [158] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(350),
  [161] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [164] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(351),
  [167] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(314),
  [170] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(188),
  [173] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(187),
  [176] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_stylesheet_repeat1, 2, 0, 0), SHIFT_REPEAT(273),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(326),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(354),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(355),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(136),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(170),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(304),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(356),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(357),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(225),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(224),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(239),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [235] = {.entry = {.count = 1, .reusable = false}}, SHIFT(245),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(204),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [249] = {.entry = {.count = 1, .reusable = false}}, SHIFT(334),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(352),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(353),
  [255] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(337),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(348),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(349),
  [269] = {.entry = {.count = 1, .reusable = false}}, SHIFT(211),
  [271] = {.entry = {.count = 1, .reusable = false}}, SHIFT(266),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(269),
  [275] = {.entry = {.count = 1, .reusable = false}}, SHIFT(269),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_last_declaration, 3, 0, 14),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [285] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [289] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [291] = {.entry = {.count = 1, .reusable = false}}, SHIFT(175),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selector, 1, 0, 1),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__value, 1, 0, 3),
  [303] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__selector, 1, 0, 1),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [307] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__value, 1, 0, 3),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0),
  [325] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(315),
  [328] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(155),
  [331] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(170),
  [334] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(156),
  [337] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(352),
  [340] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(353),
  [343] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(136),
  [346] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(137),
  [349] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(80),
  [352] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(170),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [371] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0),
  [376] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(315),
  [379] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(155),
  [382] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(175),
  [385] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(156),
  [388] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(352),
  [391] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(353),
  [394] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(136),
  [397] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(137),
  [400] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(80),
  [403] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(175),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [408] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arguments_repeat1, 2, 0, 0),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [412] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_last_declaration, 4, 0, 14),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_value, 3, 0, 0),
  [418] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_value, 3, 0, 0),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [424] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selector, 1, 0, 0),
  [426] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__value, 1, 0, 0),
  [428] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__selector, 1, 0, 0),
  [430] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__value, 1, 0, 0),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [440] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 3, 0, 11),
  [442] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 3, 0, 11),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [450] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pseudo_class_arguments_repeat1, 2, 0, 0),
  [452] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 2, 0, 5),
  [454] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 2, 0, 5),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [458] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 3, 0, 10),
  [460] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 3, 0, 10),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 2, 0, 2),
  [466] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 2, 0, 2),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__query, 1, 0, 4),
  [472] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__query, 1, 0, 4),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(252),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 5, 0, 9),
  [484] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 5, 0, 9),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_with_selector_arguments, 2, 0, 0),
  [488] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_with_selector_arguments, 2, 0, 0),
  [490] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_arguments, 2, 0, 0),
  [492] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_arguments, 2, 0, 0),
  [494] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 3, 0, 2),
  [496] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 3, 0, 2),
  [498] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_arguments, 2, 0, 0),
  [500] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_arguments, 2, 0, 0),
  [502] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_selector, 4, 0, 10),
  [504] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_selector, 4, 0, 10),
  [506] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 4, 0, 11),
  [508] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 4, 0, 11),
  [510] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 4, 0, 15),
  [512] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 4, 0, 15),
  [514] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_with_selector_arguments, 3, 0, 0),
  [516] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_with_selector_arguments, 3, 0, 0),
  [518] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_arguments, 3, 0, 0),
  [520] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_arguments, 3, 0, 0),
  [522] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_selector, 3, 0, 5),
  [524] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_selector, 3, 0, 5),
  [526] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_arguments, 3, 0, 0),
  [528] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_arguments, 3, 0, 0),
  [530] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 3, 0, 9),
  [532] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 3, 0, 9),
  [534] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_with_selector_arguments, 4, 0, 0),
  [536] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_with_selector_arguments, 4, 0, 0),
  [538] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_selector, 2, 0, 2),
  [540] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_selector, 2, 0, 2),
  [542] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_class_arguments, 4, 0, 0),
  [544] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_class_arguments, 4, 0, 0),
  [546] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pseudo_element_arguments, 4, 0, 0),
  [548] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pseudo_element_arguments, 4, 0, 0),
  [550] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_universal_selector, 1, 0, 0),
  [552] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_universal_selector, 1, 0, 0),
  [554] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_selector, 6, 0, 15),
  [556] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_selector, 6, 0, 15),
  [558] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id_selector, 2, 0, 6),
  [560] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_id_selector, 2, 0, 6),
  [562] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_descendant_selector, 3, 0, 0),
  [564] = {.entry = {.count = 1, .reusable = true}}, SHIFT(343),
  [566] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_descendant_selector, 3, 0, 0),
  [568] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_selector, 3, 0, 10),
  [570] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_selector, 3, 0, 10),
  [572] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_id_selector, 3, 0, 12),
  [574] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_id_selector, 3, 0, 12),
  [576] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_child_selector, 3, 0, 0),
  [578] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_child_selector, 3, 0, 0),
  [580] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sibling_selector, 3, 0, 0),
  [582] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sibling_selector, 3, 0, 0),
  [584] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_adjacent_sibling_selector, 3, 0, 0),
  [586] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_adjacent_sibling_selector, 3, 0, 0),
  [588] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_selector, 3, 0, 0),
  [590] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_namespace_selector, 3, 0, 0),
  [592] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_media_statement, 3, 0, 0),
  [594] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_media_statement, 3, 0, 0),
  [596] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rule_set, 2, 0, 0),
  [598] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rule_set, 2, 0, 0),
  [600] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframes_statement, 3, 0, 8),
  [602] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_keyframes_statement, 3, 0, 8),
  [604] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_supports_statement, 3, 0, 0),
  [606] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_supports_statement, 3, 0, 0),
  [608] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 4, 0, 0),
  [610] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 4, 0, 0),
  [612] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [614] = {.entry = {.count = 1, .reusable = false}}, SHIFT(222),
  [616] = {.entry = {.count = 1, .reusable = false}}, SHIFT(265),
  [618] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_at_rule, 2, 0, 0),
  [620] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_at_rule, 2, 0, 0),
  [622] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 5, 0, 0),
  [624] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 5, 0, 0),
  [626] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_media_statement, 4, 0, 0),
  [628] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_media_statement, 4, 0, 0),
  [630] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframe_block_list, 3, 0, 0),
  [632] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_keyframe_block_list, 3, 0, 0),
  [634] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_statement, 4, 0, 13),
  [636] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_namespace_statement, 4, 0, 13),
  [638] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [640] = {.entry = {.count = 1, .reusable = false}}, SHIFT(260),
  [642] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 5, 0, 14),
  [644] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 5, 0, 14),
  [646] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframe_block_list, 2, 0, 0),
  [648] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_keyframe_block_list, 2, 0, 0),
  [650] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_postcss_statement, 3, 0, 0),
  [652] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_postcss_statement, 3, 0, 0),
  [654] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 4, 0, 0),
  [656] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 4, 0, 0),
  [658] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 3, 0, 0),
  [660] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 3, 0, 0),
  [662] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [664] = {.entry = {.count = 1, .reusable = false}}, SHIFT(171),
  [666] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 4, 0, 14),
  [668] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 4, 0, 14),
  [670] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [672] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [674] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 6, 0, 14),
  [676] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 6, 0, 14),
  [678] = {.entry = {.count = 1, .reusable = true}}, SHIFT(339),
  [680] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [682] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [684] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [688] = {.entry = {.count = 1, .reusable = true}}, SHIFT(341),
  [690] = {.entry = {.count = 1, .reusable = false}}, SHIFT(198),
  [692] = {.entry = {.count = 1, .reusable = false}}, SHIFT(202),
  [694] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [696] = {.entry = {.count = 1, .reusable = false}}, SHIFT(217),
  [698] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [700] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [702] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [704] = {.entry = {.count = 1, .reusable = false}}, SHIFT(228),
  [706] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [708] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [710] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_charset_statement, 3, 0, 0),
  [712] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_charset_statement, 3, 0, 0),
  [714] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_namespace_statement, 3, 0, 0),
  [716] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_statement, 3, 0, 0),
  [718] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_at_rule, 3, 0, 0),
  [720] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_at_rule, 3, 0, 0),
  [722] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [724] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [726] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_at_rule, 4, 0, 0),
  [728] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_at_rule, 4, 0, 0),
  [730] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [732] = {.entry = {.count = 1, .reusable = false}}, SHIFT(256),
  [734] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_value, 1, 0, 0),
  [736] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_value, 1, 0, 0),
  [738] = {.entry = {.count = 1, .reusable = false}}, SHIFT(159),
  [740] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_value, 1, 0, 0),
  [742] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_value, 1, 0, 0),
  [744] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [746] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [748] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [750] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [752] = {.entry = {.count = 1, .reusable = false}}, SHIFT(244),
  [754] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [756] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [758] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [760] = {.entry = {.count = 1, .reusable = false}}, SHIFT(183),
  [762] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [764] = {.entry = {.count = 1, .reusable = false}}, SHIFT(262),
  [766] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [768] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [770] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [772] = {.entry = {.count = 1, .reusable = false}}, SHIFT(274),
  [774] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [776] = {.entry = {.count = 1, .reusable = false}}, SHIFT(264),
  [778] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_value, 2, 0, 0),
  [780] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_color_value, 2, 0, 0),
  [782] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_value, 2, 0, 0),
  [784] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_value, 2, 0, 0),
  [786] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_value, 2, 0, 0),
  [788] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_value, 2, 0, 0),
  [790] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_expression, 2, 0, 7),
  [792] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_expression, 2, 0, 7),
  [794] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 2, 0, 0),
  [796] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 2, 0, 0),
  [798] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grid_value, 3, 0, 0),
  [800] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grid_value, 3, 0, 0),
  [802] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_value, 3, 0, 0),
  [804] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesized_value, 3, 0, 0),
  [806] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, 0, 0),
  [808] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, 0, 0),
  [810] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 3, 0, 0),
  [812] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 3, 0, 0),
  [814] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grid_value, 4, 0, 0),
  [816] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grid_value, 4, 0, 0),
  [818] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 4, 0, 0),
  [820] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arguments, 4, 0, 0),
  [822] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_postcss_statement_repeat1, 1, 0, 0),
  [824] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_postcss_statement_repeat1, 1, 0, 0),
  [826] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 2, 0, 0),
  [828] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [830] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_last_declaration, 5, 0, 14),
  [832] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 1, 0, 0),
  [834] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_declaration_repeat1, 1, 0, 0),
  [836] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [838] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [840] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [842] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [844] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [846] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [848] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [850] = {.entry = {.count = 1, .reusable = false}}, SHIFT(257),
  [852] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [854] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [856] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [858] = {.entry = {.count = 1, .reusable = false}}, SHIFT(147),
  [860] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [862] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [864] = {.entry = {.count = 1, .reusable = true}}, SHIFT(335),
  [866] = {.entry = {.count = 1, .reusable = true}}, SHIFT(324),
  [868] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [870] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [872] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [874] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [876] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [878] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [880] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [882] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [884] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_selectors_repeat1, 2, 0, 0),
  [886] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selectors, 1, 0, 0),
  [888] = {.entry = {.count = 1, .reusable = false}}, SHIFT(152),
  [890] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [892] = {.entry = {.count = 1, .reusable = false}}, SHIFT(205),
  [894] = {.entry = {.count = 1, .reusable = false}}, SHIFT(221),
  [896] = {.entry = {.count = 1, .reusable = true}}, SHIFT(255),
  [898] = {.entry = {.count = 1, .reusable = false}}, SHIFT(277),
  [900] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [902] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [904] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [906] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [908] = {.entry = {.count = 1, .reusable = true}}, SHIFT(305),
  [910] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
  [912] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [914] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [916] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [918] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [920] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [922] = {.entry = {.count = 1, .reusable = true}}, SHIFT(308),
  [924] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [926] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_keyframe_block_list_repeat1, 2, 0, 0),
  [928] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_keyframe_block_list_repeat1, 2, 0, 0), SHIFT_REPEAT(305),
  [931] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_keyframe_block_list_repeat1, 2, 0, 0), SHIFT_REPEAT(306),
  [934] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [936] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [938] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [940] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [942] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [944] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [946] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [948] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_query, 3, 0, 0),
  [950] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_query, 3, 0, 0),
  [952] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_feature_query, 5, 0, 16),
  [954] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_query, 2, 0, 0),
  [956] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selector_query, 4, 0, 0),
  [958] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_grid_value_repeat1, 2, 0, 0),
  [960] = {.entry = {.count = 1, .reusable = false}}, SHIFT(303),
  [962] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [964] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [966] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_statement_repeat1, 2, 0, 0),
  [968] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [970] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [972] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [974] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [976] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [978] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [980] = {.entry = {.count = 1, .reusable = true}}, SHIFT(241),
  [982] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [984] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [986] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [988] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [990] = {.entry = {.count = 1, .reusable = false}}, SHIFT(311),
  [992] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [994] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [996] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_selectors_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [999] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyframe_block, 2, 0, 0),
  [1001] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [1003] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [1005] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [1007] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_arguments_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [1010] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(207),
  [1013] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [1015] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_grid_value_repeat1, 2, 0, 0), SHIFT_REPEAT(133),
  [1018] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selectors, 2, 0, 0),
  [1020] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [1022] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pseudo_class_arguments_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [1025] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [1027] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [1029] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [1031] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [1033] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [1035] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [1037] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [1039] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [1041] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [1043] = {.entry = {.count = 1, .reusable = false}}, SHIFT(231),
  [1045] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [1047] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [1049] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [1051] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [1053] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [1055] = {.entry = {.count = 1, .reusable = true}}, SHIFT(276),
  [1057] = {.entry = {.count = 1, .reusable = false}}, SHIFT(342),
  [1059] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [1061] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [1063] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1065] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [1067] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [1069] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [1071] = {.entry = {.count = 1, .reusable = true}}, SHIFT(302),
  [1073] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [1075] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [1077] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [1079] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [1081] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [1083] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [1085] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [1087] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [1089] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [1091] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [1093] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [1095] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [1097] = {.entry = {.count = 1, .reusable = false}}, SHIFT(358),
  [1099] = {.entry = {.count = 1, .reusable = false}}, SHIFT(333),
  [1101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [1103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [1105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [1107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [1109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [1111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(316),
  [1113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(317),
  [1115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [1117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(323),
  [1119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(328),
  [1121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(329),
  [1123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(330),
  [1125] = {.entry = {.count = 1, .reusable = false}}, SHIFT(331),
  [1127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(332),
  [1129] = {.entry = {.count = 1, .reusable = false}}, SHIFT(359),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__descendant_operator = 0,
  ts_external_token__pseudo_class_selector_colon = 1,
  ts_external_token___error_recovery = 2,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__descendant_operator] = sym__descendant_operator,
  [ts_external_token__pseudo_class_selector_colon] = sym__pseudo_class_selector_colon,
  [ts_external_token___error_recovery] = sym___error_recovery,
};

static const bool ts_external_scanner_states[4][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__descendant_operator] = true,
    [ts_external_token__pseudo_class_selector_colon] = true,
    [ts_external_token___error_recovery] = true,
  },
  [2] = {
    [ts_external_token__pseudo_class_selector_colon] = true,
  },
  [3] = {
    [ts_external_token__descendant_operator] = true,
    [ts_external_token__pseudo_class_selector_colon] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_css_external_scanner_create(void);
void tree_sitter_css_external_scanner_destroy(void *);
bool tree_sitter_css_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_css_external_scanner_serialize(void *, char *);
void tree_sitter_css_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_css(void) {
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
      tree_sitter_css_external_scanner_create,
      tree_sitter_css_external_scanner_destroy,
      tree_sitter_css_external_scanner_scan,
      tree_sitter_css_external_scanner_serialize,
      tree_sitter_css_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
