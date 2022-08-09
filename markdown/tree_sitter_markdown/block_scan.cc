#include "./block_scan.h"

#include "./block_scan_util.generated.h"
#include "./predicate.h"
#include "./util.h"

namespace tree_sitter_markdown {

BlockScanResult scn_blk_nod(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  BlockScanResult scn_rlt;
  (scn_rlt = scn_ind_cod(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln))
  || (scn_rlt = scn_blk_asr(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln))
  || (scn_rlt = scn_blk_btk(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln))
  || (scn_rlt = scn_blk_eql(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln))
  || (scn_rlt = scn_blk_hsh(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln))
  || (scn_rlt = scn_blk_hyp(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln))
  || (scn_rlt = scn_blk_lng(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln))
  || (scn_rlt = scn_blk_num(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln))
  || (scn_rlt = scn_blk_pls(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln))
  || (scn_rlt = scn_blk_rng(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln))
  || (scn_rlt = scn_blk_tld(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln))
  || (scn_rlt = scn_blk_usc(lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln));
  return scn_rlt;
}

void push_lst_nod_mkr_if_necessary(BlockDelimiterList &blk_dlms, BlockDelimiter &nxt_blk_dlm, const LexedColumn ind, const Symbol lst_blk_ctx_sym) {
  if (is_lst_itm_bgn(lst_blk_ctx_sym)) {
    LexedColumn lst_itm_cnt_ind = nxt_blk_dlm.sym() == SYM_IND_COD_BGN_PFX ? 0 : ind;
    blk_dlms.push_back(BlockDelimiter(SYM_LST_ITM_CNT_BGN_MKR, 0, lst_itm_cnt_ind));
  }

  if (
    lst_blk_ctx_sym != SYM_ASR_LST_BGN_MKR
    && lst_blk_ctx_sym != SYM_HYP_LST_BGN_MKR
    && lst_blk_ctx_sym != SYM_PLS_LST_BGN_MKR
    && lst_blk_ctx_sym != SYM_DOT_LST_BGN_MKR
    && lst_blk_ctx_sym != SYM_RPR_LST_BGN_MKR
  ) {
    Symbol lst_bgn_mkr = SYM_NOT_FOUND;
    if (nxt_blk_dlm.sym() == SYM_ASR_LST_ITM_BGN) lst_bgn_mkr = SYM_ASR_LST_BGN_MKR;
    else if (nxt_blk_dlm.sym() == SYM_HYP_LST_ITM_BGN) lst_bgn_mkr = SYM_HYP_LST_BGN_MKR;
    else if (nxt_blk_dlm.sym() == SYM_PLS_LST_ITM_BGN) lst_bgn_mkr = SYM_PLS_LST_BGN_MKR;
    else if (nxt_blk_dlm.sym() == SYM_DOT_LST_ITM_BGN) lst_bgn_mkr = SYM_DOT_LST_BGN_MKR;
    else if (nxt_blk_dlm.sym() == SYM_RPR_LST_ITM_BGN) lst_bgn_mkr = SYM_RPR_LST_BGN_MKR;
    if (lst_bgn_mkr != SYM_NOT_FOUND) {
      blk_dlms.push_back(BlockDelimiter(lst_bgn_mkr, 0));
    }
  }
}

void scn_blk(Lexer &lxr, BlockDelimiterList &blk_dlms, const BlockContextStack &blk_ctx_stk, const LexedColumn ind) {
  lxr.bgn_rec_tbl_col_cnt();
  BlockDelimiterList tmp_blk_dlms;
  if (BSR_ACCEPT == scn_blk_nod(lxr, tmp_blk_dlms, ind, /*is_pas_all_blk_ctx*/ true, /*is_pgh_cont_ln*/ false)) {
    lxr.end_rec_tbl_col_cnt();
  } else {
    lxr.adv_til(is_eol_chr);
    uint16_t tbl_col_cnt = lxr.tbl_col_cnt();
    lxr.end_rec_tbl_col_cnt();

    bool is_tbl = false;

    if (is_lbk_chr(lxr.lka_chr())) {
      lxr.adv_if('\r');
      lxr.adv_if('\n');
      BlockContextStack::ConstIterator ctx_itr = blk_ctx_stk.begin();
      BlockContextStack::ConstIterator ctx_end = blk_ctx_stk.end();
      const LexedColumn cur_ind = adv_blk_pfx(lxr, ctx_itr, ctx_end);
      bool is_pas_all_blk_ctx = ctx_itr == ctx_end
                             && (blk_ctx_stk.empty() || !is_lst_itm_bgn(blk_ctx_stk.back().sym())
                                  ? cur_ind < 4
                                  : cur_ind >= ind && cur_ind - ind < 4);
      if (is_pas_all_blk_ctx && !is_eol_chr(lxr.lka_chr()) && scn_tbl_dlm_row(lxr, tbl_col_cnt)) {
        is_tbl = true;
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_TBL_HED_ROW_BGN_MKR, 0));
      }
    }

    if (!is_tbl) tmp_blk_dlms.push_back(BlockDelimiter(SYM_PGH_BGN_MKR, 0));
  }
  TREE_SITTER_MARKDOWN_ASSERT(!tmp_blk_dlms.empty());
  push_lst_nod_mkr_if_necessary(blk_dlms, tmp_blk_dlms.front(), ind, blk_ctx_stk.empty() ? SYM_NOT_FOUND : blk_ctx_stk.back().sym());
  tmp_blk_dlms.transfer_to(blk_dlms);
}

