#include "./inline_context.h"

namespace tree_sitter_markdown {

InlineDelimiterList::Iterator InlineContext::dlm_itr() const { return dlm_itr_; }
ParseState InlineContext::pst() const { TREE_SITTER_MARKDOWN_ASSERT(is_vld_pst()); return pst_; }
bool InlineContext::is_vld_pst() const { return pst_ != PST_INVALID; }
bool InlineContext::has_asr() const { return has_asr_; }
bool InlineContext::has_usc() const { return has_usc_; }
bool InlineContext::has_del() const { return has_del_; }
bool InlineContext::has_cln() const { return has_cln_; }
LexedLength InlineContext::btk_len() const { return btk_len_; }

InlineContext::InlineContext(const InlineDelimiterList::Iterator dlm_itr) {
  dlm_itr_ = dlm_itr;
  has_asr_ = dlm_itr->sym() == SYM_ASR_BGN;
  has_usc_ = dlm_itr->sym() == SYM_USC_BGN;
  has_del_ = dlm_itr->sym() == SYM_DEL_BGN;
  has_cln_ = dlm_itr->sym() == SYM_LNK_REF_DEF_CLN;
  btk_len_ = dlm_itr->sym() == SYM_COD_SPN_BGN ? dlm_itr->len() : 0;
  upd_pst();
}
InlineContext::InlineContext(const InlineDelimiterList::Iterator dlm_itr, const InlineContext &prt_ctx) {
  dlm_itr_ = dlm_itr;
  has_asr_ = prt_ctx.has_asr_ || dlm_itr->sym() == SYM_ASR_BGN;
  has_usc_ = prt_ctx.has_usc_ || dlm_itr->sym() == SYM_USC_BGN;
  has_del_ = prt_ctx.has_del_ || dlm_itr->sym() == SYM_DEL_BGN;
  has_cln_ = prt_ctx.has_cln_ || dlm_itr->sym() == SYM_LNK_REF_DEF_CLN;
  btk_len_ = prt_ctx.btk_len_ || (dlm_itr->sym() == SYM_COD_SPN_BGN ? dlm_itr->len() : 0);
  upd_pst();
}

void InlineContext::upd_pst() {
  pst_ = inl_sym_pst(dlm_itr_->sym(), has_asr_, has_usc_, has_del_);
}

//==============================================================================

bool InlineContextStack::empty() const { return stk_.empty(); }
InlineContext &InlineContextStack::back() { return stk_.back(); }
const InlineContext &InlineContextStack::back() const { return stk_.back(); }
const InlineContext &InlineContextStack::back(const uint8_t offset) const {
  ConstReverseIterator itr = stk_.rbegin();
  for (uint8_t i = 0; i < offset; i++) itr++;
  TREE_SITTER_MARKDOWN_ASSERT(itr != stk_.rend());
  return *itr;
}

void InlineContextStack::clear() { stk_.clear(); }

void InlineContextStack::push(const InlineDelimiterList::Iterator dlm_itr) {
  if (empty()) {
    stk_.push_back(InlineContext(dlm_itr));
  } else {
    stk_.push_back(InlineContext(dlm_itr, back()));
  }
}
void InlineContextStack::pop() {
  TREE_SITTER_MARKDOWN_ASSERT(!empty());
  stk_.pop_back();
}
void InlineContextStack::pop_erase(InlineDelimiterList &inl_dlms) {
  TREE_SITTER_MARKDOWN_ASSERT(!empty());
  inl_dlms.erase(stk_.back().dlm_itr());
  stk_.pop_back();
}
void InlineContextStack::pop_yes() {
  TREE_SITTER_MARKDOWN_ASSERT(!stk_.back().dlm_itr()->yes());
  stk_.back().dlm_itr()->set_yes(true);
  pop();
}
void InlineContextStack::pop_paired(InlineDelimiter *const end_dlm) {
  TREE_SITTER_MARKDOWN_ASSERT(!stk_.back().dlm_itr()->has_end_dlm());
  end_dlm->set_yes(true);
  stk_.back().dlm_itr()->set_end_dlm(end_dlm);
  pop_yes();
}
void InlineContextStack::pop_paired(const InlineDelimiterList::Iterator end_dlm_itr) {
  pop_paired(&(*end_dlm_itr));
}
bool InlineContextStack::pop_all_lnk_bgn(InlineDelimiterList::Iterator &fst_pop_lnk_bgn_itr) {
  bool has_fst_pop_lnk_bgn = false;

  InlineDelimiter *img_bgn = NULL_PTR;
  InlineDelimiterCustomData lnk_bgn_cnt = 0;

  Iterator ctx_itr = stk_.begin();
  Iterator ctx_end = stk_.end();
  while (ctx_itr != ctx_end) {
    if (ctx_itr->dlm_itr()->sym() == SYM_LNK_BGN) {
      if (!has_fst_pop_lnk_bgn && img_bgn == NULL_PTR) {
        has_fst_pop_lnk_bgn = true;
        fst_pop_lnk_bgn_itr = ctx_itr->dlm_itr();
      }
      ctx_itr = stk_.erase(ctx_itr);
      lnk_bgn_cnt++;
    } else {
      if (lnk_bgn_cnt != 0 && img_bgn != NULL_PTR) {
        img_bgn->set_ctm_dat(img_bgn->ctm_dat() + lnk_bgn_cnt);
        lnk_bgn_cnt = 0;
        img_bgn = NULL_PTR;
      }
      if (ctx_itr->dlm_itr()->sym() == SYM_IMG_BGN) {
        img_bgn = &(*ctx_itr->dlm_itr());
      }
      ctx_itr++;
    }
  }
  if (lnk_bgn_cnt != 0 && img_bgn != NULL_PTR) {
    img_bgn->set_ctm_dat(img_bgn->ctm_dat() + lnk_bgn_cnt);
  }

  return has_fst_pop_lnk_bgn;
}

}
