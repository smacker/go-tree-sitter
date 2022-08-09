#ifndef TREE_SITTER_MARKDOWN_PARSE_TABLE_H_
#define TREE_SITTER_MARKDOWN_PARSE_TABLE_H_

namespace tree_sitter_markdown {

enum Symbol {
  // inline
  SYM_TXT,
  SYM_WSP,
  SYM_BSL_LBK,
  SYM_BSL_ESC, // \.
  SYM_CHR_REF, // &...;
  SYM_ASR_BGN, // *
  SYM_ASR_END, // *
  SYM_USC_BGN, // _
  SYM_USC_END, // _
  SYM_DEL_BGN, // ~
  SYM_DEL_END, // ~
  SYM_IMG_BGN, // ![
  SYM_LNK_BGN, // [
  SYM_LNK_END, // ]
  SYM_LNK_REF_DEF_BGN, // [
  SYM_LNK_REF_DEF_CLN, // :
  SYM_LNK_INL_BGN, // (
  SYM_LNK_INL_END, // )
  SYM_LNK_DST_EXP_BGN, // <
  SYM_LNK_DST_EXP_END, // >
  SYM_LNK_DST_IMP_PRN_BGN, // (
  SYM_LNK_DST_IMP_PRN_END, // )
  SYM_LNK_TIT_SQT_BGN, // '
  SYM_LNK_TIT_SQT_END, // '
  SYM_LNK_TIT_DQT_BGN, // "
  SYM_LNK_TIT_DQT_END, // "
  SYM_LNK_TIT_PRN_BGN, // (
  SYM_LNK_TIT_PRN_END, // )
  SYM_LNK_REF_BGN, // [
  SYM_LNK_REF_END, // ]
  SYM_COD_SPN_BGN, // `
  SYM_COD_SPN_END, // `
  SYM_EXT_AUT_LNK_BGN,
  SYM_EXT_WWW_AUT_LNK_BGN_MKR,
  SYM_EXT_URL_AUT_LNK_BGN_MKR,
  SYM_EXT_EML_AUT_LNK_BGN_MKR,
  SYM_EXT_AUT_LNK_CTN,
  SYM_AUT_LNK_HTM_OPN_TAG_BGN, // <
  SYM_URI_AUT_LNK_BGN, // <
  SYM_EML_AUT_LNK_BGN, // <
  SYM_AUT_LNK_END, // >
  SYM_HTM_OPN_TAG_BGN, // <
  SYM_HTM_CLS_TAG_BGN, // </
  SYM_HTM_DCL_BGN, // <!
  SYM_HTM_TAG_END, // >
  SYM_HTM_SLF_TAG_END, // />
  SYM_HTM_ATR_EQL, // =
  SYM_HTM_ATR_SQT_BGN, // '
  SYM_HTM_ATR_SQT_END, // '
  SYM_HTM_ATR_DQT_BGN, // "
  SYM_HTM_ATR_DQT_END, // "
  SYM_HTM_CMT_BGN, // <!--
  SYM_HTM_CMT_END, // -->
  SYM_HTM_PRC_BGN, // <?
  SYM_HTM_PRC_END, // ?>
  SYM_HTM_CDA_BGN, // <![CDATA[
  SYM_HTM_CDA_END, // ]]>
  SYM_ATX_END, // #
  SYM_LST_CHK_BOX, // [x]
  SYM_TBL_COL_SEP, // |
  SYM_TBL_COL_ALN, // :-:

  // inline open marker
  SYM_FEN_COD_INF_BGN_MKR,
  SYM_LNK_DST_IMP_BGN_MKR,
  SYM_HTM_ATR_UQT_BGN_MKR,

  // inline close marker
  SYM_FEN_COD_INF_END_MKR,
  SYM_LNK_DST_IMP_END_MKR,
  SYM_EXT_AUT_LNK_END_MKR,
  SYM_EML_AUT_LNK_END_MKR,
  SYM_HTM_ATR_UQT_END_MKR,

  SYM_LNK_DST_END_MKR,
  SYM_LNK_TIT_END_MKR,
  SYM_HTM_CLS_TAG_NAM_END_MKR,
  SYM_HTM_ATR_KEY_END_MKR,
  SYM_HTM_DCL_NAM_END_MKR,

