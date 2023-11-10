#include "flags_res.h"

#include "grep_test.h"

void print_line(char *line) { printf("%s", line); }
void print_line_num(int str_counter) { printf("%d:", str_counter); }
void print_filename(char *filename) { printf("%s:", filename); }
void option_l(flags option, char *filename) {
  if (option.l) printf("%s\n", filename);
}
void option_c(flags option, int comp_counter, char *filename, int file_count) {
  if (option.c && !option.l) {
    if (file_count > 1) print_filename(filename);
    printf("%d\n", comp_counter);
  }
  if (option.l) {
    int i = 0;
    if (file_count > 1) print_filename(filename);
    if (comp_counter >= 1) {
      i = 1;
      printf("%d\n", i);
    } else
      printf("%d\n", i);
  }
}
int change_reg(char *line, char *temp) {
  int r = 0;
  for (int i = 0; temp[i]; i++) temp[i] = tolower(temp[i]);
  if (strstr(line, temp) != NULL) r = 1;
  for (int i = 0; temp[i]; i++) temp[i] = toupper(temp[i]);
  if (strstr(line, temp) != NULL) r = 1;
  return r;
}

int fill_flags(int argc, char *argv[], flags *option) {
  char opt;

  while ((opt = getopt(argc, argv, "ivclnhe:")) != -1) {
    switch (opt) {
      case 'e':
        printf("flag %c\n", opt);
        option->e = 1;
        break;
      case 'i':
        printf("flag %c\n", opt);
        option->i = 1;
        break;
      case 'v':
        printf("flag %c\n", opt);
        option->v = 1;
        break;
      case 'c':
        printf("flag %c\n", opt);
        option->c = 1;
        break;
      case 'l':
        printf("flag %c\n", opt);
        option->l = 1;
        break;
      case 'n':
        printf("flag %c\n", opt);
        option->n = 1;
        break;
      case 'h':
        printf("flag %c\n", opt);
        option->h = 1;
        break;
    }
  }
  return optind;
}

int flags_realise(char *line, flags option, char *filename, int file_count,
                  char *temp, int str_counter, int comp_counter) {
  if (file_count > 1 && !option.h && !option.c && !option.l && !option.v)
    print_filename(filename);
  if (option.h) {
    if (!option.n) {
      if (!option.i) {
        if (!option.v) {
          if (strstr(line, temp) != NULL) print_line(line);
        }
      }
    }
  }
  if (option.i) {
    if (!option.c) {
      if (!option.v) {
        if (!option.n) {
          int change_count = 0;
          change_count = change_reg(line, temp);
          if (change_count == 1) {
            print_line(line);
          }
        }
      }
    }
  }
  if (option.n) {
    if (!option.v) {
      if (option.i) {
        if (change_reg(line, temp) == 1) print_line_num(str_counter);
        print_line(line);
      } else if (!option.i) {
        if (strstr(line, temp) != NULL) {
          print_line_num(str_counter);
          print_line(line);
        }
      }
    }
  }
  if (option.v) {
    if (!option.c) {
      if (option.i) {
        if (change_reg(line, temp) == 1)
          line = NULL;
        else
        print_filename(filename);
          print_line(line);
      }

      if (!option.i) {
        if (strstr(line, temp) != NULL)
          line = NULL;
        else if (option.n) {
            print_filename(filename);
          print_line_num(str_counter);
          print_line(line);
        } else if(strstr(line, temp) == NULL){
        print_filename(filename);
          print_line(line);
        }
      }
    }
  }
  if (option.c) {
    if (!option.v) {
      if (option.i) {
        if (change_reg(line, temp) == 1) comp_counter++;
      } else if (!option.i) {
        if (strstr(line, temp) != NULL) comp_counter++;
      }
    }
    if (option.v) {
      if (strstr(line, temp) == NULL) comp_counter++;
    }
  }

  return comp_counter;
}
