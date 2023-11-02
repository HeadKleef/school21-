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
void option_e(char ch) {
  if (ch == '\n')
    printf("$\n");
  else
    option_v(ch);
}
int option_n(int i, char ch) {
  if (i == 1) {
    printf("%6d\t", i);
    i++;
  }
  if (ch == '\n') {
    printf("\n%6d\t", i);
    i++;
  } else
    putchar(ch);
  return i;
}
int option_b(int i, char ch, FILE *file) {
  
  if (i == 1) {
    printf("%6d\t", i);
    i++;
  }
  if (ch == '\n' && !is_empty_line(file)) {
    printf("\n%6d\t", i);
    i++;
  } else
    putchar(ch);
  return i;
}
int option_s(char ch, FILE*file, int i){
  if (is_empty_line(file) && new_line(ch)) {
    i++;
      if (ch == EOF) {
        ungetc(ch, file);
      }
      if (i > 3) printf("\n");
    } else
      putchar(ch);
       return i;
}

void option_t(char ch) {
  if (is_tab(ch)) {
    printf("^I");
  } else
    option_v(ch);
}
void option_T(char ch) {
  if (is_tab(ch)) {
    printf("^I");
  } else
    putchar(ch);
}
void option_E(char ch) {
  if (ch == '\n')
    printf("$\n");
  else
    putchar(ch);
}

void option_v(unsigned char ch) {
  if (is_tab(ch)) {
    printf("%c", ch);
  } else if (ch < 32 && ch != 10) {
    ch += 64;
    printf("^%c", ch);
  } else if (ch == 127) {
    printf("^?");
  } else if (ch > 127 && ch < 160) {
    ch -= 64;
    printf("M-^%c", ch);
  } else if (ch >= 160 && ch <= 192) {
    ch -= 128;
    printf("M-%c", ch);
  } else
    printf("%c", ch);
}
int choose_flag(int i, int p, char ch, FILE *file) {
  
  switch (p) {
    case 0:
      putchar(ch);
      break;
    case 1:
      option_e(ch);
      break;
    case 2:
      i = option_n(i, ch);
      break;
    case 3:
      i = option_b(i, ch, file);
      break;
    case 4:
      i = option_s(ch, file, i);
      break;
    case 5:
      option_t(ch);
      break;
    case 6:
      option_v(ch);
      break;
    case 7:
      option_T(ch);
      break;
    case 8:
      option_E(ch);
      break;
    default:
      putchar(ch);
  }
  return i;
}
