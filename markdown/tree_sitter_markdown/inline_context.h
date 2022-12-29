#ifndef TREE_SITTER_MARKDOWN_INLINE_CONTEXT_H_
#define TREE_SITTER_MARKDOWN_INLINE_CONTEXT_H_

#include <list>
#include "./inline_delimiter.h"
#include "./parse_table.h"

namespace tree_sitter_markdown {

struct InlineContext {
private:
  InlineDelimiterList::Iterator dlm_itr_;
  ParseState pst_;
  bool has_asr_;
  bool has_usc_;
  bool has_del_;
  bool has_cln_;
  LexedLength btk_len_;
public:
  InlineDelimiterList::Iterator dlm_itr() const;
  ParseState pst() const;
  bool is_vld_pst() const;
  bool has_asr() const;
  bool has_usc() const;
  bool has_del() const;
  bool has_cln() const;
  LexedLength btk_len() const;

  InlineContext(const InlineDelimiterList::Iterator delimiter_iterator);
  InlineContext(const InlineDelimiterList::Iterator delimiter_iterator, const InlineContext &parent_context);

  void upd_pst();
};

struct InlineContextStack {
public:
  typedef std::list<InlineContext>::iterator Iterator;
  typedef std::list<InlineContext>::const_iterator ConstIterator;
  typedef std::list<InlineContext>::const_reverse_iterator ConstReverseIterator;
private:
  std::list<InlineContext> stk_;
public:
  bool empty() const;
  InlineContext &back();
  const InlineContext &back() const;
  const InlineContext &back(const uint8_t offset) const;

  void clear();

  void push(const InlineDelimiterList::Iterator delimiter_iterator);
  void pop();
  void pop_erase(InlineDelimiterList &inline_delimiter_list);
  void pop_yes();
  void pop_paired(InlineDelimiter *const end_delimiter);
  void pop_paired(const InlineDelimiterList::Iterator end_delimiter_iterator);
  bool pop_all_lnk_bgn(InlineDelimiterList::Iterator &first_popped_lnk_bgn_iterator);
};

}

#endif // TREE_SITTER_MARKDOWN_INLINE_CONTEXT_H_
