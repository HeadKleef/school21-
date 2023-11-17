

#ifndef GREP_H_
#define GREP_H_

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int def;

} flags;

int main(int argc, char *argv[]);
void open_file(char *filename[], flags *option, int file_count, int filename_co,
               int temp_co, int argc, int opt_e_check);
int flag_check(char *flag);
int check_file_exist(char *filename);

#endif