#include "s21_string.h"

void *s21_to_upper(const char *str) {
  s21_size_t i = 0, j = s21_strlen(str);
  char *str_clone = (char *)str;

  for (; i < j && str[i] > 96 && str[i] < 123; i++) {
    if (str[i] != '\0') str_clone[i] = str[i] - 32;
  }
  return str_clone;
}

void *s21_to_lower(const char *str) {
  s21_size_t i = 0, j = s21_strlen(str);
  char *str_clone = (char *)str;
  for (; i < j && str[i] > 64 && str[i] < 91; i++) {
    if (str[i] != '\0') str_clone[i] = str[i] + 32;
  }
  return str_clone;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = malloc(s21_strlen(str) + s21_strlen(src));
  char *str_clone = (char *)str;
  char *r, *s;
  for (r = res, s = str_clone; *s || *src; r++) {
    if (s == str_clone + start_index && *src)
      *r = *(src++);
    else
      *r = *(s++);
  }
  *r = 0;
  free(res);
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t i = 0, trim_count = 0;
  char *src_clone = (char *)src;
  char *trim_char = (char *)trim_chars;
  for (; trim_count < s21_strlen(trim_char); trim_count++) {
    while (src_clone[i] != trim_char[trim_count]) {
      i++;
    }
    for (; i < s21_strlen(src); i++) {
      src_clone[i] = src_clone[i + 1];
    }
    i = 0;
  }
  for (trim_count = 0; trim_count < s21_strlen(trim_char); trim_count++) {
    i = s21_strlen(src_clone);
    while (src_clone[i] != trim_char[trim_count]) {
      i--;
    }
    for (; i < s21_strlen(src); i++) {
      src_clone[i] = src_clone[i + 1];
    }
    i = s21_strlen(src_clone);
  }

  return src_clone;
}
