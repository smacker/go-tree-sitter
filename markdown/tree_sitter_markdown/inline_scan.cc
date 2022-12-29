#include "./inline_scan.h"

#include "./block_scan.h"
#include "./inline_scan_util.generated.h"
#include "./predicate.h"
#include "./util.h"

#define VLD(SYM) vld_sym(SYM, blk_ctx_stk, inl_ctx_stk)
#define NXT_ITR(ITR) (++ITR, ITR--)

#define MAYBE_TBL_COL_SEP() (in_tbl && (lxr.lka_chr() == '|' || lxr.lka_chr() == '\\'))
#define DEFAULT_EXT_AUT_LNK_PAREN_BALANCE_COUNTER (INLINE_DELIMITER_CUSTOM_DATA_MAX / 2)

namespace tree_sitter_markdown {

bool is_in_tbl(const BlockContextStack &blk_ctx_stk) {
  if (blk_ctx_stk.empty()) return false;
  Symbol ctx_sym = blk_ctx_stk.back().sym();
  return ctx_sym == SYM_TBL_HED_ROW_BGN_MKR
      || ctx_sym == SYM_TBL_DLM_ROW_BGN_MKR
      || ctx_sym == SYM_TBL_DAT_ROW_BGN_MKR;
}

void scn_mid(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, InlineDelimiterList::Iterator &nxt_inl_dlm_itr, const InlineDelimiterList::Iterator &end_inl_dlm_itr, LexedIndex &end_idx, const bool shd_fsh_inl_ctx_stk) {
  lxr.adv_rpt(is_wsp_chr);
  while (lxr.cur_idx() < end_idx) {
    scn_inl(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr, end_inl_dlm_itr, end_idx, shd_fsh_inl_ctx_stk);
    lxr.adv_rpt(is_wsp_chr);
  }
}

Symbol scn_inl(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk) {
  TREE_SITTER_MARKDOWN_ASSERT(!is_wht_chr(lxr.lka_chr()));
  if (scn_blk_txt(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk)) return SYM_BLK_TXT;
  InlineDelimiterList::Iterator nxt_inl_dlm_itr = inl_dlms.end();
  InlineDelimiterList::Iterator end_inl_dlm_itr = inl_dlms.end();
  LexedIndex end_idx = LEXED_INDEX_MAX;
  return scn_inl(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr, end_inl_dlm_itr, end_idx, /*shd_fsh_inl_ctx_stk*/ true);
}

Symbol scn_inl(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, InlineDelimiterList::Iterator &nxt_inl_dlm_itr, const InlineDelimiterList::Iterator &end_inl_dlm_itr, LexedIndex &end_idx, const bool shd_fsh_inl_ctx_stk) {
  bool is_txt = true;
  bool is_invalid = false;

  bool is_fen_cod_inf = blk_ctx_stk.back().sym() == SYM_BTK_FEN_COD_BGN
                     || blk_ctx_stk.back().sym() == SYM_TLD_FEN_COD_BGN;
  if (is_fen_cod_inf) {
    is_txt = false;
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_FEN_COD_INF_BGN_MKR, lxr.cur_pos(), lxr.cur_pos()))
    );
  }

  for (bool is_fst_rnd = true; is_fst_rnd || !inl_ctx_stk.empty(); is_fst_rnd = false) {
    if (!is_fst_rnd && !is_fen_cod_inf) {
      blk_ctx_stk.mrk_has_fst_ctn();
    }

    bool is_end = is_eof_chr(lxr.lka_chr()) || lxr.cur_idx() >= end_idx;
    if (is_end || is_invalid) {
      if (is_end && !shd_fsh_inl_ctx_stk) break;
      is_invalid = false;
      hdl_unpaired_inl_dlm(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr, end_inl_dlm_itr);
      continue;
    }

    if (nxt_inl_dlm_itr != inl_dlms.end() && nxt_inl_dlm_itr->pos().idx() == lxr.cur_idx()) {
      if (nxt_inl_dlm_itr->has_end_dlm()) {
        InlineDelimiter *nxt_dlm_end_dlm = nxt_inl_dlm_itr->end_dlm();
        lxr.jmp_pos(nxt_dlm_end_dlm->end_pos());
        while (&(*nxt_inl_dlm_itr) != nxt_dlm_end_dlm) nxt_inl_dlm_itr++;
      } else {
        lxr.jmp_pos(nxt_inl_dlm_itr->end_pos());
      }
      nxt_inl_dlm_itr++;
      continue;
    }

    if (
      hdl_lnk_dst_imp_bgn_mkr(lxr, inl_dlms, inl_ctx_stk, nxt_inl_dlm_itr)
      || hdl_lnk_dst_imp_end_mkr(lxr, inl_dlms, inl_ctx_stk, nxt_inl_dlm_itr)
      || hdl_htm_atr_uqt_bgn_mkr(lxr, inl_dlms, inl_ctx_stk, nxt_inl_dlm_itr)
      || hdl_htm_atr_uqt_end_mkr(lxr, inl_dlms, inl_ctx_stk, nxt_inl_dlm_itr)
    ) {
      TREE_SITTER_MARKDOWN_ASSERT(!is_txt);
      continue;
    }

    if (is_lbk_chr(lxr.lka_chr())) {
      if (VLD(SYM_FEN_COD_INF_END_MKR)) {
        inl_ctx_stk.pop_paired(
          inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_FEN_COD_INF_END_MKR, lxr.cur_pos(), lxr.cur_pos()))
        );
        continue;
      }
      if (VLD(SYM_LIT_LBK)) {
        BlockDelimiter *lit_brk = blk_dlms.lit_lbk(lxr.cur_row());
        if (lit_brk == NULL_PTR) {
          LexedIndex lbk_bgn_idx = lxr.cur_idx();
          if (scn_eol(lxr, blk_dlms, blk_ctx_stk)) {
            end_idx = lbk_bgn_idx;
          } else if (blk_dlms.back().sym() == SYM_LIT_LBK) {
            lxr.jmp_pos(blk_dlms.back().end_pos());
          } else {
            is_invalid = true;
          }
        } else if (lit_brk->sym() != SYM_LIT_LBK) {
          end_idx = lxr.cur_idx();
        } else if (lit_brk->has_pos()) {
          lxr.jmp_pos(lit_brk->end_pos());
        } else {
          LexedPosition bgn_pos = lxr.cur_pos();
          lxr.adv_len(lit_brk->len());
          lit_brk->set_pos(bgn_pos, lxr.cur_pos());
        }
      } else {
        is_invalid = true;
      }
      continue;
    }

    if (scn_ext_aut_lnk(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)) {
      is_txt = false;
      continue;
    }

    if (
      scn_inl_amp(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_asr(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_bng(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_bsl(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr, end_idx)
      || scn_inl_btk(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_cln(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_dqt(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_eql(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_hsh(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_hyp(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_lbt(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_lng(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_lpr(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_pip(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr, end_idx)
      || scn_inl_qus(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_rbt(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_rng(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_rpr(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_slh(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_sqt(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_tld(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_inl_usc(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
    ) {
      is_txt = false;
      continue;
    }

    if (VLD(SYM_WSP) && lxr.adv_rpt(is_wsp_chr)) {
      is_txt = false;
      continue;
    }

    if (scn_inl_txt(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)) {
      continue;
    }

    is_invalid = true;
  }

  if (!is_fen_cod_inf) {
    blk_ctx_stk.mrk_has_fst_ctn();
  }

  return is_txt ? SYM_TXT : inl_dlms.front().sym();
}

bool scn_blk_txt(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk) {
  if (!vld_sym(SYM_BLK_TXT, blk_ctx_stk)) return false;
  if (
    !blk_ctx_stk.back().has_fst_ctn()
    && (blk_ctx_stk.back().sym() == SYM_BTK_FEN_COD_BGN
      || blk_ctx_stk.back().sym() == SYM_TLD_FEN_COD_BGN)
  ) return false; // scan info string first

  Symbol ctx_sym = blk_ctx_stk.back().sym();

  if (
    ctx_sym == SYM_IND_COD_BGN_MKR
    || ctx_sym == SYM_BTK_FEN_COD_BGN
    || ctx_sym == SYM_TLD_FEN_COD_BGN
    || ctx_sym == SYM_HTM_BLK_DIV_BGN_MKR
    || ctx_sym == SYM_HTM_BLK_CMP_BGN_MKR
  ) {
    while (!is_eol_chr(lxr.lka_chr())) lxr.adv();
    lxr.mrk_end();
    return true;
  }

  if (ctx_sym == SYM_HTM_BLK_SCR_BGN_MKR) {
    bool has_end = false;
    while (!is_eol_chr(lxr.lka_chr())) {
      if (!has_end && lxr.lka_chr() == '<') {
        has_end = adv_blk_htm_end(lxr);
        continue;
      }
      if (!is_wht_chr(lxr.lka_chr())) {
        lxr.adv();
        continue;
      }
      lxr.adv_rpt(is_wsp_chr);
    }
    lxr.mrk_end();
    if (has_end) {
      TREE_SITTER_MARKDOWN_ASSERT(blk_dlms.empty());
      blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_SCR_END_MKR, lxr.cur_pos(), lxr.cur_pos()));
    }
    return true;
  }

  if (ctx_sym == SYM_HTM_BLK_CMT_BGN_MKR) {
    bool has_end = false;
    while (!is_eol_chr(lxr.lka_chr())) {
      if (!has_end && lxr.adv_if('-')) {
        if (lxr.adv_if('-')) {
          lxr.adv_rpt('-');
          if (lxr.adv_if('>')) has_end = true;
        }
        continue;
      }
      if (!is_wht_chr(lxr.lka_chr())) {
        lxr.adv();
        continue;
      }
      lxr.adv_rpt(is_wsp_chr);
    }
    lxr.mrk_end();
    if (has_end) {
      TREE_SITTER_MARKDOWN_ASSERT(blk_dlms.empty());
      blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_CMT_END_MKR, lxr.cur_pos(), lxr.cur_pos()));
    }
    return true;
  }

  if (ctx_sym == SYM_HTM_BLK_PRC_BGN_MKR) {
    bool has_end = false;
    while (!is_eol_chr(lxr.lka_chr())) {
      if (!has_end && lxr.adv_rpt('?')) {
        if (lxr.adv_if('>')) has_end = true;
        continue;
      }
      if (!is_wht_chr(lxr.lka_chr())) {
        lxr.adv();
        continue;
      }
      lxr.adv_rpt(is_wsp_chr);
    }
    lxr.mrk_end();
    if (has_end) {
      TREE_SITTER_MARKDOWN_ASSERT(blk_dlms.empty());
      blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_PRC_END_MKR, lxr.cur_pos(), lxr.cur_pos()));
    }
    return true;
  }

  if (ctx_sym == SYM_HTM_BLK_DCL_BGN_MKR) {
    bool has_end = false;
    while (!is_eol_chr(lxr.lka_chr())) {
      if (!has_end && lxr.adv_if('>')) {
        has_end = true;
        continue;
      }
      if (!is_wht_chr(lxr.lka_chr())) {
        lxr.adv();
        continue;
      }
      lxr.adv_rpt(is_wsp_chr);
    }
    lxr.mrk_end();
    if (has_end) {
      TREE_SITTER_MARKDOWN_ASSERT(blk_dlms.empty());
      blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_DCL_END_MKR, lxr.cur_pos(), lxr.cur_pos()));
    }
    return true;
  }

  if (ctx_sym == SYM_HTM_BLK_CDA_BGN_MKR) {
    bool has_end = false;
    while (!is_eol_chr(lxr.lka_chr())) {
      if (!has_end && lxr.adv_if(']')) {
        if (lxr.adv_rpt(']')) {
          if (lxr.adv_if('>')) has_end = true;
        }
        continue;
      }
      if (!is_wht_chr(lxr.lka_chr())) {
        lxr.adv();
        continue;
      }
      lxr.adv_rpt(is_wsp_chr);
    }
    lxr.mrk_end();
    if (has_end) {
      TREE_SITTER_MARKDOWN_ASSERT(blk_dlms.empty());
      blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_CDA_END_MKR, lxr.cur_pos(), lxr.cur_pos()));
    }
    return true;
  }

  TREE_SITTER_MARKDOWN_ASSERT(false);
}

struct ExtendedAutolinkDomainSegment {
private:
  bool has_usc_;
  LexedPosition end_pos_;
public:
  bool has_usc() const { return has_usc_; }
  LexedPosition end_pos() const { return end_pos_; }
  ExtendedAutolinkDomainSegment(bool has_usc, LexedPosition end_pos):
    has_usc_(has_usc), end_pos_(end_pos) {}
};

bool scn_ext_aut_lnk_vld_dmn(Lexer &lxr) {
  std::vector<ExtendedAutolinkDomainSegment> segs;
  bool has_dot = false;
  for (;;) {
    bool has_ctn = false;
    bool has_usc = false;
    while (is_asc_ltr_chr(lxr.lka_chr()) || is_num_chr(lxr.lka_chr()) || lxr.lka_chr() == '_' || lxr.lka_chr() == '-') {
      if (lxr.lka_chr() == '_') has_usc = true;
      lxr.adv();
      has_ctn = true;
    }
    if (!has_ctn) {
      if (has_dot) lxr.jmp_pos(lxr.cur_pos().clone_add(-1));
      break;
    }
    segs.push_back(ExtendedAutolinkDomainSegment(has_usc, lxr.cur_pos()));
    if (!lxr.adv_if('.')) break;
    has_dot = true;
  }
  // no underscores may be present in the last two segments of the domain.
  for (;;) {
    while (!segs.empty() && segs.back().has_usc()) segs.pop_back();
    if (segs.size() >= 2 && segs[segs.size() - 2].has_usc()) {
      segs.pop_back();
      segs.pop_back();
      if (!segs.empty()) continue;
    }
    break;
  }
  if (segs.size() < 2) return false;
  lxr.jmp_pos(segs.back().end_pos());
  return true;
}

bool scn_ext_aut_lnk(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (VLD(SYM_EXT_AUT_LNK_CTN)) {
    LexedPosition bgn_pos = lxr.cur_pos();
    bool in_tbl = is_in_tbl(blk_ctx_stk);
    InlineDelimiterList::Iterator ctx_itr = inl_ctx_stk.back().dlm_itr();
    while (
      (nxt_inl_dlm_itr == inl_dlms.end() || lxr.cur_idx() < nxt_inl_dlm_itr->pos().idx())
      && !is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '<' && !MAYBE_TBL_COL_SEP()
    ) {
      if (lxr.lka_chr() == '(') {
        ctx_itr->set_ctm_dat(ctx_itr->ctm_dat() - 1);
      } else if (lxr.lka_chr() == ')') {
        ctx_itr->set_ctm_dat(ctx_itr->ctm_dat() + 1);
      }
      lxr.adv();
    }

    if (bgn_pos.dist(lxr.cur_pos()) == 0) {
      if (MAYBE_TBL_COL_SEP()) return false;
      inl_ctx_stk.pop_paired(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_EXT_AUT_LNK_END_MKR, bgn_pos, bgn_pos))
      );
      return true;
    }

    if (MAYBE_TBL_COL_SEP()) {
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_EXT_AUT_LNK_CTN, bgn_pos, lxr.cur_pos()));
    } else {
      LexedIndex end_idx = lxr.cur_idx();
      while (
        lxr.has_chr_at_idx('?', end_idx)
        || lxr.has_chr_at_idx('!', end_idx)
        || lxr.has_chr_at_idx('.', end_idx)
        || lxr.has_chr_at_idx(',', end_idx)
        || lxr.has_chr_at_idx(':', end_idx)
        || lxr.has_chr_at_idx('*', end_idx)
        || lxr.has_chr_at_idx('_', end_idx)
        || lxr.has_chr_at_idx('~', end_idx)
      ) end_idx--;
      if (ctx_itr->ctm_dat() > DEFAULT_EXT_AUT_LNK_PAREN_BALANCE_COUNTER) {
        InlineDelimiterCustomData unpaired_lpr_cnt = ctx_itr->ctm_dat() - DEFAULT_EXT_AUT_LNK_PAREN_BALANCE_COUNTER;
        while (unpaired_lpr_cnt && lxr.has_chr_at_idx(')', end_idx)) {
          end_idx--;
          unpaired_lpr_cnt--;
        }
      }
      if (lxr.has_chr_at_idx(';', end_idx)) {
        LexedIndex offset = 1;
        while (lxr.has_chr_at_idx(is_asc_ltr_chr, end_idx - offset) || lxr.has_chr_at_idx(is_num_chr, end_idx - offset)) offset++;
        if (offset > 1 && lxr.has_chr_at_idx('&', end_idx - offset)) end_idx -= offset;
      }
      LexedPosition end_pos = lxr.cur_pos().clone_add(end_idx - lxr.cur_idx());
      if (bgn_pos.dist(end_pos) != 0) {
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_EXT_AUT_LNK_CTN, bgn_pos, end_pos));
      }
      inl_ctx_stk.pop_paired(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_EXT_AUT_LNK_END_MKR, end_pos, end_pos))
      );
      lxr.jmp_pos(end_pos);
    }
    return true;
  }
  if (VLD(SYM_EXT_AUT_LNK_BGN) && is_ext_aut_lnk_bgn(lxr.cur_chr(), lxr.lka_chr())) {
    LexedPosition bgn_pos = lxr.cur_pos();
    bool has_usc = false;
    LexedPosition fst_usc_pos;
    if (lxr.adv_if('h')) {
      if (lxr.adv_if('t')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('p')) {
            lxr.adv_if('s');
            LexedPosition cln_bgn_pos = lxr.cur_pos();
            if (lxr.adv_if(':')) {
              if (lxr.adv_if('/')) {
                if (lxr.adv_if('/')) {
                  if (scn_ext_aut_lnk_vld_dmn(lxr)) {
                    inl_ctx_stk.push(inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_EXT_URL_AUT_LNK_BGN_MKR, bgn_pos, bgn_pos)));
                    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_EXT_AUT_LNK_CTN, bgn_pos, lxr.cur_pos()));
                    inl_ctx_stk.back().dlm_itr()->set_ctm_dat(DEFAULT_EXT_AUT_LNK_PAREN_BALANCE_COUNTER);
                    return true;
                  }
                }
              }
              lxr.jmp_pos(cln_bgn_pos);
              inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_EXT_AUT_LNK_BGN, bgn_pos, lxr.cur_pos()));
              return true;
            }
          }
        }
      }
    } else if (lxr.adv_if('w')) {
      if (lxr.adv_if('w')) {
        if (lxr.adv_if('w')) {
          if (lxr.adv_if('.')) {
            if (scn_ext_aut_lnk_vld_dmn(lxr)) {
              inl_ctx_stk.push(inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_EXT_WWW_AUT_LNK_BGN_MKR, bgn_pos, bgn_pos)));
              inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_EXT_AUT_LNK_CTN, bgn_pos, lxr.cur_pos()));
              inl_ctx_stk.back().dlm_itr()->set_ctm_dat(DEFAULT_EXT_AUT_LNK_PAREN_BALANCE_COUNTER);
              return true;
            }
          }
        }
      }
    }

    while (is_asc_ltr_chr(lxr.lka_chr()) || is_num_chr(lxr.lka_chr()) || lxr.lka_chr() == '.' || lxr.lka_chr() == '-' || lxr.lka_chr() == '_' || lxr.lka_chr() == '+') {
      if (!has_usc && lxr.lka_chr() == '_') {
        has_usc = true;
        fst_usc_pos.set(lxr.cur_pos());
      }
      lxr.adv();
    }

    if (bgn_pos.dist(lxr.cur_pos()) == 0) return false;

    if (lxr.adv_if('@')) {
      uint16_t seg_cnt = 0;
      for (;;) {
        bool has_ctn = false;
        while (is_asc_ltr_chr(lxr.lka_chr()) || is_num_chr(lxr.lka_chr()) || lxr.lka_chr() == '_' || lxr.lka_chr() == '-') {
          if (!has_usc && lxr.lka_chr() == '_') {
            has_usc = true;
            fst_usc_pos.set(lxr.cur_pos());
          }
          lxr.adv();
          has_ctn = true;
        }
        if (!has_ctn) {
          if (seg_cnt) lxr.jmp_pos(lxr.cur_pos().clone_add(-1));
          break;
        }
        seg_cnt++;
        if (!lxr.adv_if('.')) break;
      }
      if (seg_cnt >= 2 && lxr.cur_chr() != '-' && lxr.cur_chr() != '_') {
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_EXT_EML_AUT_LNK_BGN_MKR, bgn_pos, bgn_pos));
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_EXT_AUT_LNK_CTN, bgn_pos, lxr.cur_pos()));
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_EXT_AUT_LNK_END_MKR, lxr.cur_pos(), lxr.cur_pos()));
        return true;
      }
    }

    if (has_usc) lxr.jmp_pos(fst_usc_pos);
    LexedPosition end_pos = lxr.cur_pos();
    if (bgn_pos.dist(end_pos) == 0) {
      TREE_SITTER_MARKDOWN_ASSERT(has_usc);
      return false;
    }
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_EXT_AUT_LNK_BGN, bgn_pos, end_pos));
    return true;
  }
  return false;
}

