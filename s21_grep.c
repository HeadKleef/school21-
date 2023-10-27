#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checks.h"
#include "options.h"

void cut(char *temp, char *filename, int l) {
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
    choose_opt(str_counter, temp, line, filename, l);
    if (strstr(line, temp) != NULL) comp_counter++;
  }
  if (l == 4) option_c(comp_counter);
  free(line);
  fclose(stream);
}

int main(int argc, char *argv[]) {
  int arg_count = argc;
  int w = 0;
  int l = 0;
  int i = 1;
  int *pars = (int *)malloc(arg_count * sizeof(int));
  for (i = 1; i < arg_count; i++) {
    l = strlen(argv[i]);
    char *t = (char *)malloc(l * sizeof(char));
    w = flag_check(argv[i], t);
    free(t);
    pars[i] = w;
  }
  int error_file = 0;
  int f = 0;
  int co = 0;
  int flag_num = 0;
  int file_count = 0;
  
  for (int i = 1; i < arg_count; i++) {
    if (pars[i] == 0) {
      co++;
      // printf("%d", co);
    }
    if (pars[i] == 1) {
      flag_num = choose_flag(argv[i]);
      co = 0;
    }
    if (co == 2) {
      f = check_file_exist(argv[i]);
      // printf("\nf = %d\n", f);
      co = 0;
    }
    if (f == 0) {
      error_file++;
    }
    if (f == 1) {
      cut(argv[i - 1], argv[i], flag_num);
      f = 0;
      file_count++;
      error_file = 0;
    }
  }
  // for(int i =0; i < f; i++){
  //   if(file_count == 1){
  //     cut(argv[i - 1], argv[i], flag_num);
  //   }
  //   if(file_count > 1){
  //     printf()
  //   }
  // }
  //printf("\n");
  free(pars);
  return 0;
}