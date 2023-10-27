#include "checks.h"

int flag_check(char *flag, char t[]) {
  int w = 1;

  t = flag;

  if (t[0] != 45) w = 0;

  return w;
}

int check_file_exist(char *filename) {
  int chek = 0;
  FILE *file;
  file = fopen(filename, "r");
  if (file) {
    fclose(file);
    chek = 1;
  } else
    chek = 0;
  return chek;
}