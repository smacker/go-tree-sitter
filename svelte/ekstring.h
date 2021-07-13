#ifndef EKSTRING_H
#define EKSTRING_H

#include "allocator.h"
#include <string.h>

typedef struct {
  const char *buf;
  size_t length;
  za_Allocator *A;
} ekstring;

#define NaS(x) ((ekstring){NULL, 0, (x)})
const ekstring init_string_str(za_Allocator *A, const char *buf,
                               size_t length) {
  char *s = (char *)za_Alloc(A, sizeof(char) * (length + 1));
  strncpy(s, buf, length);
  s[length] = '\0';
  return (const ekstring){s, length, A};
}
const ekstring init_string_string(const ekstring str) {
  za_Allocator *A = str.A;
  char *s = (char *)za_Alloc(A, (str.length + 1) * sizeof(char));
  strncpy(s, str.buf, str.length + 1);
  return (const ekstring){s, str.length, A};
}
bool compare_string_string(const ekstring s1, const ekstring s2) {
  if (s1.length == s2.length)
    return strncmp(s1.buf, s2.buf, s1.length) == 0;
  return false;
}
const ekstring concat_string_string(const ekstring s1, const ekstring s2) {
  const size_t length = s1.length + s2.length + 1;
  char *s = (char *)za_Alloc(s1.A, length);
  strncpy(s, s1.buf, s1.length);
  strncpy(s + s1.length, s2.buf, s2.length);
  s[length] = '\0';
  return (const ekstring){s, length - 1, s1.A};
}
const ekstring concat_string_char(const ekstring s1, const char c) {
  if (s1.buf == NULL) {
    char *s = (char *)za_Alloc(s1.A, 2);
    s[0] = c;
    s[1] = '\0';
    return (const ekstring){s, 1, s1.A};
  }
  size_t length = s1.length + 2;
  char *s = (char *)za_Alloc(s1.A, length);
  strncpy(s, s1.buf, s1.length);
  s[length - 2] = c;
  s[length - 1] = '\0';
  return (const ekstring){s, length - 1, s1.A};
}
const int parse_int(const ekstring s1) { return atoi(s1.buf); }
const char *get_string_cstring(const ekstring s) { return s.buf; }
void destroy_string(const ekstring s) {
  // za_Free(s.A, (void *)s.buf);
}

#endif
