#include "../s21_string.h"

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

  // //strncat test
  // char *strncat_test_ret_1 = s21_strncat(str_test_1, str_test_2, n);
  // char *strncat_test_ret_2 = strncat(str_test_1, str_test_2, n);
  // // printf("%s\n", strncat_test_ret_2);
  // if (strstr(strncat_test_ret_1, strncat_test_ret_2) != 0 &&
  //     strcmp(strncat_test_ret_1, strncat_test_ret_2) == 0)
  //   printf("strncat test : \033[0;32mdone\033[0m \n");
  // else
  //   printf("strncat test : \033[0;31mfailed\033[0m\n");

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
  char strstr_test_arr[40] = "Hello world";
  char strstr_test_arr_2[10] = "llo";
  char *strstr_test_ret_1 = s21_strstr(strstr_test_arr, strstr_test_arr_2);
  char *strstr_test_ret_2 = strstr(strstr_test_arr, strstr_test_arr_2);
  printf("\n ret1 = %s ret 2 = %s", strstr_test_ret_1, strstr_test_ret_2);
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

  // strerror test
  for (int i = 0; i < 110; i++) {
    char *test_ret_err_2 = strerror(i);
    char *test_ret_err_1 = s21_strerror(i);
    if (strstr(test_ret_err_1, test_ret_err_2) != 0 &&
        strcmp(test_ret_err_1, test_ret_err_2) == 0)
      printf("strerror test %d: \033[0;32mdone\033[0m \n", i);
    else
      printf("strerror test %d : \033[0;31mfailed\033[0m\n", i);
  }

  char str1[10] = "SChOOl-21";
  char str2[10] = "SCHOOL-21";
  char str3[10] = "school-21";

  // TO UPPER TEST
  char *to_upper_test_ret_1 = s21_to_upper(str1);
  printf("RES : %s\n", to_upper_test_ret_1);
  if (strstr(to_upper_test_ret_1, str2) != 0 &&
      strcmp(to_upper_test_ret_1, str2) == 0)
    printf("to_upper test : \033[0;32mdone\033[0m \n");
  else
    printf("to_upper test : \033[0;31mfailed\033[0m\n");
  free(to_upper_test_ret_1);
  // TO LOWER TEST
  char *to_lower_test_ret_1 = s21_to_lower(str1);
  printf("RES : %s\n", to_lower_test_ret_1);
  if (strstr(to_lower_test_ret_1, str3) != 0 &&
      strcmp(to_lower_test_ret_1, str3) == 0)
    printf("to_lower test : \033[0;32mdone\033[0m \n");
  else
    printf("to_lower test : \033[0;31mfailed\033[0m\n");
  free(to_lower_test_ret_1);

  // INSERT TEST
  // const char str_insert[20] = "QWE";
  const char str_insert[20] = " ";
  // const char src_insert[20] = "123123";
  const char src_insert[20] = "School-21 test";
  // char insert[20] = "123QWE123";
  char insert[150] = "Sch ool-21 test";
  s21_size_t start_index = 3;
  printf("STRING: %s\n", str_insert);
  printf("SOURCE: %s\n", src_insert);
  printf("INDEX: %d\n", start_index);

  char *insert_test_ret_1 = s21_insert(src_insert, str_insert, start_index);
  printf("INSERT: %s\n", insert_test_ret_1);
  if (strstr(insert_test_ret_1, insert) != 0 &&
      strcmp(insert_test_ret_1, insert) == 0)
    printf("insert test : \033[0;32mdone\033[0m \n");
  else
    printf("insert test : \033[0;31mfailed\033[0m\n");
  free(insert_test_ret_1);

  // TRIM TEST
  const char src_trim[20] = "Q1W2E3Q4W5E";
  char trim_chars[10] = "QWE";
  const char trim[10] = "12345";

  char *trim_test_ret_1 = s21_trim(src_trim, trim_chars);
  if (strstr(trim_test_ret_1, trim) != 0 && strcmp(trim_test_ret_1, trim) == 0)
    printf("trim test : \033[0;32mdone\033[0m \n");
  else
    printf("trim test : \033[0;31mfailed\033[0m\n");

  free(trim_test_ret_1);


  char strp1[100] = {'\0'};
  char strp2[100] = {'\0'};
  // char format[] = "%cdgnh%-6.3u % +-8.2fd%6.33s";
  int r1 = s21_sprintf(strp1, "%s%10s%.0s%7.2s%-10.3s %5.3s%-5.0s", "aboba",
                       "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", "QWERTY",
                       "AAAAABOOOOOBAAA");
  int r2 =
      sprintf(strp2, "%s%10s%.0s%7.2s%-10.3s %5.3s%-5.0s", "aboba", "helloworld",
              "ABOBA", "ABOBBAAA", "AAABOBA", "QWERTY", "AAAAABOOOOOBAAA");

  // char str1[1000];
  // char str2[1000];
  // char s[10] = {'h', 'e', 'l', 'l', 'o'};

  // int r1 = sprintf(str1, "%s%10s%.0s%7.2s%-10.3s %5.3s%-5.0s%s%s%6.33s",
  //                  "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA",
  //                  "QWERTY", "AAAAABOOOOOBAAA", "ABOBAAAAA", s, s);
  // int r2 = s21_sprintf(str2, "%s%10s%.0s%7.2s%-10.3s%5.3s%-5.0s%s%s%6.33s",
  //                 "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA",
  //                "QWERTY", "AAAAABOOOOOBAAA", "ABOBAAAAA", s, s);
  // result = sprintf(str2, "%.0f", 99.99);
  // myres = s21_sprintf(str, "%.0f", 99.99);
  // // char str1[1000];
  // char str2[1000];
  // int r1 =
  //     sprintf(str1, "%+-10.5f%+10.2f%15.16f%+.10f%.16f%-10.f%25.f%25.f%.2f%.f",
  //             2546.4324, 3452.4325, 5678.43256, 456789.243242, 3456789123.43245,
  //             12345.6788, 34.4325432, 4325678.43242, 99.990, 34567.43244);
  // int r2 = s21_sprintf(
  //     str2, "%+-10.5f%+10.2f%15.16f%+.10f%.16f%-10.f%25.f%25.f%.2f%.f",
  //     2546.4324, 3452.4325, 5678.43256, 456789.243242, 3456789123.43245,
  //     12345.6788, 34.4325432, 4325678.43242, 99.990, 34567.43244);
