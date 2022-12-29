#ifndef TREE_SITTER_MARKDOWN_UTIL_H_
#define TREE_SITTER_MARKDOWN_UTIL_H_

#include "./block_context.h"
#include "./lexer.h"
#include "./inline_context.h"
#include "./parse_table.h"

namespace tree_sitter_markdown {

bool adv_blk_htm_end(Lexer &lexer);
bool vld_sym(const Symbol symbol, const BlockContextStack &block_context_stack);
bool vld_sym(const Symbol symbol, const BlockContextStack &block_context_stack, const InlineContextStack &inline_context_stack);
bool is_lst_itm_bgn(const Symbol symbol);

}

#endif // TREE_SITTER_MARKDOWN_UTIL_H_
