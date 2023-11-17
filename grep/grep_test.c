
#include "flags.h"

int flag_check(char *flag) {
  int i = 0;
  if (flag[0] == 45) i = 1;
  return i;
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
void open_file(char *filename[], flags *option, int file_count, int filename_co,
               int temp_co, int argc, int opt_e_check) {
  FILE *stream;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int str_counter = 0;
  int comp_counter = 0;
  if (check_file_exist(filename[filename_co]) == 1) {
    stream = fopen(filename[filename_co], "r");
    if (stream == NULL) exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, stream)) != -1) {
      str_counter++;
      fill_flags(argc, filename, option, line, opt_e_check, file_count,
                 filename_co);
      comp_counter =
          flags_realise(line, *option, filename[filename_co], file_count,
                        filename[temp_co], str_counter, comp_counter);
    }

    if (option->c)
      option_c(*option, comp_counter, filename[filename_co], file_count);
    if (option->l) option_l(*option, filename[filename_co]);

    free(line);
    fclose(stream);
    if (option->v && !option->l && !option->c) printf("\n");
  } else if (!option->s && filename[filename_co] != NULL)
    printf("grep: %s: No such file or directory\n", filename[filename_co]);
}
int main(int argc, char *argv[]) {
  flags option = {0};
  if (argc > 1 && flag_check(argv[1]) == 1) {
    int i = flags_count(argc, argv) + 1;
    int file_count = argc - (i + 1);
    int opt_e_check = 0;
    int c = (i + 1);
    if (argv[argc - (file_count + 1)][1] == 'e') {
      file_count--;
      opt_e_check = 1;
      c++;
    }
    int n = i;
    // printf("n = %d\n argc = %d \n file_c = %d \n", n, argc, c);
    while (n < (argc - 1)) {
      open_file(argv, &option, file_count, c, i, argc, opt_e_check);
      n++;
      c++;
    }
  } else if (argc > 1) {
    // option.def = 1;
    int file_count = argc - 2;
    int opt_e_check = 0;
    int i = 1;
    int c = 2;
    // printf("%s", argv[2]);
    for (int n = 1; n < argc; n++)
      open_file(argv, &option, file_count, c, i, argc, opt_e_check);
  }
  return 0;
}