bool scn_inl_amp(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '&' || !VLD(SYM_CHR_REF)) return false;

  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();
  LexedPosition amp_end_pos = lxr.cur_pos();

  LexedLength dec_ref_len = 0;
  LexedLength hex_ref_len = 0;
  LexedLength ent_ref_len = 0;

  if (lxr.adv_if('#')) {
    if (is_num_chr(lxr.lka_chr())) {
      // decimal numeric character references
      dec_ref_len = lxr.adv_rpt_len(is_num_chr, 7) + 1;
    } else if (lxr.adv_if('x') || lxr.adv_if('X')) {
      // hexadecimal numeric character references
      if (is_hex_chr(lxr.lka_chr())) {
        hex_ref_len = lxr.adv_rpt_len(is_hex_chr, 6) + 2;
      }
    }
  } else {
    // entity references
    adv_inl_ent_ref_nam(lxr, ent_ref_len);
  }

  LexedLength ref_len = bgn_pos.dist(lxr.cur_pos()) - 1;

  if (ref_len == 0) {
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_CHR_REF, bgn_pos, amp_end_pos));
    return true;
  }

  if (
    (ref_len == dec_ref_len || ref_len == hex_ref_len || ref_len == ent_ref_len)
    && lxr.adv_if(';')
  ) {
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_CHR_REF, bgn_pos, lxr.cur_pos()));
  } else {
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_CHR_REF, bgn_pos, amp_end_pos));
    lxr.jmp_pos(amp_end_pos);
  }

  return true;
}

