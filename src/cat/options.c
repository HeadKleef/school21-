
#include "options.h"

int file_exist(char *filename) {
  int chek = 0;
  FILE *file;
  file = fopen(filename, "r");
  if (file) {
    fclose(file);
    chek = 1;
  }
  return chek;
}
int check_flag(char *filename) {
  int i = 0;
  if (filename[0] == 45) i = 1;
  return i;
}

int option(char *filename) {
  int l = 0;
  if (filename[0] == 45) {
    if (filename[1] == 'e') l = 1;
    if (filename[1] == 'n') l = 2;
    if (filename[1] == 'b') l = 3;
    if (filename[1] == 's') l = 4;
    if (filename[1] == 't') l = 5;
    if (filename[1] == 'v') l = 6;
    if (filename[1] == 'T') l = 7;
    if (filename[1] == 'E') l = 8;
    char gnu_n[9] = "--number";
    if (strcmp(filename, gnu_n) == 0) l = 2;
    char gnu_b[19] = "--number-nonblank";
    if (strcmp(filename, gnu_b) == 0) l = 3;
    char gnu_s[16] = "--squeeze-blank";
    if (strcmp(filename, gnu_s) == 0) l = 4;
  } else
    l = 0;
  return l;
}
