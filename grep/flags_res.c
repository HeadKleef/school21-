
#include "flags.h"

void print_line(char *line) { printf("%s", line); }
void print_line_num(int str_counter) { printf("%d:", str_counter); }
void print_filename(char *filename) { printf("%s:", filename); }
void option_l(flags option, char *filename) {
  if (option.l) printf("%s\n", filename);
}

int option_e(int i, char *line, char *temp) {
  if (i < 1) {
    regex_t re_temp;
    regcomp(&re_temp, temp, REG_EXTENDED);
    if (regexec(&re_temp, line, 0, NULL, 0) == 0) {
      print_line(line);
      i++;
    }
    regfree(&re_temp);
  }
  return i;
}

int option_f(int file_count, char *filename, int str_counter, flags option,
             int i, char *line, char *line_f) {
  // Создаем временный буфер для обработки строки
  char *temp_line_f = strdup(line_f);
  if (temp_line_f == NULL) {
    perror("Unable to allocate memory");
    exit(EXIT_FAILURE);
  }
  // Удаляем символ новой строки (\n) или символы новой строки Windows (\r\n)
  size_t line_len = strlen(temp_line_f);
  if (line_len > 0 && (temp_line_f[line_len - 1] == '\n' ||
                       temp_line_f[line_len - 1] == '\r')) {
    temp_line_f[line_len - 1] =
        '\0';  // заменяем символ новой строки на нуль-терминатор
    if (line_len > 1 && temp_line_f[line_len - 2] == '\r') {
      temp_line_f[line_len - 2] =
          '\0';  // обработка символа \r при использовании Windows
    }
  }
  if (i < 1) {
    int reg = 0;
    regex_t re_temp_f;
    if (option.i) regcomp(&re_temp_f, temp_line_f, REG_ICASE | REG_EXTENDED);
    if (!option.i) regcomp(&re_temp_f, temp_line_f, REG_EXTENDED);
    reg = regexec(&re_temp_f, line, 0, NULL, 0);
    if (!option.v) {
      if (reg == 0) {
        if (file_count > 1) print_filename(filename);
        if (option.n) print_line_num(str_counter);
        if (!option.l && !option.c && !option.o) {
          printf("%s", line);
        }
        i++;
      }
      regfree(&re_temp_f);
    } else if (option.v && !option.l && !option.c && !option.o && !option.i) {
      regcomp(&re_temp_f, temp_line_f, REG_EXTENDED);
      if (reg != 0) print_line(line);
      i++;
    }

    free(temp_line_f);  // Освобождаем выделенную память для временного буфера
    regfree(&re_temp_f);
  }
  return i;
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
  regfree(&re_icase_temp);
  return r;
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
  if (option.n && !option.v && !option.o) {
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
  }
  if (option.v && !option.c && !option.f) {
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
  if (option.o && !option.v && !option.l && !option.c) {
    regmatch_t match;
    int count = 0;
    if (option.i) {
      regex_t re_icase_temp;
      regcomp(&re_icase_temp, temp, REG_ICASE);
      re_temp = re_icase_temp;
    }
    int strlen_count = strlen(line);
    while (count < strlen_count) {
      if (regexec(&re_temp, line, 1, &match, 0) == 0) {
        if (option.n && count < 1) print_line_num(str_counter);
        int i = 0;
        for (i = match.rm_so; i < match.rm_eo; i++) {
          printf("%c", line[i]);
        }
        printf("\n");
        line = line + match.rm_eo;
      }
      count++;
    }
  }
  if (option.def) {
    if (regexec(&re_temp, line, 0, NULL, 0) == 0) print_line(line);
  }
  if (option.f) {
    int i = 0;
    FILE *stream_f;
    char *line_f = NULL;
    size_t len = 0;
    ssize_t read;

    if (check_file_exist(temp) == 1) {
      stream_f = fopen(temp, "r");
      if (stream_f == NULL) exit(EXIT_FAILURE);
      while ((read = getline(&line_f, &len, stream_f)) != -1) {
        i = option_f(file_count, filename, str_counter, option, i, line,
                     line_f);
      }
      // if (line_f[read - 1] == '\n')
      // {
      //   rewind(stream_f); // смещение на один байт после символа новой строки
      // }
      free(line_f);
      fclose(stream_f);
    }
    comp_counter = comp_counter + i;
  }
  regfree(&re_temp);

  return comp_counter;
}