bool scn_inl_asr(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  return scn_dlm_run('*', SYM_ASR_BGN, SYM_ASR_END, can_opn_asr, can_cls_asr, &InlineContext::has_asr, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr);
}

bool scn_inl_bng(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '!' || !VLD(SYM_IMG_BGN)) return false;
  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();
  if (lxr.adv_if('[')) {
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_IMG_BGN, bgn_pos, lxr.cur_pos()))
    );
  } else {
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_IMG_BGN, bgn_pos, lxr.cur_pos()));
  }
  return true;
}

bool scn_inl_bsl(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr, LexedIndex &end_idx) {
  if (lxr.lka_chr() != '\\') return false;
  bool in_tbl = is_in_tbl(blk_ctx_stk);
  if (VLD(SYM_BSL_ESC)) {
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    if (lxr.adv_if(is_asc_pun_chr)) {
      if (lxr.cur_chr() == '\\' && lxr.lka_chr() == '|' && in_tbl) lxr.adv();
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_BSL_ESC, bgn_pos, lxr.cur_pos()));
    } else if (VLD(SYM_BSL_LBK) && !in_tbl && is_lbk_chr(lxr.lka_chr())) {
      LexedPosition bsl_end_pos = lxr.cur_pos();
      BlockDelimiter *lit_brk = blk_dlms.lit_lbk(lxr.cur_row());
      if (lit_brk == NULL_PTR) {
        if (scn_eol(lxr, blk_dlms, blk_ctx_stk)) {
          inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_BSL_LBK, bgn_pos, bsl_end_pos));
          end_idx = bgn_pos.idx();
        } else {
          TREE_SITTER_MARKDOWN_ASSERT(blk_dlms.back().sym() == SYM_LIT_LBK);
          inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_BSL_LBK, bgn_pos, bsl_end_pos));
          lxr.jmp_pos(blk_dlms.back().end_pos());
        }
      } else if (lit_brk->sym() != SYM_LIT_LBK) {
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_BSL_LBK, bgn_pos, bsl_end_pos));
      } else {
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_BSL_LBK, bgn_pos, bsl_end_pos));
      }
    } else {
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_BSL_ESC, bgn_pos, lxr.cur_pos()));
    }
    return true;
  }
  if (in_tbl && !inl_ctx_stk.empty()) {
    Symbol ctx_sym = inl_ctx_stk.back().dlm_itr()->sym();
    if (
      ctx_sym == SYM_COD_SPN_BGN
      || ctx_sym == SYM_EXT_WWW_AUT_LNK_BGN_MKR
      || ctx_sym == SYM_EXT_URL_AUT_LNK_BGN_MKR
      || ctx_sym == SYM_URI_AUT_LNK_BGN
      || ctx_sym == SYM_EML_AUT_LNK_BGN
      || ctx_sym == SYM_HTM_DCL_NAM_END_MKR
      || ctx_sym == SYM_HTM_ATR_EQL
      || ctx_sym == SYM_HTM_ATR_UQT_BGN_MKR
      || ctx_sym == SYM_HTM_ATR_SQT_BGN
      || ctx_sym == SYM_HTM_ATR_DQT_BGN
      || ctx_sym == SYM_HTM_CMT_BGN
      || ctx_sym == SYM_HTM_PRC_BGN
      || ctx_sym == SYM_HTM_CDA_BGN
    ) {
      LexedPosition bgn_pos = lxr.cur_pos();
      lxr.adv();
      if (ctx_sym == SYM_HTM_ATR_EQL) {
        inl_ctx_stk.pop_yes();
        inl_ctx_stk.push(
          inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_ATR_UQT_BGN_MKR, bgn_pos, bgn_pos))
        );
      }
      if (lxr.adv_if('|')) {
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_BSL_ESC, bgn_pos, lxr.cur_pos()));
      } else if (ctx_sym == SYM_EML_AUT_LNK_BGN) {
        inl_ctx_stk.push(
          inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_EML_AUT_LNK_IVD_MKR, bgn_pos, bgn_pos))
        );
        TREE_SITTER_MARKDOWN_ASSERT(!inl_ctx_stk.back().is_vld_pst());
      } else {
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_BSL_ESC, bgn_pos, lxr.cur_pos()));
      }
      return true;
    }
  }
  return false;
}

bool scn_inl_btk(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '`' || !(VLD(SYM_COD_SPN_BGN) || VLD(SYM_COD_SPN_END))) return false;
  LexedPosition bgn_pos = lxr.cur_pos();
  LexedLength btk_len = lxr.adv_rpt_len('`');
  LexedPosition end_pos = lxr.cur_pos();
  if (VLD(SYM_COD_SPN_BGN)) {
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_COD_SPN_BGN, bgn_pos, end_pos))
    );
  } else {
    TREE_SITTER_MARKDOWN_ASSERT(!inl_ctx_stk.empty());
    if (inl_ctx_stk.back().btk_len() == btk_len) {
      inl_ctx_stk.pop_paired(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_COD_SPN_END, bgn_pos, end_pos))
      );
    } else {
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_COD_SPN_END, bgn_pos, end_pos));
    }
  }
  return true;
}

bool scn_inl_cln(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != ':') return false;
  if (VLD(SYM_LNK_REF_DEF_CLN)) {
    InlineDelimiterList::Iterator lnk_end_itr = inl_ctx_stk.back().dlm_itr();
    TREE_SITTER_MARKDOWN_ASSERT(lnk_end_itr->sym() == SYM_LNK_END);

    InlineDelimiterList::Iterator lnk_bgn_itr = inl_ctx_stk.back(1).dlm_itr();
    if (lnk_bgn_itr->sym() != SYM_LNK_BGN) return false;

    bool is_in_pgh = blk_ctx_stk.back().sym() == SYM_PGH_BGN_MKR;
    bool is_fst_inl_nod = lnk_bgn_itr->ctm_dat();
    bool is_vld_lnk_lbl = lnk_end_itr->ctm_dat();

    if (!is_in_pgh || !is_vld_lnk_lbl || !is_fst_inl_nod) return false;

    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();

    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_REF_DEF_CLN, bgn_pos, lxr.cur_pos()))
    );

    return true;
  }
  if (VLD(SYM_TBL_COL_ALN)) {
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    lxr.adv_rpt('-');
    lxr.adv_if(':');
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_TBL_COL_ALN, bgn_pos, lxr.cur_pos()));
    return true;
  }
  return false;
}

bool scn_inl_dqt(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  return scn_lnk_tit_bgn('"', SYM_LNK_TIT_DQT_BGN, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_lnk_tit_end('"', SYM_LNK_TIT_DQT_BGN, SYM_LNK_TIT_DQT_END, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_htm_atr_val_bgn('"', SYM_HTM_ATR_DQT_BGN, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_htm_atr_val_end('"', SYM_HTM_ATR_DQT_BGN, SYM_HTM_ATR_DQT_END, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr);
}

bool scn_inl_eql(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '=' || !VLD(SYM_HTM_ATR_EQL)) return false;
  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();
  LexedPosition end_pos = lxr.cur_pos();
  TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_ATR_KEY_END_MKR);
  inl_ctx_stk.pop_erase(inl_dlms);
  inl_ctx_stk.push(
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_ATR_EQL, bgn_pos, end_pos))
  );
  return true;
}

bool scn_inl_hsh(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '#' || !VLD(SYM_ATX_END)) return false;
  if (!is_wsp_chr(lxr.cur_chr())) return false;
  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv_rpt('#');
  LexedPosition end_pos = lxr.cur_pos();
  lxr.adv_rpt(is_wsp_chr);
  inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(is_eol_chr(lxr.lka_chr()), SYM_ATX_END, bgn_pos, end_pos));
  return true;
}

