#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef OPTIONS_H_
#define OPTIONS_H_

int choose_flag(char *flag);
void choose_opt(int str_counter, char *temp, char *line, char *filename, int l,
                int file_count);
void option_v(char *line, char *temp, int file_count, char *filename);
void option_c(int comp_counter, int file_count, char *filename);
void option_l(char *filename);
void option_i(char *line, char *temp, int file_count, char *filename);
#endif