bool /*is_interrupted*/ scn_eol(Lexer &lxr, BlockDelimiterList &blk_dlms, BlockContextStack &blk_ctx_stk) {
  TREE_SITTER_MARKDOWN_ASSERT(is_eol_chr(lxr.lka_chr()));

  LexedPosition bgn_pos = lxr.cur_pos();

  if (!blk_ctx_stk.empty()) {
    Symbol ctx_sym = blk_ctx_stk.back().sym();
    if (is_lst_itm_bgn(ctx_sym)) {
      blk_dlms.push_back(BlockDelimiter(SYM_LST_ITM_CNT_BGN_MKR, 0));
      if (is_lbk_chr(lxr.lka_chr())) {
        lxr.adv_if('\r');
        lxr.adv_if('\n');
        BlockContextStack::ConstIterator ctx_itr = blk_ctx_stk.begin();
        BlockContextStack::ConstIterator ctx_end = blk_ctx_stk.end();
        adv_blk_pfx(lxr, ctx_itr, ctx_end);
        bool is_pas_all_blk_ctx = ctx_itr == ctx_end;
        if (!is_pas_all_blk_ctx || is_eol_chr(lxr.lka_chr())) {
          // disallow double blank lines in list item begin
          blk_dlms.push_back(BlockDelimiter(SYM_LST_ITM_CNT_END_MKR, 0));
          blk_dlms.push_back(BlockDelimiter(SYM_LST_ITM_END_MKR, 0));
        }
      }
      return true;
    }
    if (ctx_sym == SYM_TBL_HED_ROW_BGN_MKR) {
      blk_dlms.push_back(BlockDelimiter(SYM_TBL_ROW_END_MKR, 0));
      lxr.adv_if('\r');
      lxr.adv_if('\n');
      BlockContextStack::ConstIterator ctx_itr = blk_ctx_stk.begin();
      BlockContextStack::ConstIterator ctx_end = blk_ctx_stk.end();
      adv_blk_pfx(lxr, ctx_itr, ctx_end);
      LexedPosition end_pos = lxr.cur_pos();
      blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, bgn_pos, end_pos));
      blk_dlms.push_back(BlockDelimiter(SYM_TBL_DLM_ROW_BGN_MKR, end_pos, end_pos));
      return true;
    }
  }

  if (is_eof_chr(lxr.lka_chr())) {
    for (
      BlockContextStack::ConstReverseIterator itr = blk_ctx_stk.rbegin(), end = blk_ctx_stk.rend();
      itr != end;
      itr++
    ) blk_dlms.push_back(BlockDelimiter(get_blk_cls_sym(itr->sym()), 0));
    return true;
  }

  if (!blk_ctx_stk.empty() && blk_ctx_stk.back().sym() == SYM_ATX_BGN) {
    blk_dlms.push_back(BlockDelimiter(SYM_ATX_END_MKR, 0));
    return true;
  }

  lxr.adv_if('\r');
  lxr.adv_if('\n');

  LexedCharacter lbk_nxt_chr = lxr.lka_chr();

  BlockDelimiterList tmp_blk_dlms;
  LexedPosition lst_bgn_pos = bgn_pos;
  bool has_end_mkr = false;
  bool has_opn_mkr = false;
  bool has_blk_lbk = false;

  for (;;) {
    // EOF-only newlines are NOT considered part of the fenced code block content
    if (
      is_eof_chr(lxr.lka_chr())
      && !blk_ctx_stk.empty()
      && (blk_ctx_stk.back().sym() == SYM_BTK_FEN_COD_BGN || blk_ctx_stk.back().sym() == SYM_TLD_FEN_COD_BGN)
    ) {
      TREE_SITTER_MARKDOWN_ASSERT(!has_blk_lbk);
      has_end_mkr = true;
      tmp_blk_dlms.push_back(BlockDelimiter(get_blk_cls_sym(blk_ctx_stk.back().sym()), 0));
      break;
    }

    BlockContextStack::ConstIterator ctx_itr = blk_ctx_stk.begin();
    const BlockContextStack::ConstIterator ctx_end_itr = blk_ctx_stk.end();
    LexedPosition lst_non_wsp_end_pos;
    const LexedColumn cur_ind = adv_blk_pfx(lxr, ctx_itr, ctx_end_itr, lst_non_wsp_end_pos);
    const BlockContextStack::ConstIterator fst_failed_ctx_itr = ctx_itr;
    const bool is_pas_all_blk_ctx = fst_failed_ctx_itr == ctx_end_itr;
    const bool is_eol = is_eol_chr(lxr.lka_chr());
    if (is_pas_all_blk_ctx && is_eol) {
      if (blk_ctx_stk.empty() || blk_ctx_stk.back().sym() == SYM_BQT_BGN) {
        TREE_SITTER_MARKDOWN_ASSERT(!has_blk_lbk);
        has_blk_lbk = true;
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_BNK_LBK, bgn_pos, lst_non_wsp_end_pos));
        break;
      }
      if (
        blk_ctx_stk.back().sym() == SYM_PGH_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_DIV_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_CMP_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_TBL_DLM_ROW_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_TBL_DAT_ROW_BGN_MKR
      ) {
        TREE_SITTER_MARKDOWN_ASSERT(!has_blk_lbk);
        has_end_mkr = true;
        tmp_blk_dlms.push_back(BlockDelimiter(get_blk_cls_sym(blk_ctx_stk.back().sym()), 0));
        break;
      }
      bool is_vtr_spc_sensitive = blk_ctx_stk.back().sym() == SYM_IND_COD_BGN_MKR
                               || blk_ctx_stk.back().sym() == SYM_BTK_FEN_COD_BGN
                               || blk_ctx_stk.back().sym() == SYM_TLD_FEN_COD_BGN
                               || blk_ctx_stk.back().sym() == SYM_HTM_BLK_SCR_BGN_MKR
                               || blk_ctx_stk.back().sym() == SYM_HTM_BLK_CMT_BGN_MKR
                               || blk_ctx_stk.back().sym() == SYM_HTM_BLK_PRC_BGN_MKR
                               || blk_ctx_stk.back().sym() == SYM_HTM_BLK_DCL_BGN_MKR
                               || blk_ctx_stk.back().sym() == SYM_HTM_BLK_CDA_BGN_MKR;
      LexedLength ind_chr_cnt = 0;
      LexedLength vrt_spc_cnt = !is_vtr_spc_sensitive ? 0 : lxr.clc_vtr_spc_cnt(cur_ind, 0, ind_chr_cnt);
      has_blk_lbk = true;
      tmp_blk_dlms.push_back(BlockDelimiter(SYM_BNK_LBK, lst_bgn_pos.dist(lst_non_wsp_end_pos) + ind_chr_cnt));
      tmp_blk_dlms.push_vtr_spc(vrt_spc_cnt);
      if (blk_ctx_stk.back().sym() == SYM_BTK_FEN_COD_BGN || blk_ctx_stk.back().sym() == SYM_TLD_FEN_COD_BGN) {
        break;
      }
    } else if (is_pas_all_blk_ctx) {
      if (blk_ctx_stk.empty() || blk_ctx_stk.back().sym() == SYM_BQT_BGN) {
        TREE_SITTER_MARKDOWN_ASSERT(!has_blk_lbk);
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, bgn_pos, lst_non_wsp_end_pos));
        has_opn_mkr = true;
        scn_blk(lxr, tmp_blk_dlms, blk_ctx_stk, cur_ind);
        break;
      }
      if (blk_ctx_stk.back().sym() == SYM_LST_ITM_CNT_BGN_MKR) {
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, lst_bgn_pos, lst_non_wsp_end_pos));
        has_opn_mkr = true;
        scn_blk(lxr, tmp_blk_dlms, blk_ctx_stk, cur_ind);
        break;
      }
      if (blk_ctx_stk.back().sym() == SYM_HTM_BLK_DIV_BGN_MKR || blk_ctx_stk.back().sym() == SYM_HTM_BLK_CMP_BGN_MKR) {
        TREE_SITTER_MARKDOWN_ASSERT(!has_blk_lbk);
        LexedLength ind_chr_cnt;
        LexedLength vrt_spc_cnt = lxr.clc_vtr_spc_cnt(cur_ind, 0, ind_chr_cnt);
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, bgn_pos.dist(lst_non_wsp_end_pos) + ind_chr_cnt));
        tmp_blk_dlms.push_vtr_spc(vrt_spc_cnt);
        break;
      }
      if (
        blk_ctx_stk.back().sym() == SYM_IND_COD_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_SCR_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_CMT_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_PRC_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_DCL_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_CDA_BGN_MKR
      ) {
        LexedLength ind_chr_cnt;
        LexedLength vrt_spc_cnt = lxr.clc_vtr_spc_cnt(cur_ind, 0, ind_chr_cnt);
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, lst_bgn_pos.dist(lst_non_wsp_end_pos) + ind_chr_cnt));
        tmp_blk_dlms.push_vtr_spc(vrt_spc_cnt);
        break;
      }
      if (blk_ctx_stk.back().sym() == SYM_BTK_FEN_COD_BGN) {
        LexedLength ind_chr_cnt;
        LexedLength vrt_spc_cnt = lxr.clc_vtr_spc_cnt(cur_ind, 0, ind_chr_cnt);
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, lst_bgn_pos.dist(lst_non_wsp_end_pos) + ind_chr_cnt));
        if (BSR_ACCEPT == scn_fen_cod('`', SYM_BTK_FEN_COD_END, /*min_len*/ blk_ctx_stk.back().len(), /*allow_non_wsp*/ false, /*allow_dlm_chr*/ false, lxr, tmp_blk_dlms, cur_ind + blk_ctx_stk.back().ind(), is_pas_all_blk_ctx, false)) {
          has_end_mkr = true;
          tmp_blk_dlms.push_back(BlockDelimiter(SYM_BTK_FEN_COD_END_MKR, lxr.cur_pos(), lxr.cur_pos()));
        } else {
          tmp_blk_dlms.push_vtr_spc(vrt_spc_cnt);
        }
        break;
      }
      if (blk_ctx_stk.back().sym() == SYM_TLD_FEN_COD_BGN) {
        LexedLength ind_chr_cnt;
        LexedLength vrt_spc_cnt = lxr.clc_vtr_spc_cnt(cur_ind, 0, ind_chr_cnt);
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, lst_bgn_pos.dist(lst_non_wsp_end_pos) + ind_chr_cnt));
        if (BSR_ACCEPT == scn_fen_cod('~', SYM_TLD_FEN_COD_END, /*min_len*/ blk_ctx_stk.back().len(), /*allow_non_wsp*/ false, /*allow_dlm_chr*/ false, lxr, tmp_blk_dlms, cur_ind + blk_ctx_stk.back().ind(), is_pas_all_blk_ctx, false)) {
          has_end_mkr = true;
          tmp_blk_dlms.push_back(BlockDelimiter(SYM_TLD_FEN_COD_END_MKR, lxr.cur_pos(), lxr.cur_pos()));
        } else {
          tmp_blk_dlms.push_vtr_spc(vrt_spc_cnt);
        }
        break;
      }
      if (blk_ctx_stk.back().sym() == SYM_ASR_LST_BGN_MKR) {
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, lst_bgn_pos, lst_non_wsp_end_pos));
        if (BSR_ACCEPT != scn_stx_and_thm_brk_and_lst_itm('*', SYM_NOT_FOUND, SYM_NOT_FOUND, SYM_ASR_LST_ITM_BGN, lxr, tmp_blk_dlms, cur_ind, is_pas_all_blk_ctx, /*is_pgh_cont_ln*/ false)) {
          has_blk_lbk = false;
          tmp_blk_dlms.clear();
          has_end_mkr = true;
          tmp_blk_dlms.push_back(BlockDelimiter(SYM_LST_END_MKR, 0));
        }
        break;
      }
      if (blk_ctx_stk.back().sym() == SYM_HYP_LST_BGN_MKR) {
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, lst_bgn_pos, lst_non_wsp_end_pos));
        if (BSR_ACCEPT != scn_stx_and_thm_brk_and_lst_itm('-', SYM_NOT_FOUND, SYM_NOT_FOUND, SYM_HYP_LST_ITM_BGN, lxr, tmp_blk_dlms, cur_ind, is_pas_all_blk_ctx, /*is_pgh_cont_ln*/ false)) {
          has_blk_lbk = false;
          tmp_blk_dlms.clear();
          has_end_mkr = true;
          tmp_blk_dlms.push_back(BlockDelimiter(SYM_LST_END_MKR, 0));
        }
        break;
      }
      if (blk_ctx_stk.back().sym() == SYM_PLS_LST_BGN_MKR) {
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, lst_bgn_pos, lst_non_wsp_end_pos));
        if (BSR_ACCEPT != scn_stx_and_thm_brk_and_lst_itm('+', SYM_NOT_FOUND, SYM_NOT_FOUND, SYM_PLS_LST_ITM_BGN, lxr, tmp_blk_dlms, cur_ind, is_pas_all_blk_ctx, /*is_pgh_cont_ln*/ false)) {
          has_blk_lbk = false;
          tmp_blk_dlms.clear();
          has_end_mkr = true;
          tmp_blk_dlms.push_back(BlockDelimiter(SYM_LST_END_MKR, 0));
        }
        break;
      }
      if (blk_ctx_stk.back().sym() == SYM_DOT_LST_BGN_MKR) {
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, lst_bgn_pos, lst_non_wsp_end_pos));
        if (BSR_ACCEPT != scn_num_lst_itm(/*allow_dot*/ true, /*allow_rpr*/ false, lxr, tmp_blk_dlms, cur_ind, is_pas_all_blk_ctx, /*is_pgh_cont_ln*/ false)) {
          has_blk_lbk = false;
          tmp_blk_dlms.clear();
          has_end_mkr = true;
          tmp_blk_dlms.push_back(BlockDelimiter(SYM_LST_END_MKR, 0));
        }
        break;
      }
      if (blk_ctx_stk.back().sym() == SYM_RPR_LST_BGN_MKR) {
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, lst_bgn_pos, lst_non_wsp_end_pos));
        if (BSR_ACCEPT != scn_num_lst_itm(/*allow_dot*/ false, /*allow_rpr*/ true, lxr, tmp_blk_dlms, cur_ind, is_pas_all_blk_ctx, /*is_pgh_cont_ln*/ false)) {
          has_blk_lbk = false;
          tmp_blk_dlms.clear();
          has_end_mkr = true;
          tmp_blk_dlms.push_back(BlockDelimiter(SYM_LST_END_MKR, 0));
        }
        break;
      }
      TREE_SITTER_MARKDOWN_ASSERT(
        !has_blk_lbk
        && (blk_ctx_stk.back().sym() == SYM_PGH_BGN_MKR
          || blk_ctx_stk.back().sym() == SYM_TBL_DLM_ROW_BGN_MKR
          || blk_ctx_stk.back().sym() == SYM_TBL_DAT_ROW_BGN_MKR)
      );
      bool is_pgh_cont_ln = blk_ctx_stk.back().sym() == SYM_PGH_BGN_MKR;
      if (BSR_ACCEPT == scn_blk_nod(lxr, tmp_blk_dlms, cur_ind, is_pas_all_blk_ctx, is_pgh_cont_ln)) {
        has_opn_mkr = true;
        has_end_mkr = true;
        blk_dlms.push_back(BlockDelimiter(get_blk_cls_sym(blk_ctx_stk.back().sym()), 0));
        blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, bgn_pos, lst_non_wsp_end_pos));
        BlockContextStack::ConstReverseIterator lst_blk_ctx_itr = ++blk_ctx_stk.rbegin();
        Symbol lst_blk_ctx_sym = lst_blk_ctx_itr == blk_ctx_stk.rend() ? SYM_NOT_FOUND : lst_blk_ctx_itr->sym();
        push_lst_nod_mkr_if_necessary(blk_dlms, tmp_blk_dlms.front(), cur_ind, lst_blk_ctx_sym);
      } else if (is_pgh_cont_ln) {
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, bgn_pos, lst_non_wsp_end_pos));
      } else {
        blk_dlms.push_back(BlockDelimiter(get_blk_cls_sym(blk_ctx_stk.back().sym()), 0));
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, bgn_pos, lst_non_wsp_end_pos));
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_TBL_DAT_ROW_BGN_MKR, 0));
      }
      break;
    } else if (is_eol) {
      TREE_SITTER_MARKDOWN_ASSERT(!blk_ctx_stk.empty());
      const BlockContext *fst_bqt_ctx = NULL_PTR;
      for (
        BlockContextStack::ConstIterator cur_ctx_itr = fst_failed_ctx_itr;
        cur_ctx_itr != ctx_end_itr;
        cur_ctx_itr++
      ) {
        if (cur_ctx_itr->sym() == SYM_BQT_BGN) {
          fst_bqt_ctx = &(*cur_ctx_itr);
          break;
        }
      }
      if (fst_bqt_ctx != NULL_PTR) {
        has_blk_lbk = false;
        tmp_blk_dlms.clear();
        for (
          BlockContextStack::ConstReverseIterator cur_ctx_itr = blk_ctx_stk.rbegin();;
          cur_ctx_itr++
        ) {
          has_end_mkr = true;
          tmp_blk_dlms.push_back(BlockDelimiter(get_blk_cls_sym(cur_ctx_itr->sym()), 0));
          if (&(*cur_ctx_itr) == fst_bqt_ctx) break;
        }
        break;
      }
      if (
        blk_ctx_stk.back().sym() == SYM_PGH_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_DIV_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_CMP_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_TBL_DLM_ROW_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_TBL_DAT_ROW_BGN_MKR
      ) {
        TREE_SITTER_MARKDOWN_ASSERT(!has_blk_lbk);
        has_end_mkr = true;
        tmp_blk_dlms.push_back(BlockDelimiter(get_blk_cls_sym(blk_ctx_stk.back().sym()), 0));
        break;
      }
      has_blk_lbk = true;
      tmp_blk_dlms.push_back(BlockDelimiter(SYM_BNK_LBK, lst_bgn_pos, lxr.cur_pos()));
      if (blk_ctx_stk.back().sym() == SYM_BTK_FEN_COD_BGN || blk_ctx_stk.back().sym() == SYM_TLD_FEN_COD_BGN) {
        break;
      }
    } else {
      TREE_SITTER_MARKDOWN_ASSERT(!blk_ctx_stk.empty());
      if (blk_ctx_stk.back().sym() == SYM_BTK_FEN_COD_BGN || blk_ctx_stk.back().sym() == SYM_TLD_FEN_COD_BGN) {
        TREE_SITTER_MARKDOWN_ASSERT(!has_blk_lbk);
        has_end_mkr = true;
        tmp_blk_dlms.push_back(BlockDelimiter(get_blk_cls_sym(blk_ctx_stk.back().sym()), 0));
        break;
      }
      if (
        blk_ctx_stk.back().sym() == SYM_IND_COD_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_SCR_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_CMT_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_PRC_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_DCL_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_CDA_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_DIV_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HTM_BLK_CMP_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_BQT_BGN
        || blk_ctx_stk.back().sym() == SYM_ASR_LST_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_HYP_LST_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_PLS_LST_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_DOT_LST_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_RPR_LST_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_LST_ITM_CNT_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_TBL_DLM_ROW_BGN_MKR
        || blk_ctx_stk.back().sym() == SYM_TBL_DAT_ROW_BGN_MKR
      ) {
        has_blk_lbk = false;
        tmp_blk_dlms.clear();
        has_end_mkr = true;
        tmp_blk_dlms.push_back(BlockDelimiter(get_blk_cls_sym(blk_ctx_stk.back().sym()), 0));
        if (tmp_blk_dlms.back().sym() == SYM_LST_ITM_CNT_END_MKR) {
          tmp_blk_dlms.push_back(BlockDelimiter(SYM_LST_ITM_END_MKR, 0));
        }
        break;
      }
      TREE_SITTER_MARKDOWN_ASSERT(blk_ctx_stk.back().sym() == SYM_PGH_BGN_MKR && !has_blk_lbk);
      if (BSR_ACCEPT == scn_blk_nod(lxr, tmp_blk_dlms, cur_ind, is_pas_all_blk_ctx, /*is_pgh_cont_ln*/ true)) {
        has_opn_mkr = true;
        BlockContextStack::ConstReverseIterator cur_ctx_itr = blk_ctx_stk.rbegin();
        for (;; cur_ctx_itr++) {
          has_end_mkr = true;
          blk_dlms.push_back(BlockDelimiter(get_blk_cls_sym(cur_ctx_itr->sym()), 0));
          if (&(*cur_ctx_itr) == &(*fst_failed_ctx_itr)) break;
        }
        if (blk_dlms.back().sym() == SYM_LST_ITM_CNT_END_MKR) {
          cur_ctx_itr++;
          blk_dlms.push_back(BlockDelimiter(SYM_LST_ITM_END_MKR, 0));
        }
        cur_ctx_itr++;
        if (
          blk_dlms.back().sym() == SYM_LST_ITM_END_MKR
          && !(
            (tmp_blk_dlms.front().sym() == SYM_ASR_LST_ITM_BGN && cur_ctx_itr->sym() == SYM_ASR_LST_BGN_MKR)
            || (tmp_blk_dlms.front().sym() == SYM_HYP_LST_ITM_BGN && cur_ctx_itr->sym() == SYM_HYP_LST_BGN_MKR)
            || (tmp_blk_dlms.front().sym() == SYM_PLS_LST_ITM_BGN && cur_ctx_itr->sym() == SYM_PLS_LST_BGN_MKR)
            || (tmp_blk_dlms.front().sym() == SYM_DOT_LST_ITM_BGN && cur_ctx_itr->sym() == SYM_DOT_LST_BGN_MKR)
            || (tmp_blk_dlms.front().sym() == SYM_RPR_LST_ITM_BGN && cur_ctx_itr->sym() == SYM_RPR_LST_BGN_MKR)
          )
        ) {
          cur_ctx_itr++;
          blk_dlms.push_back(BlockDelimiter(SYM_LST_END_MKR, 0));
        }
        blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, bgn_pos, lst_non_wsp_end_pos));
        const BlockContextStack::ConstReverseIterator lst_blk_ctx_itr = cur_ctx_itr;
        Symbol lst_blk_ctx_sym = lst_blk_ctx_itr == blk_ctx_stk.rend() ? SYM_NOT_FOUND : lst_blk_ctx_itr->sym();
        push_lst_nod_mkr_if_necessary(blk_dlms, tmp_blk_dlms.front(), cur_ind, lst_blk_ctx_sym);
      } else {
        tmp_blk_dlms.push_back(BlockDelimiter(SYM_LIT_LBK, bgn_pos, lst_non_wsp_end_pos));
      }
      break;
    }

    if (is_lbk_chr(lxr.lka_chr())) {
      lst_bgn_pos = lxr.cur_pos();
      lxr.adv_if('\r');
      lxr.adv_if('\n');
      continue;
    }

    TREE_SITTER_MARKDOWN_ASSERT(is_eof_chr(lxr.lka_chr()) && !has_opn_mkr && !has_end_mkr);
    has_blk_lbk = false;
    tmp_blk_dlms.clear();
    for (
      BlockContextStack::ConstReverseIterator itr = blk_ctx_stk.rbegin(), end = blk_ctx_stk.rend();
      itr != end;
      itr++, has_end_mkr = true
    ) tmp_blk_dlms.push_back(BlockDelimiter(get_blk_cls_sym(itr->sym()), 0));
    break;
  }

  if (!has_opn_mkr && !has_end_mkr && !blk_ctx_stk.empty() && !is_eof_chr(lbk_nxt_chr)) {
    BlockContext &ctx = blk_ctx_stk.back();
    if (!ctx.has_fst_ctn() && (ctx.sym() == SYM_BTK_FEN_COD_BGN || ctx.sym() == SYM_TLD_FEN_COD_BGN)) {
      TREE_SITTER_MARKDOWN_ASSERT(tmp_blk_dlms.front().sym() == SYM_LIT_LBK || tmp_blk_dlms.front().sym() == SYM_BNK_LBK);
      tmp_blk_dlms.transfer_to(blk_dlms, 1);
      blk_dlms.push_back(BlockDelimiter(SYM_FEN_COD_CTN_BGN_MKR, 0));
    }
  }

  blk_ctx_stk.mrk_has_fst_ctn();

  tmp_blk_dlms.transfer_to(blk_dlms);
  return has_opn_mkr || has_end_mkr;
}

