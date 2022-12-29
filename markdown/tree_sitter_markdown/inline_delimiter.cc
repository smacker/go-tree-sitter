#include "./inline_delimiter.h"
#include "./predicate.h"

#define MAX_INL_DLM_LEN 0b11111111

namespace tree_sitter_markdown {

bool MinimizedInlineDelimiter::yes() const { return yes_; }
Symbol MinimizedInlineDelimiter::sym() const { return sym_; }
LexedLength MinimizedInlineDelimiter::len() const { return len_; }

MinimizedInlineDelimiter::MinimizedInlineDelimiter(): yes_(false), sym_(SYM_NOT_FOUND), len_(LEXED_LENGTH_MAX) {}
MinimizedInlineDelimiter::MinimizedInlineDelimiter(const bool yes, const Symbol sym, const LexedIndex len): yes_(yes), sym_(sym), len_(len) {}

unsigned MinimizedInlineDelimiter::serialize(unsigned char *buffer) const {
  TREE_SITTER_MARKDOWN_ASSERT(is_inl_sym(sym_));
  TREE_SITTER_MARKDOWN_ASSERT(sym_ <= 0b1111111);
  TREE_SITTER_MARKDOWN_ASSERT(len_ <= MAX_INL_DLM_LEN);
  buffer[0] = (sym_ << 1) | yes_;
  buffer[1] = len_;
  return 2;
}
unsigned MinimizedInlineDelimiter::deserialize(const unsigned char *buffer) {
  yes_ = buffer[0] & 1;
  sym_ = static_cast<Symbol>(buffer[0] >> 1);
  len_ = buffer[1];
  return 2;
}

TokenType MinimizedInlineDelimiter::tkn_typ(LexedCharacter cur_chr, LexedCharacter lka_chr) const {
  if (sym_ == SYM_BSL_LBK) {
    if (lka_chr == '\\') return TKN_HRD_LBK;
  } else if (sym_ == SYM_BSL_ESC) {
    if (lka_chr == '\\') return TKN_BSL_ESC;
  } else if (sym_ == SYM_CHR_REF) {
    if (lka_chr == '&') return TKN_CHR_REF;
  } else if (sym_ == SYM_ASR_BGN) {
    if (lka_chr == '*') return len_ == 1 ? TKN_EMP_BGN : TKN_STG_BGN;
  } else if (sym_ == SYM_ASR_END) {
    if (lka_chr == '*') return len_ == 1 ? TKN_EMP_END : TKN_STG_END;
  } else if (sym_ == SYM_USC_BGN) {
    if (lka_chr == '_') return len_ == 1 ? TKN_EMP_BGN : TKN_STG_BGN;
  } else if (sym_ == SYM_USC_END) {
    if (lka_chr == '_') return len_ == 1 ? TKN_EMP_END : TKN_STG_END;
  } else if (sym_ == SYM_DEL_BGN) {
    if (lka_chr == '~') return TKN_DEL_BGN;
  } else if (sym_ == SYM_DEL_END) {
    if (lka_chr == '~') return TKN_DEL_END;
  } else if (sym_ == SYM_IMG_BGN) {
    if (lka_chr == '!') return TKN_IMG_BGN;
  } else if (sym_ == SYM_LNK_BGN) {
    if (lka_chr == '[') return TKN_LNK_BGN;
  } else if (sym_ == SYM_LNK_END) {
    if (lka_chr == ']') return TKN_LNK_END;
  } else if (sym_ == SYM_LNK_REF_DEF_BGN) {
    if (lka_chr == '[') return TKN_LNK_REF_DEF_BGN;
  } else if (sym_ == SYM_LNK_REF_DEF_CLN) {
    if (lka_chr == ':') return TKN_LNK_REF_DEF_CLN;
  } else if (sym_ == SYM_LNK_INL_BGN) {
    if (lka_chr == '(') return TKN_LNK_INL_BGN;
  } else if (sym_ == SYM_LNK_INL_END) {
    if (lka_chr == ')') return TKN_LNK_INL_END;
  } else if (sym_ == SYM_LNK_DST_EXP_BGN) {
    if (lka_chr == '<') return TKN_LNK_DST_BGN;
  } else if (sym_ == SYM_LNK_DST_EXP_END) {
    if (lka_chr == '>') return TKN_LNK_DST_END;
  } else if (sym_ == SYM_LNK_DST_IMP_BGN_MKR) {
    if (!is_wht_chr(lka_chr)) return TKN_LNK_DST_BGN_MKR;
  } else if (sym_ == SYM_LNK_DST_IMP_END_MKR) {
    if (is_wht_chr(lka_chr) || lka_chr == ')') return TKN_LNK_DST_END_MKR;
  } else if (sym_ == SYM_LNK_DST_IMP_PRN_BGN) {
    if (lka_chr == '(') return TKN_TXT;
  } else if (sym_ == SYM_LNK_DST_IMP_PRN_END) {
    if (lka_chr == ')') return TKN_TXT;
  } else if (sym_ == SYM_LNK_TIT_SQT_BGN) {
    if (lka_chr == '\'') return TKN_LNK_TIT_BGN;
  } else if (sym_ == SYM_LNK_TIT_SQT_END) {
    if (lka_chr == '\'') return TKN_LNK_TIT_END;
  } else if (sym_ == SYM_LNK_TIT_DQT_BGN) {
    if (lka_chr == '"') return TKN_LNK_TIT_BGN;
  } else if (sym_ == SYM_LNK_TIT_DQT_END) {
    if (lka_chr == '"') return TKN_LNK_TIT_END;
  } else if (sym_ == SYM_LNK_TIT_PRN_BGN) {
    if (lka_chr == '(') return TKN_LNK_TIT_BGN;
  } else if (sym_ == SYM_LNK_TIT_PRN_END) {
    if (lka_chr == ')') return TKN_LNK_TIT_END;
  } else if (sym_ == SYM_LNK_REF_BGN) {
    if (lka_chr == '[') return TKN_LNK_REF_BGN;
  } else if (sym_ == SYM_LNK_REF_END) {
    if (lka_chr == ']') return TKN_LNK_REF_END;
  } else if (sym_ == SYM_COD_SPN_BGN) {
    if (lka_chr == '`') return TKN_COD_SPN_BGN;
  } else if (sym_ == SYM_COD_SPN_END) {
    if (lka_chr == '`') return TKN_COD_SPN_END;
  } else if (sym_ == SYM_EXT_AUT_LNK_BGN) {
    if (is_ext_aut_lnk_bgn(cur_chr, lka_chr)) return TKN_TXT;
  } else if (sym_ == SYM_EXT_WWW_AUT_LNK_BGN_MKR) {
    if (is_ext_aut_lnk_bgn(cur_chr, lka_chr)) return TKN_EXT_WWW_AUT_LNK_BGN_MKR;
  } else if (sym_ == SYM_EXT_URL_AUT_LNK_BGN_MKR) {
    if (is_ext_aut_lnk_bgn(cur_chr, lka_chr)) return TKN_EXT_URL_AUT_LNK_BGN_MKR;
  } else if (sym_ == SYM_EXT_EML_AUT_LNK_BGN_MKR) {
    if (is_ext_aut_lnk_bgn(cur_chr, lka_chr)) return TKN_EXT_EML_AUT_LNK_BGN_MKR;
  } else if (sym_ == SYM_EXT_AUT_LNK_CTN) {
    return TKN_TXT;
  } else if (sym_ == SYM_EXT_AUT_LNK_END_MKR) {
    return TKN_EXT_AUT_LNK_END_MKR;
  } else if (sym_ == SYM_AUT_LNK_HTM_OPN_TAG_BGN) {
    if (lka_chr == '<') return TKN_TXT;
  } else if (sym_ == SYM_URI_AUT_LNK_BGN) {
    if (lka_chr == '<') return TKN_URI_AUT_LNK_BGN;
  } else if (sym_ == SYM_EML_AUT_LNK_BGN) {
    if (lka_chr == '<') return TKN_EML_AUT_LNK_BGN;
  } else if (sym_ == SYM_AUT_LNK_END) {
    if (lka_chr == '>') return TKN_AUT_LNK_END;
  } else if (sym_ == SYM_HTM_OPN_TAG_BGN) {
    if (lka_chr == '<') return TKN_HTM_OPN_TAG_BGN;
  } else if (sym_ == SYM_HTM_CLS_TAG_BGN) {
    if (lka_chr == '<') return TKN_HTM_CLS_TAG_BGN;
  } else if (sym_ == SYM_HTM_DCL_BGN) {
    if (lka_chr == '<') return TKN_HTM_DCL_BGN;
  } else if (sym_ == SYM_HTM_TAG_END) {
    if (lka_chr == '>') return TKN_HTM_TAG_END;
  } else if (sym_ == SYM_HTM_SLF_TAG_END) {
    if (lka_chr == '/') return TKN_HTM_SLF_TAG_END;
  } else if (sym_ == SYM_HTM_ATR_EQL) {
    if (lka_chr == '=') return TKN_HTM_ATR_EQL;
  } else if (sym_ == SYM_HTM_ATR_UQT_BGN_MKR) {
    if (!is_wht_chr(lka_chr)) return TKN_HTM_ATR_VAL_BGN_MKR;
  } else if (sym_ == SYM_HTM_ATR_UQT_END_MKR) {
    if (is_wht_chr(lka_chr) || lka_chr == '/' ||  lka_chr == '>') return TKN_HTM_ATR_VAL_END_MKR;
  } else if (sym_ == SYM_HTM_ATR_SQT_BGN) {
    if (lka_chr == '\'') return TKN_HTM_ATR_VAL_BGN;
  } else if (sym_ == SYM_HTM_ATR_SQT_END) {
    if (lka_chr == '\'') return TKN_HTM_ATR_VAL_END;
  } else if (sym_ == SYM_HTM_ATR_DQT_BGN) {
    if (lka_chr == '"') return TKN_HTM_ATR_VAL_BGN;
  } else if (sym_ == SYM_HTM_ATR_DQT_END) {
    if (lka_chr == '"') return TKN_HTM_ATR_VAL_END;
  } else if (sym_ == SYM_HTM_CMT_BGN) {
    if (lka_chr == '<') return TKN_HTM_CMT_BGN;
  } else if (sym_ == SYM_HTM_CMT_END) {
    if (lka_chr == '-') return TKN_HTM_CMT_END;
  } else if (sym_ == SYM_HTM_PRC_BGN) {
    if (lka_chr == '<') return TKN_HTM_PRC_BGN;
  } else if (sym_ == SYM_HTM_PRC_END) {
    if (lka_chr == '?') return TKN_HTM_PRC_END;
  } else if (sym_ == SYM_HTM_CDA_BGN) {
    if (lka_chr == '<') return TKN_HTM_CDA_BGN;
  } else if (sym_ == SYM_HTM_CDA_END) {
    if (lka_chr == ']') return TKN_HTM_CDA_END;
  } else if (sym_ == SYM_ATX_END) {
    if (lka_chr == '#') return TKN_ATX_END;
  } else if (sym_ == SYM_LST_CHK_BOX) {
    if (lka_chr == '[') return TKN_LST_CHK_BOX;
  } else if (sym_ == SYM_TBL_COL_SEP) {
    if (lka_chr == '|') return TKN_TBL_COL_SEP;
  } else if (sym_ == SYM_TBL_COL_ALN) {
    if (lka_chr == ':' || lka_chr == '-') return TKN_TBL_COL_ALN;
  } else if (sym_ == SYM_FEN_COD_INF_BGN_MKR) {
    if (!is_wht_chr(lka_chr)) return TKN_FEN_COD_INF_BGN_MKR;
  } else if (sym_ == SYM_FEN_COD_INF_END_MKR) {
    if (is_eol_chr(lka_chr)) return TKN_FEN_COD_INF_END_MKR;
  }
  return TKN_NOT_FOUND;
}

//==============================================================================

bool MinimizedInlineDelimiterList::empty() const { return list_.empty(); }
MinimizedInlineDelimiter &MinimizedInlineDelimiterList::front() { return list_.front(); }

void MinimizedInlineDelimiterList::pop_front() { list_.pop_front(); }
void MinimizedInlineDelimiterList::push_back(const MinimizedInlineDelimiter &delimiter) { list_.push_back(delimiter); }

void MinimizedInlineDelimiterList::clear() { list_.clear(); }
unsigned MinimizedInlineDelimiterList::serialize(unsigned char *buffer) const {
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
unsigned MinimizedInlineDelimiterList::deserialize(const unsigned char *buffer) {
  size_t i = 0;
  list_.resize(buffer[i++]);
  for (Iterator itr = list_.begin(), end = list_.end(); itr != end; itr++) {
    i += itr->deserialize(&buffer[i]);
  }
  return i;
}

//==============================================================================

bool InlineDelimiter::yes() const { return yes_; }
Symbol InlineDelimiter::sym() const { return sym_; }
LexedLength InlineDelimiter::len() const { return len_; }
LexedLength InlineDelimiter::ori_len() const { return ori_len_; }
const LexedPosition &InlineDelimiter::pos() const { return pos_; }
const LexedPosition &InlineDelimiter::end_pos() const { return end_pos_; }
InlineDelimiterCustomData InlineDelimiter::ctm_dat() const { return ctm_dat_; }
bool InlineDelimiter::has_end_dlm() const { return end_dlm_ != NULL_PTR; }
InlineDelimiter *InlineDelimiter::end_dlm() const { return end_dlm_; }

void InlineDelimiter::set_yes(const bool yes) { yes_ = yes; }
void InlineDelimiter::set_sym(const Symbol sym) { sym_ = sym; }
void InlineDelimiter::set_end_pos(const LexedPosition &pos) { end_pos_.set(pos); len_ = pos_.dist(end_pos_); }
void InlineDelimiter::set_ctm_dat(const InlineDelimiterCustomData ctm_dat) { ctm_dat_ = ctm_dat; }
void InlineDelimiter::set_end_dlm(InlineDelimiter *const end_dlm) { end_dlm_ = end_dlm; }
void InlineDelimiter::set_end_dlm(InlineDelimiterList::Iterator end_dlm_itr) { end_dlm_ = &(*end_dlm_itr); }

InlineDelimiter::InlineDelimiter(const bool yes, const Symbol sym, const LexedPosition &pos, const LexedPosition &end_pos):
  yes_(yes), sym_(sym), len_(pos.dist(end_pos)), ori_len_(len_), pos_(pos), end_pos_(end_pos), ctm_dat_(0), end_dlm_(NULL_PTR) {}

MinimizedInlineDelimiter InlineDelimiter::to_min() const { return MinimizedInlineDelimiter(yes_, sym_, len_); }

//==============================================================================

bool InlineDelimiterList::empty() const { return list_.empty(); }
InlineDelimiter &InlineDelimiterList::front() { return list_.front(); }
InlineDelimiterList::Iterator InlineDelimiterList::end() { return list_.end(); }

void InlineDelimiterList::clear() { list_.clear(); }

void InlineDelimiterList::pop_front() { list_.pop_front(); }
InlineDelimiterList::Iterator InlineDelimiterList::insert(Iterator nxt_itr, const InlineDelimiter &dlm) { return list_.insert(nxt_itr, dlm); }
InlineDelimiterList::Iterator InlineDelimiterList::erase(Iterator itr) { return list_.erase(itr); }
InlineDelimiterList::Iterator InlineDelimiterList::erase(Iterator itr, Iterator end_itr) { return list_.erase(itr, end_itr); }

void InlineDelimiterList::transfer_to(MinimizedInlineDelimiterList &minimized_list) {
  while (!empty()) {
    const MinimizedInlineDelimiter &inl_dlm = front().to_min();
    if (inl_dlm.len() <= MAX_INL_DLM_LEN) {
      minimized_list.push_back(inl_dlm);
    } else {
      // split SYM_EXT_AUT_LNK_BGN/SYM_EXT_AUT_LNK_CTN into multiple parts to bypass length limit for inline delimeters
      TREE_SITTER_MARKDOWN_ASSERT(inl_dlm.sym() == SYM_EXT_AUT_LNK_BGN || inl_dlm.sym() == SYM_EXT_AUT_LNK_CTN);
      minimized_list.push_back(MinimizedInlineDelimiter(inl_dlm.yes(), inl_dlm.sym(), MAX_INL_DLM_LEN));
      LexedLength rst_len = inl_dlm.len() - MAX_INL_DLM_LEN;
      while (rst_len > 0) {
        LexedLength len = rst_len > MAX_INL_DLM_LEN ? MAX_INL_DLM_LEN : rst_len;
        minimized_list.push_back(MinimizedInlineDelimiter(inl_dlm.yes(), SYM_EXT_AUT_LNK_CTN, len));
        rst_len -= len;
      }
    }
    pop_front();
  }
}

}
