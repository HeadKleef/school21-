#include "s21_string.h"


// void s21_memchr(){}

// int s21_memcmp(){}

// void s21_memmove(){}

// void s21_memset(){}

// char s21_strcat(){}

// char s21_strncat(){}

// char s21_strchr(){}

//int s21_strcmp(const char *str1, const char *str2){}

// int s21_strncmp(){}

 char *s21_strcpy(char *dest, const char *src){
    s21_size_t i = 0, slen= s21_strlen(src);
    for(i = 0; i <= slen; i++){
        dest[i]= src[i];
    }
    return dest;

 }
 char *s21_strncpy(char *dest, const char *src, s21_size_t n){
 s21_size_t i = 0, slen = s21_strlen(src);
    for(i=0; i <= slen && i< n; i++){
        dest[i] = src[i];
    }
    return dest;
 }

//size_t *s21_strspn(){}

// char s21_strerror(){}

size_t s21_strlen(const char *str){
    s21_size_t i =0;
    while(str[i] != '\0'){ i++;}
    return i;
}

// char s21_strpbrk(){}

// char s21_strrchr(){}

// size_t s21_strpn(){}

// char s21_strstr(){}

// char s21_strtok(){}