LexedColumn adv_blk_pfx(Lexer &lxr, BlockContextStack::ConstIterator &ctx_itr, const BlockContextStack::ConstIterator &ctx_end) {
  LexedPosition lst_non_wsp_end_pos;
  return adv_blk_pfx(lxr, ctx_itr, ctx_end, lst_non_wsp_end_pos);
}
LexedColumn adv_blk_pfx(Lexer &lxr, BlockContextStack::ConstIterator &ctx_itr, const BlockContextStack::ConstIterator &ctx_end, LexedPosition &lst_non_wsp_end_pos) {
  lst_non_wsp_end_pos.set(lxr.cur_pos());
  lxr.adv_rpt(is_wsp_chr);
  LexedColumn cur_ind = lxr.cur_ind();
  for (; ctx_itr != ctx_end; ctx_itr++) {
    if (ctx_itr->sym() == SYM_BQT_BGN) {
      if (cur_ind < 4 && lxr.adv_if('>')) {
        lst_non_wsp_end_pos.set(lxr.cur_pos());
        lxr.adv_rpt(is_wsp_chr);
        cur_ind = lxr.cur_ind();
        if (cur_ind) cur_ind--;
      } else break;
    } else if (
      is_lst_itm_bgn(ctx_itr->sym())
      || ctx_itr->sym() == SYM_LST_ITM_CNT_BGN_MKR
      || ctx_itr->sym() == SYM_IND_COD_BGN_MKR
    ) {
      LexedColumn ind = ctx_itr->sym() == SYM_IND_COD_BGN_MKR
        ? 4
        : ctx_itr->sym() == SYM_LST_ITM_CNT_BGN_MKR
          ? ctx_itr->ind()
          : ctx_itr->ind() + ctx_itr->len() + 1;
      if (cur_ind >= ind) {
        cur_ind -= ind;
      } else break;
    } else if (
      ctx_itr->sym() == SYM_BTK_FEN_COD_BGN
      || ctx_itr->sym() == SYM_TLD_FEN_COD_BGN
    ) {
      if (cur_ind >= ctx_itr->ind()) {
        cur_ind -= ctx_itr->ind();
      } else {
        cur_ind = 0;
      }
    }
  }
  return cur_ind;
}

