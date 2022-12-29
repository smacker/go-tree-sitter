#include "./lexer.h"

#include <cstring>
#include "./predicate.h"

namespace tree_sitter_markdown {

LexedIndex Lexer::cur_idx() const { return cur_idx_; }
LexedRow Lexer::cur_row() const { return cur_row_; }
LexedColumn Lexer::cur_col() const { return cur_col_; }
LexedPosition Lexer::cur_pos() const { return LexedPosition(cur_idx_, cur_row_, cur_col_); }
LexedPosition Lexer::cur_pos(const LexedIndex offset_idx) const { return LexedPosition(cur_idx_ + offset_idx, cur_row_, cur_col_ + offset_idx); }
LexedCharacter Lexer::cur_chr() const { return cur_chr_; }
LexedCharacter Lexer::lka_chr() const { return lka_chr_; }
LexedLength Lexer::cur_spc() const { return cur_spc_; }
LexedColumn Lexer::cur_ind() const { return cur_ind_; }

void Lexer::clear() {
  bgn_chr_ = 0;
  bgn_col_ = 0;
}
void Lexer::init(TSLexer *lexer) {
  lxr_ = lexer;
  cur_idx_ = 0;
  cur_row_ = 0;
  cur_col_ = bgn_col_;
  end_col_ = LEXED_INDEX_MAX;
  cur_chr_ = bgn_chr_;
  lka_chr_ = lexer->lookahead;
  end_chr_ = LEXED_CHARACTER_MAX;
  buf_bgn_idx_ = LEXED_INDEX_MAX;
  chr_buf_.clear();
  cur_spc_ = 0;
  cur_ind_ = 0;
  ind_chr_col_buf_.clear();
  is_rec_tbl_col_cnt_ = false;
}
void Lexer::mrk_end() {
  end_col_ = cur_col_;
  end_chr_ = cur_chr_;
  lxr_->mark_end(lxr_);
}

unsigned Lexer::serialize(unsigned char *buffer) {
  size_t i = 0;
  memcpy(&buffer[i], &bgn_col_, sizeof bgn_col_);
  i += sizeof bgn_col_;
  memcpy(&buffer[i], &bgn_chr_, sizeof bgn_chr_);
  i += sizeof bgn_chr_;
  return i;
}
unsigned Lexer::deserialize(const unsigned char *buffer) {
  size_t i = 0;
  memcpy(&bgn_col_, &buffer[i], sizeof bgn_col_);
  i += sizeof bgn_col_;
  memcpy(&bgn_chr_, &buffer[i], sizeof bgn_chr_);
  i += sizeof bgn_chr_;
  return i;
}

void Lexer::adv(const bool skp) {
  if (lka_chr_ == '\n' || lka_chr_ == '\r') {
    cur_col_ = 0;
    cur_ind_ = 0;
    ind_chr_col_buf_.clear();
  } else if (lka_chr_ == '\t') {
    LexedColumn offset = 4 - (cur_col_ % 4);
    cur_col_ += offset;
    cur_ind_ += offset;
    ind_chr_col_buf_.push_back(offset);
  } else if (lka_chr_ == ' ') {
    cur_col_++;
    cur_ind_++;
    ind_chr_col_buf_.push_back(1);
  } else {
    cur_col_++;
    cur_ind_ = 0;
    ind_chr_col_buf_.clear();
  }

  if (
    lka_chr_ == '\r'
    || (lka_chr_ == '\n' && cur_chr_ != '\r')
  ) cur_row_++;

  if (is_rec_tbl_col_cnt_ && !is_wsp_chr(lka_chr_)) {
    if (lka_chr_ == '|' && cur_chr_ != '\\') {
      if (tbl_col_is_bgn_) tbl_col_has_bgn_pip_ = true;
      tbl_col_pip_cnt_++;
      tbl_col_has_ctn_ = false;
    } else {
      tbl_col_has_ctn_ = true;
    }
    tbl_col_is_bgn_ = false;
  }

  if (lka_chr_ == ' ') cur_spc_++;
  else cur_spc_ = 0;

  cur_idx_++;
  cur_chr_ = lka_chr_;
  if (buf_bgn_idx_ == LEXED_INDEX_MAX) {
    lxr_->advance(lxr_, skp);
    lka_chr_ = lxr_->lookahead;
  } else {
    if (cur_idx_ - buf_bgn_idx_ + 1 >= chr_buf_.size()) {
      lxr_->advance(lxr_, skp);
      chr_buf_.push_back(lxr_->lookahead);
    }
    lka_chr_ = chr_buf_[cur_idx_ - buf_bgn_idx_ + 1];
  }
}
void Lexer::adv_len(const LexedLength len, const bool skp) {
  for (LexedLength i = 0; i < len; i++) adv(skp);
}
bool Lexer::adv_if(const LexedCharacter chr, const bool skp) {
  if (lka_chr_ != chr) return false;
  adv(skp);
  return true;
}
bool Lexer::adv_if(bool (*is_chr)(LexedCharacter), const bool skp) {
  if (!is_chr(lka_chr_)) return false;
  adv(skp);
  return true;
}
bool Lexer::adv_til(const LexedCharacter chr, const bool skp) {
  if (lka_chr_ == chr) return false;
  do adv(skp);
  while (lka_chr_ != chr);
  return true;
}
bool Lexer::adv_til(bool (*is_chr)(LexedCharacter), const bool skp) {
  if (is_chr(lka_chr_)) return false;
  do adv(skp);
  while (!is_chr(lka_chr_));
  return true;
}
bool Lexer::adv_rpt(const LexedCharacter chr, const bool skp) {
  bool has_chr = lka_chr_ == chr;
  if (has_chr) {
    do adv(skp);
    while (lka_chr_ == chr);
  }
  return has_chr;
}
bool Lexer::adv_rpt(bool (*is_chr)(LexedCharacter), const bool skp) {
  bool has_chr = is_chr(lka_chr_);
  if (has_chr) {
    do adv(skp);
    while (is_chr(lka_chr_));
  }
  return has_chr;
}
LexedLength Lexer::adv_rpt_len(const LexedCharacter chr, const LexedLength max_len, const bool skp) {
  LexedLength i = 0;
  for (; lka_chr_ == chr && i < max_len; i++) adv(skp);
  return i;
}
LexedLength Lexer::adv_rpt_len(bool (*is_chr)(LexedCharacter), const LexedLength max_len, const bool skp) {
  LexedLength i = 0;
  for (; is_chr(lka_chr_) && i < max_len; i++) adv(skp);
  return i;
}

void Lexer::bgn_buf() {
  TREE_SITTER_MARKDOWN_ASSERT(buf_bgn_idx_ == LEXED_INDEX_MAX);
  buf_bgn_idx_ = cur_idx_;
  chr_buf_.push_back(cur_chr_);
  chr_buf_.push_back(lka_chr_);
}
void Lexer::jmp_pos(const LexedPosition &pos) {
  if (pos.idx() == cur_idx_) return;
  TREE_SITTER_MARKDOWN_ASSERT(pos.idx() >= buf_bgn_idx_);
  TREE_SITTER_MARKDOWN_ASSERT(pos.idx() - buf_bgn_idx_ < chr_buf_.size() - 1);
  cur_idx_ = pos.idx();
  cur_row_ = pos.row();
  cur_col_ = pos.col();
  cur_chr_ = chr_buf_[cur_idx_ - buf_bgn_idx_];
  lka_chr_ = chr_buf_[cur_idx_ - buf_bgn_idx_ + 1];
  cur_spc_ = 0;
  cur_ind_ = 0;
}
bool Lexer::has_chr_at_idx(const LexedCharacter chr, const LexedIndex idx) const {
  TREE_SITTER_MARKDOWN_ASSERT(idx >= buf_bgn_idx_);
  TREE_SITTER_MARKDOWN_ASSERT(idx - buf_bgn_idx_ < chr_buf_.size());
  return idx < 0 ? false : chr_buf_[idx - buf_bgn_idx_] == chr;
}
bool Lexer::has_chr_at_idx(bool (*is_chr)(LexedCharacter), const LexedIndex idx) const {
  TREE_SITTER_MARKDOWN_ASSERT(idx >= buf_bgn_idx_);
  TREE_SITTER_MARKDOWN_ASSERT(idx - buf_bgn_idx_ < chr_buf_.size());
  return idx < 0 ? false : is_chr(chr_buf_[idx - buf_bgn_idx_]);
}
bool Lexer::has_chr_in_rng(bool (*is_chr)(LexedCharacter), const LexedIndex idx, const LexedIndex end_idx) const {
  TREE_SITTER_MARKDOWN_ASSERT(idx >= buf_bgn_idx_);
  TREE_SITTER_MARKDOWN_ASSERT(idx - buf_bgn_idx_ <= end_idx);
  TREE_SITTER_MARKDOWN_ASSERT(end_idx - buf_bgn_idx_ < chr_buf_.size() - 1);
  for (LexedIndex i = idx - buf_bgn_idx_; i < end_idx - buf_bgn_idx_; i++) {
    if (is_chr(chr_buf_[i])) return true;
  }
  return false;
}
bool Lexer::has_chr_in_rng(bool (*is_chr)(LexedCharacter), const LexedPosition pos, const LexedPosition end_pos) const {
  return has_chr_in_rng(is_chr, pos.idx(), end_pos.idx());
}

void Lexer::bgn_rec_tbl_col_cnt() {
  TREE_SITTER_MARKDOWN_ASSERT(!is_rec_tbl_col_cnt_);
  is_rec_tbl_col_cnt_ = true;
  tbl_col_is_bgn_ = true;
  tbl_col_has_bgn_pip_ = false;
  tbl_col_has_ctn_ = false;
  tbl_col_pip_cnt_ = 0;
}
void Lexer::end_rec_tbl_col_cnt() {
  TREE_SITTER_MARKDOWN_ASSERT(is_rec_tbl_col_cnt_);
  is_rec_tbl_col_cnt_ = false;
}
uint16_t Lexer::tbl_col_cnt() {
  TREE_SITTER_MARKDOWN_ASSERT(is_rec_tbl_col_cnt_);
  uint16_t tbl_col_cnt_ = tbl_col_pip_cnt_ + 1;
  if (tbl_col_has_bgn_pip_) tbl_col_cnt_--;
  bool has_end_pip = (tbl_col_pip_cnt_ - tbl_col_has_bgn_pip_) && !tbl_col_has_ctn_;
  if (has_end_pip) tbl_col_cnt_--;
  return tbl_col_cnt_;
}

LexedLength Lexer::clc_vtr_spc_cnt(const LexedColumn cur_ind, const LexedColumn tgt_ind, LexedLength &ind_chr_cnt_btw_cur_and_tgt) const {
  const LexedColumn actual_tgt_ind = cur_ind_ - cur_ind + tgt_ind;
  if (actual_tgt_ind == 0) {
    ind_chr_cnt_btw_cur_and_tgt = 0;
    return 0;
  }
  LexedColumn ind = 0;
  for (uint16_t i = 0; i < ind_chr_col_buf_.size(); i++) {
    ind += ind_chr_col_buf_[i];
    if (ind >= actual_tgt_ind) {
      ind_chr_cnt_btw_cur_and_tgt = i + 1;
      return ind - actual_tgt_ind;
    }
  }
  TREE_SITTER_MARKDOWN_ASSERT(false);
}

bool Lexer::ret_sym(const TokenType rlt_sym) {
  TREE_SITTER_MARKDOWN_ASSERT(end_col_ != LEXED_COLUMN_MAX);
  bgn_col_ = end_col_;
  TREE_SITTER_MARKDOWN_ASSERT(end_chr_ != LEXED_CHARACTER_MAX);
  bgn_chr_ = end_chr_;
  lxr_->result_symbol = rlt_sym;
  return true;
}

}
