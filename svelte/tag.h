/**
 * ------- UTILS CONTENTS --------
 * 67 - 318     -> allocator
 * 320 - 474    -> vc_vector
 * 476 - 527    -> ekstring
 * 529 - 746    -> tags
 * 748 - 1216   -> hashmap
 * -------------------------------
 * */

#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "allocator.h"
#include "vc_vector.h"
#include "ekstring.h"

// ------------------------ Tag ------------------------------
typedef enum {
  AREA = 1,
  BASE,
  BASEFONT,
  BGSOUND,
  BR,
  COL,
  COMMAND,
  EMBED,
  FRAME,
  HR,
  IMAGE,
  IMG,
  INPUT,
  ISINDEX,
  KEYGEN,
  LINK,
  MENUITEM,
  META,
  NEXTID,
  PARAM,
  SOURCE,
  TRACK,
  WBR,
  END_OF_VOID_TAGS,
  A,
  ABBR,
  ADDRESS,
  ARTICLE,
  ASIDE,
  AUDIO,
  B,
  BDI,
  BDO,
  BLOCKQUOTE,
  BODY,
  BUTTON,
  CANVAS,
  CAPTION,
  CITE,
  CODE,
  COLGROUP,
  DATA,
  DATALIST,
  DD,
  DEL,
  DETAILS,
  DFN,
  DIALOG,
  DIV,
  DL,
  DT,
  EM,
  FIELDSET,
  FIGCAPTION,
  FIGURE,
  FOOTER,
  FORM,
  H1,
  H2,
  H3,
  H4,
  H5,
  H6,
  HEAD,
  HEADER,
  HGROUP,
  HTML,
  I,
  IFRAME,
  INS,
  KBD,
  LABEL,
  LEGEND,
  LI,
  MAIN,
  MAP,
  MARK,
  MATH,
  MENU,
  METER,
  NAV,
  NOSCRIPT,
  OBJECT,
  OL,
  OPTGROUP,
  OPTION,
  OUTPUT,
  P,
  PICTURE,
  PRE,
  PROGRESS,
  Q,
  RB,
  RP,
  RT,
  RTC,
  RUBY,
  S,
  SAMP,
  SCRIPT,
  SECTION,
  SELECT,
  SLOT,
  SMALL,
  SPAN,
  STRONG,
  STYLE,
  SUB,
  SUMMARY,
  SUP,
  SVG,
  TABLE,
  TBODY,
  TD,
  TEMPLATE,
  TEXTAREA,
  TFOOT,
  TH,
  THEAD,
  TIME,
  TITLE,
  TR,
  U,
  UL,
  VAR,
  VIDEO,
  CUSTOM,
} TagType;

typedef struct Tag {
  TagType type;
  ekstring custom_tag_name;
} Tag;

static const TagType TAG_TYPES_NOT_ALLOWED_IN_PARAGRAPHS[] = {
    ADDRESS,  ARTICLE,    ASIDE,  BLOCKQUOTE, DETAILS, DIV, DL,
    FIELDSET, FIGCAPTION, FIGURE, FOOTER,     FORM,    H1,  H2,
    H3,       H4,         H5,     H6,         HEADER,  HR,  MAIN,
    NAV,      OL,         P,      PRE,        SECTION,
};
static const unsigned int TTNAIP_LEN =
    sizeof(TAG_TYPES_NOT_ALLOWED_IN_PARAGRAPHS) / sizeof(TagType);

Tag *initTag(za_Allocator *A) {
  Tag *t = (Tag *)za_Alloc(A, sizeof(Tag));
  t->type = END_OF_VOID_TAGS;
  t->custom_tag_name = NaS(A);
  return t;
}
Tag *initTagArgs(za_Allocator *A, TagType type, const ekstring name) {
  Tag *t = (Tag *)za_Alloc(A, sizeof(Tag));
  t->type = type;
  t->custom_tag_name = init_string_string(name);
  return t;
}

bool compareTags(const Tag *a, const Tag *b) {
  if (a == NULL || b == NULL) {
    if (a == NULL && b == NULL)
      return true;
    return false;
  }
  if (a->type != b->type)
    return false;
  if (a->type == CUSTOM &&
      !compare_string_string(a->custom_tag_name, b->custom_tag_name))
    return false;
  return true;
}

const bool is_void(Tag *tag) { return tag->type < END_OF_VOID_TAGS; }

const bool findTagType(const TagType *tt, TagType toFind) {
  for (int i = 0; i < TTNAIP_LEN; i++)
    if (tt[i] == toFind)
      return true;
  return false;
}

const bool findTag(vc_vector *v, Tag *tag) {
  for (size_t i = 0; i < v->count; i++)
    if (compareTags(vc_vector_at(v, i), tag))
      return true;
  return false;
}

bool can_contain(const Tag *parent, const Tag *tag) {
  TagType child = tag->type;

  switch (parent->type) {
  case LI:
    return child != LI;
  case DT:
  case DD:
    return child != DT && child != DD;
  case P:
    return !findTagType(TAG_TYPES_NOT_ALLOWED_IN_PARAGRAPHS, tag->type);
  case COLGROUP:
    return child == COL;
  case RB:
  case RT:
  case RP:
    return child != RB && child != RT && child != RP;
  case OPTGROUP:
    return child != OPTGROUP;
  case TR:
    return child != TR;
  case TD:
  case TH:
    return child != TD && child != TH && child != TR;
  default:
    return true;
  }
}


#endif
