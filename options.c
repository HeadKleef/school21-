#include "options.h"
void option_c(int comp_counter) { printf("%d", comp_counter); }

int choose_flag(char *flag) {
  int l = 0;
  if (flag[1] == 'e') {
    l = 1;
  } else if (flag[1] == 'i') {
    l = 2;
  } else if (flag[1] == 'v') {
    l = 3;
  } else if (flag[1] == 'c') {
    l = 4;
  } else if (flag[1] == 'l') {
    l = 5;
  } else if (flag[1] == 'n') {
    l = 6;
  }else {
    printf("wrong_flag: %s\n", flag);
  }
  return l;
}

void choose_opt(int str_counter, char *temp, char *line, char *filename,
                int l) {
  if (l == 0) {
    if (strstr(line, temp) != NULL) {
      printf("%s", line);
    }
  } else if (l == 1) {
    if (strstr(line, temp) != NULL) {
      printf("%s", line);
    }
  } else if (l == 2) {
    for (int i = 0; temp[i]; i++) {
      temp[i] = tolower(temp[i]);
    }
    if (strstr(line, temp) != NULL) {
      printf("%s", line);
    }
    for (int i = 0; temp[i]; i++) {
      temp[i] = toupper(temp[i]);
      if (strstr(line, temp) != NULL) {
        printf("%s", line);
      }
    }

  } else if (l == 3) {
    if (strstr(line, temp) != NULL) {
      line = NULL;
    } else
      printf("%s", line);
  }
  if (l == 5) {
    if (strstr(line, temp) != NULL) {
      printf("%s\n", filename);
    }
  } else if (l == 6) {
    if (strstr(line, temp) != NULL) {
      printf("%d: %s", str_counter, line);
    }
  }
}