bool scn_tbl_dlm_row(Lexer &lxr, const uint16_t tbl_col_cnt) {
  bool has_pip = lxr.adv_if('|');
  bool has_cln = false;

  lxr.adv_rpt(is_wsp_chr);

  uint16_t hyp_cnt = 0;

  while (!is_eol_chr(lxr.lka_chr())) {
    if (lxr.adv_if(':')) has_cln = true;
    if (!lxr.adv_rpt('-')) return false;
    if (lxr.adv_if(':')) has_cln = true;
    hyp_cnt++;

    lxr.adv_rpt(is_wsp_chr);
    if (is_eol_chr(lxr.lka_chr())) break;

    if (!lxr.adv_if('|')) return false;
    has_pip = true;

    lxr.adv_rpt(is_wsp_chr);
  }

  return (has_pip || has_cln) && hyp_cnt == tbl_col_cnt;
}

BlockScanResult scn_ind_cod(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  if (!is_pas_all_blk_ctx || is_pgh_cont_ln || ind < 4 || is_wht_chr(lxr.lka_chr())) return BSR_REJECT;
  LexedLength ind_chr_cnt;
  LexedLength vtr_spc_cnt = lxr.clc_vtr_spc_cnt(ind, 4, ind_chr_cnt);
  blk_dlms.push_back(BlockDelimiter(SYM_IND_COD_BGN_PFX, ind_chr_cnt));
  blk_dlms.push_back(BlockDelimiter(SYM_IND_COD_BGN_MKR, 0));
  blk_dlms.push_vtr_spc(vtr_spc_cnt);
  return BSR_ACCEPT;
}

