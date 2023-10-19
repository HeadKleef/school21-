#include <stdio.h>
#include <stdlib.h>

#include "choose.h"
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
void open_empty(char *filename[]) {
  FILE *file;
  char c;
  if (file_exist(filename[2]) == 1) {
    file = fopen(filename[2], "r");
    while ((c = fgetc(file)) != EOF) {
      putchar(c);
    }
    fclose(file);
  } else {
    printf("wrong filename");
  }
}

void open(char *filename[]) {
  int p = option(filename[1]);
  char ch;
  FILE *file;
  if (file_exist(filename[2]) == 1) {
    file = fopen(filename[2], "r");
    while ((ch = fgetc(file)) != EOF) {
      choose_flag(p, ch, file);
    }
    fclose(file);
  } else {
    printf("wrong filename");
  }
}
int main(int argc, char *argv[]) {
  if (argc < 3) {
    open_empty(argv);
  } else
    open(argv);
  return 0;
}