#include "s21_string.h"


// void s21_memchr(){}

// int s21_memcmp(){}

// void s21_memmove(){}

// void s21_memset(){}

// char s21_strcat(){}

// char s21_strncat(){}

 char *s21_strchr(const char *str, int c){
    s21_size_t i = 0;
    char *result = S21_NULL;
    while( str[i] !=  '\0' &&  str[i] != (char) c){
        i++;
    }
    result = (char*) &str[i];
    return result;
//     char * res = S21_NULL;
//   s21_size_t i = 0;
//   while (str[i] != '\0' && res == S21_NULL) {
//     if (str[i] == c)
//       res =  (char*) &str[i];
//     i++;
//   }
//   return res;

 }

int s21_strcmp(const char *str1, const char *str2){
    while(*str1 && (*str1 == *str2)){
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

 int s21_strncmp(const char *str1, const char *str2, s21_size_t n){
    s21_size_t i = 0;
     while(*str1 && (*str1 == *str2) && i < n){
        str1++;
        str2++;
        i++;
    }
    return *str1 - *str2;
 }

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