//   char c3[100] = "lolkek";
//   char c4[100] = "lolkek";
//   int r1 = sprintf(c3 + 6, "%d", -6000);
//   int r2 = s21_sprintf(c4 + 6, "%d", -6000);
//   printf("-%s\n", c3);
//   printf("=%s\n", c4);
   printf("%d==%d\n", r1, r2);

////////////////


// int a, a1;
// int b, b1;
// int c, c1, d, d1, e, e1;
// a = b = c = d = 1;
// a1 = b1 = c1 = d1 = 1;
// const char str[] = "-12345 -000456000 111 +0005 666 777";
// sscanf(str, "%3d %d %d %*d %d %2d", &a, &b, &c, &d, &e);
//                  s21_sscanf(str, "%3d %d %d %*d %d %2d", &a1, &b1, &c1, &d1,
//                             &e1);
// printf("%d %d", a, a1);
// printf("%d %d", b, b1);
// printf("%d %d", c, c1);
// printf("%d %d", d, d1);
// printf("%d %d", e, e1);

// char a[40] = {'\0'}, c[40] = {'\0'}, d[40] = {'\0'};
// char b[40] = {'\0'};
// char a2[40] = {'\0'}, c2[40] = {'\0'}, d2[40] = {'\0'};
// wchar_t b2[40] = {'\0'};
// const char str[] = "lol kek cheburek morzh pisos";
// printf("%d %d", sscanf(str, "%s %s %3c %*s %s", a, b, c, d),
//                  s21_sscanf(str, "%s %s %3c %*s %s", a2, b2, c2, d2));
// printf("%s %s", a, a2);
// printf("%s %s", c, c2);
// printf("%s %s", d, d2);

// int a1, b1, c1, d1, a2, b2, c2, d2;
// a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
// const char str[] = "1778 012 0x1111 -10 pisos";
// int r1 = sscanf(str, "%x%x%x%x", &a1, &b1, &c1, &d1);
// int r2 = s21_sscanf(str, "%x%x%x%x", &a2, &b2, &c2, &d2);
// printf("%d %d", r1, r2);
// printf("%d %d", a1, a2);
// printf("%d %d", b1, b2);
// printf("%d %d", c1, c2);
// printf("%d %d", d1, d2);

// int a1, b1, c1, d1, a2, b2, c2, d2;
// a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
// const char str[] = "1778 012 0x1Aa8 -10 pisos";
// int r1 = sscanf(str, "%*i%i%i%i", &a1, &b1, &c1);
// int r2 = s21_sscanf(str, "%*i%i%i%i", &a2, &b2, &c2);
// printf("%d %d", r1, r2);
// printf("%d %d", a1, a2);
// printf("%d %d", b1, b2);
// printf("%d %d", c1, c2);

// int a1, b1, c1, d1, a2, b2, c2, d2;
// a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
// const char str[] = "1775 012 0 -10 pisos";
// int r1 = sscanf(str, "%o%o%o%o", &a1, &b1, &c1, &d1);
// int r2 = s21_sscanf(str, "%o%o%o%o", &a2, &b2, &c2, &d2);
// printf("%d %d", r1, r2);
// printf("%d %d", a1, a2);
// printf("%d %d", b1, b2);
// printf("%d %d", c1, c2);
// printf("%d %d", d1, d2);


// int a1, b1, c1, d1, a2, b2, c2, d2;
// a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
// const char str[] = "-12345 -000456000 111    0005 pisos";
// int r1 = s21_sscanf(str, "%d %d %n %d", &a1, &b1, &c1, &d1);
// int r2 = sscanf(str, "%d %d %n %d", &a2, &b2, &c2, &d2);
// printf("%d %d", r1, r2);
// printf("%d %d", a1, a2);
// printf("%d %d", b1, b2);
// printf("%d %d", c1, c2);
// printf("%d %d", d1, d2);

// float a1, b1, a2, b2;
// float c1, c2;
// float d1, d2;
// a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1.1;
// const char str[] = "-12345.445 12.34e+03 -0.0 1234e-03 pisos";
// s21_sscanf(str, "%f%f%f%f", &a1, &b1, &c1, &d1);
// sscanf(str, "%f%f%f%f", &a2, &b2, &c2, &d2);
// ck_assert_float_eq(a1, a2);
// ck_assert_float_eq(b1, b2);
// ck_assert_float_eq(c1, c2);

// unsigned int a1, b1, a2, b2;
// unsigned int c1, c2;
// unsigned int d1, d2;
// a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
// const char str[] = "0 0002 -1 -1234 666 pisos";
// int r1 = sscanf(str, "%*u%u%u%u%u", &a1, &b1, &c1, &d1);
// int r2 = s21_sscanf(str, "%*u%u%u%u%u", &a2, &b2, &c2, &d2);
// printf("%d %d", r1, r2);
// printf("%d %d", a1, a2);
// printf("%d %d", b1, b2);
// printf("%d %d", c1, c2);
// printf("%d %d", d1, d2);



////////
  return 0;
}

