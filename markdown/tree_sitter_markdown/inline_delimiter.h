#ifndef TREE_SITTER_MARKDOWN_INLINE_DELIMITER_H_
#define TREE_SITTER_MARKDOWN_INLINE_DELIMITER_H_

#include <list>
#include "./parse_table.h"
#include "./shared_type.h"
#include "./token_type.h"

namespace tree_sitter_markdown {

struct MinimizedInlineDelimiter {
private:
  bool yes_;
  Symbol sym_;
  LexedLength len_;
public:
  bool yes() const;
  Symbol sym() const;
  LexedLength len() const;

  MinimizedInlineDelimiter();
  MinimizedInlineDelimiter(const bool yes, const Symbol symbol, const LexedIndex length);

  unsigned serialize(unsigned char *buffer) const;
  unsigned deserialize(const unsigned char *buffer);

  void print() const;

  TokenType tkn_typ(LexedCharacter current_character, LexedCharacter lookahead_character) const;
};

struct MinimizedInlineDelimiterList {
public:
  typedef std::list<MinimizedInlineDelimiter>::iterator Iterator;
  typedef std::list<MinimizedInlineDelimiter>::const_iterator ConstIterator;
private:
  std::list<MinimizedInlineDelimiter> list_;
public:
  bool empty() const;
  MinimizedInlineDelimiter &front();

  void pop_front();
  void push_back(const MinimizedInlineDelimiter &delimiter);

  void clear();
  unsigned serialize(unsigned char *buffer) const;
  unsigned deserialize(const unsigned char *buffer);
};

struct InlineDelimiter {
private:
  bool yes_;
  Symbol sym_;
  LexedLength len_;
  LexedLength ori_len_;
  LexedPosition pos_;
  LexedPosition end_pos_;
  InlineDelimiterCustomData ctm_dat_;
  InlineDelimiter *end_dlm_;
public:
  bool yes() const;
  Symbol sym() const;
  LexedLength len() const;
  LexedLength ori_len() const;
  const LexedPosition &pos() const;
  const LexedPosition &end_pos() const;
  InlineDelimiterCustomData ctm_dat() const;
  bool has_end_dlm() const;
  InlineDelimiter *end_dlm() const;

  void set_yes(const bool yes);
  void set_sym(const Symbol symbol);
  void set_end_pos(const LexedPosition &position);
  void set_ctm_dat(const InlineDelimiterCustomData custom_data);
  void set_end_dlm(InlineDelimiter *const end_delimiter);
  void set_end_dlm(std::list<InlineDelimiter>::iterator end_delimiter_itr);

  InlineDelimiter(const bool yes, const Symbol symbol, const LexedPosition &position, const LexedPosition &end_position);

  MinimizedInlineDelimiter to_min() const;
};

struct InlineDelimiterList {
public:
  typedef std::list<InlineDelimiter>::iterator Iterator;
  typedef std::list<InlineDelimiter>::const_iterator ConstIterator;
private:
  std::list<InlineDelimiter> list_;
public:
  bool empty() const;
  InlineDelimiter &front();
  Iterator end();

  void clear();

  void pop_front();
  Iterator insert(Iterator next_iterator, const InlineDelimiter &delimiter);
  Iterator erase(Iterator iterator);
  Iterator erase(Iterator iterator, Iterator end_iterator);

  void transfer_to(MinimizedInlineDelimiterList &minimized_list);
};

}

#endif // TREE_SITTER_MARKDOWN_INLINE_DELIMITER_H_
