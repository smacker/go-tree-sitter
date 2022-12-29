#include "./util.h"

namespace tree_sitter_markdown {

bool adv_blk_htm_end(Lexer &lxr) {
  if (lxr.adv_if('<')) {
    if (lxr.adv_if('/')) {
      if (lxr.adv_if('p') || lxr.adv_if('P')) {
        if (lxr.adv_if('r') || lxr.adv_if('R')) {
          if (lxr.adv_if('e') || lxr.adv_if('E')) {
            if (lxr.adv_if('>')) {
              return true; // </pre>
        }}}
      } else if (lxr.adv_if('s') || lxr.adv_if('S')) {
        if (lxr.adv_if('c') || lxr.adv_if('C')) {
          if (lxr.adv_if('r') || lxr.adv_if('R')) {
            if (lxr.adv_if('i') || lxr.adv_if('I')) {
              if (lxr.adv_if('p') || lxr.adv_if('P')) {
                if (lxr.adv_if('t') || lxr.adv_if('T')) {
                  if (lxr.adv_if('>')) {
                    return true; // </script>
          }}}}}
        } else if (lxr.adv_if('t') || lxr.adv_if('T')) {
          if (lxr.adv_if('y') || lxr.adv_if('Y')) {
            if (lxr.adv_if('l') || lxr.adv_if('L')) {
              if (lxr.adv_if('e') || lxr.adv_if('E')) {
                if (lxr.adv_if('>')) {
                  return true; // </style>
        }}}}}
      }
    }
  }
  return false;
}

bool vld_sym(const Symbol sym, const BlockContextStack &blk_ctx_stk) {
  TREE_SITTER_MARKDOWN_ASSERT(!blk_ctx_stk.empty());
  return vld_sym(sym, blk_ctx_stk.back().pst());
}
bool vld_sym(const Symbol sym, const BlockContextStack &blk_ctx_stk, const InlineContextStack &inl_ctx_stk) {
  return inl_ctx_stk.empty()
    ? vld_sym(sym, blk_ctx_stk)
    : inl_ctx_stk.back().is_vld_pst() && vld_sym(sym, inl_ctx_stk.back().pst());
}

bool is_lst_itm_bgn(const Symbol sym) {
  return sym == SYM_ASR_LST_ITM_BGN
      || sym == SYM_HYP_LST_ITM_BGN
      || sym == SYM_PLS_LST_ITM_BGN
      || sym == SYM_DOT_LST_ITM_BGN
      || sym == SYM_RPR_LST_ITM_BGN;
}

}
