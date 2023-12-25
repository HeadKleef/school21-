#include "s21_string.h"

void *s21_to_upper(const char *str) {
  s21_size_t i = 0, j = s21_strlen(str);
  char *str_clone = (char *)str;
  for (; i < j; i++) {
    if (str[i] != '\0' && str[i] > 96 && str[i] < 123)
      str_clone[i] = str[i] - 32;
  }
  return str_clone;
}

void *s21_to_lower(const char *str) {
  s21_size_t i = 0, j = s21_strlen(str);
  char *str_clone = (char *)str;
  for (; i < j; i++) {
    if (str[i] != '\0' && str[i] > 64 && str[i] < 91)
      str_clone[i] = str[i] + 32;
  }
  return str_clone;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  //   s21_size_t src_size = s21_strlen(src), str_size = s21_strlen(str);
  //   char *res = calloc(src_size + str_size + 2, 1);
  //   char *str_clone = (char *)str;
  //   char *r, *s;
  //   for (r = res, s = str_clone; *s || *src; r++) {
  //     if (s == str_clone + start_index && *src)
  //       *r = *(src++);
  //     else
  //       *r = *(s++);
  //   }
  //   *r = 0;

  //   return (void *)res;
  // }
  s21_size_t str_size = s21_strlen(str), src_size = s21_strlen(src), n = 0,
             j = 0;
  char *src_clone = (char *)src;
  char *str_clone = (char *)str;
  char *result = calloc(src_size + str_size + 2, 1);
  char buff[1000] = {0};
  while (src_clone[n] != '\0') {
    buff[n] = src[n];
    n++;
  }

  n = 0;
  for (; j < str_size ; j ++) {
    buff[start_index + (str_size + j)] = buff[start_index + j];
    buff[start_index + j] = str_clone[n];
    n++;
  }
  printf("buff = %s str_size = %d\n", buff, str_size);
  s21_size_t l = 0;
  while (buff[l] != '\0') {
    result[l] = buff[l];
    l++;
  }
  printf("result = %s\n", result);
  return (void *)result;
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