BlockScanResult scn_blk_asr(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  return scn_stx_and_thm_brk_and_lst_itm('*', SYM_NOT_FOUND, SYM_ASR_THM_BRK_BGN, SYM_ASR_LST_ITM_BGN, lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln);
}

BlockScanResult scn_blk_btk(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  return scn_fen_cod('`', SYM_BTK_FEN_COD_BGN, /*min_len*/ 3, /*allow_non_wsp*/ true, /*allow_dlm_chr*/ false, lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln);
}

BlockScanResult scn_blk_eql(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  return scn_stx_and_thm_brk_and_lst_itm('=', SYM_EQL_STX_BGN, SYM_NOT_FOUND, SYM_NOT_FOUND, lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln);
}

BlockScanResult scn_blk_hsh(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  if (ind >= 4 || lxr.lka_chr() != '#') return BSR_REJECT;

  LexedPosition bgn_pos = lxr.cur_pos();
  LexedLength len = lxr.adv_rpt_len('#');
  if (len > 6 || !is_wht_chr(lxr.lka_chr())) return BSR_FAILED;
  LexedPosition end_pos = lxr.cur_pos();

  blk_dlms.push_back(BlockDelimiter(SYM_ATX_BGN, bgn_pos, end_pos));
  return BSR_ACCEPT;
}

