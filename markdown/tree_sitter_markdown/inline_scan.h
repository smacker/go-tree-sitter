#ifndef TREE_SITTER_MARKDOWN_INLINE_SCAN_H_
#define TREE_SITTER_MARKDOWN_INLINE_SCAN_H_

#include "./block_context.h"
#include "./block_delimiter.h"
#include "./inline_context.h"
#include "./inline_delimiter.h"
#include "./lexer.h"
#include "./parse_table.h"

namespace tree_sitter_markdown {

void scn_mid(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, InlineDelimiterList::Iterator &next_inline_delimiter_iterator, const InlineDelimiterList::Iterator &end_inline_delimiter_iterator, LexedIndex &end_index, const bool should_flush_inline_context_stack);

Symbol scn_inl(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack);
Symbol scn_inl(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, InlineDelimiterList::Iterator &next_inline_delimiter_iterator, const InlineDelimiterList::Iterator &end_inline_delimiter_iterator, LexedIndex &end_index, const bool should_flush_inline_context_stack);

bool scn_blk_txt(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack);

bool scn_ext_aut_lnk(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);

bool scn_inl_amp(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_asr(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_bng(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_bsl(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator, LexedIndex &end_index);
bool scn_inl_btk(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_cln(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_dqt(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_eql(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_hsh(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_hyp(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_lbt(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_lng(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_lpr(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_pip(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator, LexedIndex &end_index);
bool scn_inl_qus(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_rbt(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_rng(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_rpr(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_slh(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_sqt(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_tld(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool scn_inl_usc(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);

bool scn_inl_txt(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);

bool scn_aut_lnk_htm_opn_tag_txt(
  Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator
);
bool scn_dlm_run(
  LexedCharacter delimiter_character, Symbol bgn_symbol, Symbol end_symbol, bool (*can_open_delimiter)(LexedCharacter, LexedCharacter), bool (*can_close_delimiter)(LexedCharacter, LexedCharacter), bool (InlineContext::*has_delimiter)() const,
  Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator
);
bool scn_lnk_tit_bgn(
  LexedCharacter delimiter_character, Symbol bgn_symbol,
  Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator
);
bool scn_lnk_tit_end(
  LexedCharacter delimiter_character, Symbol bgn_symbol, Symbol end_symbol,
  Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator
);
bool scn_htm_atr_val_bgn(
  LexedCharacter delimiter_character, Symbol bgn_symbol,
  Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator
);
bool scn_htm_atr_val_end(
  LexedCharacter delimiter_character, Symbol bgn_symbol, Symbol end_symbol,
  Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator
);

bool hdl_lnk_dst_imp_bgn_mkr(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool hdl_lnk_dst_imp_end_mkr(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool hdl_htm_atr_uqt_bgn_mkr(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
bool hdl_htm_atr_uqt_end_mkr(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, const InlineDelimiterList::Iterator &next_inline_delimiter_iterator);
void hdl_paired_lnk_end(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack);
void hdl_paired_lnk_ref_def(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack);
void hdl_unpaired_inl_dlm(Lexer &lexer, InlineDelimiterList &inline_delimiters, InlineContextStack &inline_context_stack, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack, InlineDelimiterList::Iterator &next_inline_delimiter_iterator, const InlineDelimiterList::Iterator &end_inline_delimiter_iterator);

}

#endif // TREE_SITTER_MARKDOWN_INLINE_SCAN_H_
