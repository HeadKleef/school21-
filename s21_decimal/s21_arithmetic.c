#include "s21_decimal.h"

void add_view(s21_decimal *val)
{ /*Вложенный цикл имеет ошибку в условии (i вместо j).
Результат сдвига внутри вложенного цикла не сохраняется, что, вероятно, является ошибкой.
Отсутствует оператор увеличения i во внешнем цикле (i++), что может привести к бесконечному циклу, если условие val->bits[0] < S21_MAX_INT всегда выполняется.*/

    for (int i = 0; val->bits[0] < S21_MAX_INT; i++)
    {
        for (int j = 0; i < 3; j++)
        {
            val->bits[j] << 1;
        }
        set_exponent(get_exponent(val->bits[3]) - 1, val);
    }
}
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{ // оператор сложения
    int floating_1=0;
    for (int i = 0; i < 4; i++){
        int bit_v1 = value_1.bits[i];
        int bit_v2 = value_2.bits[i];
        int result_bit = 0;
        for (int j = 0; j < 32; j++){
            result_bit += pow(((bit_v1%2+bit_v2%2)+floating_1)%2, j);
            floating_1=((bit_v1%2+bit_v2%2)+floating_1)/2;
        }
    }
}

// int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){} // оператор вычитания

// int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){} // оператор умножения

// int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){} // оператор деления
