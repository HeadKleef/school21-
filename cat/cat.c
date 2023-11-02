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
    while ((ch = fgetc(file)) != EOF) {
      i = choose_flag(i, p, ch, file);
    }
    fclose(file);
  }
  if (file_exist(filename[l]) == 0 && filename[l] != filename[1]) {
    printf("\ncat: %s: No such file or directory\n", filename[l]);
  }
}
int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    open(argv, i);
  }
  return 0;
}
