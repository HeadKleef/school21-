#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

} flags;

int main(int argc, char *argv[]);
void open_file(char *filename, char *temp, flags *option, int file_count);
int flag_check(char *flag);
#endif