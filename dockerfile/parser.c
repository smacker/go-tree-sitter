#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 252
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 128
#define ALIAS_COUNT 0
#define TOKEN_COUNT 65
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 15

enum {
  anon_sym_LF = 1,
  aux_sym_from_instruction_token1 = 2,
  aux_sym_from_instruction_token2 = 3,
  aux_sym_run_instruction_token1 = 4,
  aux_sym_cmd_instruction_token1 = 5,
  aux_sym_label_instruction_token1 = 6,
  aux_sym_expose_instruction_token1 = 7,
  aux_sym_env_instruction_token1 = 8,
  aux_sym_add_instruction_token1 = 9,
  aux_sym_copy_instruction_token1 = 10,
  aux_sym_entrypoint_instruction_token1 = 11,
  aux_sym_volume_instruction_token1 = 12,
  aux_sym_user_instruction_token1 = 13,
  anon_sym_COLON = 14,
  aux_sym__user_name_or_group_token1 = 15,
  aux_sym_workdir_instruction_token1 = 16,
  aux_sym_arg_instruction_token1 = 17,
  aux_sym_arg_instruction_token2 = 18,
  anon_sym_EQ = 19,
  aux_sym_onbuild_instruction_token1 = 20,
  aux_sym_stopsignal_instruction_token1 = 21,
  aux_sym__stopsignal_value_token1 = 22,
  aux_sym_healthcheck_instruction_token1 = 23,
  anon_sym_NONE = 24,
  aux_sym_shell_instruction_token1 = 25,
  aux_sym_maintainer_instruction_token1 = 26,
  aux_sym_maintainer_instruction_token2 = 27,
  aux_sym_cross_build_instruction_token1 = 28,
  aux_sym_path_token1 = 29,
  aux_sym_path_token2 = 30,
  anon_sym_DOLLAR = 31,
  anon_sym_LBRACE = 32,
  aux_sym_expansion_token1 = 33,
  anon_sym_RBRACE = 34,
  sym_variable = 35,
  aux_sym__spaced_env_pair_token1 = 36,
  aux_sym__env_key_token1 = 37,
  aux_sym_expose_port_token1 = 38,
  anon_sym_SLASHtcp = 39,
  anon_sym_SLASHudp = 40,
  aux_sym_label_pair_token1 = 41,
  aux_sym_image_name_token1 = 42,
  aux_sym_image_name_token2 = 43,
  aux_sym_image_tag_token1 = 44,
  anon_sym_AT = 45,
  aux_sym_image_digest_token1 = 46,
  anon_sym_DASH_DASH = 47,
  aux_sym_param_token1 = 48,
  aux_sym_param_token2 = 49,
  aux_sym_image_alias_token1 = 50,
  anon_sym_LBRACK = 51,
  anon_sym_COMMA = 52,
  anon_sym_RBRACK = 53,
  aux_sym_shell_fragment_token1 = 54,
  aux_sym_shell_fragment_token2 = 55,
  anon_sym_BSLASH_LF = 56,
  anon_sym_POUND = 57,
  anon_sym_DQUOTE = 58,
  aux_sym_double_quoted_string_token1 = 59,
  aux_sym_unquoted_string_token1 = 60,
  anon_sym_BSLASH = 61,
  sym_escape_sequence = 62,
  sym__non_newline_whitespace = 63,
  sym_comment = 64,
  sym_source_file = 65,
  sym__instruction = 66,
  sym_from_instruction = 67,
  sym_run_instruction = 68,
  sym_cmd_instruction = 69,
  sym_label_instruction = 70,
  sym_expose_instruction = 71,
  sym_env_instruction = 72,
  sym_add_instruction = 73,
  sym_copy_instruction = 74,
  sym_entrypoint_instruction = 75,
  sym_volume_instruction = 76,
  sym_user_instruction = 77,
  aux_sym__user_name_or_group = 78,
  sym_workdir_instruction = 79,
  sym_arg_instruction = 80,
  sym_onbuild_instruction = 81,
  sym_stopsignal_instruction = 82,
  aux_sym__stopsignal_value = 83,
  sym_healthcheck_instruction = 84,
  sym_shell_instruction = 85,
  sym_maintainer_instruction = 86,
  sym_cross_build_instruction = 87,
  sym_path = 88,
  sym_expansion = 89,
  sym_env_pair = 90,
  sym__spaced_env_pair = 91,
  sym__env_key = 92,
  sym_expose_port = 93,
  sym_label_pair = 94,
  sym_image_spec = 95,
  sym_image_name = 96,
  sym_image_tag = 97,
  sym_image_digest = 98,
  sym_param = 99,
  sym_image_alias = 100,
  sym_string_array = 101,
  sym_shell_command = 102,
  sym_shell_fragment = 103,
  sym_line_continuation = 104,
  sym_required_line_continuation = 105,
  sym__comment_line = 106,
  sym__anon_comment = 107,
  sym_double_quoted_string = 108,
  sym_unquoted_string = 109,
  aux_sym_source_file_repeat1 = 110,
  aux_sym_label_instruction_repeat1 = 111,
  aux_sym_expose_instruction_repeat1 = 112,
  aux_sym_env_instruction_repeat1 = 113,
  aux_sym_add_instruction_repeat1 = 114,
  aux_sym_volume_instruction_repeat1 = 115,
  aux_sym_healthcheck_instruction_repeat1 = 116,
  aux_sym_path_repeat1 = 117,
  aux_sym_image_name_repeat1 = 118,
  aux_sym_image_tag_repeat1 = 119,
  aux_sym_image_digest_repeat1 = 120,
  aux_sym_image_alias_repeat1 = 121,
  aux_sym_string_array_repeat1 = 122,
  aux_sym_shell_command_repeat1 = 123,
  aux_sym_shell_command_repeat2 = 124,
  aux_sym_shell_fragment_repeat1 = 125,
  aux_sym_double_quoted_string_repeat1 = 126,
  aux_sym_unquoted_string_repeat1 = 127,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LF] = "\n",
  [aux_sym_from_instruction_token1] = "FROM",
  [aux_sym_from_instruction_token2] = "AS",
  [aux_sym_run_instruction_token1] = "RUN",
  [aux_sym_cmd_instruction_token1] = "CMD",
  [aux_sym_label_instruction_token1] = "LABEL",
  [aux_sym_expose_instruction_token1] = "EXPOSE",
  [aux_sym_env_instruction_token1] = "ENV",
  [aux_sym_add_instruction_token1] = "ADD",
  [aux_sym_copy_instruction_token1] = "COPY",
  [aux_sym_entrypoint_instruction_token1] = "ENTRYPOINT",
  [aux_sym_volume_instruction_token1] = "VOLUME",
  [aux_sym_user_instruction_token1] = "USER",
  [anon_sym_COLON] = ":",
  [aux_sym__user_name_or_group_token1] = "_user_name_or_group_token1",
  [aux_sym_workdir_instruction_token1] = "WORKDIR",
  [aux_sym_arg_instruction_token1] = "ARG",
  [aux_sym_arg_instruction_token2] = "unquoted_string",
  [anon_sym_EQ] = "=",
  [aux_sym_onbuild_instruction_token1] = "ONBUILD",
  [aux_sym_stopsignal_instruction_token1] = "STOPSIGNAL",
  [aux_sym__stopsignal_value_token1] = "_stopsignal_value_token1",
  [aux_sym_healthcheck_instruction_token1] = "HEALTHCHECK",
  [anon_sym_NONE] = "NONE",
  [aux_sym_shell_instruction_token1] = "SHELL",
  [aux_sym_maintainer_instruction_token1] = "MAINTAINER",
  [aux_sym_maintainer_instruction_token2] = "maintainer_instruction_token2",
  [aux_sym_cross_build_instruction_token1] = "CROSS_BUILD",
  [aux_sym_path_token1] = "path_token1",
  [aux_sym_path_token2] = "path_token2",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_LBRACE] = "{",
  [aux_sym_expansion_token1] = "variable",
  [anon_sym_RBRACE] = "}",
  [sym_variable] = "variable",
  [aux_sym__spaced_env_pair_token1] = "_spaced_env_pair_token1",
  [aux_sym__env_key_token1] = "unquoted_string",
  [aux_sym_expose_port_token1] = "expose_port_token1",
  [anon_sym_SLASHtcp] = "/tcp",
  [anon_sym_SLASHudp] = "/udp",
  [aux_sym_label_pair_token1] = "unquoted_string",
  [aux_sym_image_name_token1] = "image_name_token1",
  [aux_sym_image_name_token2] = "image_name_token2",
  [aux_sym_image_tag_token1] = "image_tag_token1",
  [anon_sym_AT] = "@",
  [aux_sym_image_digest_token1] = "image_digest_token1",
  [anon_sym_DASH_DASH] = "--",
  [aux_sym_param_token1] = "param_token1",
  [aux_sym_param_token2] = "param_token2",
  [aux_sym_image_alias_token1] = "image_alias_token1",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [aux_sym_shell_fragment_token1] = "shell_fragment_token1",
  [aux_sym_shell_fragment_token2] = "shell_fragment_token2",
  [anon_sym_BSLASH_LF] = "\\\n",
  [anon_sym_POUND] = "#",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_double_quoted_string_token1] = "double_quoted_string_token1",
  [aux_sym_unquoted_string_token1] = "unquoted_string_token1",
  [anon_sym_BSLASH] = "\\ ",
  [sym_escape_sequence] = "escape_sequence",
  [sym__non_newline_whitespace] = "_non_newline_whitespace",
  [sym_comment] = "comment",
  [sym_source_file] = "source_file",
  [sym__instruction] = "_instruction",
  [sym_from_instruction] = "from_instruction",
  [sym_run_instruction] = "run_instruction",
  [sym_cmd_instruction] = "cmd_instruction",
  [sym_label_instruction] = "label_instruction",
  [sym_expose_instruction] = "expose_instruction",
  [sym_env_instruction] = "env_instruction",
  [sym_add_instruction] = "add_instruction",
  [sym_copy_instruction] = "copy_instruction",
  [sym_entrypoint_instruction] = "entrypoint_instruction",
  [sym_volume_instruction] = "volume_instruction",
  [sym_user_instruction] = "user_instruction",
  [aux_sym__user_name_or_group] = "_user_name_or_group",
  [sym_workdir_instruction] = "workdir_instruction",
  [sym_arg_instruction] = "arg_instruction",
  [sym_onbuild_instruction] = "onbuild_instruction",
  [sym_stopsignal_instruction] = "stopsignal_instruction",
  [aux_sym__stopsignal_value] = "_stopsignal_value",
  [sym_healthcheck_instruction] = "healthcheck_instruction",
  [sym_shell_instruction] = "shell_instruction",
  [sym_maintainer_instruction] = "maintainer_instruction",
  [sym_cross_build_instruction] = "cross_build_instruction",
  [sym_path] = "path",
  [sym_expansion] = "expansion",
  [sym_env_pair] = "env_pair",
  [sym__spaced_env_pair] = "env_pair",
  [sym__env_key] = "_env_key",
  [sym_expose_port] = "expose_port",
  [sym_label_pair] = "label_pair",
  [sym_image_spec] = "image_spec",
  [sym_image_name] = "image_name",
  [sym_image_tag] = "image_tag",
  [sym_image_digest] = "image_digest",
  [sym_param] = "param",
  [sym_image_alias] = "image_alias",
  [sym_string_array] = "string_array",
  [sym_shell_command] = "shell_command",
  [sym_shell_fragment] = "shell_fragment",
  [sym_line_continuation] = "line_continuation",
  [sym_required_line_continuation] = "line_continuation",
  [sym__comment_line] = "_comment_line",
  [sym__anon_comment] = "comment",
  [sym_double_quoted_string] = "double_quoted_string",
  [sym_unquoted_string] = "unquoted_string",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_label_instruction_repeat1] = "label_instruction_repeat1",
  [aux_sym_expose_instruction_repeat1] = "expose_instruction_repeat1",
  [aux_sym_env_instruction_repeat1] = "env_instruction_repeat1",
  [aux_sym_add_instruction_repeat1] = "add_instruction_repeat1",
  [aux_sym_volume_instruction_repeat1] = "volume_instruction_repeat1",
  [aux_sym_healthcheck_instruction_repeat1] = "healthcheck_instruction_repeat1",
  [aux_sym_path_repeat1] = "path_repeat1",
  [aux_sym_image_name_repeat1] = "image_name_repeat1",
  [aux_sym_image_tag_repeat1] = "image_tag_repeat1",
  [aux_sym_image_digest_repeat1] = "image_digest_repeat1",
  [aux_sym_image_alias_repeat1] = "image_alias_repeat1",
  [aux_sym_string_array_repeat1] = "string_array_repeat1",
  [aux_sym_shell_command_repeat1] = "shell_command_repeat1",
  [aux_sym_shell_command_repeat2] = "shell_command_repeat2",
  [aux_sym_shell_fragment_repeat1] = "shell_fragment_repeat1",
  [aux_sym_double_quoted_string_repeat1] = "double_quoted_string_repeat1",
  [aux_sym_unquoted_string_repeat1] = "unquoted_string_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LF] = anon_sym_LF,
  [aux_sym_from_instruction_token1] = aux_sym_from_instruction_token1,
  [aux_sym_from_instruction_token2] = aux_sym_from_instruction_token2,
  [aux_sym_run_instruction_token1] = aux_sym_run_instruction_token1,
  [aux_sym_cmd_instruction_token1] = aux_sym_cmd_instruction_token1,
  [aux_sym_label_instruction_token1] = aux_sym_label_instruction_token1,
  [aux_sym_expose_instruction_token1] = aux_sym_expose_instruction_token1,
  [aux_sym_env_instruction_token1] = aux_sym_env_instruction_token1,
  [aux_sym_add_instruction_token1] = aux_sym_add_instruction_token1,
  [aux_sym_copy_instruction_token1] = aux_sym_copy_instruction_token1,
  [aux_sym_entrypoint_instruction_token1] = aux_sym_entrypoint_instruction_token1,
  [aux_sym_volume_instruction_token1] = aux_sym_volume_instruction_token1,
  [aux_sym_user_instruction_token1] = aux_sym_user_instruction_token1,
  [anon_sym_COLON] = anon_sym_COLON,
  [aux_sym__user_name_or_group_token1] = aux_sym__user_name_or_group_token1,
  [aux_sym_workdir_instruction_token1] = aux_sym_workdir_instruction_token1,
  [aux_sym_arg_instruction_token1] = aux_sym_arg_instruction_token1,
  [aux_sym_arg_instruction_token2] = sym_unquoted_string,
  [anon_sym_EQ] = anon_sym_EQ,
  [aux_sym_onbuild_instruction_token1] = aux_sym_onbuild_instruction_token1,
  [aux_sym_stopsignal_instruction_token1] = aux_sym_stopsignal_instruction_token1,
  [aux_sym__stopsignal_value_token1] = aux_sym__stopsignal_value_token1,
  [aux_sym_healthcheck_instruction_token1] = aux_sym_healthcheck_instruction_token1,
  [anon_sym_NONE] = anon_sym_NONE,
  [aux_sym_shell_instruction_token1] = aux_sym_shell_instruction_token1,
  [aux_sym_maintainer_instruction_token1] = aux_sym_maintainer_instruction_token1,
  [aux_sym_maintainer_instruction_token2] = aux_sym_maintainer_instruction_token2,
  [aux_sym_cross_build_instruction_token1] = aux_sym_cross_build_instruction_token1,
  [aux_sym_path_token1] = aux_sym_path_token1,
  [aux_sym_path_token2] = aux_sym_path_token2,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [aux_sym_expansion_token1] = sym_variable,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_variable] = sym_variable,
  [aux_sym__spaced_env_pair_token1] = aux_sym__spaced_env_pair_token1,
  [aux_sym__env_key_token1] = sym_unquoted_string,
  [aux_sym_expose_port_token1] = aux_sym_expose_port_token1,
  [anon_sym_SLASHtcp] = anon_sym_SLASHtcp,
  [anon_sym_SLASHudp] = anon_sym_SLASHudp,
  [aux_sym_label_pair_token1] = sym_unquoted_string,
  [aux_sym_image_name_token1] = aux_sym_image_name_token1,
  [aux_sym_image_name_token2] = aux_sym_image_name_token2,
  [aux_sym_image_tag_token1] = aux_sym_image_tag_token1,
  [anon_sym_AT] = anon_sym_AT,
  [aux_sym_image_digest_token1] = aux_sym_image_digest_token1,
  [anon_sym_DASH_DASH] = anon_sym_DASH_DASH,
  [aux_sym_param_token1] = aux_sym_param_token1,
  [aux_sym_param_token2] = aux_sym_param_token2,
  [aux_sym_image_alias_token1] = aux_sym_image_alias_token1,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [aux_sym_shell_fragment_token1] = aux_sym_shell_fragment_token1,
  [aux_sym_shell_fragment_token2] = aux_sym_shell_fragment_token2,
  [anon_sym_BSLASH_LF] = anon_sym_BSLASH_LF,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_double_quoted_string_token1] = aux_sym_double_quoted_string_token1,
  [aux_sym_unquoted_string_token1] = aux_sym_unquoted_string_token1,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym__non_newline_whitespace] = sym__non_newline_whitespace,
  [sym_comment] = sym_comment,
  [sym_source_file] = sym_source_file,
  [sym__instruction] = sym__instruction,
  [sym_from_instruction] = sym_from_instruction,
  [sym_run_instruction] = sym_run_instruction,
  [sym_cmd_instruction] = sym_cmd_instruction,
  [sym_label_instruction] = sym_label_instruction,
  [sym_expose_instruction] = sym_expose_instruction,
  [sym_env_instruction] = sym_env_instruction,
  [sym_add_instruction] = sym_add_instruction,
  [sym_copy_instruction] = sym_copy_instruction,
  [sym_entrypoint_instruction] = sym_entrypoint_instruction,
  [sym_volume_instruction] = sym_volume_instruction,
  [sym_user_instruction] = sym_user_instruction,
  [aux_sym__user_name_or_group] = aux_sym__user_name_or_group,
  [sym_workdir_instruction] = sym_workdir_instruction,
  [sym_arg_instruction] = sym_arg_instruction,
  [sym_onbuild_instruction] = sym_onbuild_instruction,
  [sym_stopsignal_instruction] = sym_stopsignal_instruction,
  [aux_sym__stopsignal_value] = aux_sym__stopsignal_value,
  [sym_healthcheck_instruction] = sym_healthcheck_instruction,
  [sym_shell_instruction] = sym_shell_instruction,
  [sym_maintainer_instruction] = sym_maintainer_instruction,
  [sym_cross_build_instruction] = sym_cross_build_instruction,
  [sym_path] = sym_path,
  [sym_expansion] = sym_expansion,
  [sym_env_pair] = sym_env_pair,
  [sym__spaced_env_pair] = sym_env_pair,
  [sym__env_key] = sym__env_key,
  [sym_expose_port] = sym_expose_port,
  [sym_label_pair] = sym_label_pair,
  [sym_image_spec] = sym_image_spec,
  [sym_image_name] = sym_image_name,
  [sym_image_tag] = sym_image_tag,
  [sym_image_digest] = sym_image_digest,
  [sym_param] = sym_param,
  [sym_image_alias] = sym_image_alias,
  [sym_string_array] = sym_string_array,
  [sym_shell_command] = sym_shell_command,
  [sym_shell_fragment] = sym_shell_fragment,
  [sym_line_continuation] = sym_line_continuation,
  [sym_required_line_continuation] = sym_line_continuation,
  [sym__comment_line] = sym__comment_line,
  [sym__anon_comment] = sym_comment,
  [sym_double_quoted_string] = sym_double_quoted_string,
  [sym_unquoted_string] = sym_unquoted_string,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_label_instruction_repeat1] = aux_sym_label_instruction_repeat1,
  [aux_sym_expose_instruction_repeat1] = aux_sym_expose_instruction_repeat1,
  [aux_sym_env_instruction_repeat1] = aux_sym_env_instruction_repeat1,
  [aux_sym_add_instruction_repeat1] = aux_sym_add_instruction_repeat1,
  [aux_sym_volume_instruction_repeat1] = aux_sym_volume_instruction_repeat1,
  [aux_sym_healthcheck_instruction_repeat1] = aux_sym_healthcheck_instruction_repeat1,
  [aux_sym_path_repeat1] = aux_sym_path_repeat1,
  [aux_sym_image_name_repeat1] = aux_sym_image_name_repeat1,
  [aux_sym_image_tag_repeat1] = aux_sym_image_tag_repeat1,
  [aux_sym_image_digest_repeat1] = aux_sym_image_digest_repeat1,
  [aux_sym_image_alias_repeat1] = aux_sym_image_alias_repeat1,
  [aux_sym_string_array_repeat1] = aux_sym_string_array_repeat1,
  [aux_sym_shell_command_repeat1] = aux_sym_shell_command_repeat1,
  [aux_sym_shell_command_repeat2] = aux_sym_shell_command_repeat2,
  [aux_sym_shell_fragment_repeat1] = aux_sym_shell_fragment_repeat1,
  [aux_sym_double_quoted_string_repeat1] = aux_sym_double_quoted_string_repeat1,
  [aux_sym_unquoted_string_repeat1] = aux_sym_unquoted_string_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_from_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_from_instruction_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_run_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_cmd_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_label_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_expose_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_env_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_add_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_copy_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_entrypoint_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_volume_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_user_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__user_name_or_group_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_workdir_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_arg_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_arg_instruction_token2] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_onbuild_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_stopsignal_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__stopsignal_value_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_healthcheck_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NONE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_shell_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_maintainer_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_maintainer_instruction_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_cross_build_instruction_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_path_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_path_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_expansion_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_variable] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__spaced_env_pair_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__env_key_token1] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_expose_port_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASHtcp] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASHudp] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_label_pair_token1] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_image_name_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_image_name_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_image_tag_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_image_digest_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_param_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_param_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_image_alias_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_shell_fragment_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_shell_fragment_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BSLASH_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_double_quoted_string_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_unquoted_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym__non_newline_whitespace] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__instruction] = {
    .visible = false,
    .named = true,
  },
  [sym_from_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_run_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_cmd_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_label_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_expose_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_env_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_add_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_copy_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_entrypoint_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_volume_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_user_instruction] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__user_name_or_group] = {
    .visible = false,
    .named = false,
  },
  [sym_workdir_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_arg_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_onbuild_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_stopsignal_instruction] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__stopsignal_value] = {
    .visible = false,
    .named = false,
  },
  [sym_healthcheck_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_shell_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_maintainer_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_cross_build_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_path] = {
    .visible = true,
    .named = true,
  },
  [sym_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_env_pair] = {
    .visible = true,
    .named = true,
  },
  [sym__spaced_env_pair] = {
    .visible = true,
    .named = true,
  },
  [sym__env_key] = {
    .visible = false,
    .named = true,
  },
  [sym_expose_port] = {
    .visible = true,
    .named = true,
  },
  [sym_label_pair] = {
    .visible = true,
    .named = true,
  },
  [sym_image_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_image_name] = {
    .visible = true,
    .named = true,
  },
  [sym_image_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_image_digest] = {
    .visible = true,
    .named = true,
  },
  [sym_param] = {
    .visible = true,
    .named = true,
  },
  [sym_image_alias] = {
    .visible = true,
    .named = true,
  },
  [sym_string_array] = {
    .visible = true,
    .named = true,
  },
  [sym_shell_command] = {
    .visible = true,
    .named = true,
  },
  [sym_shell_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_line_continuation] = {
    .visible = true,
    .named = true,
  },
  [sym_required_line_continuation] = {
    .visible = true,
    .named = true,
  },
  [sym__comment_line] = {
    .visible = false,
    .named = true,
  },
  [sym__anon_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_double_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_unquoted_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_label_instruction_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_expose_instruction_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_env_instruction_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_add_instruction_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_volume_instruction_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_healthcheck_instruction_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_path_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_image_name_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_image_tag_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_image_digest_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_image_alias_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_array_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_shell_command_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_shell_command_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_shell_fragment_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_double_quoted_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_unquoted_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_as = 1,
  field_default = 2,
  field_digest = 3,
  field_group = 4,
  field_key = 5,
  field_name = 6,
  field_tag = 7,
  field_user = 8,
  field_value = 9,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_as] = "as",
  [field_default] = "default",
  [field_digest] = "digest",
  [field_group] = "group",
  [field_key] = "key",
  [field_name] = "name",
  [field_tag] = "tag",
  [field_user] = "user",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 4, .length = 1},
  [5] = {.index = 5, .length = 2},
  [6] = {.index = 7, .length = 2},
  [7] = {.index = 9, .length = 1},
  [8] = {.index = 10, .length = 3},
  [9] = {.index = 13, .length = 2},
  [10] = {.index = 15, .length = 2},
  [11] = {.index = 17, .length = 2},
  [12] = {.index = 19, .length = 2},
  [13] = {.index = 21, .length = 2},
  [14] = {.index = 23, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 0},
  [1] =
    {field_name, 1, .inherited = true},
    {field_value, 1, .inherited = true},
  [3] =
    {field_user, 1},
  [4] =
    {field_name, 1},
  [5] =
    {field_name, 0},
    {field_tag, 1},
  [7] =
    {field_digest, 1},
    {field_name, 0},
  [9] =
    {field_as, 3},
  [10] =
    {field_digest, 2},
    {field_name, 0},
    {field_tag, 1},
  [13] =
    {field_key, 0},
    {field_value, 2},
  [15] =
    {field_name, 0},
    {field_value, 2},
  [17] =
    {field_group, 3},
    {field_user, 1},
  [19] =
    {field_default, 3},
    {field_name, 1},
  [21] =
    {field_name, 1},
    {field_value, 3},
  [23] =
    {field_as, 4},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [3] = {
    [1] = sym_unquoted_string,
  },
  [11] = {
    [1] = sym_unquoted_string,
    [3] = sym_unquoted_string,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  aux_sym__user_name_or_group, 2,
    aux_sym__user_name_or_group,
    sym_unquoted_string,
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(159);
      if (lookahead == '"') ADVANCE(233);
      if (lookahead == '#') ADVANCE(232);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == ',') ADVANCE(226);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == ':') ADVANCE(175);
      if (lookahead == '=') ADVANCE(180);
      if (lookahead == '@') ADVANCE(217);
      if (lookahead == '[') ADVANCE(225);
      if (lookahead == '\\') ADVANCE(193);
      if (lookahead == ']') ADVANCE(227);
      if (lookahead == '{') ADVANCE(197);
      if (lookahead == '}') ADVANCE(201);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(156)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      if (lookahead != 0) ADVANCE(192);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(230);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(230);
      if (lookahead == ' ') ADVANCE(239);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(230);
      if (lookahead == 'U') ADVANCE(155);
      if (lookahead == 'u') ADVANCE(151);
      if (lookahead == 'x') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(242);
      if (lookahead != 0) ADVANCE(240);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(230);
      if (lookahead != 0) ADVANCE(229);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '"') ADVANCE(233);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '"') ADVANCE(233);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(236);
      if (lookahead != 0) ADVANCE(238);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '/') ADVANCE(58);
      if (lookahead == ':') ADVANCE(175);
      if (lookahead == '=') ADVANCE(180);
      if (lookahead == '@') ADVANCE(217);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(133);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(205);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '/') ADVANCE(58);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(133);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(205);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == ':') ADVANCE(175);
      if (lookahead == '@') ADVANCE(217);
      if (lookahead == '\\') ADVANCE(211);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(212);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(20)
      if (lookahead != 0) ADVANCE(213);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == ':') ADVANCE(175);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(16)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(183);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == ':') ADVANCE(175);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(18)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(205);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '@') ADVANCE(217);
      if (lookahead == '\\') ADVANCE(214);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(215);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      if (lookahead != 0) ADVANCE(216);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(218);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      if (('0' <= lookahead && lookahead <= ':') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 14:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(133);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      END_STATE();
    case 15:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 16:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(16)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(183);
      END_STATE();
    case 17:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 18:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(18)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(205);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      END_STATE();
    case 19:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(237);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(238);
      END_STATE();
    case 20:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(211);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(212);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(20)
      if (lookahead != 0 &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(213);
      END_STATE();
    case 21:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(194);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(21)
      if (lookahead != 0) ADVANCE(195);
      END_STATE();
    case 22:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(22)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 23:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(23)
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 24:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(24)
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '[') ADVANCE(228);
      END_STATE();
    case 25:
      if (lookahead == '\n') SKIP(27)
      if (lookahead == '"') ADVANCE(233);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(234);
      if (lookahead != 0) ADVANCE(235);
      END_STATE();
    case 26:
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead == '\r') SKIP(26)
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(194);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(243);
      if (lookahead != 0) ADVANCE(195);
      END_STATE();
    case 27:
      if (lookahead == '"') ADVANCE(233);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(27)
      END_STATE();
    case 28:
      if (lookahead == '"') ADVANCE(233);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(27)
      if (lookahead != 0) ADVANCE(238);
      END_STATE();
    case 29:
      if (lookahead == '#') ADVANCE(232);
      if (lookahead == '[') ADVANCE(225);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(29)
      if (lookahead != 0) ADVANCE(228);
      END_STATE();
    case 30:
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == '\\') ADVANCE(193);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(30)
      if (lookahead != 0) ADVANCE(192);
      END_STATE();
    case 31:
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == '\\') ADVANCE(210);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(31)
      if (lookahead != 0 &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(209);
      END_STATE();
    case 32:
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '[') ADVANCE(225);
      if (lookahead == '\\') ADVANCE(193);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(32)
      if (lookahead != 0 &&
          lookahead != '-') ADVANCE(192);
      END_STATE();
    case 33:
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(33)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 34:
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(34)
      END_STATE();
    case 35:
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(34)
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 36:
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(36)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(183);
      END_STATE();
    case 37:
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(214);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(34)
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(216);
      END_STATE();
    case 38:
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(194);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(244);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(38)
      if (lookahead != 0) ADVANCE(195);
      END_STATE();
    case 39:
      if (lookahead == '-') ADVANCE(220);
      END_STATE();
    case 40:
      if (lookahead == '=') ADVANCE(180);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(203);
      END_STATE();
    case 41:
      if (lookahead == 'E') ADVANCE(185);
      END_STATE();
    case 42:
      if (lookahead == 'N') ADVANCE(41);
      END_STATE();
    case 43:
      if (lookahead == 'O') ADVANCE(42);
      END_STATE();
    case 44:
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '{') ADVANCE(197);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(44)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      END_STATE();
    case 45:
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(45)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 46:
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(46)
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 47:
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(47)
      END_STATE();
    case 48:
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(47)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      END_STATE();
    case 49:
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(49)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(179);
      END_STATE();
    case 50:
      if (lookahead == '\\') ADVANCE(198);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(199);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(200);
      END_STATE();
    case 51:
      if (lookahead == '\\') ADVANCE(222);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(47)
      if (lookahead != 0) ADVANCE(223);
      END_STATE();
    case 52:
      if (lookahead == '_') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 53:
      if (lookahead == '_') ADVANCE(66);
      END_STATE();
    case 54:
      if (lookahead == 'c') ADVANCE(56);
      END_STATE();
    case 55:
      if (lookahead == 'd') ADVANCE(57);
      END_STATE();
    case 56:
      if (lookahead == 'p') ADVANCE(206);
      END_STATE();
    case 57:
      if (lookahead == 'p') ADVANCE(207);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(54);
      if (lookahead == 'u') ADVANCE(55);
      END_STATE();
    case 59:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(65);
      END_STATE();
    case 60:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(89);
      END_STATE();
    case 61:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(97);
      END_STATE();
    case 62:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(100);
      END_STATE();
    case 63:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(90);
      END_STATE();
    case 64:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(143);
      END_STATE();
    case 65:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(81);
      END_STATE();
    case 66:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(145);
      END_STATE();
    case 67:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(95);
      END_STATE();
    case 68:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(87);
      END_STATE();
    case 69:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(70);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(83);
      END_STATE();
    case 70:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(170);
      END_STATE();
    case 71:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(166);
      END_STATE();
    case 72:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(181);
      END_STATE();
    case 73:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(191);
      END_STATE();
    case 74:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(91);
      END_STATE();
    case 75:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(168);
      END_STATE();
    case 76:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(173);
      END_STATE();
    case 77:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 78:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(61);
      END_STATE();
    case 79:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(104);
      END_STATE();
    case 80:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(127);
      END_STATE();
    case 81:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(98);
      END_STATE();
    case 82:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(129);
      END_STATE();
    case 83:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(178);
      END_STATE();
    case 84:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(113);
      END_STATE();
    case 85:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(68);
      END_STATE();
    case 86:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(79);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(119);
      END_STATE();
    case 87:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(77);
      END_STATE();
    case 88:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(84);
      END_STATE();
    case 89:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(111);
      END_STATE();
    case 90:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(114);
      END_STATE();
    case 91:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(128);
      END_STATE();
    case 92:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(112);
      END_STATE();
    case 93:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(102);
      END_STATE();
    case 94:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(103);
      END_STATE();
    case 95:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(184);
      END_STATE();
    case 96:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(74);
      END_STATE();
    case 97:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(138);
      END_STATE();
    case 98:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(167);
      END_STATE();
    case 99:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(186);
      END_STATE();
    case 100:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(182);
      END_STATE();
    case 101:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(144);
      END_STATE();
    case 102:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(72);
      END_STATE();
    case 103:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(73);
      END_STATE();
    case 104:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(99);
      END_STATE();
    case 105:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(162);
      END_STATE();
    case 106:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(71);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(122);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(118);
      END_STATE();
    case 107:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(76);
      END_STATE();
    case 108:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(140);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(124);
      END_STATE();
    case 109:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(165);
      END_STATE();
    case 110:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(64);
      END_STATE();
    case 111:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(141);
      END_STATE();
    case 112:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(139);
      END_STATE();
    case 113:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(62);
      END_STATE();
    case 114:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(82);
      END_STATE();
    case 115:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(101);
      END_STATE();
    case 116:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(105);
      END_STATE();
    case 117:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(126);
      END_STATE();
    case 118:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(135);
      END_STATE();
    case 119:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(123);
      END_STATE();
    case 120:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(137);
      END_STATE();
    case 121:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(92);
      END_STATE();
    case 122:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(146);
      END_STATE();
    case 123:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(136);
      END_STATE();
    case 124:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(120);
      END_STATE();
    case 125:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(121);
      END_STATE();
    case 126:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(96);
      END_STATE();
    case 127:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(174);
      END_STATE();
    case 128:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(177);
      END_STATE();
    case 129:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(187);
      END_STATE();
    case 130:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(147);
      END_STATE();
    case 131:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(116);
      END_STATE();
    case 132:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(53);
      END_STATE();
    case 133:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(163);
      END_STATE();
    case 134:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(80);
      END_STATE();
    case 135:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(132);
      END_STATE();
    case 136:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(88);
      END_STATE();
    case 137:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(75);
      END_STATE();
    case 138:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(85);
      END_STATE();
    case 139:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(172);
      END_STATE();
    case 140:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(130);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(169);
      END_STATE();
    case 141:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(63);
      END_STATE();
    case 142:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(109);
      END_STATE();
    case 143:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(93);
      END_STATE();
    case 144:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(107);
      END_STATE();
    case 145:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(94);
      END_STATE();
    case 146:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(171);
      END_STATE();
    case 147:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(125);
      END_STATE();
    case 148:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(240);
      END_STATE();
    case 149:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(148);
      END_STATE();
    case 150:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(149);
      END_STATE();
    case 151:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(150);
      END_STATE();
    case 152:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(151);
      END_STATE();
    case 153:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(152);
      END_STATE();
    case 154:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(153);
      END_STATE();
    case 155:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(154);
      END_STATE();
    case 156:
      if (eof) ADVANCE(159);
      if (lookahead == '"') ADVANCE(233);
      if (lookahead == '#') ADVANCE(232);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == ',') ADVANCE(226);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == '[') ADVANCE(225);
      if (lookahead == '\\') ADVANCE(193);
      if (lookahead == ']') ADVANCE(227);
      if (lookahead == '{') ADVANCE(197);
      if (lookahead == '}') ADVANCE(201);
      if (lookahead == ':' ||
          lookahead == '@') ADVANCE(192);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(156)
      if (lookahead != 0) ADVANCE(192);
      END_STATE();
    case 157:
      if (eof) ADVANCE(159);
      if (lookahead == '"') ADVANCE(233);
      if (lookahead == '#') ADVANCE(245);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == ',') ADVANCE(226);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == '=') ADVANCE(180);
      if (lookahead == 'N') ADVANCE(43);
      if (lookahead == '[') ADVANCE(225);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == ']') ADVANCE(227);
      if (lookahead == '}') ADVANCE(201);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(69);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(106);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(108);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(131);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(78);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(59);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(60);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(110);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(142);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(86);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(134);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(115);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(158)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(205);
      END_STATE();
    case 158:
      if (eof) ADVANCE(159);
      if (lookahead == '"') ADVANCE(233);
      if (lookahead == '#') ADVANCE(245);
      if (lookahead == '$') ADVANCE(196);
      if (lookahead == ',') ADVANCE(226);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == 'N') ADVANCE(43);
      if (lookahead == '[') ADVANCE(225);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == ']') ADVANCE(227);
      if (lookahead == '}') ADVANCE(201);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(69);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(106);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(108);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(131);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(78);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(59);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(60);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(110);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(142);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(86);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(134);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(115);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(158)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(205);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(160);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(243);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_from_instruction_token1);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_from_instruction_token2);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_from_instruction_token2);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(213);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_run_instruction_token1);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_cmd_instruction_token1);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_label_instruction_token1);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_expose_instruction_token1);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_env_instruction_token1);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_add_instruction_token1);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_copy_instruction_token1);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_entrypoint_instruction_token1);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_volume_instruction_token1);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_user_instruction_token1);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym__user_name_or_group_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_workdir_instruction_token1);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_arg_instruction_token1);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_arg_instruction_token2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(179);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_onbuild_instruction_token1);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_stopsignal_instruction_token1);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym__stopsignal_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(183);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_healthcheck_instruction_token1);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_NONE);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_shell_instruction_token1);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token1);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token2);
      if (lookahead == '\n') ADVANCE(230);
      if (lookahead != 0) ADVANCE(190);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token2);
      if (lookahead == '\\') ADVANCE(188);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(189);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(190);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(190);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_cross_build_instruction_token1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(191);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_path_token1);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_path_token1);
      if (lookahead == '\n') ADVANCE(230);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_path_token2);
      if (lookahead == '\n') ADVANCE(230);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$') ADVANCE(195);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_path_token2);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$') ADVANCE(195);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_expansion_token1);
      if (lookahead == '\n') ADVANCE(231);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(200);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_expansion_token1);
      if (lookahead == '\\') ADVANCE(198);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(199);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(200);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_expansion_token1);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(200);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_variable);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym__spaced_env_pair_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(203);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym__env_key_token1);
      if (lookahead == '_') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(204);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_expose_port_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(205);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_SLASHtcp);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_SLASHudp);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_label_pair_token1);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(208);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_image_name_token1);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_image_name_token1);
      if (lookahead == '\n') ADVANCE(230);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_image_name_token2);
      if (lookahead == '\n') ADVANCE(230);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(213);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_image_name_token2);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(164);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(213);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_image_name_token2);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(213);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_image_tag_token1);
      if (lookahead == '\n') ADVANCE(230);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != '@') ADVANCE(216);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_image_tag_token1);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(216);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != '@') ADVANCE(216);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_image_tag_token1);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != '@') ADVANCE(216);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_image_digest_token1);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(219);
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_image_digest_token1);
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_param_token1);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_param_token2);
      if (lookahead == '\n') ADVANCE(230);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(223);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym_param_token2);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(223);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(aux_sym_image_alias_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_shell_fragment_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\\') ADVANCE(228);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_shell_fragment_token2);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_BSLASH_LF);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(anon_sym_BSLASH_LF);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(200);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(234);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(235);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(235);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(aux_sym_unquoted_string_token1);
      if (lookahead == '_') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(236);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(238);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(aux_sym_unquoted_string_token1);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(237);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(238);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(aux_sym_unquoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(238);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(240);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(241);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym__non_newline_whitespace);
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(243);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym__non_newline_whitespace);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(244);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(245);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 157},
  [2] = {.lex_state = 157},
  [3] = {.lex_state = 157},
  [4] = {.lex_state = 157},
  [5] = {.lex_state = 157},
  [6] = {.lex_state = 29},
  [7] = {.lex_state = 29},
  [8] = {.lex_state = 29},
  [9] = {.lex_state = 6},
  [10] = {.lex_state = 9},
  [11] = {.lex_state = 9},
  [12] = {.lex_state = 29},
  [13] = {.lex_state = 29},
  [14] = {.lex_state = 28},
  [15] = {.lex_state = 28},
  [16] = {.lex_state = 29},
  [17] = {.lex_state = 9},
  [18] = {.lex_state = 28},
  [19] = {.lex_state = 19},
  [20] = {.lex_state = 19},
  [21] = {.lex_state = 6},
  [22] = {.lex_state = 31},
  [23] = {.lex_state = 12},
  [24] = {.lex_state = 12},
  [25] = {.lex_state = 6},
  [26] = {.lex_state = 30},
  [27] = {.lex_state = 30},
  [28] = {.lex_state = 32},
  [29] = {.lex_state = 25},
  [30] = {.lex_state = 7},
  [31] = {.lex_state = 25},
  [32] = {.lex_state = 26},
  [33] = {.lex_state = 7},
  [34] = {.lex_state = 157},
  [35] = {.lex_state = 29},
  [36] = {.lex_state = 25},
  [37] = {.lex_state = 26},
  [38] = {.lex_state = 25},
  [39] = {.lex_state = 25},
  [40] = {.lex_state = 26},
  [41] = {.lex_state = 9},
  [42] = {.lex_state = 9},
  [43] = {.lex_state = 9},
  [44] = {.lex_state = 10},
  [45] = {.lex_state = 25},
  [46] = {.lex_state = 7},
  [47] = {.lex_state = 13},
  [48] = {.lex_state = 13},
  [49] = {.lex_state = 25},
  [50] = {.lex_state = 10},
  [51] = {.lex_state = 22},
  [52] = {.lex_state = 38},
  [53] = {.lex_state = 157},
  [54] = {.lex_state = 10},
  [55] = {.lex_state = 22},
  [56] = {.lex_state = 38},
  [57] = {.lex_state = 30},
  [58] = {.lex_state = 30},
  [59] = {.lex_state = 30},
  [60] = {.lex_state = 30},
  [61] = {.lex_state = 30},
  [62] = {.lex_state = 45},
  [63] = {.lex_state = 17},
  [64] = {.lex_state = 21},
  [65] = {.lex_state = 30},
  [66] = {.lex_state = 21},
  [67] = {.lex_state = 30},
  [68] = {.lex_state = 10},
  [69] = {.lex_state = 10},
  [70] = {.lex_state = 17},
  [71] = {.lex_state = 21},
  [72] = {.lex_state = 157},
  [73] = {.lex_state = 11},
  [74] = {.lex_state = 38},
  [75] = {.lex_state = 19},
  [76] = {.lex_state = 31},
  [77] = {.lex_state = 7},
  [78] = {.lex_state = 12},
  [79] = {.lex_state = 6},
  [80] = {.lex_state = 6},
  [81] = {.lex_state = 33},
  [82] = {.lex_state = 19},
  [83] = {.lex_state = 11},
  [84] = {.lex_state = 33},
  [85] = {.lex_state = 6},
  [86] = {.lex_state = 12},
  [87] = {.lex_state = 19},
  [88] = {.lex_state = 12},
  [89] = {.lex_state = 37},
  [90] = {.lex_state = 24},
  [91] = {.lex_state = 13},
  [92] = {.lex_state = 26},
  [93] = {.lex_state = 35},
  [94] = {.lex_state = 7},
  [95] = {.lex_state = 25},
  [96] = {.lex_state = 26},
  [97] = {.lex_state = 24},
  [98] = {.lex_state = 23},
  [99] = {.lex_state = 157},
  [100] = {.lex_state = 13},
  [101] = {.lex_state = 23},
  [102] = {.lex_state = 13},
  [103] = {.lex_state = 36},
  [104] = {.lex_state = 30},
  [105] = {.lex_state = 36},
  [106] = {.lex_state = 10},
  [107] = {.lex_state = 30},
  [108] = {.lex_state = 36},
  [109] = {.lex_state = 25},
  [110] = {.lex_state = 25},
  [111] = {.lex_state = 26},
  [112] = {.lex_state = 46},
  [113] = {.lex_state = 26},
  [114] = {.lex_state = 157},
  [115] = {.lex_state = 6},
  [116] = {.lex_state = 7},
  [117] = {.lex_state = 38},
  [118] = {.lex_state = 157},
  [119] = {.lex_state = 21},
  [120] = {.lex_state = 17},
  [121] = {.lex_state = 29},
  [122] = {.lex_state = 6},
  [123] = {.lex_state = 29},
  [124] = {.lex_state = 6},
  [125] = {.lex_state = 29},
  [126] = {.lex_state = 157},
  [127] = {.lex_state = 17},
  [128] = {.lex_state = 17},
  [129] = {.lex_state = 157},
  [130] = {.lex_state = 10},
  [131] = {.lex_state = 6},
  [132] = {.lex_state = 6},
  [133] = {.lex_state = 7},
  [134] = {.lex_state = 10},
  [135] = {.lex_state = 21},
  [136] = {.lex_state = 26},
  [137] = {.lex_state = 38},
  [138] = {.lex_state = 10},
  [139] = {.lex_state = 21},
  [140] = {.lex_state = 26},
  [141] = {.lex_state = 38},
  [142] = {.lex_state = 7},
  [143] = {.lex_state = 44},
  [144] = {.lex_state = 44},
  [145] = {.lex_state = 23},
  [146] = {.lex_state = 157},
  [147] = {.lex_state = 22},
  [148] = {.lex_state = 44},
  [149] = {.lex_state = 26},
  [150] = {.lex_state = 26},
  [151] = {.lex_state = 26},
  [152] = {.lex_state = 26},
  [153] = {.lex_state = 44},
  [154] = {.lex_state = 157},
  [155] = {.lex_state = 44},
  [156] = {.lex_state = 44},
  [157] = {.lex_state = 31},
  [158] = {.lex_state = 26},
  [159] = {.lex_state = 7},
  [160] = {.lex_state = 44},
  [161] = {.lex_state = 44},
  [162] = {.lex_state = 157},
  [163] = {.lex_state = 44},
  [164] = {.lex_state = 157},
  [165] = {.lex_state = 157},
  [166] = {.lex_state = 44},
  [167] = {.lex_state = 44},
  [168] = {.lex_state = 30},
  [169] = {.lex_state = 44},
  [170] = {.lex_state = 7},
  [171] = {.lex_state = 23},
  [172] = {.lex_state = 40},
  [173] = {.lex_state = 7},
  [174] = {.lex_state = 23},
  [175] = {.lex_state = 7},
  [176] = {.lex_state = 22},
  [177] = {.lex_state = 40},
  [178] = {.lex_state = 22},
  [179] = {.lex_state = 30},
  [180] = {.lex_state = 23},
  [181] = {.lex_state = 157},
  [182] = {.lex_state = 22},
  [183] = {.lex_state = 157},
  [184] = {.lex_state = 6},
  [185] = {.lex_state = 6},
  [186] = {.lex_state = 6},
  [187] = {.lex_state = 6},
  [188] = {.lex_state = 6},
  [189] = {.lex_state = 6},
  [190] = {.lex_state = 6},
  [191] = {.lex_state = 6},
  [192] = {.lex_state = 38},
  [193] = {.lex_state = 50},
  [194] = {.lex_state = 6},
  [195] = {.lex_state = 157},
  [196] = {.lex_state = 6},
  [197] = {.lex_state = 6},
  [198] = {.lex_state = 157},
  [199] = {.lex_state = 6},
  [200] = {.lex_state = 6},
  [201] = {.lex_state = 6},
  [202] = {.lex_state = 189},
  [203] = {.lex_state = 157},
  [204] = {.lex_state = 48},
  [205] = {.lex_state = 157},
  [206] = {.lex_state = 6},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 6},
  [209] = {.lex_state = 6},
  [210] = {.lex_state = 189},
  [211] = {.lex_state = 157},
  [212] = {.lex_state = 51},
  [213] = {.lex_state = 189},
  [214] = {.lex_state = 6},
  [215] = {.lex_state = 157},
  [216] = {.lex_state = 51},
  [217] = {.lex_state = 49},
  [218] = {.lex_state = 6},
  [219] = {.lex_state = 157},
  [220] = {.lex_state = 6},
  [221] = {.lex_state = 157},
  [222] = {.lex_state = 51},
  [223] = {.lex_state = 157},
  [224] = {.lex_state = 6},
  [225] = {.lex_state = 157},
  [226] = {.lex_state = 6},
  [227] = {.lex_state = 157},
  [228] = {.lex_state = 6},
  [229] = {.lex_state = 157},
  [230] = {.lex_state = 157},
  [231] = {.lex_state = 157},
  [232] = {.lex_state = 6},
  [233] = {.lex_state = 157},
  [234] = {.lex_state = 6},
  [235] = {.lex_state = 157},
  [236] = {.lex_state = 50},
  [237] = {.lex_state = 157},
  [238] = {.lex_state = 50},
  [239] = {.lex_state = 157},
  [240] = {.lex_state = 50},
  [241] = {.lex_state = 50},
  [242] = {.lex_state = 50},
  [243] = {.lex_state = 50},
  [244] = {.lex_state = 50},
  [245] = {.lex_state = 50},
  [246] = {.lex_state = 50},
  [247] = {.lex_state = 50},
  [248] = {.lex_state = 50},
  [249] = {.lex_state = 48},
  [250] = {.lex_state = 48},
  [251] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_line_continuation] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [aux_sym_path_token1] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [aux_sym_image_name_token1] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [aux_sym_param_token1] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_BSLASH_LF] = ACTIONS(3),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(207),
    [sym__instruction] = STATE(208),
    [sym_from_instruction] = STATE(206),
    [sym_run_instruction] = STATE(206),
    [sym_cmd_instruction] = STATE(206),
    [sym_label_instruction] = STATE(206),
    [sym_expose_instruction] = STATE(206),
    [sym_env_instruction] = STATE(206),
    [sym_add_instruction] = STATE(206),
    [sym_copy_instruction] = STATE(206),
    [sym_entrypoint_instruction] = STATE(206),
    [sym_volume_instruction] = STATE(206),
    [sym_user_instruction] = STATE(206),
    [sym_workdir_instruction] = STATE(206),
    [sym_arg_instruction] = STATE(206),
    [sym_onbuild_instruction] = STATE(206),
    [sym_stopsignal_instruction] = STATE(206),
    [sym_healthcheck_instruction] = STATE(206),
    [sym_shell_instruction] = STATE(206),
    [sym_maintainer_instruction] = STATE(206),
    [sym_cross_build_instruction] = STATE(206),
    [sym_line_continuation] = STATE(1),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [aux_sym_from_instruction_token1] = ACTIONS(7),
    [aux_sym_run_instruction_token1] = ACTIONS(9),
    [aux_sym_cmd_instruction_token1] = ACTIONS(11),
    [aux_sym_label_instruction_token1] = ACTIONS(13),
    [aux_sym_expose_instruction_token1] = ACTIONS(15),
    [aux_sym_env_instruction_token1] = ACTIONS(17),
    [aux_sym_add_instruction_token1] = ACTIONS(19),
    [aux_sym_copy_instruction_token1] = ACTIONS(21),
    [aux_sym_entrypoint_instruction_token1] = ACTIONS(23),
    [aux_sym_volume_instruction_token1] = ACTIONS(25),
    [aux_sym_user_instruction_token1] = ACTIONS(27),
    [aux_sym_workdir_instruction_token1] = ACTIONS(29),
    [aux_sym_arg_instruction_token1] = ACTIONS(31),
    [aux_sym_onbuild_instruction_token1] = ACTIONS(33),
    [aux_sym_stopsignal_instruction_token1] = ACTIONS(35),
    [aux_sym_healthcheck_instruction_token1] = ACTIONS(37),
    [aux_sym_shell_instruction_token1] = ACTIONS(39),
    [aux_sym_maintainer_instruction_token1] = ACTIONS(41),
    [aux_sym_cross_build_instruction_token1] = ACTIONS(43),
    [anon_sym_BSLASH_LF] = ACTIONS(3),
    [sym_comment] = ACTIONS(45),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 25,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(47), 1,
      ts_builtin_sym_end,
    ACTIONS(49), 1,
      aux_sym_from_instruction_token1,
    ACTIONS(52), 1,
      aux_sym_run_instruction_token1,
    ACTIONS(55), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(58), 1,
      aux_sym_label_instruction_token1,
    ACTIONS(61), 1,
      aux_sym_expose_instruction_token1,
    ACTIONS(64), 1,
      aux_sym_env_instruction_token1,
    ACTIONS(67), 1,
      aux_sym_add_instruction_token1,
    ACTIONS(70), 1,
      aux_sym_copy_instruction_token1,
    ACTIONS(73), 1,
      aux_sym_entrypoint_instruction_token1,
    ACTIONS(76), 1,
      aux_sym_volume_instruction_token1,
    ACTIONS(79), 1,
      aux_sym_user_instruction_token1,
    ACTIONS(82), 1,
      aux_sym_workdir_instruction_token1,
    ACTIONS(85), 1,
      aux_sym_arg_instruction_token1,
    ACTIONS(88), 1,
      aux_sym_onbuild_instruction_token1,
    ACTIONS(91), 1,
      aux_sym_stopsignal_instruction_token1,
    ACTIONS(94), 1,
      aux_sym_healthcheck_instruction_token1,
    ACTIONS(97), 1,
      aux_sym_shell_instruction_token1,
    ACTIONS(100), 1,
      aux_sym_maintainer_instruction_token1,
    ACTIONS(103), 1,
      aux_sym_cross_build_instruction_token1,
    ACTIONS(106), 1,
      sym_comment,
    STATE(208), 1,
      sym__instruction,
    STATE(2), 2,
      sym_line_continuation,
      aux_sym_source_file_repeat1,
    STATE(206), 19,
      sym_from_instruction,
      sym_run_instruction,
      sym_cmd_instruction,
      sym_label_instruction,
      sym_expose_instruction,
      sym_env_instruction,
      sym_add_instruction,
      sym_copy_instruction,
      sym_entrypoint_instruction,
      sym_volume_instruction,
      sym_user_instruction,
      sym_workdir_instruction,
      sym_arg_instruction,
      sym_onbuild_instruction,
      sym_stopsignal_instruction,
      sym_healthcheck_instruction,
      sym_shell_instruction,
      sym_maintainer_instruction,
      sym_cross_build_instruction,
  [95] = 26,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(7), 1,
      aux_sym_from_instruction_token1,
    ACTIONS(9), 1,
      aux_sym_run_instruction_token1,
    ACTIONS(11), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(13), 1,
      aux_sym_label_instruction_token1,
    ACTIONS(15), 1,
      aux_sym_expose_instruction_token1,
    ACTIONS(17), 1,
      aux_sym_env_instruction_token1,
    ACTIONS(19), 1,
      aux_sym_add_instruction_token1,
    ACTIONS(21), 1,
      aux_sym_copy_instruction_token1,
    ACTIONS(23), 1,
      aux_sym_entrypoint_instruction_token1,
    ACTIONS(25), 1,
      aux_sym_volume_instruction_token1,
    ACTIONS(27), 1,
      aux_sym_user_instruction_token1,
    ACTIONS(29), 1,
      aux_sym_workdir_instruction_token1,
    ACTIONS(31), 1,
      aux_sym_arg_instruction_token1,
    ACTIONS(33), 1,
      aux_sym_onbuild_instruction_token1,
    ACTIONS(35), 1,
      aux_sym_stopsignal_instruction_token1,
    ACTIONS(37), 1,
      aux_sym_healthcheck_instruction_token1,
    ACTIONS(39), 1,
      aux_sym_shell_instruction_token1,
    ACTIONS(41), 1,
      aux_sym_maintainer_instruction_token1,
    ACTIONS(43), 1,
      aux_sym_cross_build_instruction_token1,
    ACTIONS(45), 1,
      sym_comment,
    ACTIONS(109), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      aux_sym_source_file_repeat1,
    STATE(3), 1,
      sym_line_continuation,
    STATE(208), 1,
      sym__instruction,
    STATE(206), 19,
      sym_from_instruction,
      sym_run_instruction,
      sym_cmd_instruction,
      sym_label_instruction,
      sym_expose_instruction,
      sym_env_instruction,
      sym_add_instruction,
      sym_copy_instruction,
      sym_entrypoint_instruction,
      sym_volume_instruction,
      sym_user_instruction,
      sym_workdir_instruction,
      sym_arg_instruction,
      sym_onbuild_instruction,
      sym_stopsignal_instruction,
      sym_healthcheck_instruction,
      sym_shell_instruction,
      sym_maintainer_instruction,
      sym_cross_build_instruction,
  [192] = 23,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(7), 1,
      aux_sym_from_instruction_token1,
    ACTIONS(9), 1,
      aux_sym_run_instruction_token1,
    ACTIONS(11), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(13), 1,
      aux_sym_label_instruction_token1,
    ACTIONS(15), 1,
      aux_sym_expose_instruction_token1,
    ACTIONS(17), 1,
      aux_sym_env_instruction_token1,
    ACTIONS(19), 1,
      aux_sym_add_instruction_token1,
    ACTIONS(21), 1,
      aux_sym_copy_instruction_token1,
    ACTIONS(23), 1,
      aux_sym_entrypoint_instruction_token1,
    ACTIONS(25), 1,
      aux_sym_volume_instruction_token1,
    ACTIONS(27), 1,
      aux_sym_user_instruction_token1,
    ACTIONS(29), 1,
      aux_sym_workdir_instruction_token1,
    ACTIONS(31), 1,
      aux_sym_arg_instruction_token1,
    ACTIONS(33), 1,
      aux_sym_onbuild_instruction_token1,
    ACTIONS(35), 1,
      aux_sym_stopsignal_instruction_token1,
    ACTIONS(37), 1,
      aux_sym_healthcheck_instruction_token1,
    ACTIONS(39), 1,
      aux_sym_shell_instruction_token1,
    ACTIONS(41), 1,
      aux_sym_maintainer_instruction_token1,
    ACTIONS(43), 1,
      aux_sym_cross_build_instruction_token1,
    STATE(4), 1,
      sym_line_continuation,
    STATE(185), 1,
      sym__instruction,
    STATE(206), 19,
      sym_from_instruction,
      sym_run_instruction,
      sym_cmd_instruction,
      sym_label_instruction,
      sym_expose_instruction,
      sym_env_instruction,
      sym_add_instruction,
      sym_copy_instruction,
      sym_entrypoint_instruction,
      sym_volume_instruction,
      sym_user_instruction,
      sym_workdir_instruction,
      sym_arg_instruction,
      sym_onbuild_instruction,
      sym_stopsignal_instruction,
      sym_healthcheck_instruction,
      sym_shell_instruction,
      sym_maintainer_instruction,
      sym_cross_build_instruction,
  [280] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    STATE(5), 1,
      sym_line_continuation,
    ACTIONS(47), 21,
      ts_builtin_sym_end,
      aux_sym_from_instruction_token1,
      aux_sym_run_instruction_token1,
      aux_sym_cmd_instruction_token1,
      aux_sym_label_instruction_token1,
      aux_sym_expose_instruction_token1,
      aux_sym_env_instruction_token1,
      aux_sym_add_instruction_token1,
      aux_sym_copy_instruction_token1,
      aux_sym_entrypoint_instruction_token1,
      aux_sym_volume_instruction_token1,
      aux_sym_user_instruction_token1,
      aux_sym_workdir_instruction_token1,
      aux_sym_arg_instruction_token1,
      aux_sym_onbuild_instruction_token1,
      aux_sym_stopsignal_instruction_token1,
      aux_sym_healthcheck_instruction_token1,
      aux_sym_shell_instruction_token1,
      aux_sym_maintainer_instruction_token1,
      aux_sym_cross_build_instruction_token1,
      sym_comment,
  [310] = 11,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(111), 1,
      anon_sym_LBRACK,
    ACTIONS(115), 1,
      anon_sym_POUND,
    STATE(6), 1,
      sym_line_continuation,
    STATE(12), 1,
      aux_sym_shell_command_repeat1,
    STATE(90), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(115), 1,
      sym_shell_fragment,
    STATE(121), 1,
      sym__comment_line,
    STATE(200), 1,
      sym__anon_comment,
    ACTIONS(113), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(201), 2,
      sym_string_array,
      sym_shell_command,
  [346] = 11,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(111), 1,
      anon_sym_LBRACK,
    ACTIONS(115), 1,
      anon_sym_POUND,
    STATE(7), 1,
      sym_line_continuation,
    STATE(12), 1,
      aux_sym_shell_command_repeat1,
    STATE(90), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(115), 1,
      sym_shell_fragment,
    STATE(121), 1,
      sym__comment_line,
    STATE(200), 1,
      sym__anon_comment,
    ACTIONS(113), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(199), 2,
      sym_string_array,
      sym_shell_command,
  [382] = 11,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(111), 1,
      anon_sym_LBRACK,
    ACTIONS(115), 1,
      anon_sym_POUND,
    STATE(8), 1,
      sym_line_continuation,
    STATE(12), 1,
      aux_sym_shell_command_repeat1,
    STATE(90), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(115), 1,
      sym_shell_fragment,
    STATE(121), 1,
      sym__comment_line,
    STATE(200), 1,
      sym__anon_comment,
    ACTIONS(113), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(191), 2,
      sym_string_array,
      sym_shell_command,
  [418] = 10,
    ACTIONS(117), 1,
      anon_sym_LF,
    ACTIONS(119), 1,
      anon_sym_DOLLAR,
    ACTIONS(121), 1,
      aux_sym__env_key_token1,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(125), 1,
      anon_sym_DQUOTE,
    STATE(9), 1,
      sym_line_continuation,
    STATE(25), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(80), 1,
      sym_expansion,
    ACTIONS(127), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
    STATE(147), 2,
      sym_double_quoted_string,
      sym_unquoted_string,
  [451] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(131), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(133), 1,
      anon_sym_DOLLAR,
    ACTIONS(136), 1,
      aux_sym_image_name_token2,
    STATE(42), 1,
      sym_expansion,
    STATE(10), 2,
      sym_line_continuation,
      aux_sym_image_name_repeat1,
    ACTIONS(129), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
  [476] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(141), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(143), 1,
      anon_sym_DOLLAR,
    ACTIONS(145), 1,
      aux_sym_image_name_token2,
    STATE(10), 1,
      aux_sym_image_name_repeat1,
    STATE(11), 1,
      sym_line_continuation,
    STATE(42), 1,
      sym_expansion,
    ACTIONS(139), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
  [503] = 9,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(115), 1,
      anon_sym_POUND,
    STATE(12), 1,
      sym_line_continuation,
    STATE(35), 1,
      aux_sym_shell_command_repeat1,
    STATE(90), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(121), 1,
      sym__comment_line,
    STATE(122), 1,
      sym_shell_fragment,
    STATE(200), 1,
      sym__anon_comment,
    ACTIONS(113), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
  [532] = 9,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(115), 1,
      anon_sym_POUND,
    STATE(13), 1,
      sym_line_continuation,
    STATE(16), 1,
      aux_sym_shell_command_repeat1,
    STATE(90), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(121), 1,
      sym__comment_line,
    STATE(200), 1,
      sym__anon_comment,
    STATE(224), 1,
      sym_shell_fragment,
    ACTIONS(113), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
  [561] = 8,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(147), 1,
      anon_sym_DOLLAR,
    ACTIONS(149), 1,
      anon_sym_DQUOTE,
    STATE(14), 1,
      sym_line_continuation,
    STATE(19), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(75), 1,
      sym_expansion,
    ACTIONS(151), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
    STATE(145), 2,
      sym_double_quoted_string,
      sym_unquoted_string,
  [588] = 8,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(147), 1,
      anon_sym_DOLLAR,
    ACTIONS(149), 1,
      anon_sym_DQUOTE,
    STATE(15), 1,
      sym_line_continuation,
    STATE(19), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(75), 1,
      sym_expansion,
    ACTIONS(151), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
    STATE(232), 2,
      sym_double_quoted_string,
      sym_unquoted_string,
  [615] = 9,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(115), 1,
      anon_sym_POUND,
    STATE(16), 1,
      sym_line_continuation,
    STATE(35), 1,
      aux_sym_shell_command_repeat1,
    STATE(90), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(121), 1,
      sym__comment_line,
    STATE(200), 1,
      sym__anon_comment,
    STATE(209), 1,
      sym_shell_fragment,
    ACTIONS(113), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
  [644] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(143), 1,
      anon_sym_DOLLAR,
    ACTIONS(145), 1,
      aux_sym_image_name_token2,
    ACTIONS(155), 1,
      aux_sym_from_instruction_token2,
    STATE(11), 1,
      aux_sym_image_name_repeat1,
    STATE(17), 1,
      sym_line_continuation,
    STATE(42), 1,
      sym_expansion,
    ACTIONS(153), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
  [671] = 8,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(147), 1,
      anon_sym_DOLLAR,
    ACTIONS(149), 1,
      anon_sym_DQUOTE,
    STATE(18), 1,
      sym_line_continuation,
    STATE(19), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(75), 1,
      sym_expansion,
    ACTIONS(151), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
    STATE(228), 2,
      sym_double_quoted_string,
      sym_unquoted_string,
  [698] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(157), 1,
      anon_sym_LF,
    ACTIONS(159), 1,
      anon_sym_DOLLAR,
    ACTIONS(161), 1,
      aux_sym_label_pair_token1,
    STATE(19), 1,
      sym_line_continuation,
    STATE(20), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(75), 1,
      sym_expansion,
    ACTIONS(151), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
  [724] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(163), 1,
      anon_sym_LF,
    ACTIONS(165), 1,
      anon_sym_DOLLAR,
    ACTIONS(168), 1,
      aux_sym_label_pair_token1,
    STATE(75), 1,
      sym_expansion,
    ACTIONS(170), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
    STATE(20), 2,
      sym_line_continuation,
      aux_sym_unquoted_string_repeat1,
  [748] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(163), 1,
      anon_sym_LF,
    ACTIONS(168), 1,
      aux_sym__env_key_token1,
    ACTIONS(173), 1,
      anon_sym_DOLLAR,
    STATE(80), 1,
      sym_expansion,
    ACTIONS(176), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
    STATE(21), 2,
      sym_line_continuation,
      aux_sym_unquoted_string_repeat1,
  [772] = 9,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(179), 1,
      anon_sym_DOLLAR,
    ACTIONS(181), 1,
      aux_sym_image_name_token1,
    ACTIONS(183), 1,
      anon_sym_DASH_DASH,
    STATE(17), 1,
      sym_expansion,
    STATE(22), 1,
      sym_line_continuation,
    STATE(30), 1,
      sym_image_name,
    STATE(76), 1,
      sym_param,
    STATE(170), 1,
      sym_image_spec,
  [800] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(187), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(189), 1,
      anon_sym_DOLLAR,
    ACTIONS(192), 1,
      aux_sym_image_tag_token1,
    STATE(88), 1,
      sym_expansion,
    ACTIONS(185), 2,
      anon_sym_LF,
      anon_sym_AT,
    STATE(23), 2,
      sym_line_continuation,
      aux_sym_image_tag_repeat1,
  [824] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(197), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(199), 1,
      anon_sym_DOLLAR,
    ACTIONS(201), 1,
      aux_sym_image_tag_token1,
    STATE(23), 1,
      aux_sym_image_tag_repeat1,
    STATE(24), 1,
      sym_line_continuation,
    STATE(88), 1,
      sym_expansion,
    ACTIONS(195), 2,
      anon_sym_LF,
      anon_sym_AT,
  [850] = 8,
    ACTIONS(119), 1,
      anon_sym_DOLLAR,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(157), 1,
      anon_sym_LF,
    ACTIONS(161), 1,
      aux_sym__env_key_token1,
    STATE(21), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(25), 1,
      sym_line_continuation,
    STATE(80), 1,
      sym_expansion,
    ACTIONS(127), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
  [876] = 9,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(203), 1,
      aux_sym_path_token1,
    ACTIONS(205), 1,
      anon_sym_DOLLAR,
    ACTIONS(207), 1,
      anon_sym_DASH_DASH,
    STATE(26), 1,
      sym_line_continuation,
    STATE(56), 1,
      sym_expansion,
    STATE(58), 1,
      sym_param,
    STATE(59), 1,
      aux_sym_add_instruction_repeat1,
    STATE(192), 1,
      sym_path,
  [904] = 9,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(203), 1,
      aux_sym_path_token1,
    ACTIONS(205), 1,
      anon_sym_DOLLAR,
    ACTIONS(207), 1,
      anon_sym_DASH_DASH,
    STATE(27), 1,
      sym_line_continuation,
    STATE(56), 1,
      sym_expansion,
    STATE(60), 1,
      sym_param,
    STATE(61), 1,
      aux_sym_add_instruction_repeat1,
    STATE(192), 1,
      sym_path,
  [932] = 8,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(111), 1,
      anon_sym_LBRACK,
    ACTIONS(209), 1,
      aux_sym_path_token1,
    ACTIONS(211), 1,
      anon_sym_DOLLAR,
    STATE(28), 1,
      sym_line_continuation,
    STATE(37), 1,
      sym_expansion,
    STATE(140), 1,
      sym_path,
    STATE(188), 1,
      sym_string_array,
  [957] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(213), 1,
      anon_sym_DOLLAR,
    ACTIONS(215), 1,
      anon_sym_DQUOTE,
    ACTIONS(217), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(219), 1,
      sym_escape_sequence,
    STATE(29), 1,
      sym_line_continuation,
    STATE(38), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(95), 1,
      sym_expansion,
  [982] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(221), 1,
      anon_sym_LF,
    ACTIONS(223), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(225), 1,
      anon_sym_COLON,
    ACTIONS(227), 1,
      anon_sym_AT,
    STATE(30), 1,
      sym_line_continuation,
    STATE(94), 1,
      sym_image_tag,
    STATE(175), 1,
      sym_image_digest,
  [1007] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(213), 1,
      anon_sym_DOLLAR,
    ACTIONS(217), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(219), 1,
      sym_escape_sequence,
    ACTIONS(229), 1,
      anon_sym_DQUOTE,
    STATE(31), 1,
      sym_line_continuation,
    STATE(45), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(95), 1,
      sym_expansion,
  [1032] = 6,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(233), 1,
      aux_sym_path_token2,
    ACTIONS(236), 1,
      anon_sym_DOLLAR,
    STATE(92), 1,
      sym_expansion,
    ACTIONS(231), 2,
      anon_sym_LF,
      sym__non_newline_whitespace,
    STATE(32), 2,
      sym_line_continuation,
      aux_sym_path_repeat1,
  [1053] = 6,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(239), 1,
      anon_sym_LF,
    ACTIONS(241), 1,
      anon_sym_DOLLAR,
    ACTIONS(244), 1,
      aux_sym_expose_port_token1,
    STATE(33), 2,
      sym_line_continuation,
      aux_sym_expose_instruction_repeat1,
    STATE(133), 2,
      sym_expansion,
      sym_expose_port,
  [1074] = 8,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(11), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(247), 1,
      anon_sym_NONE,
    ACTIONS(249), 1,
      anon_sym_DASH_DASH,
    STATE(34), 1,
      sym_line_continuation,
    STATE(72), 1,
      aux_sym_healthcheck_instruction_repeat1,
    STATE(183), 1,
      sym_param,
    STATE(184), 1,
      sym_cmd_instruction,
  [1099] = 6,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(253), 1,
      anon_sym_POUND,
    STATE(121), 1,
      sym__comment_line,
    STATE(200), 1,
      sym__anon_comment,
    ACTIONS(251), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(35), 2,
      sym_line_continuation,
      aux_sym_shell_command_repeat1,
  [1120] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(213), 1,
      anon_sym_DOLLAR,
    ACTIONS(217), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(219), 1,
      sym_escape_sequence,
    ACTIONS(256), 1,
      anon_sym_DQUOTE,
    STATE(36), 1,
      sym_line_continuation,
    STATE(39), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(95), 1,
      sym_expansion,
  [1145] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(260), 1,
      aux_sym_path_token2,
    ACTIONS(262), 1,
      anon_sym_DOLLAR,
    STATE(37), 1,
      sym_line_continuation,
    STATE(40), 1,
      aux_sym_path_repeat1,
    STATE(92), 1,
      sym_expansion,
    ACTIONS(258), 2,
      anon_sym_LF,
      sym__non_newline_whitespace,
  [1168] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(213), 1,
      anon_sym_DOLLAR,
    ACTIONS(217), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(219), 1,
      sym_escape_sequence,
    ACTIONS(264), 1,
      anon_sym_DQUOTE,
    STATE(38), 1,
      sym_line_continuation,
    STATE(39), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(95), 1,
      sym_expansion,
  [1193] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(266), 1,
      anon_sym_DOLLAR,
    ACTIONS(269), 1,
      anon_sym_DQUOTE,
    ACTIONS(271), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(274), 1,
      sym_escape_sequence,
    STATE(95), 1,
      sym_expansion,
    STATE(39), 2,
      sym_line_continuation,
      aux_sym_double_quoted_string_repeat1,
  [1216] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(260), 1,
      aux_sym_path_token2,
    ACTIONS(262), 1,
      anon_sym_DOLLAR,
    STATE(32), 1,
      aux_sym_path_repeat1,
    STATE(40), 1,
      sym_line_continuation,
    STATE(92), 1,
      sym_expansion,
    ACTIONS(277), 2,
      anon_sym_LF,
      sym__non_newline_whitespace,
  [1239] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(41), 1,
      sym_line_continuation,
    ACTIONS(279), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
    ACTIONS(281), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_name_token2,
  [1256] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(42), 1,
      sym_line_continuation,
    ACTIONS(283), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
    ACTIONS(285), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_name_token2,
  [1273] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(43), 1,
      sym_line_continuation,
    ACTIONS(287), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
    ACTIONS(289), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_name_token2,
  [1290] = 6,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(293), 1,
      aux_sym__user_name_or_group_token1,
    ACTIONS(296), 1,
      anon_sym_DOLLAR,
    STATE(106), 1,
      sym_expansion,
    ACTIONS(291), 2,
      anon_sym_LF,
      anon_sym_COLON,
    STATE(44), 2,
      aux_sym__user_name_or_group,
      sym_line_continuation,
  [1311] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(213), 1,
      anon_sym_DOLLAR,
    ACTIONS(217), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(219), 1,
      sym_escape_sequence,
    ACTIONS(299), 1,
      anon_sym_DQUOTE,
    STATE(39), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(45), 1,
      sym_line_continuation,
    STATE(95), 1,
      sym_expansion,
  [1336] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(301), 1,
      anon_sym_LF,
    ACTIONS(303), 1,
      anon_sym_DOLLAR,
    ACTIONS(305), 1,
      aux_sym_expose_port_token1,
    STATE(33), 1,
      aux_sym_expose_instruction_repeat1,
    STATE(46), 1,
      sym_line_continuation,
    STATE(133), 2,
      sym_expansion,
      sym_expose_port,
  [1359] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(307), 1,
      anon_sym_LF,
    ACTIONS(309), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(311), 1,
      anon_sym_DOLLAR,
    ACTIONS(314), 1,
      aux_sym_image_digest_token1,
    STATE(91), 1,
      sym_expansion,
    STATE(47), 2,
      sym_line_continuation,
      aux_sym_image_digest_repeat1,
  [1382] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(317), 1,
      anon_sym_LF,
    ACTIONS(319), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(321), 1,
      anon_sym_DOLLAR,
    ACTIONS(323), 1,
      aux_sym_image_digest_token1,
    STATE(47), 1,
      aux_sym_image_digest_repeat1,
    STATE(48), 1,
      sym_line_continuation,
    STATE(91), 1,
      sym_expansion,
  [1407] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(213), 1,
      anon_sym_DOLLAR,
    ACTIONS(217), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(219), 1,
      sym_escape_sequence,
    ACTIONS(325), 1,
      anon_sym_DQUOTE,
    STATE(36), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(49), 1,
      sym_line_continuation,
    STATE(95), 1,
      sym_expansion,
  [1432] = 8,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(303), 1,
      anon_sym_DOLLAR,
    ACTIONS(327), 1,
      anon_sym_LF,
    ACTIONS(329), 1,
      anon_sym_COLON,
    ACTIONS(331), 1,
      aux_sym__user_name_or_group_token1,
    STATE(44), 1,
      aux_sym__user_name_or_group,
    STATE(50), 1,
      sym_line_continuation,
    STATE(106), 1,
      sym_expansion,
  [1457] = 6,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(333), 1,
      anon_sym_LF,
    ACTIONS(335), 1,
      aux_sym__env_key_token1,
    STATE(176), 1,
      sym_env_pair,
    STATE(203), 1,
      sym__env_key,
    STATE(51), 2,
      sym_line_continuation,
      aux_sym_env_instruction_repeat1,
  [1477] = 6,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(338), 1,
      aux_sym_path_token2,
    ACTIONS(341), 1,
      anon_sym_DOLLAR,
    ACTIONS(344), 1,
      sym__non_newline_whitespace,
    STATE(117), 1,
      sym_expansion,
    STATE(52), 2,
      sym_line_continuation,
      aux_sym_path_repeat1,
  [1497] = 6,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(346), 1,
      anon_sym_DOLLAR,
    ACTIONS(348), 1,
      aux_sym_expose_port_token1,
    STATE(46), 1,
      aux_sym_expose_instruction_repeat1,
    STATE(53), 1,
      sym_line_continuation,
    STATE(133), 2,
      sym_expansion,
      sym_expose_port,
  [1517] = 6,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(350), 1,
      anon_sym_LF,
    ACTIONS(352), 1,
      aux_sym__stopsignal_value_token1,
    ACTIONS(355), 1,
      anon_sym_DOLLAR,
    STATE(138), 1,
      sym_expansion,
    STATE(54), 2,
      aux_sym__stopsignal_value,
      sym_line_continuation,
  [1537] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(358), 1,
      anon_sym_LF,
    ACTIONS(360), 1,
      aux_sym__env_key_token1,
    STATE(51), 1,
      aux_sym_env_instruction_repeat1,
    STATE(55), 1,
      sym_line_continuation,
    STATE(176), 1,
      sym_env_pair,
    STATE(203), 1,
      sym__env_key,
  [1559] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(362), 1,
      aux_sym_path_token2,
    ACTIONS(364), 1,
      anon_sym_DOLLAR,
    ACTIONS(366), 1,
      sym__non_newline_whitespace,
    STATE(56), 1,
      sym_line_continuation,
    STATE(74), 1,
      aux_sym_path_repeat1,
    STATE(117), 1,
      sym_expansion,
  [1581] = 7,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(209), 1,
      aux_sym_path_token1,
    ACTIONS(211), 1,
      anon_sym_DOLLAR,
    STATE(37), 1,
      sym_expansion,
    STATE(57), 1,
      sym_line_continuation,
    STATE(65), 1,
      aux_sym_add_instruction_repeat1,
    STATE(151), 1,
      sym_path,
  [1603] = 7,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(203), 1,
      aux_sym_path_token1,
    ACTIONS(205), 1,
      anon_sym_DOLLAR,
    STATE(56), 1,
      sym_expansion,
    STATE(58), 1,
      sym_line_continuation,
    STATE(67), 1,
      aux_sym_add_instruction_repeat1,
    STATE(192), 1,
      sym_path,
  [1625] = 7,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(209), 1,
      aux_sym_path_token1,
    ACTIONS(211), 1,
      anon_sym_DOLLAR,
    STATE(37), 1,
      sym_expansion,
    STATE(59), 1,
      sym_line_continuation,
    STATE(65), 1,
      aux_sym_add_instruction_repeat1,
    STATE(149), 1,
      sym_path,
  [1647] = 7,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(203), 1,
      aux_sym_path_token1,
    ACTIONS(205), 1,
      anon_sym_DOLLAR,
    STATE(56), 1,
      sym_expansion,
    STATE(57), 1,
      aux_sym_add_instruction_repeat1,
    STATE(60), 1,
      sym_line_continuation,
    STATE(192), 1,
      sym_path,
  [1669] = 7,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(209), 1,
      aux_sym_path_token1,
    ACTIONS(211), 1,
      anon_sym_DOLLAR,
    STATE(37), 1,
      sym_expansion,
    STATE(61), 1,
      sym_line_continuation,
    STATE(65), 1,
      aux_sym_add_instruction_repeat1,
    STATE(158), 1,
      sym_path,
  [1691] = 7,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(368), 1,
      aux_sym__env_key_token1,
    STATE(55), 1,
      aux_sym_env_instruction_repeat1,
    STATE(62), 1,
      sym_line_continuation,
    STATE(176), 1,
      sym_env_pair,
    STATE(177), 1,
      sym__env_key,
    STATE(194), 1,
      sym__spaced_env_pair,
  [1713] = 6,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(370), 1,
      anon_sym_LF,
    ACTIONS(372), 1,
      anon_sym_DOLLAR,
    ACTIONS(375), 1,
      aux_sym_image_alias_token1,
    STATE(120), 1,
      sym_expansion,
    STATE(63), 2,
      sym_line_continuation,
      aux_sym_image_alias_repeat1,
  [1733] = 6,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(344), 1,
      anon_sym_LF,
    ACTIONS(378), 1,
      aux_sym_path_token2,
    ACTIONS(381), 1,
      anon_sym_DOLLAR,
    STATE(139), 1,
      sym_expansion,
    STATE(64), 2,
      sym_line_continuation,
      aux_sym_path_repeat1,
  [1753] = 6,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(384), 1,
      aux_sym_path_token1,
    ACTIONS(387), 1,
      anon_sym_DOLLAR,
    STATE(56), 1,
      sym_expansion,
    STATE(192), 1,
      sym_path,
    STATE(65), 2,
      sym_line_continuation,
      aux_sym_add_instruction_repeat1,
  [1773] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(390), 1,
      anon_sym_LF,
    ACTIONS(392), 1,
      aux_sym_path_token2,
    ACTIONS(394), 1,
      anon_sym_DOLLAR,
    STATE(64), 1,
      aux_sym_path_repeat1,
    STATE(66), 1,
      sym_line_continuation,
    STATE(139), 1,
      sym_expansion,
  [1795] = 7,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(209), 1,
      aux_sym_path_token1,
    ACTIONS(211), 1,
      anon_sym_DOLLAR,
    STATE(37), 1,
      sym_expansion,
    STATE(65), 1,
      aux_sym_add_instruction_repeat1,
    STATE(67), 1,
      sym_line_continuation,
    STATE(150), 1,
      sym_path,
  [1817] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(303), 1,
      anon_sym_DOLLAR,
    ACTIONS(331), 1,
      aux_sym__user_name_or_group_token1,
    ACTIONS(396), 1,
      anon_sym_LF,
    STATE(44), 1,
      aux_sym__user_name_or_group,
    STATE(68), 1,
      sym_line_continuation,
    STATE(106), 1,
      sym_expansion,
  [1839] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(398), 1,
      anon_sym_LF,
    ACTIONS(400), 1,
      aux_sym__stopsignal_value_token1,
    ACTIONS(402), 1,
      anon_sym_DOLLAR,
    STATE(54), 1,
      aux_sym__stopsignal_value,
    STATE(69), 1,
      sym_line_continuation,
    STATE(138), 1,
      sym_expansion,
  [1861] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(404), 1,
      anon_sym_LF,
    ACTIONS(406), 1,
      anon_sym_DOLLAR,
    ACTIONS(408), 1,
      aux_sym_image_alias_token1,
    STATE(63), 1,
      aux_sym_image_alias_repeat1,
    STATE(70), 1,
      sym_line_continuation,
    STATE(120), 1,
      sym_expansion,
  [1883] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(366), 1,
      anon_sym_LF,
    ACTIONS(392), 1,
      aux_sym_path_token2,
    ACTIONS(394), 1,
      anon_sym_DOLLAR,
    STATE(66), 1,
      aux_sym_path_repeat1,
    STATE(71), 1,
      sym_line_continuation,
    STATE(139), 1,
      sym_expansion,
  [1905] = 7,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(11), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(249), 1,
      anon_sym_DASH_DASH,
    STATE(72), 1,
      sym_line_continuation,
    STATE(99), 1,
      aux_sym_healthcheck_instruction_repeat1,
    STATE(183), 1,
      sym_param,
    STATE(218), 1,
      sym_cmd_instruction,
  [1927] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(73), 1,
      sym_line_continuation,
    ACTIONS(279), 2,
      anon_sym_LF,
      anon_sym_COLON,
    ACTIONS(281), 3,
      aux_sym__user_name_or_group_token1,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
  [1943] = 7,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(362), 1,
      aux_sym_path_token2,
    ACTIONS(364), 1,
      anon_sym_DOLLAR,
    ACTIONS(390), 1,
      sym__non_newline_whitespace,
    STATE(52), 1,
      aux_sym_path_repeat1,
    STATE(74), 1,
      sym_line_continuation,
    STATE(117), 1,
      sym_expansion,
  [1965] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(75), 1,
      sym_line_continuation,
    ACTIONS(412), 2,
      anon_sym_DOLLAR,
      aux_sym_label_pair_token1,
    ACTIONS(410), 3,
      anon_sym_LF,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
  [1981] = 7,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(179), 1,
      anon_sym_DOLLAR,
    ACTIONS(181), 1,
      aux_sym_image_name_token1,
    STATE(17), 1,
      sym_expansion,
    STATE(30), 1,
      sym_image_name,
    STATE(76), 1,
      sym_line_continuation,
    STATE(173), 1,
      sym_image_spec,
  [2003] = 5,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(414), 1,
      anon_sym_LF,
    STATE(77), 1,
      sym_line_continuation,
    ACTIONS(416), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
    ACTIONS(418), 2,
      anon_sym_SLASHtcp,
      anon_sym_SLASHudp,
  [2021] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(78), 1,
      sym_line_continuation,
    ACTIONS(279), 2,
      anon_sym_LF,
      anon_sym_AT,
    ACTIONS(281), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_tag_token1,
  [2037] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(79), 1,
      sym_line_continuation,
    ACTIONS(281), 2,
      anon_sym_DOLLAR,
      aux_sym__env_key_token1,
    ACTIONS(279), 3,
      anon_sym_LF,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
  [2053] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(80), 1,
      sym_line_continuation,
    ACTIONS(412), 2,
      anon_sym_DOLLAR,
      aux_sym__env_key_token1,
    ACTIONS(410), 3,
      anon_sym_LF,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
  [2069] = 7,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(420), 1,
      anon_sym_DOLLAR,
    ACTIONS(422), 1,
      aux_sym_image_alias_token1,
    STATE(70), 1,
      aux_sym_image_alias_repeat1,
    STATE(81), 1,
      sym_line_continuation,
    STATE(120), 1,
      sym_expansion,
    STATE(234), 1,
      sym_image_alias,
  [2091] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(82), 1,
      sym_line_continuation,
    ACTIONS(289), 2,
      anon_sym_DOLLAR,
      aux_sym_label_pair_token1,
    ACTIONS(287), 3,
      anon_sym_LF,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
  [2107] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(83), 1,
      sym_line_continuation,
    ACTIONS(287), 2,
      anon_sym_LF,
      anon_sym_COLON,
    ACTIONS(289), 3,
      aux_sym__user_name_or_group_token1,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
  [2123] = 7,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(420), 1,
      anon_sym_DOLLAR,
    ACTIONS(422), 1,
      aux_sym_image_alias_token1,
    STATE(70), 1,
      aux_sym_image_alias_repeat1,
    STATE(84), 1,
      sym_line_continuation,
    STATE(120), 1,
      sym_expansion,
    STATE(220), 1,
      sym_image_alias,
  [2145] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(85), 1,
      sym_line_continuation,
    ACTIONS(289), 2,
      anon_sym_DOLLAR,
      aux_sym__env_key_token1,
    ACTIONS(287), 3,
      anon_sym_LF,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
  [2161] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(86), 1,
      sym_line_continuation,
    ACTIONS(287), 2,
      anon_sym_LF,
      anon_sym_AT,
    ACTIONS(289), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_tag_token1,
  [2177] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(87), 1,
      sym_line_continuation,
    ACTIONS(281), 2,
      anon_sym_DOLLAR,
      aux_sym_label_pair_token1,
    ACTIONS(279), 3,
      anon_sym_LF,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH,
  [2193] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(88), 1,
      sym_line_continuation,
    ACTIONS(424), 2,
      anon_sym_LF,
      anon_sym_AT,
    ACTIONS(426), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_tag_token1,
  [2209] = 6,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(201), 1,
      aux_sym_image_tag_token1,
    ACTIONS(428), 1,
      anon_sym_DOLLAR,
    STATE(24), 1,
      aux_sym_image_tag_repeat1,
    STATE(88), 1,
      sym_expansion,
    STATE(89), 1,
      sym_line_continuation,
  [2228] = 5,
    ACTIONS(430), 1,
      anon_sym_LF,
    ACTIONS(434), 1,
      anon_sym_BSLASH_LF,
    STATE(90), 1,
      sym_line_continuation,
    STATE(97), 1,
      aux_sym_shell_fragment_repeat1,
    ACTIONS(432), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
  [2245] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(91), 1,
      sym_line_continuation,
    ACTIONS(436), 2,
      anon_sym_LF,
      aux_sym_image_digest_token1,
    ACTIONS(438), 2,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
  [2260] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(92), 1,
      sym_line_continuation,
    ACTIONS(440), 4,
      anon_sym_LF,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
      sym__non_newline_whitespace,
  [2273] = 6,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(323), 1,
      aux_sym_image_digest_token1,
    ACTIONS(442), 1,
      anon_sym_DOLLAR,
    STATE(48), 1,
      aux_sym_image_digest_repeat1,
    STATE(91), 1,
      sym_expansion,
    STATE(93), 1,
      sym_line_continuation,
  [2292] = 6,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(227), 1,
      anon_sym_AT,
    ACTIONS(444), 1,
      anon_sym_LF,
    ACTIONS(446), 1,
      aux_sym_from_instruction_token2,
    STATE(94), 1,
      sym_line_continuation,
    STATE(159), 1,
      sym_image_digest,
  [2311] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(450), 1,
      aux_sym_double_quoted_string_token1,
    STATE(95), 1,
      sym_line_continuation,
    ACTIONS(448), 3,
      anon_sym_DOLLAR,
      anon_sym_DQUOTE,
      sym_escape_sequence,
  [2326] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(96), 1,
      sym_line_continuation,
    ACTIONS(281), 4,
      anon_sym_LF,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
      sym__non_newline_whitespace,
  [2339] = 4,
    ACTIONS(452), 1,
      anon_sym_LF,
    ACTIONS(457), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(454), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(97), 2,
      sym_line_continuation,
      aux_sym_shell_fragment_repeat1,
  [2354] = 5,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(459), 1,
      anon_sym_LF,
    ACTIONS(461), 1,
      aux_sym_label_pair_token1,
    STATE(171), 1,
      sym_label_pair,
    STATE(98), 2,
      sym_line_continuation,
      aux_sym_label_instruction_repeat1,
  [2371] = 5,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(464), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(466), 1,
      anon_sym_DASH_DASH,
    STATE(183), 1,
      sym_param,
    STATE(99), 2,
      sym_line_continuation,
      aux_sym_healthcheck_instruction_repeat1,
  [2388] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(100), 1,
      sym_line_continuation,
    ACTIONS(287), 2,
      anon_sym_LF,
      aux_sym_image_digest_token1,
    ACTIONS(289), 2,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
  [2403] = 6,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(469), 1,
      anon_sym_LF,
    ACTIONS(471), 1,
      aux_sym_label_pair_token1,
    STATE(98), 1,
      aux_sym_label_instruction_repeat1,
    STATE(101), 1,
      sym_line_continuation,
    STATE(171), 1,
      sym_label_pair,
  [2422] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(102), 1,
      sym_line_continuation,
    ACTIONS(279), 2,
      anon_sym_LF,
      aux_sym_image_digest_token1,
    ACTIONS(281), 2,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
  [2437] = 6,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(473), 1,
      aux_sym__stopsignal_value_token1,
    ACTIONS(475), 1,
      anon_sym_DOLLAR,
    STATE(69), 1,
      aux_sym__stopsignal_value,
    STATE(103), 1,
      sym_line_continuation,
    STATE(138), 1,
      sym_expansion,
  [2456] = 6,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(477), 1,
      aux_sym_path_token1,
    ACTIONS(479), 1,
      anon_sym_DOLLAR,
    STATE(71), 1,
      sym_expansion,
    STATE(104), 1,
      sym_line_continuation,
    STATE(187), 1,
      sym_path,
  [2475] = 6,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(346), 1,
      anon_sym_DOLLAR,
    ACTIONS(481), 1,
      aux_sym__user_name_or_group_token1,
    STATE(50), 1,
      aux_sym__user_name_or_group,
    STATE(105), 1,
      sym_line_continuation,
    STATE(106), 1,
      sym_expansion,
  [2494] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(106), 1,
      sym_line_continuation,
    ACTIONS(483), 2,
      anon_sym_LF,
      anon_sym_COLON,
    ACTIONS(485), 2,
      aux_sym__user_name_or_group_token1,
      anon_sym_DOLLAR,
  [2509] = 6,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(209), 1,
      aux_sym_path_token1,
    ACTIONS(211), 1,
      anon_sym_DOLLAR,
    STATE(37), 1,
      sym_expansion,
    STATE(107), 1,
      sym_line_continuation,
    STATE(152), 1,
      sym_path,
  [2528] = 6,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(346), 1,
      anon_sym_DOLLAR,
    ACTIONS(481), 1,
      aux_sym__user_name_or_group_token1,
    STATE(68), 1,
      aux_sym__user_name_or_group,
    STATE(106), 1,
      sym_expansion,
    STATE(108), 1,
      sym_line_continuation,
  [2547] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(287), 1,
      aux_sym_double_quoted_string_token1,
    STATE(109), 1,
      sym_line_continuation,
    ACTIONS(289), 3,
      anon_sym_DOLLAR,
      anon_sym_DQUOTE,
      sym_escape_sequence,
  [2562] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(279), 1,
      aux_sym_double_quoted_string_token1,
    STATE(110), 1,
      sym_line_continuation,
    ACTIONS(281), 3,
      anon_sym_DOLLAR,
      anon_sym_DQUOTE,
      sym_escape_sequence,
  [2577] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(111), 1,
      sym_line_continuation,
    ACTIONS(289), 4,
      anon_sym_LF,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
      sym__non_newline_whitespace,
  [2590] = 5,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(487), 1,
      aux_sym_label_pair_token1,
    STATE(101), 1,
      aux_sym_label_instruction_repeat1,
    STATE(112), 1,
      sym_line_continuation,
    STATE(171), 1,
      sym_label_pair,
  [2606] = 5,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(489), 1,
      anon_sym_LF,
    ACTIONS(491), 1,
      sym__non_newline_whitespace,
    STATE(113), 1,
      sym_line_continuation,
    STATE(136), 1,
      aux_sym_volume_instruction_repeat1,
  [2622] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(493), 1,
      anon_sym_COMMA,
    ACTIONS(496), 1,
      anon_sym_RBRACK,
    STATE(114), 2,
      sym_line_continuation,
      aux_sym_string_array_repeat1,
  [2636] = 5,
    ACTIONS(498), 1,
      anon_sym_LF,
    ACTIONS(500), 1,
      anon_sym_BSLASH_LF,
    STATE(13), 1,
      sym_required_line_continuation,
    STATE(115), 1,
      sym_line_continuation,
    STATE(124), 1,
      aux_sym_shell_command_repeat2,
  [2652] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(502), 1,
      anon_sym_LF,
    STATE(116), 1,
      sym_line_continuation,
    ACTIONS(504), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
  [2666] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(506), 1,
      sym__non_newline_whitespace,
    STATE(117), 1,
      sym_line_continuation,
    ACTIONS(440), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [2680] = 5,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(508), 1,
      anon_sym_RBRACK,
    ACTIONS(510), 1,
      anon_sym_DQUOTE,
    STATE(118), 1,
      sym_line_continuation,
    STATE(126), 1,
      sym_double_quoted_string,
  [2696] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(287), 1,
      anon_sym_LF,
    STATE(119), 1,
      sym_line_continuation,
    ACTIONS(289), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [2710] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(512), 1,
      anon_sym_LF,
    STATE(120), 1,
      sym_line_continuation,
    ACTIONS(514), 2,
      anon_sym_DOLLAR,
      aux_sym_image_alias_token1,
  [2724] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    STATE(121), 1,
      sym_line_continuation,
    ACTIONS(516), 3,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
      anon_sym_POUND,
  [2736] = 5,
    ACTIONS(500), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(518), 1,
      anon_sym_LF,
    STATE(13), 1,
      sym_required_line_continuation,
    STATE(122), 1,
      sym_line_continuation,
    STATE(132), 1,
      aux_sym_shell_command_repeat2,
  [2752] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    STATE(123), 1,
      sym_line_continuation,
    ACTIONS(520), 3,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
      anon_sym_POUND,
  [2764] = 5,
    ACTIONS(500), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(518), 1,
      anon_sym_LF,
    STATE(13), 1,
      sym_required_line_continuation,
    STATE(124), 1,
      sym_line_continuation,
    STATE(131), 1,
      aux_sym_shell_command_repeat2,
  [2780] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    STATE(125), 1,
      sym_line_continuation,
    ACTIONS(522), 3,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
      anon_sym_POUND,
  [2792] = 5,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(524), 1,
      anon_sym_COMMA,
    ACTIONS(526), 1,
      anon_sym_RBRACK,
    STATE(126), 1,
      sym_line_continuation,
    STATE(129), 1,
      aux_sym_string_array_repeat1,
  [2808] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(279), 1,
      anon_sym_LF,
    STATE(127), 1,
      sym_line_continuation,
    ACTIONS(281), 2,
      anon_sym_DOLLAR,
      aux_sym_image_alias_token1,
  [2822] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(287), 1,
      anon_sym_LF,
    STATE(128), 1,
      sym_line_continuation,
    ACTIONS(289), 2,
      anon_sym_DOLLAR,
      aux_sym_image_alias_token1,
  [2836] = 5,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(524), 1,
      anon_sym_COMMA,
    ACTIONS(528), 1,
      anon_sym_RBRACK,
    STATE(114), 1,
      aux_sym_string_array_repeat1,
    STATE(129), 1,
      sym_line_continuation,
  [2852] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(279), 1,
      anon_sym_LF,
    STATE(130), 1,
      sym_line_continuation,
    ACTIONS(281), 2,
      aux_sym__stopsignal_value_token1,
      anon_sym_DOLLAR,
  [2866] = 4,
    ACTIONS(530), 1,
      anon_sym_LF,
    ACTIONS(532), 1,
      anon_sym_BSLASH_LF,
    STATE(13), 1,
      sym_required_line_continuation,
    STATE(131), 2,
      sym_line_continuation,
      aux_sym_shell_command_repeat2,
  [2880] = 5,
    ACTIONS(500), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(535), 1,
      anon_sym_LF,
    STATE(13), 1,
      sym_required_line_continuation,
    STATE(131), 1,
      aux_sym_shell_command_repeat2,
    STATE(132), 1,
      sym_line_continuation,
  [2896] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(537), 1,
      anon_sym_LF,
    STATE(133), 1,
      sym_line_continuation,
    ACTIONS(539), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
  [2910] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(287), 1,
      anon_sym_LF,
    STATE(134), 1,
      sym_line_continuation,
    ACTIONS(289), 2,
      aux_sym__stopsignal_value_token1,
      anon_sym_DOLLAR,
  [2924] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(279), 1,
      anon_sym_LF,
    STATE(135), 1,
      sym_line_continuation,
    ACTIONS(281), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [2938] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(541), 1,
      anon_sym_LF,
    ACTIONS(543), 1,
      sym__non_newline_whitespace,
    STATE(136), 2,
      sym_line_continuation,
      aux_sym_volume_instruction_repeat1,
  [2952] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(287), 1,
      sym__non_newline_whitespace,
    STATE(137), 1,
      sym_line_continuation,
    ACTIONS(289), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [2966] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(546), 1,
      anon_sym_LF,
    STATE(138), 1,
      sym_line_continuation,
    ACTIONS(548), 2,
      aux_sym__stopsignal_value_token1,
      anon_sym_DOLLAR,
  [2980] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(506), 1,
      anon_sym_LF,
    STATE(139), 1,
      sym_line_continuation,
    ACTIONS(440), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [2994] = 5,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(491), 1,
      sym__non_newline_whitespace,
    ACTIONS(550), 1,
      anon_sym_LF,
    STATE(113), 1,
      aux_sym_volume_instruction_repeat1,
    STATE(140), 1,
      sym_line_continuation,
  [3010] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(279), 1,
      sym__non_newline_whitespace,
    STATE(141), 1,
      sym_line_continuation,
    ACTIONS(281), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [3024] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(552), 1,
      anon_sym_LF,
    ACTIONS(554), 1,
      anon_sym_EQ,
    STATE(142), 1,
      sym_line_continuation,
  [3037] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(556), 1,
      anon_sym_LBRACE,
    ACTIONS(558), 1,
      sym_variable,
    STATE(143), 1,
      sym_line_continuation,
  [3050] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(560), 1,
      anon_sym_LBRACE,
    ACTIONS(562), 1,
      sym_variable,
    STATE(144), 1,
      sym_line_continuation,
  [3063] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(564), 1,
      anon_sym_LF,
    ACTIONS(566), 1,
      aux_sym_label_pair_token1,
    STATE(145), 1,
      sym_line_continuation,
  [3076] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    STATE(146), 1,
      sym_line_continuation,
    ACTIONS(568), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3087] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(570), 1,
      anon_sym_LF,
    ACTIONS(572), 1,
      aux_sym__env_key_token1,
    STATE(147), 1,
      sym_line_continuation,
  [3100] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(574), 1,
      anon_sym_LBRACE,
    ACTIONS(576), 1,
      sym_variable,
    STATE(148), 1,
      sym_line_continuation,
  [3113] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(578), 1,
      anon_sym_LF,
    ACTIONS(580), 1,
      sym__non_newline_whitespace,
    STATE(149), 1,
      sym_line_continuation,
  [3126] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(580), 1,
      sym__non_newline_whitespace,
    ACTIONS(582), 1,
      anon_sym_LF,
    STATE(150), 1,
      sym_line_continuation,
  [3139] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(580), 1,
      sym__non_newline_whitespace,
    ACTIONS(584), 1,
      anon_sym_LF,
    STATE(151), 1,
      sym_line_continuation,
  [3152] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(152), 1,
      sym_line_continuation,
    ACTIONS(541), 2,
      anon_sym_LF,
      sym__non_newline_whitespace,
  [3163] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(586), 1,
      anon_sym_LBRACE,
    ACTIONS(588), 1,
      sym_variable,
    STATE(153), 1,
      sym_line_continuation,
  [3176] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(510), 1,
      anon_sym_DQUOTE,
    STATE(154), 1,
      sym_line_continuation,
    STATE(164), 1,
      sym_double_quoted_string,
  [3189] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(590), 1,
      anon_sym_LBRACE,
    ACTIONS(592), 1,
      sym_variable,
    STATE(155), 1,
      sym_line_continuation,
  [3202] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(594), 1,
      anon_sym_LBRACE,
    ACTIONS(596), 1,
      sym_variable,
    STATE(156), 1,
      sym_line_continuation,
  [3215] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(598), 1,
      anon_sym_DOLLAR,
    ACTIONS(600), 1,
      aux_sym_image_name_token1,
    STATE(157), 1,
      sym_line_continuation,
  [3228] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(580), 1,
      sym__non_newline_whitespace,
    ACTIONS(602), 1,
      anon_sym_LF,
    STATE(158), 1,
      sym_line_continuation,
  [3241] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(604), 1,
      anon_sym_LF,
    ACTIONS(606), 1,
      aux_sym_from_instruction_token2,
    STATE(159), 1,
      sym_line_continuation,
  [3254] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(608), 1,
      anon_sym_LBRACE,
    ACTIONS(610), 1,
      sym_variable,
    STATE(160), 1,
      sym_line_continuation,
  [3267] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(612), 1,
      anon_sym_LBRACE,
    ACTIONS(614), 1,
      sym_variable,
    STATE(161), 1,
      sym_line_continuation,
  [3280] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    STATE(162), 1,
      sym_line_continuation,
    ACTIONS(616), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3291] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(618), 1,
      anon_sym_LBRACE,
    ACTIONS(620), 1,
      sym_variable,
    STATE(163), 1,
      sym_line_continuation,
  [3304] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    STATE(164), 1,
      sym_line_continuation,
    ACTIONS(496), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3315] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(111), 1,
      anon_sym_LBRACK,
    STATE(165), 1,
      sym_line_continuation,
    STATE(186), 1,
      sym_string_array,
  [3328] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(622), 1,
      anon_sym_LBRACE,
    ACTIONS(624), 1,
      sym_variable,
    STATE(166), 1,
      sym_line_continuation,
  [3341] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(626), 1,
      anon_sym_LBRACE,
    ACTIONS(628), 1,
      sym_variable,
    STATE(167), 1,
      sym_line_continuation,
  [3354] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(630), 1,
      aux_sym_path_token1,
    ACTIONS(632), 1,
      anon_sym_DOLLAR,
    STATE(168), 1,
      sym_line_continuation,
  [3367] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(634), 1,
      anon_sym_LBRACE,
    ACTIONS(636), 1,
      sym_variable,
    STATE(169), 1,
      sym_line_continuation,
  [3380] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(638), 1,
      anon_sym_LF,
    ACTIONS(640), 1,
      aux_sym_from_instruction_token2,
    STATE(170), 1,
      sym_line_continuation,
  [3393] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(642), 1,
      anon_sym_LF,
    ACTIONS(644), 1,
      aux_sym_label_pair_token1,
    STATE(171), 1,
      sym_line_continuation,
  [3406] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    STATE(172), 1,
      sym_line_continuation,
    ACTIONS(646), 2,
      anon_sym_EQ,
      aux_sym__spaced_env_pair_token1,
  [3417] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(648), 1,
      anon_sym_LF,
    ACTIONS(650), 1,
      aux_sym_from_instruction_token2,
    STATE(173), 1,
      sym_line_continuation,
  [3430] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(568), 1,
      anon_sym_LF,
    ACTIONS(652), 1,
      aux_sym_label_pair_token1,
    STATE(174), 1,
      sym_line_continuation,
  [3443] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(654), 1,
      anon_sym_LF,
    ACTIONS(656), 1,
      aux_sym_from_instruction_token2,
    STATE(175), 1,
      sym_line_continuation,
  [3456] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(658), 1,
      anon_sym_LF,
    ACTIONS(660), 1,
      aux_sym__env_key_token1,
    STATE(176), 1,
      sym_line_continuation,
  [3469] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(662), 1,
      anon_sym_EQ,
    ACTIONS(664), 1,
      aux_sym__spaced_env_pair_token1,
    STATE(177), 1,
      sym_line_continuation,
  [3482] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(616), 1,
      anon_sym_LF,
    ACTIONS(666), 1,
      aux_sym__env_key_token1,
    STATE(178), 1,
      sym_line_continuation,
  [3495] = 4,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(598), 1,
      anon_sym_DOLLAR,
    ACTIONS(600), 1,
      aux_sym_path_token1,
    STATE(179), 1,
      sym_line_continuation,
  [3508] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(616), 1,
      anon_sym_LF,
    ACTIONS(666), 1,
      aux_sym_label_pair_token1,
    STATE(180), 1,
      sym_line_continuation,
  [3521] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    STATE(181), 1,
      sym_line_continuation,
    ACTIONS(598), 2,
      aux_sym_cmd_instruction_token1,
      anon_sym_DASH_DASH,
  [3532] = 4,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(568), 1,
      anon_sym_LF,
    ACTIONS(652), 1,
      aux_sym__env_key_token1,
    STATE(182), 1,
      sym_line_continuation,
  [3545] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    STATE(183), 1,
      sym_line_continuation,
    ACTIONS(668), 2,
      aux_sym_cmd_instruction_token1,
      anon_sym_DASH_DASH,
  [3556] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(670), 1,
      anon_sym_LF,
    STATE(184), 1,
      sym_line_continuation,
  [3566] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(672), 1,
      anon_sym_LF,
    STATE(185), 1,
      sym_line_continuation,
  [3576] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(674), 1,
      anon_sym_LF,
    STATE(186), 1,
      sym_line_continuation,
  [3586] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(676), 1,
      anon_sym_LF,
    STATE(187), 1,
      sym_line_continuation,
  [3596] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(678), 1,
      anon_sym_LF,
    STATE(188), 1,
      sym_line_continuation,
  [3606] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(680), 1,
      anon_sym_LF,
    STATE(189), 1,
      sym_line_continuation,
  [3616] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(682), 1,
      anon_sym_LF,
    STATE(190), 1,
      sym_line_continuation,
  [3626] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(684), 1,
      anon_sym_LF,
    STATE(191), 1,
      sym_line_continuation,
  [3636] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(686), 1,
      sym__non_newline_whitespace,
    STATE(192), 1,
      sym_line_continuation,
  [3646] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(688), 1,
      aux_sym_expansion_token1,
    STATE(193), 1,
      sym_line_continuation,
  [3656] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(690), 1,
      anon_sym_LF,
    STATE(194), 1,
      sym_line_continuation,
  [3666] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(692), 1,
      anon_sym_EQ,
    STATE(195), 1,
      sym_line_continuation,
  [3676] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(694), 1,
      anon_sym_LF,
    STATE(196), 1,
      sym_line_continuation,
  [3686] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(696), 1,
      anon_sym_LF,
    STATE(197), 1,
      sym_line_continuation,
  [3696] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(698), 1,
      anon_sym_EQ,
    STATE(198), 1,
      sym_line_continuation,
  [3706] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(700), 1,
      anon_sym_LF,
    STATE(199), 1,
      sym_line_continuation,
  [3716] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(702), 1,
      anon_sym_LF,
    STATE(200), 1,
      sym_line_continuation,
  [3726] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(704), 1,
      anon_sym_LF,
    STATE(201), 1,
      sym_line_continuation,
  [3736] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(706), 1,
      aux_sym_maintainer_instruction_token2,
    STATE(202), 1,
      sym_line_continuation,
  [3746] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(662), 1,
      anon_sym_EQ,
    STATE(203), 1,
      sym_line_continuation,
  [3756] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(708), 1,
      aux_sym_param_token1,
    STATE(204), 1,
      sym_line_continuation,
  [3766] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(646), 1,
      anon_sym_EQ,
    STATE(205), 1,
      sym_line_continuation,
  [3776] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(710), 1,
      anon_sym_LF,
    STATE(206), 1,
      sym_line_continuation,
  [3786] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(712), 1,
      ts_builtin_sym_end,
    STATE(207), 1,
      sym_line_continuation,
  [3796] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(714), 1,
      anon_sym_LF,
    STATE(208), 1,
      sym_line_continuation,
  [3806] = 3,
    ACTIONS(716), 1,
      anon_sym_LF,
    ACTIONS(718), 1,
      anon_sym_BSLASH_LF,
    STATE(209), 1,
      sym_line_continuation,
  [3816] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(720), 1,
      aux_sym_maintainer_instruction_token2,
    STATE(210), 1,
      sym_line_continuation,
  [3826] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(722), 1,
      anon_sym_RBRACE,
    STATE(211), 1,
      sym_line_continuation,
  [3836] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(724), 1,
      aux_sym_param_token2,
    STATE(212), 1,
      sym_line_continuation,
  [3846] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(726), 1,
      aux_sym_maintainer_instruction_token2,
    STATE(213), 1,
      sym_line_continuation,
  [3856] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(728), 1,
      anon_sym_LF,
    STATE(214), 1,
      sym_line_continuation,
  [3866] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(730), 1,
      anon_sym_RBRACE,
    STATE(215), 1,
      sym_line_continuation,
  [3876] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(732), 1,
      aux_sym_param_token2,
    STATE(216), 1,
      sym_line_continuation,
  [3886] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(734), 1,
      aux_sym_arg_instruction_token2,
    STATE(217), 1,
      sym_line_continuation,
  [3896] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(736), 1,
      anon_sym_LF,
    STATE(218), 1,
      sym_line_continuation,
  [3906] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(738), 1,
      anon_sym_RBRACE,
    STATE(219), 1,
      sym_line_continuation,
  [3916] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(740), 1,
      anon_sym_LF,
    STATE(220), 1,
      sym_line_continuation,
  [3926] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(742), 1,
      anon_sym_RBRACE,
    STATE(221), 1,
      sym_line_continuation,
  [3936] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(744), 1,
      aux_sym_param_token2,
    STATE(222), 1,
      sym_line_continuation,
  [3946] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(746), 1,
      anon_sym_RBRACE,
    STATE(223), 1,
      sym_line_continuation,
  [3956] = 3,
    ACTIONS(530), 1,
      anon_sym_LF,
    ACTIONS(748), 1,
      anon_sym_BSLASH_LF,
    STATE(224), 1,
      sym_line_continuation,
  [3966] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(750), 1,
      anon_sym_RBRACE,
    STATE(225), 1,
      sym_line_continuation,
  [3976] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(752), 1,
      anon_sym_LF,
    STATE(226), 1,
      sym_line_continuation,
  [3986] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(754), 1,
      anon_sym_RBRACE,
    STATE(227), 1,
      sym_line_continuation,
  [3996] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(756), 1,
      anon_sym_LF,
    STATE(228), 1,
      sym_line_continuation,
  [4006] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(758), 1,
      anon_sym_RBRACE,
    STATE(229), 1,
      sym_line_continuation,
  [4016] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(760), 1,
      anon_sym_RBRACE,
    STATE(230), 1,
      sym_line_continuation,
  [4026] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(762), 1,
      anon_sym_RBRACE,
    STATE(231), 1,
      sym_line_continuation,
  [4036] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(764), 1,
      anon_sym_LF,
    STATE(232), 1,
      sym_line_continuation,
  [4046] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(766), 1,
      anon_sym_RBRACE,
    STATE(233), 1,
      sym_line_continuation,
  [4056] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(768), 1,
      anon_sym_LF,
    STATE(234), 1,
      sym_line_continuation,
  [4066] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(770), 1,
      anon_sym_RBRACE,
    STATE(235), 1,
      sym_line_continuation,
  [4076] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(772), 1,
      aux_sym_expansion_token1,
    STATE(236), 1,
      sym_line_continuation,
  [4086] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(774), 1,
      anon_sym_EQ,
    STATE(237), 1,
      sym_line_continuation,
  [4096] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(776), 1,
      aux_sym_expansion_token1,
    STATE(238), 1,
      sym_line_continuation,
  [4106] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(778), 1,
      anon_sym_EQ,
    STATE(239), 1,
      sym_line_continuation,
  [4116] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(780), 1,
      aux_sym_expansion_token1,
    STATE(240), 1,
      sym_line_continuation,
  [4126] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(782), 1,
      aux_sym_expansion_token1,
    STATE(241), 1,
      sym_line_continuation,
  [4136] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(784), 1,
      aux_sym_expansion_token1,
    STATE(242), 1,
      sym_line_continuation,
  [4146] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(786), 1,
      aux_sym_expansion_token1,
    STATE(243), 1,
      sym_line_continuation,
  [4156] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(788), 1,
      aux_sym_expansion_token1,
    STATE(244), 1,
      sym_line_continuation,
  [4166] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(790), 1,
      aux_sym_expansion_token1,
    STATE(245), 1,
      sym_line_continuation,
  [4176] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(792), 1,
      aux_sym_expansion_token1,
    STATE(246), 1,
      sym_line_continuation,
  [4186] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(794), 1,
      aux_sym_expansion_token1,
    STATE(247), 1,
      sym_line_continuation,
  [4196] = 3,
    ACTIONS(123), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(796), 1,
      aux_sym_expansion_token1,
    STATE(248), 1,
      sym_line_continuation,
  [4206] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(798), 1,
      aux_sym_param_token1,
    STATE(249), 1,
      sym_line_continuation,
  [4216] = 3,
    ACTIONS(3), 1,
      anon_sym_BSLASH_LF,
    ACTIONS(800), 1,
      aux_sym_param_token1,
    STATE(250), 1,
      sym_line_continuation,
  [4226] = 1,
    ACTIONS(802), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 95,
  [SMALL_STATE(4)] = 192,
  [SMALL_STATE(5)] = 280,
  [SMALL_STATE(6)] = 310,
  [SMALL_STATE(7)] = 346,
  [SMALL_STATE(8)] = 382,
  [SMALL_STATE(9)] = 418,
  [SMALL_STATE(10)] = 451,
  [SMALL_STATE(11)] = 476,
  [SMALL_STATE(12)] = 503,
  [SMALL_STATE(13)] = 532,
  [SMALL_STATE(14)] = 561,
  [SMALL_STATE(15)] = 588,
  [SMALL_STATE(16)] = 615,
  [SMALL_STATE(17)] = 644,
  [SMALL_STATE(18)] = 671,
  [SMALL_STATE(19)] = 698,
  [SMALL_STATE(20)] = 724,
  [SMALL_STATE(21)] = 748,
  [SMALL_STATE(22)] = 772,
  [SMALL_STATE(23)] = 800,
  [SMALL_STATE(24)] = 824,
  [SMALL_STATE(25)] = 850,
  [SMALL_STATE(26)] = 876,
  [SMALL_STATE(27)] = 904,
  [SMALL_STATE(28)] = 932,
  [SMALL_STATE(29)] = 957,
  [SMALL_STATE(30)] = 982,
  [SMALL_STATE(31)] = 1007,
  [SMALL_STATE(32)] = 1032,
  [SMALL_STATE(33)] = 1053,
  [SMALL_STATE(34)] = 1074,
  [SMALL_STATE(35)] = 1099,
  [SMALL_STATE(36)] = 1120,
  [SMALL_STATE(37)] = 1145,
  [SMALL_STATE(38)] = 1168,
  [SMALL_STATE(39)] = 1193,
  [SMALL_STATE(40)] = 1216,
  [SMALL_STATE(41)] = 1239,
  [SMALL_STATE(42)] = 1256,
  [SMALL_STATE(43)] = 1273,
  [SMALL_STATE(44)] = 1290,
  [SMALL_STATE(45)] = 1311,
  [SMALL_STATE(46)] = 1336,
  [SMALL_STATE(47)] = 1359,
  [SMALL_STATE(48)] = 1382,
  [SMALL_STATE(49)] = 1407,
  [SMALL_STATE(50)] = 1432,
  [SMALL_STATE(51)] = 1457,
  [SMALL_STATE(52)] = 1477,
  [SMALL_STATE(53)] = 1497,
  [SMALL_STATE(54)] = 1517,
  [SMALL_STATE(55)] = 1537,
  [SMALL_STATE(56)] = 1559,
  [SMALL_STATE(57)] = 1581,
  [SMALL_STATE(58)] = 1603,
  [SMALL_STATE(59)] = 1625,
  [SMALL_STATE(60)] = 1647,
  [SMALL_STATE(61)] = 1669,
  [SMALL_STATE(62)] = 1691,
  [SMALL_STATE(63)] = 1713,
  [SMALL_STATE(64)] = 1733,
  [SMALL_STATE(65)] = 1753,
  [SMALL_STATE(66)] = 1773,
  [SMALL_STATE(67)] = 1795,
  [SMALL_STATE(68)] = 1817,
  [SMALL_STATE(69)] = 1839,
  [SMALL_STATE(70)] = 1861,
  [SMALL_STATE(71)] = 1883,
  [SMALL_STATE(72)] = 1905,
  [SMALL_STATE(73)] = 1927,
  [SMALL_STATE(74)] = 1943,
  [SMALL_STATE(75)] = 1965,
  [SMALL_STATE(76)] = 1981,
  [SMALL_STATE(77)] = 2003,
  [SMALL_STATE(78)] = 2021,
  [SMALL_STATE(79)] = 2037,
  [SMALL_STATE(80)] = 2053,
  [SMALL_STATE(81)] = 2069,
  [SMALL_STATE(82)] = 2091,
  [SMALL_STATE(83)] = 2107,
  [SMALL_STATE(84)] = 2123,
  [SMALL_STATE(85)] = 2145,
  [SMALL_STATE(86)] = 2161,
  [SMALL_STATE(87)] = 2177,
  [SMALL_STATE(88)] = 2193,
  [SMALL_STATE(89)] = 2209,
  [SMALL_STATE(90)] = 2228,
  [SMALL_STATE(91)] = 2245,
  [SMALL_STATE(92)] = 2260,
  [SMALL_STATE(93)] = 2273,
  [SMALL_STATE(94)] = 2292,
  [SMALL_STATE(95)] = 2311,
  [SMALL_STATE(96)] = 2326,
  [SMALL_STATE(97)] = 2339,
  [SMALL_STATE(98)] = 2354,
  [SMALL_STATE(99)] = 2371,
  [SMALL_STATE(100)] = 2388,
  [SMALL_STATE(101)] = 2403,
  [SMALL_STATE(102)] = 2422,
  [SMALL_STATE(103)] = 2437,
  [SMALL_STATE(104)] = 2456,
  [SMALL_STATE(105)] = 2475,
  [SMALL_STATE(106)] = 2494,
  [SMALL_STATE(107)] = 2509,
  [SMALL_STATE(108)] = 2528,
  [SMALL_STATE(109)] = 2547,
  [SMALL_STATE(110)] = 2562,
  [SMALL_STATE(111)] = 2577,
  [SMALL_STATE(112)] = 2590,
  [SMALL_STATE(113)] = 2606,
  [SMALL_STATE(114)] = 2622,
  [SMALL_STATE(115)] = 2636,
  [SMALL_STATE(116)] = 2652,
  [SMALL_STATE(117)] = 2666,
  [SMALL_STATE(118)] = 2680,
  [SMALL_STATE(119)] = 2696,
  [SMALL_STATE(120)] = 2710,
  [SMALL_STATE(121)] = 2724,
  [SMALL_STATE(122)] = 2736,
  [SMALL_STATE(123)] = 2752,
  [SMALL_STATE(124)] = 2764,
  [SMALL_STATE(125)] = 2780,
  [SMALL_STATE(126)] = 2792,
  [SMALL_STATE(127)] = 2808,
  [SMALL_STATE(128)] = 2822,
  [SMALL_STATE(129)] = 2836,
  [SMALL_STATE(130)] = 2852,
  [SMALL_STATE(131)] = 2866,
  [SMALL_STATE(132)] = 2880,
  [SMALL_STATE(133)] = 2896,
  [SMALL_STATE(134)] = 2910,
  [SMALL_STATE(135)] = 2924,
  [SMALL_STATE(136)] = 2938,
  [SMALL_STATE(137)] = 2952,
  [SMALL_STATE(138)] = 2966,
  [SMALL_STATE(139)] = 2980,
  [SMALL_STATE(140)] = 2994,
  [SMALL_STATE(141)] = 3010,
  [SMALL_STATE(142)] = 3024,
  [SMALL_STATE(143)] = 3037,
  [SMALL_STATE(144)] = 3050,
  [SMALL_STATE(145)] = 3063,
  [SMALL_STATE(146)] = 3076,
  [SMALL_STATE(147)] = 3087,
  [SMALL_STATE(148)] = 3100,
  [SMALL_STATE(149)] = 3113,
  [SMALL_STATE(150)] = 3126,
  [SMALL_STATE(151)] = 3139,
  [SMALL_STATE(152)] = 3152,
  [SMALL_STATE(153)] = 3163,
  [SMALL_STATE(154)] = 3176,
  [SMALL_STATE(155)] = 3189,
  [SMALL_STATE(156)] = 3202,
  [SMALL_STATE(157)] = 3215,
  [SMALL_STATE(158)] = 3228,
  [SMALL_STATE(159)] = 3241,
  [SMALL_STATE(160)] = 3254,
  [SMALL_STATE(161)] = 3267,
  [SMALL_STATE(162)] = 3280,
  [SMALL_STATE(163)] = 3291,
  [SMALL_STATE(164)] = 3304,
  [SMALL_STATE(165)] = 3315,
  [SMALL_STATE(166)] = 3328,
  [SMALL_STATE(167)] = 3341,
  [SMALL_STATE(168)] = 3354,
  [SMALL_STATE(169)] = 3367,
  [SMALL_STATE(170)] = 3380,
  [SMALL_STATE(171)] = 3393,
  [SMALL_STATE(172)] = 3406,
  [SMALL_STATE(173)] = 3417,
  [SMALL_STATE(174)] = 3430,
  [SMALL_STATE(175)] = 3443,
  [SMALL_STATE(176)] = 3456,
  [SMALL_STATE(177)] = 3469,
  [SMALL_STATE(178)] = 3482,
  [SMALL_STATE(179)] = 3495,
  [SMALL_STATE(180)] = 3508,
  [SMALL_STATE(181)] = 3521,
  [SMALL_STATE(182)] = 3532,
  [SMALL_STATE(183)] = 3545,
  [SMALL_STATE(184)] = 3556,
  [SMALL_STATE(185)] = 3566,
  [SMALL_STATE(186)] = 3576,
  [SMALL_STATE(187)] = 3586,
  [SMALL_STATE(188)] = 3596,
  [SMALL_STATE(189)] = 3606,
  [SMALL_STATE(190)] = 3616,
  [SMALL_STATE(191)] = 3626,
  [SMALL_STATE(192)] = 3636,
  [SMALL_STATE(193)] = 3646,
  [SMALL_STATE(194)] = 3656,
  [SMALL_STATE(195)] = 3666,
  [SMALL_STATE(196)] = 3676,
  [SMALL_STATE(197)] = 3686,
  [SMALL_STATE(198)] = 3696,
  [SMALL_STATE(199)] = 3706,
  [SMALL_STATE(200)] = 3716,
  [SMALL_STATE(201)] = 3726,
  [SMALL_STATE(202)] = 3736,
  [SMALL_STATE(203)] = 3746,
  [SMALL_STATE(204)] = 3756,
  [SMALL_STATE(205)] = 3766,
  [SMALL_STATE(206)] = 3776,
  [SMALL_STATE(207)] = 3786,
  [SMALL_STATE(208)] = 3796,
  [SMALL_STATE(209)] = 3806,
  [SMALL_STATE(210)] = 3816,
  [SMALL_STATE(211)] = 3826,
  [SMALL_STATE(212)] = 3836,
  [SMALL_STATE(213)] = 3846,
  [SMALL_STATE(214)] = 3856,
  [SMALL_STATE(215)] = 3866,
  [SMALL_STATE(216)] = 3876,
  [SMALL_STATE(217)] = 3886,
  [SMALL_STATE(218)] = 3896,
  [SMALL_STATE(219)] = 3906,
  [SMALL_STATE(220)] = 3916,
  [SMALL_STATE(221)] = 3926,
  [SMALL_STATE(222)] = 3936,
  [SMALL_STATE(223)] = 3946,
  [SMALL_STATE(224)] = 3956,
  [SMALL_STATE(225)] = 3966,
  [SMALL_STATE(226)] = 3976,
  [SMALL_STATE(227)] = 3986,
  [SMALL_STATE(228)] = 3996,
  [SMALL_STATE(229)] = 4006,
  [SMALL_STATE(230)] = 4016,
  [SMALL_STATE(231)] = 4026,
  [SMALL_STATE(232)] = 4036,
  [SMALL_STATE(233)] = 4046,
  [SMALL_STATE(234)] = 4056,
  [SMALL_STATE(235)] = 4066,
  [SMALL_STATE(236)] = 4076,
  [SMALL_STATE(237)] = 4086,
  [SMALL_STATE(238)] = 4096,
  [SMALL_STATE(239)] = 4106,
  [SMALL_STATE(240)] = 4116,
  [SMALL_STATE(241)] = 4126,
  [SMALL_STATE(242)] = 4136,
  [SMALL_STATE(243)] = 4146,
  [SMALL_STATE(244)] = 4156,
  [SMALL_STATE(245)] = 4166,
  [SMALL_STATE(246)] = 4176,
  [SMALL_STATE(247)] = 4186,
  [SMALL_STATE(248)] = 4196,
  [SMALL_STATE(249)] = 4206,
  [SMALL_STATE(250)] = 4216,
  [SMALL_STATE(251)] = 4226,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(22),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(6),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(7),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(112),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(53),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(62),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(26),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(27),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(8),
  [76] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(28),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(105),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(104),
  [85] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(217),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(103),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(34),
  [97] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(165),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(213),
  [103] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(210),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(208),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_env_pair, 2, .production_id = 1),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(144),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_env_pair, 2, .production_id = 1),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(251),
  [125] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_name_repeat1, 2),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_name_repeat1, 2),
  [133] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_name_repeat1, 2), SHIFT_REPEAT(169),
  [136] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_name_repeat1, 2), SHIFT_REPEAT(42),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_name, 2),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_name, 2),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [145] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_name, 1),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_name, 1),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquoted_string, 1),
  [159] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquoted_string, 1),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_unquoted_string_repeat1, 2),
  [165] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 2), SHIFT_REPEAT(148),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 2),
  [170] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_unquoted_string_repeat1, 2), SHIFT_REPEAT(75),
  [173] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 2), SHIFT_REPEAT(144),
  [176] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_unquoted_string_repeat1, 2), SHIFT_REPEAT(80),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_tag_repeat1, 2),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_tag_repeat1, 2),
  [189] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_tag_repeat1, 2), SHIFT_REPEAT(156),
  [192] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_tag_repeat1, 2), SHIFT_REPEAT(88),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_tag, 2),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_tag, 2),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(156),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [215] = {.entry = {.count = 1, .reusable = false}}, SHIFT(146),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [219] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 1, .production_id = 1),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 1, .production_id = 1),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2),
  [233] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(92),
  [236] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(163),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expose_instruction_repeat1, 2),
  [241] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_expose_instruction_repeat1, 2), SHIFT_REPEAT(167),
  [244] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_expose_instruction_repeat1, 2), SHIFT_REPEAT(77),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_command_repeat1, 2),
  [253] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_shell_command_repeat1, 2), SHIFT_REPEAT(202),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(180),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_path, 1),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [262] = {.entry = {.count = 1, .reusable = false}}, SHIFT(163),
  [264] = {.entry = {.count = 1, .reusable = false}}, SHIFT(162),
  [266] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2), SHIFT_REPEAT(153),
  [269] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2),
  [271] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2), SHIFT_REPEAT(95),
  [274] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2), SHIFT_REPEAT(95),
  [277] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_path, 2),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expansion, 4),
  [281] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expansion, 4),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_name_repeat1, 1),
  [285] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_name_repeat1, 1),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expansion, 2),
  [289] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expansion, 2),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__user_name_or_group, 2),
  [293] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__user_name_or_group, 2), SHIFT_REPEAT(106),
  [296] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__user_name_or_group, 2), SHIFT_REPEAT(167),
  [299] = {.entry = {.count = 1, .reusable = false}}, SHIFT(178),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expose_instruction, 2),
  [303] = {.entry = {.count = 1, .reusable = false}}, SHIFT(167),
  [305] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_digest_repeat1, 2),
  [309] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_digest_repeat1, 2),
  [311] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_digest_repeat1, 2), SHIFT_REPEAT(155),
  [314] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_image_digest_repeat1, 2), SHIFT_REPEAT(91),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_digest, 2),
  [319] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_digest, 2),
  [321] = {.entry = {.count = 1, .reusable = false}}, SHIFT(155),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [325] = {.entry = {.count = 1, .reusable = false}}, SHIFT(174),
  [327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_instruction, 2, .production_id = 3),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [331] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_env_instruction_repeat1, 2),
  [335] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_env_instruction_repeat1, 2), SHIFT_REPEAT(205),
  [338] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(117),
  [341] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(166),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [350] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stopsignal_value, 2),
  [352] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__stopsignal_value, 2), SHIFT_REPEAT(138),
  [355] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__stopsignal_value, 2), SHIFT_REPEAT(160),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_env_instruction, 2),
  [360] = {.entry = {.count = 1, .reusable = false}}, SHIFT(205),
  [362] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [364] = {.entry = {.count = 1, .reusable = false}}, SHIFT(166),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 1),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_alias_repeat1, 2),
  [372] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_alias_repeat1, 2), SHIFT_REPEAT(143),
  [375] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_alias_repeat1, 2), SHIFT_REPEAT(120),
  [378] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(139),
  [381] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(161),
  [384] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_add_instruction_repeat1, 2), SHIFT_REPEAT(56),
  [387] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_instruction_repeat1, 2), SHIFT_REPEAT(166),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 2),
  [392] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [394] = {.entry = {.count = 1, .reusable = false}}, SHIFT(161),
  [396] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_instruction, 4, .production_id = 11),
  [398] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stopsignal_instruction, 2),
  [400] = {.entry = {.count = 1, .reusable = false}}, SHIFT(138),
  [402] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [404] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_alias, 1),
  [406] = {.entry = {.count = 1, .reusable = false}}, SHIFT(143),
  [408] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [410] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_unquoted_string_repeat1, 1),
  [412] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 1),
  [414] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expose_port, 1),
  [416] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expose_port, 1),
  [418] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [424] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_tag_repeat1, 1),
  [426] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_tag_repeat1, 1),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_fragment, 1),
  [432] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [434] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_shell_fragment, 1),
  [436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_digest_repeat1, 1),
  [438] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_digest_repeat1, 1),
  [440] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 1),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [444] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 2, .production_id = 5),
  [446] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 2, .production_id = 5),
  [448] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 1),
  [450] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 1),
  [452] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_fragment_repeat1, 2),
  [454] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_shell_fragment_repeat1, 2), SHIFT_REPEAT(97),
  [457] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_shell_fragment_repeat1, 2),
  [459] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_label_instruction_repeat1, 2),
  [461] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_label_instruction_repeat1, 2), SHIFT_REPEAT(198),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_healthcheck_instruction_repeat1, 2),
  [466] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_healthcheck_instruction_repeat1, 2), SHIFT_REPEAT(250),
  [469] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_instruction, 2),
  [471] = {.entry = {.count = 1, .reusable = false}}, SHIFT(198),
  [473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [477] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [479] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [483] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__user_name_or_group, 1),
  [485] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__user_name_or_group, 1),
  [487] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [489] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_volume_instruction, 3),
  [491] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [493] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_array_repeat1, 2), SHIFT_REPEAT(154),
  [496] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_array_repeat1, 2),
  [498] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_command, 1),
  [500] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [502] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expose_port, 2),
  [504] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expose_port, 2),
  [506] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 1),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [512] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_alias_repeat1, 1),
  [514] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_alias_repeat1, 1),
  [516] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_command_repeat1, 1),
  [518] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_command, 2),
  [520] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__comment_line, 2),
  [522] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_required_line_continuation, 1),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [530] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_command_repeat2, 2),
  [532] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_shell_command_repeat2, 2), SHIFT_REPEAT(125),
  [535] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_command, 3),
  [537] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expose_instruction_repeat1, 1),
  [539] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_expose_instruction_repeat1, 1),
  [541] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_volume_instruction_repeat1, 2),
  [543] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_volume_instruction_repeat1, 2), SHIFT_REPEAT(107),
  [546] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stopsignal_value, 1),
  [548] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__stopsignal_value, 1),
  [550] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_volume_instruction, 2),
  [552] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_instruction, 2, .production_id = 4),
  [554] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [556] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [558] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [560] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [562] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [564] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_pair, 3, .production_id = 9),
  [566] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label_pair, 3, .production_id = 9),
  [568] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 2),
  [570] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_env_pair, 3, .production_id = 10),
  [572] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_env_pair, 3, .production_id = 10),
  [574] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [578] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_instruction, 3),
  [580] = {.entry = {.count = 1, .reusable = false}}, SHIFT(168),
  [582] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_instruction, 4),
  [584] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_copy_instruction, 4),
  [586] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [590] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [592] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [594] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [596] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [598] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param, 4, .production_id = 13),
  [600] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_param, 4, .production_id = 13),
  [602] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_copy_instruction, 3),
  [604] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 3, .production_id = 8),
  [606] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 3, .production_id = 8),
  [608] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [610] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [612] = {.entry = {.count = 1, .reusable = true}}, SHIFT(241),
  [614] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [616] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 3),
  [618] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [620] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [622] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [624] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [626] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [628] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [630] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_add_instruction_repeat1, 2),
  [632] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_instruction_repeat1, 2),
  [634] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [636] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [638] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 2),
  [640] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [642] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_label_instruction_repeat1, 1),
  [644] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_label_instruction_repeat1, 1),
  [646] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__env_key, 1),
  [648] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 3),
  [650] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [652] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 2),
  [654] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 2, .production_id = 6),
  [656] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 2, .production_id = 6),
  [658] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_env_instruction_repeat1, 1),
  [660] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_env_instruction_repeat1, 1),
  [662] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [664] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [666] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 3),
  [668] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_healthcheck_instruction_repeat1, 1),
  [670] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_healthcheck_instruction, 2),
  [672] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_onbuild_instruction, 2),
  [674] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_instruction, 2),
  [676] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_workdir_instruction, 2),
  [678] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_volume_instruction, 2),
  [680] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_maintainer_instruction, 2),
  [682] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cross_build_instruction, 2),
  [684] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entrypoint_instruction, 2),
  [686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [688] = {.entry = {.count = 1, .reusable = false}}, SHIFT(230),
  [690] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_env_instruction, 2, .production_id = 2),
  [692] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [694] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_array, 2),
  [696] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__anon_comment, 2),
  [698] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [700] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cmd_instruction, 2),
  [702] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [704] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_run_instruction, 2),
  [706] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [708] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [710] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__instruction, 1),
  [712] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [714] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [716] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_command_repeat2, 3),
  [718] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_shell_command_repeat2, 3),
  [720] = {.entry = {.count = 1, .reusable = false}}, SHIFT(190),
  [722] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [724] = {.entry = {.count = 1, .reusable = false}}, SHIFT(179),
  [726] = {.entry = {.count = 1, .reusable = false}}, SHIFT(189),
  [728] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_array, 4),
  [730] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [732] = {.entry = {.count = 1, .reusable = false}}, SHIFT(181),
  [734] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [736] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_healthcheck_instruction, 3),
  [738] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [740] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 5, .production_id = 14),
  [742] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [744] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [746] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [748] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_shell_command_repeat2, 2),
  [750] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [752] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_array, 3),
  [754] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [756] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_instruction, 4, .production_id = 12),
  [758] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [760] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [762] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [764] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__spaced_env_pair, 3, .production_id = 10),
  [766] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [768] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 4, .production_id = 7),
  [770] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [772] = {.entry = {.count = 1, .reusable = false}}, SHIFT(211),
  [774] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [776] = {.entry = {.count = 1, .reusable = false}}, SHIFT(215),
  [778] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [780] = {.entry = {.count = 1, .reusable = false}}, SHIFT(219),
  [782] = {.entry = {.count = 1, .reusable = false}}, SHIFT(221),
  [784] = {.entry = {.count = 1, .reusable = false}}, SHIFT(223),
  [786] = {.entry = {.count = 1, .reusable = false}}, SHIFT(225),
  [788] = {.entry = {.count = 1, .reusable = false}}, SHIFT(227),
  [790] = {.entry = {.count = 1, .reusable = false}}, SHIFT(229),
  [792] = {.entry = {.count = 1, .reusable = false}}, SHIFT(231),
  [794] = {.entry = {.count = 1, .reusable = false}}, SHIFT(233),
  [796] = {.entry = {.count = 1, .reusable = false}}, SHIFT(235),
  [798] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [800] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [802] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line_continuation, 1),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_dockerfile(void) {
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
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
