
#include "flags.h"

int flag_check(char *flag) {
  int i = 0;
  if (flag[0] == 45) i = 1;
  return i;
}

void fill_flags(int argc, char *argv[], flags *option, char *line,
                int opt_e_check, int file_count, int filename_co) {
  char opt;
  int i = 0;
  if (opt_e_check == 1) optind = 1;
  if (file_count > 1 && opt_e_check == 1) print_filename(argv[filename_co]);
  while ((opt = getopt(argc, argv, "ivclnhfsoe:")) != -1) {
    switch (opt) {
      case 'e':
        option->e = 1;
        i = option_e(i, line, optarg);
        break;
      case 'i':
        option->i = 1;
        break;
      case 'v':
        option->v = 1;
        break;
      case 'c':
        option->c = 1;
        break;
      case 'l':
        option->l = 1;
        break;
      case 'n':
        option->n = 1;
        break;
      case 'h':
        option->h = 1;
        break;
      case 's':
        option->s = 1;
        break;
      case 'f':
        option->f = 1;
        break;
      case 'o':
        option->o = 1;
        break;
    }
  }
}

int flags_count(int argc, char *argv[]) {
  int i = 0;
  int n = 0;
  for (n = 0; n < argc; n++) {
    if (argv[n][0] == 45) i++;
  }
  return i;
}

int check_file_exist(char *filename) {
  int chek = 0;
  if (filename != NULL) {
    FILE *file = fopen(filename, "r");
    if (file) {
      fclose(file);
      chek = 1;
    }
    if (!file) {
      chek = 0;
    }
  }
  return chek;
}
int open_file(char *filename[], flags *option, int file_count, int filename_co,
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
    if (option->l && comp_counter > 0) {
      option_l(*option, filename[filename_co]);
    }
    if (option->v && !option->l && !option->c && file_count == 1) {
      printf("\n");
    }
    if (option->v && (comp_counter == 0 || (comp_counter == 1 && option->n)) &&
        !option->l && !option->c && file_count > 1)
      printf("\n");
    free(line);
    fclose(stream);
  } else if (!option->s && filename[filename_co] != NULL) {
    fprintf(stderr, "grep: %s: No such file or directory\n",
            filename[filename_co]);
  }

  return comp_counter;
}
int main(int argc, char *argv[]) {
  flags option = {0};
  if (argc > 1 && flag_check(argv[1]) == 1) {
    int i = 0;
    int comp_check = 0;
    int comp_counter = 0;
    i = flags_count(argc, argv) + 1;
    int file_count = argc - (i + 1);
    int opt_e_check = 0;
    int c = (i + 1);
    if (argv[argc - (file_count + 1)][1] == 'e') {
      file_count--;
      opt_e_check = 1;
      c++;
    }
    int n = i;
    while (n < (argc - 1)) {
      comp_counter =
          open_file(argv, &option, file_count, c, i, argc, opt_e_check);
      n++;
      c++;
      if (comp_counter > 0) comp_check++;
    }
    if ((i - 1 == 1) && file_count != 1 && comp_check > 0 &&
        (option.h || option.s || option.n || option.i))
      printf("\n");
  } else if (argc > 1) {
    option.def = 1;
    int file_count = argc - 2;
    int opt_e_check = 0;
    int i = 1;
    int c = 2;
    for (int n = 1; n < file_count + 1; n++) {
      open_file(argv, &option, file_count, c, i, argc, opt_e_check);
    }
  }

  return 0;
}
