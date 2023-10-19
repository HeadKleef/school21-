
#include "options.h"

int option(char *filename) {
  char opt[2];
  opt[1] = filename[1];
  int l = 0;
  if (opt[1] == 'e') {
    l = 1;
  } else if (opt[1] == 'n') {
    l = 2;
  } else if (opt[1] == 'b') {
    l = 3;
  } else if (opt[1] == 's') {
    l = 4;
  } else if (opt[1] == 't') {
    l = 5;
  } else {
    printf("wrong_flag");
  }
  return l;
}