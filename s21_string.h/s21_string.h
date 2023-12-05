#include <stdio.h>
#include <stdlib.h>

#ifndef S21_STRING_H_
#define S21_STRING_H_

typedef unsigned int s21_size_t;
#define S21_NULL (void*)0

char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
size_t s21_strlen(const char *str);


#endif