BlockScanResult scn_blk_hyp(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  return scn_stx_and_thm_brk_and_lst_itm('-', SYM_HYP_STX_BGN, SYM_HYP_THM_BRK_BGN, SYM_HYP_LST_ITM_BGN, lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln);
}

BlockScanResult scn_blk_lng(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  if (ind >= 4 || lxr.lka_chr() != '<') return BSR_REJECT;

  lxr.adv();

  if (lxr.adv_if('?')) {
    blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_PRC_BGN_MKR, 0));
    return BSR_ACCEPT;
  }

  if (lxr.adv_if('!')) {
    if (lxr.adv_if(is_upp_asc_ltr_chr)) {
      blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_DCL_BGN_MKR, 0));
      return BSR_ACCEPT;
    } else if (lxr.adv_if('-')) {
      if (!lxr.adv_if('-')) return BSR_FAILED;
      blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_CMT_BGN_MKR, 0));
      return BSR_ACCEPT;
    } else if (lxr.adv_if('[')) {
      if (lxr.adv_if('C')) {
        if (lxr.adv_if('D')) {
          if (lxr.adv_if('A')) {
            if (lxr.adv_if('T')) {
              if (lxr.adv_if('A')) {
                if (lxr.adv_if('[')) {
                  blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_CDA_BGN_MKR, 0));
                  return BSR_ACCEPT;
                }
              }
            }
          }
        }
      }
    }
    return BSR_FAILED;
  }

  bool is_cls_tag = lxr.adv_if('/');

  LexedPosition nam_bgn_pos = lxr.cur_pos();
  LexedLength scr_len = 0;
  LexedLength div_len = 0;

  adv_blk_htm_tag_nam(lxr, scr_len, div_len);

  LexedLength nam_len = nam_bgn_pos.dist(lxr.cur_pos());
  if (nam_len > 0) {
    if (nam_len == scr_len && !is_cls_tag && (lxr.adv_if(is_wht_chr) || lxr.adv_if('>'))) {
      blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_SCR_BGN_MKR, 0));
      return BSR_ACCEPT;
    } else if (nam_len == div_len && (lxr.adv_if(is_wht_chr) || lxr.adv_if('>') || lxr.adv_if('/'))) {
      if (lxr.cur_chr() == '/' && !lxr.adv_if('>')) return BSR_FAILED;
      blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_DIV_BGN_MKR, 0));
      return BSR_ACCEPT;
    }
  }

  if (is_pas_all_blk_ctx && is_pgh_cont_ln) return BSR_FAILED;

  if (nam_len == 0 && !lxr.adv_if(is_asc_ltr_chr)) return BSR_FAILED;
  while (lxr.adv_if(is_asc_ltr_chr) || lxr.adv_if(is_num_chr) || lxr.adv_if('-'));

  if (is_cls_tag) {
    lxr.adv_rpt(is_wsp_chr);
    if (!lxr.adv_if('>')) return BSR_FAILED;
  } else if (!lxr.adv_if('>')) {
    if (!lxr.adv_rpt(is_wsp_chr)) return BSR_FAILED;
    for (;;) {
      if (lxr.adv_if('>')) break;
      if (lxr.adv_if(is_asc_ltr_chr) || lxr.adv_if('_') || lxr.adv_if(':')) {
        while (lxr.adv_if(is_asc_ltr_chr) || lxr.adv_if('_') || lxr.adv_if(':') || lxr.adv_if(is_num_chr) || lxr.adv_if('.') || lxr.adv_if('-'));
        lxr.adv_rpt(is_wsp_chr);
        if (!lxr.adv_if('=')) continue;
        lxr.adv_rpt(is_wsp_chr);
        if (lxr.adv_if('\'')) {
          while (lxr.lka_chr() != '\'' && !is_eol_chr(lxr.lka_chr())) lxr.adv();
          if (lxr.adv_if('\'')) {
            if (lxr.adv_if('>')) break;
            if (!lxr.adv_rpt(is_wsp_chr)) return BSR_FAILED;
            continue;
          }
        } else if (lxr.adv_if('"')) {
          while (lxr.lka_chr() != '"' && !is_eol_chr(lxr.lka_chr())) lxr.adv();
          if (lxr.adv_if('"')) {
            if (lxr.adv_if('>')) break;
            if (!lxr.adv_rpt(is_wsp_chr)) return BSR_FAILED;
            continue;
          }
        } else if (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '=' && lxr.lka_chr() != '<' && lxr.lka_chr() != '>' && lxr.lka_chr() != '`') {
          lxr.adv();
          while (!is_wht_chr(lxr.lka_chr()) && lxr.lka_chr() != '=' && lxr.lka_chr() != '<' && lxr.lka_chr() != '>' && lxr.lka_chr() != '`' && lxr.lka_chr() != '\'' && lxr.lka_chr() != '"' ) lxr.adv();
          if (lxr.adv_if('>')) break;
          if (!lxr.adv_rpt(is_wsp_chr)) return BSR_FAILED;
          continue;
        }
      }
      return BSR_FAILED;
    }
  }

  lxr.adv_rpt(is_wsp_chr);
  if (!is_eol_chr(lxr.lka_chr())) return BSR_FAILED;

  blk_dlms.push_back(BlockDelimiter(SYM_HTM_BLK_CMP_BGN_MKR, 0));
  return BSR_ACCEPT;
}

