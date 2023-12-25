#include "s21_string.h"

/***************************** MEMCHR *****************************/
/*    поиск первого вхождения символа c (беззнаковый тип)        */
/*в первых n байтах строки, на которую указывает аргумент str.   */
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

/***************************** MEMCMP *****************************/
/*        Сравнивает первые n байтов str1 и str2.                 */
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

/***************************** MEMCPY *****************************/
/*            Копирует n символов из src в dest.                  */
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_clone = (unsigned char *)dest;
  const unsigned char *src_clone = (const unsigned char *)src;
  s21_size_t i = 0;
  for (; i <= n; i++) {
    dest_clone[i] = src_clone[i];
  }
  return dest_clone;
}

/***************************** MEMSET *****************************/
/* Копирует символ c (беззнаковый тип) в первые n символов строки,*/
/*              на которую указывает аргумент str.                */
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *str_clone = (unsigned char *)str;
  s21_size_t i = 0;
  while (i < n) {
    str_clone[i] = c;
    i++;
  }
  return str_clone;
}

/**************************** STRNCAT *****************************/
/*   Добавляет строку, на которую указывает src, в конец строки,  */
/*       на которую указывает dest, длиной до n символов.         */
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n) {
    dest[i] = src[i];
    i++;
  }
  return dest;
}

/***************************** STRCHR *****************************/
/*  Выполняет поиск первого вхождения символа c (беззнаковый тип) */
/*        в строке, на которую указывает аргумент str.            */
char *s21_strchr(const char *str, int c) {
  s21_size_t i = 0;
  char *result = S21_NULL;
  while (str[i] != '\0' && str[i] != (char)c) {
    i++;
  }
  if (str[i] != '\0') result = (char *)&str[i];

  return result;
}

/**************************** STRNCMP *****************************/
/*        Сравнивает не более первых n байтов str1 и str2.        */
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0;
  while (*str1 && (*str1 == *str2) && i < n) {
    str1++;
    str2++;
    i++;
  }
  return *str1 - *str2;
}

/**************************** STRNCPY *****************************/
/*               Копирует до n символов из строки,                */
/*               на которую указывает src, в dest.                */
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0, slen = s21_strlen(src);
  for (; i <= slen && i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}

/**************************** STRNSPN *****************************/
/*          Вычисляет длину начального сегмента str1,             */
/*   который полностью состоит из символов, не входящих в str2.   */
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  for (; !s21_strchr(str2, str1[i]); i++) {
  }
  return i;
}

/**************************** STRERROR ****************************/
/*      Выполняет поиск во внутреннем массиве номера ошибки       */
/* errnum и возвращает указатель на строку с сообщением об ошибке.*/
/* Нужно объявить макросы, содержащие массивы сообщений об ошибке */
/* для операционных систем mac и linux. Описания ошибок есть в    */
/*   оригинальной библиотеке. Проверка текущей ОС осуществляется  */
/*               с помощью директив.                              */

void s21_reverse_str(char *dest, char *str) {
  s21_size_t len = s21_strlen(str), i = 0;
  for (s21_size_t j = (len - 1); i < len; i++, j--) {
    dest[i] = str[j];
  }
  dest[i] = '\0';
}

char *s21_convert_from_int(int num) {
  char tmp[20];
  static char result[20];
  int i = 0;
  int n = num;
  while (n != 0) {
    if (n < 0) {
      tmp[i] = (n * (-1) % 10) + '0';
    } else {
      tmp[i] = (n % 10) + '0';
    }
    n /= 10;
    i++;
  }
  if (num < 0) {
    tmp[i++] = '-';
  }
  tmp[i] = '\0';
  s21_reverse_str(result, tmp);
  return result;
}

char *s21_strerror(int errnum) {
  static char res[100] = {0};
  ARRAY;
  int flag = 0;
  for (int i = 0; i < ERR_MAX; i++) {
    if (errnum == i) {
      s21_strcpy(res, errlist[i]);
      flag = -1;
    }
  }
  if (flag == 0) {
    char str[100] = ERROR;
    char *errnum_str = s21_convert_from_int(errnum);
    char *tmp = s21_strcat(str, errnum_str);
    s21_strcpy(res, tmp);
  }
  return res;
}

// char *s21_strerror(int errnum) {
//   char *res = S21_NULL;
//   ARRAY;
//   s21_size_t flag = 0, i = 0;
//   while (i <= ERR_MAX) {
//     if (errnum == i) {
//       res = errlist[i];
//       flag = -1;
//       break;
//     }
//     i++;
//   }
//   // if (flag == 0) {
//   //   char *err = ERROR;
//   //   char *errnum_str = (char *)errnum;
//   //   char *un_res = s21_strcat(errnum_str, err);
//   //   res = un_res;
//   // }

//   return res;
// }

/***************************** STRLEN *****************************/
s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

/**************************** STRPBRK *****************************/
/*              Вычисляет длину строки str,                       */
/*          не включая завершающий нулевой символ.                */
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

/***************************** STRSTR *****************************/
/*    Находит первый символ в строке str1, который соответствует  */
/*                любому символу, указанному в str2.              */
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

/***************************** strtok *****************************/
/*        Выполняет поиск последнего вхождения символа c          */
/* (беззнаковый тип) в строке, на которую указывает аргумент str. */
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
char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0, slen = s21_strlen(src);
  for (i = 0; i <= slen; i++) {
    dest[i] = src[i];
  }
  return dest;
}

char *s21_strcat(char *dest, const char *src) {
  s21_size_t dest_l = s21_strlen(dest), i = 0;
  for (; src[i] != '\0'; i++) dest[dest_l + i] = src[i];
  dest[dest_l + s21_strlen(src) + 1] = '\0';
  return dest;
}

/*****************  UNUSED FUNCTIONS ***************************/
/* int s21_strcmp(const char *str1, const char *str2) {        */
/*   while (*str1 && (*str1 == *str2)) {                       */
/*     str1++;                                                 */
/*     str2++;                                                 */
/*   }                                                         */
/*   return *str1 - *str2;                                     */
/* }                                                           */
/***************************************************************/