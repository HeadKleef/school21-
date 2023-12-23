#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n = 3;
  int test = '5';
  int nb = 45;
  char str_test_1[10] = "qwert";
  char str_test_2[10] = "yw0q";
  char strchr_test[30] = "0-132433533367-a8";

  // memchr test

  char *memchr_test_ret_1 = s21_memchr(strchr_test, nb, n);
  char *memchr_test_ret_2 = memchr(strchr_test, nb, n);
  if (strstr(memchr_test_ret_1, memchr_test_ret_2) != 0 &&
      strcmp(memchr_test_ret_1, memchr_test_ret_2) == 0)
    printf("memchr test : \033[0;32mdone\033[0m\n");
  else
    printf("memchr test : \033[0;31mfailed\033[0m\n");

  // memcmp test
  int memcmp_test_ret_1 = s21_memcmp(str_test_1, str_test_2, n);
  int memcmp_test_ret_2 = memcmp(str_test_1, str_test_2, n);
  if (memcmp_test_ret_1 == memcmp_test_ret_2)
    printf("memcmp test : \033[0;32mdone\033[0m \n");
  else
    printf("memcmp test : \033[0;31mfailed\033[0m\n");

  // memcpy test
  char *memcpy_test_ret_1 = s21_memcpy(str_test_1, str_test_2, n);
  char *memcpy_test_ret_2 = memcpy(str_test_1, str_test_2, n);
  if (strstr(memcpy_test_ret_1, memcpy_test_ret_2) != 0 &&
      strcmp(memcpy_test_ret_1, memcpy_test_ret_2) == 0)
    printf("memcpy test : \033[0;32mdone\033[0m \n");
  else
    printf("memcpy test : \033[0;31mfailed\033[0m\n");

  // memset test
  char *memset_test_ret_1 = s21_memset(str_test_1, test, n);
  char *memset_test_ret_2 = memset(str_test_1, test, n);
  if (strstr(memset_test_ret_1, memset_test_ret_2) != 0 &&
      strcmp(memset_test_ret_1, memset_test_ret_2) == 0)
    printf("memset test : \033[0;32mdone\033[0m \n");
  else
    printf("memset test : \033[0;31mfailed\033[0m\n");

  // strncat test
  char *strncat_test_ret_1 = s21_strncat(str_test_1, str_test_2, n);
  char *strncat_test_ret_2 = strncat(str_test_1, str_test_2, n);
  // printf("%s\n", strncat_test_ret_2);
  if (strstr(strncat_test_ret_1, strncat_test_ret_2) != 0 &&
      strcmp(strncat_test_ret_1, strncat_test_ret_2) == 0)
    printf("strncat test : \033[0;32mdone\033[0m \n");
  else
    printf("strncat test : \033[0;31mfailed\033[0m\n");

  // strchr test
  char *strchr_test_ret_1 = s21_strchr(strchr_test, nb);
  char *strchr_test_ret_2 = strchr(strchr_test, nb);
  if (strstr(strchr_test_ret_1, strchr_test_ret_2) != 0 &&
      strcmp(strchr_test_ret_1, strchr_test_ret_2) == 0)
    printf("strchr test : \033[0;32mdone\033[0m \n");
  else
    printf("strchr test : \033[0;31mfailed\033[0m\n");

  // strncmp test
  int strncmp_test_ret_1 = s21_strncmp(str_test_1, str_test_2, n);
  int strncmp_test_ret_2 = strncmp(str_test_1, str_test_2, n);
  if (strncmp_test_ret_1 == strncmp_test_ret_2)
    printf("strncmp test : \033[0;32mdone\033[0m \n");
  else
    printf("strncmp test : \033[0;31mfailed\033[0m\n");

  // strncpy test
  char *strncpy_test_ret_1 = s21_strncpy(str_test_1, str_test_2, n);
  char *strncpy_test_ret_2 = strncpy(str_test_1, str_test_2, n);
  if (strstr(strncpy_test_ret_1, strncpy_test_ret_2) != 0 &&
      strcmp(strncpy_test_ret_1, strncpy_test_ret_2) == 0)
    printf("strncpy test : \033[0;32mdone\033[0m \n");
  else
    printf("strncpy test : \033[0;31mfailed\033[0m\n");

  // strcspn test
  char strcspn_test_arr[10] = "123456789";
  char strcspn_test_arr_2[10] = "89";
  int strcspn_test_ret_1 = strcspn(strcspn_test_arr, strcspn_test_arr_2);
  int strcspn_test_ret_2 = s21_strcspn(strcspn_test_arr, strcspn_test_arr_2);
  if (strcspn_test_ret_1 == strcspn_test_ret_2)
    printf("strcspn test :  \033[0;32mdone\033[0m\n");
  else
    printf("strcspn test : \033[0;31mfailed\033[0m\n");

  // strlen test
  char strlen_test[14][30] = {"This",
                              "This string",
                              "This string",
                              "\0This string for",
                              "\0This string for",
                              "This striNg for tests.",
                              "This striNg for tests.",
                              "This striNg for tests.",
                              " ",
                              "   ",
                              ".   ",
                              "This string for tests.",
                              "special symbol"};

  for (int i = 0; i <= 13; i++) {
    int strlen_test_ret_1 = s21_strlen(strlen_test[i]);
    int strlen_test_ret_2 = strlen(strlen_test[i]);
    if (strlen_test_ret_1 == strlen_test_ret_2)
      printf("strlen test %d:  \033[0;32mdone\033[0m\n", i);
    else
      printf("strlen test %d : \033[0;31mfailed\033[0m\n", i);
  }

  int strlen_test_ret_1 = s21_strlen(str_test_1);
  int strlen_test_ret_2 = strlen(str_test_1);
  if (strlen_test_ret_1 == strlen_test_ret_2)
    printf("strlen test :  \033[0;32mdone\033[0m\n");
  else
    printf("strlen test : \033[0;31mfailed\033[0m\n");

  // strpbrk test
  char *strpbrk_test_ret_1 = s21_strpbrk(str_test_1, str_test_2);
  char *strpbrk_test_ret_2 = strpbrk(str_test_1, str_test_2);
  if (strstr(strpbrk_test_ret_1, strpbrk_test_ret_2) != 0 &&
      strcmp(strpbrk_test_ret_1, strpbrk_test_ret_2) == 0)
    printf("strpbrk test : \033[0;32mdone\033[0m \n");
  else
    printf("strpbrk test : \033[0;31mfailed\033[0m\n");

  // strrchr test
  char *strrchr_test_ret_1 = s21_strrchr(strchr_test, nb);
  char *strrchr_test_ret_2 = strrchr(strchr_test, nb);
  if (strstr(strrchr_test_ret_1, strrchr_test_ret_2) != 0 &&
      strcmp(strrchr_test_ret_1, strrchr_test_ret_2) == 0)
    printf("strrchr test : \033[0;32mdone\033[0m \n");
  else
    printf("strrchr test : \033[0;31mfailed\033[0m\n");

  // strstr test
  char strstr_test_arr[10] = "1289fyukb";
  char strstr_test_arr_2[10] = "89";
  char *strstr_test_ret_1 = strstr(strstr_test_arr, strstr_test_arr_2);
  char *strstr_test_ret_2 = strstr(strstr_test_arr, strstr_test_arr_2);
  if (strstr(strstr_test_ret_1, strstr_test_ret_2) != 0 &&
      strcmp(strstr_test_ret_1, strstr_test_ret_2) == 0)
    printf("strstr test : \033[0;32mdone\033[0m \n");
  else
    printf("strstr test : \033[0;31mfailed\033[0m\n");

  // strtok test
  char str[] = "Hello,World!This,is,a,sample,string";
  const char delim[] = ",";
  char *strtok_ret_test_1 = strtok(str, delim);
  char *strtok_ret_test_2 = s21_strtok(str, delim);
  if (strstr(strtok_ret_test_1, strtok_ret_test_2) != 0 &&
      strcmp(strtok_ret_test_1, strtok_ret_test_2) == 0)
    printf("strtok test : \033[0;32mdone\033[0m \n");
  else
    printf("strtok test : \033[0;31mfailed\033[0m\n");

  // // strerror test
  // for (int i = 0; i < 110; i++) {
  //   char *test_ret_err_2 = strerror(i);
  //   char *test_ret_err_1 = s21_strerror(i);
  //   if (strstr(test_ret_err_1, test_ret_err_2) != 0 &&
  //       strcmp(test_ret_err_1, test_ret_err_2) == 0)
  //     printf("strerror test %d: \033[0;32mdone\033[0m \n", i);
  //   else
  //     printf("strerror test %d : \033[0;31mfailed\033[0m\n", i);
  // }

  char str1[10] = "qweASD";
  char str2[10] = "QWEASD";
  char str3[10] = "qweasd";
  // TO UPPER TEST
  char *to_upper_test_ret_1 = s21_to_upper(str1);
  if (strstr(to_upper_test_ret_1, str2) != 0 &&
      strcmp(to_upper_test_ret_1, str2) == 0)
    printf("to_upper test : \033[0;32mdone\033[0m \n");
  else
    printf("to_upper test : \033[0;31mfailed\033[0m\n");

  // TO LOWER TEST
  char *to_lower_test_ret_1 = s21_to_lower(str1);
  if (strstr(to_lower_test_ret_1, str3) != 0 &&
      strcmp(to_lower_test_ret_1, str3) == 0)
    printf("to_lower test : \033[0;32mdone\033[0m \n");
  else
    printf("to_lower test : \033[0;31mfailed\033[0m\n");

  // INSERT TEST
  // char str_insert[20] = "123123";
  // char src_insert[20] = "QWE";
  // char insert[20] = "123QWE123";
  // s21_size_t start_index = 3;
  // printf("STRING: %s\n", str_insert);
  // printf("SOURCE: %s\n", src_insert);
  // printf("INDEX: %d\n", start_index);

  // char *insert_test_ret_1 = s21_insert(src_insert, str_insert, start_index);
  // printf("INSERT: %s\n", insert_test_ret_1);
  // if (strstr(insert_test_ret_1, insert) != 0 &&
  //     strcmp(insert_test_ret_1, insert) == 0)
  //   printf("insert test : \033[0;32mdone\033[0m \n");
  // else
  //   printf("insert test : \033[0;31mfailed\033[0m\n");

  // TRIM TEST
  const char src_trim[20] = "Q1W2E3Q4W5E";
  char trim_chars[10] = "QWE";
  const char trim[10] = "12345";

  printf("SOURCE: %s\n", src_trim);
  printf("TRIM CHARS: %s\n", trim_chars);
  printf("HOW NEED: %s\n", trim);

  char *trim_test_ret_1 = s21_trim(src_trim, trim_chars);
  printf("HOW HAVE: %s\n", trim_test_ret_1);
  if (strstr(trim_test_ret_1, trim) != 0 && strcmp(trim_test_ret_1, trim) == 0)
    printf("trim test : \033[0;32mdone\033[0m \n");
  else
    printf("trim test : \033[0;31mfailed\033[0m\n");

  return 0;
}

// // strcmp test
// int strcmp_test_ret_1 = s21_strcmp(str_test_1, str_test_2);
// int strcmp_test_ret_2 = strcmp(str_test_1, str_test_2);
// if (strcmp_test_ret_1 == strcmp_test_ret_2)
//   printf("strcmp test : \033[0;32mdone\033[0m \n");
// else
//   printf("strcmp test : \033[0;31mfailed\033[0m\n");

// // strcpy test
// char *strcpy_test_ret_1 = s21_strcpy(str_test_1, str_test_2);
// char *strcpy_test_ret_2 = strcpy(str_test_1, str_test_2);
// if (strstr(strcpy_test_ret_1, strcpy_test_ret_2) != 0 &&
//     strcmp(strcpy_test_ret_1, strcpy_test_ret_2) == 0)
//   printf("strcpy test : \033[0;32mdone\033[0m \n");
// else
//   printf("strcpy test : \033[0;31mfailed\033[0m\n");