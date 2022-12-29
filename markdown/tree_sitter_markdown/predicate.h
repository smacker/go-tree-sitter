#ifndef TREE_SITTER_MARKDOWN_PREDICATE_H_
#define TREE_SITTER_MARKDOWN_PREDICATE_H_

#include "./shared_type.h"

namespace tree_sitter_markdown {

bool is_wsp_chr(const LexedCharacter character);
bool is_lbk_chr(const LexedCharacter character);
bool is_eof_chr(const LexedCharacter character);
bool is_eol_chr(const LexedCharacter character);
bool is_wht_chr(const LexedCharacter character);
bool is_non_wht_chr(const LexedCharacter character);
bool is_num_chr(const LexedCharacter character);
bool is_hex_chr(const LexedCharacter character);
bool is_asc_ltr_chr(const LexedCharacter character);
bool is_low_asc_ltr_chr(const LexedCharacter character);
bool is_upp_asc_ltr_chr(const LexedCharacter character);
bool is_asc_pun_chr(const LexedCharacter character);
bool is_uni_pun_chr(const LexedCharacter character);
bool is_asc_wht_chr(const LexedCharacter character);
bool is_uni_wht_chr(const LexedCharacter character);
bool is_lfk_dlm_run(const LexedCharacter left_character, const LexedCharacter right_character);
bool is_rfk_dlm_run(const LexedCharacter left_character, const LexedCharacter right_character);
bool can_opn_asr(const LexedCharacter left_character, const LexedCharacter right_character);
bool can_cls_asr(const LexedCharacter left_character, const LexedCharacter right_character);
bool can_opn_usc(const LexedCharacter left_character, const LexedCharacter right_character);
bool can_cls_usc(const LexedCharacter left_character, const LexedCharacter right_character);

bool is_aut_lnk_eml_dmn_sid_chr(const LexedCharacter character);
bool is_aut_lnk_eml_dmn_mid_chr(const LexedCharacter character);

bool is_ext_aut_lnk_bgn(const LexedCharacter current_character, const LexedCharacter lookahead_character);

}

#endif // TREE_SITTER_MARKDOWN_PREDICATE_H_