bool scn_inl_hyp(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '-') return false;
  if (VLD(SYM_HTM_CMT_END)) {
    LexedPosition bgn_pos = lxr.cur_pos();
    LexedLength hyp_len = lxr.adv_rpt_len('-', 3);
    lxr.adv_rpt('-');
    if (hyp_len == 2 && lxr.adv_if('>')) {
      TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_CMT_BGN);
      inl_ctx_stk.pop_paired(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_HTM_CMT_END, bgn_pos, lxr.cur_pos()))
      );
    } else if (hyp_len >= 2) {
      inl_ctx_stk.push(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_CMT_END, bgn_pos, lxr.cur_pos()))
      );
      TREE_SITTER_MARKDOWN_ASSERT(!inl_ctx_stk.back().is_vld_pst());
    } else {
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_CMT_END, bgn_pos, lxr.cur_pos()));
    }
    return true;
  }
  if (VLD(SYM_TBL_COL_ALN)) {
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv_rpt('-');
    lxr.adv_if(':');
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_TBL_COL_ALN, bgn_pos, lxr.cur_pos()));
    return true;
  }
  return false;
}

bool scn_inl_lbt(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '[') return false;
  BlockContextStack::ConstReverseIterator blk_ctx_itr = blk_ctx_stk.rbegin();
  if (
    blk_ctx_itr->sym() == SYM_PGH_BGN_MKR
    && !blk_ctx_itr->has_fst_ctn()
    && ++blk_ctx_itr != blk_ctx_stk.rend()
    && blk_ctx_itr->sym() == SYM_LST_ITM_CNT_BGN_MKR
  ) {
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    if (lxr.adv_if(' ') || lxr.adv_if('x') || lxr.adv_if('X')) {
      if (lxr.adv_if(']')) {
        LexedPosition end_pos = lxr.cur_pos();
        if (lxr.adv_rpt(is_wsp_chr) && !is_eol_chr(lxr.lka_chr())) {
          inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_LST_CHK_BOX, bgn_pos, end_pos));
          return true;
        }
      }
    }
    lxr.jmp_pos(bgn_pos);
  }
  if (VLD(SYM_LNK_BGN)) {
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    InlineDelimiterList::Iterator lnk_bgn_itr = inl_dlms.insert(
      nxt_inl_dlm_itr,
      InlineDelimiter(false, SYM_LNK_BGN, bgn_pos, lxr.cur_pos())
    );
    bool is_fst_inl_nod = !blk_ctx_stk.back().has_fst_ctn();
    lnk_bgn_itr->set_ctm_dat(is_fst_inl_nod);
    inl_ctx_stk.push(lnk_bgn_itr);
    return true;
  }
  if (VLD(SYM_LNK_REF_BGN)) {
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_END);
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_REF_BGN, bgn_pos, lxr.cur_pos()))
    );
    return true;
  }
  return false;
}

bool scn_inl_lng(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '<') return false;
  if (VLD(SYM_LNK_DST_EXP_BGN)) {
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_DST_EXP_BGN, bgn_pos, lxr.cur_pos()))
    );
    return true;
  }
  if (VLD(SYM_AUT_LNK_HTM_OPN_TAG_BGN)) {
    TREE_SITTER_MARKDOWN_ASSERT(
      VLD(SYM_HTM_CLS_TAG_BGN)
      && VLD(SYM_HTM_DCL_BGN)
      && VLD(SYM_HTM_CMT_BGN)
      && VLD(SYM_HTM_PRC_BGN)
      && VLD(SYM_HTM_CDA_BGN)
    );

    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    LexedPosition lng_end_pos = lxr.cur_pos();
    LexedPosition end_pos;

    Symbol rlt_sym = SYM_NOT_FOUND;

    if (lxr.adv_if('/')) {
      rlt_sym = SYM_HTM_CLS_TAG_BGN;
      end_pos = lxr.cur_pos();
    } else if (lxr.adv_if('?')) {
      rlt_sym = SYM_HTM_PRC_BGN;
      end_pos = lxr.cur_pos();
    } else if (lxr.adv_if('!')) {
      if (lxr.adv_if('-')) {
        if (lxr.adv_if('-') && lxr.lka_chr() != '>') {
          end_pos = lxr.cur_pos();
          if (!lxr.adv_if('-') || lxr.lka_chr() != '>') {
            rlt_sym = SYM_HTM_CMT_BGN;
          }
        }
      } else if (lxr.adv_if('[')) {
        if (
          lxr.adv_if('C')
          && lxr.adv_if('D')
          && lxr.adv_if('A')
          && lxr.adv_if('T')
          && lxr.adv_if('A')
          && lxr.adv_if('[')
        ) {
          rlt_sym = SYM_HTM_CDA_BGN;
          end_pos = lxr.cur_pos();
        }
      } else {
        rlt_sym = SYM_HTM_DCL_BGN;
        end_pos = lxr.cur_pos();
      }
    } else {
      rlt_sym = SYM_AUT_LNK_HTM_OPN_TAG_BGN;
      end_pos = lxr.cur_pos();
    }

    if (rlt_sym == SYM_NOT_FOUND) {
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_AUT_LNK_HTM_OPN_TAG_BGN, bgn_pos, lng_end_pos));
      lxr.jmp_pos(lng_end_pos);
    } else {
      inl_ctx_stk.push(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, rlt_sym, bgn_pos, end_pos))
      );
      lxr.jmp_pos(end_pos);
    }

    return true;
  }
  return false;
}

bool scn_inl_lpr(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '(') return false;
  if (VLD(SYM_LNK_INL_BGN)) {
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_END);
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_INL_BGN, bgn_pos, lxr.cur_pos()))
    );
    return true;
  }
  if (VLD(SYM_LNK_DST_IMP_PRN_BGN)) {
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_DST_IMP_PRN_BGN, bgn_pos, lxr.cur_pos()))
    );
    return true;
  }
  return scn_lnk_tit_bgn('(', SYM_LNK_TIT_PRN_BGN, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr);
}

bool scn_inl_pip(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr, LexedIndex &end_idx) {
  if (lxr.lka_chr() != '|' || !is_in_tbl(blk_ctx_stk)) return false;
  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();
  if (lxr.cur_chr() != '\\') {
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_TBL_COL_SEP, bgn_pos, lxr.cur_pos()));
    end_idx = bgn_pos.idx();
  } else {
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_TBL_COL_SEP, bgn_pos, lxr.cur_pos()));
  }
  return true;
}

bool scn_inl_qus(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '?' || !VLD(SYM_HTM_PRC_END)) return false;
  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();
  if (lxr.adv_if('>')) {
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_PRC_BGN);
    inl_ctx_stk.pop_paired(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_HTM_PRC_END, bgn_pos, lxr.cur_pos()))
    );
  } else {
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_PRC_END, bgn_pos, lxr.cur_pos()));
  }
  return true;
}

bool scn_inl_rbt(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != ']') return false;
  if (VLD(SYM_LNK_END)) {
    InlineDelimiterList::Iterator ctx_dlm_itr = inl_ctx_stk.back().dlm_itr();
    bool is_img = ctx_dlm_itr->sym() == SYM_IMG_BGN;
    bool is_lnk = ctx_dlm_itr->sym() == SYM_LNK_BGN;
    TREE_SITTER_MARKDOWN_ASSERT(is_img || is_lnk);

    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();

    if (is_img && ctx_dlm_itr->/*unpaired_lbt_cnt*/ctm_dat() != 0) {
      ctx_dlm_itr->set_ctm_dat(ctx_dlm_itr->ctm_dat() - 1);
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_END, bgn_pos, lxr.cur_pos()));
    } else {
      bool is_vld_lnk_lbl = ctx_dlm_itr->end_pos().idx() - bgn_pos.idx() <= 999
                         && lxr.has_chr_in_rng(is_non_wht_chr, ctx_dlm_itr->end_pos().idx() + 1, bgn_pos.idx() + 1);
      InlineDelimiterList::Iterator lnk_end_itr = inl_dlms.insert(
        nxt_inl_dlm_itr,
        InlineDelimiter(false, SYM_LNK_END, bgn_pos, lxr.cur_pos())
      );
      lnk_end_itr->set_ctm_dat(is_vld_lnk_lbl);
      inl_ctx_stk.push(lnk_end_itr);
    }

    return true;
  }
  if (VLD(SYM_LNK_REF_END)) {
    InlineDelimiterList::Iterator ctx_dlm_itr = inl_ctx_stk.back().dlm_itr();
    TREE_SITTER_MARKDOWN_ASSERT(ctx_dlm_itr->sym() == SYM_LNK_REF_BGN);

    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    LexedPosition end_pos = lxr.cur_pos();

    bool is_clp_ref = ctx_dlm_itr->end_pos().idx() - bgn_pos.idx() == 0;
    bool is_ful_ref = ctx_dlm_itr->end_pos().idx() - bgn_pos.idx() <= 999
                   && lxr.has_chr_in_rng(is_non_wht_chr, ctx_dlm_itr->end_pos().idx() + 1, bgn_pos.idx() + 1);

    InlineDelimiterList::Iterator lnk_end_itr = inl_ctx_stk.back(1).dlm_itr();
    TREE_SITTER_MARKDOWN_ASSERT(lnk_end_itr->sym() == SYM_LNK_END);

    bool is_lnk_frt_vlk_lnk_lbl = lnk_end_itr->ctm_dat();

    if (is_clp_ref ? !is_lnk_frt_vlk_lnk_lbl : !is_ful_ref) {
      inl_ctx_stk.push(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_REF_END, bgn_pos, end_pos))
      );
      TREE_SITTER_MARKDOWN_ASSERT(!inl_ctx_stk.back().is_vld_pst());
    } else {
      InlineDelimiterList::Iterator lnk_ref_end_itr = inl_dlms.insert(
        nxt_inl_dlm_itr,
        InlineDelimiter(true, SYM_LNK_REF_END, bgn_pos, end_pos)
      );
      inl_ctx_stk.pop_paired(lnk_ref_end_itr);
      hdl_paired_lnk_end(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk);
    }

    return true;
  }
  if (VLD(SYM_HTM_CDA_END)) {
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_CDA_BGN);
    LexedPosition bgn_pos = lxr.cur_pos();
    LexedLength rbt_len = lxr.adv_rpt_len(']');
    if (rbt_len > 2 && lxr.adv_if('>')) {
      LexedPosition txt_end_pos = lxr.cur_pos(-3);
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_CDA_END, bgn_pos, txt_end_pos));
      inl_ctx_stk.pop_paired(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_HTM_CDA_END, txt_end_pos, lxr.cur_pos()))
      );
    } else if (rbt_len == 2 && lxr.adv_if('>')) {
      inl_ctx_stk.pop_paired(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_HTM_CDA_END, bgn_pos, lxr.cur_pos()))
      );
    } else {
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_CDA_END, bgn_pos, lxr.cur_pos()));
    }
    return true;
  }
  return false;
}

