#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 265
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 124
#define ALIAS_COUNT 0
#define TOKEN_COUNT 63
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 6
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
  aux_sym__user_name_group_token1 = 15,
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
  aux_sym_image_tag_token1 = 43,
  anon_sym_AT = 44,
  aux_sym_image_digest_token1 = 45,
  anon_sym_DASH_DASH = 46,
  aux_sym_param_token1 = 47,
  aux_sym_param_token2 = 48,
  aux_sym_image_alias_token1 = 49,
  anon_sym_LBRACK = 50,
  anon_sym_COMMA = 51,
  anon_sym_RBRACK = 52,
  aux_sym_shell_fragment_token1 = 53,
  aux_sym_shell_fragment_token2 = 54,
  sym_line_continuation = 55,
  anon_sym_POUND = 56,
  anon_sym_DQUOTE = 57,
  aux_sym_double_quoted_string_token1 = 58,
  aux_sym_unquoted_string_token1 = 59,
  anon_sym_BSLASH = 60,
  sym_escape_sequence = 61,
  sym__non_newline_whitespace = 62,
  sym_source_file = 63,
  sym__instruction = 64,
  sym_from_instruction = 65,
  sym_run_instruction = 66,
  sym_cmd_instruction = 67,
  sym_label_instruction = 68,
  sym_expose_instruction = 69,
  sym_env_instruction = 70,
  sym_add_instruction = 71,
  sym_copy_instruction = 72,
  sym_entrypoint_instruction = 73,
  sym_volume_instruction = 74,
  sym_user_instruction = 75,
  aux_sym__user_name_group = 76,
  sym_workdir_instruction = 77,
  sym_arg_instruction = 78,
  sym_onbuild_instruction = 79,
  sym_stopsignal_instruction = 80,
  aux_sym__stopsignal_value = 81,
  sym_healthcheck_instruction = 82,
  sym_shell_instruction = 83,
  sym_maintainer_instruction = 84,
  sym_cross_build_instruction = 85,
  sym_path = 86,
  sym_expansion = 87,
  sym_env_pair = 88,
  sym__spaced_env_pair = 89,
  sym__env_key = 90,
  sym_expose_port = 91,
  sym_label_pair = 92,
  sym_image_spec = 93,
  sym_image_name = 94,
  sym_image_tag = 95,
  sym_image_digest = 96,
  sym_param = 97,
  sym_image_alias = 98,
  sym_string_array = 99,
  sym_shell_command = 100,
  sym_shell_fragment = 101,
  sym__comment_line = 102,
  sym__anon_comment = 103,
  sym_double_quoted_string = 104,
  sym_unquoted_string = 105,
  sym_comment = 106,
  aux_sym_source_file_repeat1 = 107,
  aux_sym_label_instruction_repeat1 = 108,
  aux_sym_expose_instruction_repeat1 = 109,
  aux_sym_env_instruction_repeat1 = 110,
  aux_sym_volume_instruction_repeat1 = 111,
  aux_sym_healthcheck_instruction_repeat1 = 112,
  aux_sym_path_repeat1 = 113,
  aux_sym_image_name_repeat1 = 114,
  aux_sym_image_tag_repeat1 = 115,
  aux_sym_image_digest_repeat1 = 116,
  aux_sym_image_alias_repeat1 = 117,
  aux_sym_string_array_repeat1 = 118,
  aux_sym_shell_command_repeat1 = 119,
  aux_sym_shell_command_repeat2 = 120,
  aux_sym_shell_fragment_repeat1 = 121,
  aux_sym_double_quoted_string_repeat1 = 122,
  aux_sym_unquoted_string_repeat1 = 123,
};

static const char *ts_symbol_names[] = {
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
  [aux_sym__user_name_group_token1] = "_user_name_group_token1",
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
  [sym_line_continuation] = "line_continuation",
  [anon_sym_POUND] = "#",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_double_quoted_string_token1] = "double_quoted_string_token1",
  [aux_sym_unquoted_string_token1] = "unquoted_string_token1",
  [anon_sym_BSLASH] = "\\ ",
  [sym_escape_sequence] = "escape_sequence",
  [sym__non_newline_whitespace] = "_non_newline_whitespace",
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
  [aux_sym__user_name_group] = "_user_name_group",
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
  [sym__comment_line] = "_comment_line",
  [sym__anon_comment] = "comment",
  [sym_double_quoted_string] = "double_quoted_string",
  [sym_unquoted_string] = "unquoted_string",
  [sym_comment] = "comment",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_label_instruction_repeat1] = "label_instruction_repeat1",
  [aux_sym_expose_instruction_repeat1] = "expose_instruction_repeat1",
  [aux_sym_env_instruction_repeat1] = "env_instruction_repeat1",
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

