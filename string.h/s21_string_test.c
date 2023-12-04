#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_string.h"

int main(){
char str_test_1[10] = "qwerty";
char str_test_2[10] = "ytrewq";

//strcpy test
char *strcpy_test_ret_1 = s21_strcpy(str_test_1, str_test_2);
char *strcpy_test_ret_2 = strcpy(str_test_1, str_test_2);
if(strstr(strcpy_test_ret_1, strcpy_test_ret_2) != 0 && strcmp(strcpy_test_ret_1, strcpy_test_ret_2) == 0) printf("strcpy test : done \n");

//strncpy test
int n = 3;
char *strncpy_test_ret_1 = s21_strncpy(str_test_1, str_test_2, n);
char *strncpy_test_ret_2 = strncpy(str_test_1, str_test_2,n);
if(strstr(strncpy_test_ret_1, strncpy_test_ret_2) != 0  && strcmp(strncpy_test_ret_1, strncpy_test_ret_2) == 0) printf("strncpy test : done \n");


//strlen test
int strlen_test_ret_1 = s21_strlen(str_test_1);
int strlen_test_ret_2 = strlen(str_test_1);
if(strlen_test_ret_1 == strlen_test_ret_2) printf("strlen test : done\n");



    return 0;
}