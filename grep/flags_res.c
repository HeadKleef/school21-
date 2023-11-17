
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
  for (int i = 0; temp[i]; i++) temp[i] = tolower(temp[i]);
  if (strstr(line, temp) != NULL) r = 1;
  for (int i = 0; temp[i]; i++) temp[i] = toupper(temp[i]);
  if (strstr(line, temp) != NULL) r = 1;
  return r;
}

int flags_realise(char *line, flags option, char *filename, int file_count,
                  char *temp, int str_counter, int comp_counter) {
  if (file_count > 1 && !option.h && !option.c && !option.l && !option.v) {
    if (strstr(line, temp) != NULL) print_filename(filename);
    // if(option.e && strstr(line, temp) != NULL) print_filename(filename);
  }
  if (option.e) {
    if (strstr(line, temp) != NULL) print_line(line);
  }
  if (option.h && !option.n && !option.i && !option.v && !option.c) {
    if (strstr(line, temp) != NULL) print_line(line);
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
      if (strstr(line, temp) != NULL) {
        print_line_num(str_counter);
        print_line(line);
      }
    }
    if (option.o) {
      if (strstr(line, temp) != NULL) print_line_num(str_counter);
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
      if (strstr(line, temp) != NULL)
        line = NULL;
      else if (option.n) {
        if (file_count > 1) print_filename(filename);
        print_line_num(str_counter);
        print_line(line);
      } else if (!option.l) {
        if (strstr(line, temp) == NULL) {
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
        if (strstr(line, temp) != NULL) comp_counter++;
      }
    }
    if (option.v) {
      if (strstr(line, temp) == NULL) comp_counter++;
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
    if (strstr(line, temp) != NULL) print_line(line);
  }
  return comp_counter;
}