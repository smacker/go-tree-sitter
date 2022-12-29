#ifndef TREE_SITTER_MARKDOWN_TRACED_LEXER_H_
#define TREE_SITTER_MARKDOWN_TRACED_LEXER_H_

#include "parser.h"
#include <vector>
#include "./shared_type.h"
#include "./token_type.h"

namespace tree_sitter_markdown {

struct Lexer {
private:
  TSLexer *lxr_;
  LexedIndex cur_idx_;
  LexedRow cur_row_;
  LexedColumn cur_col_;
  LexedColumn bgn_col_;
  LexedColumn end_col_;
  LexedCharacter bgn_chr_;
  LexedCharacter cur_chr_;
  LexedCharacter lka_chr_;
  LexedCharacter end_chr_;
  LexedIndex buf_bgn_idx_;
  std::vector<LexedCharacter> chr_buf_;
  LexedLength cur_spc_;
  LexedColumn cur_ind_;
  typedef std::vector<uint8_t> IndentCharColumnBuffer;
  IndentCharColumnBuffer ind_chr_col_buf_;
  bool is_rec_tbl_col_cnt_;
  bool tbl_col_is_bgn_;
  bool tbl_col_has_bgn_pip_;
  bool tbl_col_has_ctn_;
  uint16_t tbl_col_pip_cnt_;
public:
  LexedIndex cur_idx() const;
  LexedRow cur_row() const;
  LexedColumn cur_col() const;
  LexedPosition cur_pos() const;
  LexedPosition cur_pos(const LexedIndex offset_index) const;
  LexedCharacter cur_chr() const;
  LexedCharacter lka_chr() const;
  LexedLength cur_spc() const;
  LexedColumn cur_ind() const;

  void clear();
  void init(TSLexer *lexer);
  void mrk_end();

  unsigned serialize(unsigned char *buffer);
  unsigned deserialize(const unsigned char *buffer);

  void adv(const bool skip = false);
  void adv_len(const LexedLength length, const bool skip = false);
  bool adv_if(const LexedCharacter character, const bool skip = false);
  bool adv_if(bool (*is_character)(LexedCharacter), const bool skip = false);
  bool adv_til(const LexedCharacter character, const bool skip = false);
  bool adv_til(bool (*is_character)(LexedCharacter), const bool skip = false);
  bool adv_rpt(const LexedCharacter character, const bool skip = false);
  bool adv_rpt(bool (*is_character)(LexedCharacter), const bool skip = false);
  LexedLength adv_rpt_len(const LexedCharacter character, const LexedLength max_length = LEXED_LENGTH_MAX, const bool skip = false);
  LexedLength adv_rpt_len(bool (*is_character)(LexedCharacter), const LexedLength max_length = LEXED_LENGTH_MAX, const bool skip = false);

  void bgn_buf();
  void jmp_pos(const LexedPosition &position);
  bool has_chr_at_idx(const LexedCharacter character, const LexedIndex index) const;
  bool has_chr_at_idx(bool (*is_character)(LexedCharacter), const LexedIndex index) const;
  bool has_chr_in_rng(bool (*is_character)(LexedCharacter), const LexedIndex index, const LexedIndex end_index) const;
  bool has_chr_in_rng(bool (*is_character)(LexedCharacter), const LexedPosition position, const LexedPosition end_position) const;

  void bgn_rec_tbl_col_cnt();
  void end_rec_tbl_col_cnt();
  uint16_t tbl_col_cnt();

  LexedLength clc_vtr_spc_cnt(const LexedColumn current_indentation, const LexedColumn target_indentation, LexedLength &indentation_character_count_between_current_and_target) const;

  bool ret_sym(const TokenType result_symbol);
};

}

#endif // TREE_SITTER_MARKDOWN_TRACED_LEXER_H_
