#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns,
                      matrix_t *result) {  //создание матрицы
  int error = OK;

  if (rows < 1 || columns < 1)
    error = FAIL;
  else if (!result)
    error = FAIL;
  else {
    result->rows = rows;
    result->columns = columns;

    result->matrix =
        malloc(sizeof(double) * rows);  // выделение памяти для строк
    if (!result->matrix)
      error = FAIL;
    else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] =
            malloc(sizeof(double) * columns);  // выделение памяти для столбцов
        if (!result->matrix[i]) error = FAIL;
      }
    }
  }
  return error;
}

void s21_remove_matrix(matrix_t *A) {  // очистка матрицы

  for (int i = 0; i < A->rows; i++) {  // очистка столбцов
    free(A->matrix[i]);
  }
  free(A->matrix);  // очистка строк
  A->matrix = NULL;
  if (A->rows) A->rows = 0;
  if (A->columns) A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {  // сравнение матриц
  int error = FAILURE;

  if (is_okay(A) && is_okay(B) && A->columns == B->columns &&
      A->rows == B->rows) {
    error = SUCCESS;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          error = FAILURE;
        }
      }
    }
  }
  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A->matrix == NULL) {
    return FAIL;
  }
  if (A->rows == 0 || A->columns == 0) {
    return CALC_ERROR;
  }
  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return OK;
}

int s21_inverse_matrix(matrix_t *A,
                       matrix_t *result) {  // инвертирование матрицы
  int error = FAIL;
  if (is_okay(A)) {
    error = OK;
    double det = 0;
    s21_determinant(A, &det);
    if (A->rows != A->columns || det == 0) {
      error = CALC_ERROR;
    } else {
      matrix_t complements;
      matrix_t transponse;
      int compl = s21_calc_complements(A, &complements);
      int create = s21_transpose(&complements, &transponse);
      if (create == 0 && compl == 0) {
        error = s21_mult_number(&transponse, 1 / det, result);
        s21_remove_matrix(&complements);
        s21_remove_matrix(&transponse);
      }
    }
  }
  return error;
}
