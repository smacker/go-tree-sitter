#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 325
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 164
#define ALIAS_COUNT 0
#define TOKEN_COUNT 87
#define EXTERNAL_TOKEN_COUNT 5
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 16

enum ts_symbol_identifiers {
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
  aux_sym__immediate_user_name_or_group_fragment_token1 = 16,
  aux_sym_workdir_instruction_token1 = 17,
  aux_sym_arg_instruction_token1 = 18,
  aux_sym_arg_instruction_token2 = 19,
  anon_sym_EQ = 20,
  aux_sym_onbuild_instruction_token1 = 21,
  aux_sym_stopsignal_instruction_token1 = 22,
  aux_sym__stopsignal_value_token1 = 23,
  aux_sym__stopsignal_value_token2 = 24,
  aux_sym_healthcheck_instruction_token1 = 25,
  anon_sym_NONE = 26,
  aux_sym_shell_instruction_token1 = 27,
  aux_sym_maintainer_instruction_token1 = 28,
  aux_sym_maintainer_instruction_token2 = 29,
  aux_sym_cross_build_instruction_token1 = 30,
  aux_sym_path_token1 = 31,
  aux_sym_path_token2 = 32,
  aux_sym_path_token3 = 33,
  aux_sym_path_with_heredoc_token1 = 34,
  anon_sym_DOLLAR = 35,
  anon_sym_DOLLAR2 = 36,
  anon_sym_LBRACE = 37,
  aux_sym__expansion_body_token1 = 38,
  anon_sym_RBRACE = 39,
  sym_variable = 40,
  aux_sym__spaced_env_pair_token1 = 41,
  aux_sym__env_key_token1 = 42,
  aux_sym_expose_port_token1 = 43,
  anon_sym_SLASHtcp = 44,
  anon_sym_SLASHudp = 45,
  aux_sym_label_pair_token1 = 46,
  aux_sym_image_name_token1 = 47,
  aux_sym_image_name_token2 = 48,
  aux_sym_image_tag_token1 = 49,
  anon_sym_AT = 50,
  aux_sym_image_digest_token1 = 51,
  anon_sym_DASH_DASH = 52,
  aux_sym_param_token1 = 53,
  aux_sym_param_token2 = 54,
  anon_sym_mount = 55,
  anon_sym_COMMA = 56,
  aux_sym_mount_param_param_token1 = 57,
  aux_sym_image_alias_token1 = 58,
  aux_sym_image_alias_token2 = 59,
  aux_sym_shell_fragment_token1 = 60,
  aux_sym_shell_fragment_token2 = 61,
  aux_sym_shell_fragment_token3 = 62,
  aux_sym_shell_fragment_token4 = 63,
  sym_line_continuation = 64,
  sym_required_line_continuation = 65,
  anon_sym_LBRACK = 66,
  anon_sym_COMMA2 = 67,
  anon_sym_RBRACK = 68,
  anon_sym_DQUOTE = 69,
  aux_sym_json_string_token1 = 70,
  sym_json_escape_sequence = 71,
  aux_sym_double_quoted_string_token1 = 72,
  anon_sym_BSLASH = 73,
  anon_sym_SQUOTE = 74,
  aux_sym_single_quoted_string_token1 = 75,
  aux_sym_unquoted_string_token1 = 76,
  anon_sym_BSLASH2 = 77,
  sym_double_quoted_escape_sequence = 78,
  sym_single_quoted_escape_sequence = 79,
  sym__non_newline_whitespace = 80,
  sym_comment = 81,
  sym_heredoc_marker = 82,
  sym_heredoc_line = 83,
  sym_heredoc_end = 84,
  sym_heredoc_nl = 85,
  sym_error_sentinel = 86,
  sym_source_file = 87,
  sym__instruction = 88,
  sym_from_instruction = 89,
  sym_run_instruction = 90,
  sym_cmd_instruction = 91,
  sym_label_instruction = 92,
  sym_expose_instruction = 93,
  sym_env_instruction = 94,
  sym_add_instruction = 95,
  sym_copy_instruction = 96,
  sym_entrypoint_instruction = 97,
  sym_volume_instruction = 98,
  sym_user_instruction = 99,
  sym__user_name_or_group = 100,
  aux_sym__immediate_user_name_or_group = 101,
  sym__immediate_user_name_or_group_fragment = 102,
  sym_workdir_instruction = 103,
  sym_arg_instruction = 104,
  sym_onbuild_instruction = 105,
  sym_stopsignal_instruction = 106,
  sym__stopsignal_value = 107,
  sym_healthcheck_instruction = 108,
  sym_shell_instruction = 109,
  sym_maintainer_instruction = 110,
  sym_cross_build_instruction = 111,
  sym_heredoc_block = 112,
  sym_path = 113,
  sym_path_with_heredoc = 114,
  sym_expansion = 115,
  sym__immediate_expansion = 116,
  sym__imm_expansion = 117,
  sym__expansion_body = 118,
  sym_env_pair = 119,
  sym__spaced_env_pair = 120,
  sym__env_key = 121,
  sym_expose_port = 122,
  sym_label_pair = 123,
  sym_image_spec = 124,
  sym_image_name = 125,
  sym_image_tag = 126,
  sym_image_digest = 127,
  sym_param = 128,
  sym_mount_param = 129,
  sym_mount_param_param = 130,
  sym_image_alias = 131,
  sym_shell_command = 132,
  sym_shell_fragment = 133,
  sym_json_string_array = 134,
  sym_json_string = 135,
  sym_double_quoted_string = 136,
  sym_single_quoted_string = 137,
  sym_unquoted_string = 138,
  aux_sym_source_file_repeat1 = 139,
  aux_sym_run_instruction_repeat1 = 140,
  aux_sym_run_instruction_repeat2 = 141,
  aux_sym_label_instruction_repeat1 = 142,
  aux_sym_expose_instruction_repeat1 = 143,
  aux_sym_env_instruction_repeat1 = 144,
  aux_sym_add_instruction_repeat1 = 145,
  aux_sym_add_instruction_repeat2 = 146,
  aux_sym_volume_instruction_repeat1 = 147,
  aux_sym__user_name_or_group_repeat1 = 148,
  aux_sym__stopsignal_value_repeat1 = 149,
  aux_sym_heredoc_block_repeat1 = 150,
  aux_sym_path_repeat1 = 151,
  aux_sym_image_name_repeat1 = 152,
  aux_sym_image_tag_repeat1 = 153,
  aux_sym_image_digest_repeat1 = 154,
  aux_sym_mount_param_repeat1 = 155,
  aux_sym_image_alias_repeat1 = 156,
  aux_sym_shell_command_repeat1 = 157,
  aux_sym_shell_fragment_repeat1 = 158,
  aux_sym_json_string_array_repeat1 = 159,
  aux_sym_json_string_repeat1 = 160,
  aux_sym_double_quoted_string_repeat1 = 161,
  aux_sym_single_quoted_string_repeat1 = 162,
  aux_sym_unquoted_string_repeat1 = 163,
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
  [aux_sym__immediate_user_name_or_group_fragment_token1] = "_immediate_user_name_or_group_fragment_token1",
  [aux_sym_workdir_instruction_token1] = "WORKDIR",
  [aux_sym_arg_instruction_token1] = "ARG",
  [aux_sym_arg_instruction_token2] = "unquoted_string",
  [anon_sym_EQ] = "=",
  [aux_sym_onbuild_instruction_token1] = "ONBUILD",
  [aux_sym_stopsignal_instruction_token1] = "STOPSIGNAL",
  [aux_sym__stopsignal_value_token1] = "_stopsignal_value_token1",
  [aux_sym__stopsignal_value_token2] = "_stopsignal_value_token2",
  [aux_sym_healthcheck_instruction_token1] = "HEALTHCHECK",
  [anon_sym_NONE] = "NONE",
  [aux_sym_shell_instruction_token1] = "SHELL",
  [aux_sym_maintainer_instruction_token1] = "MAINTAINER",
  [aux_sym_maintainer_instruction_token2] = "maintainer_instruction_token2",
  [aux_sym_cross_build_instruction_token1] = "CROSS_BUILD",
  [aux_sym_path_token1] = "path_token1",
  [aux_sym_path_token2] = "path_token2",
  [aux_sym_path_token3] = "path_token3",
  [aux_sym_path_with_heredoc_token1] = "path_with_heredoc_token1",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_DOLLAR2] = "$",
  [anon_sym_LBRACE] = "{",
  [aux_sym__expansion_body_token1] = "variable",
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
  [anon_sym_mount] = "mount",
  [anon_sym_COMMA] = ",",
  [aux_sym_mount_param_param_token1] = "mount_param_param_token1",
  [aux_sym_image_alias_token1] = "image_alias_token1",
  [aux_sym_image_alias_token2] = "image_alias_token2",
  [aux_sym_shell_fragment_token1] = "shell_fragment_token1",
  [aux_sym_shell_fragment_token2] = "shell_fragment_token2",
  [aux_sym_shell_fragment_token3] = "shell_fragment_token3",
  [aux_sym_shell_fragment_token4] = "shell_fragment_token4",
  [sym_line_continuation] = "line_continuation",
  [sym_required_line_continuation] = "line_continuation",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA2] = ",",
  [anon_sym_RBRACK] = "]",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_json_string_token1] = "json_string_token1",
  [sym_json_escape_sequence] = "escape_sequence",
  [aux_sym_double_quoted_string_token1] = "double_quoted_string_token1",
  [anon_sym_BSLASH] = "\\",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_single_quoted_string_token1] = "single_quoted_string_token1",
  [aux_sym_unquoted_string_token1] = "unquoted_string_token1",
  [anon_sym_BSLASH2] = "\\ ",
  [sym_double_quoted_escape_sequence] = "escape_sequence",
  [sym_single_quoted_escape_sequence] = "escape_sequence",
  [sym__non_newline_whitespace] = "_non_newline_whitespace",
  [sym_comment] = "comment",
  [sym_heredoc_marker] = "heredoc_marker",
  [sym_heredoc_line] = "heredoc_line",
  [sym_heredoc_end] = "heredoc_end",
  [sym_heredoc_nl] = "_heredoc_nl",
  [sym_error_sentinel] = "error_sentinel",
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
  [sym__user_name_or_group] = "unquoted_string",
  [aux_sym__immediate_user_name_or_group] = "_immediate_user_name_or_group",
  [sym__immediate_user_name_or_group_fragment] = "_immediate_user_name_or_group_fragment",
  [sym_workdir_instruction] = "workdir_instruction",
  [sym_arg_instruction] = "arg_instruction",
  [sym_onbuild_instruction] = "onbuild_instruction",
  [sym_stopsignal_instruction] = "stopsignal_instruction",
  [sym__stopsignal_value] = "_stopsignal_value",
  [sym_healthcheck_instruction] = "healthcheck_instruction",
  [sym_shell_instruction] = "shell_instruction",
  [sym_maintainer_instruction] = "maintainer_instruction",
  [sym_cross_build_instruction] = "cross_build_instruction",
  [sym_heredoc_block] = "heredoc_block",
  [sym_path] = "path",
  [sym_path_with_heredoc] = "path",
  [sym_expansion] = "expansion",
  [sym__immediate_expansion] = "_immediate_expansion",
  [sym__imm_expansion] = "expansion",
  [sym__expansion_body] = "_expansion_body",
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
  [sym_mount_param] = "mount_param",
  [sym_mount_param_param] = "mount_param_param",
  [sym_image_alias] = "image_alias",
  [sym_shell_command] = "shell_command",
  [sym_shell_fragment] = "shell_fragment",
  [sym_json_string_array] = "json_string_array",
  [sym_json_string] = "json_string",
  [sym_double_quoted_string] = "double_quoted_string",
  [sym_single_quoted_string] = "single_quoted_string",
  [sym_unquoted_string] = "unquoted_string",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_run_instruction_repeat1] = "run_instruction_repeat1",
  [aux_sym_run_instruction_repeat2] = "run_instruction_repeat2",
  [aux_sym_label_instruction_repeat1] = "label_instruction_repeat1",
  [aux_sym_expose_instruction_repeat1] = "expose_instruction_repeat1",
  [aux_sym_env_instruction_repeat1] = "env_instruction_repeat1",
  [aux_sym_add_instruction_repeat1] = "add_instruction_repeat1",
  [aux_sym_add_instruction_repeat2] = "add_instruction_repeat2",
  [aux_sym_volume_instruction_repeat1] = "volume_instruction_repeat1",
  [aux_sym__user_name_or_group_repeat1] = "_user_name_or_group_repeat1",
  [aux_sym__stopsignal_value_repeat1] = "_stopsignal_value_repeat1",
  [aux_sym_heredoc_block_repeat1] = "heredoc_block_repeat1",
  [aux_sym_path_repeat1] = "path_repeat1",
  [aux_sym_image_name_repeat1] = "image_name_repeat1",
  [aux_sym_image_tag_repeat1] = "image_tag_repeat1",
  [aux_sym_image_digest_repeat1] = "image_digest_repeat1",
  [aux_sym_mount_param_repeat1] = "mount_param_repeat1",
  [aux_sym_image_alias_repeat1] = "image_alias_repeat1",
  [aux_sym_shell_command_repeat1] = "shell_command_repeat1",
  [aux_sym_shell_fragment_repeat1] = "shell_fragment_repeat1",
  [aux_sym_json_string_array_repeat1] = "json_string_array_repeat1",
  [aux_sym_json_string_repeat1] = "json_string_repeat1",
  [aux_sym_double_quoted_string_repeat1] = "double_quoted_string_repeat1",
  [aux_sym_single_quoted_string_repeat1] = "single_quoted_string_repeat1",
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
  [aux_sym__immediate_user_name_or_group_fragment_token1] = aux_sym__immediate_user_name_or_group_fragment_token1,
  [aux_sym_workdir_instruction_token1] = aux_sym_workdir_instruction_token1,
  [aux_sym_arg_instruction_token1] = aux_sym_arg_instruction_token1,
  [aux_sym_arg_instruction_token2] = sym_unquoted_string,
  [anon_sym_EQ] = anon_sym_EQ,
  [aux_sym_onbuild_instruction_token1] = aux_sym_onbuild_instruction_token1,
  [aux_sym_stopsignal_instruction_token1] = aux_sym_stopsignal_instruction_token1,
  [aux_sym__stopsignal_value_token1] = aux_sym__stopsignal_value_token1,
  [aux_sym__stopsignal_value_token2] = aux_sym__stopsignal_value_token2,
  [aux_sym_healthcheck_instruction_token1] = aux_sym_healthcheck_instruction_token1,
  [anon_sym_NONE] = anon_sym_NONE,
  [aux_sym_shell_instruction_token1] = aux_sym_shell_instruction_token1,
  [aux_sym_maintainer_instruction_token1] = aux_sym_maintainer_instruction_token1,
  [aux_sym_maintainer_instruction_token2] = aux_sym_maintainer_instruction_token2,
  [aux_sym_cross_build_instruction_token1] = aux_sym_cross_build_instruction_token1,
  [aux_sym_path_token1] = aux_sym_path_token1,
  [aux_sym_path_token2] = aux_sym_path_token2,
  [aux_sym_path_token3] = aux_sym_path_token3,
  [aux_sym_path_with_heredoc_token1] = aux_sym_path_with_heredoc_token1,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_DOLLAR2] = anon_sym_DOLLAR,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [aux_sym__expansion_body_token1] = sym_variable,
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
  [anon_sym_mount] = anon_sym_mount,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [aux_sym_mount_param_param_token1] = aux_sym_mount_param_param_token1,
  [aux_sym_image_alias_token1] = aux_sym_image_alias_token1,
  [aux_sym_image_alias_token2] = aux_sym_image_alias_token2,
  [aux_sym_shell_fragment_token1] = aux_sym_shell_fragment_token1,
  [aux_sym_shell_fragment_token2] = aux_sym_shell_fragment_token2,
  [aux_sym_shell_fragment_token3] = aux_sym_shell_fragment_token3,
  [aux_sym_shell_fragment_token4] = aux_sym_shell_fragment_token4,
  [sym_line_continuation] = sym_line_continuation,
  [sym_required_line_continuation] = sym_line_continuation,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA2] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_json_string_token1] = aux_sym_json_string_token1,
  [sym_json_escape_sequence] = sym_json_escape_sequence,
  [aux_sym_double_quoted_string_token1] = aux_sym_double_quoted_string_token1,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_single_quoted_string_token1] = aux_sym_single_quoted_string_token1,
  [aux_sym_unquoted_string_token1] = aux_sym_unquoted_string_token1,
  [anon_sym_BSLASH2] = anon_sym_BSLASH2,
  [sym_double_quoted_escape_sequence] = sym_json_escape_sequence,
  [sym_single_quoted_escape_sequence] = sym_json_escape_sequence,
  [sym__non_newline_whitespace] = sym__non_newline_whitespace,
  [sym_comment] = sym_comment,
  [sym_heredoc_marker] = sym_heredoc_marker,
  [sym_heredoc_line] = sym_heredoc_line,
  [sym_heredoc_end] = sym_heredoc_end,
  [sym_heredoc_nl] = sym_heredoc_nl,
  [sym_error_sentinel] = sym_error_sentinel,
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
  [sym__user_name_or_group] = sym_unquoted_string,
  [aux_sym__immediate_user_name_or_group] = aux_sym__immediate_user_name_or_group,
  [sym__immediate_user_name_or_group_fragment] = sym__immediate_user_name_or_group_fragment,
  [sym_workdir_instruction] = sym_workdir_instruction,
  [sym_arg_instruction] = sym_arg_instruction,
  [sym_onbuild_instruction] = sym_onbuild_instruction,
  [sym_stopsignal_instruction] = sym_stopsignal_instruction,
  [sym__stopsignal_value] = sym__stopsignal_value,
  [sym_healthcheck_instruction] = sym_healthcheck_instruction,
  [sym_shell_instruction] = sym_shell_instruction,
  [sym_maintainer_instruction] = sym_maintainer_instruction,
  [sym_cross_build_instruction] = sym_cross_build_instruction,
  [sym_heredoc_block] = sym_heredoc_block,
  [sym_path] = sym_path,
  [sym_path_with_heredoc] = sym_path,
  [sym_expansion] = sym_expansion,
  [sym__immediate_expansion] = sym__immediate_expansion,
  [sym__imm_expansion] = sym_expansion,
  [sym__expansion_body] = sym__expansion_body,
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
  [sym_mount_param] = sym_mount_param,
  [sym_mount_param_param] = sym_mount_param_param,
  [sym_image_alias] = sym_image_alias,
  [sym_shell_command] = sym_shell_command,
  [sym_shell_fragment] = sym_shell_fragment,
  [sym_json_string_array] = sym_json_string_array,
  [sym_json_string] = sym_json_string,
  [sym_double_quoted_string] = sym_double_quoted_string,
  [sym_single_quoted_string] = sym_single_quoted_string,
  [sym_unquoted_string] = sym_unquoted_string,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_run_instruction_repeat1] = aux_sym_run_instruction_repeat1,
  [aux_sym_run_instruction_repeat2] = aux_sym_run_instruction_repeat2,
  [aux_sym_label_instruction_repeat1] = aux_sym_label_instruction_repeat1,
  [aux_sym_expose_instruction_repeat1] = aux_sym_expose_instruction_repeat1,
  [aux_sym_env_instruction_repeat1] = aux_sym_env_instruction_repeat1,
  [aux_sym_add_instruction_repeat1] = aux_sym_add_instruction_repeat1,
  [aux_sym_add_instruction_repeat2] = aux_sym_add_instruction_repeat2,
  [aux_sym_volume_instruction_repeat1] = aux_sym_volume_instruction_repeat1,
  [aux_sym__user_name_or_group_repeat1] = aux_sym__user_name_or_group_repeat1,
  [aux_sym__stopsignal_value_repeat1] = aux_sym__stopsignal_value_repeat1,
  [aux_sym_heredoc_block_repeat1] = aux_sym_heredoc_block_repeat1,
  [aux_sym_path_repeat1] = aux_sym_path_repeat1,
  [aux_sym_image_name_repeat1] = aux_sym_image_name_repeat1,
  [aux_sym_image_tag_repeat1] = aux_sym_image_tag_repeat1,
  [aux_sym_image_digest_repeat1] = aux_sym_image_digest_repeat1,
  [aux_sym_mount_param_repeat1] = aux_sym_mount_param_repeat1,
  [aux_sym_image_alias_repeat1] = aux_sym_image_alias_repeat1,
  [aux_sym_shell_command_repeat1] = aux_sym_shell_command_repeat1,
  [aux_sym_shell_fragment_repeat1] = aux_sym_shell_fragment_repeat1,
  [aux_sym_json_string_array_repeat1] = aux_sym_json_string_array_repeat1,
  [aux_sym_json_string_repeat1] = aux_sym_json_string_repeat1,
  [aux_sym_double_quoted_string_repeat1] = aux_sym_double_quoted_string_repeat1,
  [aux_sym_single_quoted_string_repeat1] = aux_sym_single_quoted_string_repeat1,
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
  [aux_sym__immediate_user_name_or_group_fragment_token1] = {
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
  [aux_sym__stopsignal_value_token2] = {
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
  [aux_sym_path_token3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_path_with_heredoc_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__expansion_body_token1] = {
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
  [anon_sym_mount] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_mount_param_param_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_image_alias_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_image_alias_token2] = {
    .visible = false,
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
  [aux_sym_shell_fragment_token3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_shell_fragment_token4] = {
    .visible = false,
    .named = false,
  },
  [sym_line_continuation] = {
    .visible = true,
    .named = true,
  },
  [sym_required_line_continuation] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_json_string_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_json_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_double_quoted_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_single_quoted_string_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_unquoted_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BSLASH2] = {
    .visible = true,
    .named = false,
  },
  [sym_double_quoted_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_single_quoted_escape_sequence] = {
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
  [sym_heredoc_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_heredoc_line] = {
    .visible = true,
    .named = true,
  },
  [sym_heredoc_end] = {
    .visible = true,
    .named = true,
  },
  [sym_heredoc_nl] = {
    .visible = true,
    .named = false,
  },
  [sym_error_sentinel] = {
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
  [sym__user_name_or_group] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__immediate_user_name_or_group] = {
    .visible = false,
    .named = false,
  },
  [sym__immediate_user_name_or_group_fragment] = {
    .visible = false,
    .named = true,
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
  [sym__stopsignal_value] = {
    .visible = false,
    .named = true,
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
  [sym_heredoc_block] = {
    .visible = true,
    .named = true,
  },
  [sym_path] = {
    .visible = true,
    .named = true,
  },
  [sym_path_with_heredoc] = {
    .visible = true,
    .named = true,
  },
  [sym_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym__immediate_expansion] = {
    .visible = false,
    .named = true,
  },
  [sym__imm_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym__expansion_body] = {
    .visible = false,
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
  [sym_mount_param] = {
    .visible = true,
    .named = true,
  },
  [sym_mount_param_param] = {
    .visible = true,
    .named = true,
  },
  [sym_image_alias] = {
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
  [sym_json_string_array] = {
    .visible = true,
    .named = true,
  },
  [sym_json_string] = {
    .visible = true,
    .named = true,
  },
  [sym_double_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_single_quoted_string] = {
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
  [aux_sym_run_instruction_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_run_instruction_repeat2] = {
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
  [aux_sym_add_instruction_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_volume_instruction_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__user_name_or_group_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__stopsignal_value_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_heredoc_block_repeat1] = {
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
  [aux_sym_mount_param_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_image_alias_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_shell_command_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_shell_fragment_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_json_string_array_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_json_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_double_quoted_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_single_quoted_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_unquoted_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
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
  [15] = {.index = 24, .length = 3},
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
  [24] =
    {field_name, 1},
    {field_value, 3},
    {field_value, 4},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [11] = {
    [3] = sym_unquoted_string,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  aux_sym__immediate_user_name_or_group, 2,
    aux_sym__immediate_user_name_or_group,
    sym_unquoted_string,
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
  [29] = 29,
  [30] = 29,
  [31] = 31,
  [32] = 32,
  [33] = 18,
  [34] = 34,
  [35] = 26,
  [36] = 36,
  [37] = 37,
  [38] = 17,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 29,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 39,
  [50] = 50,
  [51] = 24,
  [52] = 39,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
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
  [67] = 53,
  [68] = 68,
  [69] = 40,
  [70] = 32,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 65,
  [80] = 55,
  [81] = 81,
  [82] = 72,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 36,
  [87] = 61,
  [88] = 88,
  [89] = 44,
  [90] = 90,
  [91] = 40,
  [92] = 92,
  [93] = 40,
  [94] = 94,
  [95] = 95,
  [96] = 72,
  [97] = 95,
  [98] = 98,
  [99] = 99,
  [100] = 65,
  [101] = 95,
  [102] = 102,
  [103] = 99,
  [104] = 72,
  [105] = 77,
  [106] = 106,
  [107] = 74,
  [108] = 108,
  [109] = 65,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 72,
  [118] = 118,
  [119] = 119,
  [120] = 99,
  [121] = 65,
  [122] = 65,
  [123] = 123,
  [124] = 124,
  [125] = 72,
  [126] = 126,
  [127] = 72,
  [128] = 128,
  [129] = 129,
  [130] = 72,
  [131] = 131,
  [132] = 132,
  [133] = 65,
  [134] = 134,
  [135] = 135,
  [136] = 72,
  [137] = 65,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 77,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 65,
  [150] = 77,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 56,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 65,
  [163] = 72,
  [164] = 164,
  [165] = 164,
  [166] = 164,
  [167] = 164,
  [168] = 168,
  [169] = 169,
  [170] = 164,
  [171] = 169,
  [172] = 164,
  [173] = 173,
  [174] = 169,
  [175] = 164,
  [176] = 169,
  [177] = 164,
  [178] = 178,
  [179] = 169,
  [180] = 164,
  [181] = 181,
  [182] = 169,
  [183] = 183,
  [184] = 164,
  [185] = 169,
  [186] = 186,
  [187] = 164,
  [188] = 186,
  [189] = 169,
  [190] = 190,
  [191] = 191,
  [192] = 169,
  [193] = 129,
  [194] = 65,
  [195] = 195,
  [196] = 191,
  [197] = 72,
  [198] = 77,
  [199] = 164,
  [200] = 77,
  [201] = 201,
  [202] = 202,
  [203] = 152,
  [204] = 204,
  [205] = 77,
  [206] = 206,
  [207] = 72,
  [208] = 65,
  [209] = 209,
  [210] = 190,
  [211] = 77,
  [212] = 72,
  [213] = 144,
  [214] = 65,
  [215] = 77,
  [216] = 164,
  [217] = 72,
  [218] = 218,
  [219] = 219,
  [220] = 220,
  [221] = 221,
  [222] = 74,
  [223] = 138,
  [224] = 147,
  [225] = 225,
  [226] = 159,
  [227] = 160,
  [228] = 228,
  [229] = 173,
  [230] = 230,
  [231] = 231,
  [232] = 232,
  [233] = 233,
  [234] = 234,
  [235] = 74,
  [236] = 236,
  [237] = 237,
  [238] = 238,
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 243,
  [244] = 244,
  [245] = 245,
  [246] = 246,
  [247] = 247,
  [248] = 248,
  [249] = 249,
  [250] = 225,
  [251] = 251,
  [252] = 252,
  [253] = 253,
  [254] = 195,
  [255] = 248,
  [256] = 256,
  [257] = 257,
  [258] = 258,
  [259] = 259,
  [260] = 260,
  [261] = 260,
  [262] = 262,
  [263] = 263,
  [264] = 264,
  [265] = 265,
  [266] = 147,
  [267] = 267,
  [268] = 252,
  [269] = 138,
  [270] = 240,
  [271] = 271,
  [272] = 272,
  [273] = 273,
  [274] = 274,
  [275] = 275,
  [276] = 276,
  [277] = 252,
  [278] = 248,
  [279] = 279,
  [280] = 280,
  [281] = 252,
  [282] = 248,
  [283] = 283,
  [284] = 284,
  [285] = 252,
  [286] = 286,
  [287] = 287,
  [288] = 252,
  [289] = 159,
  [290] = 290,
  [291] = 252,
  [292] = 292,
  [293] = 293,
  [294] = 252,
  [295] = 160,
  [296] = 296,
  [297] = 252,
  [298] = 298,
  [299] = 252,
  [300] = 300,
  [301] = 252,
  [302] = 231,
  [303] = 252,
  [304] = 304,
  [305] = 252,
  [306] = 252,
  [307] = 298,
  [308] = 262,
  [309] = 298,
  [310] = 262,
  [311] = 298,
  [312] = 262,
  [313] = 298,
  [314] = 298,
  [315] = 298,
  [316] = 298,
  [317] = 298,
  [318] = 298,
  [319] = 298,
  [320] = 298,
  [321] = 298,
  [322] = 298,
  [323] = 264,
  [324] = 264,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(168);
      ADVANCE_MAP(
        '"', 271,
        '#', 206,
        '$', 214,
        '\'', 282,
        ',', 253,
        '-', 261,
        ':', 182,
        '<', 229,
        '=', 191,
        '@', 240,
        '[', 268,
        '\\', 279,
        ']', 270,
        '_', 221,
        '{', 215,
        '}', 220,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(165);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(185);
      if (lookahead != 0) ADVANCE(204);
      END_STATE();
    case 1:
      if (lookahead == '\t') ADVANCE(3);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == ' ') ADVANCE(290);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '\n', 266,
        'u', 162,
        '\t', 3,
        ' ', 3,
        '"', 275,
        '/', 275,
        '\\', 275,
        'b', 275,
        'f', 275,
        'n', 275,
        'r', 275,
        't', 275,
      );
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(265);
      if (lookahead != 0 &&
          lookahead != ',' &&
          lookahead != '-' &&
          lookahead != '=') ADVANCE(264);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '"') ADVANCE(271);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\'') ADVANCE(282);
      if (lookahead == ':') ADVANCE(182);
      if (lookahead == '=') ADVANCE(191);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '"') ADVANCE(271);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\'') ADVANCE(282);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(223);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '"') ADVANCE(271);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\'') ADVANCE(282);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '"') ADVANCE(271);
      if (lookahead == '#') ADVANCE(286);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\'') ADVANCE(282);
      if (lookahead == '\\') ADVANCE(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(287);
      if (lookahead != 0) ADVANCE(289);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '"') ADVANCE(271);
      if (lookahead == '#') ADVANCE(286);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\'') ADVANCE(282);
      if (lookahead == '\\') ADVANCE(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(288);
      if (lookahead != 0) ADVANCE(289);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == ':') ADVANCE(182);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(241);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (('0' <= lookahead && lookahead <= ':') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(242);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(195);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(258);
      END_STATE();
    case 14:
      ADVANCE_MAP(
        '\n', 169,
        '#', 294,
        '$', 213,
        '/', 68,
        ':', 182,
        '@', 240,
        '\\', 3,
        'A', 143,
        'a', 143,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(15);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(224);
      END_STATE();
    case 15:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '$') ADVANCE(213);
      if (lookahead == '/') ADVANCE(68);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(143);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(15);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(224);
      END_STATE();
    case 16:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '<') ADVANCE(262);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == ',' ||
          lookahead == '-' ||
          lookahead == '=') ADVANCE(260);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(16);
      if (lookahead != 0 &&
          lookahead != '[' &&
          lookahead != '\\') ADVANCE(263);
      END_STATE();
    case 17:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(293);
      if ((0x0b <= lookahead && lookahead <= '\r')) SKIP(19);
      END_STATE();
    case 18:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(143);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      END_STATE();
    case 19:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      END_STATE();
    case 20:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(223);
      END_STATE();
    case 21:
      ADVANCE_MAP(
        '\n', 169,
        '#', 234,
        '$', 214,
        ':', 182,
        '@', 240,
        '\\', 232,
        'A', 233,
        'a', 233,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (lookahead != 0) ADVANCE(235);
      END_STATE();
    case 22:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(238);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '@') ADVANCE(240);
      if (lookahead == '\\') ADVANCE(236);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(237);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (lookahead != 0) ADVANCE(239);
      END_STATE();
    case 23:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(210);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\\') ADVANCE(209);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(293);
      if ((0x0b <= lookahead && lookahead <= '\r')) SKIP(19);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 24:
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == '#') ADVANCE(210);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\\') ADVANCE(209);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 25:
      if (lookahead == '\n') ADVANCE(267);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(265);
      if (lookahead != 0 &&
          lookahead != ',' &&
          lookahead != '-' &&
          lookahead != '=') ADVANCE(264);
      END_STATE();
    case 26:
      if (lookahead == '\n') SKIP(30);
      if (lookahead == '"') ADVANCE(271);
      if (lookahead == '#') ADVANCE(277);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\\') ADVANCE(280);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(276);
      if (lookahead != 0) ADVANCE(278);
      END_STATE();
    case 27:
      if (lookahead == '\n') SKIP(42);
      if (lookahead == '#') ADVANCE(284);
      if (lookahead == '\'') ADVANCE(282);
      if (lookahead == '\\') ADVANCE(281);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(283);
      if (lookahead != 0) ADVANCE(285);
      END_STATE();
    case 28:
      if (lookahead == '"') ADVANCE(271);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\'') ADVANCE(282);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(28);
      END_STATE();
    case 29:
      if (lookahead == '"') ADVANCE(271);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\'') ADVANCE(282);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(29);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 30:
      if (lookahead == '"') ADVANCE(271);
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\\') ADVANCE(279);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(30);
      END_STATE();
    case 31:
      if (lookahead == '"') ADVANCE(271);
      if (lookahead == '#') ADVANCE(286);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\'') ADVANCE(282);
      if (lookahead == '\\') ADVANCE(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(28);
      if (lookahead != 0) ADVANCE(289);
      END_STATE();
    case 32:
      if (lookahead == '"') ADVANCE(271);
      if (lookahead == '#') ADVANCE(272);
      if (lookahead == '\\') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(273);
      if (lookahead != 0) ADVANCE(274);
      END_STATE();
    case 33:
      if (lookahead == '#') ADVANCE(206);
      if (lookahead == '$') ADVANCE(213);
      if (lookahead == '-') ADVANCE(59);
      if (lookahead == '<') ADVANCE(163);
      if (lookahead == '\\') ADVANCE(205);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(33);
      if (lookahead != 0) ADVANCE(204);
      END_STATE();
    case 34:
      if (lookahead == '#') ADVANCE(206);
      if (lookahead == '$') ADVANCE(213);
      if (lookahead == '<') ADVANCE(164);
      if (lookahead == '[') ADVANCE(268);
      if (lookahead == '\\') ADVANCE(205);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(34);
      if (lookahead != 0 &&
          lookahead != '-') ADVANCE(204);
      END_STATE();
    case 35:
      if (lookahead == '#') ADVANCE(206);
      if (lookahead == '$') ADVANCE(213);
      if (lookahead == '<') ADVANCE(164);
      if (lookahead == '\\') ADVANCE(205);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(35);
      if (lookahead != 0 &&
          lookahead != '-') ADVANCE(204);
      END_STATE();
    case 36:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(49);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 37:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(49);
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(242);
      END_STATE();
    case 38:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '$') ADVANCE(213);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == 'm') ADVANCE(245);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(40);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(194);
      END_STATE();
    case 39:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '$') ADVANCE(213);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(39);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(257);
      END_STATE();
    case 40:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '$') ADVANCE(213);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(194);
      END_STATE();
    case 41:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '$') ADVANCE(213);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(41);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(183);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(184);
      END_STATE();
    case 42:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\'') ADVANCE(282);
      if (lookahead == '\\') ADVANCE(279);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(42);
      END_STATE();
    case 43:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == ',') ADVANCE(253);
      if (lookahead == '-') ADVANCE(261);
      if (lookahead == '<') ADVANCE(262);
      if (lookahead == '=') ADVANCE(260);
      if (lookahead == '[') ADVANCE(268);
      if (lookahead == '\\') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(44);
      if (lookahead != 0) ADVANCE(263);
      END_STATE();
    case 44:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '-') ADVANCE(261);
      if (lookahead == '<') ADVANCE(262);
      if (lookahead == '[') ADVANCE(268);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == ',' ||
          lookahead == '=') ADVANCE(260);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(44);
      if (lookahead != 0) ADVANCE(263);
      END_STATE();
    case 45:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '<') ADVANCE(262);
      if (lookahead == '[') ADVANCE(268);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == ',' ||
          lookahead == '-' ||
          lookahead == '=') ADVANCE(260);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(45);
      if (lookahead != 0) ADVANCE(263);
      END_STATE();
    case 46:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '=') ADVANCE(191);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(222);
      END_STATE();
    case 47:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == '{') ADVANCE(215);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(49);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      END_STATE();
    case 48:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(293);
      if (('\n' <= lookahead && lookahead <= '\r')) SKIP(49);
      END_STATE();
    case 49:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(49);
      END_STATE();
    case 50:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(49);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 51:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(51);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(223);
      END_STATE();
    case 52:
      if (lookahead == '#') ADVANCE(294);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(190);
      END_STATE();
    case 53:
      if (lookahead == '#') ADVANCE(238);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\\') ADVANCE(236);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(49);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(239);
      END_STATE();
    case 54:
      if (lookahead == '#') ADVANCE(210);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '\\') ADVANCE(209);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(293);
      if (('\n' <= lookahead && lookahead <= '\r')) SKIP(49);
      if (lookahead != 0) ADVANCE(211);
      END_STATE();
    case 55:
      if (lookahead == '#') ADVANCE(231);
      if (lookahead == '$') ADVANCE(213);
      if (lookahead == '-') ADVANCE(59);
      if (lookahead == '\\') ADVANCE(230);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(55);
      if (lookahead != 0 &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(229);
      END_STATE();
    case 56:
      if (lookahead == '#') ADVANCE(255);
      if (lookahead == '\\') ADVANCE(254);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(49);
      if (lookahead != 0 &&
          lookahead != ',' &&
          lookahead != '=') ADVANCE(256);
      END_STATE();
    case 57:
      if (lookahead == '#') ADVANCE(250);
      if (lookahead == '\\') ADVANCE(249);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(49);
      if (lookahead != 0) ADVANCE(251);
      END_STATE();
    case 58:
      if (lookahead == '#') ADVANCE(216);
      if (lookahead == '\\') ADVANCE(217);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(219);
      END_STATE();
    case 59:
      if (lookahead == '-') ADVANCE(243);
      END_STATE();
    case 60:
      if (lookahead == 'E') ADVANCE(197);
      END_STATE();
    case 61:
      if (lookahead == 'N') ADVANCE(60);
      END_STATE();
    case 62:
      if (lookahead == 'O') ADVANCE(61);
      END_STATE();
    case 63:
      if (lookahead == '_') ADVANCE(76);
      END_STATE();
    case 64:
      if (lookahead == 'c') ADVANCE(66);
      END_STATE();
    case 65:
      if (lookahead == 'd') ADVANCE(67);
      END_STATE();
    case 66:
      if (lookahead == 'p') ADVANCE(226);
      END_STATE();
    case 67:
      if (lookahead == 'p') ADVANCE(227);
      END_STATE();
    case 68:
      if (lookahead == 't') ADVANCE(64);
      if (lookahead == 'u') ADVANCE(65);
      END_STATE();
    case 69:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(75);
      END_STATE();
    case 70:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(99);
      END_STATE();
    case 71:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(107);
      END_STATE();
    case 72:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(110);
      END_STATE();
    case 73:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(100);
      END_STATE();
    case 74:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(153);
      END_STATE();
    case 75:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(91);
      END_STATE();
    case 76:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(155);
      END_STATE();
    case 77:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(105);
      END_STATE();
    case 78:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(97);
      END_STATE();
    case 79:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(80);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(93);
      END_STATE();
    case 80:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(177);
      END_STATE();
    case 81:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(173);
      END_STATE();
    case 82:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(192);
      END_STATE();
    case 83:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(203);
      END_STATE();
    case 84:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(101);
      END_STATE();
    case 85:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(175);
      END_STATE();
    case 86:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(180);
      END_STATE();
    case 87:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(77);
      END_STATE();
    case 88:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(71);
      END_STATE();
    case 89:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(114);
      END_STATE();
    case 90:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(137);
      END_STATE();
    case 91:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(108);
      END_STATE();
    case 92:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(139);
      END_STATE();
    case 93:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(189);
      END_STATE();
    case 94:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(123);
      END_STATE();
    case 95:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(78);
      END_STATE();
    case 96:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(89);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(129);
      END_STATE();
    case 97:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(87);
      END_STATE();
    case 98:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(94);
      END_STATE();
    case 99:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(121);
      END_STATE();
    case 100:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(124);
      END_STATE();
    case 101:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(138);
      END_STATE();
    case 102:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(122);
      END_STATE();
    case 103:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(112);
      END_STATE();
    case 104:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(113);
      END_STATE();
    case 105:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(196);
      END_STATE();
    case 106:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(84);
      END_STATE();
    case 107:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(148);
      END_STATE();
    case 108:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(174);
      END_STATE();
    case 109:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(198);
      END_STATE();
    case 110:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(193);
      END_STATE();
    case 111:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(154);
      END_STATE();
    case 112:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(82);
      END_STATE();
    case 113:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(83);
      END_STATE();
    case 114:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(109);
      END_STATE();
    case 115:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(170);
      END_STATE();
    case 116:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(81);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(132);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(128);
      END_STATE();
    case 117:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(86);
      END_STATE();
    case 118:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(150);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(134);
      END_STATE();
    case 119:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(172);
      END_STATE();
    case 120:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(74);
      END_STATE();
    case 121:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(151);
      END_STATE();
    case 122:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(149);
      END_STATE();
    case 123:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(72);
      END_STATE();
    case 124:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(92);
      END_STATE();
    case 125:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(111);
      END_STATE();
    case 126:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(115);
      END_STATE();
    case 127:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(136);
      END_STATE();
    case 128:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(145);
      END_STATE();
    case 129:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(133);
      END_STATE();
    case 130:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(147);
      END_STATE();
    case 131:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(102);
      END_STATE();
    case 132:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(156);
      END_STATE();
    case 133:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(146);
      END_STATE();
    case 134:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(130);
      END_STATE();
    case 135:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(131);
      END_STATE();
    case 136:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(106);
      END_STATE();
    case 137:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(181);
      END_STATE();
    case 138:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(188);
      END_STATE();
    case 139:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(199);
      END_STATE();
    case 140:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(157);
      END_STATE();
    case 141:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(126);
      END_STATE();
    case 142:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(63);
      END_STATE();
    case 143:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(171);
      END_STATE();
    case 144:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(90);
      END_STATE();
    case 145:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(142);
      END_STATE();
    case 146:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(98);
      END_STATE();
    case 147:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(85);
      END_STATE();
    case 148:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(95);
      END_STATE();
    case 149:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(179);
      END_STATE();
    case 150:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(140);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(176);
      END_STATE();
    case 151:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(73);
      END_STATE();
    case 152:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(119);
      END_STATE();
    case 153:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(103);
      END_STATE();
    case 154:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(117);
      END_STATE();
    case 155:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(104);
      END_STATE();
    case 156:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(178);
      END_STATE();
    case 157:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(135);
      END_STATE();
    case 158:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(225);
      END_STATE();
    case 159:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(275);
      END_STATE();
    case 160:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(159);
      END_STATE();
    case 161:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(160);
      END_STATE();
    case 162:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      END_STATE();
    case 163:
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != '-' &&
          lookahead != '<') ADVANCE(212);
      END_STATE();
    case 164:
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(207);
      END_STATE();
    case 165:
      if (eof) ADVANCE(168);
      ADVANCE_MAP(
        '"', 271,
        '#', 206,
        '$', 213,
        '\'', 282,
        ',', 269,
        '-', 261,
        '<', 229,
        '=', 204,
        '[', 268,
        '\\', 279,
        ']', 270,
        ':', 204,
        '@', 204,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(165);
      if (lookahead != 0) ADVANCE(204);
      END_STATE();
    case 166:
      if (eof) ADVANCE(168);
      ADVANCE_MAP(
        '"', 271,
        '#', 294,
        '$', 213,
        ',', 269,
        '-', 59,
        '=', 191,
        'N', 62,
        '[', 268,
        '\\', 3,
        ']', 270,
        '}', 220,
        'A', 79,
        'a', 79,
        'C', 116,
        'c', 116,
        'E', 118,
        'e', 118,
        'F', 141,
        'f', 141,
        'H', 88,
        'h', 88,
        'L', 69,
        'l', 69,
        'M', 70,
        'm', 70,
        'O', 120,
        'o', 120,
        'R', 152,
        'r', 152,
        'S', 96,
        's', 96,
        'U', 144,
        'u', 144,
        'V', 125,
        'v', 125,
        'W', 127,
        'w', 127,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(167);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(224);
      END_STATE();
    case 167:
      if (eof) ADVANCE(168);
      ADVANCE_MAP(
        '"', 271,
        '#', 294,
        '$', 213,
        ',', 269,
        '-', 59,
        'N', 62,
        '[', 268,
        '\\', 3,
        ']', 270,
        'A', 79,
        'a', 79,
        'C', 116,
        'c', 116,
        'E', 118,
        'e', 118,
        'F', 141,
        'f', 141,
        'H', 88,
        'h', 88,
        'L', 69,
        'l', 69,
        'M', 70,
        'm', 70,
        'O', 120,
        'o', 120,
        'R', 152,
        'r', 152,
        'S', 96,
        's', 96,
        'U', 144,
        'u', 144,
        'V', 125,
        'v', 125,
        'W', 127,
        'w', 127,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(167);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(224);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(169);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_from_instruction_token1);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_from_instruction_token2);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_run_instruction_token1);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_cmd_instruction_token1);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_label_instruction_token1);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_expose_instruction_token1);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_env_instruction_token1);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_add_instruction_token1);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_copy_instruction_token1);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_entrypoint_instruction_token1);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_volume_instruction_token1);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_user_instruction_token1);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym__user_name_or_group_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(183);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym__user_name_or_group_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(184);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym__immediate_user_name_or_group_fragment_token1);
      if (lookahead == '-') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(185);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym__immediate_user_name_or_group_fragment_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(186);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym__immediate_user_name_or_group_fragment_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_workdir_instruction_token1);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_arg_instruction_token1);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_arg_instruction_token2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(190);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_onbuild_instruction_token1);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_stopsignal_instruction_token1);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym__stopsignal_value_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(194);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym__stopsignal_value_token2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(195);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_healthcheck_instruction_token1);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_NONE);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_shell_instruction_token1);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token1);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token2);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(200);
      if (lookahead != 0) ADVANCE(202);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token2);
      if (lookahead == '#') ADVANCE(202);
      if (lookahead == '\\') ADVANCE(200);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(201);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(202);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_maintainer_instruction_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_cross_build_instruction_token1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(203);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_path_token1);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_path_token1);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_path_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(294);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_path_token2);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_path_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '<' &&
          lookahead != '\\') ADVANCE(263);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_path_token3);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '$') ADVANCE(211);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_path_token3);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ' ||
          lookahead == '$') ADVANCE(294);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(210);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_path_token3);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '$') ADVANCE(211);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_path_with_heredoc_token1);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_DOLLAR2);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym__expansion_body_token1);
      if (lookahead == '\n') ADVANCE(219);
      if (lookahead == '}') ADVANCE(294);
      if (lookahead != 0) ADVANCE(216);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym__expansion_body_token1);
      if (lookahead == '\n') ADVANCE(219);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(217);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(219);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym__expansion_body_token1);
      if (lookahead == '#') ADVANCE(216);
      if (lookahead == '\\') ADVANCE(217);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(219);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym__expansion_body_token1);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(219);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_variable);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym__spaced_env_pair_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(222);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym__env_key_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(223);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(aux_sym_expose_port_token1);
      if (lookahead == '-') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(224);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(aux_sym_expose_port_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(225);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_SLASHtcp);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_SLASHudp);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_label_pair_token1);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(228);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_image_name_token1);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(aux_sym_image_name_token1);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_image_name_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(294);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(aux_sym_image_name_token2);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(235);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(aux_sym_image_name_token2);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(235);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(235);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(aux_sym_image_name_token2);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ' ||
          lookahead == '$' ||
          lookahead == ':' ||
          lookahead == '@') ADVANCE(294);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(234);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(aux_sym_image_name_token2);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != ':' &&
          lookahead != '@') ADVANCE(235);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(aux_sym_image_tag_token1);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '$' &&
          lookahead != '@') ADVANCE(239);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(aux_sym_image_tag_token1);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(239);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != '@') ADVANCE(239);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(aux_sym_image_tag_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ' ||
          lookahead == '$' ||
          lookahead == '@') ADVANCE(294);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(238);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(aux_sym_image_tag_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '$' &&
          lookahead != '@') ADVANCE(239);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(aux_sym_image_digest_token1);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(242);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(aux_sym_image_digest_token1);
      if (('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(242);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(aux_sym_param_token1);
      if (lookahead == 'n') ADVANCE(246);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(aux_sym_param_token1);
      if (lookahead == 'o') ADVANCE(247);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(aux_sym_param_token1);
      if (lookahead == 't') ADVANCE(252);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(aux_sym_param_token1);
      if (lookahead == 'u') ADVANCE(244);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_param_token1);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(aux_sym_param_token2);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(251);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(aux_sym_param_token2);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(294);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(250);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(aux_sym_param_token2);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(251);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(anon_sym_mount);
      if (lookahead == '-' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(248);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(aux_sym_mount_param_param_token1);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ',' &&
          lookahead != '=') ADVANCE(256);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(aux_sym_mount_param_param_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ' ||
          lookahead == ',' ||
          lookahead == '=') ADVANCE(294);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(255);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(aux_sym_mount_param_param_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != ',' &&
          lookahead != '=') ADVANCE(256);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(aux_sym_image_alias_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(257);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(aux_sym_image_alias_token2);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(258);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(aux_sym_shell_fragment_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(259);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(aux_sym_shell_fragment_token2);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(aux_sym_shell_fragment_token2);
      if (lookahead == '-') ADVANCE(243);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(aux_sym_shell_fragment_token3);
      if (lookahead == '\n' ||
          lookahead == '\\') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(208);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(aux_sym_shell_fragment_token3);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '<' &&
          lookahead != '\\') ADVANCE(263);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(aux_sym_shell_fragment_token4);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(aux_sym_shell_fragment_token4);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_line_continuation);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_required_line_continuation);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(anon_sym_COMMA2);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(aux_sym_json_string_token1);
      if (lookahead == '\n') ADVANCE(274);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(294);
      if (lookahead != 0) ADVANCE(272);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(aux_sym_json_string_token1);
      if (lookahead == '#') ADVANCE(272);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(273);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '#' &&
          lookahead != '\\') ADVANCE(274);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(aux_sym_json_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(274);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_json_escape_sequence);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '#') ADVANCE(277);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(276);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < '"' || '$' < lookahead) &&
          lookahead != '\\') ADVANCE(278);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '"' ||
          lookahead == '$' ||
          lookahead == '\\') ADVANCE(294);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(277);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(278);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(291);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead == '\'' ||
          lookahead == '\\') ADVANCE(292);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '#') ADVANCE(284);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(283);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(285);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '\'' ||
          lookahead == '\\') ADVANCE(294);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(284);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(285);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(aux_sym_unquoted_string_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ' ||
          lookahead == '"' ||
          lookahead == '$' ||
          lookahead == '\'' ||
          lookahead == '\\') ADVANCE(294);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(286);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(aux_sym_unquoted_string_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(287);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(289);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(aux_sym_unquoted_string_token1);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(288);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(289);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(aux_sym_unquoted_string_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(289);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(anon_sym_BSLASH2);
      if (lookahead == '\n') ADVANCE(266);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_double_quoted_escape_sequence);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_single_quoted_escape_sequence);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym__non_newline_whitespace);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(293);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(294);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 166},
  [2] = {.lex_state = 166},
  [3] = {.lex_state = 166},
  [4] = {.lex_state = 166},
  [5] = {.lex_state = 166},
  [6] = {.lex_state = 44, .external_lex_state = 2},
  [7] = {.lex_state = 44, .external_lex_state = 2},
  [8] = {.lex_state = 8},
  [9] = {.lex_state = 31},
  [10] = {.lex_state = 31},
  [11] = {.lex_state = 31},
  [12] = {.lex_state = 44, .external_lex_state = 2},
  [13] = {.lex_state = 33, .external_lex_state = 2},
  [14] = {.lex_state = 33, .external_lex_state = 2},
  [15] = {.lex_state = 45, .external_lex_state = 2},
  [16] = {.lex_state = 45, .external_lex_state = 2},
  [17] = {.lex_state = 9},
  [18] = {.lex_state = 9},
  [19] = {.lex_state = 33, .external_lex_state = 2},
  [20] = {.lex_state = 33, .external_lex_state = 2},
  [21] = {.lex_state = 43, .external_lex_state = 2},
  [22] = {.lex_state = 21},
  [23] = {.lex_state = 43, .external_lex_state = 2},
  [24] = {.lex_state = 16, .external_lex_state = 3},
  [25] = {.lex_state = 21},
  [26] = {.lex_state = 16, .external_lex_state = 3},
  [27] = {.lex_state = 21},
  [28] = {.lex_state = 43, .external_lex_state = 2},
  [29] = {.lex_state = 26},
  [30] = {.lex_state = 26},
  [31] = {.lex_state = 43, .external_lex_state = 2},
  [32] = {.lex_state = 16, .external_lex_state = 3},
  [33] = {.lex_state = 8},
  [34] = {.lex_state = 22},
  [35] = {.lex_state = 16, .external_lex_state = 2},
  [36] = {.lex_state = 23, .external_lex_state = 4},
  [37] = {.lex_state = 22},
  [38] = {.lex_state = 8},
  [39] = {.lex_state = 26},
  [40] = {.lex_state = 23, .external_lex_state = 4},
  [41] = {.lex_state = 5},
  [42] = {.lex_state = 10},
  [43] = {.lex_state = 10},
  [44] = {.lex_state = 23, .external_lex_state = 4},
  [45] = {.lex_state = 26},
  [46] = {.lex_state = 5},
  [47] = {.lex_state = 26},
  [48] = {.lex_state = 10},
  [49] = {.lex_state = 26},
  [50] = {.lex_state = 43, .external_lex_state = 2},
  [51] = {.lex_state = 16, .external_lex_state = 2},
  [52] = {.lex_state = 26},
  [53] = {.lex_state = 45, .external_lex_state = 2},
  [54] = {.lex_state = 11},
  [55] = {.lex_state = 23},
  [56] = {.lex_state = 33, .external_lex_state = 2},
  [57] = {.lex_state = 10},
  [58] = {.lex_state = 33, .external_lex_state = 2},
  [59] = {.lex_state = 33, .external_lex_state = 2},
  [60] = {.lex_state = 33, .external_lex_state = 2},
  [61] = {.lex_state = 23},
  [62] = {.lex_state = 34},
  [63] = {.lex_state = 33, .external_lex_state = 2},
  [64] = {.lex_state = 33, .external_lex_state = 2},
  [65] = {.lex_state = 9},
  [66] = {.lex_state = 10},
  [67] = {.lex_state = 45, .external_lex_state = 2},
  [68] = {.lex_state = 55},
  [69] = {.lex_state = 23},
  [70] = {.lex_state = 16, .external_lex_state = 2},
  [71] = {.lex_state = 29},
  [72] = {.lex_state = 9},
  [73] = {.lex_state = 11},
  [74] = {.lex_state = 44, .external_lex_state = 2},
  [75] = {.lex_state = 36},
  [76] = {.lex_state = 166},
  [77] = {.lex_state = 21},
  [78] = {.lex_state = 13},
  [79] = {.lex_state = 21},
  [80] = {.lex_state = 24},
  [81] = {.lex_state = 13},
  [82] = {.lex_state = 21},
  [83] = {.lex_state = 12},
  [84] = {.lex_state = 12},
  [85] = {.lex_state = 14},
  [86] = {.lex_state = 54},
  [87] = {.lex_state = 24},
  [88] = {.lex_state = 14},
  [89] = {.lex_state = 54},
  [90] = {.lex_state = 14},
  [91] = {.lex_state = 54},
  [92] = {.lex_state = 12},
  [93] = {.lex_state = 24},
  [94] = {.lex_state = 13},
  [95] = {.lex_state = 27},
  [96] = {.lex_state = 26},
  [97] = {.lex_state = 27},
  [98] = {.lex_state = 166},
  [99] = {.lex_state = 27},
  [100] = {.lex_state = 23, .external_lex_state = 4},
  [101] = {.lex_state = 27},
  [102] = {.lex_state = 51},
  [103] = {.lex_state = 27},
  [104] = {.lex_state = 8},
  [105] = {.lex_state = 23, .external_lex_state = 4},
  [106] = {.lex_state = 20},
  [107] = {.lex_state = 33, .external_lex_state = 2},
  [108] = {.lex_state = 17, .external_lex_state = 4},
  [109] = {.lex_state = 22},
  [110] = {.lex_state = 27},
  [111] = {.lex_state = 17, .external_lex_state = 4},
  [112] = {.lex_state = 17, .external_lex_state = 4},
  [113] = {.lex_state = 55},
  [114] = {.lex_state = 17, .external_lex_state = 4},
  [115] = {.lex_state = 20},
  [116] = {.lex_state = 35},
  [117] = {.lex_state = 23, .external_lex_state = 4},
  [118] = {.lex_state = 35},
  [119] = {.lex_state = 14},
  [120] = {.lex_state = 27},
  [121] = {.lex_state = 26},
  [122] = {.lex_state = 8},
  [123] = {.lex_state = 166},
  [124] = {.lex_state = 37},
  [125] = {.lex_state = 22},
  [126] = {.lex_state = 53},
  [127] = {.lex_state = 23},
  [128] = {.lex_state = 5, .external_lex_state = 4},
  [129] = {.lex_state = 16, .external_lex_state = 4},
  [130] = {.lex_state = 11},
  [131] = {.lex_state = 39},
  [132] = {.lex_state = 39},
  [133] = {.lex_state = 11},
  [134] = {.lex_state = 33, .external_lex_state = 2},
  [135] = {.lex_state = 32},
  [136] = {.lex_state = 10},
  [137] = {.lex_state = 10},
  [138] = {.lex_state = 5},
  [139] = {.lex_state = 5, .external_lex_state = 4},
  [140] = {.lex_state = 5, .external_lex_state = 4},
  [141] = {.lex_state = 10},
  [142] = {.lex_state = 5, .external_lex_state = 4},
  [143] = {.lex_state = 32},
  [144] = {.lex_state = 16, .external_lex_state = 4},
  [145] = {.lex_state = 5, .external_lex_state = 4},
  [146] = {.lex_state = 5},
  [147] = {.lex_state = 5},
  [148] = {.lex_state = 38},
  [149] = {.lex_state = 23},
  [150] = {.lex_state = 23},
  [151] = {.lex_state = 5, .external_lex_state = 4},
  [152] = {.lex_state = 16, .external_lex_state = 4},
  [153] = {.lex_state = 5, .external_lex_state = 4},
  [154] = {.lex_state = 5, .external_lex_state = 4},
  [155] = {.lex_state = 5, .external_lex_state = 4},
  [156] = {.lex_state = 166},
  [157] = {.lex_state = 41},
  [158] = {.lex_state = 32},
  [159] = {.lex_state = 5},
  [160] = {.lex_state = 5},
  [161] = {.lex_state = 14},
  [162] = {.lex_state = 12},
  [163] = {.lex_state = 12},
  [164] = {.lex_state = 47},
  [165] = {.lex_state = 47},
  [166] = {.lex_state = 47},
  [167] = {.lex_state = 47},
  [168] = {.lex_state = 17},
  [169] = {.lex_state = 47},
  [170] = {.lex_state = 47},
  [171] = {.lex_state = 47},
  [172] = {.lex_state = 47},
  [173] = {.lex_state = 16, .external_lex_state = 4},
  [174] = {.lex_state = 47},
  [175] = {.lex_state = 47},
  [176] = {.lex_state = 47},
  [177] = {.lex_state = 47},
  [178] = {.lex_state = 166},
  [179] = {.lex_state = 47},
  [180] = {.lex_state = 47},
  [181] = {.lex_state = 166, .external_lex_state = 5},
  [182] = {.lex_state = 47},
  [183] = {.lex_state = 166, .external_lex_state = 5},
  [184] = {.lex_state = 47},
  [185] = {.lex_state = 47},
  [186] = {.lex_state = 166},
  [187] = {.lex_state = 47},
  [188] = {.lex_state = 166},
  [189] = {.lex_state = 47},
  [190] = {.lex_state = 166},
  [191] = {.lex_state = 166},
  [192] = {.lex_state = 47},
  [193] = {.lex_state = 16},
  [194] = {.lex_state = 13},
  [195] = {.lex_state = 17, .external_lex_state = 4},
  [196] = {.lex_state = 166},
  [197] = {.lex_state = 13},
  [198] = {.lex_state = 14},
  [199] = {.lex_state = 47},
  [200] = {.lex_state = 13},
  [201] = {.lex_state = 17},
  [202] = {.lex_state = 10},
  [203] = {.lex_state = 16},
  [204] = {.lex_state = 17},
  [205] = {.lex_state = 12},
  [206] = {.lex_state = 14},
  [207] = {.lex_state = 24},
  [208] = {.lex_state = 24},
  [209] = {.lex_state = 166, .external_lex_state = 5},
  [210] = {.lex_state = 166},
  [211] = {.lex_state = 24},
  [212] = {.lex_state = 54},
  [213] = {.lex_state = 16},
  [214] = {.lex_state = 54},
  [215] = {.lex_state = 54},
  [216] = {.lex_state = 47},
  [217] = {.lex_state = 14},
  [218] = {.lex_state = 38},
  [219] = {.lex_state = 20},
  [220] = {.lex_state = 17},
  [221] = {.lex_state = 14},
  [222] = {.lex_state = 55},
  [223] = {.lex_state = 20},
  [224] = {.lex_state = 20},
  [225] = {.lex_state = 5, .external_lex_state = 4},
  [226] = {.lex_state = 20},
  [227] = {.lex_state = 20},
  [228] = {.lex_state = 166},
  [229] = {.lex_state = 16},
  [230] = {.lex_state = 166},
  [231] = {.lex_state = 5, .external_lex_state = 4},
  [232] = {.lex_state = 166, .external_lex_state = 5},
  [233] = {.lex_state = 5, .external_lex_state = 4},
  [234] = {.lex_state = 5, .external_lex_state = 4},
  [235] = {.lex_state = 166},
  [236] = {.lex_state = 166},
  [237] = {.lex_state = 5},
  [238] = {.lex_state = 56},
  [239] = {.lex_state = 14},
  [240] = {.lex_state = 5, .external_lex_state = 4},
  [241] = {.lex_state = 166},
  [242] = {.lex_state = 14},
  [243] = {.lex_state = 5},
  [244] = {.lex_state = 166},
  [245] = {.lex_state = 56},
  [246] = {.lex_state = 14},
  [247] = {.lex_state = 46},
  [248] = {.lex_state = 57},
  [249] = {.lex_state = 5},
  [250] = {.lex_state = 5},
  [251] = {.lex_state = 5},
  [252] = {.lex_state = 166},
  [253] = {.lex_state = 48},
  [254] = {.lex_state = 48},
  [255] = {.lex_state = 57},
  [256] = {.lex_state = 5},
  [257] = {.lex_state = 166},
  [258] = {.lex_state = 5},
  [259] = {.lex_state = 5},
  [260] = {.lex_state = 259},
  [261] = {.lex_state = 259},
  [262] = {.lex_state = 166},
  [263] = {.lex_state = 5},
  [264] = {.lex_state = 50},
  [265] = {.lex_state = 166},
  [266] = {.lex_state = 166},
  [267] = {.lex_state = 5},
  [268] = {.lex_state = 166},
  [269] = {.lex_state = 166},
  [270] = {.lex_state = 5},
  [271] = {.lex_state = 56},
  [272] = {.lex_state = 5},
  [273] = {.lex_state = 166},
  [274] = {.lex_state = 201},
  [275] = {.lex_state = 201},
  [276] = {.lex_state = 5},
  [277] = {.lex_state = 166},
  [278] = {.lex_state = 57},
  [279] = {.lex_state = 5},
  [280] = {.lex_state = 52},
  [281] = {.lex_state = 166},
  [282] = {.lex_state = 57},
  [283] = {.lex_state = 5},
  [284] = {.lex_state = 5},
  [285] = {.lex_state = 166},
  [286] = {.lex_state = 5},
  [287] = {.lex_state = 5},
  [288] = {.lex_state = 166},
  [289] = {.lex_state = 166},
  [290] = {.lex_state = 5},
  [291] = {.lex_state = 166},
  [292] = {.lex_state = 166},
  [293] = {.lex_state = 5},
  [294] = {.lex_state = 166},
  [295] = {.lex_state = 166},
  [296] = {.lex_state = 5},
  [297] = {.lex_state = 166},
  [298] = {.lex_state = 58},
  [299] = {.lex_state = 166},
  [300] = {.lex_state = 166},
  [301] = {.lex_state = 166},
  [302] = {.lex_state = 5},
  [303] = {.lex_state = 166},
  [304] = {.lex_state = 5},
  [305] = {.lex_state = 166},
  [306] = {.lex_state = 166},
  [307] = {.lex_state = 58},
  [308] = {.lex_state = 166},
  [309] = {.lex_state = 58},
  [310] = {.lex_state = 166},
  [311] = {.lex_state = 58},
  [312] = {.lex_state = 166},
  [313] = {.lex_state = 58},
  [314] = {.lex_state = 58},
  [315] = {.lex_state = 58},
  [316] = {.lex_state = 58},
  [317] = {.lex_state = 58},
  [318] = {.lex_state = 58},
  [319] = {.lex_state = 58},
  [320] = {.lex_state = 58},
  [321] = {.lex_state = 58},
  [322] = {.lex_state = 58},
  [323] = {.lex_state = 50},
  [324] = {.lex_state = 50},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [aux_sym__immediate_user_name_or_group_fragment_token1] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [aux_sym_path_token1] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_DOLLAR2] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_variable] = ACTIONS(1),
    [aux_sym_image_name_token1] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [aux_sym_shell_fragment_token2] = ACTIONS(1),
    [sym_line_continuation] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA2] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_comment] = ACTIONS(5),
    [sym_heredoc_marker] = ACTIONS(1),
    [sym_heredoc_line] = ACTIONS(1),
    [sym_heredoc_end] = ACTIONS(1),
    [sym_heredoc_nl] = ACTIONS(1),
    [sym_error_sentinel] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(273),
    [sym__instruction] = STATE(267),
    [sym_from_instruction] = STATE(267),
    [sym_run_instruction] = STATE(267),
    [sym_cmd_instruction] = STATE(267),
    [sym_label_instruction] = STATE(267),
    [sym_expose_instruction] = STATE(267),
    [sym_env_instruction] = STATE(267),
    [sym_add_instruction] = STATE(267),
    [sym_copy_instruction] = STATE(267),
    [sym_entrypoint_instruction] = STATE(267),
    [sym_volume_instruction] = STATE(267),
    [sym_user_instruction] = STATE(267),
    [sym_workdir_instruction] = STATE(267),
    [sym_arg_instruction] = STATE(267),
    [sym_onbuild_instruction] = STATE(267),
    [sym_stopsignal_instruction] = STATE(267),
    [sym_healthcheck_instruction] = STATE(267),
    [sym_shell_instruction] = STATE(267),
    [sym_maintainer_instruction] = STATE(267),
    [sym_cross_build_instruction] = STATE(267),
    [aux_sym_source_file_repeat1] = STATE(2),
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
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 23,
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
    ACTIONS(47), 1,
      ts_builtin_sym_end,
    STATE(3), 1,
      aux_sym_source_file_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(267), 20,
      sym__instruction,
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
  [90] = 23,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    ACTIONS(51), 1,
      aux_sym_from_instruction_token1,
    ACTIONS(54), 1,
      aux_sym_run_instruction_token1,
    ACTIONS(57), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(60), 1,
      aux_sym_label_instruction_token1,
    ACTIONS(63), 1,
      aux_sym_expose_instruction_token1,
    ACTIONS(66), 1,
      aux_sym_env_instruction_token1,
    ACTIONS(69), 1,
      aux_sym_add_instruction_token1,
    ACTIONS(72), 1,
      aux_sym_copy_instruction_token1,
    ACTIONS(75), 1,
      aux_sym_entrypoint_instruction_token1,
    ACTIONS(78), 1,
      aux_sym_volume_instruction_token1,
    ACTIONS(81), 1,
      aux_sym_user_instruction_token1,
    ACTIONS(84), 1,
      aux_sym_workdir_instruction_token1,
    ACTIONS(87), 1,
      aux_sym_arg_instruction_token1,
    ACTIONS(90), 1,
      aux_sym_onbuild_instruction_token1,
    ACTIONS(93), 1,
      aux_sym_stopsignal_instruction_token1,
    ACTIONS(96), 1,
      aux_sym_healthcheck_instruction_token1,
    ACTIONS(99), 1,
      aux_sym_shell_instruction_token1,
    ACTIONS(102), 1,
      aux_sym_maintainer_instruction_token1,
    ACTIONS(105), 1,
      aux_sym_cross_build_instruction_token1,
    STATE(3), 1,
      aux_sym_source_file_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(267), 20,
      sym__instruction,
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
  [180] = 21,
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
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(279), 20,
      sym__instruction,
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
  [264] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(49), 20,
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
  [291] = 9,
    ACTIONS(110), 1,
      anon_sym_DASH_DASH,
    ACTIONS(112), 1,
      anon_sym_LBRACK,
    ACTIONS(114), 1,
      sym_heredoc_marker,
    STATE(26), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(129), 1,
      sym_shell_fragment,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(128), 2,
      sym_shell_command,
      sym_json_string_array,
    STATE(7), 3,
      sym_param,
      sym_mount_param,
      aux_sym_run_instruction_repeat1,
    ACTIONS(108), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [326] = 9,
    ACTIONS(110), 1,
      anon_sym_DASH_DASH,
    ACTIONS(112), 1,
      anon_sym_LBRACK,
    ACTIONS(114), 1,
      sym_heredoc_marker,
    STATE(26), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(129), 1,
      sym_shell_fragment,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(151), 2,
      sym_shell_command,
      sym_json_string_array,
    STATE(12), 3,
      sym_param,
      sym_mount_param,
      aux_sym_run_instruction_repeat1,
    ACTIONS(108), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [361] = 9,
    ACTIONS(116), 1,
      anon_sym_LF,
    ACTIONS(118), 1,
      anon_sym_DOLLAR2,
    ACTIONS(120), 1,
      aux_sym__env_key_token1,
    ACTIONS(122), 1,
      anon_sym_DQUOTE,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(126), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
    STATE(38), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_unquoted_string_repeat1,
    STATE(219), 3,
      sym_double_quoted_string,
      sym_single_quoted_string,
      sym_unquoted_string,
  [395] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(128), 1,
      anon_sym_DOLLAR2,
    ACTIONS(130), 1,
      anon_sym_DQUOTE,
    ACTIONS(132), 1,
      anon_sym_SQUOTE,
    ACTIONS(134), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
    STATE(17), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_unquoted_string_repeat1,
    STATE(304), 3,
      sym_double_quoted_string,
      sym_single_quoted_string,
      sym_unquoted_string,
  [425] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(128), 1,
      anon_sym_DOLLAR2,
    ACTIONS(130), 1,
      anon_sym_DQUOTE,
    ACTIONS(132), 1,
      anon_sym_SQUOTE,
    ACTIONS(134), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
    STATE(17), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_unquoted_string_repeat1,
    STATE(146), 3,
      sym_double_quoted_string,
      sym_single_quoted_string,
      sym_unquoted_string,
  [455] = 8,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(128), 1,
      anon_sym_DOLLAR2,
    ACTIONS(130), 1,
      anon_sym_DQUOTE,
    ACTIONS(132), 1,
      anon_sym_SQUOTE,
    ACTIONS(134), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
    STATE(17), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_unquoted_string_repeat1,
    STATE(296), 3,
      sym_double_quoted_string,
      sym_single_quoted_string,
      sym_unquoted_string,
  [485] = 5,
    ACTIONS(138), 1,
      anon_sym_DASH_DASH,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(141), 2,
      sym_heredoc_marker,
      anon_sym_LBRACK,
    STATE(12), 3,
      sym_param,
      sym_mount_param,
      aux_sym_run_instruction_repeat1,
    ACTIONS(136), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [508] = 11,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(143), 1,
      aux_sym_path_token1,
    ACTIONS(145), 1,
      aux_sym_path_with_heredoc_token1,
    ACTIONS(147), 1,
      anon_sym_DOLLAR,
    ACTIONS(149), 1,
      anon_sym_DASH_DASH,
    ACTIONS(151), 1,
      sym_heredoc_marker,
    STATE(63), 1,
      aux_sym_add_instruction_repeat2,
    STATE(86), 1,
      sym_expansion,
    STATE(253), 1,
      sym_path_with_heredoc,
    STATE(20), 2,
      sym_param,
      aux_sym_add_instruction_repeat1,
  [543] = 11,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(143), 1,
      aux_sym_path_token1,
    ACTIONS(145), 1,
      aux_sym_path_with_heredoc_token1,
    ACTIONS(147), 1,
      anon_sym_DOLLAR,
    ACTIONS(149), 1,
      anon_sym_DASH_DASH,
    ACTIONS(151), 1,
      sym_heredoc_marker,
    STATE(64), 1,
      aux_sym_add_instruction_repeat2,
    STATE(86), 1,
      sym_expansion,
    STATE(253), 1,
      sym_path_with_heredoc,
    STATE(19), 2,
      sym_param,
      aux_sym_add_instruction_repeat1,
  [578] = 8,
    ACTIONS(155), 1,
      aux_sym_shell_fragment_token2,
    ACTIONS(157), 1,
      anon_sym_LBRACK,
    ACTIONS(159), 1,
      sym_heredoc_marker,
    STATE(35), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(193), 1,
      sym_shell_fragment,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(251), 2,
      sym_shell_command,
      sym_json_string_array,
    ACTIONS(153), 3,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [607] = 8,
    ACTIONS(155), 1,
      aux_sym_shell_fragment_token2,
    ACTIONS(157), 1,
      anon_sym_LBRACK,
    ACTIONS(159), 1,
      sym_heredoc_marker,
    STATE(35), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(193), 1,
      sym_shell_fragment,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(258), 2,
      sym_shell_command,
      sym_json_string_array,
    ACTIONS(153), 3,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [636] = 6,
    ACTIONS(128), 1,
      anon_sym_DOLLAR2,
    ACTIONS(161), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(165), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
    ACTIONS(163), 3,
      aux_sym_label_pair_token1,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    STATE(18), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_unquoted_string_repeat1,
  [661] = 6,
    ACTIONS(167), 1,
      anon_sym_LF,
    ACTIONS(169), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(174), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
    ACTIONS(172), 3,
      aux_sym_label_pair_token1,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    STATE(18), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_unquoted_string_repeat1,
  [686] = 11,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(143), 1,
      aux_sym_path_token1,
    ACTIONS(145), 1,
      aux_sym_path_with_heredoc_token1,
    ACTIONS(147), 1,
      anon_sym_DOLLAR,
    ACTIONS(149), 1,
      anon_sym_DASH_DASH,
    ACTIONS(151), 1,
      sym_heredoc_marker,
    STATE(60), 1,
      aux_sym_add_instruction_repeat2,
    STATE(86), 1,
      sym_expansion,
    STATE(253), 1,
      sym_path_with_heredoc,
    STATE(56), 2,
      sym_param,
      aux_sym_add_instruction_repeat1,
  [721] = 11,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(143), 1,
      aux_sym_path_token1,
    ACTIONS(145), 1,
      aux_sym_path_with_heredoc_token1,
    ACTIONS(147), 1,
      anon_sym_DOLLAR,
    ACTIONS(149), 1,
      anon_sym_DASH_DASH,
    ACTIONS(151), 1,
      sym_heredoc_marker,
    STATE(58), 1,
      aux_sym_add_instruction_repeat2,
    STATE(86), 1,
      sym_expansion,
    STATE(253), 1,
      sym_path_with_heredoc,
    STATE(56), 2,
      sym_param,
      aux_sym_add_instruction_repeat1,
  [756] = 5,
    ACTIONS(181), 1,
      anon_sym_COMMA,
    STATE(23), 1,
      aux_sym_mount_param_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(179), 3,
      sym_heredoc_marker,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
    ACTIONS(177), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [778] = 6,
    ACTIONS(185), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(187), 1,
      anon_sym_DOLLAR2,
    ACTIONS(189), 1,
      aux_sym_image_name_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(183), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
    STATE(27), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_name_repeat1,
  [802] = 5,
    ACTIONS(181), 1,
      anon_sym_COMMA,
    STATE(28), 1,
      aux_sym_mount_param_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(193), 3,
      sym_heredoc_marker,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
    ACTIONS(191), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [824] = 6,
    ACTIONS(200), 1,
      sym_required_line_continuation,
    ACTIONS(202), 1,
      sym_heredoc_marker,
    STATE(24), 1,
      aux_sym_shell_fragment_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(195), 2,
      sym_heredoc_nl,
      anon_sym_LF,
    ACTIONS(197), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [848] = 6,
    ACTIONS(187), 1,
      anon_sym_DOLLAR2,
    ACTIONS(207), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(209), 1,
      aux_sym_image_name_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(205), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
    STATE(22), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_name_repeat1,
  [872] = 6,
    ACTIONS(114), 1,
      sym_heredoc_marker,
    ACTIONS(215), 1,
      sym_required_line_continuation,
    STATE(24), 1,
      aux_sym_shell_fragment_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(211), 2,
      sym_heredoc_nl,
      anon_sym_LF,
    ACTIONS(213), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [896] = 6,
    ACTIONS(219), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(221), 1,
      anon_sym_DOLLAR2,
    ACTIONS(224), 1,
      aux_sym_image_name_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(217), 3,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_AT,
    STATE(27), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_name_repeat1,
  [920] = 5,
    ACTIONS(231), 1,
      anon_sym_COMMA,
    STATE(28), 1,
      aux_sym_mount_param_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(229), 3,
      sym_heredoc_marker,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
    ACTIONS(227), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [942] = 6,
    ACTIONS(234), 1,
      anon_sym_DOLLAR2,
    ACTIONS(236), 1,
      anon_sym_DQUOTE,
    ACTIONS(240), 1,
      sym_double_quoted_escape_sequence,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(238), 2,
      aux_sym_double_quoted_string_token1,
      anon_sym_BSLASH,
    STATE(47), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_double_quoted_string_repeat1,
  [965] = 6,
    ACTIONS(234), 1,
      anon_sym_DOLLAR2,
    ACTIONS(240), 1,
      sym_double_quoted_escape_sequence,
    ACTIONS(242), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(238), 2,
      aux_sym_double_quoted_string_token1,
      anon_sym_BSLASH,
    STATE(47), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_double_quoted_string_repeat1,
  [988] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(227), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
    ACTIONS(229), 4,
      sym_heredoc_marker,
      anon_sym_DASH_DASH,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [1005] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(195), 3,
      sym_heredoc_marker,
      sym_heredoc_nl,
      anon_sym_LF,
    ACTIONS(200), 5,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
      sym_required_line_continuation,
  [1022] = 6,
    ACTIONS(167), 1,
      anon_sym_LF,
    ACTIONS(172), 1,
      aux_sym__env_key_token1,
    ACTIONS(244), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(247), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
    STATE(33), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_unquoted_string_repeat1,
  [1045] = 6,
    ACTIONS(252), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(254), 1,
      anon_sym_DOLLAR2,
    ACTIONS(256), 1,
      aux_sym_image_tag_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(250), 2,
      anon_sym_LF,
      anon_sym_AT,
    STATE(37), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_tag_repeat1,
  [1068] = 6,
    ACTIONS(159), 1,
      sym_heredoc_marker,
    ACTIONS(211), 1,
      anon_sym_LF,
    ACTIONS(215), 1,
      sym_required_line_continuation,
    STATE(51), 1,
      aux_sym_shell_fragment_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(258), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [1091] = 6,
    ACTIONS(260), 1,
      anon_sym_LF,
    ACTIONS(262), 1,
      aux_sym_path_token3,
    ACTIONS(264), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(266), 2,
      sym_heredoc_nl,
      sym__non_newline_whitespace,
    STATE(44), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [1114] = 6,
    ACTIONS(270), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(272), 1,
      anon_sym_DOLLAR2,
    ACTIONS(275), 1,
      aux_sym_image_tag_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(268), 2,
      anon_sym_LF,
      anon_sym_AT,
    STATE(37), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_tag_repeat1,
  [1137] = 6,
    ACTIONS(118), 1,
      anon_sym_DOLLAR2,
    ACTIONS(161), 1,
      anon_sym_LF,
    ACTIONS(163), 1,
      aux_sym__env_key_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(278), 2,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
    STATE(33), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_unquoted_string_repeat1,
  [1160] = 6,
    ACTIONS(234), 1,
      anon_sym_DOLLAR2,
    ACTIONS(280), 1,
      anon_sym_DQUOTE,
    ACTIONS(284), 1,
      sym_double_quoted_escape_sequence,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(282), 2,
      aux_sym_double_quoted_string_token1,
      anon_sym_BSLASH,
    STATE(45), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_double_quoted_string_repeat1,
  [1183] = 6,
    ACTIONS(286), 1,
      anon_sym_LF,
    ACTIONS(288), 1,
      aux_sym_path_token3,
    ACTIONS(291), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(294), 2,
      sym_heredoc_nl,
      sym__non_newline_whitespace,
    STATE(40), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [1206] = 7,
    ACTIONS(296), 1,
      anon_sym_LF,
    ACTIONS(298), 1,
      aux_sym_label_pair_token1,
    ACTIONS(300), 1,
      anon_sym_DQUOTE,
    ACTIONS(302), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(46), 2,
      sym_label_pair,
      aux_sym_label_instruction_repeat1,
    STATE(257), 2,
      sym_double_quoted_string,
      sym_single_quoted_string,
  [1231] = 5,
    ACTIONS(306), 1,
      aux_sym__immediate_user_name_or_group_fragment_token1,
    ACTIONS(308), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(304), 2,
      anon_sym_LF,
      anon_sym_COLON,
    STATE(43), 4,
      sym__immediate_user_name_or_group_fragment,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym__user_name_or_group_repeat1,
  [1252] = 5,
    ACTIONS(312), 1,
      aux_sym__immediate_user_name_or_group_fragment_token1,
    ACTIONS(315), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(310), 2,
      anon_sym_LF,
      anon_sym_COLON,
    STATE(43), 4,
      sym__immediate_user_name_or_group_fragment,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym__user_name_or_group_repeat1,
  [1273] = 6,
    ACTIONS(264), 1,
      anon_sym_DOLLAR2,
    ACTIONS(318), 1,
      anon_sym_LF,
    ACTIONS(320), 1,
      aux_sym_path_token3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(322), 2,
      sym_heredoc_nl,
      sym__non_newline_whitespace,
    STATE(40), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [1296] = 6,
    ACTIONS(234), 1,
      anon_sym_DOLLAR2,
    ACTIONS(240), 1,
      sym_double_quoted_escape_sequence,
    ACTIONS(324), 1,
      anon_sym_DQUOTE,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(238), 2,
      aux_sym_double_quoted_string_token1,
      anon_sym_BSLASH,
    STATE(47), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_double_quoted_string_repeat1,
  [1319] = 7,
    ACTIONS(326), 1,
      anon_sym_LF,
    ACTIONS(328), 1,
      aux_sym_label_pair_token1,
    ACTIONS(331), 1,
      anon_sym_DQUOTE,
    ACTIONS(334), 1,
      anon_sym_SQUOTE,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(46), 2,
      sym_label_pair,
      aux_sym_label_instruction_repeat1,
    STATE(257), 2,
      sym_double_quoted_string,
      sym_single_quoted_string,
  [1344] = 6,
    ACTIONS(337), 1,
      anon_sym_DOLLAR2,
    ACTIONS(340), 1,
      anon_sym_DQUOTE,
    ACTIONS(345), 1,
      sym_double_quoted_escape_sequence,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(342), 2,
      aux_sym_double_quoted_string_token1,
      anon_sym_BSLASH,
    STATE(47), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_double_quoted_string_repeat1,
  [1367] = 5,
    ACTIONS(308), 1,
      anon_sym_DOLLAR2,
    ACTIONS(350), 1,
      aux_sym__immediate_user_name_or_group_fragment_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(348), 2,
      anon_sym_LF,
      anon_sym_COLON,
    STATE(42), 4,
      sym__immediate_user_name_or_group_fragment,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym__user_name_or_group_repeat1,
  [1388] = 6,
    ACTIONS(234), 1,
      anon_sym_DOLLAR2,
    ACTIONS(352), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      sym_double_quoted_escape_sequence,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(354), 2,
      aux_sym_double_quoted_string_token1,
      anon_sym_BSLASH,
    STATE(29), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_double_quoted_string_repeat1,
  [1411] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(358), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
    ACTIONS(360), 4,
      sym_heredoc_marker,
      anon_sym_DASH_DASH,
      anon_sym_COMMA,
      anon_sym_LBRACK,
  [1428] = 6,
    ACTIONS(195), 1,
      anon_sym_LF,
    ACTIONS(200), 1,
      sym_required_line_continuation,
    ACTIONS(365), 1,
      sym_heredoc_marker,
    STATE(51), 1,
      aux_sym_shell_fragment_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(362), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [1451] = 6,
    ACTIONS(234), 1,
      anon_sym_DOLLAR2,
    ACTIONS(368), 1,
      anon_sym_DQUOTE,
    ACTIONS(372), 1,
      sym_double_quoted_escape_sequence,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(370), 2,
      aux_sym_double_quoted_string_token1,
      anon_sym_BSLASH,
    STATE(30), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_double_quoted_string_repeat1,
  [1474] = 6,
    ACTIONS(155), 1,
      aux_sym_shell_fragment_token2,
    ACTIONS(159), 1,
      sym_heredoc_marker,
    STATE(35), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(229), 1,
      sym_shell_fragment,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(153), 3,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [1496] = 6,
    ACTIONS(374), 1,
      anon_sym_LF,
    ACTIONS(376), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(378), 1,
      anon_sym_DOLLAR2,
    ACTIONS(381), 1,
      aux_sym_image_digest_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(54), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_digest_repeat1,
  [1518] = 6,
    ACTIONS(384), 1,
      anon_sym_LF,
    ACTIONS(386), 1,
      aux_sym_path_token3,
    ACTIONS(388), 1,
      anon_sym_DOLLAR2,
    ACTIONS(390), 1,
      sym__non_newline_whitespace,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(61), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [1540] = 6,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(392), 1,
      aux_sym_path_token1,
    ACTIONS(396), 1,
      anon_sym_DASH_DASH,
    STATE(56), 2,
      sym_param,
      aux_sym_add_instruction_repeat1,
    ACTIONS(394), 3,
      sym_heredoc_marker,
      aux_sym_path_with_heredoc_token1,
      anon_sym_DOLLAR,
  [1562] = 6,
    ACTIONS(399), 1,
      anon_sym_LF,
    ACTIONS(401), 1,
      aux_sym__immediate_user_name_or_group_fragment_token1,
    ACTIONS(404), 1,
      anon_sym_DOLLAR2,
    STATE(57), 1,
      aux_sym__immediate_user_name_or_group,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(202), 3,
      sym__immediate_user_name_or_group_fragment,
      sym__immediate_expansion,
      sym__imm_expansion,
  [1584] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(407), 1,
      aux_sym_path_token1,
    ACTIONS(409), 1,
      aux_sym_path_with_heredoc_token1,
    ACTIONS(411), 1,
      anon_sym_DOLLAR,
    ACTIONS(413), 1,
      sym_heredoc_marker,
    STATE(36), 1,
      sym_expansion,
    STATE(59), 1,
      aux_sym_add_instruction_repeat2,
    STATE(108), 1,
      sym_path_with_heredoc,
  [1612] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(415), 1,
      aux_sym_path_token1,
    ACTIONS(418), 1,
      aux_sym_path_with_heredoc_token1,
    ACTIONS(421), 1,
      anon_sym_DOLLAR,
    ACTIONS(424), 1,
      sym_heredoc_marker,
    STATE(59), 1,
      aux_sym_add_instruction_repeat2,
    STATE(86), 1,
      sym_expansion,
    STATE(253), 1,
      sym_path_with_heredoc,
  [1640] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(407), 1,
      aux_sym_path_token1,
    ACTIONS(409), 1,
      aux_sym_path_with_heredoc_token1,
    ACTIONS(411), 1,
      anon_sym_DOLLAR,
    ACTIONS(413), 1,
      sym_heredoc_marker,
    STATE(36), 1,
      sym_expansion,
    STATE(59), 1,
      aux_sym_add_instruction_repeat2,
    STATE(112), 1,
      sym_path_with_heredoc,
  [1668] = 6,
    ACTIONS(388), 1,
      anon_sym_DOLLAR2,
    ACTIONS(427), 1,
      anon_sym_LF,
    ACTIONS(429), 1,
      aux_sym_path_token3,
    ACTIONS(431), 1,
      sym__non_newline_whitespace,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(69), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [1690] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(157), 1,
      anon_sym_LBRACK,
    ACTIONS(433), 1,
      aux_sym_path_token1,
    ACTIONS(435), 1,
      aux_sym_path_token2,
    ACTIONS(437), 1,
      anon_sym_DOLLAR,
    STATE(55), 1,
      sym_expansion,
    STATE(201), 1,
      sym_path,
    STATE(287), 1,
      sym_json_string_array,
  [1718] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(407), 1,
      aux_sym_path_token1,
    ACTIONS(409), 1,
      aux_sym_path_with_heredoc_token1,
    ACTIONS(411), 1,
      anon_sym_DOLLAR,
    ACTIONS(413), 1,
      sym_heredoc_marker,
    STATE(36), 1,
      sym_expansion,
    STATE(59), 1,
      aux_sym_add_instruction_repeat2,
    STATE(111), 1,
      sym_path_with_heredoc,
  [1746] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(407), 1,
      aux_sym_path_token1,
    ACTIONS(409), 1,
      aux_sym_path_with_heredoc_token1,
    ACTIONS(411), 1,
      anon_sym_DOLLAR,
    ACTIONS(413), 1,
      sym_heredoc_marker,
    STATE(36), 1,
      sym_expansion,
    STATE(59), 1,
      aux_sym_add_instruction_repeat2,
    STATE(114), 1,
      sym_path_with_heredoc,
  [1774] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(439), 2,
      anon_sym_LF,
      anon_sym_DOLLAR2,
    ACTIONS(441), 5,
      aux_sym_label_pair_token1,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
  [1790] = 6,
    ACTIONS(308), 1,
      anon_sym_DOLLAR2,
    ACTIONS(443), 1,
      anon_sym_LF,
    ACTIONS(445), 1,
      aux_sym__immediate_user_name_or_group_fragment_token1,
    STATE(57), 1,
      aux_sym__immediate_user_name_or_group,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(202), 3,
      sym__immediate_user_name_or_group_fragment,
      sym__immediate_expansion,
      sym__imm_expansion,
  [1812] = 6,
    ACTIONS(114), 1,
      sym_heredoc_marker,
    ACTIONS(447), 1,
      aux_sym_shell_fragment_token2,
    STATE(26), 1,
      aux_sym_shell_fragment_repeat1,
    STATE(173), 1,
      sym_shell_fragment,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(108), 3,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [1834] = 9,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(449), 1,
      anon_sym_DOLLAR,
    ACTIONS(451), 1,
      aux_sym_image_name_token1,
    ACTIONS(453), 1,
      anon_sym_DASH_DASH,
    STATE(25), 1,
      sym_expansion,
    STATE(88), 1,
      sym_image_name,
    STATE(113), 1,
      sym_param,
    STATE(242), 1,
      sym_image_spec,
  [1862] = 6,
    ACTIONS(286), 1,
      anon_sym_LF,
    ACTIONS(294), 1,
      sym__non_newline_whitespace,
    ACTIONS(455), 1,
      aux_sym_path_token3,
    ACTIONS(458), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(69), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [1884] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(195), 2,
      sym_heredoc_marker,
      anon_sym_LF,
    ACTIONS(200), 5,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
      sym_required_line_continuation,
  [1900] = 6,
    ACTIONS(461), 1,
      aux_sym_label_pair_token1,
    ACTIONS(463), 1,
      anon_sym_DQUOTE,
    ACTIONS(465), 1,
      anon_sym_SQUOTE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(41), 2,
      sym_label_pair,
      aux_sym_label_instruction_repeat1,
    STATE(257), 2,
      sym_double_quoted_string,
      sym_single_quoted_string,
  [1922] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(467), 2,
      anon_sym_LF,
      anon_sym_DOLLAR2,
    ACTIONS(469), 5,
      aux_sym_label_pair_token1,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
  [1938] = 6,
    ACTIONS(471), 1,
      anon_sym_LF,
    ACTIONS(473), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(475), 1,
      anon_sym_DOLLAR2,
    ACTIONS(477), 1,
      aux_sym_image_digest_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(54), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_digest_repeat1,
  [1960] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(481), 3,
      sym_heredoc_marker,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
    ACTIONS(479), 4,
      aux_sym_path_token2,
      aux_sym_shell_fragment_token2,
      aux_sym_shell_fragment_token3,
      aux_sym_shell_fragment_token4,
  [1976] = 5,
    ACTIONS(308), 1,
      anon_sym_DOLLAR2,
    ACTIONS(445), 1,
      aux_sym__immediate_user_name_or_group_fragment_token1,
    STATE(66), 1,
      aux_sym__immediate_user_name_or_group,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(202), 3,
      sym__immediate_user_name_or_group_fragment,
      sym__immediate_expansion,
      sym__imm_expansion,
  [1995] = 6,
    ACTIONS(13), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(483), 1,
      anon_sym_NONE,
    ACTIONS(485), 1,
      anon_sym_DASH_DASH,
    STATE(284), 1,
      sym_cmd_instruction,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(98), 2,
      sym_param,
      aux_sym_add_instruction_repeat1,
  [2016] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(489), 2,
      aux_sym_from_instruction_token2,
      aux_sym_image_name_token2,
    ACTIONS(487), 4,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_DOLLAR2,
      anon_sym_AT,
  [2031] = 5,
    ACTIONS(491), 1,
      anon_sym_LF,
    ACTIONS(493), 1,
      anon_sym_DOLLAR2,
    ACTIONS(495), 1,
      aux_sym_image_alias_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(81), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_alias_repeat1,
  [2050] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(441), 2,
      aux_sym_from_instruction_token2,
      aux_sym_image_name_token2,
    ACTIONS(439), 4,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_DOLLAR2,
      anon_sym_AT,
  [2065] = 5,
    ACTIONS(390), 1,
      anon_sym_LF,
    ACTIONS(497), 1,
      aux_sym_path_token3,
    ACTIONS(499), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(87), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [2084] = 5,
    ACTIONS(493), 1,
      anon_sym_DOLLAR2,
    ACTIONS(501), 1,
      anon_sym_LF,
    ACTIONS(503), 1,
      aux_sym_image_alias_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(94), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_alias_repeat1,
  [2103] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(469), 2,
      aux_sym_from_instruction_token2,
      aux_sym_image_name_token2,
    ACTIONS(467), 4,
      anon_sym_LF,
      anon_sym_COLON,
      anon_sym_DOLLAR2,
      anon_sym_AT,
  [2118] = 5,
    ACTIONS(505), 1,
      anon_sym_LF,
    ACTIONS(507), 1,
      aux_sym__stopsignal_value_token2,
    ACTIONS(510), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(83), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym__stopsignal_value_repeat1,
  [2137] = 5,
    ACTIONS(513), 1,
      anon_sym_LF,
    ACTIONS(515), 1,
      aux_sym__stopsignal_value_token2,
    ACTIONS(517), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(83), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym__stopsignal_value_repeat1,
  [2156] = 5,
    ACTIONS(519), 1,
      anon_sym_LF,
    ACTIONS(521), 1,
      anon_sym_DOLLAR,
    ACTIONS(523), 1,
      aux_sym_expose_port_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(90), 3,
      sym_expansion,
      sym_expose_port,
      aux_sym_expose_instruction_repeat1,
  [2175] = 5,
    ACTIONS(266), 1,
      sym__non_newline_whitespace,
    ACTIONS(525), 1,
      aux_sym_path_token3,
    ACTIONS(527), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(89), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [2194] = 5,
    ACTIONS(431), 1,
      anon_sym_LF,
    ACTIONS(499), 1,
      anon_sym_DOLLAR2,
    ACTIONS(529), 1,
      aux_sym_path_token3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(93), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [2213] = 7,
    ACTIONS(531), 1,
      anon_sym_LF,
    ACTIONS(533), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(535), 1,
      anon_sym_COLON,
    ACTIONS(537), 1,
      anon_sym_AT,
    STATE(161), 1,
      sym_image_tag,
    STATE(239), 1,
      sym_image_digest,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [2236] = 5,
    ACTIONS(322), 1,
      sym__non_newline_whitespace,
    ACTIONS(527), 1,
      anon_sym_DOLLAR2,
    ACTIONS(539), 1,
      aux_sym_path_token3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(91), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [2255] = 5,
    ACTIONS(541), 1,
      anon_sym_LF,
    ACTIONS(543), 1,
      anon_sym_DOLLAR,
    ACTIONS(546), 1,
      aux_sym_expose_port_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(90), 3,
      sym_expansion,
      sym_expose_port,
      aux_sym_expose_instruction_repeat1,
  [2274] = 5,
    ACTIONS(294), 1,
      sym__non_newline_whitespace,
    ACTIONS(549), 1,
      aux_sym_path_token3,
    ACTIONS(552), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(91), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [2293] = 5,
    ACTIONS(517), 1,
      anon_sym_DOLLAR2,
    ACTIONS(555), 1,
      anon_sym_LF,
    ACTIONS(557), 1,
      aux_sym__stopsignal_value_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(84), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym__stopsignal_value_repeat1,
  [2312] = 5,
    ACTIONS(294), 1,
      anon_sym_LF,
    ACTIONS(559), 1,
      aux_sym_path_token3,
    ACTIONS(562), 1,
      anon_sym_DOLLAR2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(93), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_path_repeat1,
  [2331] = 5,
    ACTIONS(565), 1,
      anon_sym_LF,
    ACTIONS(567), 1,
      anon_sym_DOLLAR2,
    ACTIONS(570), 1,
      aux_sym_image_alias_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(94), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_alias_repeat1,
  [2350] = 5,
    ACTIONS(575), 1,
      anon_sym_SQUOTE,
    ACTIONS(577), 1,
      sym_single_quoted_escape_sequence,
    STATE(110), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(573), 2,
      anon_sym_BSLASH,
      aux_sym_single_quoted_string_token1,
  [2368] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(467), 2,
      anon_sym_DOLLAR2,
      sym_double_quoted_escape_sequence,
    ACTIONS(469), 3,
      anon_sym_DQUOTE,
      aux_sym_double_quoted_string_token1,
      anon_sym_BSLASH,
  [2382] = 5,
    ACTIONS(577), 1,
      sym_single_quoted_escape_sequence,
    ACTIONS(579), 1,
      anon_sym_SQUOTE,
    STATE(110), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(573), 2,
      anon_sym_BSLASH,
      aux_sym_single_quoted_string_token1,
  [2400] = 5,
    ACTIONS(13), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(485), 1,
      anon_sym_DASH_DASH,
    STATE(263), 1,
      sym_cmd_instruction,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(156), 2,
      sym_param,
      aux_sym_add_instruction_repeat1,
  [2418] = 5,
    ACTIONS(583), 1,
      anon_sym_SQUOTE,
    ACTIONS(585), 1,
      sym_single_quoted_escape_sequence,
    STATE(97), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(581), 2,
      anon_sym_BSLASH,
      aux_sym_single_quoted_string_token1,
  [2436] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(441), 2,
      anon_sym_LF,
      aux_sym_path_token3,
    ACTIONS(439), 3,
      sym_heredoc_nl,
      anon_sym_DOLLAR2,
      sym__non_newline_whitespace,
  [2450] = 5,
    ACTIONS(577), 1,
      sym_single_quoted_escape_sequence,
    ACTIONS(587), 1,
      anon_sym_SQUOTE,
    STATE(110), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(573), 2,
      anon_sym_BSLASH,
      aux_sym_single_quoted_string_token1,
  [2468] = 5,
    ACTIONS(589), 1,
      aux_sym__env_key_token1,
    STATE(247), 1,
      sym__env_key,
    STATE(256), 1,
      sym__spaced_env_pair,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(115), 2,
      sym_env_pair,
      aux_sym_env_instruction_repeat1,
  [2486] = 5,
    ACTIONS(593), 1,
      anon_sym_SQUOTE,
    ACTIONS(595), 1,
      sym_single_quoted_escape_sequence,
    STATE(101), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(591), 2,
      anon_sym_BSLASH,
      aux_sym_single_quoted_string_token1,
  [2504] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(467), 2,
      anon_sym_LF,
      anon_sym_DOLLAR2,
    ACTIONS(469), 3,
      aux_sym__env_key_token1,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
  [2518] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(489), 2,
      anon_sym_LF,
      aux_sym_path_token3,
    ACTIONS(487), 3,
      sym_heredoc_nl,
      anon_sym_DOLLAR2,
      sym__non_newline_whitespace,
  [2532] = 5,
    ACTIONS(597), 1,
      anon_sym_LF,
    ACTIONS(599), 1,
      aux_sym__env_key_token1,
    STATE(265), 1,
      sym__env_key,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(106), 2,
      sym_env_pair,
      aux_sym_env_instruction_repeat1,
  [2550] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(479), 1,
      aux_sym_path_token1,
    ACTIONS(481), 4,
      sym_heredoc_marker,
      aux_sym_path_with_heredoc_token1,
      anon_sym_DOLLAR,
      anon_sym_DASH_DASH,
  [2566] = 5,
    ACTIONS(602), 1,
      anon_sym_LF,
    ACTIONS(604), 1,
      sym__non_newline_whitespace,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(140), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [2584] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(441), 2,
      aux_sym_from_instruction_token2,
      aux_sym_image_tag_token1,
    ACTIONS(439), 3,
      anon_sym_LF,
      anon_sym_DOLLAR2,
      anon_sym_AT,
  [2598] = 5,
    ACTIONS(611), 1,
      anon_sym_SQUOTE,
    ACTIONS(613), 1,
      sym_single_quoted_escape_sequence,
    STATE(110), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(608), 2,
      anon_sym_BSLASH,
      aux_sym_single_quoted_string_token1,
  [2616] = 5,
    ACTIONS(604), 1,
      sym__non_newline_whitespace,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(616), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(153), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [2634] = 5,
    ACTIONS(604), 1,
      sym__non_newline_whitespace,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(618), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(139), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [2652] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(449), 1,
      anon_sym_DOLLAR,
    ACTIONS(451), 1,
      aux_sym_image_name_token1,
    STATE(25), 1,
      sym_expansion,
    STATE(88), 1,
      sym_image_name,
    STATE(221), 1,
      sym_image_spec,
  [2674] = 5,
    ACTIONS(604), 1,
      sym__non_newline_whitespace,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(620), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(155), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [2692] = 5,
    ACTIONS(622), 1,
      anon_sym_LF,
    ACTIONS(624), 1,
      aux_sym__env_key_token1,
    STATE(265), 1,
      sym__env_key,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(106), 2,
      sym_env_pair,
      aux_sym_env_instruction_repeat1,
  [2710] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(433), 1,
      aux_sym_path_token1,
    ACTIONS(435), 1,
      aux_sym_path_token2,
    ACTIONS(437), 1,
      anon_sym_DOLLAR,
    STATE(55), 1,
      sym_expansion,
    STATE(220), 1,
      sym_path,
  [2732] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(469), 2,
      anon_sym_LF,
      aux_sym_path_token3,
    ACTIONS(467), 3,
      sym_heredoc_nl,
      anon_sym_DOLLAR2,
      sym__non_newline_whitespace,
  [2746] = 7,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(626), 1,
      aux_sym_path_token1,
    ACTIONS(628), 1,
      aux_sym_path_token2,
    ACTIONS(630), 1,
      anon_sym_DOLLAR,
    STATE(80), 1,
      sym_expansion,
    STATE(276), 1,
      sym_path,
  [2768] = 4,
    ACTIONS(632), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(634), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
    ACTIONS(636), 2,
      anon_sym_SLASHtcp,
      anon_sym_SLASHudp,
  [2784] = 5,
    ACTIONS(640), 1,
      anon_sym_SQUOTE,
    ACTIONS(642), 1,
      sym_single_quoted_escape_sequence,
    STATE(95), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(638), 2,
      anon_sym_BSLASH,
      aux_sym_single_quoted_string_token1,
  [2802] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(439), 2,
      anon_sym_DOLLAR2,
      sym_double_quoted_escape_sequence,
    ACTIONS(441), 3,
      anon_sym_DQUOTE,
      aux_sym_double_quoted_string_token1,
      anon_sym_BSLASH,
  [2816] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(439), 2,
      anon_sym_LF,
      anon_sym_DOLLAR2,
    ACTIONS(441), 3,
      aux_sym__env_key_token1,
      aux_sym_unquoted_string_token1,
      anon_sym_BSLASH2,
  [2830] = 4,
    ACTIONS(644), 1,
      anon_sym_DOLLAR,
    ACTIONS(646), 1,
      aux_sym_expose_port_token1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(85), 3,
      sym_expansion,
      sym_expose_port,
      aux_sym_expose_instruction_repeat1,
  [2846] = 4,
    ACTIONS(475), 1,
      anon_sym_DOLLAR2,
    ACTIONS(648), 1,
      aux_sym_image_digest_token1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(73), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_digest_repeat1,
  [2862] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(469), 2,
      aux_sym_from_instruction_token2,
      aux_sym_image_tag_token1,
    ACTIONS(467), 3,
      anon_sym_LF,
      anon_sym_DOLLAR2,
      anon_sym_AT,
  [2876] = 5,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(254), 1,
      anon_sym_DOLLAR2,
    ACTIONS(650), 1,
      aux_sym_image_tag_token1,
    STATE(34), 3,
      sym__immediate_expansion,
      sym__imm_expansion,
      aux_sym_image_tag_repeat1,
  [2894] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(467), 2,
      anon_sym_DOLLAR2,
      sym__non_newline_whitespace,
    ACTIONS(469), 2,
      anon_sym_LF,
      aux_sym_path_token3,
  [2907] = 4,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(652), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(154), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [2922] = 4,
    ACTIONS(656), 1,
      sym_required_line_continuation,
    STATE(152), 1,
      aux_sym_shell_command_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(654), 2,
      sym_heredoc_nl,
      anon_sym_LF,
  [2937] = 3,
    ACTIONS(469), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(467), 3,
      anon_sym_LF,
      anon_sym_DOLLAR2,
      aux_sym_image_digest_token1,
  [2950] = 5,
    ACTIONS(658), 1,
      anon_sym_DOLLAR,
    ACTIONS(660), 1,
      aux_sym_image_alias_token1,
    STATE(78), 1,
      sym_expansion,
    STATE(259), 1,
      sym_image_alias,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [2967] = 5,
    ACTIONS(658), 1,
      anon_sym_DOLLAR,
    ACTIONS(660), 1,
      aux_sym_image_alias_token1,
    STATE(78), 1,
      sym_expansion,
    STATE(293), 1,
      sym_image_alias,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [2984] = 3,
    ACTIONS(441), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(439), 3,
      anon_sym_LF,
      anon_sym_DOLLAR2,
      aux_sym_image_digest_token1,
  [2997] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(662), 1,
      aux_sym_path_token1,
    ACTIONS(664), 3,
      sym_heredoc_marker,
      aux_sym_path_with_heredoc_token1,
      anon_sym_DOLLAR,
  [3012] = 5,
    ACTIONS(666), 1,
      anon_sym_DQUOTE,
    ACTIONS(668), 1,
      aux_sym_json_string_token1,
    ACTIONS(670), 1,
      sym_json_escape_sequence,
    STATE(143), 1,
      aux_sym_json_string_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [3029] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(467), 4,
      anon_sym_LF,
      anon_sym_COLON,
      aux_sym__immediate_user_name_or_group_fragment_token1,
      anon_sym_DOLLAR2,
  [3040] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(439), 4,
      anon_sym_LF,
      anon_sym_COLON,
      aux_sym__immediate_user_name_or_group_fragment_token1,
      anon_sym_DOLLAR2,
  [3051] = 3,
    ACTIONS(672), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(674), 3,
      aux_sym_label_pair_token1,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [3064] = 4,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(676), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(142), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [3079] = 4,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(678), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(142), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [3094] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(487), 4,
      anon_sym_LF,
      anon_sym_COLON,
      aux_sym__immediate_user_name_or_group_fragment_token1,
      anon_sym_DOLLAR2,
  [3105] = 4,
    ACTIONS(680), 1,
      anon_sym_LF,
    ACTIONS(682), 1,
      sym_heredoc_nl,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(142), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [3120] = 5,
    ACTIONS(685), 1,
      anon_sym_DQUOTE,
    ACTIONS(687), 1,
      aux_sym_json_string_token1,
    ACTIONS(690), 1,
      sym_json_escape_sequence,
    STATE(143), 1,
      aux_sym_json_string_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [3137] = 4,
    ACTIONS(695), 1,
      sym_required_line_continuation,
    STATE(144), 1,
      aux_sym_shell_command_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(693), 2,
      sym_heredoc_nl,
      anon_sym_LF,
  [3152] = 4,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(698), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(142), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [3167] = 3,
    ACTIONS(700), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(702), 3,
      aux_sym_label_pair_token1,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [3180] = 3,
    ACTIONS(704), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(706), 3,
      aux_sym_label_pair_token1,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [3193] = 5,
    ACTIONS(708), 1,
      aux_sym__stopsignal_value_token1,
    ACTIONS(710), 1,
      anon_sym_DOLLAR,
    STATE(92), 1,
      sym_expansion,
    STATE(283), 1,
      sym__stopsignal_value,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3210] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(439), 2,
      anon_sym_DOLLAR2,
      sym__non_newline_whitespace,
    ACTIONS(441), 2,
      anon_sym_LF,
      aux_sym_path_token3,
  [3223] = 3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(487), 2,
      anon_sym_DOLLAR2,
      sym__non_newline_whitespace,
    ACTIONS(489), 2,
      anon_sym_LF,
      aux_sym_path_token3,
  [3236] = 4,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(712), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(145), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [3251] = 4,
    ACTIONS(656), 1,
      sym_required_line_continuation,
    STATE(144), 1,
      aux_sym_shell_command_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(714), 2,
      sym_heredoc_nl,
      anon_sym_LF,
  [3266] = 4,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(716), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(142), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [3281] = 4,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(712), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(142), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [3296] = 4,
    ACTIONS(606), 1,
      sym_heredoc_nl,
    ACTIONS(718), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    STATE(142), 2,
      sym_heredoc_block,
      aux_sym_run_instruction_repeat2,
  [3311] = 4,
    ACTIONS(394), 1,
      aux_sym_cmd_instruction_token1,
    ACTIONS(720), 1,
      anon_sym_DASH_DASH,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    STATE(156), 2,
      sym_param,
      aux_sym_add_instruction_repeat1,
  [3326] = 5,
    ACTIONS(723), 1,
      aux_sym__user_name_or_group_token1,
    ACTIONS(725), 1,
      anon_sym_DOLLAR,
    STATE(48), 1,
      sym_expansion,
    STATE(243), 1,
      sym__user_name_or_group,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3343] = 5,
    ACTIONS(727), 1,
      anon_sym_DQUOTE,
    ACTIONS(729), 1,
      aux_sym_json_string_token1,
    ACTIONS(731), 1,
      sym_json_escape_sequence,
    STATE(135), 1,
      aux_sym_json_string_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [3360] = 3,
    ACTIONS(733), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(735), 3,
      aux_sym_label_pair_token1,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [3373] = 3,
    ACTIONS(737), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(739), 3,
      aux_sym_label_pair_token1,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [3386] = 5,
    ACTIONS(537), 1,
      anon_sym_AT,
    ACTIONS(741), 1,
      anon_sym_LF,
    ACTIONS(743), 1,
      aux_sym_from_instruction_token2,
    STATE(246), 1,
      sym_image_digest,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [3403] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(439), 3,
      anon_sym_LF,
      aux_sym__stopsignal_value_token2,
      anon_sym_DOLLAR2,
  [3413] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(467), 3,
      anon_sym_LF,
      aux_sym__stopsignal_value_token2,
      anon_sym_DOLLAR2,
  [3423] = 4,
    ACTIONS(745), 1,
      anon_sym_LBRACE,
    ACTIONS(747), 1,
      sym_variable,
    STATE(194), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3437] = 4,
    ACTIONS(749), 1,
      anon_sym_LBRACE,
    ACTIONS(751), 1,
      sym_variable,
    STATE(100), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3451] = 4,
    ACTIONS(753), 1,
      anon_sym_LBRACE,
    ACTIONS(755), 1,
      sym_variable,
    STATE(122), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3465] = 4,
    ACTIONS(757), 1,
      anon_sym_LBRACE,
    ACTIONS(759), 1,
      sym_variable,
    STATE(65), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3479] = 4,
    ACTIONS(761), 1,
      anon_sym_LF,
    ACTIONS(763), 1,
      sym__non_newline_whitespace,
    STATE(168), 1,
      aux_sym_volume_instruction_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [3493] = 4,
    ACTIONS(745), 1,
      anon_sym_LBRACE,
    ACTIONS(766), 1,
      sym_variable,
    STATE(200), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3507] = 4,
    ACTIONS(768), 1,
      anon_sym_LBRACE,
    ACTIONS(770), 1,
      sym_variable,
    STATE(133), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3521] = 4,
    ACTIONS(749), 1,
      anon_sym_LBRACE,
    ACTIONS(772), 1,
      sym_variable,
    STATE(105), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3535] = 4,
    ACTIONS(774), 1,
      anon_sym_LBRACE,
    ACTIONS(776), 1,
      sym_variable,
    STATE(109), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3549] = 3,
    ACTIONS(778), 1,
      sym_required_line_continuation,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(693), 2,
      sym_heredoc_nl,
      anon_sym_LF,
  [3561] = 4,
    ACTIONS(780), 1,
      anon_sym_LBRACE,
    ACTIONS(782), 1,
      sym_variable,
    STATE(205), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3575] = 4,
    ACTIONS(780), 1,
      anon_sym_LBRACE,
    ACTIONS(784), 1,
      sym_variable,
    STATE(162), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3589] = 4,
    ACTIONS(786), 1,
      anon_sym_LBRACE,
    ACTIONS(788), 1,
      sym_variable,
    STATE(211), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3603] = 4,
    ACTIONS(786), 1,
      anon_sym_LBRACE,
    ACTIONS(790), 1,
      sym_variable,
    STATE(208), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3617] = 4,
    ACTIONS(792), 1,
      anon_sym_COMMA2,
    ACTIONS(795), 1,
      anon_sym_RBRACK,
    STATE(178), 1,
      aux_sym_json_string_array_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3631] = 4,
    ACTIONS(797), 1,
      anon_sym_LBRACE,
    ACTIONS(799), 1,
      sym_variable,
    STATE(141), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3645] = 4,
    ACTIONS(797), 1,
      anon_sym_LBRACE,
    ACTIONS(801), 1,
      sym_variable,
    STATE(137), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3659] = 4,
    ACTIONS(803), 1,
      sym_heredoc_line,
    ACTIONS(806), 1,
      sym_heredoc_end,
    STATE(181), 1,
      aux_sym_heredoc_block_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3673] = 4,
    ACTIONS(808), 1,
      anon_sym_LBRACE,
    ACTIONS(810), 1,
      sym_variable,
    STATE(150), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3687] = 4,
    ACTIONS(812), 1,
      sym_heredoc_line,
    ACTIONS(814), 1,
      sym_heredoc_end,
    STATE(181), 1,
      aux_sym_heredoc_block_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3701] = 4,
    ACTIONS(808), 1,
      anon_sym_LBRACE,
    ACTIONS(816), 1,
      sym_variable,
    STATE(149), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3715] = 4,
    ACTIONS(818), 1,
      anon_sym_LBRACE,
    ACTIONS(820), 1,
      sym_variable,
    STATE(215), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3729] = 4,
    ACTIONS(822), 1,
      anon_sym_COMMA2,
    ACTIONS(824), 1,
      anon_sym_RBRACK,
    STATE(178), 1,
      aux_sym_json_string_array_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3743] = 4,
    ACTIONS(818), 1,
      anon_sym_LBRACE,
    ACTIONS(826), 1,
      sym_variable,
    STATE(214), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3757] = 4,
    ACTIONS(822), 1,
      anon_sym_COMMA2,
    ACTIONS(828), 1,
      anon_sym_RBRACK,
    STATE(178), 1,
      aux_sym_json_string_array_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3771] = 4,
    ACTIONS(830), 1,
      anon_sym_LBRACE,
    ACTIONS(832), 1,
      sym_variable,
    STATE(77), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3785] = 4,
    ACTIONS(822), 1,
      anon_sym_COMMA2,
    ACTIONS(834), 1,
      anon_sym_RBRACK,
    STATE(188), 1,
      aux_sym_json_string_array_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3799] = 4,
    ACTIONS(836), 1,
      anon_sym_RBRACK,
    ACTIONS(838), 1,
      anon_sym_DQUOTE,
    STATE(190), 1,
      sym_json_string,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3813] = 4,
    ACTIONS(840), 1,
      anon_sym_LBRACE,
    ACTIONS(842), 1,
      sym_variable,
    STATE(198), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3827] = 4,
    ACTIONS(654), 1,
      anon_sym_LF,
    ACTIONS(844), 1,
      sym_required_line_continuation,
    STATE(203), 1,
      aux_sym_shell_command_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [3841] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(439), 3,
      anon_sym_LF,
      anon_sym_DOLLAR2,
      aux_sym_image_alias_token2,
  [3851] = 3,
    ACTIONS(260), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(266), 2,
      sym_heredoc_nl,
      sym__non_newline_whitespace,
  [3863] = 4,
    ACTIONS(838), 1,
      anon_sym_DQUOTE,
    ACTIONS(846), 1,
      anon_sym_RBRACK,
    STATE(210), 1,
      sym_json_string,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3877] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(467), 3,
      anon_sym_LF,
      anon_sym_DOLLAR2,
      aux_sym_image_alias_token2,
  [3887] = 3,
    ACTIONS(487), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(489), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
  [3899] = 4,
    ACTIONS(848), 1,
      anon_sym_LBRACE,
    ACTIONS(850), 1,
      sym_variable,
    STATE(121), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [3913] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(487), 3,
      anon_sym_LF,
      anon_sym_DOLLAR2,
      aux_sym_image_alias_token2,
  [3923] = 4,
    ACTIONS(852), 1,
      anon_sym_LF,
    ACTIONS(854), 1,
      sym__non_newline_whitespace,
    STATE(204), 1,
      aux_sym_volume_instruction_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [3937] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(856), 3,
      anon_sym_LF,
      aux_sym__immediate_user_name_or_group_fragment_token1,
      anon_sym_DOLLAR2,
  [3947] = 4,
    ACTIONS(714), 1,
      anon_sym_LF,
    ACTIONS(844), 1,
      sym_required_line_continuation,
    STATE(213), 1,
      aux_sym_shell_command_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [3961] = 4,
    ACTIONS(854), 1,
      sym__non_newline_whitespace,
    ACTIONS(858), 1,
      anon_sym_LF,
    STATE(168), 1,
      aux_sym_volume_instruction_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [3975] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(487), 3,
      anon_sym_LF,
      aux_sym__stopsignal_value_token2,
      anon_sym_DOLLAR2,
  [3985] = 3,
    ACTIONS(860), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(862), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
  [3997] = 3,
    ACTIONS(469), 1,
      aux_sym_path_token3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(467), 2,
      anon_sym_LF,
      anon_sym_DOLLAR2,
  [4009] = 3,
    ACTIONS(441), 1,
      aux_sym_path_token3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(439), 2,
      anon_sym_LF,
      anon_sym_DOLLAR2,
  [4021] = 4,
    ACTIONS(812), 1,
      sym_heredoc_line,
    ACTIONS(864), 1,
      sym_heredoc_end,
    STATE(183), 1,
      aux_sym_heredoc_block_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4035] = 4,
    ACTIONS(822), 1,
      anon_sym_COMMA2,
    ACTIONS(866), 1,
      anon_sym_RBRACK,
    STATE(186), 1,
      aux_sym_json_string_array_repeat1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4049] = 3,
    ACTIONS(489), 1,
      aux_sym_path_token3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(487), 2,
      anon_sym_LF,
      anon_sym_DOLLAR2,
  [4061] = 3,
    ACTIONS(469), 1,
      aux_sym_path_token3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(467), 2,
      anon_sym_DOLLAR2,
      sym__non_newline_whitespace,
  [4073] = 4,
    ACTIONS(693), 1,
      anon_sym_LF,
    ACTIONS(868), 1,
      sym_required_line_continuation,
    STATE(213), 1,
      aux_sym_shell_command_repeat1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4087] = 3,
    ACTIONS(441), 1,
      aux_sym_path_token3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(439), 2,
      anon_sym_DOLLAR2,
      sym__non_newline_whitespace,
  [4099] = 3,
    ACTIONS(489), 1,
      aux_sym_path_token3,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(487), 2,
      anon_sym_DOLLAR2,
      sym__non_newline_whitespace,
  [4111] = 4,
    ACTIONS(830), 1,
      anon_sym_LBRACE,
    ACTIONS(871), 1,
      sym_variable,
    STATE(79), 1,
      sym__expansion_body,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4125] = 3,
    ACTIONS(467), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(469), 2,
      anon_sym_DOLLAR,
      aux_sym_expose_port_token1,
  [4137] = 3,
    ACTIONS(873), 1,
      aux_sym_param_token1,
    ACTIONS(875), 1,
      anon_sym_mount,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4148] = 3,
    ACTIONS(877), 1,
      anon_sym_LF,
    ACTIONS(879), 1,
      aux_sym__env_key_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4159] = 3,
    ACTIONS(761), 1,
      anon_sym_LF,
    ACTIONS(881), 1,
      sym__non_newline_whitespace,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4170] = 3,
    ACTIONS(883), 1,
      anon_sym_LF,
    ACTIONS(885), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4181] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(479), 1,
      aux_sym_image_name_token1,
    ACTIONS(481), 1,
      anon_sym_DOLLAR,
  [4194] = 3,
    ACTIONS(672), 1,
      anon_sym_LF,
    ACTIONS(674), 1,
      aux_sym__env_key_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4205] = 3,
    ACTIONS(704), 1,
      anon_sym_LF,
    ACTIONS(706), 1,
      aux_sym__env_key_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4216] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(887), 2,
      sym_heredoc_nl,
      anon_sym_LF,
  [4225] = 3,
    ACTIONS(733), 1,
      anon_sym_LF,
    ACTIONS(735), 1,
      aux_sym__env_key_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4236] = 3,
    ACTIONS(737), 1,
      anon_sym_LF,
    ACTIONS(739), 1,
      aux_sym__env_key_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4247] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(889), 2,
      anon_sym_COMMA2,
      anon_sym_RBRACK,
  [4256] = 3,
    ACTIONS(693), 1,
      anon_sym_LF,
    ACTIONS(778), 1,
      sym_required_line_continuation,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4267] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(795), 2,
      anon_sym_COMMA2,
      anon_sym_RBRACK,
  [4276] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(891), 2,
      sym_heredoc_nl,
      anon_sym_LF,
  [4285] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(806), 2,
      sym_heredoc_line,
      sym_heredoc_end,
  [4294] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(893), 2,
      sym_heredoc_nl,
      anon_sym_LF,
  [4303] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(895), 2,
      sym_heredoc_nl,
      anon_sym_LF,
  [4312] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(481), 2,
      aux_sym_cmd_instruction_token1,
      anon_sym_DASH_DASH,
  [4321] = 3,
    ACTIONS(157), 1,
      anon_sym_LBRACK,
    STATE(286), 1,
      sym_json_string_array,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4332] = 3,
    ACTIONS(897), 1,
      anon_sym_LF,
    ACTIONS(899), 1,
      anon_sym_EQ,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4343] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(901), 1,
      aux_sym_mount_param_param_token1,
    STATE(31), 1,
      sym_mount_param_param,
  [4356] = 3,
    ACTIONS(903), 1,
      anon_sym_LF,
    ACTIONS(905), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4367] = 2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(907), 2,
      sym_heredoc_nl,
      anon_sym_LF,
  [4376] = 3,
    ACTIONS(838), 1,
      anon_sym_DQUOTE,
    STATE(230), 1,
      sym_json_string,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4387] = 3,
    ACTIONS(909), 1,
      anon_sym_LF,
    ACTIONS(911), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4398] = 3,
    ACTIONS(913), 1,
      anon_sym_LF,
    ACTIONS(915), 1,
      anon_sym_COLON,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4409] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(917), 2,
      anon_sym_COMMA2,
      anon_sym_RBRACK,
  [4418] = 4,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(901), 1,
      aux_sym_mount_param_param_token1,
    STATE(21), 1,
      sym_mount_param_param,
  [4431] = 3,
    ACTIONS(919), 1,
      anon_sym_LF,
    ACTIONS(921), 1,
      aux_sym_from_instruction_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4442] = 3,
    ACTIONS(923), 1,
      anon_sym_EQ,
    ACTIONS(925), 1,
      aux_sym__spaced_env_pair_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4453] = 3,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(927), 1,
      aux_sym_param_token2,
  [4463] = 2,
    ACTIONS(929), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4471] = 2,
    ACTIONS(887), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4479] = 2,
    ACTIONS(931), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4487] = 2,
    ACTIONS(933), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4495] = 2,
    ACTIONS(604), 1,
      sym__non_newline_whitespace,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4503] = 2,
    ACTIONS(266), 1,
      sym__non_newline_whitespace,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4511] = 3,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(935), 1,
      aux_sym_param_token2,
  [4521] = 2,
    ACTIONS(937), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4529] = 2,
    ACTIONS(939), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4537] = 2,
    ACTIONS(941), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4545] = 2,
    ACTIONS(943), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4553] = 2,
    ACTIONS(945), 1,
      aux_sym_shell_fragment_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4561] = 2,
    ACTIONS(947), 1,
      aux_sym_shell_fragment_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4569] = 2,
    ACTIONS(949), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4577] = 2,
    ACTIONS(951), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4585] = 2,
    ACTIONS(953), 1,
      aux_sym_param_token1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4593] = 2,
    ACTIONS(923), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4601] = 2,
    ACTIONS(704), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4609] = 2,
    ACTIONS(955), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4617] = 2,
    ACTIONS(957), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4625] = 2,
    ACTIONS(672), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4633] = 2,
    ACTIONS(907), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4641] = 3,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(959), 1,
      aux_sym_mount_param_param_token1,
  [4651] = 2,
    ACTIONS(961), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4659] = 2,
    ACTIONS(963), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4667] = 2,
    ACTIONS(965), 1,
      aux_sym_maintainer_instruction_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4675] = 2,
    ACTIONS(967), 1,
      aux_sym_maintainer_instruction_token2,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4683] = 2,
    ACTIONS(969), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4691] = 2,
    ACTIONS(971), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4699] = 3,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(973), 1,
      aux_sym_param_token2,
  [4709] = 2,
    ACTIONS(975), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4717] = 2,
    ACTIONS(977), 1,
      aux_sym_arg_instruction_token2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4725] = 2,
    ACTIONS(979), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4733] = 3,
    ACTIONS(3), 1,
      sym_line_continuation,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(981), 1,
      aux_sym_param_token2,
  [4743] = 2,
    ACTIONS(983), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4751] = 2,
    ACTIONS(985), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4759] = 2,
    ACTIONS(987), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4767] = 2,
    ACTIONS(989), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4775] = 2,
    ACTIONS(991), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4783] = 2,
    ACTIONS(993), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4791] = 2,
    ACTIONS(733), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4799] = 2,
    ACTIONS(995), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4807] = 2,
    ACTIONS(997), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4815] = 2,
    ACTIONS(999), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4823] = 2,
    ACTIONS(1001), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4831] = 2,
    ACTIONS(1003), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4839] = 2,
    ACTIONS(737), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4847] = 2,
    ACTIONS(1005), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4855] = 2,
    ACTIONS(1007), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4863] = 2,
    ACTIONS(1009), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4871] = 2,
    ACTIONS(1011), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4879] = 2,
    ACTIONS(1013), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4887] = 2,
    ACTIONS(1015), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4895] = 2,
    ACTIONS(891), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4903] = 2,
    ACTIONS(1017), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4911] = 2,
    ACTIONS(1019), 1,
      anon_sym_LF,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4919] = 2,
    ACTIONS(1021), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4927] = 2,
    ACTIONS(1023), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4935] = 2,
    ACTIONS(1025), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4943] = 2,
    ACTIONS(1027), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4951] = 2,
    ACTIONS(1029), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4959] = 2,
    ACTIONS(1031), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4967] = 2,
    ACTIONS(1033), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4975] = 2,
    ACTIONS(1035), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [4983] = 2,
    ACTIONS(1037), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4991] = 2,
    ACTIONS(1039), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [4999] = 2,
    ACTIONS(1041), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [5007] = 2,
    ACTIONS(1043), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [5015] = 2,
    ACTIONS(1045), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [5023] = 2,
    ACTIONS(1047), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [5031] = 2,
    ACTIONS(1049), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [5039] = 2,
    ACTIONS(1051), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [5047] = 2,
    ACTIONS(1053), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [5055] = 2,
    ACTIONS(1055), 1,
      aux_sym__expansion_body_token1,
    ACTIONS(5), 2,
      sym_line_continuation,
      sym_comment,
  [5063] = 2,
    ACTIONS(1057), 1,
      aux_sym_param_token1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [5071] = 2,
    ACTIONS(1059), 1,
      aux_sym_param_token1,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 90,
  [SMALL_STATE(4)] = 180,
  [SMALL_STATE(5)] = 264,
  [SMALL_STATE(6)] = 291,
  [SMALL_STATE(7)] = 326,
  [SMALL_STATE(8)] = 361,
  [SMALL_STATE(9)] = 395,
  [SMALL_STATE(10)] = 425,
  [SMALL_STATE(11)] = 455,
  [SMALL_STATE(12)] = 485,
  [SMALL_STATE(13)] = 508,
  [SMALL_STATE(14)] = 543,
  [SMALL_STATE(15)] = 578,
  [SMALL_STATE(16)] = 607,
  [SMALL_STATE(17)] = 636,
  [SMALL_STATE(18)] = 661,
  [SMALL_STATE(19)] = 686,
  [SMALL_STATE(20)] = 721,
  [SMALL_STATE(21)] = 756,
  [SMALL_STATE(22)] = 778,
  [SMALL_STATE(23)] = 802,
  [SMALL_STATE(24)] = 824,
  [SMALL_STATE(25)] = 848,
  [SMALL_STATE(26)] = 872,
  [SMALL_STATE(27)] = 896,
  [SMALL_STATE(28)] = 920,
  [SMALL_STATE(29)] = 942,
  [SMALL_STATE(30)] = 965,
  [SMALL_STATE(31)] = 988,
  [SMALL_STATE(32)] = 1005,
  [SMALL_STATE(33)] = 1022,
  [SMALL_STATE(34)] = 1045,
  [SMALL_STATE(35)] = 1068,
  [SMALL_STATE(36)] = 1091,
  [SMALL_STATE(37)] = 1114,
  [SMALL_STATE(38)] = 1137,
  [SMALL_STATE(39)] = 1160,
  [SMALL_STATE(40)] = 1183,
  [SMALL_STATE(41)] = 1206,
  [SMALL_STATE(42)] = 1231,
  [SMALL_STATE(43)] = 1252,
  [SMALL_STATE(44)] = 1273,
  [SMALL_STATE(45)] = 1296,
  [SMALL_STATE(46)] = 1319,
  [SMALL_STATE(47)] = 1344,
  [SMALL_STATE(48)] = 1367,
  [SMALL_STATE(49)] = 1388,
  [SMALL_STATE(50)] = 1411,
  [SMALL_STATE(51)] = 1428,
  [SMALL_STATE(52)] = 1451,
  [SMALL_STATE(53)] = 1474,
  [SMALL_STATE(54)] = 1496,
  [SMALL_STATE(55)] = 1518,
  [SMALL_STATE(56)] = 1540,
  [SMALL_STATE(57)] = 1562,
  [SMALL_STATE(58)] = 1584,
  [SMALL_STATE(59)] = 1612,
  [SMALL_STATE(60)] = 1640,
  [SMALL_STATE(61)] = 1668,
  [SMALL_STATE(62)] = 1690,
  [SMALL_STATE(63)] = 1718,
  [SMALL_STATE(64)] = 1746,
  [SMALL_STATE(65)] = 1774,
  [SMALL_STATE(66)] = 1790,
  [SMALL_STATE(67)] = 1812,
  [SMALL_STATE(68)] = 1834,
  [SMALL_STATE(69)] = 1862,
  [SMALL_STATE(70)] = 1884,
  [SMALL_STATE(71)] = 1900,
  [SMALL_STATE(72)] = 1922,
  [SMALL_STATE(73)] = 1938,
  [SMALL_STATE(74)] = 1960,
  [SMALL_STATE(75)] = 1976,
  [SMALL_STATE(76)] = 1995,
  [SMALL_STATE(77)] = 2016,
  [SMALL_STATE(78)] = 2031,
  [SMALL_STATE(79)] = 2050,
  [SMALL_STATE(80)] = 2065,
  [SMALL_STATE(81)] = 2084,
  [SMALL_STATE(82)] = 2103,
  [SMALL_STATE(83)] = 2118,
  [SMALL_STATE(84)] = 2137,
  [SMALL_STATE(85)] = 2156,
  [SMALL_STATE(86)] = 2175,
  [SMALL_STATE(87)] = 2194,
  [SMALL_STATE(88)] = 2213,
  [SMALL_STATE(89)] = 2236,
  [SMALL_STATE(90)] = 2255,
  [SMALL_STATE(91)] = 2274,
  [SMALL_STATE(92)] = 2293,
  [SMALL_STATE(93)] = 2312,
  [SMALL_STATE(94)] = 2331,
  [SMALL_STATE(95)] = 2350,
  [SMALL_STATE(96)] = 2368,
  [SMALL_STATE(97)] = 2382,
  [SMALL_STATE(98)] = 2400,
  [SMALL_STATE(99)] = 2418,
  [SMALL_STATE(100)] = 2436,
  [SMALL_STATE(101)] = 2450,
  [SMALL_STATE(102)] = 2468,
  [SMALL_STATE(103)] = 2486,
  [SMALL_STATE(104)] = 2504,
  [SMALL_STATE(105)] = 2518,
  [SMALL_STATE(106)] = 2532,
  [SMALL_STATE(107)] = 2550,
  [SMALL_STATE(108)] = 2566,
  [SMALL_STATE(109)] = 2584,
  [SMALL_STATE(110)] = 2598,
  [SMALL_STATE(111)] = 2616,
  [SMALL_STATE(112)] = 2634,
  [SMALL_STATE(113)] = 2652,
  [SMALL_STATE(114)] = 2674,
  [SMALL_STATE(115)] = 2692,
  [SMALL_STATE(116)] = 2710,
  [SMALL_STATE(117)] = 2732,
  [SMALL_STATE(118)] = 2746,
  [SMALL_STATE(119)] = 2768,
  [SMALL_STATE(120)] = 2784,
  [SMALL_STATE(121)] = 2802,
  [SMALL_STATE(122)] = 2816,
  [SMALL_STATE(123)] = 2830,
  [SMALL_STATE(124)] = 2846,
  [SMALL_STATE(125)] = 2862,
  [SMALL_STATE(126)] = 2876,
  [SMALL_STATE(127)] = 2894,
  [SMALL_STATE(128)] = 2907,
  [SMALL_STATE(129)] = 2922,
  [SMALL_STATE(130)] = 2937,
  [SMALL_STATE(131)] = 2950,
  [SMALL_STATE(132)] = 2967,
  [SMALL_STATE(133)] = 2984,
  [SMALL_STATE(134)] = 2997,
  [SMALL_STATE(135)] = 3012,
  [SMALL_STATE(136)] = 3029,
  [SMALL_STATE(137)] = 3040,
  [SMALL_STATE(138)] = 3051,
  [SMALL_STATE(139)] = 3064,
  [SMALL_STATE(140)] = 3079,
  [SMALL_STATE(141)] = 3094,
  [SMALL_STATE(142)] = 3105,
  [SMALL_STATE(143)] = 3120,
  [SMALL_STATE(144)] = 3137,
  [SMALL_STATE(145)] = 3152,
  [SMALL_STATE(146)] = 3167,
  [SMALL_STATE(147)] = 3180,
  [SMALL_STATE(148)] = 3193,
  [SMALL_STATE(149)] = 3210,
  [SMALL_STATE(150)] = 3223,
  [SMALL_STATE(151)] = 3236,
  [SMALL_STATE(152)] = 3251,
  [SMALL_STATE(153)] = 3266,
  [SMALL_STATE(154)] = 3281,
  [SMALL_STATE(155)] = 3296,
  [SMALL_STATE(156)] = 3311,
  [SMALL_STATE(157)] = 3326,
  [SMALL_STATE(158)] = 3343,
  [SMALL_STATE(159)] = 3360,
  [SMALL_STATE(160)] = 3373,
  [SMALL_STATE(161)] = 3386,
  [SMALL_STATE(162)] = 3403,
  [SMALL_STATE(163)] = 3413,
  [SMALL_STATE(164)] = 3423,
  [SMALL_STATE(165)] = 3437,
  [SMALL_STATE(166)] = 3451,
  [SMALL_STATE(167)] = 3465,
  [SMALL_STATE(168)] = 3479,
  [SMALL_STATE(169)] = 3493,
  [SMALL_STATE(170)] = 3507,
  [SMALL_STATE(171)] = 3521,
  [SMALL_STATE(172)] = 3535,
  [SMALL_STATE(173)] = 3549,
  [SMALL_STATE(174)] = 3561,
  [SMALL_STATE(175)] = 3575,
  [SMALL_STATE(176)] = 3589,
  [SMALL_STATE(177)] = 3603,
  [SMALL_STATE(178)] = 3617,
  [SMALL_STATE(179)] = 3631,
  [SMALL_STATE(180)] = 3645,
  [SMALL_STATE(181)] = 3659,
  [SMALL_STATE(182)] = 3673,
  [SMALL_STATE(183)] = 3687,
  [SMALL_STATE(184)] = 3701,
  [SMALL_STATE(185)] = 3715,
  [SMALL_STATE(186)] = 3729,
  [SMALL_STATE(187)] = 3743,
  [SMALL_STATE(188)] = 3757,
  [SMALL_STATE(189)] = 3771,
  [SMALL_STATE(190)] = 3785,
  [SMALL_STATE(191)] = 3799,
  [SMALL_STATE(192)] = 3813,
  [SMALL_STATE(193)] = 3827,
  [SMALL_STATE(194)] = 3841,
  [SMALL_STATE(195)] = 3851,
  [SMALL_STATE(196)] = 3863,
  [SMALL_STATE(197)] = 3877,
  [SMALL_STATE(198)] = 3887,
  [SMALL_STATE(199)] = 3899,
  [SMALL_STATE(200)] = 3913,
  [SMALL_STATE(201)] = 3923,
  [SMALL_STATE(202)] = 3937,
  [SMALL_STATE(203)] = 3947,
  [SMALL_STATE(204)] = 3961,
  [SMALL_STATE(205)] = 3975,
  [SMALL_STATE(206)] = 3985,
  [SMALL_STATE(207)] = 3997,
  [SMALL_STATE(208)] = 4009,
  [SMALL_STATE(209)] = 4021,
  [SMALL_STATE(210)] = 4035,
  [SMALL_STATE(211)] = 4049,
  [SMALL_STATE(212)] = 4061,
  [SMALL_STATE(213)] = 4073,
  [SMALL_STATE(214)] = 4087,
  [SMALL_STATE(215)] = 4099,
  [SMALL_STATE(216)] = 4111,
  [SMALL_STATE(217)] = 4125,
  [SMALL_STATE(218)] = 4137,
  [SMALL_STATE(219)] = 4148,
  [SMALL_STATE(220)] = 4159,
  [SMALL_STATE(221)] = 4170,
  [SMALL_STATE(222)] = 4181,
  [SMALL_STATE(223)] = 4194,
  [SMALL_STATE(224)] = 4205,
  [SMALL_STATE(225)] = 4216,
  [SMALL_STATE(226)] = 4225,
  [SMALL_STATE(227)] = 4236,
  [SMALL_STATE(228)] = 4247,
  [SMALL_STATE(229)] = 4256,
  [SMALL_STATE(230)] = 4267,
  [SMALL_STATE(231)] = 4276,
  [SMALL_STATE(232)] = 4285,
  [SMALL_STATE(233)] = 4294,
  [SMALL_STATE(234)] = 4303,
  [SMALL_STATE(235)] = 4312,
  [SMALL_STATE(236)] = 4321,
  [SMALL_STATE(237)] = 4332,
  [SMALL_STATE(238)] = 4343,
  [SMALL_STATE(239)] = 4356,
  [SMALL_STATE(240)] = 4367,
  [SMALL_STATE(241)] = 4376,
  [SMALL_STATE(242)] = 4387,
  [SMALL_STATE(243)] = 4398,
  [SMALL_STATE(244)] = 4409,
  [SMALL_STATE(245)] = 4418,
  [SMALL_STATE(246)] = 4431,
  [SMALL_STATE(247)] = 4442,
  [SMALL_STATE(248)] = 4453,
  [SMALL_STATE(249)] = 4463,
  [SMALL_STATE(250)] = 4471,
  [SMALL_STATE(251)] = 4479,
  [SMALL_STATE(252)] = 4487,
  [SMALL_STATE(253)] = 4495,
  [SMALL_STATE(254)] = 4503,
  [SMALL_STATE(255)] = 4511,
  [SMALL_STATE(256)] = 4521,
  [SMALL_STATE(257)] = 4529,
  [SMALL_STATE(258)] = 4537,
  [SMALL_STATE(259)] = 4545,
  [SMALL_STATE(260)] = 4553,
  [SMALL_STATE(261)] = 4561,
  [SMALL_STATE(262)] = 4569,
  [SMALL_STATE(263)] = 4577,
  [SMALL_STATE(264)] = 4585,
  [SMALL_STATE(265)] = 4593,
  [SMALL_STATE(266)] = 4601,
  [SMALL_STATE(267)] = 4609,
  [SMALL_STATE(268)] = 4617,
  [SMALL_STATE(269)] = 4625,
  [SMALL_STATE(270)] = 4633,
  [SMALL_STATE(271)] = 4641,
  [SMALL_STATE(272)] = 4651,
  [SMALL_STATE(273)] = 4659,
  [SMALL_STATE(274)] = 4667,
  [SMALL_STATE(275)] = 4675,
  [SMALL_STATE(276)] = 4683,
  [SMALL_STATE(277)] = 4691,
  [SMALL_STATE(278)] = 4699,
  [SMALL_STATE(279)] = 4709,
  [SMALL_STATE(280)] = 4717,
  [SMALL_STATE(281)] = 4725,
  [SMALL_STATE(282)] = 4733,
  [SMALL_STATE(283)] = 4743,
  [SMALL_STATE(284)] = 4751,
  [SMALL_STATE(285)] = 4759,
  [SMALL_STATE(286)] = 4767,
  [SMALL_STATE(287)] = 4775,
  [SMALL_STATE(288)] = 4783,
  [SMALL_STATE(289)] = 4791,
  [SMALL_STATE(290)] = 4799,
  [SMALL_STATE(291)] = 4807,
  [SMALL_STATE(292)] = 4815,
  [SMALL_STATE(293)] = 4823,
  [SMALL_STATE(294)] = 4831,
  [SMALL_STATE(295)] = 4839,
  [SMALL_STATE(296)] = 4847,
  [SMALL_STATE(297)] = 4855,
  [SMALL_STATE(298)] = 4863,
  [SMALL_STATE(299)] = 4871,
  [SMALL_STATE(300)] = 4879,
  [SMALL_STATE(301)] = 4887,
  [SMALL_STATE(302)] = 4895,
  [SMALL_STATE(303)] = 4903,
  [SMALL_STATE(304)] = 4911,
  [SMALL_STATE(305)] = 4919,
  [SMALL_STATE(306)] = 4927,
  [SMALL_STATE(307)] = 4935,
  [SMALL_STATE(308)] = 4943,
  [SMALL_STATE(309)] = 4951,
  [SMALL_STATE(310)] = 4959,
  [SMALL_STATE(311)] = 4967,
  [SMALL_STATE(312)] = 4975,
  [SMALL_STATE(313)] = 4983,
  [SMALL_STATE(314)] = 4991,
  [SMALL_STATE(315)] = 4999,
  [SMALL_STATE(316)] = 5007,
  [SMALL_STATE(317)] = 5015,
  [SMALL_STATE(318)] = 5023,
  [SMALL_STATE(319)] = 5031,
  [SMALL_STATE(320)] = 5039,
  [SMALL_STATE(321)] = 5047,
  [SMALL_STATE(322)] = 5055,
  [SMALL_STATE(323)] = 5063,
  [SMALL_STATE(324)] = 5071,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(275),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(68),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(123),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(102),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(157),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(118),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(280),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(148),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(76),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(236),
  [102] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(275),
  [105] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(274),
  [108] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_env_pair, 2, 0, 1),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_env_pair, 2, 0, 1),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [134] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_run_instruction_repeat1, 2, 0, 0),
  [138] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_run_instruction_repeat1, 2, 0, 0), SHIFT_REPEAT(218),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_run_instruction_repeat1, 2, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(323),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [153] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquoted_string, 1, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquoted_string, 1, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_unquoted_string_repeat1, 2, 0, 0),
  [169] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_unquoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(167),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 2, 0, 0),
  [174] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_mount_param, 4, 0, 13),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mount_param, 4, 0, 13),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_name, 2, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_name, 2, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [189] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_mount_param, 5, 0, 15),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mount_param, 5, 0, 15),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_fragment_repeat1, 2, 0, 0),
  [197] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_shell_fragment_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_shell_fragment_repeat1, 2, 0, 0),
  [202] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_shell_fragment_repeat1, 2, 0, 0), SHIFT_REPEAT(260),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_name, 1, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_name, 1, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_fragment, 1, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_shell_fragment, 1, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_name_repeat1, 2, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_name_repeat1, 2, 0, 0),
  [221] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_image_name_repeat1, 2, 0, 0), SHIFT_REPEAT(216),
  [224] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_name_repeat1, 2, 0, 0), SHIFT_REPEAT(27),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_mount_param_repeat1, 2, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_mount_param_repeat1, 2, 0, 0),
  [231] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_mount_param_repeat1, 2, 0, 0), SHIFT_REPEAT(238),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [236] = {.entry = {.count = 1, .reusable = false}}, SHIFT(226),
  [238] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [242] = {.entry = {.count = 1, .reusable = false}}, SHIFT(159),
  [244] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_unquoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(166),
  [247] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_unquoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_tag, 2, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_tag, 2, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [258] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_path_with_heredoc, 1, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path_with_heredoc, 1, 0, 0),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_tag_repeat1, 2, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_tag_repeat1, 2, 0, 0),
  [272] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_image_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(172),
  [275] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_image_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [278] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [280] = {.entry = {.count = 1, .reusable = false}}, SHIFT(269),
  [282] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2, 0, 0),
  [288] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [291] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2, 0, 0), SHIFT_REPEAT(165),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2, 0, 0),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_instruction, 2, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = false}}, SHIFT(257),
  [300] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [302] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__user_name_or_group, 2, 0, 0),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__user_name_or_group_repeat1, 2, 0, 0),
  [312] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__user_name_or_group_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [315] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__user_name_or_group_repeat1, 2, 0, 0), SHIFT_REPEAT(180),
  [318] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_path_with_heredoc, 2, 0, 0),
  [320] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path_with_heredoc, 2, 0, 0),
  [324] = {.entry = {.count = 1, .reusable = false}}, SHIFT(289),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_label_instruction_repeat1, 2, 0, 0),
  [328] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_label_instruction_repeat1, 2, 0, 0), SHIFT_REPEAT(257),
  [331] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_label_instruction_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [334] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_label_instruction_repeat1, 2, 0, 0), SHIFT_REPEAT(120),
  [337] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(199),
  [340] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0),
  [342] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [345] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__user_name_or_group, 1, 0, 0),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [352] = {.entry = {.count = 1, .reusable = false}}, SHIFT(223),
  [354] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [358] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_mount_param_param, 3, 0, 0),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mount_param_param, 3, 0, 0),
  [362] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_shell_fragment_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [365] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_shell_fragment_repeat1, 2, 0, 0), SHIFT_REPEAT(261),
  [368] = {.entry = {.count = 1, .reusable = false}}, SHIFT(138),
  [370] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_digest_repeat1, 2, 0, 0),
  [376] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_image_digest_repeat1, 2, 0, 0),
  [378] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_image_digest_repeat1, 2, 0, 0), SHIFT_REPEAT(170),
  [381] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_image_digest_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [384] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_path, 1, 0, 0),
  [386] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 1, 0, 0),
  [392] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_add_instruction_repeat1, 2, 0, 0),
  [394] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_instruction_repeat1, 2, 0, 0),
  [396] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_instruction_repeat1, 2, 0, 0), SHIFT_REPEAT(323),
  [399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__immediate_user_name_or_group, 2, 0, 0),
  [401] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__immediate_user_name_or_group, 2, 0, 0), SHIFT_REPEAT(202),
  [404] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__immediate_user_name_or_group, 2, 0, 0), SHIFT_REPEAT(180),
  [407] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [415] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_add_instruction_repeat2, 2, 0, 0), SHIFT_REPEAT(86),
  [418] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_instruction_repeat2, 2, 0, 0), SHIFT_REPEAT(86),
  [421] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_instruction_repeat2, 2, 0, 0), SHIFT_REPEAT(185),
  [424] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_instruction_repeat2, 2, 0, 0), SHIFT_REPEAT(254),
  [427] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_path, 2, 0, 0),
  [429] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [431] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 2, 0, 0),
  [433] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [439] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__imm_expansion, 2, 0, 0),
  [441] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__imm_expansion, 2, 0, 0),
  [443] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_instruction, 4, 0, 11),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [451] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [455] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [458] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2, 0, 0), SHIFT_REPEAT(184),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expansion_body, 3, 0, 0),
  [469] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expansion_body, 3, 0, 0),
  [471] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_digest, 2, 0, 0),
  [473] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_digest, 2, 0, 0),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [479] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_param, 4, 0, 13),
  [481] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param, 4, 0, 13),
  [483] = {.entry = {.count = 1, .reusable = true}}, SHIFT(284),
  [485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(324),
  [487] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expansion, 2, 0, 0),
  [489] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expansion, 2, 0, 0),
  [491] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_alias, 1, 0, 0),
  [493] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [497] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [501] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_alias, 2, 0, 0),
  [503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [505] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stopsignal_value_repeat1, 2, 0, 0),
  [507] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__stopsignal_value_repeat1, 2, 0, 0), SHIFT_REPEAT(83),
  [510] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__stopsignal_value_repeat1, 2, 0, 0), SHIFT_REPEAT(175),
  [513] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__stopsignal_value, 2, 0, 0),
  [515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [519] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expose_instruction, 2, 0, 0),
  [521] = {.entry = {.count = 1, .reusable = false}}, SHIFT(192),
  [523] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [525] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [529] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [531] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 1, 0, 1),
  [533] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 1, 0, 1),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [539] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [541] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expose_instruction_repeat1, 2, 0, 0),
  [543] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_expose_instruction_repeat1, 2, 0, 0), SHIFT_REPEAT(192),
  [546] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_expose_instruction_repeat1, 2, 0, 0), SHIFT_REPEAT(119),
  [549] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [552] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2, 0, 0), SHIFT_REPEAT(187),
  [555] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__stopsignal_value, 1, 0, 0),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [559] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_path_repeat1, 2, 0, 0), SHIFT_REPEAT(93),
  [562] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2, 0, 0), SHIFT_REPEAT(177),
  [565] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_image_alias_repeat1, 2, 0, 0),
  [567] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_image_alias_repeat1, 2, 0, 0), SHIFT_REPEAT(164),
  [570] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_image_alias_repeat1, 2, 0, 0), SHIFT_REPEAT(94),
  [573] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [575] = {.entry = {.count = 1, .reusable = false}}, SHIFT(295),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [579] = {.entry = {.count = 1, .reusable = false}}, SHIFT(227),
  [581] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [583] = {.entry = {.count = 1, .reusable = false}}, SHIFT(224),
  [585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [587] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [591] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [593] = {.entry = {.count = 1, .reusable = false}}, SHIFT(147),
  [595] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [597] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_env_instruction_repeat1, 2, 0, 0),
  [599] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_env_instruction_repeat1, 2, 0, 0), SHIFT_REPEAT(265),
  [602] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_instruction, 4, 0, 0),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [608] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [611] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0),
  [613] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [616] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_instruction, 3, 0, 0),
  [618] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_copy_instruction, 4, 0, 0),
  [620] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_copy_instruction, 3, 0, 0),
  [622] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_env_instruction, 2, 0, 0),
  [624] = {.entry = {.count = 1, .reusable = false}}, SHIFT(265),
  [626] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [628] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [630] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [632] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expose_port, 1, 0, 0),
  [634] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expose_port, 1, 0, 0),
  [636] = {.entry = {.count = 1, .reusable = false}}, SHIFT(206),
  [638] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [640] = {.entry = {.count = 1, .reusable = false}}, SHIFT(266),
  [642] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [644] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [646] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [650] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [652] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_run_instruction, 2, 0, 0),
  [654] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_command, 1, 0, 0),
  [656] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [658] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [660] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [662] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_add_instruction_repeat2, 2, 0, 0),
  [664] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_instruction_repeat2, 2, 0, 0),
  [666] = {.entry = {.count = 1, .reusable = false}}, SHIFT(228),
  [668] = {.entry = {.count = 1, .reusable = false}}, SHIFT(143),
  [670] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [672] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 2, 0, 0),
  [674] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 2, 0, 0),
  [676] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_copy_instruction, 5, 0, 0),
  [678] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_instruction, 5, 0, 0),
  [680] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_run_instruction_repeat2, 2, 0, 0),
  [682] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_run_instruction_repeat2, 2, 0, 0), SHIFT_REPEAT(209),
  [685] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_json_string_repeat1, 2, 0, 0),
  [687] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_json_string_repeat1, 2, 0, 0), SHIFT_REPEAT(143),
  [690] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_string_repeat1, 2, 0, 0), SHIFT_REPEAT(143),
  [693] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_shell_command_repeat1, 2, 0, 0),
  [695] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_shell_command_repeat1, 2, 0, 0), SHIFT_REPEAT(67),
  [698] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_run_instruction, 4, 0, 0),
  [700] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_pair, 3, 0, 9),
  [702] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label_pair, 3, 0, 9),
  [704] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_quoted_string, 2, 0, 0),
  [706] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_quoted_string, 2, 0, 0),
  [708] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [710] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [712] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_run_instruction, 3, 0, 0),
  [714] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_command, 2, 0, 0),
  [716] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_instruction, 4, 0, 0),
  [718] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_copy_instruction, 4, 0, 0),
  [720] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_instruction_repeat1, 2, 0, 0), SHIFT_REPEAT(324),
  [723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [727] = {.entry = {.count = 1, .reusable = false}}, SHIFT(244),
  [729] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [731] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [733] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 3, 0, 0),
  [735] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 3, 0, 0),
  [737] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_quoted_string, 3, 0, 0),
  [739] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_quoted_string, 3, 0, 0),
  [741] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 2, 0, 5),
  [743] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 2, 0, 5),
  [745] = {.entry = {.count = 1, .reusable = true}}, SHIFT(318),
  [747] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [749] = {.entry = {.count = 1, .reusable = true}}, SHIFT(317),
  [751] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [753] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [755] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [757] = {.entry = {.count = 1, .reusable = true}}, SHIFT(321),
  [759] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [761] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_volume_instruction_repeat1, 2, 0, 0),
  [763] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_volume_instruction_repeat1, 2, 0, 0), SHIFT_REPEAT(116),
  [766] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [768] = {.entry = {.count = 1, .reusable = true}}, SHIFT(320),
  [770] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [772] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [774] = {.entry = {.count = 1, .reusable = true}}, SHIFT(319),
  [776] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [778] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_shell_command_repeat1, 2, 0, 0),
  [780] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [782] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [784] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [786] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [788] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [790] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [792] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_string_array_repeat1, 2, 0, 0), SHIFT_REPEAT(241),
  [795] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_string_array_repeat1, 2, 0, 0),
  [797] = {.entry = {.count = 1, .reusable = true}}, SHIFT(313),
  [799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [801] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [803] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_heredoc_block_repeat1, 2, 0, 0), SHIFT_REPEAT(272),
  [806] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_heredoc_block_repeat1, 2, 0, 0),
  [808] = {.entry = {.count = 1, .reusable = true}}, SHIFT(311),
  [810] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [812] = {.entry = {.count = 1, .reusable = true}}, SHIFT(272),
  [814] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [816] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [818] = {.entry = {.count = 1, .reusable = true}}, SHIFT(309),
  [820] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [822] = {.entry = {.count = 1, .reusable = true}}, SHIFT(241),
  [824] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [826] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [828] = {.entry = {.count = 1, .reusable = true}}, SHIFT(302),
  [830] = {.entry = {.count = 1, .reusable = true}}, SHIFT(298),
  [832] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [834] = {.entry = {.count = 1, .reusable = true}}, SHIFT(270),
  [836] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [838] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [840] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [842] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [844] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [846] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [848] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [850] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [852] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_volume_instruction, 2, 0, 0),
  [854] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [856] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__immediate_user_name_or_group, 1, 0, 0),
  [858] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_volume_instruction, 3, 0, 0),
  [860] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expose_port, 2, 0, 0),
  [862] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expose_port, 2, 0, 0),
  [864] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [866] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [868] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_shell_command_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [871] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [873] = {.entry = {.count = 1, .reusable = false}}, SHIFT(308),
  [875] = {.entry = {.count = 1, .reusable = false}}, SHIFT(300),
  [877] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_env_pair, 3, 0, 10),
  [879] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_env_pair, 3, 0, 10),
  [881] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_volume_instruction_repeat1, 2, 0, 0),
  [883] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 3, 0, 0),
  [885] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [887] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_string_array, 2, 0, 0),
  [889] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_string, 3, 0, 0),
  [891] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_string_array, 4, 0, 0),
  [893] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heredoc_block, 3, 0, 0),
  [895] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heredoc_block, 2, 0, 0),
  [897] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_instruction, 2, 0, 4),
  [899] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [901] = {.entry = {.count = 1, .reusable = false}}, SHIFT(292),
  [903] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 2, 0, 6),
  [905] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 2, 0, 6),
  [907] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_string_array, 3, 0, 0),
  [909] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 2, 0, 0),
  [911] = {.entry = {.count = 1, .reusable = false}}, SHIFT(131),
  [913] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_instruction, 2, 0, 3),
  [915] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [917] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_string, 2, 0, 0),
  [919] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_image_spec, 3, 0, 8),
  [921] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_image_spec, 3, 0, 8),
  [923] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [925] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [927] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [929] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_maintainer_instruction, 2, 0, 0),
  [931] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entrypoint_instruction, 2, 0, 0),
  [933] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [935] = {.entry = {.count = 1, .reusable = false}}, SHIFT(222),
  [937] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_env_instruction, 2, 0, 2),
  [939] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [941] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cmd_instruction, 2, 0, 0),
  [943] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 4, 0, 7),
  [945] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [947] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [949] = {.entry = {.count = 1, .reusable = true}}, SHIFT(255),
  [951] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_healthcheck_instruction, 3, 0, 0),
  [953] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [955] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [957] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [959] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [961] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [963] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [965] = {.entry = {.count = 1, .reusable = false}}, SHIFT(290),
  [967] = {.entry = {.count = 1, .reusable = false}}, SHIFT(249),
  [969] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_workdir_instruction, 2, 0, 0),
  [971] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [973] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [975] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_onbuild_instruction, 2, 0, 0),
  [977] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [979] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [981] = {.entry = {.count = 1, .reusable = false}}, SHIFT(235),
  [983] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stopsignal_instruction, 2, 0, 0),
  [985] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_healthcheck_instruction, 2, 0, 0),
  [987] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [989] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shell_instruction, 2, 0, 0),
  [991] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_volume_instruction, 2, 0, 0),
  [993] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [995] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cross_build_instruction, 2, 0, 0),
  [997] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [999] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [1001] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_from_instruction, 5, 0, 14),
  [1003] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [1005] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__spaced_env_pair, 3, 0, 10),
  [1007] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [1009] = {.entry = {.count = 1, .reusable = false}}, SHIFT(252),
  [1011] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [1013] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [1015] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [1017] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [1019] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_instruction, 4, 0, 12),
  [1021] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [1023] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [1025] = {.entry = {.count = 1, .reusable = false}}, SHIFT(268),
  [1027] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [1029] = {.entry = {.count = 1, .reusable = false}}, SHIFT(277),
  [1031] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [1033] = {.entry = {.count = 1, .reusable = false}}, SHIFT(281),
  [1035] = {.entry = {.count = 1, .reusable = true}}, SHIFT(282),
  [1037] = {.entry = {.count = 1, .reusable = false}}, SHIFT(285),
  [1039] = {.entry = {.count = 1, .reusable = false}}, SHIFT(288),
  [1041] = {.entry = {.count = 1, .reusable = false}}, SHIFT(291),
  [1043] = {.entry = {.count = 1, .reusable = false}}, SHIFT(294),
  [1045] = {.entry = {.count = 1, .reusable = false}}, SHIFT(297),
  [1047] = {.entry = {.count = 1, .reusable = false}}, SHIFT(299),
  [1049] = {.entry = {.count = 1, .reusable = false}}, SHIFT(301),
  [1051] = {.entry = {.count = 1, .reusable = false}}, SHIFT(303),
  [1053] = {.entry = {.count = 1, .reusable = false}}, SHIFT(305),
  [1055] = {.entry = {.count = 1, .reusable = false}}, SHIFT(306),
  [1057] = {.entry = {.count = 1, .reusable = true}}, SHIFT(310),
  [1059] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_heredoc_marker = 0,
  ts_external_token_heredoc_line = 1,
  ts_external_token_heredoc_end = 2,
  ts_external_token_heredoc_nl = 3,
  ts_external_token_error_sentinel = 4,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_heredoc_marker] = sym_heredoc_marker,
  [ts_external_token_heredoc_line] = sym_heredoc_line,
  [ts_external_token_heredoc_end] = sym_heredoc_end,
  [ts_external_token_heredoc_nl] = sym_heredoc_nl,
  [ts_external_token_error_sentinel] = sym_error_sentinel,
};

static const bool ts_external_scanner_states[6][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_heredoc_marker] = true,
    [ts_external_token_heredoc_line] = true,
    [ts_external_token_heredoc_end] = true,
    [ts_external_token_heredoc_nl] = true,
    [ts_external_token_error_sentinel] = true,
  },
  [2] = {
    [ts_external_token_heredoc_marker] = true,
  },
  [3] = {
    [ts_external_token_heredoc_marker] = true,
    [ts_external_token_heredoc_nl] = true,
  },
  [4] = {
    [ts_external_token_heredoc_nl] = true,
  },
  [5] = {
    [ts_external_token_heredoc_line] = true,
    [ts_external_token_heredoc_end] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_dockerfile_external_scanner_create(void);
void tree_sitter_dockerfile_external_scanner_destroy(void *);
bool tree_sitter_dockerfile_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_dockerfile_external_scanner_serialize(void *, char *);
void tree_sitter_dockerfile_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_dockerfile(void) {
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
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_dockerfile_external_scanner_create,
      tree_sitter_dockerfile_external_scanner_destroy,
      tree_sitter_dockerfile_external_scanner_scan,
      tree_sitter_dockerfile_external_scanner_serialize,
      tree_sitter_dockerfile_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