bool scn_inl_rng(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '>') return false;
  if (VLD(SYM_LNK_DST_EXP_END)) {
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_DST_EXP_BGN);
    InlineDelimiterList::Iterator lnk_end_nxt_itr = inl_ctx_stk.back(1).dlm_itr();
    TREE_SITTER_MARKDOWN_ASSERT(lnk_end_nxt_itr->sym() == SYM_LNK_INL_BGN || lnk_end_nxt_itr->sym() == SYM_LNK_REF_DEF_CLN);
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    LexedPosition end_pos = lxr.cur_pos();
    if (is_wht_chr(lxr.lka_chr()) || (lnk_end_nxt_itr->sym() == SYM_LNK_INL_BGN && lxr.lka_chr() == ')')) {
      inl_ctx_stk.pop_paired(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_LNK_DST_EXP_END, bgn_pos, end_pos))
      );
      inl_ctx_stk.push(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_DST_END_MKR, end_pos, end_pos))
      );
    } else {
      inl_ctx_stk.push(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_DST_EXP_END, bgn_pos, end_pos))
      );
      TREE_SITTER_MARKDOWN_ASSERT(!inl_ctx_stk.back().is_vld_pst());
    }
    return true;
  }
  if (VLD(SYM_AUT_LNK_END)) {
    if (inl_ctx_stk.back().dlm_itr()->sym() == SYM_EML_AUT_LNK_END_MKR) {
      inl_ctx_stk.pop_erase(inl_dlms);
    }
    TREE_SITTER_MARKDOWN_ASSERT(
      inl_ctx_stk.back().dlm_itr()->sym() == SYM_URI_AUT_LNK_BGN
      || inl_ctx_stk.back().dlm_itr()->sym() == SYM_EML_AUT_LNK_BGN
    );
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    inl_ctx_stk.pop_paired(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_AUT_LNK_END, bgn_pos, lxr.cur_pos()))
    );
    return true;
  }
  if (VLD(SYM_HTM_TAG_END)) {
    if (
      inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_ATR_KEY_END_MKR
      || inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_CLS_TAG_NAM_END_MKR
      || inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_DCL_NAM_END_MKR
    ) inl_ctx_stk.pop_erase(inl_dlms);
    TREE_SITTER_MARKDOWN_ASSERT(
      inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_OPN_TAG_BGN
      || inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_CLS_TAG_BGN
      || inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_DCL_BGN
    );
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    inl_ctx_stk.pop_paired(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_HTM_TAG_END, bgn_pos, lxr.cur_pos()))
    );
    return true;
  }
  return false;
}

bool scn_inl_rpr(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != ')') return false;
  if (VLD(SYM_LNK_INL_END) && !inl_ctx_stk.back().has_cln()) {
    if (
      inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_DST_END_MKR
      || inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_TIT_END_MKR
    ) inl_ctx_stk.pop_erase(inl_dlms);
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_INL_BGN);

    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();

    InlineDelimiterList::Iterator lnk_inl_end_itr = inl_dlms.insert(
      nxt_inl_dlm_itr,
      InlineDelimiter(true, SYM_LNK_INL_END, bgn_pos, lxr.cur_pos())
    );
    inl_ctx_stk.pop_paired(lnk_inl_end_itr);

    hdl_paired_lnk_end(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk);

    return true;
  }
  if (VLD(SYM_LNK_DST_IMP_PRN_END)) {
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_DST_IMP_PRN_BGN);
    inl_ctx_stk.pop();
    LexedPosition bgn_pos = lxr.cur_pos();
    lxr.adv();
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_DST_IMP_PRN_END, bgn_pos, lxr.cur_pos()));
    return true;
  }
  return scn_lnk_tit_end(')', SYM_LNK_TIT_PRN_BGN, SYM_LNK_TIT_PRN_END, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr);
}

bool scn_inl_slh(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '/' || !VLD(SYM_HTM_SLF_TAG_END)) return false;
  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();
  if (lxr.adv_if('>')) {
    if (
      inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_ATR_KEY_END_MKR
    ) inl_ctx_stk.pop_erase(inl_dlms);
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_OPN_TAG_BGN);
    inl_ctx_stk.pop_paired(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_HTM_SLF_TAG_END, bgn_pos, lxr.cur_pos()))
    );
  } else {
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_SLF_TAG_END, bgn_pos, lxr.cur_pos()))
    );
    TREE_SITTER_MARKDOWN_ASSERT(!inl_ctx_stk.back().is_vld_pst());
  }
  return true;
}

bool scn_inl_sqt(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  return scn_lnk_tit_bgn('\'', SYM_LNK_TIT_SQT_BGN, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_lnk_tit_end('\'', SYM_LNK_TIT_SQT_BGN, SYM_LNK_TIT_SQT_END, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_htm_atr_val_bgn('\'', SYM_HTM_ATR_SQT_BGN, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr)
      || scn_htm_atr_val_end('\'', SYM_HTM_ATR_SQT_BGN, SYM_HTM_ATR_SQT_END, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr);
}

bool scn_inl_tld(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (lxr.lka_chr() != '~') return false;

  bool vld_bgn = VLD(SYM_DEL_BGN);
  bool vld_end = VLD(SYM_DEL_END);

  if (!vld_bgn && !vld_end) return false;

  LexedPosition bgn_pos = lxr.cur_pos();
  LexedCharacter l_chr = lxr.cur_chr();
  LexedLength tld_len = lxr.adv_rpt_len('~');
  LexedCharacter r_chr = lxr.lka_chr();
  LexedPosition end_pos = lxr.cur_pos();

  bool can_opn = is_lfk_dlm_run(l_chr, r_chr);
  bool can_cls = is_rfk_dlm_run(l_chr, r_chr);

  if (can_cls && vld_end && tld_len == 2) {
    while (inl_ctx_stk.back().dlm_itr()->sym() != SYM_DEL_BGN) inl_ctx_stk.pop();
    inl_ctx_stk.pop_paired(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_DEL_END, bgn_pos, end_pos))
    );
  } else if (can_opn && vld_bgn && tld_len == 2) {
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_DEL_BGN, bgn_pos, end_pos))
    );
  } else {
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_DEL_BGN, bgn_pos, end_pos));
  }

  return true;
}

bool scn_inl_usc(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  return scn_dlm_run('_', SYM_USC_BGN, SYM_USC_END, can_opn_usc, can_cls_usc, &InlineContext::has_usc, lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr);
}

bool scn_inl_txt(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (is_wht_chr(lxr.lka_chr()) || !VLD(SYM_TXT)) return false;

  if (!inl_ctx_stk.empty()) {
    bool in_tbl = is_in_tbl(blk_ctx_stk);
    Symbol ctx_sym = inl_ctx_stk.back().dlm_itr()->sym();

    if (ctx_sym == SYM_LNK_DST_IMP_BGN_MKR || ctx_sym == SYM_LNK_DST_IMP_PRN_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '\\' && lxr.lka_chr() != '&' && lxr.lka_chr() != '(' && lxr.lka_chr() != ')' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_LNK_DST_EXP_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '\\' && lxr.lka_chr() != '&' && lxr.lka_chr() != '<' && lxr.lka_chr() != '>' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_LNK_TIT_SQT_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '\\' && lxr.lka_chr() != '&' && lxr.lka_chr() != '\'' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_LNK_TIT_DQT_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '\\' && lxr.lka_chr() != '&' && lxr.lka_chr() != '"' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_LNK_TIT_PRN_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '\\' && lxr.lka_chr() != '&' && lxr.lka_chr() != '(' && lxr.lka_chr() != ')' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_LNK_REF_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '\\' && lxr.lka_chr() != '[' && lxr.lka_chr() != ']' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_AUT_LNK_HTM_OPN_TAG_BGN) {
      return scn_aut_lnk_htm_opn_tag_txt(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, nxt_inl_dlm_itr);
    }
    if (ctx_sym == SYM_URI_AUT_LNK_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '<' && lxr.lka_chr() != '>' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_EML_AUT_LNK_BGN) {
      if (lxr.adv_if('@')) {
        if (!lxr.adv_if(is_aut_lnk_eml_dmn_sid_chr)) return false;
        if (lxr.adv_rpt_len(is_aut_lnk_eml_dmn_mid_chr, 61)) {
          if (is_aut_lnk_eml_dmn_sid_chr(lxr.lka_chr())) lxr.adv();
          else if (!is_aut_lnk_eml_dmn_sid_chr(lxr.cur_chr())) return false;
        }
        while (lxr.lka_chr() != '>') {
          if (!lxr.adv_if('.')) return false;
          if (!lxr.adv_if(is_aut_lnk_eml_dmn_sid_chr)) return false;
          if (lxr.adv_rpt_len(is_aut_lnk_eml_dmn_mid_chr, 61)) {
            if (is_aut_lnk_eml_dmn_sid_chr(lxr.lka_chr())) lxr.adv();
            else if (!is_aut_lnk_eml_dmn_sid_chr(lxr.cur_chr())) return false;
          }
        }
        inl_ctx_stk.push(
          inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_EML_AUT_LNK_END_MKR, lxr.cur_pos(), lxr.cur_pos()))
        );
        return true;
      } else {
        bool has_txt = false;
        while (
          (is_asc_ltr_chr(lxr.lka_chr()) || is_num_chr(lxr.lka_chr()) || lxr.lka_chr() == '-' || lxr.lka_chr() == '/'
            || lxr.lka_chr() == '!' || lxr.lka_chr() == '#' || lxr.lka_chr() == '$' || lxr.lka_chr() == '%'
            || lxr.lka_chr() == '&' || lxr.lka_chr() == '\'' || lxr.lka_chr() == '*' || lxr.lka_chr() == '='
            || lxr.lka_chr() == '?' || lxr.lka_chr() == '^' || lxr.lka_chr() == '_' || lxr.lka_chr() == '`'
            || lxr.lka_chr() == '{' || lxr.lka_chr() == '|' || lxr.lka_chr() == '}' || lxr.lka_chr() == '~')
          && !MAYBE_TBL_COL_SEP()
        ) {
          lxr.adv();
          has_txt = true;
        }
        return has_txt;
      }
    }
    if (ctx_sym == SYM_HTM_CLS_TAG_BGN) {
      if (lxr.adv_if(is_asc_ltr_chr)) {
        while (is_asc_ltr_chr(lxr.lka_chr()) || is_num_chr(lxr.lka_chr()) || lxr.lka_chr() == '-') lxr.adv();
        if (is_wht_chr(lxr.lka_chr()) || lxr.lka_chr() == '>') {
          inl_ctx_stk.push(
            inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_CLS_TAG_NAM_END_MKR, lxr.cur_pos(), lxr.cur_pos()))
          );
          return true;
        }
      }
      return false;
    }
    if (ctx_sym == SYM_HTM_DCL_BGN) {
      if (lxr.adv_if(is_upp_asc_ltr_chr)) {
        lxr.adv_rpt(is_upp_asc_ltr_chr);
        if (is_wht_chr(lxr.lka_chr())) {
          inl_ctx_stk.push(
            inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_DCL_NAM_END_MKR, lxr.cur_pos(), lxr.cur_pos()))
          );
          return true;
        }
      }
      return false;
    }
    if (ctx_sym == SYM_HTM_DCL_NAM_END_MKR) {
      if (lxr.lka_chr() != '>' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '>'&& !MAYBE_TBL_COL_SEP()) lxr.adv();
        return true;
      }
      return false;
    }
    if (ctx_sym == SYM_HTM_OPN_TAG_BGN || ctx_sym == SYM_HTM_ATR_KEY_END_MKR) {
      if (is_asc_ltr_chr(lxr.lka_chr()) || lxr.lka_chr() == '_' || lxr.lka_chr() == ':') {
        lxr.adv();
        while (is_asc_ltr_chr(lxr.lka_chr()) || is_num_chr(lxr.lka_chr()) || lxr.lka_chr() == '_' || lxr.lka_chr() == '.' || lxr.lka_chr() == ':' || lxr.lka_chr() == '-') lxr.adv();
        if (ctx_sym == SYM_HTM_ATR_KEY_END_MKR) {
          inl_ctx_stk.pop_erase(inl_dlms);
          TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_OPN_TAG_BGN);
        }
        inl_ctx_stk.push(
          inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_ATR_KEY_END_MKR, lxr.cur_pos(), lxr.cur_pos()))
        );
        return true;
      }
      return false;
    }
    if (ctx_sym == SYM_HTM_ATR_UQT_BGN_MKR) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '"' && lxr.lka_chr() != '\'' && lxr.lka_chr() != '=' && lxr.lka_chr() != '<' && lxr.lka_chr() != '>' && lxr.lka_chr() != '`' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_HTM_ATR_SQT_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '\'' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_HTM_ATR_DQT_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '"' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_HTM_CMT_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '-' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_HTM_PRC_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '?' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
    if (ctx_sym == SYM_HTM_CDA_BGN) {
      bool has_txt = false;
      while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != ']' && !MAYBE_TBL_COL_SEP()) {
        lxr.adv();
        has_txt = true;
      }
      return has_txt;
    }
  }

  lxr.adv();
  return true;
}

