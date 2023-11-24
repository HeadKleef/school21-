#include <stdio.h>
#include <stdlib.h>

#include "choose.h"
#include "options.h"

void open(char *filename[], int l) {
  int p = option(filename[1]);
  int i = 1;

  char ch;

  FILE *file;
  if (file_exist(filename[l]) == 1) {
    file = fopen(filename[l], "r");
    while (!feof(file) && !ferror(file)) {
      ch = fgetc(file);
      if (ch != EOF) i = choose_flag(i, p, ch, file);
    }
    fclose(file);
  }
  if (file_exist(filename[l]) == 0 && filename[l] != filename[1]) {
    printf("\ncat: %s: No such file or directory\n", filename[l]);
  }
}
int main(int argc, char *argv[]) {
  if (argc <= 1) printf("cat: no such flag,  file or directory\n");
  if (argc <= 2 && check_flag(argv[1]) == 1)
    printf("cat: No such file or directory\n");
  for (int i = 1; i < argc; i++) {
    open(argv, i);
  }
  return 0;
}