#ifndef TREE_SITTER_MARKDOWN_BLOCK_DELIMITER_H_
#define TREE_SITTER_MARKDOWN_BLOCK_DELIMITER_H_

#include <list>
#include "./parse_table.h"
#include "./shared_type.h"
#include "./token_type.h"

namespace tree_sitter_markdown {

struct BlockDelimiter {
private:
  Symbol sym_;
  LexedLength len_;
  LexedColumn ind_;
  bool has_pos_;
  LexedPosition pos_;
  LexedPosition end_pos_;
public:
  Symbol sym() const;
  LexedLength len() const;
  LexedColumn ind() const;
  bool has_pos() const;
  const LexedPosition &pos() const;
  const LexedPosition &end_pos() const;

  void set_len(const LexedLength length);
  void set_ind(const LexedColumn indentation);
  void set_pos(const LexedPosition &position, const LexedPosition &end_position);
  void drop_pos();

  BlockDelimiter();
  BlockDelimiter(const Symbol symbol, const LexedLength length, const LexedColumn indentation = 0);
  BlockDelimiter(const Symbol symbol, const LexedPosition &position, const LexedPosition &end_position, const LexedColumn indentation = 0);

  unsigned serialize(unsigned char *buffer) const;
  unsigned deserialize(const unsigned char *buffer);

  TokenType tkn_typ(LexedCharacter lookahead_character) const;
};

struct BlockDelimiterList {
public:
  typedef std::list<BlockDelimiter>::iterator Iterator;
  typedef std::list<BlockDelimiter>::const_iterator ConstIterator;
private:
  std::list<BlockDelimiter> list_;
public:
  bool empty() const;
  BlockDelimiter &front();
  BlockDelimiter &back();
  Iterator end();
  BlockDelimiter *lit_lbk(const LexedRow row);

  void clear();
  void drop_pos();
  unsigned serialize(unsigned char *buffer) const;
  unsigned deserialize(const unsigned char *buffer);

  void pop_front();
  void push_back(const BlockDelimiter &delimiter);
  Iterator insert(const Iterator itr, const BlockDelimiter &delimiter);
  Iterator insert(const LexedRow row, const BlockDelimiter &delimiter);
  Iterator erase(Iterator iterator, Iterator end_iterator);

  void push_vtr_spc(const LexedLength count);

  void transfer_to(BlockDelimiterList &list);
  void transfer_to(BlockDelimiterList &list, const uint16_t count);
};

}

#endif // TREE_SITTER_MARKDOWN_BLOCK_DELIMITER_H_
