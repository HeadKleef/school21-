#include "grep_test.h"

#include "flags_res.h"

int flag_check(char *flag) {
  int i = 0;
  if (flag[0] == 45) i = 1;
  return i;
}
void open_file(char *filename, char *temp, flags *option, int file_count) {
  FILE *stream;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int str_counter = 0;
  int comp_counter = 0;

  // printf("\nfile = %s pattern = %s flag = %d count = %d\n", filename, temp,
  // option->c, file_count);
  stream = fopen(filename, "r");
  if (stream == NULL) exit(EXIT_FAILURE);
  while ((read = getline(&line, &len, stream)) != -1) {
    str_counter++;
    comp_counter = flags_realise(line, *option, filename, file_count, temp,
                                 str_counter, comp_counter);
  }

  option_c(*option, comp_counter, filename, file_count);
  if (comp_counter > 1) option_l(*option, filename);

  free(line);
  fclose(stream);
}
int main(int argc, char *argv[]) {
  flags option = {0};
  // printf("argc = %d\n", argc);
  if (argc > 1 && flag_check(argv[1]) == 1) {
    int i = fill_flags(argc, argv, &option);
    int file_count = argc - (i + 1);
    // printf("i = %d", i);
    int n = i;
    int c = (i + 1);
    while (n < (argc - 1)) {
      // printf("%s", argv[i]);
      open_file(argv[c], argv[i], &option, file_count);
      n++;
      c++;
    }
  } else if (argc > 1) {
    int file_count = argc - 2;
    for (int n = 1; n < argc; n++)
      open_file(argv[2], argv[1], &option, file_count);
  }
  return 0;
}
