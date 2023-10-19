#include <stdio.h>
#include <stdlib.h>

#ifndef CHOOSE_H_
#define CHOOSE_H_

int choose_flag(int i, int p, char ch, FILE *file);
int is_empty_line(FILE *file);
int new_line(char c);
int is_tab(char c);
void option_e(char ch);
int option_n(int i, char ch);
int option_b(int i, char ch, FILE *file);
void option_s(char ch, FILE *file);
void option_t(char ch);

#endif
