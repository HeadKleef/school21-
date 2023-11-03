#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checks.h"
#include "options.h"

void cut(char *temp, char *filename, int l, int file_count) {
  FILE *stream;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int str_counter = 0;
  int comp_counter = 0;
  stream = fopen(filename, "r");
  if (stream == NULL) exit(EXIT_FAILURE);
  while ((read = getline(&line, &len, stream)) != -1) {
    str_counter++;
    choose_opt(str_counter, temp, line, filename, l, file_count);
    if (strstr(line, temp) != NULL) comp_counter++;
  }
  if (comp_counter > 0 && l == 5) option_l(filename);
  if (l == 4) option_c(comp_counter, file_count, filename);
  free(line);
  fclose(stream);
}
int main(int argc, char *argv[]) {
  int arg_count = argc;
  int w, min = 0;
  int *pars = (int *)malloc(arg_count * sizeof(int));
  for (int i = 1; i < arg_count; i++) {
    w = flag_check(argv[i]);
    pars[i] = w;
  }
  int f, flag_num, count = 0;
  int co = 0;
  int file_count = 0;
  int error_file = 1;
  for (int i = 1; i < arg_count; i++) {
    if (pars[i] == 0) co++;
    if (co >= 2) file_count++;
  }
  for (int i = 1; i < arg_count; i++) {
    if (pars[i] == 0) co++;
    if (pars[i] == 1) {
      if ((min = strlen(argv[i])) > 1) {
        flag_num = choose_flag(argv[i]);
        co = 0;
      }
    }
    if (co >= 1) f = check_file_exist(argv[i]);
    if (f == 0 && i > 2) error_file++;
    if (error_file > 1) {
      printf("\ngrep: %s: No such file or directory\n", argv[i]);
      error_file = 1;
      count++;
    }
    if (f == 1) {
      count++;
      cut(argv[i - count], argv[i], flag_num, file_count);
    }
  }
  free(pars);
  return 0;
}