bool scn_aut_lnk_htm_opn_tag_txt(
  Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr
) {
  bool is_uri_aut_lnk = is_asc_ltr_chr(lxr.lka_chr());
  bool is_eml_aut_lnk = true;
  bool is_htm_opn_tag = is_asc_ltr_chr(lxr.lka_chr());

  uint16_t slh_cnt = 0;
  LexedIndex txt_len = 0;
  for (;; txt_len++, lxr.adv()) {
    if (is_asc_ltr_chr(lxr.lka_chr()) || is_num_chr(lxr.lka_chr()) || lxr.lka_chr() == '-');
    else if (lxr.lka_chr() == '+' || lxr.lka_chr() == '.') {
      is_htm_opn_tag = false;
    } else if (lxr.lka_chr() == '/') {
      slh_cnt++; // htm_opn_tag: slash is only allowed to be at the end of the text
      is_uri_aut_lnk = false;
    } else if (lxr.lka_chr() == '@' && txt_len == 0) {
      return false;
    } else if (
      lxr.lka_chr() == '\\'
      || lxr.lka_chr() == '!' || lxr.lka_chr() == '#' || lxr.lka_chr() == '$' || lxr.lka_chr() == '%'
      || lxr.lka_chr() == '&' || lxr.lka_chr() == '\'' || lxr.lka_chr() == '*' || lxr.lka_chr() == '='
      || lxr.lka_chr() == '?' || lxr.lka_chr() == '^' || lxr.lka_chr() == '_' || lxr.lka_chr() == '`'
      || lxr.lka_chr() == '{' || lxr.lka_chr() == '|' || lxr.lka_chr() == '}' || lxr.lka_chr() == '~'
    ) {
      TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_AUT_LNK_HTM_OPN_TAG_BGN);
      inl_ctx_stk.back().dlm_itr()->set_sym(SYM_EML_AUT_LNK_BGN);
      inl_ctx_stk.back().upd_pst();
      return true;
    } else break;
  }

  if (is_htm_opn_tag && txt_len >= 1 && (is_wht_chr(lxr.lka_chr()) || lxr.lka_chr() == '>' || (lxr.cur_chr() == '/' && slh_cnt == 1 && txt_len >= 2))) {
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_AUT_LNK_HTM_OPN_TAG_BGN);
    inl_ctx_stk.back().dlm_itr()->set_sym(SYM_HTM_OPN_TAG_BGN);
    inl_ctx_stk.back().upd_pst();
    if (lxr.cur_chr() == '/') lxr.jmp_pos(lxr.cur_pos().clone_add(-1));
    return true;
  }

  if (is_uri_aut_lnk && txt_len >= 2 && txt_len <= 32 && lxr.adv_if(':')) {
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_AUT_LNK_HTM_OPN_TAG_BGN);
    inl_ctx_stk.back().dlm_itr()->set_sym(SYM_URI_AUT_LNK_BGN);
    inl_ctx_stk.back().upd_pst();
    return true;
  }

  if (is_eml_aut_lnk && txt_len >= 1) {
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_AUT_LNK_HTM_OPN_TAG_BGN);
    inl_ctx_stk.back().dlm_itr()->set_sym(SYM_EML_AUT_LNK_BGN);
    inl_ctx_stk.back().upd_pst();
    return true;
  }

  return false;
}

bool scn_dlm_run(
  LexedCharacter dlm_chr, Symbol bgn_sym, Symbol end_sym, bool (*can_opn_dlm)(LexedCharacter, LexedCharacter), bool (*can_cls_dlm)(LexedCharacter, LexedCharacter), bool (InlineContext::*has_dlm)() const,
  Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr
) {
  const InlineDelimiterCustomData CAN_OPN_CLS_DLM_FLG = 1;

  bool vld_bgn = VLD(bgn_sym);
  bool vld_end = VLD(end_sym);

  if (lxr.lka_chr() != dlm_chr || !(vld_bgn || vld_end)) return false;

  LexedPosition bgn_pos = lxr.cur_pos();

  LexedCharacter l_chr = lxr.cur_chr();
  LexedLength run_len = lxr.adv_rpt_len(dlm_chr);
  LexedCharacter r_chr = lxr.lka_chr();

  bool can_opn = can_opn_dlm(l_chr, r_chr);
  bool can_cls = can_cls_dlm(l_chr, r_chr);

  if (vld_end && can_cls) {
    LexedLength rst_run_len = run_len;

    std::vector<InlineDelimiterList::Iterator> opn_dlm_itr_buf;

    bool in_1st_ctx = true;
    while (
      !inl_ctx_stk.empty()
      && (inl_ctx_stk.back().*has_dlm)()
      && rst_run_len
    ) {
      InlineDelimiterList::Iterator opn_dlm_itr = inl_ctx_stk.back().dlm_itr();

      if (opn_dlm_itr->sym() != bgn_sym) {
        inl_ctx_stk.pop();
        continue;
      }

      if (in_1st_ctx) {
        if (
          can_opn
          && (run_len + opn_dlm_itr->ori_len()) % 3 == 0
          && !(run_len % 3 == 0 && opn_dlm_itr->ori_len() % 3 == 0)
        ) break;
        in_1st_ctx = false;
      }

      if (
        opn_dlm_itr->ctm_dat() == CAN_OPN_CLS_DLM_FLG
        && (run_len + opn_dlm_itr->ori_len()) % 3 == 0
        && !(run_len % 3 == 0 && opn_dlm_itr->ori_len() % 3 == 0)
      ) {
        inl_ctx_stk.pop();
        continue;
      }

      InlineDelimiterList::Iterator opn_dlm_nxt_itr = NXT_ITR(opn_dlm_itr);
      LexedPosition opn_dlm_end_pos = opn_dlm_itr->end_pos();
      LexedLength cur_run_len = rst_run_len;

      if (opn_dlm_itr->len() > rst_run_len) {
        opn_dlm_itr->set_end_pos(opn_dlm_itr->end_pos().clone_add(-rst_run_len));
      } else if (opn_dlm_itr->len() == rst_run_len) {
        inl_dlms.erase(opn_dlm_itr);
        inl_ctx_stk.pop();
      } else {
        cur_run_len = opn_dlm_itr->len();
        inl_dlms.erase(opn_dlm_itr);
        inl_ctx_stk.pop();
      }

      for (LexedLength i = 0; i < cur_run_len / 2; i++) {
        opn_dlm_nxt_itr = inl_dlms.insert(
          opn_dlm_nxt_itr,
          InlineDelimiter(true, bgn_sym, opn_dlm_end_pos.clone_add(-2), opn_dlm_end_pos)
        );
        opn_dlm_end_pos.add(-2);
        opn_dlm_itr_buf.push_back(opn_dlm_nxt_itr);
      }

      if (cur_run_len % 2 == 1) {
        opn_dlm_nxt_itr = inl_dlms.insert(
          opn_dlm_nxt_itr,
          InlineDelimiter(true, bgn_sym, opn_dlm_end_pos.clone_add(-1), opn_dlm_end_pos)
        );
        opn_dlm_end_pos.add(-1);
        opn_dlm_itr_buf.push_back(opn_dlm_nxt_itr);
      }

      rst_run_len -= cur_run_len;
    }

    LexedLength act_run_len = run_len - rst_run_len;
    LexedPosition cls_dlm_bgn_pos = bgn_pos;

    for (
      std::vector<InlineDelimiterList::Iterator>::iterator
        opn_dlm_itr_itr = opn_dlm_itr_buf.begin(),
        opn_dlm_itr_buf_end_itr = opn_dlm_itr_buf.end();
      opn_dlm_itr_itr != opn_dlm_itr_buf_end_itr;
      opn_dlm_itr_itr++
    ) {
      InlineDelimiterList::Iterator opn_dlm_itr = *opn_dlm_itr_itr;
      InlineDelimiterList::Iterator cls_dlm_itr = inl_dlms.insert(
        nxt_inl_dlm_itr,
        InlineDelimiter(
          true,
          end_sym,
          cls_dlm_bgn_pos,
          cls_dlm_bgn_pos.clone_add(opn_dlm_itr->len())
        )
      );
      opn_dlm_itr->set_end_dlm(cls_dlm_itr);
      cls_dlm_bgn_pos.add(opn_dlm_itr->len());
    }
    opn_dlm_itr_buf.clear();

    if (rst_run_len) {
      LexedPosition rst_bgn_pos = bgn_pos.clone_add(act_run_len);
      InlineDelimiterList::Iterator rst_dlm_itr = inl_dlms.insert(
        nxt_inl_dlm_itr,
        InlineDelimiter(false, bgn_sym, rst_bgn_pos, rst_bgn_pos.clone_add(rst_run_len))
      );
      if (vld_bgn && can_opn) {
        rst_dlm_itr->set_ctm_dat(CAN_OPN_CLS_DLM_FLG);
        inl_ctx_stk.push(rst_dlm_itr);
      }
    }
  } else if (vld_bgn && can_opn) {
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, bgn_sym, bgn_pos, lxr.cur_pos()))
    );
  } else {
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, bgn_sym, bgn_pos, lxr.cur_pos()));
  }

  return true;
}