BlockScanResult scn_blk_num(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  return scn_num_lst_itm(/*allow_dot*/ true, /*allow_rpr*/ true, lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln);
}

BlockScanResult scn_blk_pls(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  return scn_stx_and_thm_brk_and_lst_itm('+', SYM_NOT_FOUND, SYM_NOT_FOUND, SYM_PLS_LST_ITM_BGN, lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln);
}

BlockScanResult scn_blk_rng(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  if (ind >= 4 || lxr.lka_chr() != '>') return BSR_REJECT;
  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();
  LexedPosition end_pos = lxr.cur_pos();
  blk_dlms.push_back(BlockDelimiter(SYM_BQT_BGN, bgn_pos, end_pos));
  return BSR_ACCEPT;
}

BlockScanResult scn_blk_tld(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  return scn_fen_cod('~', SYM_TLD_FEN_COD_BGN, /*min_len*/ 3, /*allow_non_wsp*/ true, /*allow_dlm_chr*/ true, lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln);
}

BlockScanResult scn_blk_usc(Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln) {
  return scn_stx_and_thm_brk_and_lst_itm('_', SYM_NOT_FOUND, SYM_USC_THM_BRK_BGN, SYM_NOT_FOUND, lxr, blk_dlms, ind, is_pas_all_blk_ctx, is_pgh_cont_ln);
}