static TSSymbol ts_symbol_map[] = {
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
  [aux_sym__user_name_group_token1] = aux_sym__user_name_group_token1,
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
  [sym_line_continuation] = sym_line_continuation,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_double_quoted_string_token1] = aux_sym_double_quoted_string_token1,
  [aux_sym_unquoted_string_token1] = aux_sym_unquoted_string_token1,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym__non_newline_whitespace] = sym__non_newline_whitespace,
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
  [aux_sym__user_name_group] = aux_sym__user_name_group,
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
  [sym__comment_line] = sym__comment_line,
  [sym__anon_comment] = sym_comment,
  [sym_double_quoted_string] = sym_double_quoted_string,
  [sym_unquoted_string] = sym_unquoted_string,
  [sym_comment] = sym_comment,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_label_instruction_repeat1] = aux_sym_label_instruction_repeat1,
  [aux_sym_expose_instruction_repeat1] = aux_sym_expose_instruction_repeat1,
  [aux_sym_env_instruction_repeat1] = aux_sym_env_instruction_repeat1,
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
  [aux_sym__user_name_group_token1] = {
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
  [sym_line_continuation] = {
    .visible = true,
    .named = true,
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
  [aux_sym__user_name_group] = {
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
  [sym_comment] = {
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

static const char *ts_field_names[] = {
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
    {field_name, 2, .inherited = true},
    {field_value, 2, .inherited = true},
  [3] =
    {field_user, 2},
  [4] =
    {field_name, 2},
  [5] =
    {field_name, 0},
    {field_tag, 1},
  [7] =
    {field_digest, 1},
    {field_name, 0},
  [9] =
    {field_as, 4},
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
    {field_group, 4},
    {field_user, 2},
  [19] =
    {field_default, 4},
    {field_name, 2},
  [21] =
    {field_name, 1},
    {field_value, 3},
  [23] =
    {field_as, 5},
};

static TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [3] = {
    [2] = sym_unquoted_string,
  },
  [11] = {
    [2] = sym_unquoted_string,
    [4] = sym_unquoted_string,
  },
};

static uint16_t ts_non_terminal_alias_map[] = {
  aux_sym__user_name_group, 2,
    aux_sym__user_name_group,
    sym_unquoted_string,
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(162);
      if (lookahead == '"') ADVANCE(243);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == ',') ADVANCE(229);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == ':') ADVANCE(177);
      if (lookahead == '=') ADVANCE(183);
      if (lookahead == '@') ADVANCE(219);
      if (lookahead == '[') ADVANCE(228);
      if (lookahead == '\\') ADVANCE(196);
      if (lookahead == ']') ADVANCE(230);
      if (lookahead == '{') ADVANCE(200);
      if (lookahead == '}') ADVANCE(204);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(161)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      if (lookahead != 0) ADVANCE(195);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(233);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead == ' ') ADVANCE(249);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead == 'U') ADVANCE(158);
      if (lookahead == 'u') ADVANCE(154);
      if (lookahead == 'x') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(252);
      if (lookahead != 0) ADVANCE(250);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead != 0) ADVANCE(232);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '/') ADVANCE(61);
      if (lookahead == ':') ADVANCE(177);
      if (lookahead == '=') ADVANCE(183);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(208);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(179);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '/') ADVANCE(61);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(208);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(220);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('0' <= lookahead && lookahead <= ':') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(136);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(9)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(10)
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(227);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(12)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == ':') ADVANCE(177);
      if (lookahead == '@') ADVANCE(219);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(136);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      END_STATE();
    case 14:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(136);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      END_STATE();
    case 15:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 16:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(16)
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 17:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (lookahead != 0 &&
          lookahead != '[') ADVANCE(231);
      END_STATE();
    case 18:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(237);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == ':') ADVANCE(177);
      if (lookahead == '@') ADVANCE(219);
      if (lookahead == '\\') ADVANCE(212);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(214);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (lookahead != 0) ADVANCE(215);
      END_STATE();
    case 19:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(236);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(9)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(246);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(248);
      END_STATE();
    case 20:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(236);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(10)
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(248);
      END_STATE();
    case 21:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(238);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '@') ADVANCE(219);
      if (lookahead == '\\') ADVANCE(216);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(217);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (lookahead != 0) ADVANCE(218);
      END_STATE();
    case 22:
      if (lookahead == '\n') ADVANCE(163);
      if (lookahead == '#') ADVANCE(239);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(197);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(22)
      if (lookahead != 0) ADVANCE(198);
      END_STATE();
    case 23:
      if (lookahead == '\n') SKIP(26)
      if (lookahead == '"') ADVANCE(243);
      if (lookahead == '#') ADVANCE(245);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(244);
      if (lookahead != 0) ADVANCE(245);
      END_STATE();
    case 24:
      if (lookahead == '\n') ADVANCE(164);
      if (lookahead == '\r') SKIP(24)
      if (lookahead == '#') ADVANCE(239);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(197);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(253);
      if (lookahead != 0) ADVANCE(198);
      END_STATE();
    case 25:
      if (lookahead == '\n') ADVANCE(164);
      if (lookahead == '\r') SKIP(25)
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(253);
      END_STATE();
    case 26:
      if (lookahead == '"') ADVANCE(243);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(26)
      END_STATE();
    case 27:
      if (lookahead == '"') ADVANCE(243);
      if (lookahead == '#') ADVANCE(236);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(26)
      if (lookahead != 0) ADVANCE(248);
      END_STATE();
    case 28:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == '\\') ADVANCE(196);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(28)
      if (lookahead != 0) ADVANCE(195);
      END_STATE();
    case 29:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(29)
      END_STATE();
    case 30:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '[') ADVANCE(228);
      if (lookahead == '\\') ADVANCE(196);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(30)
      if (lookahead != 0 &&
          lookahead != '-') ADVANCE(195);
      END_STATE();
    case 31:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(31)
      END_STATE();
    case 32:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(31)
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      END_STATE();
    case 33:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(33)
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(227);
      END_STATE();
    case 34:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(35)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      END_STATE();
    case 35:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(35)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      END_STATE();
    case 36:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '=') ADVANCE(183);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(206);
      END_STATE();
    case 37:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '[') ADVANCE(228);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(37)
      if (lookahead != 0) ADVANCE(231);
      END_STATE();
    case 38:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '{') ADVANCE(200);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(38)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 39:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(254);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(39)
      END_STATE();
    case 40:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(40)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 41:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(41)
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 42:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(42)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(182);
      END_STATE();
    case 43:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(43)
      END_STATE();
    case 44:
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(43)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 45:
      if (lookahead == '#') ADVANCE(237);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '-') ADVANCE(213);
      if (lookahead == '\\') ADVANCE(212);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(29)
      if (lookahead != 0 &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(215);
      END_STATE();
    case 46:
      if (lookahead == '#') ADVANCE(237);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(212);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(31)
      if (lookahead != 0 &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(215);
      END_STATE();
    case 47:
      if (lookahead == '#') ADVANCE(238);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(216);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(31)
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(218);
      END_STATE();
    case 48:
      if (lookahead == '#') ADVANCE(239);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == '\\') ADVANCE(197);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(254);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(48)
      if (lookahead != 0) ADVANCE(198);
      END_STATE();
    case 49:
      if (lookahead == '#') ADVANCE(242);
      if (lookahead == '\\') ADVANCE(201);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(203);
      END_STATE();
    case 50:
      if (lookahead == '#') ADVANCE(240);
      if (lookahead == '\\') ADVANCE(225);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(43)
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 51:
      if (lookahead == '-') ADVANCE(222);
      END_STATE();
    case 52:
      if (lookahead == 'E') ADVANCE(188);
      END_STATE();
    case 53:
      if (lookahead == 'N') ADVANCE(52);
      END_STATE();
    case 54:
      if (lookahead == 'O') ADVANCE(53);
      END_STATE();
    case 55:
      if (lookahead == '_') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(207);
      END_STATE();
    case 56:
      if (lookahead == '_') ADVANCE(69);
      END_STATE();
    case 57:
      if (lookahead == 'c') ADVANCE(59);
      END_STATE();
    case 58:
      if (lookahead == 'd') ADVANCE(60);
      END_STATE();
    case 59:
      if (lookahead == 'p') ADVANCE(209);
      END_STATE();
    case 60:
      if (lookahead == 'p') ADVANCE(210);
      END_STATE();
    case 61:
      if (lookahead == 't') ADVANCE(57);
      if (lookahead == 'u') ADVANCE(58);
      END_STATE();
    case 62:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(68);
      END_STATE();
    case 63:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(92);
      END_STATE();
    case 64:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(100);
      END_STATE();
    case 65:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(103);
      END_STATE();
    case 66:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(93);
      END_STATE();
    case 67:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(146);
      END_STATE();
    case 68:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(84);
      END_STATE();
    case 69:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(148);
      END_STATE();
    case 70:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(98);
      END_STATE();
    case 71:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(90);
      END_STATE();
    case 72:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(73);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 73:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(172);
      END_STATE();
    case 74:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(168);
      END_STATE();
    case 75:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(184);
      END_STATE();
    case 76:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(194);
      END_STATE();
    case 77:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(94);
      END_STATE();
    case 78:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(170);
      END_STATE();
    case 79:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(175);
      END_STATE();
    case 80:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(70);
      END_STATE();
    case 81:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 82:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(107);
      END_STATE();
    case 83:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(130);
      END_STATE();
    case 84:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(101);
      END_STATE();
    case 85:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(132);
      END_STATE();
    case 86:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(181);
      END_STATE();
    case 87:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(116);
      END_STATE();
    case 88:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(71);
      END_STATE();
    case 89:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(82);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(122);
      END_STATE();
    case 90:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(80);
      END_STATE();
    case 91:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(87);
      END_STATE();
    case 92:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(114);
      END_STATE();
    case 93:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(117);
      END_STATE();
    case 94:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(131);
      END_STATE();
    case 95:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(115);
      END_STATE();
    case 96:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(105);
      END_STATE();
    case 97:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(106);
      END_STATE();
    case 98:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(187);
      END_STATE();
    case 99:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(77);
      END_STATE();
    case 100:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(141);
      END_STATE();
    case 101:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(169);
      END_STATE();
    case 102:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(189);
      END_STATE();
    case 103:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(185);
      END_STATE();
    case 104:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(147);
      END_STATE();
    case 105:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(75);
      END_STATE();
    case 106:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(76);
      END_STATE();
    case 107:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(102);
      END_STATE();
    case 108:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(165);
      END_STATE();
    case 109:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(74);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(125);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(121);
      END_STATE();
    case 110:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(79);
      END_STATE();
    case 111:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(143);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(127);
      END_STATE();
    case 112:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(167);
      END_STATE();
    case 113:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(67);
      END_STATE();
    case 114:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(144);
      END_STATE();
    case 115:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(142);
      END_STATE();
    case 116:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(65);
      END_STATE();
    case 117:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(85);
      END_STATE();
    case 118:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(104);
      END_STATE();
    case 119:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(108);
      END_STATE();
    case 120:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(129);
      END_STATE();
    case 121:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(138);
      END_STATE();
    case 122:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(126);
      END_STATE();
    case 123:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(140);
      END_STATE();
    case 124:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(95);
      END_STATE();
    case 125:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(149);
      END_STATE();
    case 126:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(139);
      END_STATE();
    case 127:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(123);
      END_STATE();
    case 128:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(124);
      END_STATE();
    case 129:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(99);
      END_STATE();
    case 130:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(176);
      END_STATE();
    case 131:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(180);
      END_STATE();
    case 132:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(190);
      END_STATE();
    case 133:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(150);
      END_STATE();
    case 134:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(119);
      END_STATE();
    case 135:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(56);
      END_STATE();
    case 136:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(166);
      END_STATE();
    case 137:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(83);
      END_STATE();
    case 138:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(135);
      END_STATE();
    case 139:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(91);
      END_STATE();
    case 140:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(78);
      END_STATE();
    case 141:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(88);
      END_STATE();
    case 142:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(174);
      END_STATE();
    case 143:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(133);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(171);
      END_STATE();
    case 144:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(66);
      END_STATE();
    case 145:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(112);
      END_STATE();
    case 146:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(96);
      END_STATE();
    case 147:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(110);
      END_STATE();
    case 148:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(97);
      END_STATE();
    case 149:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(173);
      END_STATE();
    case 150:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(128);
      END_STATE();
    case 151:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(250);
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
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(155);
      END_STATE();
    case 157:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(156);
      END_STATE();
    case 158:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      END_STATE();
    case 159:
      if (eof) ADVANCE(162);
      if (lookahead == '"') ADVANCE(243);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == ',') ADVANCE(229);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == '=') ADVANCE(183);
      if (lookahead == 'N') ADVANCE(54);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == ']') ADVANCE(230);
      if (lookahead == '}') ADVANCE(204);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(72);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(109);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(111);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(134);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(81);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(62);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(63);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(113);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(145);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(89);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(137);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(118);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(120);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(160)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(208);
      END_STATE();
    case 160:
      if (eof) ADVANCE(162);
      if (lookahead == '"') ADVANCE(243);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == ',') ADVANCE(229);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == 'N') ADVANCE(54);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == ']') ADVANCE(230);
      if (lookahead == '}') ADVANCE(204);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(72);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(109);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(111);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(134);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(81);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(62);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(63);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(113);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(145);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(89);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(137);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(118);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(120);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(160)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(208);
      END_STATE();
    case 161:
      if (eof) ADVANCE(162);
      if (lookahead == '"') ADVANCE(243);
      if (lookahead == '#') ADVANCE(235);
      if (lookahead == '$') ADVANCE(199);
      if (lookahead == ',') ADVANCE(229);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == '[') ADVANCE(228);
      if (lookahead == '\\') ADVANCE(196);
      if (lookahead == ']') ADVANCE(230);
      if (lookahead == '{') ADVANCE(200);
      if (lookahead == '}') ADVANCE(204);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(161)
      if (lookahead != 0) ADVANCE(195);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(163);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(164);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(253);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_from_instruction_token1);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_from_instruction_token2);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_run_instruction_token1);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_cmd_instruction_token1);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_label_instruction_token1);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_expose_instruction_token1);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_env_instruction_token1);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_add_instruction_token1);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_copy_instruction_token1);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_entrypoint_instruction_token1);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_volume_instruction_token1);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_user_instruction_token1);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym__user_name_group_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(179);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym__user_name_group_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(179);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_workdir_instruction_token1);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_arg_instruction_token1);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_arg_instruction_token2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(182);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_onbuild_instruction_token1);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_stopsignal_instruction_token1);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym__stopsignal_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_healthcheck_instruction_token1);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_NONE);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_shell_instruction_token1);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token1);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token2);
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead != 0) ADVANCE(193);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token2);
      if (lookahead == '#') ADVANCE(241);
      if (lookahead == '\\') ADVANCE(191);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(192);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(193);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(193);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_cross_build_instruction_token1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(194);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_path_token1);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_path_token1);
      if (lookahead == '\n') ADVANCE(233);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_path_token2);
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$') ADVANCE(198);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_path_token2);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$') ADVANCE(198);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_expansion_token1);
      if (lookahead == '\n') ADVANCE(234);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(203);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_expansion_token1);
      if (lookahead == '#') ADVANCE(242);
      if (lookahead == '\\') ADVANCE(201);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(203);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_expansion_token1);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(203);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_variable);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(205);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym__spaced_env_pair_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(206);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym__env_key_token1);
      if (lookahead == '_') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(207);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_expose_port_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(208);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_SLASHtcp);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_SLASHudp);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_label_pair_token1);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(211);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_image_name_token1);
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(215);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_image_name_token1);
      if (lookahead == '-') ADVANCE(223);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(215);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_image_name_token1);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(215);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_image_name_token1);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(215);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_image_tag_token1);
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != '@') ADVANCE(218);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_image_tag_token1);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != '@') ADVANCE(218);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_image_tag_token1);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != '@') ADVANCE(218);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_image_digest_token1);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_image_digest_token1);
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(215);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(aux_sym_param_token1);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(224);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(aux_sym_param_token2);
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(226);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(aux_sym_param_token2);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(226);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(aux_sym_image_alias_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(227);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_shell_fragment_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\\') ADVANCE(231);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(aux_sym_shell_fragment_token2);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_line_continuation);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_line_continuation);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(203);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(248);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(215);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != '@') ADVANCE(218);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '$') ADVANCE(198);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(226);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(193);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(203);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '#') ADVANCE(245);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(244);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          (lookahead < '"' || '$' < lookahead) &&
          lookahead != '\\') ADVANCE(245);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(245);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(aux_sym_unquoted_string_token1);
      if (lookahead == '_') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(246);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(248);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_unquoted_string_token1);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(248);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_unquoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(248);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(250);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(251);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym__non_newline_whitespace);
      if (lookahead == '\n') ADVANCE(164);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(253);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym__non_newline_whitespace);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(254);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 159},
  [2] = {.lex_state = 159},
  [3] = {.lex_state = 159},
  [4] = {.lex_state = 159},
  [5] = {.lex_state = 159},
  [6] = {.lex_state = 18},
  [7] = {.lex_state = 45},
  [8] = {.lex_state = 18},
  [9] = {.lex_state = 27},
  [10] = {.lex_state = 27},
  [11] = {.lex_state = 27},
  [12] = {.lex_state = 27},
  [13] = {.lex_state = 37},
  [14] = {.lex_state = 37},
  [15] = {.lex_state = 21},
  [16] = {.lex_state = 19},
  [17] = {.lex_state = 37},
  [18] = {.lex_state = 37},
  [19] = {.lex_state = 19},
  [20] = {.lex_state = 20},
  [21] = {.lex_state = 37},
  [22] = {.lex_state = 21},
  [23] = {.lex_state = 20},
  [24] = {.lex_state = 5},
  [25] = {.lex_state = 23},
  [26] = {.lex_state = 18},
  [27] = {.lex_state = 24},
  [28] = {.lex_state = 24},
  [29] = {.lex_state = 18},
  [30] = {.lex_state = 23},
  [31] = {.lex_state = 7},
  [32] = {.lex_state = 7},
  [33] = {.lex_state = 24},
  [34] = {.lex_state = 5},
  [35] = {.lex_state = 5},
  [36] = {.lex_state = 28},
  [37] = {.lex_state = 28},
  [38] = {.lex_state = 23},
  [39] = {.lex_state = 30},
  [40] = {.lex_state = 46},
  [41] = {.lex_state = 13},
  [42] = {.lex_state = 23},
  [43] = {.lex_state = 18},
  [44] = {.lex_state = 159},
  [45] = {.lex_state = 5},
  [46] = {.lex_state = 23},
  [47] = {.lex_state = 23},
  [48] = {.lex_state = 23},
  [49] = {.lex_state = 11},
  [50] = {.lex_state = 5},
  [51] = {.lex_state = 20},
  [52] = {.lex_state = 19},
  [53] = {.lex_state = 33},
  [54] = {.lex_state = 48},
  [55] = {.lex_state = 5},
  [56] = {.lex_state = 159},
  [57] = {.lex_state = 40},
  [58] = {.lex_state = 5},
  [59] = {.lex_state = 21},
  [60] = {.lex_state = 11},
  [61] = {.lex_state = 12},
  [62] = {.lex_state = 37},
  [63] = {.lex_state = 19},
  [64] = {.lex_state = 48},
  [65] = {.lex_state = 22},
  [66] = {.lex_state = 22},
  [67] = {.lex_state = 5},
  [68] = {.lex_state = 33},
  [69] = {.lex_state = 22},
  [70] = {.lex_state = 21},
  [71] = {.lex_state = 15},
  [72] = {.lex_state = 21},
  [73] = {.lex_state = 20},
  [74] = {.lex_state = 15},
  [75] = {.lex_state = 48},
  [76] = {.lex_state = 20},
  [77] = {.lex_state = 12},
  [78] = {.lex_state = 19},
  [79] = {.lex_state = 159},
  [80] = {.lex_state = 16},
  [81] = {.lex_state = 23},
  [82] = {.lex_state = 34},
  [83] = {.lex_state = 28},
  [84] = {.lex_state = 24},
  [85] = {.lex_state = 28},
  [86] = {.lex_state = 28},
  [87] = {.lex_state = 34},
  [88] = {.lex_state = 24},
  [89] = {.lex_state = 28},
  [90] = {.lex_state = 23},
  [91] = {.lex_state = 28},
  [92] = {.lex_state = 7},
  [93] = {.lex_state = 24},
  [94] = {.lex_state = 17},
  [95] = {.lex_state = 5},
  [96] = {.lex_state = 159},
  [97] = {.lex_state = 28},
  [98] = {.lex_state = 34},
  [99] = {.lex_state = 17},
  [100] = {.lex_state = 16},
  [101] = {.lex_state = 23},
  [102] = {.lex_state = 7},
  [103] = {.lex_state = 28},
  [104] = {.lex_state = 47},
  [105] = {.lex_state = 32},
  [106] = {.lex_state = 13},
  [107] = {.lex_state = 28},
  [108] = {.lex_state = 7},
  [109] = {.lex_state = 12},
  [110] = {.lex_state = 25},
  [111] = {.lex_state = 159},
  [112] = {.lex_state = 12},
  [113] = {.lex_state = 5},
  [114] = {.lex_state = 5},
  [115] = {.lex_state = 41},
  [116] = {.lex_state = 25},
  [117] = {.lex_state = 48},
  [118] = {.lex_state = 22},
  [119] = {.lex_state = 159},
  [120] = {.lex_state = 48},
  [121] = {.lex_state = 48},
  [122] = {.lex_state = 11},
  [123] = {.lex_state = 25},
  [124] = {.lex_state = 11},
  [125] = {.lex_state = 12},
  [126] = {.lex_state = 159},
  [127] = {.lex_state = 17},
  [128] = {.lex_state = 159},
  [129] = {.lex_state = 22},
  [130] = {.lex_state = 11},
  [131] = {.lex_state = 22},
  [132] = {.lex_state = 38},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 38},
  [135] = {.lex_state = 38},
  [136] = {.lex_state = 5},
  [137] = {.lex_state = 38},
  [138] = {.lex_state = 13},
  [139] = {.lex_state = 159},
  [140] = {.lex_state = 5},
  [141] = {.lex_state = 13},
  [142] = {.lex_state = 159},
  [143] = {.lex_state = 38},
  [144] = {.lex_state = 38},
  [145] = {.lex_state = 15},
  [146] = {.lex_state = 159},
  [147] = {.lex_state = 16},
  [148] = {.lex_state = 15},
  [149] = {.lex_state = 5},
  [150] = {.lex_state = 5},
  [151] = {.lex_state = 16},
  [152] = {.lex_state = 13},
  [153] = {.lex_state = 37},
  [154] = {.lex_state = 15},
  [155] = {.lex_state = 16},
  [156] = {.lex_state = 38},
  [157] = {.lex_state = 28},
  [158] = {.lex_state = 36},
  [159] = {.lex_state = 16},
  [160] = {.lex_state = 38},
  [161] = {.lex_state = 25},
  [162] = {.lex_state = 13},
  [163] = {.lex_state = 15},
  [164] = {.lex_state = 38},
  [165] = {.lex_state = 46},
  [166] = {.lex_state = 36},
  [167] = {.lex_state = 38},
  [168] = {.lex_state = 159},
  [169] = {.lex_state = 159},
  [170] = {.lex_state = 38},
  [171] = {.lex_state = 159},
  [172] = {.lex_state = 38},
  [173] = {.lex_state = 5},
  [174] = {.lex_state = 5},
  [175] = {.lex_state = 5},
  [176] = {.lex_state = 5},
  [177] = {.lex_state = 5},
  [178] = {.lex_state = 49},
  [179] = {.lex_state = 5},
  [180] = {.lex_state = 5},
  [181] = {.lex_state = 5},
  [182] = {.lex_state = 159},
  [183] = {.lex_state = 5},
  [184] = {.lex_state = 5},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 42},
  [187] = {.lex_state = 192},
  [188] = {.lex_state = 192},
  [189] = {.lex_state = 39},
  [190] = {.lex_state = 39},
  [191] = {.lex_state = 5},
  [192] = {.lex_state = 5},
  [193] = {.lex_state = 39},
  [194] = {.lex_state = 5},
  [195] = {.lex_state = 39},
  [196] = {.lex_state = 5},
  [197] = {.lex_state = 39},
  [198] = {.lex_state = 5},
  [199] = {.lex_state = 44},
  [200] = {.lex_state = 39},
  [201] = {.lex_state = 5},
  [202] = {.lex_state = 5},
  [203] = {.lex_state = 192},
  [204] = {.lex_state = 5},
  [205] = {.lex_state = 5},
  [206] = {.lex_state = 5},
  [207] = {.lex_state = 50},
  [208] = {.lex_state = 5},
  [209] = {.lex_state = 159},
  [210] = {.lex_state = 192},
  [211] = {.lex_state = 39},
  [212] = {.lex_state = 39},
  [213] = {.lex_state = 39},
  [214] = {.lex_state = 39},
  [215] = {.lex_state = 159},
  [216] = {.lex_state = 159},
  [217] = {.lex_state = 39},
  [218] = {.lex_state = 39},
  [219] = {.lex_state = 39},
  [220] = {.lex_state = 39},
  [221] = {.lex_state = 5},
  [222] = {.lex_state = 39},
  [223] = {.lex_state = 159},
  [224] = {.lex_state = 50},
  [225] = {.lex_state = 39},
  [226] = {.lex_state = 159},
  [227] = {.lex_state = 39},
  [228] = {.lex_state = 159},
  [229] = {.lex_state = 50},
  [230] = {.lex_state = 39},
  [231] = {.lex_state = 5},
  [232] = {.lex_state = 159},
  [233] = {.lex_state = 5},
  [234] = {.lex_state = 159},
  [235] = {.lex_state = 5},
  [236] = {.lex_state = 159},
  [237] = {.lex_state = 5},
  [238] = {.lex_state = 159},
  [239] = {.lex_state = 5},
  [240] = {.lex_state = 159},
  [241] = {.lex_state = 5},
  [242] = {.lex_state = 159},
  [243] = {.lex_state = 39},
  [244] = {.lex_state = 159},
  [245] = {.lex_state = 39},
  [246] = {.lex_state = 159},
  [247] = {.lex_state = 5},
  [248] = {.lex_state = 159},
  [249] = {.lex_state = 49},
  [250] = {.lex_state = 159},
  [251] = {.lex_state = 49},
  [252] = {.lex_state = 159},
  [253] = {.lex_state = 49},
  [254] = {.lex_state = 49},
  [255] = {.lex_state = 49},
  [256] = {.lex_state = 49},
  [257] = {.lex_state = 49},
  [258] = {.lex_state = 49},
  [259] = {.lex_state = 49},
  [260] = {.lex_state = 49},
  [261] = {.lex_state = 49},
  [262] = {.lex_state = 44},
  [263] = {.lex_state = 44},
  [264] = {(TSStateId)(-1)},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [aux_sym__user_name_group_token1] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [aux_sym_path_token1] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [aux_sym_param_token1] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_line_continuation] = ACTIONS(3),
    [anon_sym_POUND] = ACTIONS(5),
    [anon_sym_DQUOTE] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(185),
    [sym__instruction] = STATE(183),
    [sym_from_instruction] = STATE(181),
    [sym_run_instruction] = STATE(181),
    [sym_cmd_instruction] = STATE(181),
    [sym_label_instruction] = STATE(181),
    [sym_expose_instruction] = STATE(181),
    [sym_env_instruction] = STATE(181),
    [sym_add_instruction] = STATE(181),
    [sym_copy_instruction] = STATE(181),
    [sym_entrypoint_instruction] = STATE(181),
    [sym_volume_instruction] = STATE(181),
    [sym_user_instruction] = STATE(181),
    [sym_workdir_instruction] = STATE(181),
    [sym_arg_instruction] = STATE(181),
    [sym_onbuild_instruction] = STATE(181),
    [sym_stopsignal_instruction] = STATE(181),
    [sym_healthcheck_instruction] = STATE(181),
    [sym_shell_instruction] = STATE(181),
    [sym_maintainer_instruction] = STATE(181),
    [sym_cross_build_instruction] = STATE(181),
    [sym_comment] = STATE(1),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(7),
    [aux_sym_from_instruction_token1] = ACTIONS(9),
    [aux_sym_run_instruction_token1] = ACTIONS(11),
    [aux_sym_cmd_instruction_token1] = ACTIONS(13),
    [aux_sym_label_instruction_token1] = ACTIONS(15),
    [aux_sym_expose_instruction_token1] = ACTIONS(17),
    [aux_sym_env_instruction_token1] = ACTIONS(19),
    [aux_sym_add_instruction_token1] = ACTIONS(21),
    [aux_sym_copy_instruction_token1] = ACTIONS(23),
    [aux_sym_entrypoint_instruction_token1] = ACTIONS(25),
    [aux_sym_volume_instruction_token1] = ACTIONS(27),
    [aux_sym_user_instruction_token1] = ACTIONS(29),
    [aux_sym_workdir_instruction_token1] = ACTIONS(31),
    [aux_sym_arg_instruction_token1] = ACTIONS(33),
    [aux_sym_onbuild_instruction_token1] = ACTIONS(35),
    [aux_sym_stopsignal_instruction_token1] = ACTIONS(37),
    [aux_sym_healthcheck_instruction_token1] = ACTIONS(39),
    [aux_sym_shell_instruction_token1] = ACTIONS(41),
    [aux_sym_maintainer_instruction_token1] = ACTIONS(43),
    [aux_sym_cross_build_instruction_token1] = ACTIONS(45),
    [sym_line_continuation] = ACTIONS(3),
    [anon_sym_POUND] = ACTIONS(5),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 25,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
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
    STATE(183), 1,
      sym__instruction,
    STATE(2), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(181), 19,
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
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(9), 1,
      aux_sym_from_instruction_token1,
    ACTIONS(11), 1,
      aux_sym_run_instruction_token1,
    ACTIONS(13), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(15), 1,
      aux_sym_label_instruction_token1,
    ACTIONS(17), 1,
      aux_sym_expose_instruction_token1,
    ACTIONS(19), 1,
      aux_sym_env_instruction_token1,
    ACTIONS(21), 1,
      aux_sym_add_instruction_token1,
    ACTIONS(23), 1,
      aux_sym_copy_instruction_token1,
    ACTIONS(25), 1,
      aux_sym_entrypoint_instruction_token1,
    ACTIONS(27), 1,
      aux_sym_volume_instruction_token1,
    ACTIONS(29), 1,
      aux_sym_user_instruction_token1,
    ACTIONS(31), 1,
      aux_sym_workdir_instruction_token1,
    ACTIONS(33), 1,
      aux_sym_arg_instruction_token1,
    ACTIONS(35), 1,
      aux_sym_onbuild_instruction_token1,
    ACTIONS(37), 1,
      aux_sym_stopsignal_instruction_token1,
    ACTIONS(39), 1,
      aux_sym_healthcheck_instruction_token1,
    ACTIONS(41), 1,
      aux_sym_shell_instruction_token1,
    ACTIONS(43), 1,
      aux_sym_maintainer_instruction_token1,
    ACTIONS(45), 1,
      aux_sym_cross_build_instruction_token1,
    ACTIONS(106), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      aux_sym_source_file_repeat1,
    STATE(3), 1,
      sym_comment,
    STATE(183), 1,
      sym__instruction,
    STATE(181), 19,
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
  [192] = 24,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(9), 1,
      aux_sym_from_instruction_token1,
    ACTIONS(11), 1,
      aux_sym_run_instruction_token1,
    ACTIONS(13), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(15), 1,
      aux_sym_label_instruction_token1,
    ACTIONS(17), 1,
      aux_sym_expose_instruction_token1,
    ACTIONS(19), 1,
      aux_sym_env_instruction_token1,
    ACTIONS(21), 1,
      aux_sym_add_instruction_token1,
    ACTIONS(23), 1,
      aux_sym_copy_instruction_token1,
    ACTIONS(25), 1,
      aux_sym_entrypoint_instruction_token1,
    ACTIONS(27), 1,
      aux_sym_volume_instruction_token1,
    ACTIONS(29), 1,
      aux_sym_user_instruction_token1,
    ACTIONS(31), 1,
      aux_sym_workdir_instruction_token1,
    ACTIONS(33), 1,
      aux_sym_arg_instruction_token1,
    ACTIONS(35), 1,
      aux_sym_onbuild_instruction_token1,
    ACTIONS(37), 1,
      aux_sym_stopsignal_instruction_token1,
    ACTIONS(39), 1,
      aux_sym_healthcheck_instruction_token1,
    ACTIONS(41), 1,
      aux_sym_shell_instruction_token1,
    ACTIONS(43), 1,
      aux_sym_maintainer_instruction_token1,
    ACTIONS(45), 1,
      aux_sym_cross_build_instruction_token1,
    STATE(4), 1,
      sym_comment,
    STATE(235), 1,
      sym__instruction,
    STATE(181), 19,
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
  [283] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    STATE(5), 1,
      sym_comment,
    ACTIONS(47), 20,
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
  [315] = 9,
    ACTIONS(110), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(112), 1,
      anon_sym_DOLLAR,
    ACTIONS(114), 1,
      aux_sym_image_name_token1,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(6), 1,
      sym_comment,
    STATE(8), 1,
      aux_sym_image_name_repeat1,
    STATE(43), 1,
      sym_expansion,
    ACTIONS(108), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
  [345] = 11,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(114), 1,
      aux_sym_image_name_token1,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(120), 1,
      anon_sym_DOLLAR,
    ACTIONS(122), 1,
      anon_sym_DASH_DASH,
    STATE(6), 1,
      aux_sym_image_name_repeat1,
    STATE(7), 1,
      sym_comment,
    STATE(40), 1,
      sym_param,
    STATE(41), 1,
      sym_image_name,
    STATE(43), 1,
      sym_expansion,
    STATE(141), 1,
      sym_image_spec,
  [379] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(126), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(128), 1,
      anon_sym_DOLLAR,
    ACTIONS(131), 1,
      aux_sym_image_name_token1,
    STATE(43), 1,
      sym_expansion,
    STATE(8), 2,
      sym_comment,
      aux_sym_image_name_repeat1,
    ACTIONS(124), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
  [407] = 10,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(134), 1,
      anon_sym_DOLLAR,
    ACTIONS(136), 1,
      anon_sym_DQUOTE,
    ACTIONS(138), 1,
      aux_sym_unquoted_string_token1,
    ACTIONS(140), 1,
      anon_sym_BSLASH,
    STATE(9), 1,
      sym_comment,
    STATE(23), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(51), 1,
      sym_expansion,
    STATE(151), 2,
      sym_double_quoted_string,
      sym_unquoted_string,
  [439] = 10,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(134), 1,
      anon_sym_DOLLAR,
    ACTIONS(136), 1,
      anon_sym_DQUOTE,
    ACTIONS(138), 1,
      aux_sym_unquoted_string_token1,
    ACTIONS(140), 1,
      anon_sym_BSLASH,
    STATE(10), 1,
      sym_comment,
    STATE(23), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(51), 1,
      sym_expansion,
    STATE(194), 2,
      sym_double_quoted_string,
      sym_unquoted_string,
  [471] = 10,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(142), 1,
      anon_sym_DOLLAR,
    ACTIONS(144), 1,
      anon_sym_DQUOTE,
    ACTIONS(146), 1,
      aux_sym_unquoted_string_token1,
    ACTIONS(148), 1,
      anon_sym_BSLASH,
    STATE(11), 1,
      sym_comment,
    STATE(19), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(63), 1,
      sym_expansion,
    STATE(154), 2,
      sym_double_quoted_string,
      sym_unquoted_string,
  [503] = 10,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(134), 1,
      anon_sym_DOLLAR,
    ACTIONS(136), 1,
      anon_sym_DQUOTE,
    ACTIONS(138), 1,
      aux_sym_unquoted_string_token1,
    ACTIONS(140), 1,
      anon_sym_BSLASH,
    STATE(12), 1,
      sym_comment,
    STATE(23), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(51), 1,
      sym_expansion,
    STATE(184), 2,
      sym_double_quoted_string,
      sym_unquoted_string,
  [535] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(150), 1,
      anon_sym_LBRACK,
    STATE(13), 1,
      sym_comment,
    STATE(94), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(136), 1,
      sym_shell_fragment,
    ACTIONS(152), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(241), 2,
      sym_string_array,
      sym_shell_command,
  [562] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(154), 1,
      anon_sym_POUND,
    STATE(14), 1,
      sym_comment,
    STATE(94), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(177), 1,
      sym_shell_fragment,
    STATE(201), 1,
      sym__anon_comment,
    ACTIONS(152), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(62), 2,
      sym__comment_line,
      aux_sym_shell_command_repeat1,
  [589] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(158), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(160), 1,
      anon_sym_DOLLAR,
    ACTIONS(163), 1,
      aux_sym_image_tag_token1,
    STATE(59), 1,
      sym_expansion,
    ACTIONS(156), 2,
      anon_sym_LF,
      anon_sym_AT,
    STATE(15), 2,
      sym_comment,
      aux_sym_image_tag_repeat1,
  [616] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(166), 1,
      anon_sym_LF,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    ACTIONS(171), 1,
      aux_sym__env_key_token1,
    ACTIONS(173), 1,
      aux_sym_unquoted_string_token1,
    ACTIONS(176), 1,
      anon_sym_BSLASH,
    STATE(63), 1,
      sym_expansion,
    STATE(16), 2,
      sym_comment,
      aux_sym_unquoted_string_repeat1,
  [645] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(150), 1,
      anon_sym_LBRACK,
    STATE(17), 1,
      sym_comment,
    STATE(94), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(136), 1,
      sym_shell_fragment,
    ACTIONS(152), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(173), 2,
      sym_string_array,
      sym_shell_command,
  [672] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(150), 1,
      anon_sym_LBRACK,
    STATE(18), 1,
      sym_comment,
    STATE(94), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(136), 1,
      sym_shell_fragment,
    ACTIONS(152), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(205), 2,
      sym_string_array,
      sym_shell_command,
  [699] = 10,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(146), 1,
      aux_sym_unquoted_string_token1,
    ACTIONS(148), 1,
      anon_sym_BSLASH,
    ACTIONS(179), 1,
      anon_sym_LF,
    ACTIONS(181), 1,
      anon_sym_DOLLAR,
    ACTIONS(183), 1,
      aux_sym__env_key_token1,
    STATE(16), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(19), 1,
      sym_comment,
    STATE(63), 1,
      sym_expansion,
  [730] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(166), 1,
      anon_sym_LF,
    ACTIONS(171), 1,
      aux_sym_label_pair_token1,
    ACTIONS(185), 1,
      anon_sym_DOLLAR,
    ACTIONS(188), 1,
      aux_sym_unquoted_string_token1,
    ACTIONS(191), 1,
      anon_sym_BSLASH,
    STATE(51), 1,
      sym_expansion,
    STATE(20), 2,
      sym_comment,
      aux_sym_unquoted_string_repeat1,
  [759] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(154), 1,
      anon_sym_POUND,
    STATE(21), 1,
      sym_comment,
    STATE(94), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(201), 1,
      sym__anon_comment,
    STATE(202), 1,
      sym_shell_fragment,
    ACTIONS(152), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(14), 2,
      sym__comment_line,
      aux_sym_shell_command_repeat1,
  [786] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(196), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(198), 1,
      anon_sym_DOLLAR,
    ACTIONS(200), 1,
      aux_sym_image_tag_token1,
    STATE(15), 1,
      aux_sym_image_tag_repeat1,
    STATE(22), 1,
      sym_comment,
    STATE(59), 1,
      sym_expansion,
    ACTIONS(194), 2,
      anon_sym_LF,
      anon_sym_AT,
  [815] = 10,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(138), 1,
      aux_sym_unquoted_string_token1,
    ACTIONS(140), 1,
      anon_sym_BSLASH,
    ACTIONS(179), 1,
      anon_sym_LF,
    ACTIONS(183), 1,
      aux_sym_label_pair_token1,
    ACTIONS(202), 1,
      anon_sym_DOLLAR,
    STATE(20), 1,
      aux_sym_unquoted_string_repeat1,
    STATE(23), 1,
      sym_comment,
    STATE(51), 1,
      sym_expansion,
  [846] = 7,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(204), 1,
      anon_sym_LF,
    ACTIONS(206), 1,
      anon_sym_DOLLAR,
    ACTIONS(209), 1,
      aux_sym_expose_port_token1,
    STATE(24), 2,
      sym_comment,
      aux_sym_expose_instruction_repeat1,
    STATE(113), 2,
      sym_expansion,
      sym_expose_port,
  [870] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(212), 1,
      anon_sym_DOLLAR,
    ACTIONS(214), 1,
      anon_sym_DQUOTE,
    ACTIONS(216), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(218), 1,
      sym_escape_sequence,
    STATE(25), 1,
      sym_comment,
    STATE(30), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(90), 1,
      sym_expansion,
  [898] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(26), 1,
      sym_comment,
    ACTIONS(220), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
    ACTIONS(222), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_name_token1,
  [918] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(226), 1,
      aux_sym_path_token2,
    ACTIONS(228), 1,
      anon_sym_DOLLAR,
    STATE(27), 1,
      sym_comment,
    STATE(28), 1,
      aux_sym_path_repeat1,
    STATE(84), 1,
      sym_expansion,
    ACTIONS(224), 2,
      anon_sym_LF,
      sym__non_newline_whitespace,
  [944] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(226), 1,
      aux_sym_path_token2,
    ACTIONS(228), 1,
      anon_sym_DOLLAR,
    STATE(28), 1,
      sym_comment,
    STATE(33), 1,
      aux_sym_path_repeat1,
    STATE(84), 1,
      sym_expansion,
    ACTIONS(230), 2,
      anon_sym_LF,
      sym__non_newline_whitespace,
  [970] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(29), 1,
      sym_comment,
    ACTIONS(232), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
    ACTIONS(234), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_name_token1,
  [990] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(236), 1,
      anon_sym_DOLLAR,
    ACTIONS(239), 1,
      anon_sym_DQUOTE,
    ACTIONS(241), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(244), 1,
      sym_escape_sequence,
    STATE(90), 1,
      sym_expansion,
    STATE(30), 2,
      sym_comment,
      aux_sym_double_quoted_string_repeat1,
  [1016] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(247), 1,
      anon_sym_LF,
    ACTIONS(249), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(251), 1,
      anon_sym_DOLLAR,
    ACTIONS(254), 1,
      aux_sym_image_digest_token1,
    STATE(92), 1,
      sym_expansion,
    STATE(31), 2,
      sym_comment,
      aux_sym_image_digest_repeat1,
  [1042] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(257), 1,
      anon_sym_LF,
    ACTIONS(259), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(261), 1,
      anon_sym_DOLLAR,
    ACTIONS(263), 1,
      aux_sym_image_digest_token1,
    STATE(31), 1,
      aux_sym_image_digest_repeat1,
    STATE(32), 1,
      sym_comment,
    STATE(92), 1,
      sym_expansion,
  [1070] = 7,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(267), 1,
      aux_sym_path_token2,
    ACTIONS(270), 1,
      anon_sym_DOLLAR,
    STATE(84), 1,
      sym_expansion,
    ACTIONS(265), 2,
      anon_sym_LF,
      sym__non_newline_whitespace,
    STATE(33), 2,
      sym_comment,
      aux_sym_path_repeat1,
  [1094] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(273), 1,
      anon_sym_LF,
    ACTIONS(275), 1,
      anon_sym_DOLLAR,
    ACTIONS(277), 1,
      aux_sym_expose_port_token1,
    STATE(24), 1,
      aux_sym_expose_instruction_repeat1,
    STATE(34), 1,
      sym_comment,
    STATE(113), 2,
      sym_expansion,
      sym_expose_port,
  [1120] = 7,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(281), 1,
      aux_sym__user_name_group_token1,
    ACTIONS(284), 1,
      anon_sym_DOLLAR,
    STATE(95), 1,
      sym_expansion,
    ACTIONS(279), 2,
      anon_sym_LF,
      anon_sym_COLON,
    STATE(35), 2,
      aux_sym__user_name_group,
      sym_comment,
  [1144] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(287), 1,
      aux_sym_path_token1,
    ACTIONS(289), 1,
      anon_sym_DOLLAR,
    ACTIONS(291), 1,
      anon_sym_DASH_DASH,
    STATE(36), 1,
      sym_comment,
    STATE(75), 1,
      sym_expansion,
    STATE(89), 1,
      sym_param,
    STATE(245), 1,
      sym_path,
  [1172] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(287), 1,
      aux_sym_path_token1,
    ACTIONS(289), 1,
      anon_sym_DOLLAR,
    ACTIONS(291), 1,
      anon_sym_DASH_DASH,
    STATE(37), 1,
      sym_comment,
    STATE(75), 1,
      sym_expansion,
    STATE(91), 1,
      sym_param,
    STATE(243), 1,
      sym_path,
  [1200] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(212), 1,
      anon_sym_DOLLAR,
    ACTIONS(216), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(218), 1,
      sym_escape_sequence,
    ACTIONS(293), 1,
      anon_sym_DQUOTE,
    STATE(38), 1,
      sym_comment,
    STATE(42), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(90), 1,
      sym_expansion,
  [1228] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(150), 1,
      anon_sym_LBRACK,
    ACTIONS(295), 1,
      aux_sym_path_token1,
    ACTIONS(297), 1,
      anon_sym_DOLLAR,
    STATE(27), 1,
      sym_expansion,
    STATE(39), 1,
      sym_comment,
    STATE(110), 1,
      sym_path,
    STATE(239), 1,
      sym_string_array,
  [1256] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(114), 1,
      aux_sym_image_name_token1,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(120), 1,
      anon_sym_DOLLAR,
    STATE(6), 1,
      aux_sym_image_name_repeat1,
    STATE(40), 1,
      sym_comment,
    STATE(41), 1,
      sym_image_name,
    STATE(43), 1,
      sym_expansion,
    STATE(152), 1,
      sym_image_spec,
  [1284] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(299), 1,
      anon_sym_LF,
    ACTIONS(301), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(303), 1,
      anon_sym_COLON,
    ACTIONS(305), 1,
      anon_sym_AT,
    STATE(41), 1,
      sym_comment,
    STATE(106), 1,
      sym_image_tag,
    STATE(162), 1,
      sym_image_digest,
  [1312] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(212), 1,
      anon_sym_DOLLAR,
    ACTIONS(216), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(218), 1,
      sym_escape_sequence,
    ACTIONS(307), 1,
      anon_sym_DQUOTE,
    STATE(30), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(42), 1,
      sym_comment,
    STATE(90), 1,
      sym_expansion,
  [1340] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(43), 1,
      sym_comment,
    ACTIONS(309), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
    ACTIONS(311), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_name_token1,
  [1360] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(13), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(313), 1,
      anon_sym_NONE,
    ACTIONS(315), 1,
      anon_sym_DASH_DASH,
    STATE(44), 1,
      sym_comment,
    STATE(56), 1,
      aux_sym_healthcheck_instruction_repeat1,
    STATE(168), 1,
      sym_param,
    STATE(233), 1,
      sym_cmd_instruction,
  [1388] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(275), 1,
      anon_sym_DOLLAR,
    ACTIONS(317), 1,
      anon_sym_LF,
    ACTIONS(319), 1,
      anon_sym_COLON,
    ACTIONS(321), 1,
      aux_sym__user_name_group_token1,
    STATE(35), 1,
      aux_sym__user_name_group,
    STATE(45), 1,
      sym_comment,
    STATE(95), 1,
      sym_expansion,
  [1416] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(212), 1,
      anon_sym_DOLLAR,
    ACTIONS(216), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(218), 1,
      sym_escape_sequence,
    ACTIONS(323), 1,
      anon_sym_DQUOTE,
    STATE(46), 1,
      sym_comment,
    STATE(47), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(90), 1,
      sym_expansion,
  [1444] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(212), 1,
      anon_sym_DOLLAR,
    ACTIONS(216), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(218), 1,
      sym_escape_sequence,
    ACTIONS(325), 1,
      anon_sym_DQUOTE,
    STATE(30), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(47), 1,
      sym_comment,
    STATE(90), 1,
      sym_expansion,
  [1472] = 9,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(212), 1,
      anon_sym_DOLLAR,
    ACTIONS(216), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(218), 1,
      sym_escape_sequence,
    ACTIONS(327), 1,
      anon_sym_DQUOTE,
    STATE(25), 1,
      aux_sym_double_quoted_string_repeat1,
    STATE(48), 1,
      sym_comment,
    STATE(90), 1,
      sym_expansion,
  [1500] = 7,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(329), 1,
      anon_sym_LF,
    ACTIONS(331), 1,
      anon_sym_DOLLAR,
    ACTIONS(334), 1,
      aux_sym_image_alias_token1,
    STATE(130), 1,
      sym_expansion,
    STATE(49), 2,
      sym_comment,
      aux_sym_image_alias_repeat1,
  [1523] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(50), 1,
      sym_comment,
    ACTIONS(234), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
    ACTIONS(232), 3,
      anon_sym_LF,
      anon_sym_COLON,
      aux_sym__user_name_group_token1,
  [1542] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(51), 1,
      sym_comment,
    ACTIONS(337), 2,
      anon_sym_LF,
      anon_sym_BSLASH,
    ACTIONS(339), 3,
      anon_sym_DOLLAR,
      aux_sym_label_pair_token1,
      aux_sym_unquoted_string_token1,
  [1561] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(52), 1,
      sym_comment,
    ACTIONS(232), 2,
      anon_sym_LF,
      anon_sym_BSLASH,
    ACTIONS(234), 3,
      anon_sym_DOLLAR,
      aux_sym__env_key_token1,
      aux_sym_unquoted_string_token1,
  [1580] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(341), 1,
      anon_sym_DOLLAR,
    ACTIONS(343), 1,
      aux_sym_image_alias_token1,
    STATE(53), 1,
      sym_comment,
    STATE(60), 1,
      aux_sym_image_alias_repeat1,
    STATE(130), 1,
      sym_expansion,
    STATE(174), 1,
      sym_image_alias,
  [1605] = 7,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(345), 1,
      aux_sym_path_token2,
    ACTIONS(348), 1,
      anon_sym_DOLLAR,
    ACTIONS(351), 1,
      sym__non_newline_whitespace,
    STATE(121), 1,
      sym_expansion,
    STATE(54), 2,
      sym_comment,
      aux_sym_path_repeat1,
  [1628] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(275), 1,
      anon_sym_DOLLAR,
    ACTIONS(321), 1,
      aux_sym__user_name_group_token1,
    ACTIONS(353), 1,
      anon_sym_LF,
    STATE(35), 1,
      aux_sym__user_name_group,
    STATE(55), 1,
      sym_comment,
    STATE(95), 1,
      sym_expansion,
  [1653] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(13), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(315), 1,
      anon_sym_DASH_DASH,
    STATE(56), 1,
      sym_comment,
    STATE(96), 1,
      aux_sym_healthcheck_instruction_repeat1,
    STATE(168), 1,
      sym_param,
    STATE(208), 1,
      sym_cmd_instruction,
  [1678] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(355), 1,
      aux_sym__env_key_token1,
    STATE(57), 1,
      sym_comment,
    STATE(74), 1,
      aux_sym_env_instruction_repeat1,
    STATE(158), 1,
      sym__env_key,
    STATE(163), 1,
      sym_env_pair,
    STATE(247), 1,
      sym__spaced_env_pair,
  [1703] = 6,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(357), 1,
      anon_sym_LF,
    STATE(58), 1,
      sym_comment,
    ACTIONS(359), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
    ACTIONS(361), 2,
      anon_sym_SLASHtcp,
      anon_sym_SLASHudp,
  [1724] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(59), 1,
      sym_comment,
    ACTIONS(363), 2,
      anon_sym_LF,
      anon_sym_AT,
    ACTIONS(365), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_tag_token1,
  [1743] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(367), 1,
      anon_sym_LF,
    ACTIONS(369), 1,
      anon_sym_DOLLAR,
    ACTIONS(371), 1,
      aux_sym_image_alias_token1,
    STATE(49), 1,
      aux_sym_image_alias_repeat1,
    STATE(60), 1,
      sym_comment,
    STATE(130), 1,
      sym_expansion,
  [1768] = 7,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(373), 1,
      anon_sym_LF,
    ACTIONS(375), 1,
      aux_sym__stopsignal_value_token1,
    ACTIONS(378), 1,
      anon_sym_DOLLAR,
    STATE(112), 1,
      sym_expansion,
    STATE(61), 2,
      aux_sym__stopsignal_value,
      sym_comment,
  [1791] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(383), 1,
      anon_sym_POUND,
    STATE(201), 1,
      sym__anon_comment,
    ACTIONS(381), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(62), 3,
      sym__comment_line,
      sym_comment,
      aux_sym_shell_command_repeat1,
  [1810] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(63), 1,
      sym_comment,
    ACTIONS(337), 2,
      anon_sym_LF,
      anon_sym_BSLASH,
    ACTIONS(339), 3,
      anon_sym_DOLLAR,
      aux_sym__env_key_token1,
      aux_sym_unquoted_string_token1,
  [1829] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(386), 1,
      aux_sym_path_token2,
    ACTIONS(388), 1,
      anon_sym_DOLLAR,
    ACTIONS(390), 1,
      sym__non_newline_whitespace,
    STATE(54), 1,
      aux_sym_path_repeat1,
    STATE(64), 1,
      sym_comment,
    STATE(121), 1,
      sym_expansion,
  [1854] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(392), 1,
      anon_sym_LF,
    ACTIONS(394), 1,
      aux_sym_path_token2,
    ACTIONS(396), 1,
      anon_sym_DOLLAR,
    STATE(65), 1,
      sym_comment,
    STATE(66), 1,
      aux_sym_path_repeat1,
    STATE(118), 1,
      sym_expansion,
  [1879] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(390), 1,
      anon_sym_LF,
    ACTIONS(394), 1,
      aux_sym_path_token2,
    ACTIONS(396), 1,
      anon_sym_DOLLAR,
    STATE(66), 1,
      sym_comment,
    STATE(69), 1,
      aux_sym_path_repeat1,
    STATE(118), 1,
      sym_expansion,
  [1904] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(67), 1,
      sym_comment,
    ACTIONS(222), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
    ACTIONS(220), 3,
      anon_sym_LF,
      anon_sym_COLON,
      aux_sym__user_name_group_token1,
  [1923] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(341), 1,
      anon_sym_DOLLAR,
    ACTIONS(343), 1,
      aux_sym_image_alias_token1,
    STATE(60), 1,
      aux_sym_image_alias_repeat1,
    STATE(68), 1,
      sym_comment,
    STATE(130), 1,
      sym_expansion,
    STATE(206), 1,
      sym_image_alias,
  [1948] = 7,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(351), 1,
      anon_sym_LF,
    ACTIONS(398), 1,
      aux_sym_path_token2,
    ACTIONS(401), 1,
      anon_sym_DOLLAR,
    STATE(118), 1,
      sym_expansion,
    STATE(69), 2,
      sym_comment,
      aux_sym_path_repeat1,
  [1971] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(70), 1,
      sym_comment,
    ACTIONS(220), 2,
      anon_sym_LF,
      anon_sym_AT,
    ACTIONS(222), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_tag_token1,
  [1990] = 7,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(404), 1,
      anon_sym_LF,
    ACTIONS(406), 1,
      aux_sym__env_key_token1,
    STATE(163), 1,
      sym_env_pair,
    STATE(215), 1,
      sym__env_key,
    STATE(71), 2,
      sym_comment,
      aux_sym_env_instruction_repeat1,
  [2013] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(72), 1,
      sym_comment,
    ACTIONS(232), 2,
      anon_sym_LF,
      anon_sym_AT,
    ACTIONS(234), 3,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
      aux_sym_image_tag_token1,
  [2032] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(73), 1,
      sym_comment,
    ACTIONS(220), 2,
      anon_sym_LF,
      anon_sym_BSLASH,
    ACTIONS(222), 3,
      anon_sym_DOLLAR,
      aux_sym_label_pair_token1,
      aux_sym_unquoted_string_token1,
  [2051] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(409), 1,
      anon_sym_LF,
    ACTIONS(411), 1,
      aux_sym__env_key_token1,
    STATE(71), 1,
      aux_sym_env_instruction_repeat1,
    STATE(74), 1,
      sym_comment,
    STATE(163), 1,
      sym_env_pair,
    STATE(215), 1,
      sym__env_key,
  [2076] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(386), 1,
      aux_sym_path_token2,
    ACTIONS(388), 1,
      anon_sym_DOLLAR,
    ACTIONS(392), 1,
      sym__non_newline_whitespace,
    STATE(64), 1,
      aux_sym_path_repeat1,
    STATE(75), 1,
      sym_comment,
    STATE(121), 1,
      sym_expansion,
  [2101] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(76), 1,
      sym_comment,
    ACTIONS(232), 2,
      anon_sym_LF,
      anon_sym_BSLASH,
    ACTIONS(234), 3,
      anon_sym_DOLLAR,
      aux_sym_label_pair_token1,
      aux_sym_unquoted_string_token1,
  [2120] = 8,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(413), 1,
      anon_sym_LF,
    ACTIONS(415), 1,
      aux_sym__stopsignal_value_token1,
    ACTIONS(417), 1,
      anon_sym_DOLLAR,
    STATE(61), 1,
      aux_sym__stopsignal_value,
    STATE(77), 1,
      sym_comment,
    STATE(112), 1,
      sym_expansion,
  [2145] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(78), 1,
      sym_comment,
    ACTIONS(220), 2,
      anon_sym_LF,
      anon_sym_BSLASH,
    ACTIONS(222), 3,
      anon_sym_DOLLAR,
      aux_sym__env_key_token1,
      aux_sym_unquoted_string_token1,
  [2164] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(419), 1,
      anon_sym_DOLLAR,
    ACTIONS(421), 1,
      aux_sym_expose_port_token1,
    STATE(34), 1,
      aux_sym_expose_instruction_repeat1,
    STATE(79), 1,
      sym_comment,
    STATE(113), 2,
      sym_expansion,
      sym_expose_port,
  [2187] = 7,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(423), 1,
      anon_sym_LF,
    ACTIONS(425), 1,
      aux_sym_label_pair_token1,
    STATE(80), 1,
      sym_comment,
    STATE(100), 1,
      aux_sym_label_instruction_repeat1,
    STATE(147), 1,
      sym_label_pair,
  [2209] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(232), 1,
      aux_sym_double_quoted_string_token1,
    STATE(81), 1,
      sym_comment,
    ACTIONS(234), 3,
      anon_sym_DOLLAR,
      anon_sym_DQUOTE,
      sym_escape_sequence,
  [2227] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(321), 1,
      aux_sym__user_name_group_token1,
    ACTIONS(419), 1,
      anon_sym_DOLLAR,
    STATE(45), 1,
      aux_sym__user_name_group,
    STATE(82), 1,
      sym_comment,
    STATE(95), 1,
      sym_expansion,
  [2249] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(427), 1,
      aux_sym_path_token1,
    ACTIONS(429), 1,
      anon_sym_DOLLAR,
    STATE(65), 1,
      sym_expansion,
    STATE(83), 1,
      sym_comment,
    STATE(237), 1,
      sym_path,
  [2271] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(84), 1,
      sym_comment,
    ACTIONS(431), 4,
      anon_sym_LF,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
      sym__non_newline_whitespace,
  [2287] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(427), 1,
      aux_sym_path_token1,
    ACTIONS(429), 1,
      anon_sym_DOLLAR,
    STATE(65), 1,
      sym_expansion,
    STATE(85), 1,
      sym_comment,
    STATE(180), 1,
      sym_path,
  [2309] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(427), 1,
      aux_sym_path_token1,
    ACTIONS(429), 1,
      anon_sym_DOLLAR,
    STATE(65), 1,
      sym_expansion,
    STATE(86), 1,
      sym_comment,
    STATE(179), 1,
      sym_path,
  [2331] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(433), 1,
      aux_sym__stopsignal_value_token1,
    ACTIONS(435), 1,
      anon_sym_DOLLAR,
    STATE(77), 1,
      aux_sym__stopsignal_value,
    STATE(87), 1,
      sym_comment,
    STATE(112), 1,
      sym_expansion,
  [2353] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(88), 1,
      sym_comment,
    ACTIONS(222), 4,
      anon_sym_LF,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
      sym__non_newline_whitespace,
  [2369] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(287), 1,
      aux_sym_path_token1,
    ACTIONS(289), 1,
      anon_sym_DOLLAR,
    STATE(75), 1,
      sym_expansion,
    STATE(89), 1,
      sym_comment,
    STATE(214), 1,
      sym_path,
  [2391] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(439), 1,
      aux_sym_double_quoted_string_token1,
    STATE(90), 1,
      sym_comment,
    ACTIONS(437), 3,
      anon_sym_DOLLAR,
      anon_sym_DQUOTE,
      sym_escape_sequence,
  [2409] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(287), 1,
      aux_sym_path_token1,
    ACTIONS(289), 1,
      anon_sym_DOLLAR,
    STATE(75), 1,
      sym_expansion,
    STATE(91), 1,
      sym_comment,
    STATE(213), 1,
      sym_path,
  [2431] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(92), 1,
      sym_comment,
    ACTIONS(441), 2,
      anon_sym_LF,
      aux_sym_image_digest_token1,
    ACTIONS(443), 2,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
  [2449] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(93), 1,
      sym_comment,
    ACTIONS(234), 4,
      anon_sym_LF,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
      sym__non_newline_whitespace,
  [2465] = 6,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(445), 1,
      anon_sym_LF,
    ACTIONS(449), 1,
      sym_line_continuation,
    STATE(94), 1,
      sym_comment,
    STATE(99), 1,
      aux_sym_shell_fragment_repeat1,
    ACTIONS(447), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
  [2485] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(453), 1,
      anon_sym_DOLLAR,
    STATE(95), 1,
      sym_comment,
    ACTIONS(451), 3,
      anon_sym_LF,
      anon_sym_COLON,
      aux_sym__user_name_group_token1,
  [2503] = 6,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(455), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(457), 1,
      anon_sym_DASH_DASH,
    STATE(168), 1,
      sym_param,
    STATE(96), 2,
      sym_comment,
      aux_sym_healthcheck_instruction_repeat1,
  [2523] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(427), 1,
      aux_sym_path_token1,
    ACTIONS(429), 1,
      anon_sym_DOLLAR,
    STATE(65), 1,
      sym_expansion,
    STATE(97), 1,
      sym_comment,
    STATE(191), 1,
      sym_path,
  [2545] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(321), 1,
      aux_sym__user_name_group_token1,
    ACTIONS(419), 1,
      anon_sym_DOLLAR,
    STATE(55), 1,
      aux_sym__user_name_group,
    STATE(95), 1,
      sym_expansion,
    STATE(98), 1,
      sym_comment,
  [2567] = 5,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(460), 1,
      anon_sym_LF,
    ACTIONS(465), 1,
      sym_line_continuation,
    ACTIONS(462), 2,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
    STATE(99), 2,
      sym_comment,
      aux_sym_shell_fragment_repeat1,
  [2585] = 6,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(467), 1,
      anon_sym_LF,
    ACTIONS(469), 1,
      aux_sym_label_pair_token1,
    STATE(147), 1,
      sym_label_pair,
    STATE(100), 2,
      sym_comment,
      aux_sym_label_instruction_repeat1,
  [2605] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(220), 1,
      aux_sym_double_quoted_string_token1,
    STATE(101), 1,
      sym_comment,
    ACTIONS(222), 3,
      anon_sym_DOLLAR,
      anon_sym_DQUOTE,
      sym_escape_sequence,
  [2623] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(102), 1,
      sym_comment,
    ACTIONS(232), 2,
      anon_sym_LF,
      aux_sym_image_digest_token1,
    ACTIONS(234), 2,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
  [2641] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(295), 1,
      aux_sym_path_token1,
    ACTIONS(297), 1,
      anon_sym_DOLLAR,
    STATE(27), 1,
      sym_expansion,
    STATE(103), 1,
      sym_comment,
    STATE(161), 1,
      sym_path,
  [2663] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(200), 1,
      aux_sym_image_tag_token1,
    ACTIONS(472), 1,
      anon_sym_DOLLAR,
    STATE(22), 1,
      aux_sym_image_tag_repeat1,
    STATE(59), 1,
      sym_expansion,
    STATE(104), 1,
      sym_comment,
  [2685] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(263), 1,
      aux_sym_image_digest_token1,
    ACTIONS(474), 1,
      anon_sym_DOLLAR,
    STATE(32), 1,
      aux_sym_image_digest_repeat1,
    STATE(92), 1,
      sym_expansion,
    STATE(105), 1,
      sym_comment,
  [2707] = 7,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(305), 1,
      anon_sym_AT,
    ACTIONS(476), 1,
      anon_sym_LF,
    ACTIONS(478), 1,
      aux_sym_from_instruction_token2,
    STATE(106), 1,
      sym_comment,
    STATE(138), 1,
      sym_image_digest,
  [2729] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(427), 1,
      aux_sym_path_token1,
    ACTIONS(429), 1,
      anon_sym_DOLLAR,
    STATE(65), 1,
      sym_expansion,
    STATE(107), 1,
      sym_comment,
    STATE(192), 1,
      sym_path,
  [2751] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(108), 1,
      sym_comment,
    ACTIONS(220), 2,
      anon_sym_LF,
      aux_sym_image_digest_token1,
    ACTIONS(222), 2,
      aux_sym_from_instruction_token2,
      anon_sym_DOLLAR,
  [2769] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(220), 1,
      anon_sym_LF,
    STATE(109), 1,
      sym_comment,
    ACTIONS(222), 2,
      aux_sym__stopsignal_value_token1,
      anon_sym_DOLLAR,
  [2786] = 6,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(480), 1,
      anon_sym_LF,
    ACTIONS(482), 1,
      sym__non_newline_whitespace,
    STATE(110), 1,
      sym_comment,
    STATE(123), 1,
      aux_sym_volume_instruction_repeat1,
  [2805] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(484), 1,
      anon_sym_COMMA,
    ACTIONS(487), 1,
      anon_sym_RBRACK,
    STATE(111), 2,
      sym_comment,
      aux_sym_string_array_repeat1,
  [2822] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(489), 1,
      anon_sym_LF,
    STATE(112), 1,
      sym_comment,
    ACTIONS(491), 2,
      aux_sym__stopsignal_value_token1,
      anon_sym_DOLLAR,
  [2839] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(493), 1,
      anon_sym_LF,
    STATE(113), 1,
      sym_comment,
    ACTIONS(495), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
  [2856] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(497), 1,
      anon_sym_LF,
    STATE(114), 1,
      sym_comment,
    ACTIONS(499), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
  [2873] = 6,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(501), 1,
      aux_sym_label_pair_token1,
    STATE(80), 1,
      aux_sym_label_instruction_repeat1,
    STATE(115), 1,
      sym_comment,
    STATE(147), 1,
      sym_label_pair,
  [2892] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(503), 1,
      anon_sym_LF,
    ACTIONS(505), 1,
      sym__non_newline_whitespace,
    STATE(116), 2,
      sym_comment,
      aux_sym_volume_instruction_repeat1,
  [2909] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(220), 1,
      sym__non_newline_whitespace,
    STATE(117), 1,
      sym_comment,
    ACTIONS(222), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [2926] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(508), 1,
      anon_sym_LF,
    STATE(118), 1,
      sym_comment,
    ACTIONS(431), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [2943] = 6,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(510), 1,
      anon_sym_COMMA,
    ACTIONS(512), 1,
      anon_sym_RBRACK,
    STATE(119), 1,
      sym_comment,
    STATE(126), 1,
      aux_sym_string_array_repeat1,
  [2962] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(232), 1,
      sym__non_newline_whitespace,
    STATE(120), 1,
      sym_comment,
    ACTIONS(234), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [2979] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(508), 1,
      sym__non_newline_whitespace,
    STATE(121), 1,
      sym_comment,
    ACTIONS(431), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [2996] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(232), 1,
      anon_sym_LF,
    STATE(122), 1,
      sym_comment,
    ACTIONS(234), 2,
      anon_sym_DOLLAR,
      aux_sym_image_alias_token1,
  [3013] = 6,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(482), 1,
      sym__non_newline_whitespace,
    ACTIONS(514), 1,
      anon_sym_LF,
    STATE(116), 1,
      aux_sym_volume_instruction_repeat1,
    STATE(123), 1,
      sym_comment,
  [3032] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(220), 1,
      anon_sym_LF,
    STATE(124), 1,
      sym_comment,
    ACTIONS(222), 2,
      anon_sym_DOLLAR,
      aux_sym_image_alias_token1,
  [3049] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(232), 1,
      anon_sym_LF,
    STATE(125), 1,
      sym_comment,
    ACTIONS(234), 2,
      aux_sym__stopsignal_value_token1,
      anon_sym_DOLLAR,
  [3066] = 6,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(510), 1,
      anon_sym_COMMA,
    ACTIONS(516), 1,
      anon_sym_RBRACK,
    STATE(111), 1,
      aux_sym_string_array_repeat1,
    STATE(126), 1,
      sym_comment,
  [3085] = 4,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(518), 1,
      anon_sym_LF,
    STATE(127), 1,
      sym_comment,
    ACTIONS(520), 3,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
      sym_line_continuation,
  [3100] = 6,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(522), 1,
      anon_sym_RBRACK,
    ACTIONS(524), 1,
      anon_sym_DQUOTE,
    STATE(119), 1,
      sym_double_quoted_string,
    STATE(128), 1,
      sym_comment,
  [3119] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(232), 1,
      anon_sym_LF,
    STATE(129), 1,
      sym_comment,
    ACTIONS(234), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [3136] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(526), 1,
      anon_sym_LF,
    STATE(130), 1,
      sym_comment,
    ACTIONS(528), 2,
      anon_sym_DOLLAR,
      aux_sym_image_alias_token1,
  [3153] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(220), 1,
      anon_sym_LF,
    STATE(131), 1,
      sym_comment,
    ACTIONS(222), 2,
      aux_sym_path_token2,
      anon_sym_DOLLAR,
  [3170] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(530), 1,
      anon_sym_LBRACE,
    ACTIONS(532), 1,
      sym_variable,
    STATE(132), 1,
      sym_comment,
  [3186] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(150), 1,
      anon_sym_LBRACK,
    STATE(133), 1,
      sym_comment,
    STATE(231), 1,
      sym_string_array,
  [3202] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(534), 1,
      anon_sym_LBRACE,
    ACTIONS(536), 1,
      sym_variable,
    STATE(134), 1,
      sym_comment,
  [3218] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(538), 1,
      anon_sym_LBRACE,
    ACTIONS(540), 1,
      sym_variable,
    STATE(135), 1,
      sym_comment,
  [3234] = 5,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(542), 1,
      anon_sym_LF,
    ACTIONS(544), 1,
      sym_line_continuation,
    STATE(136), 1,
      sym_comment,
    STATE(150), 1,
      aux_sym_shell_command_repeat2,
  [3250] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(546), 1,
      anon_sym_LBRACE,
    ACTIONS(548), 1,
      sym_variable,
    STATE(137), 1,
      sym_comment,
  [3266] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(550), 1,
      anon_sym_LF,
    ACTIONS(552), 1,
      aux_sym_from_instruction_token2,
    STATE(138), 1,
      sym_comment,
  [3282] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    STATE(139), 1,
      sym_comment,
    ACTIONS(554), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3296] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(556), 1,
      anon_sym_LF,
    ACTIONS(558), 1,
      anon_sym_EQ,
    STATE(140), 1,
      sym_comment,
  [3312] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(560), 1,
      anon_sym_LF,
    ACTIONS(562), 1,
      aux_sym_from_instruction_token2,
    STATE(141), 1,
      sym_comment,
  [3328] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(524), 1,
      anon_sym_DQUOTE,
    STATE(142), 1,
      sym_comment,
    STATE(171), 1,
      sym_double_quoted_string,
  [3344] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(564), 1,
      anon_sym_LBRACE,
    ACTIONS(566), 1,
      sym_variable,
    STATE(143), 1,
      sym_comment,
  [3360] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(568), 1,
      anon_sym_LBRACE,
    ACTIONS(570), 1,
      sym_variable,
    STATE(144), 1,
      sym_comment,
  [3376] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(572), 1,
      anon_sym_LF,
    ACTIONS(574), 1,
      aux_sym__env_key_token1,
    STATE(145), 1,
      sym_comment,
  [3392] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    STATE(146), 1,
      sym_comment,
    ACTIONS(576), 2,
      aux_sym_cmd_instruction_token1,
      anon_sym_DASH_DASH,
  [3406] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(578), 1,
      anon_sym_LF,
    ACTIONS(580), 1,
      aux_sym_label_pair_token1,
    STATE(147), 1,
      sym_comment,
  [3422] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(554), 1,
      anon_sym_LF,
    ACTIONS(582), 1,
      aux_sym__env_key_token1,
    STATE(148), 1,
      sym_comment,
  [3438] = 4,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(584), 1,
      anon_sym_LF,
    ACTIONS(586), 1,
      sym_line_continuation,
    STATE(149), 2,
      sym_comment,
      aux_sym_shell_command_repeat2,
  [3452] = 5,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(544), 1,
      sym_line_continuation,
    ACTIONS(589), 1,
      anon_sym_LF,
    STATE(149), 1,
      aux_sym_shell_command_repeat2,
    STATE(150), 1,
      sym_comment,
  [3468] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(591), 1,
      anon_sym_LF,
    ACTIONS(593), 1,
      aux_sym_label_pair_token1,
    STATE(151), 1,
      sym_comment,
  [3484] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(595), 1,
      anon_sym_LF,
    ACTIONS(597), 1,
      aux_sym_from_instruction_token2,
    STATE(152), 1,
      sym_comment,
  [3500] = 3,
    ACTIONS(3), 1,
      sym_line_continuation,
    STATE(153), 1,
      sym_comment,
    ACTIONS(599), 3,
      aux_sym_shell_fragment_token1,
      aux_sym_shell_fragment_token2,
      anon_sym_POUND,
  [3512] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(601), 1,
      anon_sym_LF,
    ACTIONS(603), 1,
      aux_sym__env_key_token1,
    STATE(154), 1,
      sym_comment,
  [3528] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(572), 1,
      anon_sym_LF,
    ACTIONS(574), 1,
      aux_sym_label_pair_token1,
    STATE(155), 1,
      sym_comment,
  [3544] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(605), 1,
      anon_sym_LBRACE,
    ACTIONS(607), 1,
      sym_variable,
    STATE(156), 1,
      sym_comment,
  [3560] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(576), 1,
      anon_sym_DOLLAR,
    ACTIONS(609), 1,
      aux_sym_path_token1,
    STATE(157), 1,
      sym_comment,
  [3576] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(611), 1,
      anon_sym_EQ,
    ACTIONS(613), 1,
      aux_sym__spaced_env_pair_token1,
    STATE(158), 1,
      sym_comment,
  [3592] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(554), 1,
      anon_sym_LF,
    ACTIONS(582), 1,
      aux_sym_label_pair_token1,
    STATE(159), 1,
      sym_comment,
  [3608] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(615), 1,
      anon_sym_LBRACE,
    ACTIONS(617), 1,
      sym_variable,
    STATE(160), 1,
      sym_comment,
  [3624] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(161), 1,
      sym_comment,
    ACTIONS(503), 2,
      anon_sym_LF,
      sym__non_newline_whitespace,
  [3638] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(619), 1,
      anon_sym_LF,
    ACTIONS(621), 1,
      aux_sym_from_instruction_token2,
    STATE(162), 1,
      sym_comment,
  [3654] = 5,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(623), 1,
      anon_sym_LF,
    ACTIONS(625), 1,
      aux_sym__env_key_token1,
    STATE(163), 1,
      sym_comment,
  [3670] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(627), 1,
      anon_sym_LBRACE,
    ACTIONS(629), 1,
      sym_variable,
    STATE(164), 1,
      sym_comment,
  [3686] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(576), 1,
      anon_sym_DOLLAR,
    ACTIONS(609), 1,
      aux_sym_image_name_token1,
    STATE(165), 1,
      sym_comment,
  [3702] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    STATE(166), 1,
      sym_comment,
    ACTIONS(631), 2,
      anon_sym_EQ,
      aux_sym__spaced_env_pair_token1,
  [3716] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(633), 1,
      anon_sym_LBRACE,
    ACTIONS(635), 1,
      sym_variable,
    STATE(167), 1,
      sym_comment,
  [3732] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    STATE(168), 1,
      sym_comment,
    ACTIONS(637), 2,
      aux_sym_cmd_instruction_token1,
      anon_sym_DASH_DASH,
  [3746] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    STATE(169), 1,
      sym_comment,
    ACTIONS(572), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3760] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(639), 1,
      anon_sym_LBRACE,
    ACTIONS(641), 1,
      sym_variable,
    STATE(170), 1,
      sym_comment,
  [3776] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    STATE(171), 1,
      sym_comment,
    ACTIONS(487), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3790] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(643), 1,
      anon_sym_LBRACE,
    ACTIONS(645), 1,
      sym_variable,
    STATE(172), 1,
      sym_comment,
  [3806] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(647), 1,
      anon_sym_LF,
    STATE(173), 1,
      sym_comment,
  [3819] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(649), 1,
      anon_sym_LF,
    STATE(174), 1,
      sym_comment,
  [3832] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(651), 1,
      anon_sym_LF,
    STATE(175), 1,
      sym_comment,
  [3845] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(653), 1,
      anon_sym_LF,
    STATE(176), 1,
      sym_comment,
  [3858] = 4,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(655), 1,
      anon_sym_LF,
    ACTIONS(657), 1,
      sym_line_continuation,
    STATE(177), 1,
      sym_comment,
  [3871] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(659), 1,
      aux_sym_expansion_token1,
    STATE(178), 1,
      sym_comment,
  [3884] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(661), 1,
      anon_sym_LF,
    STATE(179), 1,
      sym_comment,
  [3897] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(663), 1,
      anon_sym_LF,
    STATE(180), 1,
      sym_comment,
  [3910] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(665), 1,
      anon_sym_LF,
    STATE(181), 1,
      sym_comment,
  [3923] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(631), 1,
      anon_sym_EQ,
    STATE(182), 1,
      sym_comment,
  [3936] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(667), 1,
      anon_sym_LF,
    STATE(183), 1,
      sym_comment,
  [3949] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(669), 1,
      anon_sym_LF,
    STATE(184), 1,
      sym_comment,
  [3962] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(671), 1,
      ts_builtin_sym_end,
    STATE(185), 1,
      sym_comment,
  [3975] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(673), 1,
      aux_sym_arg_instruction_token2,
    STATE(186), 1,
      sym_comment,
  [3988] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(675), 1,
      aux_sym_maintainer_instruction_token2,
    STATE(187), 1,
      sym_comment,
  [4001] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(677), 1,
      aux_sym_maintainer_instruction_token2,
    STATE(188), 1,
      sym_comment,
  [4014] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(679), 1,
      sym__non_newline_whitespace,
    STATE(189), 1,
      sym_comment,
  [4027] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(681), 1,
      sym__non_newline_whitespace,
    STATE(190), 1,
      sym_comment,
  [4040] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(683), 1,
      anon_sym_LF,
    STATE(191), 1,
      sym_comment,
  [4053] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(685), 1,
      anon_sym_LF,
    STATE(192), 1,
      sym_comment,
  [4066] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(687), 1,
      sym__non_newline_whitespace,
    STATE(193), 1,
      sym_comment,
  [4079] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(689), 1,
      anon_sym_LF,
    STATE(194), 1,
      sym_comment,
  [4092] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(691), 1,
      sym__non_newline_whitespace,
    STATE(195), 1,
      sym_comment,
  [4105] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(693), 1,
      anon_sym_LF,
    STATE(196), 1,
      sym_comment,
  [4118] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(695), 1,
      sym__non_newline_whitespace,
    STATE(197), 1,
      sym_comment,
  [4131] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(697), 1,
      anon_sym_LF,
    STATE(198), 1,
      sym_comment,
  [4144] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(699), 1,
      aux_sym_param_token1,
    STATE(199), 1,
      sym_comment,
  [4157] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(701), 1,
      sym__non_newline_whitespace,
    STATE(200), 1,
      sym_comment,
  [4170] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(703), 1,
      anon_sym_LF,
    STATE(201), 1,
      sym_comment,
  [4183] = 4,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(584), 1,
      anon_sym_LF,
    ACTIONS(705), 1,
      sym_line_continuation,
    STATE(202), 1,
      sym_comment,
  [4196] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(707), 1,
      aux_sym_maintainer_instruction_token2,
    STATE(203), 1,
      sym_comment,
  [4209] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(709), 1,
      anon_sym_LF,
    STATE(204), 1,
      sym_comment,
  [4222] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(711), 1,
      anon_sym_LF,
    STATE(205), 1,
      sym_comment,
  [4235] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(713), 1,
      anon_sym_LF,
    STATE(206), 1,
      sym_comment,
  [4248] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(715), 1,
      aux_sym_param_token2,
    STATE(207), 1,
      sym_comment,
  [4261] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(717), 1,
      anon_sym_LF,
    STATE(208), 1,
      sym_comment,
  [4274] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(719), 1,
      anon_sym_EQ,
    STATE(209), 1,
      sym_comment,
  [4287] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(721), 1,
      aux_sym_maintainer_instruction_token2,
    STATE(210), 1,
      sym_comment,
  [4300] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(723), 1,
      sym__non_newline_whitespace,
    STATE(211), 1,
      sym_comment,
  [4313] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(725), 1,
      sym__non_newline_whitespace,
    STATE(212), 1,
      sym_comment,
  [4326] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(727), 1,
      sym__non_newline_whitespace,
    STATE(213), 1,
      sym_comment,
  [4339] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(729), 1,
      sym__non_newline_whitespace,
    STATE(214), 1,
      sym_comment,
  [4352] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(611), 1,
      anon_sym_EQ,
    STATE(215), 1,
      sym_comment,
  [4365] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(731), 1,
      anon_sym_RBRACE,
    STATE(216), 1,
      sym_comment,
  [4378] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(733), 1,
      sym__non_newline_whitespace,
    STATE(217), 1,
      sym_comment,
  [4391] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(735), 1,
      sym__non_newline_whitespace,
    STATE(218), 1,
      sym_comment,
  [4404] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(737), 1,
      sym__non_newline_whitespace,
    STATE(219), 1,
      sym_comment,
  [4417] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(739), 1,
      sym__non_newline_whitespace,
    STATE(220), 1,
      sym_comment,
  [4430] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(741), 1,
      anon_sym_LF,
    STATE(221), 1,
      sym_comment,
  [4443] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(743), 1,
      sym__non_newline_whitespace,
    STATE(222), 1,
      sym_comment,
  [4456] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(745), 1,
      anon_sym_RBRACE,
    STATE(223), 1,
      sym_comment,
  [4469] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(747), 1,
      aux_sym_param_token2,
    STATE(224), 1,
      sym_comment,
  [4482] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(749), 1,
      sym__non_newline_whitespace,
    STATE(225), 1,
      sym_comment,
  [4495] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(751), 1,
      anon_sym_EQ,
    STATE(226), 1,
      sym_comment,
  [4508] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(753), 1,
      sym__non_newline_whitespace,
    STATE(227), 1,
      sym_comment,
  [4521] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(755), 1,
      anon_sym_RBRACE,
    STATE(228), 1,
      sym_comment,
  [4534] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(757), 1,
      aux_sym_param_token2,
    STATE(229), 1,
      sym_comment,
  [4547] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(759), 1,
      sym__non_newline_whitespace,
    STATE(230), 1,
      sym_comment,
  [4560] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(761), 1,
      anon_sym_LF,
    STATE(231), 1,
      sym_comment,
  [4573] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(763), 1,
      anon_sym_RBRACE,
    STATE(232), 1,
      sym_comment,
  [4586] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(765), 1,
      anon_sym_LF,
    STATE(233), 1,
      sym_comment,
  [4599] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(767), 1,
      anon_sym_RBRACE,
    STATE(234), 1,
      sym_comment,
  [4612] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(769), 1,
      anon_sym_LF,
    STATE(235), 1,
      sym_comment,
  [4625] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(771), 1,
      anon_sym_RBRACE,
    STATE(236), 1,
      sym_comment,
  [4638] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(773), 1,
      anon_sym_LF,
    STATE(237), 1,
      sym_comment,
  [4651] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(775), 1,
      anon_sym_RBRACE,
    STATE(238), 1,
      sym_comment,
  [4664] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(777), 1,
      anon_sym_LF,
    STATE(239), 1,
      sym_comment,
  [4677] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(779), 1,
      anon_sym_RBRACE,
    STATE(240), 1,
      sym_comment,
  [4690] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(781), 1,
      anon_sym_LF,
    STATE(241), 1,
      sym_comment,
  [4703] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(783), 1,
      anon_sym_RBRACE,
    STATE(242), 1,
      sym_comment,
  [4716] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(785), 1,
      sym__non_newline_whitespace,
    STATE(243), 1,
      sym_comment,
  [4729] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(787), 1,
      anon_sym_RBRACE,
    STATE(244), 1,
      sym_comment,
  [4742] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(789), 1,
      sym__non_newline_whitespace,
    STATE(245), 1,
      sym_comment,
  [4755] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(791), 1,
      anon_sym_RBRACE,
    STATE(246), 1,
      sym_comment,
  [4768] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(793), 1,
      anon_sym_LF,
    STATE(247), 1,
      sym_comment,
  [4781] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(795), 1,
      anon_sym_RBRACE,
    STATE(248), 1,
      sym_comment,
  [4794] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(797), 1,
      aux_sym_expansion_token1,
    STATE(249), 1,
      sym_comment,
  [4807] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(799), 1,
      anon_sym_EQ,
    STATE(250), 1,
      sym_comment,
  [4820] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(801), 1,
      aux_sym_expansion_token1,
    STATE(251), 1,
      sym_comment,
  [4833] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(803), 1,
      anon_sym_EQ,
    STATE(252), 1,
      sym_comment,
  [4846] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(805), 1,
      aux_sym_expansion_token1,
    STATE(253), 1,
      sym_comment,
  [4859] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(807), 1,
      aux_sym_expansion_token1,
    STATE(254), 1,
      sym_comment,
  [4872] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(809), 1,
      aux_sym_expansion_token1,
    STATE(255), 1,
      sym_comment,
  [4885] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(811), 1,
      aux_sym_expansion_token1,
    STATE(256), 1,
      sym_comment,
  [4898] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(813), 1,
      aux_sym_expansion_token1,
    STATE(257), 1,
      sym_comment,
  [4911] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(815), 1,
      aux_sym_expansion_token1,
    STATE(258), 1,
      sym_comment,
  [4924] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(817), 1,
      aux_sym_expansion_token1,
    STATE(259), 1,
      sym_comment,
  [4937] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(819), 1,
      aux_sym_expansion_token1,
    STATE(260), 1,
      sym_comment,
  [4950] = 4,
    ACTIONS(116), 1,
      sym_line_continuation,
    ACTIONS(118), 1,
      anon_sym_POUND,
    ACTIONS(821), 1,
      aux_sym_expansion_token1,
    STATE(261), 1,
      sym_comment,
  [4963] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(823), 1,
      aux_sym_param_token1,
    STATE(262), 1,
      sym_comment,
  [4976] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      anon_sym_POUND,
    ACTIONS(825), 1,
      aux_sym_param_token1,
    STATE(263), 1,
      sym_comment,
  [4989] = 1,
    ACTIONS(827), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 95,
  [SMALL_STATE(4)] = 192,
  [SMALL_STATE(5)] = 283,
  [SMALL_STATE(6)] = 315,
  [SMALL_STATE(7)] = 345,
  [SMALL_STATE(8)] = 379,
  [SMALL_STATE(9)] = 407,
  [SMALL_STATE(10)] = 439,
  [SMALL_STATE(11)] = 471,
  [SMALL_STATE(12)] = 503,
  [SMALL_STATE(13)] = 535,
  [SMALL_STATE(14)] = 562,
  [SMALL_STATE(15)] = 589,
  [SMALL_STATE(16)] = 616,
  [SMALL_STATE(17)] = 645,
  [SMALL_STATE(18)] = 672,
  [SMALL_STATE(19)] = 699,
  [SMALL_STATE(20)] = 730,
  [SMALL_STATE(21)] = 759,
  [SMALL_STATE(22)] = 786,
  [SMALL_STATE(23)] = 815,
  [SMALL_STATE(24)] = 846,
  [SMALL_STATE(25)] = 870,
  [SMALL_STATE(26)] = 898,
  [SMALL_STATE(27)] = 918,
  [SMALL_STATE(28)] = 944,
  [SMALL_STATE(29)] = 970,
  [SMALL_STATE(30)] = 990,
  [SMALL_STATE(31)] = 1016,
  [SMALL_STATE(32)] = 1042,
  [SMALL_STATE(33)] = 1070,
  [SMALL_STATE(34)] = 1094,
  [SMALL_STATE(35)] = 1120,
  [SMALL_STATE(36)] = 1144,
  [SMALL_STATE(37)] = 1172,
  [SMALL_STATE(38)] = 1200,
  [SMALL_STATE(39)] = 1228,
  [SMALL_STATE(40)] = 1256,
  [SMALL_STATE(41)] = 1284,
  [SMALL_STATE(42)] = 1312,
  [SMALL_STATE(43)] = 1340,
  [SMALL_STATE(44)] = 1360,
  [SMALL_STATE(45)] = 1388,
  [SMALL_STATE(46)] = 1416,
  [SMALL_STATE(47)] = 1444,
  [SMALL_STATE(48)] = 1472,
  [SMALL_STATE(49)] = 1500,
  [SMALL_STATE(50)] = 1523,
  [SMALL_STATE(51)] = 1542,
  [SMALL_STATE(52)] = 1561,
  [SMALL_STATE(53)] = 1580,
  [SMALL_STATE(54)] = 1605,
  [SMALL_STATE(55)] = 1628,
  [SMALL_STATE(56)] = 1653,
  [SMALL_STATE(57)] = 1678,
  [SMALL_STATE(58)] = 1703,
  [SMALL_STATE(59)] = 1724,
  [SMALL_STATE(60)] = 1743,
  [SMALL_STATE(61)] = 1768,
  [SMALL_STATE(62)] = 1791,
  [SMALL_STATE(63)] = 1810,
  [SMALL_STATE(64)] = 1829,
  [SMALL_STATE(65)] = 1854,
  [SMALL_STATE(66)] = 1879,
  [SMALL_STATE(67)] = 1904,
  [SMALL_STATE(68)] = 1923,
  [SMALL_STATE(69)] = 1948,
  [SMALL_STATE(70)] = 1971,
  [SMALL_STATE(71)] = 1990,
  [SMALL_STATE(72)] = 2013,
  [SMALL_STATE(73)] = 2032,
  [SMALL_STATE(74)] = 2051,
  [SMALL_STATE(75)] = 2076,
  [SMALL_STATE(76)] = 2101,
  [SMALL_STATE(77)] = 2120,
  [SMALL_STATE(78)] = 2145,
  [SMALL_STATE(79)] = 2164,
  [SMALL_STATE(80)] = 2187,
  [SMALL_STATE(81)] = 2209,
  [SMALL_STATE(82)] = 2227,
  [SMALL_STATE(83)] = 2249,
  [SMALL_STATE(84)] = 2271,
  [SMALL_STATE(85)] = 2287,
  [SMALL_STATE(86)] = 2309,
  [SMALL_STATE(87)] = 2331,
  [SMALL_STATE(88)] = 2353,
  [SMALL_STATE(89)] = 2369,
  [SMALL_STATE(90)] = 2391,
  [SMALL_STATE(91)] = 2409,
  [SMALL_STATE(92)] = 2431,
  [SMALL_STATE(93)] = 2449,
  [SMALL_STATE(94)] = 2465,
  [SMALL_STATE(95)] = 2485,
  [SMALL_STATE(96)] = 2503,
  [SMALL_STATE(97)] = 2523,
  [SMALL_STATE(98)] = 2545,
  [SMALL_STATE(99)] = 2567,
  [SMALL_STATE(100)] = 2585,
  [SMALL_STATE(101)] = 2605,
  [SMALL_STATE(102)] = 2623,
  [SMALL_STATE(103)] = 2641,
  [SMALL_STATE(104)] = 2663,
  [SMALL_STATE(105)] = 2685,
  [SMALL_STATE(106)] = 2707,
  [SMALL_STATE(107)] = 2729,
  [SMALL_STATE(108)] = 2751,
  [SMALL_STATE(109)] = 2769,
  [SMALL_STATE(110)] = 2786,
  [SMALL_STATE(111)] = 2805,
  [SMALL_STATE(112)] = 2822,
  [SMALL_STATE(113)] = 2839,
  [SMALL_STATE(114)] = 2856,
  [SMALL_STATE(115)] = 2873,
  [SMALL_STATE(116)] = 2892,
  [SMALL_STATE(117)] = 2909,
  [SMALL_STATE(118)] = 2926,
  [SMALL_STATE(119)] = 2943,
  [SMALL_STATE(120)] = 2962,
  [SMALL_STATE(121)] = 2979,
  [SMALL_STATE(122)] = 2996,
  [SMALL_STATE(123)] = 3013,
  [SMALL_STATE(124)] = 3032,
  [SMALL_STATE(125)] = 3049,
  [SMALL_STATE(126)] = 3066,
  [SMALL_STATE(127)] = 3085,
  [SMALL_STATE(128)] = 3100,
  [SMALL_STATE(129)] = 3119,
  [SMALL_STATE(130)] = 3136,
  [SMALL_STATE(131)] = 3153,
  [SMALL_STATE(132)] = 3170,
  [SMALL_STATE(133)] = 3186,
  [SMALL_STATE(134)] = 3202,
  [SMALL_STATE(135)] = 3218,
  [SMALL_STATE(136)] = 3234,
  [SMALL_STATE(137)] = 3250,
  [SMALL_STATE(138)] = 3266,
  [SMALL_STATE(139)] = 3282,
  [SMALL_STATE(140)] = 3296,
  [SMALL_STATE(141)] = 3312,
  [SMALL_STATE(142)] = 3328,
  [SMALL_STATE(143)] = 3344,
  [SMALL_STATE(144)] = 3360,
  [SMALL_STATE(145)] = 3376,
  [SMALL_STATE(146)] = 3392,
  [SMALL_STATE(147)] = 3406,
  [SMALL_STATE(148)] = 3422,
  [SMALL_STATE(149)] = 3438,
  [SMALL_STATE(150)] = 3452,
  [SMALL_STATE(151)] = 3468,
  [SMALL_STATE(152)] = 3484,
  [SMALL_STATE(153)] = 3500,
  [SMALL_STATE(154)] = 3512,
  [SMALL_STATE(155)] = 3528,
  [SMALL_STATE(156)] = 3544,
  [SMALL_STATE(157)] = 3560,
  [SMALL_STATE(158)] = 3576,
  [SMALL_STATE(159)] = 3592,
  [SMALL_STATE(160)] = 3608,
  [SMALL_STATE(161)] = 3624,
  [SMALL_STATE(162)] = 3638,
  [SMALL_STATE(163)] = 3654,
  [SMALL_STATE(164)] = 3670,
  [SMALL_STATE(165)] = 3686,
  [SMALL_STATE(166)] = 3702,
  [SMALL_STATE(167)] = 3716,
  [SMALL_STATE(168)] = 3732,
  [SMALL_STATE(169)] = 3746,
  [SMALL_STATE(170)] = 3760,
  [SMALL_STATE(171)] = 3776,
  [SMALL_STATE(172)] = 3790,
  [SMALL_STATE(173)] = 3806,
  [SMALL_STATE(174)] = 3819,
  [SMALL_STATE(175)] = 3832,
  [SMALL_STATE(176)] = 3845,
  [SMALL_STATE(177)] = 3858,
  [SMALL_STATE(178)] = 3871,
  [SMALL_STATE(179)] = 3884,
  [SMALL_STATE(180)] = 3897,
  [SMALL_STATE(181)] = 3910,
  [SMALL_STATE(182)] = 3923,
  [SMALL_STATE(183)] = 3936,
  [SMALL_STATE(184)] = 3949,
  [SMALL_STATE(185)] = 3962,
  [SMALL_STATE(186)] = 3975,
  [SMALL_STATE(187)] = 3988,
  [SMALL_STATE(188)] = 4001,
  [SMALL_STATE(189)] = 4014,
  [SMALL_STATE(190)] = 4027,
  [SMALL_STATE(191)] = 4040,
  [SMALL_STATE(192)] = 4053,
  [SMALL_STATE(193)] = 4066,
  [SMALL_STATE(194)] = 4079,
  [SMALL_STATE(195)] = 4092,
  [SMALL_STATE(196)] = 4105,
  [SMALL_STATE(197)] = 4118,
  [SMALL_STATE(198)] = 4131,
  [SMALL_STATE(199)] = 4144,
  [SMALL_STATE(200)] = 4157,
  [SMALL_STATE(201)] = 4170,
  [SMALL_STATE(202)] = 4183,
  [SMALL_STATE(203)] = 4196,
  [SMALL_STATE(204)] = 4209,
  [SMALL_STATE(205)] = 4222,
  [SMALL_STATE(206)] = 4235,
  [SMALL_STATE(207)] = 4248,
  [SMALL_STATE(208)] = 4261,
  [SMALL_STATE(209)] = 4274,
  [SMALL_STATE(210)] = 4287,
  [SMALL_STATE(211)] = 4300,
  [SMALL_STATE(212)] = 4313,
  [SMALL_STATE(213)] = 4326,
  [SMALL_STATE(214)] = 4339,
  [SMALL_STATE(215)] = 4352,
  [SMALL_STATE(216)] = 4365,
  [SMALL_STATE(217)] = 4378,
  [SMALL_STATE(218)] = 4391,
  [SMALL_STATE(219)] = 4404,
  [SMALL_STATE(220)] = 4417,
  [SMALL_STATE(221)] = 4430,
  [SMALL_STATE(222)] = 4443,
  [SMALL_STATE(223)] = 4456,
  [SMALL_STATE(224)] = 4469,
  [SMALL_STATE(225)] = 4482,
  [SMALL_STATE(226)] = 4495,
  [SMALL_STATE(227)] = 4508,
  [SMALL_STATE(228)] = 4521,
  [SMALL_STATE(229)] = 4534,
  [SMALL_STATE(230)] = 4547,
  [SMALL_STATE(231)] = 4560,
  [SMALL_STATE(232)] = 4573,
  [SMALL_STATE(233)] = 4586,
  [SMALL_STATE(234)] = 4599,
  [SMALL_STATE(235)] = 4612,
  [SMALL_STATE(236)] = 4625,
  [SMALL_STATE(237)] = 4638,
  [SMALL_STATE(238)] = 4651,
  [SMALL_STATE(239)] = 4664,
  [SMALL_STATE(240)] = 4677,
  [SMALL_STATE(241)] = 4690,
  [SMALL_STATE(242)] = 4703,
  [SMALL_STATE(243)] = 4716,
  [SMALL_STATE(244)] = 4729,
  [SMALL_STATE(245)] = 4742,
  [SMALL_STATE(246)] = 4755,
  [SMALL_STATE(247)] = 4768,
  [SMALL_STATE(248)] = 4781,
  [SMALL_STATE(249)] = 4794,
  [SMALL_STATE(250)] = 4807,
  [SMALL_STATE(251)] = 4820,
  [SMALL_STATE(252)] = 4833,
  [SMALL_STATE(253)] = 4846,
  [SMALL_STATE(254)] = 4859,
  [SMALL_STATE(255)] = 4872,
  [SMALL_STATE(256)] = 4885,
  [SMALL_STATE(257)] = 4898,
  [SMALL_STATE(258)] = 4911,
  [SMALL_STATE(259)] = 4924,
  [SMALL_STATE(260)] = 4937,
  [SMALL_STATE(261)] = 4950,
  [SMALL_STATE(262)] = 4963,
  [SMALL_STATE(263)] = 4976,
  [SMALL_STATE(264)] = 4989,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(230),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(227),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(225),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(222),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(79),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(220),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(219),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(218),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(217),
  [76] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(212),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(211),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(200),
  [85] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(197),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(195),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(193),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(190),
  [97] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(189),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(188),
  [103] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(187),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_name, 1),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_name, 1),
  [112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(164),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(210),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(199),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_name_repeat1, 2),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_name_repeat1, 2),
  [128] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_name_repeat1, 2), SHIFT_REPEAT(164),
  [131] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_name_repeat1, 2), SHIFT_REPEAT(43),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_tag_repeat1, 2),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_tag_repeat1, 2),
  [160] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_tag_repeat1, 2), SHIFT_REPEAT(132),
  [163] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_tag_repeat1, 2), SHIFT_REPEAT(59),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_unquoted_string_repeat1, 2),
  [168] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 2), SHIFT_REPEAT(134),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 2),
  [173] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 2), SHIFT_REPEAT(63),
  [176] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_unquoted_string_repeat1, 2), SHIFT_REPEAT(63),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquoted_string, 1),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquoted_string, 1),
  [185] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 2), SHIFT_REPEAT(160),
  [188] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 2), SHIFT_REPEAT(51),
  [191] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_unquoted_string_repeat1, 2), SHIFT_REPEAT(51),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_tag, 2),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_tag, 2),
  [198] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [200] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expose_instruction_repeat1, 2),
  [206] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_expose_instruction_repeat1, 2), SHIFT_REPEAT(170),
  [209] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_expose_instruction_repeat1, 2), SHIFT_REPEAT(58),
  [212] = {.entry = {.count = 1, .reusable = false}}, SHIFT(156),
  [214] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [218] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expansion, 2),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expansion, 2),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_path, 1),
  [226] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [228] = {.entry = {.count = 1, .reusable = false}}, SHIFT(172),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_path, 2),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expansion, 4),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expansion, 4),
  [236] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2), SHIFT_REPEAT(156),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2),
  [241] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2), SHIFT_REPEAT(90),
  [244] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2), SHIFT_REPEAT(90),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_digest_repeat1, 2),
  [249] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_digest_repeat1, 2),
  [251] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_digest_repeat1, 2), SHIFT_REPEAT(143),
  [254] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_image_digest_repeat1, 2), SHIFT_REPEAT(92),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_digest, 2),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_digest, 2),
  [261] = {.entry = {.count = 1, .reusable = false}}, SHIFT(143),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2),
  [267] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(84),
  [270] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(172),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expose_instruction, 2),
  [275] = {.entry = {.count = 1, .reusable = false}}, SHIFT(170),
  [277] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__user_name_group, 2),
  [281] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__user_name_group, 2), SHIFT_REPEAT(95),
  [284] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__user_name_group, 2), SHIFT_REPEAT(170),
  [287] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [293] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [295] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 1, .production_id = 1),
  [301] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 1, .production_id = 1),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [307] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_name_repeat1, 1),
  [311] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_name_repeat1, 1),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(263),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_instruction, 3, .production_id = 3),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [323] = {.entry = {.count = 1, .reusable = false}}, SHIFT(159),
  [325] = {.entry = {.count = 1, .reusable = false}}, SHIFT(155),
  [327] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [329] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_alias_repeat1, 2),
  [331] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_alias_repeat1, 2), SHIFT_REPEAT(137),
  [334] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_alias_repeat1, 2), SHIFT_REPEAT(130),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_unquoted_string_repeat1, 1),
  [339] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 1),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [345] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(121),
  [348] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(167),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2),
  [353] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_instruction, 5, .production_id = 11),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [357] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expose_port, 1),
  [359] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expose_port, 1),
  [361] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [363] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_tag_repeat1, 1),
  [365] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_tag_repeat1, 1),
  [367] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_alias, 1),
  [369] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [371] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stopsignal_value, 2),
  [375] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__stopsignal_value, 2), SHIFT_REPEAT(112),
  [378] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__stopsignal_value, 2), SHIFT_REPEAT(135),
  [381] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_command_repeat1, 2),
  [383] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_shell_command_repeat1, 2), SHIFT_REPEAT(203),
  [386] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [388] = {.entry = {.count = 1, .reusable = false}}, SHIFT(167),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 2),
  [392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 1),
  [394] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [396] = {.entry = {.count = 1, .reusable = false}}, SHIFT(144),
  [398] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(118),
  [401] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(144),
  [404] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_env_instruction_repeat1, 2),
  [406] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_env_instruction_repeat1, 2), SHIFT_REPEAT(182),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_env_instruction, 3),
  [411] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [413] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stopsignal_instruction, 3),
  [415] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [417] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [423] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_instruction, 3),
  [425] = {.entry = {.count = 1, .reusable = false}}, SHIFT(209),
  [427] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [431] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 1),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [437] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 1),
  [439] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 1),
  [441] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_digest_repeat1, 1),
  [443] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_digest_repeat1, 1),
  [445] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_fragment, 1),
  [447] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [449] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_shell_fragment, 1),
  [451] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__user_name_group, 1),
  [453] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__user_name_group, 1),
  [455] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_healthcheck_instruction_repeat1, 2),
  [457] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_healthcheck_instruction_repeat1, 2), SHIFT_REPEAT(263),
  [460] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_fragment_repeat1, 2),
  [462] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_shell_fragment_repeat1, 2), SHIFT_REPEAT(127),
  [465] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_shell_fragment_repeat1, 2),
  [467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_label_instruction_repeat1, 2),
  [469] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_label_instruction_repeat1, 2), SHIFT_REPEAT(209),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [476] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 2, .production_id = 5),
  [478] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 2, .production_id = 5),
  [480] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_volume_instruction, 3),
  [482] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [484] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_array_repeat1, 2), SHIFT_REPEAT(142),
  [487] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_array_repeat1, 2),
  [489] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stopsignal_value, 1),
  [491] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__stopsignal_value, 1),
  [493] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expose_instruction_repeat1, 1),
  [495] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_expose_instruction_repeat1, 1),
  [497] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expose_port, 2),
  [499] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expose_port, 2),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [503] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_volume_instruction_repeat1, 2),
  [505] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_volume_instruction_repeat1, 2), SHIFT_REPEAT(103),
  [508] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 1),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [514] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_volume_instruction, 4),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [518] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_fragment_repeat1, 1),
  [520] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_shell_fragment_repeat1, 1),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [526] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_alias_repeat1, 1),
  [528] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_alias_repeat1, 1),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(255),
  [540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [542] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_command, 1),
  [544] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [548] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [550] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 3, .production_id = 8),
  [552] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 3, .production_id = 8),
  [554] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 2),
  [556] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_instruction, 3, .production_id = 4),
  [558] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [560] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 3),
  [562] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [564] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [566] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [568] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [570] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [572] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 3),
  [574] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 3),
  [576] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param, 4, .production_id = 13),
  [578] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_label_instruction_repeat1, 1),
  [580] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_label_instruction_repeat1, 1),
  [582] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 2),
  [584] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_command_repeat2, 2),
  [586] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_shell_command_repeat2, 2), SHIFT_REPEAT(21),
  [589] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_command, 2),
  [591] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_pair, 3, .production_id = 9),
  [593] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label_pair, 3, .production_id = 9),
  [595] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 4),
  [597] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [599] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__comment_line, 2),
  [601] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_env_pair, 3, .production_id = 10),
  [603] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_env_pair, 3, .production_id = 10),
  [605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [609] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_param, 4, .production_id = 13),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [619] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 2, .production_id = 6),
  [621] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 2, .production_id = 6),
  [623] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_env_instruction_repeat1, 1),
  [625] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_env_instruction_repeat1, 1),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [631] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__env_key, 1),
  [633] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [635] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [637] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_healthcheck_instruction_repeat1, 1),
  [639] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [641] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [643] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [645] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [647] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cmd_instruction, 3),
  [649] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 6, .production_id = 14),
  [651] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__anon_comment, 2),
  [653] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_array, 4),
  [655] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_command_repeat2, 3),
  [657] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_shell_command_repeat2, 3),
  [659] = {.entry = {.count = 1, .reusable = false}}, SHIFT(216),
  [661] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_instruction, 6),
  [663] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_copy_instruction, 6),
  [665] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__instruction, 1),
  [667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [669] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_instruction, 5, .production_id = 12),
  [671] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [673] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [675] = {.entry = {.count = 1, .reusable = false}}, SHIFT(198),
  [677] = {.entry = {.count = 1, .reusable = false}}, SHIFT(196),
  [679] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [681] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [683] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_copy_instruction, 5),
  [685] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_instruction, 5),
  [687] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [689] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__spaced_env_pair, 3, .production_id = 10),
  [691] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [693] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_maintainer_instruction, 2),
  [695] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [697] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cross_build_instruction, 2),
  [699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [705] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_shell_command_repeat2, 2),
  [707] = {.entry = {.count = 1, .reusable = false}}, SHIFT(175),
  [709] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_array, 3),
  [711] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_run_instruction, 3),
  [713] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 5, .production_id = 7),
  [715] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [717] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_healthcheck_instruction, 4),
  [719] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [721] = {.entry = {.count = 1, .reusable = false}}, SHIFT(264),
  [723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [727] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [729] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [731] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [733] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [735] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [737] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [739] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [741] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_array, 2),
  [743] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [745] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [747] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [749] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [751] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [753] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [755] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [757] = {.entry = {.count = 1, .reusable = false}}, SHIFT(146),
  [759] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [761] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_instruction, 3),
  [763] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [765] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_healthcheck_instruction, 3),
  [767] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [769] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_onbuild_instruction, 3),
  [771] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [773] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_workdir_instruction, 3),
  [775] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [777] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_volume_instruction, 3),
  [779] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [781] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entrypoint_instruction, 3),
  [783] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [785] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [787] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [789] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [791] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [793] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_env_instruction, 3, .production_id = 2),
  [795] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [797] = {.entry = {.count = 1, .reusable = false}}, SHIFT(223),
  [799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [801] = {.entry = {.count = 1, .reusable = false}}, SHIFT(228),
  [803] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [805] = {.entry = {.count = 1, .reusable = false}}, SHIFT(232),
  [807] = {.entry = {.count = 1, .reusable = false}}, SHIFT(234),
  [809] = {.entry = {.count = 1, .reusable = false}}, SHIFT(236),
  [811] = {.entry = {.count = 1, .reusable = false}}, SHIFT(238),
  [813] = {.entry = {.count = 1, .reusable = false}}, SHIFT(240),
  [815] = {.entry = {.count = 1, .reusable = false}}, SHIFT(242),
  [817] = {.entry = {.count = 1, .reusable = false}}, SHIFT(244),
  [819] = {.entry = {.count = 1, .reusable = false}}, SHIFT(246),
  [821] = {.entry = {.count = 1, .reusable = false}}, SHIFT(248),
  [823] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [825] = {.entry = {.count = 1, .reusable = true}}, SHIFT(252),
  [827] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_dockerfile(void) {
  static TSLanguage language = {
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
    .parse_table = (const uint16_t *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
