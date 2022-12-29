#ifndef TREE_SITTER_MARKDOWN_BLOCK_CONTEXT_H_
#define TREE_SITTER_MARKDOWN_BLOCK_CONTEXT_H_

#include <vector>
#include "./parse_table.h"
#include "./shared_type.h"

namespace tree_sitter_markdown {

struct BlockContext {
private:
  bool has_fst_ctn_;
  Symbol sym_;
  LexedLength len_;
  LexedColumn ind_;
  ParseState pst_;
public:
  bool has_fst_ctn() const;
  Symbol sym() const;
  LexedLength len() const;
  LexedColumn ind() const;
  ParseState pst() const;

  void mrk_has_fst_ctn();

  BlockContext();
  BlockContext(const Symbol symbol, const LexedLength length, const LexedColumn indentation);

  unsigned serialize(unsigned char *buffer) const;
  unsigned deserialize(const unsigned char *buffer);
};

struct BlockContextStack {
public:
  typedef std::vector<BlockContext>::iterator Iterator;
  typedef std::vector<BlockContext>::const_iterator ConstIterator;
  typedef std::vector<BlockContext>::reverse_iterator ReverseIterator;
  typedef std::vector<BlockContext>::const_reverse_iterator ConstReverseIterator;
private:
  std::vector<BlockContext> stk_;
public:
  bool empty() const;
  BlockContext &back();
  const BlockContext &back() const;
  ConstIterator begin() const;
  ConstIterator end() const;
  ConstReverseIterator rbegin() const;
  ConstReverseIterator rend() const;

  void mrk_has_fst_ctn();

  void clear();
  unsigned serialize(unsigned char *buffer) const;
  unsigned deserialize(const unsigned char *buffer);

  void push(const BlockContext &block_context);
  void pop();
};

}

#endif // TREE_SITTER_MARKDOWN_BLOCK_CONTEXT_H_
