#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  s21_size_t i = 0, j = s21_strlen(str);
  char *res = calloc(j, sizeof(char *));
  for (; i < j; i++) {
    if (str[i] != '\0' && str[i] > 96 && str[i] < 123)
      res[i] = str[i] - 32;
    else
      res[i] = str[i];
  }
  return res;
}

void *s21_to_lower(const char *str) {
  s21_size_t i = 0, j = s21_strlen(str);
  char *res = calloc(j, sizeof(char *));
  for (; i < j; i++) {
    if (str[i] != '\0' && str[i] > 64 && str[i] < 91)
      res[i] = str[i] + 32;
    else
      res[i] = str[i];
  }
  return res;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t src_size = s21_strlen(src), str_size = s21_strlen(str);
  char *res = calloc(src_size + str_size + 2, 1);
  char *src_clone = (char *)src;
  char *r, *s;
  for (r = res, s = src_clone; *s || *str; r++) {
    if (s == src_clone + start_index && *str)
      *r = *(str++);
    else
      *r = *(s++);
  }
  *r = 0;
  return (void *)res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t i = 0, trim_count = 0, j = s21_strlen(trim_chars);
  char *trim_char = (char *)trim_chars;
  char *src_clone = (char *)src;
  char *res = calloc(s21_strlen(src), sizeof(char *));
  while (src_clone[i] != '\0' && i <= s21_strlen(src)) {
    res[i] = src_clone[i];
    i++;
  }
  i = 0;
  if (j != 0 && s21_strlen(src) != 0) {
    for (; trim_count < s21_strlen(trim_char); trim_count++) {
      while (res[i] != trim_char[trim_count]) {
        i++;
      }
      for (; i < s21_strlen(src); i++) {
        res[i] = res[i + 1];
      }
      i = 0;
    }
    for (trim_count = 0; trim_count < s21_strlen(trim_char); trim_count++) {
      i = s21_strlen(src);
      while (res[i] != trim_char[trim_count] && i > 0) {
        i--;
      }
      for (; i < s21_strlen(src) && i != 0; i++) {
        res[i] = res[i + 1];
      }
      i = s21_strlen(src);
    }
  }
  return res;
}
