#include <stdio.h>
#include <stdlib.h>

#ifndef CHOOSE_H_
#define CHOOSE_H_

int choose_flag(int i, int p, char ch, FILE *file);
int is_empty_line(FILE *file);
int new_line(char c);
int is_tab(char c);
void option_e(char ch);
void option_E(char ch);
int option_n(int i, char ch);
int option_b(int i, char ch, FILE *file);
int option_s(char ch, FILE *file, int i);
void option_t(char ch);
void option_T(char ch);
void option_v(unsigned char ch);

#endif