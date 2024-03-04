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

  if (is_okay(A) && is_okay(B) &&
      A->columns == B->columns &&  // сравнение  размера матриц
      A->rows == B->rows) {
    error = SUCCESS;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >
            1e-7) {  // сравнение значений матриц
          error = FAILURE;
        }
      }
    }
  }
  return error;
}

int s21_transpose(matrix_t *A,
                  matrix_t *result) {  // транспонирование матриц (перевод
                                       // столбов в строки и наоборот)
  int ret = CALC_ERROR;
  if (!is_okay(A))
    ret = FAIL;  // проверка матрицы на существование
  else {
    if (s21_create_matrix(A->rows, A->columns, result) == 0) {
      ret = OK;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] =
              A->matrix[j][i];  // умножение каждого элемента матрицы на число
        }
      }
    }
    ret = CALC_ERROR;  // возврат ошибки в случае проблем
  }
  return ret;
}

int s21_inverse_matrix(matrix_t *A,
                       matrix_t *result) {  // инвертирование матрицы
}
