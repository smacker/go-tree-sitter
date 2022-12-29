#ifndef TREE_SITTER_MARKDOWN_SHARED_TYPE_H_
#define TREE_SITTER_MARKDOWN_SHARED_TYPE_H_

#include <stdint.h>

namespace tree_sitter_markdown {

typedef uint16_t LexedIndex;
typedef uint16_t LexedRow;
typedef uint16_t LexedColumn;
typedef int32_t LexedCharacter;
typedef uint16_t LexedLength;
typedef uint16_t InlineDelimiterCustomData;

#define LEXED_INDEX_MAX UINT16_MAX
#define LEXED_ROW_MAX UINT16_MAX
#define LEXED_COLUMN_MAX UINT16_MAX
#define LEXED_CHARACTER_MAX INT32_MAX
#define LEXED_LENGTH_MAX UINT16_MAX
#define INLINE_DELIMITER_CUSTOM_DATA_MAX UINT16_MAX

#define NULL_PTR 0

struct LexedPosition {
private:
  LexedIndex idx_;
  LexedRow row_;
  LexedColumn col_;
public:
  LexedIndex idx() const;
  LexedRow row() const;
  LexedColumn col() const;

  void set(const LexedPosition &position);
  void set(const LexedIndex index, const LexedRow row, const LexedColumn column);
  void add(const LexedIndex offset_index);

  LexedPosition();
  LexedPosition(const LexedIndex index, const LexedRow row, const LexedColumn column);
  LexedPosition clone_add(const LexedIndex offset_index) const;

  LexedLength dist(const LexedPosition &position) const;
};

}

#endif // TREE_SITTER_MARKDOWN_SHARED_TYPE_H_
