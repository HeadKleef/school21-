#include "flags.h"

#include "libs.h"
#include "main.h"

void fill_flags(int argc, char *argv[], flags *option, char *line,
                int opt_e_check, int file_count, int filename_co) {
  char opt;

  if (opt_e_check == 1) optind = 1;
  if (file_count > 1 && opt_e_check == 1) print_filename(argv[filename_co]);
  while ((opt = getopt(argc, argv, "ivclnhfsoe:")) != -1) {
    switch (opt) {
      case 'e':
        option->e = 1;
        option_e(line, optarg);
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
  if (option == 0) option->def = 1;
  optind = 0;
}

int flags_count(int argc, char *argv[]) {
  int i = 0;
  int n = 0;
  for (n = 0; n < argc; n++) {
    if (argv[n][0] == 45) i++;
  }
  return i;
}