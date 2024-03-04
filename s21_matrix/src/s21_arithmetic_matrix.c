#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result) {  // сложение матриц
  int ret = CALC_ERROR;

  if (!is_okay(A) || !is_okay(B))
    ret = FAIL;  // проверка матриц на существование
  else {
    if (is_okay(A) && is_okay(B) && are_sizes_equal(*A, *B)) {
      if (s21_create_matrix(A->rows, A->columns, result) == 0) {
        ret = OK;
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] =
                A->matrix[i][j] +
                B->matrix[i][j];  // сложение каждого элемента матрицы
          }
        }
      }
    } else
      ret = CALC_ERROR;  // возврат ошибки в случае проблем
  }
  return ret;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result) {  // вычитание матриц
  int ret = CALC_ERROR;

  if (!is_okay(A) || !is_okay(B))
    ret = FAIL;  // проверка матриц на существование
  else {
    if (is_okay(A) && is_okay(B) && are_sizes_equal(*A, *B)) {
      if (s21_create_matrix(A->rows, A->columns, result) == 0) {
        ret = OK;
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] =
                A->matrix[i][j] -
                B->matrix[i][j];  // вычитание  каждого элемента матрицы
          }
        }
      }
    } else
      ret = CALC_ERROR;  // возврат ошибки в случае проблем
  }
  return ret;
}

int s21_mult_number(matrix_t *A, double number,
                    matrix_t *result) {  // умножение матрицы на число
  int ret = CALC_ERROR;
  if (!is_okay(A))
    ret = FAIL;  // проверка матрицы на существование
  else {
    if (s21_create_matrix(A->rows, A->columns, result) == 0) {
      ret = OK;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] =
              A->matrix[i][j] *
              number;  // умножение каждого элемента матрицы на число
        }
      }
    }
    ret = CALC_ERROR;  // возврат ошибки в случае проблем
  }
  return ret;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B,
                    matrix_t *result) {  // умножение двух матриц
  int ret = CALC_ERROR;

  if (!is_okay(A) || !is_okay(B))
    ret = FAIL;  // проверка матриц на существование
  else {
    if (!s21_can_be_multiplied(A, B)) {
      ret = CALC_ERROR;
    } else {
      if (s21_create_matrix(A->rows, A->columns, result) == 0) {
        ret = OK;
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }

      } else
        ret = CALC_ERROR;  // возврат ошибки в случае проблем
    }
  }
  return ret;
}

int s21_calc_complements(
    matrix_t *A,
    matrix_t *result) {  //Минор матрицы и матрица алгебраических дополнений
  int ret = FAIL;
  if (is_okay(A)) {
    ret = OK;
    if (A->rows != A->columns)
      ret = CALC_ERROR;
    else {
      if (s21_create_matrix(A->rows, A->columns, result) == 0) {
        if (A->rows == 1 && A->columns == 1) {
          result->matrix[0][0] = A->matrix[0][0];
        }
      }
    }
  }
}
int s21_determinant(matrix_t *A, double *result) {  // определитель матрицы
}

int s21_minor(matrix_t *A, int row, int column, matrix_t *result) {
  int error = FAIL;
  if (is_okay(A) && A->rows == A->columns) {  //проверка матриц на существование
    if (s21_create_matrix(A->rows - 1, A->columns - 1, result) == 0 &&
        row < A->rows &&
        column < A->columns) {  // выделениен памяти под итоговую матрицу
      error = OK;
      int n = -1;
      for (int i = 0; i < A->rows; i++) {
        if (i != row) {
          n++;
          int m = -1;  // вычисление минора каждого элемента матрицы А
          for (int j = 0; j < A->columns; j++) {
            if (j != column) {
              m++;
              result->matrix[n][m] =
                  A->matrix[i]
                           [j];  // перенос полученных данных в итоговую матрицу
            }
          }
        }
      }
    } else {
      error = CALC_ERROR;  // возврат ошибки в случае проблем
    }
  }
  return error;
}