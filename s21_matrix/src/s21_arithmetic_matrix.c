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
  int error = FAIL;
  if (is_okay(A)) {
    if (s21_create_matrix(A->rows, A->columns, result) == 0) {
      error = OK;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->rows = A->rows;
          result->columns = A->columns;
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else
      error = FAIL;
  }
  return error;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B,
                    matrix_t *result) {  // умножение двух матриц
  int error = FAIL;
  if (is_okay(A) && is_okay(B)) {  // проверка матриц на существование
    if (!s21_can_be_multiplied(A, B)) {
      error = CALC_ERROR;
    } else {
      if (s21_create_matrix(A->rows, B->columns, result) == 0) {
        result->rows = A->rows;
        result->columns = B->columns;
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
        error = OK;
      } else {
        error = FAIL;
      }
    }
  }
  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A->matrix == NULL) {
    return FAIL;
  }
  double det = 0;
  if (A->rows == 0 || A->columns == 0 || A->rows != A->columns ||
      (s21_determinant(A, &det) != OK || fabs(det) < EPSILON)) {
    return CALC_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  matrix_t temp = {0};
  s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      int k = 0;
      for (int l = 0; l < A->rows; l++) {
        if (l == i) {
          continue;
        }
        int m = 0;
        for (int n = 0; n < A->rows; n++) {
          if (n == j) {
            continue;
          }
          temp.matrix[k][m] = A->matrix[l][n];
          m++;
        }
        k++;
      }
      double res = 0;
      s21_determinant(&temp, &res);
      if ((i + j) % 2 == 0) {
        result->matrix[i][j] = res;
      } else {
        result->matrix[i][j] = -res;
      }
    }
  }
  s21_remove_matrix(&temp);
  return OK;
}
int s21_determinant(matrix_t *A, double *result) {  // определитель матрицы
  int error = FAIL;
  if (is_okay(A)) {  // проверка матриц на существование
    error = OK;
    if (A->rows != A->columns) {
      error = CALC_ERROR;
    } else {
      if (A->rows == 1 && A->columns == 1) {
        *result = A->matrix[0][0];
      } else {
        int sign = 1;
        *result = 0;
        for (int j = 0; j < A->columns; j++) {
          matrix_t temp_matrix;
          int create = s21_minor(A, 0, j, &temp_matrix);
          if (create == 0) {
            double temp_res = 0;
            int status = s21_determinant(&temp_matrix, &temp_res);
            if (status == 0) {
              *result += A->matrix[0][j] * temp_res * sign;
              sign *= -1;
            }
            s21_remove_matrix(&temp_matrix);
          }
        }
      }
    }
  }
  return error;
}

int s21_minor(matrix_t *A, int row, int column,
              matrix_t *result) {  // минор матрицы
  int error = FAIL;
  if (is_okay(A) &&
      A->rows == A->columns) {  // проверка матриц на существование
    if (s21_create_matrix(A->rows - 1, A->columns - 1, result) == 0 &&
        row < A->rows && column < A->columns) {
      error = OK;
      int n = -1;
      for (int i = 0; i < A->rows; i++) {
        if (i != row) {
          n++;
          int m = -1;
          for (int j = 0; j < A->columns; j++) {
            if (j != column) {
              m++;
              result->matrix[n][m] = A->matrix[i][j];
            }
          }
        }
      }
    } else {
      error = CALC_ERROR;
    }
  }
  return error;
}