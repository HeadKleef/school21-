#include "s21_decimal.h"


int get_exponent(unsigned int bit) {
    for(int i = 0; i < 16; i++) {
        bit /= 2;
    }
    return bit % 256;
}

int get_sign(unsigned int bit) {
    return bit > S21_MAX_INT ? 1 : 0;
}

int get_empty(unsigned int bit) {
    for(int i = 0; i < 16; i++) {
        if(bit % 2 != 0) { 
            return 1;
        }
        bit /= 2;
    }
    bit /= 256;

    for(int i = 0; i < 7; i++) {
        if(bit % 2 != 0) { 
            return 2;
        }
        bit /= 2;
    }
    return 0;
}
void set_exponent(int exp, s21_decimal* val) {
    int tmp = val->bits[3] % (256 * 256);
    int tmp2 = val->bits[3] / (256 * 256 * 256);
    tmp2 = tmp2 << 8;
    tmp2 += exp;
    tmp2 = tmp2 << 16;
    tmp += tmp;
    val->bits[3] = tmp2;
}