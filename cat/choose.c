#include "choose.h"

int new_line(char c) { return (c == '\n'); }
int is_tab(char c) { return (c == '\t'); }

int is_empty_line(FILE *file) {
  char d;
  int empty;

  empty = 0;

  d = getc(file);
  if (new_line(d)) empty = 1;
  ungetc(d, file);
  return empty;
}
void option_e(char ch){
 if (ch == '\n' || ch == 4)
      printf("$\n");
    else
      putchar(ch);
}
int option_n(int i, char ch){
if (i == 1) {
      printf(" %d ", i);
      i++;
    } else if (ch == '\n') {
      printf("\n %6d ", i);
      i++;
    } else
      putchar(ch);
  return i;
}
int option_b(int i, char ch, FILE *file){
 if (i == 1) {
      printf(" %d ", i);
      i++;
    } else if (ch == '\n' && !is_empty_line(file)) {
      printf("\n %d ", i);
      i++;
    } else
      putchar(ch);
  return i;
}
void option_s(char ch, FILE*file){
  if (is_empty_line(file) && new_line(ch)) {
      if (ch == EOF) {
        ungetc(ch, file);
      }
    } else
      putchar(ch);
}
void option_t(char ch){
  if (is_tab(ch)) {
      printf("^|");
    } else
      putchar(ch);
}
int choose_flag(int i,int p, char ch, FILE *file) {
  if (p == 1) {
    option_e(ch);
  } else if (p == 2) {
    i = option_n(i, ch);
  } else if (p == 3) {
    i = option_b(i, ch, file);
  } else if (p == 4) {
    option_s(ch, file);
  } else if (p == 5) {
    option_t(ch);
  }
  return i;
}
