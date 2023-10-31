#include "options.h"

void option_l(char *filename) { printf("%s\n", filename); }
void option_v(char *line, char *temp, int file_count, char *filename) {
  if (file_count > 1) printf("%s:", filename);
  if (strstr(line, temp) == NULL) printf("%s", line);
}
void option_c(int comp_counter, int file_count, char *filename) {
  if (file_count > 1) printf("%s:", filename);
  printf("%d\n", comp_counter);
}
void option_i(char *line, char *temp, int file_count, char *filename) {
  int r = 0;
  for (int i = 0; temp[i]; i++) temp[i] = tolower(temp[i]);
  if (strstr(line, temp) != NULL) r = 1;
  for (int i = 0; temp[i]; i++) temp[i] = toupper(temp[i]);
  if (strstr(line, temp) != NULL) r = 1;
  if (file_count > 1 && r == 1) printf("%s:", filename);
  if (r == 1) printf("%s", line);
}
int choose_flag(char *flag) {
  int l = 0;
  if (flag[1] == 'e')
    l = 1;
  else if (flag[1] == 'i')
    l = 2;
  else if (flag[1] == 'v')
    l = 3;
  else if (flag[1] == 'c')
    l = 4;
  else if (flag[1] == 'l')
    l = 5;
  else if (flag[1] == 'n')
    l = 6;
  else {
    printf("wrong_flag: %s\n", flag);
  }
  return l;
}
void choose_opt(int str_counter, char *temp, char *line, char *filename, int l,
                int file_count) {
  if (l == 3) option_v(line, temp, file_count, filename);
  if (l == 2) option_i(line, temp, file_count, filename);
  if (strstr(line, temp) != NULL && l != 2 && l != 3 && l != 4 && l != 5) {
    if (file_count > 1) printf("%s:", filename);
    switch (l) {
      case 1:
        printf("%s", line);
        break;
      case 6:
        printf("%d: %s", str_counter, line);
        break;
      default:
        printf("%s", line);
        break;
    }
  }
}
