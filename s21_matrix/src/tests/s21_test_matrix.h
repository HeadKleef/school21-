#ifndef S21_TEST_MATRIX_H_
#define S21_TEST_MATRIX_H_

#include <check.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#include "../s21_matrix.h"

#define CALCULATION_ERROR 2
#define INVALID_MATRIX 1

Suite *suite_matrix_all(void);
Suite *suite_create_matrix(void);
Suite *suite_eq_matrix(void);

Suite *suite_transpose_matrix(void);
Suite *suite_sum_matrix(void);
Suite *suite_sub_matrix(void);
Suite *suite_mult_matrix(void);
Suite *suite_mult_number_matrix(void);

Suite *suite_calc_complements(void);
Suite *suite_determinant(void);
Suite *suite_inverse_matrix(void);

void run_test(void);
void run_testcase(Suite *testcase);
double get_rand(double min, double max);

#endif
