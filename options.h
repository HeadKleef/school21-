#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef OPTIONS_H_
#define OPTIONS_H_

int choose_flag(char *flag);
void choose_opt(int str_counter, char *temp, char *line, char*filename, int l);
void option_c(int comp_counter);
#endif