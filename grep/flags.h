#include "libs.h"
#include "main.h"

#ifndef _FLAGS_RES_H_
#define _FLAGS_RES_H_

void print_line_num(int str_counter);
void print_filename(char *filename);
void option_l(flags option, char *filename);
int change_reg(char *line, char *temp);
void option_c(flags option, int comp_counter, char *filename, int file_count);
int flags_realise(char *line, flags option, char *filename, int file_count,
                  char *temp, int str_counter, int comp_counter);
void fill_flags(int argc, char *argv[], flags *option, char *line,
                int opt_e_check, int file_count, int filename_co);
int flags_count(int argc, char *argv[]);
int option_e(int i, char *line, char *temp);
void print_line(char *line);
int option_f(int file_count, char *filename, int str_counter, flags option,
             int i, char *line, char *line_f);

#endif