bool scn_lnk_tit_bgn(
  LexedCharacter dlm_chr, Symbol bgn_sym,
  Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr
) {
  if (lxr.lka_chr() != dlm_chr || !VLD(bgn_sym)) return false;
  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();
  inl_ctx_stk.push(
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, bgn_sym, bgn_pos, lxr.cur_pos()))
  );
  return true;
}

bool scn_lnk_tit_end(
  LexedCharacter dlm_chr, Symbol bgn_sym, Symbol end_sym,
  Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr
) {
  if (lxr.lka_chr() != dlm_chr || !VLD(end_sym)) return false;
  TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == bgn_sym);
  Symbol lnk_end_nxt_sym = inl_ctx_stk.back(2).dlm_itr()->sym();
  TREE_SITTER_MARKDOWN_ASSERT(lnk_end_nxt_sym == SYM_LNK_INL_BGN || lnk_end_nxt_sym == SYM_LNK_REF_DEF_CLN);
  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();
  LexedPosition end_pos = lxr.cur_pos();
  if (lnk_end_nxt_sym == SYM_LNK_REF_DEF_CLN) {
    lxr.adv_rpt(is_wsp_chr);
    if (is_eol_chr(lxr.lka_chr())) {
      inl_ctx_stk.pop_paired(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, end_sym, bgn_pos, end_pos))
      );
      hdl_paired_lnk_ref_def(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk);
      blk_dlms.push_back(
        BlockDelimiter(SYM_LNK_REF_DEF_END_MKR, lxr.cur_pos(), lxr.cur_pos())
      );
    } else {
      inl_ctx_stk.push(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, end_sym, bgn_pos, end_pos))
      );
      TREE_SITTER_MARKDOWN_ASSERT(!inl_ctx_stk.back().is_vld_pst());
    }
  } else {
    if (is_wht_chr(lxr.lka_chr()) || lxr.lka_chr() == ')') {
      inl_ctx_stk.pop_paired(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, end_sym, bgn_pos, end_pos))
      );
      TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_DST_END_MKR);
      inl_ctx_stk.pop_erase(inl_dlms);
      inl_ctx_stk.push(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_TIT_END_MKR, end_pos, end_pos))
      );
    } else {
      inl_ctx_stk.push(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, end_sym, bgn_pos, end_pos))
      );
      TREE_SITTER_MARKDOWN_ASSERT(!inl_ctx_stk.back().is_vld_pst());
    }
  }
  return true;
}

bool scn_htm_atr_val_bgn(
  LexedCharacter dlm_chr, Symbol bgn_sym,
  Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr
) {
  if (lxr.lka_chr() != dlm_chr || !VLD(bgn_sym)) return false;
  TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_HTM_ATR_EQL);
  inl_ctx_stk.pop_yes();
  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();
  inl_ctx_stk.push(
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, bgn_sym, bgn_pos, lxr.cur_pos()))
  );
  return true;
}

bool scn_htm_atr_val_end(
  LexedCharacter dlm_chr, Symbol bgn_sym, Symbol end_sym,
  Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr
) {
  if (lxr.lka_chr() != dlm_chr || !VLD(end_sym)) return false;
  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();
  if (is_wht_chr(lxr.lka_chr()) || lxr.lka_chr() == '/' || lxr.lka_chr() == '>') {
    TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == bgn_sym);
    inl_ctx_stk.pop_paired(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, end_sym, bgn_pos, lxr.cur_pos()))
    );
  } else {
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, end_sym, bgn_pos, lxr.cur_pos()))
    );
    TREE_SITTER_MARKDOWN_ASSERT(!inl_ctx_stk.back().is_vld_pst());
  }
  return true;
}

bool hdl_lnk_dst_imp_bgn_mkr(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (is_wht_chr(lxr.lka_chr()) || lxr.lka_chr() == '<' || inl_ctx_stk.empty()) return false;
  InlineDelimiterList::Iterator ctx_dlm_itr = inl_ctx_stk.back().dlm_itr();
  if (ctx_dlm_itr->sym() != SYM_LNK_INL_BGN && ctx_dlm_itr->sym() != SYM_LNK_REF_DEF_CLN) return false;
  inl_ctx_stk.push(
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_DST_IMP_BGN_MKR, lxr.cur_pos(), lxr.cur_pos()))
  );
  return true;
}

bool hdl_lnk_dst_imp_end_mkr(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (inl_ctx_stk.empty()) return false;
  InlineDelimiterList::Iterator ctx_dlm_itr = inl_ctx_stk.back().dlm_itr();
  if (ctx_dlm_itr->sym() != SYM_LNK_DST_IMP_BGN_MKR || ctx_dlm_itr->end_pos().dist(lxr.cur_pos()) == 0) return false;
  if (is_wht_chr(lxr.lka_chr()) || (inl_ctx_stk.back(1).dlm_itr()->sym() == SYM_LNK_INL_BGN && lxr.lka_chr() == ')')) {
    inl_ctx_stk.pop_paired(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_LNK_DST_IMP_END_MKR, lxr.cur_pos(), lxr.cur_pos()))
    );
    inl_ctx_stk.push(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_LNK_DST_END_MKR, lxr.cur_pos(), lxr.cur_pos()))
    );
    return true;
  }
  return false;
}

bool hdl_htm_atr_uqt_bgn_mkr(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (is_wht_chr(lxr.lka_chr()) || lxr.lka_chr() == '\'' || lxr.lka_chr() == '"' || inl_ctx_stk.empty() || inl_ctx_stk.back().dlm_itr()->sym() != SYM_HTM_ATR_EQL) return false;
  inl_ctx_stk.pop_yes();
  inl_ctx_stk.push(
    inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(false, SYM_HTM_ATR_UQT_BGN_MKR, lxr.cur_pos(), lxr.cur_pos()))
  );
  return true;
}

bool hdl_htm_atr_uqt_end_mkr(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, const InlineDelimiterList::Iterator &nxt_inl_dlm_itr) {
  if (inl_ctx_stk.empty()) return false;
  InlineDelimiterList::Iterator ctx_dlm_itr = inl_ctx_stk.back().dlm_itr();
  if (ctx_dlm_itr->sym() != SYM_HTM_ATR_UQT_BGN_MKR || ctx_dlm_itr->end_pos().dist(lxr.cur_pos()) == 0) return false;
  if (is_wht_chr(lxr.lka_chr()) || lxr.lka_chr() == '/' || lxr.lka_chr() == '>') {
    inl_ctx_stk.pop_paired(
      inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_HTM_ATR_UQT_END_MKR, lxr.cur_pos(), lxr.cur_pos()))
    );
    return true;
  }
  return false;
}

void hdl_paired_lnk_end(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk) {
  TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_END);
  LexedPosition ori_pos = lxr.cur_pos();

  InlineDelimiterList::Iterator lnk_end_itr = inl_ctx_stk.back().dlm_itr();
  inl_ctx_stk.pop();

  TREE_SITTER_MARKDOWN_ASSERT(!inl_ctx_stk.empty());

  bool is_img = inl_ctx_stk.back().dlm_itr()->sym() == SYM_IMG_BGN;
  bool is_lnk = inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_BGN;

  TREE_SITTER_MARKDOWN_ASSERT(is_img || is_lnk);

  InlineDelimiterList::Iterator lnk_bgn_itr = inl_ctx_stk.back().dlm_itr();
  inl_ctx_stk.pop_paired(lnk_end_itr);

  if (is_lnk) {
    InlineDelimiterList::Iterator fst_pop_lnk_bgn_itr;
    if (inl_ctx_stk.pop_all_lnk_bgn(fst_pop_lnk_bgn_itr)) {
      lxr.jmp_pos(fst_pop_lnk_bgn_itr->end_pos());
      InlineDelimiterList::Iterator sub_nxt_inl_dlm_itr = NXT_ITR(fst_pop_lnk_bgn_itr);
      LexedIndex sub_end_idx = lnk_bgn_itr->pos().idx();
      scn_mid(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk, sub_nxt_inl_dlm_itr, lnk_bgn_itr, sub_end_idx, /*shd_fsh_inl_ctx_stk*/ false);
    }
  }

  lxr.jmp_pos(lnk_bgn_itr->end_pos());
  InlineContextStack sub_inl_ctx_stk;
  InlineDelimiterList::Iterator sub_nxt_inl_dlm_itr = NXT_ITR(lnk_bgn_itr);
  LexedIndex sub_end_idx = lnk_end_itr->pos().idx();
  scn_mid(lxr, inl_dlms, sub_inl_ctx_stk, blk_dlms, blk_ctx_stk, sub_nxt_inl_dlm_itr, lnk_end_itr, sub_end_idx, /*shd_fsh_inl_ctx_stk*/ true);

  lxr.jmp_pos(ori_pos);
}

