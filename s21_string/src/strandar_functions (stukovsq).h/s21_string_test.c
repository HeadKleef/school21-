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
  printf("%s\n", memchr_test_ret_1);
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
  return 0;
}


// char strtok_test[30] = "abc/abc/acb/abc/acb";
// char *strtok_ret_test_1 = strtok(strtok_test, "/");
// while (strtok_ret_test_1 != NULL) {
//   printf("%s\n", strtok_ret_test_1);
// }

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