  // inline invalid marker
  SYM_EML_AUT_LNK_IVD_MKR,

  // block
  SYM_BLK_TXT,
  SYM_LIT_LBK,
  SYM_BNK_LBK,
  SYM_FEN_COD_CTN_BGN_MKR, // immediate

  // block open
  SYM_ASR_THM_BRK_BGN, // ***
  SYM_USC_THM_BRK_BGN, // ___
  SYM_HYP_THM_BRK_BGN, // ---
  SYM_PGH_BGN_MKR, // text
  SYM_EQL_STX_BGN, // ===
  SYM_HYP_STX_BGN, // ---
  SYM_ATX_BGN, // #
  SYM_IND_COD_BGN_PFX, // whitespace
  SYM_IND_COD_BGN_MKR, // immediate
  SYM_BTK_FEN_COD_BGN, // ```
  SYM_TLD_FEN_COD_BGN, // ~~~
  SYM_HTM_BLK_SCR_BGN_MKR, // <script
  SYM_HTM_BLK_CMT_BGN_MKR, // <!--
  SYM_HTM_BLK_PRC_BGN_MKR, // <?
  SYM_HTM_BLK_DCL_BGN_MKR, // <!
  SYM_HTM_BLK_CDA_BGN_MKR, // <![CDATA[
  SYM_HTM_BLK_DIV_BGN_MKR, // <div
  SYM_HTM_BLK_CMP_BGN_MKR, // <span>
  SYM_BQT_BGN, // >
  SYM_ASR_LST_BGN_MKR, // *
  SYM_ASR_LST_ITM_BGN, // *
  SYM_HYP_LST_BGN_MKR, // -
  SYM_HYP_LST_ITM_BGN, // -
  SYM_PLS_LST_BGN_MKR, // +
  SYM_PLS_LST_ITM_BGN, // +
  SYM_DOT_LST_BGN_MKR, // 1.
  SYM_DOT_LST_ITM_BGN, // 1.
  SYM_RPR_LST_BGN_MKR, // 1)
  SYM_RPR_LST_ITM_BGN, // 1)
  SYM_LST_ITM_CNT_BGN_MKR, // immediate
  SYM_TBL_HED_ROW_BGN_MKR, // text
  SYM_TBL_DLM_ROW_BGN_MKR, // text
  SYM_TBL_DAT_ROW_BGN_MKR, // text

  // block close indicator
  SYM_BTK_FEN_COD_END, // ```
  SYM_TLD_FEN_COD_END, // ~~~

  // block close marker
  SYM_THM_BRK_END_MKR, // linebreak
  SYM_PGH_END_MKR, // linebreak
  SYM_LNK_REF_DEF_END_MKR, // linebreak
  SYM_STX_END_MKR, // linebreak
  SYM_ATX_END_MKR, // linebreak
  SYM_IND_COD_END_MKR, // linebreak
  SYM_BTK_FEN_COD_END_MKR, // linebreak
  SYM_TLD_FEN_COD_END_MKR, // linebreak
  SYM_HTM_BLK_SCR_END_MKR, // linebreak
  SYM_HTM_BLK_CMT_END_MKR, // linebreak
  SYM_HTM_BLK_PRC_END_MKR, // linebreak
  SYM_HTM_BLK_DCL_END_MKR, // linebreak
  SYM_HTM_BLK_CDA_END_MKR, // linebreak
  SYM_HTM_BLK_DIV_END_MKR, // linebreak
  SYM_HTM_BLK_CMP_END_MKR, // linebreak
  SYM_BQT_END_MKR, // linebreak
  SYM_LST_END_MKR, // linebreak
  SYM_LST_ITM_END_MKR, // linebreak
  SYM_LST_ITM_CNT_END_MKR, // linebreak
  SYM_TBL_ROW_END_MKR, // linebreak

  SYM_VRT_SPC,

  // special
  SYM_NOT_FOUND,