void hdl_paired_lnk_ref_def(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk) {
  TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_DST_END_MKR);
  inl_ctx_stk.pop_erase(inl_dlms);
  TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.back().dlm_itr()->sym() == SYM_LNK_REF_DEF_CLN);
  inl_ctx_stk.pop_yes();
  InlineDelimiterList::Iterator lnk_end_itr = inl_ctx_stk.back().dlm_itr();
  TREE_SITTER_MARKDOWN_ASSERT(lnk_end_itr->sym() == SYM_LNK_END);
  inl_ctx_stk.pop();
  InlineDelimiterList::Iterator lnk_bgn_itr = inl_ctx_stk.back().dlm_itr();
  TREE_SITTER_MARKDOWN_ASSERT(lnk_bgn_itr->sym() == SYM_LNK_BGN);
  lnk_bgn_itr->set_sym(SYM_LNK_REF_DEF_BGN);
  inl_ctx_stk.pop_paired(lnk_end_itr);
  TREE_SITTER_MARKDOWN_ASSERT(inl_ctx_stk.empty());
  for (InlineDelimiterList::Iterator itr = ++lnk_bgn_itr; itr != lnk_end_itr;) {
    if (itr->sym() == SYM_BSL_ESC || itr->sym() == SYM_BSL_LBK) {
      if (itr->sym() == SYM_BSL_LBK) itr->set_yes(false);
      itr++;
    }
    else itr = inl_dlms.erase(itr);
  }
}

void hdl_unpaired_inl_dlm(Lexer &lxr, InlineDelimiterList &inl_dlms, InlineContextStack &inl_ctx_stk, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk, InlineDelimiterList::Iterator &nxt_inl_dlm_itr, const InlineDelimiterList::Iterator &end_inl_dlm_itr) {
  TREE_SITTER_MARKDOWN_ASSERT(!inl_ctx_stk.empty());
  InlineDelimiterList::Iterator unpaired_dlm_itr = inl_ctx_stk.back().dlm_itr();
  bool shd_ers = false;
  bool shd_hdl_lnk_end = false;
  switch (unpaired_dlm_itr->sym()) {
    case SYM_EXT_WWW_AUT_LNK_BGN_MKR:
    case SYM_EXT_URL_AUT_LNK_BGN_MKR:
      inl_ctx_stk.pop_paired(
        inl_dlms.insert(nxt_inl_dlm_itr, InlineDelimiter(true, SYM_EXT_AUT_LNK_END_MKR, unpaired_dlm_itr->end_pos(), unpaired_dlm_itr->end_pos()))
      );
      return;
    case SYM_LNK_END:
      shd_hdl_lnk_end = true;
      break;
    case SYM_LNK_DST_END_MKR:
    case SYM_LNK_TIT_SQT_BGN:
    case SYM_LNK_TIT_SQT_END:
    case SYM_LNK_TIT_DQT_BGN:
    case SYM_LNK_TIT_DQT_END:
    case SYM_LNK_TIT_PRN_BGN:
    case SYM_LNK_TIT_PRN_END:
    case SYM_LNK_TIT_END_MKR:
      while (unpaired_dlm_itr->sym() != SYM_LNK_DST_END_MKR && unpaired_dlm_itr->sym() != SYM_LNK_TIT_END_MKR) {
        inl_ctx_stk.pop();
        unpaired_dlm_itr = inl_ctx_stk.back().dlm_itr();
      }
      if (inl_ctx_stk.back(1).dlm_itr()->sym() == SYM_LNK_REF_DEF_CLN) {
        LexedPosition ori_pos = lxr.cur_pos();
        lxr.jmp_pos(unpaired_dlm_itr->end_pos());
        lxr.adv_rpt(is_wsp_chr);
        if (is_eol_chr(lxr.lka_chr())) {
          inl_dlms.erase(NXT_ITR(unpaired_dlm_itr), end_inl_dlm_itr);
          hdl_paired_lnk_ref_def(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk);
          BlockDelimiterList::Iterator lnk_ref_def_end_mkr_nxt_itr =  ++blk_dlms.insert(
            lxr.cur_row(),
            BlockDelimiter(SYM_LNK_REF_DEF_END_MKR, lxr.cur_pos(), lxr.cur_pos())
          );
          if (lnk_ref_def_end_mkr_nxt_itr != blk_dlms.end() && lnk_ref_def_end_mkr_nxt_itr->sym() == SYM_LIT_LBK) {
            lnk_ref_def_end_mkr_nxt_itr = ++blk_dlms.insert(++lnk_ref_def_end_mkr_nxt_itr, BlockDelimiter(SYM_PGH_BGN_MKR, 0));
          }
          while (lnk_ref_def_end_mkr_nxt_itr != blk_dlms.end()) {
            if (lnk_ref_def_end_mkr_nxt_itr->sym() == SYM_PGH_END_MKR) {
              blk_dlms.erase(lnk_ref_def_end_mkr_nxt_itr, blk_dlms.end());
              break;
            }
            lnk_ref_def_end_mkr_nxt_itr++;
          }
          return;
        }
        lxr.jmp_pos(ori_pos);
      }
    // fall through
    case SYM_LNK_REF_DEF_CLN:
    case SYM_LNK_INL_BGN:
    case SYM_LNK_DST_EXP_BGN:
    case SYM_LNK_DST_IMP_BGN_MKR:
    case SYM_LNK_DST_IMP_PRN_BGN:
    case SYM_LNK_REF_BGN:
    case SYM_LNK_REF_END:
      while (unpaired_dlm_itr->sym() != SYM_LNK_END) {
        inl_ctx_stk.pop();
        unpaired_dlm_itr = inl_ctx_stk.back().dlm_itr();
      }
      shd_ers = true;
      shd_hdl_lnk_end = true;
      break;
    case SYM_COD_SPN_BGN:
      shd_ers = true;
      break;
    case SYM_EML_AUT_LNK_END_MKR:
    case SYM_EML_AUT_LNK_IVD_MKR:
      while (unpaired_dlm_itr->sym() != SYM_EML_AUT_LNK_BGN) {
        inl_ctx_stk.pop();
        unpaired_dlm_itr = inl_ctx_stk.back().dlm_itr();
      }
      shd_ers = true;
      break;
    case SYM_HTM_OPN_TAG_BGN:
    case SYM_HTM_SLF_TAG_END:
    case SYM_HTM_ATR_KEY_END_MKR:
    case SYM_HTM_ATR_EQL:
    case SYM_HTM_ATR_UQT_BGN_MKR:
    case SYM_HTM_ATR_SQT_BGN:
    case SYM_HTM_ATR_SQT_END:
    case SYM_HTM_ATR_DQT_BGN:
    case SYM_HTM_ATR_DQT_END:
      while (unpaired_dlm_itr->sym() != SYM_HTM_OPN_TAG_BGN) {
        inl_ctx_stk.pop();
        unpaired_dlm_itr = inl_ctx_stk.back().dlm_itr();
      }
      shd_ers = true;
      break;
    case SYM_HTM_CLS_TAG_NAM_END_MKR:
      while (unpaired_dlm_itr->sym() != SYM_HTM_CLS_TAG_BGN) {
        inl_ctx_stk.pop();
        unpaired_dlm_itr = inl_ctx_stk.back().dlm_itr();
      }
      shd_ers = true;
      break;
    case SYM_HTM_DCL_NAM_END_MKR:
      while (unpaired_dlm_itr->sym() != SYM_HTM_DCL_BGN) {
        inl_ctx_stk.pop();
        unpaired_dlm_itr = inl_ctx_stk.back().dlm_itr();
      }
      shd_ers = true;
      break;
    case SYM_HTM_CMT_BGN:
    case SYM_HTM_CMT_END:
      while (unpaired_dlm_itr->sym() != SYM_HTM_CMT_BGN) {
        inl_ctx_stk.pop();
        unpaired_dlm_itr = inl_ctx_stk.back().dlm_itr();
      }
      shd_ers = true;
      break;
    case SYM_HTM_PRC_BGN:
      shd_ers = true;
      break;
    case SYM_HTM_CDA_BGN:
      shd_ers = true;
      break;
    default:
      // do nothing
      break;
  }
  if (shd_ers) {
    inl_dlms.erase(NXT_ITR(unpaired_dlm_itr), end_inl_dlm_itr);
  }
  if (shd_hdl_lnk_end) {
    TREE_SITTER_MARKDOWN_ASSERT(unpaired_dlm_itr->sym() == SYM_LNK_END);
    InlineDelimiterList::Iterator lnk_end_itr = unpaired_dlm_itr;
    bool is_vld_lnk_lbl = lnk_end_itr->ctm_dat();
    if (is_vld_lnk_lbl) {
      hdl_paired_lnk_end(lxr, inl_dlms, inl_ctx_stk, blk_dlms, blk_ctx_stk);
      lxr.jmp_pos(lnk_end_itr->end_pos());
      nxt_inl_dlm_itr = NXT_ITR(lnk_end_itr);
      return;
    }
    inl_ctx_stk.pop();
    unpaired_dlm_itr = inl_ctx_stk.back().dlm_itr();
    TREE_SITTER_MARKDOWN_ASSERT(unpaired_dlm_itr->sym() == SYM_LNK_BGN || unpaired_dlm_itr->sym() == SYM_IMG_BGN);
  }
  switch (unpaired_dlm_itr->sym()) {
    case SYM_ASR_BGN:
    case SYM_USC_BGN:
    case SYM_DEL_BGN:
    case SYM_IMG_BGN: // no need to check LNK_BGN if IMG_BGN failed
    case SYM_COD_SPN_BGN:
      break;
    default:
      if (unpaired_dlm_itr->len() > 1) {
        unpaired_dlm_itr->set_end_pos(unpaired_dlm_itr->pos().clone_add(1));
      }
      break;
  }
  lxr.jmp_pos(unpaired_dlm_itr->end_pos());
  nxt_inl_dlm_itr = NXT_ITR(unpaired_dlm_itr);
  inl_ctx_stk.pop();
}

}
