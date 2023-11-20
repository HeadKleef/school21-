
#include "flags.h"

void print_line(char *line) { printf("%s", line); }
void print_line_num(int str_counter) { printf("%d:", str_counter); }
void print_filename(char *filename) { printf("%s:", filename); }
void option_l(flags option, char *filename) {
  if (option.l) printf("%s\n", filename);
}

void option_e(char *line, char *temp) {
  if (strstr(line, temp) != NULL) print_line(line);
}
void option_f(char *line, char *line_f) {
  regex_t re_temp_f;
    regcomp(&re_temp_f, line_f, REG_EXTENDED);
  if (regexec(&re_temp_f, line, 0, NULL, 0) == 0) printf("%s", line);
  
  regfree(&re_temp_f);
}
void option_c(flags option, int comp_counter, char *filename, int file_count) {
  if (option.c && !option.l) {
    if (file_count > 1 && !option.h) print_filename(filename);
    printf("%d\n", comp_counter);
  }
  if (option.l) {
    int i = 0;
    if (file_count > 1) print_filename(filename);
    if (comp_counter >= 1 && option.c) {
      i = 1;
      printf("%d\n", i);
    } else
      printf("%d\n", i);
  }
}
int change_reg(char *line, char *temp) {
  int r = 0;
  regex_t re_icase_temp;
  regcomp(&re_icase_temp, temp, REG_ICASE);
  if (regexec(&re_icase_temp, line, 0, NULL, 0) == 0) r++;
  return r;
  regfree(&re_icase_temp);
}

int flags_realise(char *line, flags option, char *filename, int file_count,
                  char *temp, int str_counter, int comp_counter) {
  regex_t re_temp;
  regcomp(&re_temp, temp, REG_EXTENDED);
  if (file_count > 1 && !option.h && !option.c && !option.l && !option.v) {
    if (regexec(&re_temp, line, 0, NULL, 0) == 0) print_filename(filename);
    
  }
  if (option.e) {
    if (regexec(&re_temp, line, 0, NULL, 0) == 0) print_line(line);
  }
  if (option.h && !option.n && !option.i && !option.v && !option.c) {
    if (regexec(&re_temp, line, 0, NULL, 0) == 0) print_line(line);
  }
  if (option.i && !option.c && !option.v && !option.n && !option.l &&
      !option.o) {
    int change_count = 0;
    change_count = change_reg(line, temp);
    if (change_count == 1) {
      print_line(line);
    }
  }
  if (option.n && !option.v) {
    if (option.i && !option.o) {
      if (change_reg(line, temp) == 1) {
        print_line_num(str_counter);
        print_line(line);
      }
    } else if (!option.i && !option.c && !option.l && !option.o) {
      if (regexec(&re_temp, line, 0, NULL, 0) == 0) {
        print_line_num(str_counter);
        print_line(line);
      }
    }
    if (option.o) {
      if (regexec(&re_temp, line, 0, NULL, 0) == 0) print_line_num(str_counter);
      char *result = strstr(line, temp);
      int count = 0;
      while (result != NULL) {
        ++count;
        result = strstr(result + 1, temp);
      }

      for (int i = 0; i < count; i++) {
        printf("%s\n", temp);
      }
    }
  }
  if (option.v && !option.c) {
    if (option.i) {
      if (change_reg(line, temp) == 1)
        line = NULL;
      else {
        if (file_count > 1) print_filename(filename);
        if (line != NULL) print_line(line);
      }
    }
    if (!option.i) {
      if (regexec(&re_temp, line, 0, NULL, 0) == 0)
        line = NULL;
      else if (option.n) {
        if (file_count > 1) print_filename(filename);
        print_line_num(str_counter);
        print_line(line);
      } else if (!option.l) {
        if (regexec(&re_temp, line, 0, NULL, 0) != 0) {
          if (file_count > 1) print_filename(filename);
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
        if (regexec(&re_temp, line, 0, NULL, 0) == 0) comp_counter++;
      }
    }
    if (option.v) {
      if (regexec(&re_temp, line, 0, NULL, 0) != 0) comp_counter++;
    }
  }
  if (option.o && !option.v && !option.n && !option.l && !option.c) {
    char *result = strstr(line, temp);
    int count = 0;
    while (result != NULL) {
      ++count;
      result = strstr(result + 1, temp);
    }

    for (int i = 0; i < count; i++) {
      printf("%s\n", temp);
    }
  }
  if (option.def) {
    if (regexec(&re_temp, line, 0, NULL, 0) == 0) print_line(line);
  }
  if (option.f) {
    FILE *stream_f;
    char *line_f = NULL;
    size_t len = 0;
    ssize_t read;

    if (check_file_exist(temp) == 1) {
      stream_f = fopen(temp, "r");
      if (stream_f == NULL) exit(EXIT_FAILURE);
      while ((read = getline(&line_f, &len, stream_f)) != -1) {
        if(line_f[0] != '\n') option_f(line, line_f);
      }
    }
    fclose(stream_f);
  }
  regfree(&re_temp);

  return comp_counter;
}