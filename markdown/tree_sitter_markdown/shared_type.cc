#include "./shared_type.h"

#include <cassert>

namespace tree_sitter_markdown {

LexedIndex LexedPosition::idx() const { return idx_; }
LexedRow LexedPosition::row() const { return row_; }
LexedColumn LexedPosition::col() const { return col_; }

void LexedPosition::set(const LexedPosition &pos) { idx_ = pos.idx_; row_ = pos.row_; col_ = pos.col_; }
void LexedPosition::set(const LexedIndex idx, const LexedRow row, const LexedColumn col) { idx_ = idx; row_ = row; col_ = col; }
void LexedPosition::add(const LexedIndex offset_idx) { idx_ += offset_idx; col_ += offset_idx; }

LexedPosition::LexedPosition(): idx_(LEXED_INDEX_MAX), row_(LEXED_ROW_MAX), col_(LEXED_COLUMN_MAX) {}
LexedPosition::LexedPosition(const LexedIndex idx, const LexedRow row, const LexedColumn col): idx_(idx), row_(row), col_(col) {}
LexedPosition LexedPosition::clone_add(const LexedIndex offset_idx) const { return LexedPosition(idx_ + offset_idx, row_, col_ + offset_idx); }

LexedLength LexedPosition::dist(const LexedPosition &pos) const {
  TREE_SITTER_MARKDOWN_ASSERT(idx_ <= pos.idx());
  return pos.idx() - idx_;
}

}
