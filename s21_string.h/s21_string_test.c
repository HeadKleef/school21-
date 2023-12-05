#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_string.h"

int main(){
int n = 3;
int nb = 45;
char str_test_1[10] = "qwe";
char str_test_2[10] = "ytrew0q";
char strchr_test[30] = "0132433533367-a8";

//strchr test
char *strchr_test_ret_1 = s21_strchr(strchr_test, nb);
//printf("%s\n", strchr_test_ret_1);
char *strchr_test_ret_2 = strchr(strchr_test, nb);
 //printf("%s\n", strchr_test_ret_2);
if(strstr(strchr_test_ret_1, strchr_test_ret_2) != 0 && strcmp(strchr_test_ret_1, strchr_test_ret_2) == 0) printf("strchr test : done \n");
else printf("strchr test : failed\n");

//strcmp test
int strcmp_test_ret_1 = s21_strcmp(str_test_1, str_test_2);
int strcmp_test_ret_2 = strcmp(str_test_1, str_test_2);
if(strcmp_test_ret_1 == strcmp_test_ret_2) printf("strcmp test : done \n");
else printf("strcmp test : failed\n");

//strncmp test
int strncmp_test_ret_1 = s21_strncmp(str_test_1, str_test_2, n);
int strncmp_test_ret_2 = strncmp(str_test_1, str_test_2, n);
if(strncmp_test_ret_1 == strncmp_test_ret_2) printf("strncmp test : done \n");
else printf("strncmp test : failed\n");


//strcpy test
char *strcpy_test_ret_1 = s21_strcpy(str_test_1, str_test_2);
char *strcpy_test_ret_2 = strcpy(str_test_1, str_test_2);
if(strstr(strcpy_test_ret_1, strcpy_test_ret_2) != 0 && strcmp(strcpy_test_ret_1, strcpy_test_ret_2) == 0) printf("strcpy test : done \n");
else printf("strcpy test : failed\n");

//strncpy test

char *strncpy_test_ret_1 = s21_strncpy(str_test_1, str_test_2, n);
char *strncpy_test_ret_2 = strncpy(str_test_1, str_test_2,n);
if(strstr(strncpy_test_ret_1, strncpy_test_ret_2) != 0  && strcmp(strncpy_test_ret_1, strncpy_test_ret_2) == 0) printf("strncpy test : done \n");
else printf("strncpy test : failed\n");

//strlen test
int strlen_test_ret_1 = s21_strlen(str_test_1);
int strlen_test_ret_2 = strlen(str_test_1);
if(strlen_test_ret_1 == strlen_test_ret_2) printf("strlen test : done\n");
else printf("strlen test : failed\n");


    return 0;
}