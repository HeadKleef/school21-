#include "s21_decimal.h"

void add_view (s21_decimal *val) {

    for(int i = 0; val->bits[0] < S21_MAX_INT; i++) {
        for(int j = 0; i < 3; j++) {
            val->bits[j] << 1;
        }
        set_exponent(get_exponent(val->bits[3]) - 1, val);
    }
}
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){ // оператор сложения 


} 


//int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){} // оператор вычитания 

//int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){} // оператор умножения 

//int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){} // оператор деления 

