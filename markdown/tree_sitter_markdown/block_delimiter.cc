#include "./block_delimiter.h"

#include "./predicate.h"

namespace tree_sitter_markdown {

Symbol BlockDelimiter::sym() const { return sym_; }
LexedLength BlockDelimiter::len() const { return len_; }
LexedColumn BlockDelimiter::ind() const { return ind_; }
bool BlockDelimiter::has_pos() const { return has_pos_; }
const LexedPosition &BlockDelimiter::pos() const { TREE_SITTER_MARKDOWN_ASSERT(has_pos_); return pos_; }
const LexedPosition &BlockDelimiter::end_pos() const { TREE_SITTER_MARKDOWN_ASSERT(has_pos_); return end_pos_; }

void BlockDelimiter::set_len(const LexedLength len) {
  len_ = len;
}
void BlockDelimiter::set_ind(const LexedColumn ind) {
  ind_ = ind;
}
void BlockDelimiter::set_pos(const LexedPosition &pos, const LexedPosition &end_pos) {
  pos_.set(pos);
  end_pos_.set(end_pos);
  has_pos_ = true;
  TREE_SITTER_MARKDOWN_ASSERT(pos_.dist(end_pos_) == len_);
}
void BlockDelimiter::drop_pos() {
  has_pos_ = false;
}

BlockDelimiter::BlockDelimiter(): sym_(SYM_NOT_FOUND), len_(LEXED_LENGTH_MAX), ind_(LEXED_COLUMN_MAX), has_pos_(false) {}
BlockDelimiter::BlockDelimiter(const Symbol sym, const LexedLength len, const LexedColumn ind):
  sym_(sym), len_(len), ind_(ind), has_pos_(false) {}
BlockDelimiter::BlockDelimiter(const Symbol sym, const LexedPosition &pos, const LexedPosition &end_pos, const LexedColumn ind):
  sym_(sym), len_(pos.dist(end_pos)), ind_(ind), has_pos_(true), pos_(pos), end_pos_(end_pos) {}

unsigned BlockDelimiter::serialize(unsigned char *buffer) const {
  TREE_SITTER_MARKDOWN_ASSERT(is_blk_sym(sym_));
  TREE_SITTER_MARKDOWN_ASSERT(sym_ < 0b11111111);
  TREE_SITTER_MARKDOWN_ASSERT(len_ < 0b11111111);
  TREE_SITTER_MARKDOWN_ASSERT(ind_ < 0b11111111);
  buffer[0] = sym_;
  buffer[1] = len_;
  buffer[2] = ind_;
  return 3;
}
unsigned BlockDelimiter::deserialize(const unsigned char *buffer) {
  sym_ = static_cast<Symbol>(buffer[0]);
  len_ = buffer[1];
  ind_ = buffer[2];
  return 3;
}

TokenType BlockDelimiter::tkn_typ(LexedCharacter c) const {
  if (sym_ == SYM_VRT_SPC) { return TKN_VRT_SPC; }
  else if (sym_ == SYM_LIT_LBK) { if (is_lbk_chr(c)) return TKN_LIT_LBK; }
  else if (sym_ == SYM_BNK_LBK) { if (is_lbk_chr(c)) return TKN_BNK_LBK; }
  else if (sym_ == SYM_ASR_THM_BRK_BGN) { if (c == '*') return TKN_THM_BRK_BGN; }
  else if (sym_ == SYM_USC_THM_BRK_BGN) { if (c == '_') return TKN_THM_BRK_BGN; }
  else if (sym_ == SYM_HYP_THM_BRK_BGN) { if (c == '-') return TKN_THM_BRK_BGN; }
  else if (sym_ == SYM_PGH_BGN_MKR) { if (!is_wht_chr(c)) return TKN_PGH_BGN_MKR; }
  else if (sym_ == SYM_EQL_STX_BGN) { if (c == '=') return TKN_STX_BGN_1; }
  else if (sym_ == SYM_HYP_STX_BGN) { if (c == '-') return TKN_STX_BGN_2; }
  else if (sym_ == SYM_ATX_BGN) { if (c == '#') return TKN_ATX_BGN_ARR[len_ - 1]; }
  else if (sym_ == SYM_IND_COD_BGN_PFX) { if (is_wsp_chr(c)) return TKN_IND_COD_BGN_PFX; }
  else if (sym_ == SYM_IND_COD_BGN_MKR) { return TKN_IND_COD_BGN_MKR; }
  else if (sym_ == SYM_FEN_COD_CTN_BGN_MKR) { return TKN_FEN_COD_CTN_BGN_MKR; }
  else if (sym_ == SYM_BTK_FEN_COD_BGN) { if (c == '`') return TKN_FEN_COD_BGN; }
  else if (sym_ == SYM_TLD_FEN_COD_BGN) { if (c == '~') return TKN_FEN_COD_BGN; }
  else if (sym_ == SYM_HTM_BLK_SCR_BGN_MKR) { if (c == '<') return TKN_HTM_BLK_SCR_BGN_MKR; }
  else if (sym_ == SYM_HTM_BLK_CMT_BGN_MKR) { if (c == '<') return TKN_HTM_BLK_CMT_BGN_MKR; }
  else if (sym_ == SYM_HTM_BLK_PRC_BGN_MKR) { if (c == '<') return TKN_HTM_BLK_PRC_BGN_MKR; }
  else if (sym_ == SYM_HTM_BLK_DCL_BGN_MKR) { if (c == '<') return TKN_HTM_BLK_DCL_BGN_MKR; }
  else if (sym_ == SYM_HTM_BLK_CDA_BGN_MKR) { if (c == '<') return TKN_HTM_BLK_CDA_BGN_MKR; }
  else if (sym_ == SYM_HTM_BLK_DIV_BGN_MKR) { if (c == '<') return TKN_HTM_BLK_DIV_BGN_MKR; }
  else if (sym_ == SYM_HTM_BLK_CMP_BGN_MKR) { if (c == '<') return TKN_HTM_BLK_CMP_BGN_MKR; }
  else if (sym_ == SYM_BQT_BGN) { if (c == '>') return TKN_BQT_BGN; }
  else if (sym_ == SYM_ASR_LST_BGN_MKR) { if (c == '*') return TKN_LST_BGN_MKR; }
  else if (sym_ == SYM_ASR_LST_ITM_BGN) { if (c == '*') return TKN_LST_ITM_BGN; }
  else if (sym_ == SYM_HYP_LST_BGN_MKR) { if (c == '-') return TKN_LST_BGN_MKR; }
  else if (sym_ == SYM_HYP_LST_ITM_BGN) { if (c == '-') return TKN_LST_ITM_BGN; }
  else if (sym_ == SYM_PLS_LST_BGN_MKR) { if (c == '+') return TKN_LST_BGN_MKR; }
  else if (sym_ == SYM_PLS_LST_ITM_BGN) { if (c == '+') return TKN_LST_ITM_BGN; }
  else if (sym_ == SYM_DOT_LST_BGN_MKR) { if (is_num_chr(c)) return TKN_LST_BGN_MKR; }
  else if (sym_ == SYM_DOT_LST_ITM_BGN) { if (is_num_chr(c)) return TKN_LST_ITM_BGN; }
  else if (sym_ == SYM_RPR_LST_BGN_MKR) { if (is_num_chr(c)) return TKN_LST_BGN_MKR; }
  else if (sym_ == SYM_RPR_LST_ITM_BGN) { if (is_num_chr(c)) return TKN_LST_ITM_BGN; }
  else if (sym_ == SYM_LST_ITM_CNT_BGN_MKR) { return TKN_LST_ITM_CNT_BGN_MKR; }
  else if (sym_ == SYM_TBL_HED_ROW_BGN_MKR) { if (!is_wht_chr(c)) return TKN_TBL_HED_ROW_BGN_MKR; }
  else if (sym_ == SYM_TBL_DLM_ROW_BGN_MKR) { if (!is_wht_chr(c)) return TKN_TBL_DLM_ROW_BGN_MKR; }
  else if (sym_ == SYM_TBL_DAT_ROW_BGN_MKR) { if (!is_wht_chr(c)) return TKN_TBL_DAT_ROW_BGN_MKR; }
  else if (sym_ == SYM_THM_BRK_END_MKR) { if (is_eol_chr(c)) return TKN_THM_BRK_END_MKR; }
  else if (sym_ == SYM_PGH_END_MKR) { if (is_eol_chr(c)) return TKN_PGH_END_MKR; }
  else if (sym_ == SYM_LNK_REF_DEF_END_MKR) { if (is_eol_chr(c)) return TKN_LNK_REF_DEF_END_MKR; }
  else if (sym_ == SYM_STX_END_MKR) { if (is_eol_chr(c)) return TKN_STX_END_MKR; }
  else if (sym_ == SYM_ATX_END_MKR) { if (is_eol_chr(c)) return TKN_ATX_END_MKR; }
  else if (sym_ == SYM_IND_COD_END_MKR) { if (is_eol_chr(c)) return TKN_IND_COD_END_MKR; }
  else if (sym_ == SYM_BTK_FEN_COD_END) { if (c == '`') return TKN_FEN_COD_END; }
  else if (sym_ == SYM_BTK_FEN_COD_END_MKR) { if (is_eol_chr(c)) return TKN_FEN_COD_END_MKR; }
  else if (sym_ == SYM_TLD_FEN_COD_END) { if (c == '~') return TKN_FEN_COD_END; }
  else if (sym_ == SYM_TLD_FEN_COD_END_MKR) { if (is_eol_chr(c)) return TKN_FEN_COD_END_MKR; }
  else if (sym_ == SYM_HTM_BLK_SCR_END_MKR) { if (is_eol_chr(c)) return TKN_HTM_BLK_SCR_END_MKR; }
  else if (sym_ == SYM_HTM_BLK_CMT_END_MKR) { if (is_eol_chr(c)) return TKN_HTM_BLK_CMT_END_MKR; }
  else if (sym_ == SYM_HTM_BLK_PRC_END_MKR) { if (is_eol_chr(c)) return TKN_HTM_BLK_PRC_END_MKR; }
  else if (sym_ == SYM_HTM_BLK_DCL_END_MKR) { if (is_eol_chr(c)) return TKN_HTM_BLK_DCL_END_MKR; }
  else if (sym_ == SYM_HTM_BLK_CDA_END_MKR) { if (is_eol_chr(c)) return TKN_HTM_BLK_CDA_END_MKR; }
  else if (sym_ == SYM_HTM_BLK_DIV_END_MKR) { if (is_eol_chr(c)) return TKN_HTM_BLK_DIV_END_MKR; }
  else if (sym_ == SYM_HTM_BLK_CMP_END_MKR) { if (is_eol_chr(c)) return TKN_HTM_BLK_CMP_END_MKR; }
  else if (sym_ == SYM_BQT_END_MKR) { if (is_eol_chr(c)) return TKN_BQT_END_MKR; }
  else if (sym_ == SYM_LST_END_MKR) { if (is_eol_chr(c)) return TKN_LST_END_MKR; }
  else if (sym_ == SYM_LST_ITM_END_MKR) { if (is_eol_chr(c)) return TKN_LST_ITM_END_MKR; }
  else if (sym_ == SYM_LST_ITM_CNT_END_MKR) { if (is_eol_chr(c)) return TKN_LST_ITM_CNT_END_MKR; }
  else if (sym_ == SYM_TBL_ROW_END_MKR) { if (is_eol_chr(c)) return TKN_TBL_ROW_END_MKR; }
  return TKN_NOT_FOUND;
}

//==============================================================================

bool BlockDelimiterList::empty() const { return list_.empty(); }
BlockDelimiter &BlockDelimiterList::front() { return list_.front(); }
BlockDelimiter &BlockDelimiterList::back() { return list_.back(); }
BlockDelimiterList::Iterator BlockDelimiterList::end() { return list_.end(); }
BlockDelimiter *BlockDelimiterList::lit_lbk(const LexedRow row) {
  Iterator itr = list_.begin();
  Iterator end = list_.end();
  for (LexedRow i = 0; itr != end; itr++) {
    if (itr->sym() != SYM_LIT_LBK || i++ == row) {
      return &(*itr);
    }
  }
  return NULL_PTR;
}

void BlockDelimiterList::clear() { return list_.clear(); }
void BlockDelimiterList::drop_pos() {
  for (Iterator itr = list_.begin(), end = list_.end(); itr != end; itr++) {
    if (!itr->has_pos()) break;
    itr->drop_pos();
  }
}
unsigned BlockDelimiterList::serialize(unsigned char *buffer) const {
  size_t i = 0;
  size_t size_i = i++;
  size_t size = 0;
  for (ConstIterator itr = list_.begin(), end = list_.end(); itr != end; itr++) {
    i += itr->serialize(&buffer[i]);
    size++;
  }
  buffer[size_i] = size;
  return i;
}
unsigned BlockDelimiterList::deserialize(const unsigned char *buffer) {
  size_t i = 0;
  list_.resize(buffer[i++]);
  for (Iterator itr = list_.begin(), end = list_.end(); itr != end; itr++) {
    i += itr->deserialize(&buffer[i]);
  }
  return i;
}

void BlockDelimiterList::pop_front() { list_.pop_front(); }
void BlockDelimiterList::push_back(const BlockDelimiter &dlm) { list_.push_back(dlm); }
BlockDelimiterList::Iterator BlockDelimiterList::insert(const BlockDelimiterList::Iterator itr, const BlockDelimiter &dlm) {
  return list_.insert(itr, dlm);
}
BlockDelimiterList::Iterator BlockDelimiterList::insert(const LexedRow row, const BlockDelimiter &dlm) {
  Iterator itr = list_.begin();
  Iterator end = list_.end();
  for (LexedRow cur_row = 0; itr != end; itr++) {
    if (itr->sym() != SYM_LIT_LBK || cur_row++ == row) {
      return list_.insert(itr, dlm);
    }
  }
  list_.push_back(dlm);
  return list_.end();
}
BlockDelimiterList::Iterator BlockDelimiterList::erase(Iterator itr, Iterator end_itr) {
  return list_.erase(itr, end_itr);
}

void BlockDelimiterList::push_vtr_spc(const LexedLength cnt) {
  if (cnt == 0) return;
  list_.push_back(BlockDelimiter(SYM_VRT_SPC, cnt));
}

void BlockDelimiterList::transfer_to(BlockDelimiterList &list) {
  while (!empty()) {
    list.push_back(front());
    pop_front();
  }
}
void BlockDelimiterList::transfer_to(BlockDelimiterList &list, const uint16_t cnt) {
  for (uint16_t i = 0; i < cnt; i++) {
    list.push_back(front());
    pop_front();
  }
}

}
