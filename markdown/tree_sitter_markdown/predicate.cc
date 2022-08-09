#include "./predicate.h"

#include "./predicate_util.generated.h"

namespace tree_sitter_markdown {

bool is_wsp_chr(const LexedCharacter c) { return c == ' ' || c == '\t'; }
bool is_lbk_chr(const LexedCharacter c) { return c == '\n' || c == '\r'; }
bool is_eof_chr(const LexedCharacter c) { return c == 0; }
bool is_eol_chr(const LexedCharacter c) { return is_lbk_chr(c) || is_eof_chr(c); }
bool is_wht_chr(const LexedCharacter c) { return is_wsp_chr(c) || is_eol_chr(c); }
bool is_non_wht_chr(const LexedCharacter c) { return !is_wht_chr(c); }
bool is_num_chr(const LexedCharacter c) { return c >= '0' && c <= '9'; }
bool is_hex_chr(const LexedCharacter c) { return is_num_chr(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'); }
bool is_asc_ltr_chr(const LexedCharacter c) { return is_low_asc_ltr_chr(c) || is_upp_asc_ltr_chr(c); }
bool is_low_asc_ltr_chr(const LexedCharacter c) { return c >= 'a' && c <= 'z'; }
bool is_upp_asc_ltr_chr(const LexedCharacter c) { return c >= 'A' && c <= 'Z'; }
bool is_asc_pun_chr(const LexedCharacter c) {
  return c == '!' || c == '"' || c == '#' || c == '$' || c == '%' || c == '&'
      || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ','
      || c == '-' || c == '.' || c == '/' || c == ':' || c == ';' || c == '<'
      || c == '=' || c == '>' || c == '?' || c == '@' || c == '[' || c == '\\'
      || c == ']' || c == '^' || c == '_' || c == '`' || c == '{' || c == '|'
      || c == '}' || c == '~';
}
bool is_uni_pun_chr(const LexedCharacter c) {
  return is_asc_pun_chr(c) || is_unicode_Pc_Pd_Pe_Pf_Pi_Po_Ps(c);
}
bool is_asc_wht_chr(const LexedCharacter c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
}
bool is_uni_wht_chr(const LexedCharacter c) {
  return is_unicode_Zs(c) || c == '\t' || c == '\r' || c == '\n' || c == '\f';
}
bool is_lfk_dlm_run(const LexedCharacter left, const LexedCharacter right) {
  return is_uni_pun_chr(right)
    ? (left == 0 || is_uni_wht_chr(left)) || is_uni_pun_chr(left)
    : !(right == 0 || is_uni_wht_chr(right));
}
bool is_rfk_dlm_run(const LexedCharacter left, const LexedCharacter right) {
  return is_uni_pun_chr(left)
    ? (right == 0 || is_uni_wht_chr(right)) || is_uni_pun_chr(right)
    : !(left == 0 || is_uni_wht_chr(left));
}
bool can_opn_asr(const LexedCharacter left, const LexedCharacter right) {
  return is_lfk_dlm_run(left, right);
}
bool can_cls_asr(const LexedCharacter left, const LexedCharacter right) {
  return is_rfk_dlm_run(left, right);
}
bool can_opn_usc(const LexedCharacter left, const LexedCharacter right) {
  return is_lfk_dlm_run(left, right)
      && (!is_rfk_dlm_run(left, right) || is_uni_pun_chr(left));
}
bool can_cls_usc(const LexedCharacter left, const LexedCharacter right) {
  return is_rfk_dlm_run(left, right)
      && (!is_lfk_dlm_run(left, right) || is_uni_pun_chr(right));
}

bool is_aut_lnk_eml_dmn_sid_chr(const LexedCharacter c) {
  return is_asc_ltr_chr(c) || is_num_chr(c);
}
bool is_aut_lnk_eml_dmn_mid_chr(const LexedCharacter c) {
  return is_aut_lnk_eml_dmn_sid_chr(c) || c == '-';
}

bool is_ext_aut_lnk_bgn(const LexedCharacter cur_chr, const LexedCharacter lka_chr) {
  return (is_wht_chr(cur_chr) || cur_chr == '*' || cur_chr == '_' || cur_chr == '-' || cur_chr == '(')
      && (is_asc_ltr_chr(lka_chr) || is_num_chr(lka_chr) || lka_chr == '.' || lka_chr == '-' || lka_chr == '_' || lka_chr == '+');
}

}