BlockScanResult scn_fen_cod(
  LexedCharacter dlm_chr, Symbol sym, const LexedLength min_len, const bool allow_non_wsp, const bool allow_dlm_chr,
  Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln
) {
  if (ind >= 4 || lxr.lka_chr() != dlm_chr) return BSR_REJECT;

  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv_rpt(dlm_chr);
  LexedPosition end_pos = lxr.cur_pos();

  if (bgn_pos.dist(end_pos) < min_len) return BSR_FAILED;

  if (!allow_non_wsp) {
    lxr.adv_rpt(is_wsp_chr);
    if (!is_eol_chr(lxr.lka_chr())) return BSR_FAILED;
  } else if (!allow_dlm_chr) {
    for (;;) {
      if (lxr.lka_chr() == dlm_chr) return BSR_FAILED;
      else if (is_eol_chr(lxr.lka_chr())) break;
      lxr.adv();
    }
  }

  blk_dlms.push_back(BlockDelimiter(sym, bgn_pos, end_pos, ind));
  return BSR_ACCEPT;
}

BlockScanResult scn_num_lst_itm(
  const bool allow_dot, const bool allow_rpr,
  Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln
) {
  if (ind >= 4 || !is_num_chr(lxr.lka_chr())) return BSR_REJECT;

  LexedPosition bgn_pos = lxr.cur_pos();
  lxr.adv();

  if (lxr.adv_rpt(is_num_chr)) {
    if (is_pas_all_blk_ctx && is_pgh_cont_ln) return BSR_FAILED;
  } else {
    if (is_pas_all_blk_ctx && is_pgh_cont_ln && lxr.cur_chr() != '1') return BSR_FAILED;
  }

  if (bgn_pos.dist(lxr.cur_pos()) >= 10) return BSR_FAILED;

  bool is_dot = allow_dot && lxr.lka_chr() == '.';
  bool is_rpr = allow_rpr && lxr.lka_chr() == ')';

  if (!is_dot && !is_rpr) return BSR_FAILED;

  lxr.adv();
  if (!is_wht_chr(lxr.lka_chr())) return BSR_FAILED;

  LexedPosition end_pos = lxr.cur_pos();

  if (is_pas_all_blk_ctx && is_pgh_cont_ln) {
    lxr.adv_rpt(is_wsp_chr);
    if (is_eol_chr(lxr.lka_chr())) return BSR_FAILED;
  }

  blk_dlms.push_back(BlockDelimiter(is_dot ? SYM_DOT_LST_ITM_BGN : SYM_RPR_LST_ITM_BGN, bgn_pos, end_pos, ind));
  return BSR_ACCEPT;
}

BlockScanResult scn_stx_and_thm_brk_and_lst_itm(
  LexedCharacter dlm_chr, Symbol stx_sym, Symbol thm_brk_sym, Symbol lst_itm_sym,
  Lexer &lxr, BlockDelimiterList &blk_dlms, const LexedColumn ind, const bool is_pas_all_blk_ctx, const bool is_pgh_cont_ln
) {
  if (ind >= 4 || lxr.lka_chr() != dlm_chr) return BSR_REJECT;
  bool is_stx = is_pas_all_blk_ctx && is_pgh_cont_ln && stx_sym != SYM_NOT_FOUND;
  bool is_thm_brk = thm_brk_sym != SYM_NOT_FOUND;
  bool is_lst_itm = lst_itm_sym != SYM_NOT_FOUND;
  if (!is_stx && !is_thm_brk && !is_lst_itm) return BSR_REJECT;

  LexedPosition bgn_pos = lxr.cur_pos();

  LexedLength dlm_chr_cnt = lxr.adv_rpt_len(dlm_chr);
  LexedPosition stx_end_pos = lxr.cur_pos();
  LexedPosition thm_brk_end_pos = lxr.cur_pos();
  LexedPosition lst_itm_end_pos = lxr.cur_pos();

  if (dlm_chr_cnt != 1 || !is_wht_chr(lxr.lka_chr())) is_lst_itm = false;

  for (;;) {
    LexedLength dlm_chr_adv_len = lxr.adv_rpt_len(dlm_chr);
    if (dlm_chr_adv_len) {
      dlm_chr_cnt += dlm_chr_adv_len;
      thm_brk_end_pos = lxr.cur_pos();
      is_stx = false;
    }
    if (lxr.adv_rpt(is_wsp_chr)) continue;
    break;
  }

  if (!is_wht_chr(lxr.lka_chr())) is_stx = is_thm_brk = false;
  if (dlm_chr_cnt < 3) is_thm_brk = false;
  if (is_pas_all_blk_ctx && is_pgh_cont_ln && is_wht_chr(lxr.lka_chr())) is_lst_itm = false;

  LexedPosition end_pos = lxr.cur_pos();

  if (is_stx) {
    blk_dlms.push_back(BlockDelimiter(stx_sym, bgn_pos, stx_end_pos));
    blk_dlms.push_back(BlockDelimiter(SYM_STX_END_MKR, end_pos, end_pos));
    return BSR_ACCEPT;
  }

  if (is_thm_brk) {
    blk_dlms.push_back(BlockDelimiter(thm_brk_sym, bgn_pos, thm_brk_end_pos));
    blk_dlms.push_back(BlockDelimiter(SYM_THM_BRK_END_MKR, end_pos, end_pos));
    return BSR_ACCEPT;
  }

  if (is_lst_itm) {
    blk_dlms.push_back(BlockDelimiter(lst_itm_sym, bgn_pos, lst_itm_end_pos, ind));
    return BSR_ACCEPT;
  }

  return BSR_FAILED;
}

}
