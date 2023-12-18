#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *str_clone = (const unsigned char *)str;
  s21_size_t i = 0;
  char *res = S21_NULL;
  while (i < n) {
    if (str_clone[i] == c) {
      res = (void *)str_clone + i;
    }
    i++;
  }
  return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *str1_clone = (const unsigned char *)str1;
  const unsigned char *str2_clone = (const unsigned char *)str2;
  s21_size_t i = 0;
  while (*str1_clone && (*str1_clone == *str2_clone) && i < n) {
    str1_clone++;
    str2_clone++;
    i++;
  }
  return *str1_clone - *str2_clone;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_clone = (unsigned char *)dest;
  const unsigned char *src_clone = (const unsigned char *)src;
  s21_size_t i = 0;
  for (; i <= n; i++) {
    dest_clone[i] = src_clone[i];
  }
  return dest_clone;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *str_clone = (unsigned char *)str;
  s21_size_t i = 0;
  while (i < n) {
    str_clone[i] = c;
    i++;
  }
  return str_clone;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n) {
    dest[i] = src[i];
    i++;
  }
  return dest;
}

char *s21_strchr(const char *str, int c) {
  s21_size_t i = 0;
  char *result = S21_NULL;
  while (str[i] != '\0' && str[i] != (char)c) {
    i++;
  }
  if (str[i] != '\0') result = (char *)&str[i];

  return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0;
  while (*str1 && (*str1 == *str2) && i < n) {
    str1++;
    str2++;
    i++;
  }
  return *str1 - *str2;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0, slen = s21_strlen(src);
  for (; i <= slen && i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  for (; !s21_strchr(str2, str1[i]); i++) {
  }
  return i;
}

// char s21_strerror(){}

s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  return (char *)str1 + s21_strcspn(str1, str2);
}

char *s21_strrchr(const char *str, int c) {
  s21_size_t i = s21_strlen(str) - 1;
  char *result = S21_NULL;
  while (str[i] != '\0' && str[i] != (char)c) {
    i--;
  }
  if (str[i] != '\0') result = (char *)&str[i];

  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t i = 0;
  char *res = S21_NULL;
  while (i < s21_strlen(haystack)) {
    if (haystack[i] == needle[i]) {
      res = (char *)haystack + i;
    }
    i++;
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *lastToken = S21_NULL;
  char *check = S21_NULL;
  if (str != S21_NULL) {
    lastToken = str;
  } else if (lastToken == S21_NULL) {
    check = S21_NULL;
  }
  if (lastToken != S21_NULL) {
    char *start = lastToken;
    while (*start != '\0' && s21_strchr(delim, *start) != S21_NULL) {
      start++;
    }
    if (*start == '\0') {
      lastToken = S21_NULL;
      check = S21_NULL;
    } else
      check = start;

    char *end = start + 1;
    while (*end != '\0' && s21_strchr(delim, *end) == S21_NULL) {
      end++;
    }
    if (*end != '\0') {
      *end = '\0';
      lastToken = end + 1;
    } else {
      lastToken = S21_NULL;
    }
  }
  return check;
}

/* UNUSED FUNCTIONS*/
/********************************************************/
/* int s21_strcmp(const char *str1, const char *str2) { */
/*   while (*str1 && (*str1 == *str2)) {                */
/*     str1++;                                          */
/*     str2++;                                          */
/*   }                                                  */
/*   return *str1 - *str2;                              */
/* }                                                    */
/*                                                      */
/* char *s21_strcpy(char *dest, const char *src) {      */
/*   s21_size_t i = 0, slen = s21_strlen(src);          */
/*   for (i = 0; i <= slen; i++) {                      */
/*     dest[i] = src[i];                                */
/*   }                                                  */
/*   return dest;                                       */
/* }                                                    */
/********************************************************/