  // marker
  SYMBOL_NAME_COUNT,
  PARSE_TABLE_SYMBOL_COUNT = SYM_LIT_LBK + 1,
  FIRST_INLINE_SYMBOL = SYM_TXT,
  LAST_INLINE_SYMBOL = SYM_HTM_DCL_NAM_END_MKR,
  FIRST_INLINE_CLOSE_MARKER_SYMBOL = SYM_FEN_COD_INF_END_MKR,
  LAST_INLINE_CLOSE_MARKER_SYMBOL = SYM_HTM_DCL_NAM_END_MKR,
  FIRST_BLOCK_SYMBOL = SYM_LIT_LBK,
  LAST_BLOCK_SYMBOL = SYM_VRT_SPC,
  FIRST_BLOCK_OPEN_SYMBOL = SYM_ASR_THM_BRK_BGN,
  LAST_BLOCK_OPEN_SYMBOL = SYM_TBL_DAT_ROW_BGN_MKR,
  FIRST_BLOCK_CLOSE_SYMBOL = SYM_THM_BRK_END_MKR,
  LAST_BLOCK_CLOSE_SYMBOL = SYM_TBL_ROW_END_MKR,
};

bool is_inl_sym(const Symbol symbol);
bool is_inl_cls_mrk_sym(const Symbol symbol);
bool is_blk_sym(const Symbol symbol);
bool is_blk_opn_sym(const Symbol symbol);
bool is_blk_cls_sym(const Symbol symbol);
bool is_paired_blk_syms(const Symbol open_symbol, const Symbol close_symbol);
Symbol get_blk_cls_sym(const Symbol open_symbol);

enum ParseState {
  PST_PGH,
  PST_ATX,
  PST_FEN_COD_INF,
  PST_TBL_DLM_ROW,
  PST_TBL_DAT_ROW,

  PST_ASR,
  PST_USC,
  PST_DEL,
  PST_ASR_USC,
  PST_ASR_DEL,
  PST_USC_DEL,
  PST_ASR_USC_DEL,
  PST_IMG_LNK,
  PST_IMG_LNK_END,
  PST_LNK_REF_DEF_CLN,
  PST_LNK_INL,
  PST_LNK_DST_EXP,
  PST_LNK_DST_IMP,
  PST_LNK_DST_IMP_PRN,
  PST_LNK_DST_END,
  PST_LNK_TIT_SQT,
  PST_LNK_TIT_DQT,
  PST_LNK_TIT_PRN,
  PST_LNK_TIT_END,
  PST_LNK_REF,
  PST_COD_SPN,
  PST_EXT_AUT_LNK_DMN_END,
  PST_AUT_LNK_HTM_OPN_TAG,
  PST_URI_AUT_LNK_SCH_END,
  PST_EML_AUT_LNK,
  PST_EML_AUT_LNK_DMN_END,
  PST_HTM_OPN_TAG,
  PST_HTM_CLS_TAG,
  PST_HTM_CLS_TAG_NAM_END,
  PST_HTM_DCL,
  PST_HTM_DCL_NAM_END,
  PST_HTM_ATR_KEY_END,
  PST_HTM_ATR_EQL,
  PST_HTM_ATR_UQT,
  PST_HTM_ATR_SQT,
  PST_HTM_ATR_DQT,
  PST_HTM_CMT,
  PST_HTM_PRC,
  PST_HTM_CDA,

  PST_IND_COD,
  PST_BTK_FEN_COD,
  PST_TLD_FEN_COD,
  PST_HTM_BLK_SCR,
  PST_HTM_BLK_CMT,
  PST_HTM_BLK_PRC,
  PST_HTM_BLK_DCL,
  PST_HTM_BLK_CDA,
  PST_HTM_BLK_DIV,
  PST_HTM_BLK_CMP,

  // special
  PST_INVALID,

  PARSE_TABLE_STATE_COUNT = PST_INVALID,
};

ParseState blk_sym_pst(const Symbol symbol);
ParseState inl_sym_pst(const Symbol symbol, const bool has_asr, const bool has_usc, const bool has_del);
bool vld_sym(const Symbol symbol, const ParseState state);

}

#endif // TREE_SITTER_MARKDOWN_PARSE_TABLE_H_
