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

int choose_flag(int i,int p, char ch, FILE *file) {
  if (p == 1) {
    
    if (ch == '\n' || ch == 4)
      printf("$\n");
    else
      putchar(ch);
  } else if (p == 2) {
    if (i == 1) {
      printf(" %d ", i);
      i++;
    } else if (ch == '\n') {
      printf("\n %6d ", i);
      i++;
    } else
      putchar(ch);
  } else if (p == 3) {
    if (i == 1) {
      printf(" %d ", i);
      i++;
    } else if (ch == '\n' && !is_empty_line(file)) {
      printf("\n %d ", i);
      i++;
    } else
      putchar(ch);
  } else if (p == 4) {
    if (is_empty_line(file) && new_line(ch)) {
      if (ch == EOF) {
        ungetc(ch, file);
      }
    } else
      putchar(ch);
  } else if (p == 5) {
    if (is_tab(ch)) {
      printf("^|");
    } else
      putchar(ch);
  }
  return i;
}
