#ifndef TREE_SITTER_MARKDOWN_BLOCK_SCAN_H_
#define TREE_SITTER_MARKDOWN_BLOCK_SCAN_H_

#include "./block_context.h"
#include "./block_delimiter.h"
#include "./inline_context.h"
#include "./inline_delimiter.h"
#include "./lexer.h"
#include "./parse_table.h"

namespace tree_sitter_markdown {

void scn_blk(Lexer &lexer, BlockDelimiterList &block_delimiters, const BlockContextStack &block_context_stack, const LexedColumn indentation);
bool /*is_interrupted*/ scn_eol(Lexer &lexer, BlockDelimiterList &block_delimiters, BlockContextStack &block_context_stack);

LexedColumn adv_blk_pfx(Lexer &lexer, BlockContextStack::ConstIterator &block_context_iterator, const BlockContextStack::ConstIterator &block_context_end_iterator);
LexedColumn adv_blk_pfx(Lexer &lexer, BlockContextStack::ConstIterator &block_context_iterator, const BlockContextStack::ConstIterator &block_context_end_iterator, LexedPosition &last_non_whitespace_end_position);
bool scn_tbl_dlm_row(Lexer &lexer, const uint16_t table_column_count);

enum BlockScanResult {
  BSR_REJECT = 0,
  BSR_FAILED,
  BSR_ACCEPT,
};

BlockScanResult scn_ind_cod(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);
BlockScanResult scn_blk_asr(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);
BlockScanResult scn_blk_btk(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);
BlockScanResult scn_blk_eql(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);
BlockScanResult scn_blk_hsh(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);
BlockScanResult scn_blk_hyp(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);
BlockScanResult scn_blk_lng(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);
BlockScanResult scn_blk_num(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);
BlockScanResult scn_blk_pls(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);
BlockScanResult scn_blk_rng(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);
BlockScanResult scn_blk_tld(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);
BlockScanResult scn_blk_usc(Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line);

BlockScanResult scn_fen_cod(
  LexedCharacter delimiter_character, Symbol symbol, const LexedLength min_length, const bool allow_non_whitespace, const bool allow_delimiter_character,
  Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line
);
BlockScanResult scn_num_lst_itm(
  const bool allow_dot, const bool allow_rpr,
  Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line
);
BlockScanResult scn_stx_and_thm_brk_and_lst_itm(
  LexedCharacter delimiter_character, Symbol stx_symbol, Symbol thm_brk_symbol, Symbol lst_itm_symbol,
  Lexer &lexer, BlockDelimiterList &block_delimiters, const LexedColumn indentation, const bool is_passed_all_block_context, const bool is_paragraph_continuous_line
);

}

#endif // TREE_SITTER_MARKDOWN_BLOCK_SCAN_H_
