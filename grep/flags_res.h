#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "grep_test.h"

#ifndef _FLAGS_RES_H_
#define _FLAGS_RES_H_

int fill_flags(int argc, char *argv[], flags *option);
void print_line(char *line);
void print_line_num(int str_counter);
void print_filename(char *filename);
void option_l(flags option, char *filename);
int change_reg(char *line, char *temp);
void option_c(flags option, int comp_counter, char *filename, int file_count);
int flags_realise(char *line, flags option, char *filename, int file_count,
                  char *temp, int str_counter, int comp_counter);

#endif