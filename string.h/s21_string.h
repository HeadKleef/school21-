#include <stdio.h>
#include <stdlib.h>

#ifndef S21_STRING_H_
#define S21_STRING_H_

typedef unsigned int s21_size_t;

char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
size_t s21_strlen(const char *str);


#endif