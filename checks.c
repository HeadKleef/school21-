#include "checks.h"

int flag_check(char *flag) {
  int w = 0;
  if (flag[0] == 45) w = 1;
  return w;
}
int check_file_exist(char *filename) {
  int chek = 0;
  FILE *file;
  file = fopen(filename, "r");
  if (file) {
    fclose(file);
    chek = 1;
  }
  return chek;
}