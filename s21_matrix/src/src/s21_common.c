#include "s21_matrix.h"

int is_okay(matrix_t *A) {
  return (A != NULL && A->rows > 0 && A->columns > 0 && A->matrix != NULL);
}

int are_sizes_equal(matrix_t A, matrix_t B) {
  return (A.rows == B.rows && A.columns == B.columns);
}

int s21_can_be_multiplied(matrix_t *A, matrix_t *B) {
  return (A->columns == B->rows);
}
