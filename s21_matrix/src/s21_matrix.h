#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef S21_STRING_H_
#define S21_STRING_H_

#define SUCCESS 1
#define FAILURE 0

#define EPSILON 1e-7

#define OK 0
#define FAIL 1
#define CALC_ERROR 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);          // + создание матрицы
void s21_remove_matrix(matrix_t *A);                                     // +  очистка матрицы
int s21_eq_matrix(matrix_t *A, matrix_t *B);                             // + сравнение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);          // + сложение матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);          // + вычитание матриц
int s21_mult_number(matrix_t *A, double number, matrix_t *result);       // + умножение матрицы на число
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);         // + умножение двух матриц
int s21_transpose(matrix_t *A,matrix_t *result);                         // + транспонирование матриц (перевод столбов в строки и наоборот)
int s21_calc_complements(matrix_t *A, matrix_t *result);                 // + матрица алгебраических дополнений
int s21_determinant(matrix_t *A, double *result);                        // + определитель матрицы
int s21_inverse_matrix(matrix_t *A,  matrix_t *result);                  // + инвертирование матрицы
int s21_minor(matrix_t *A, int row, int column, matrix_t *result);       // + минор матрицы

int is_okay(matrix_t *A);
int are_sizes_equal(matrix_t A, matrix_t B);
int s21_can_be_multiplied(matrix_t *A, matrix_t *B);


#endif