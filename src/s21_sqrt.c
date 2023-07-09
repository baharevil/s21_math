#include "s21_math.h"
#include <ieee754.h>


long double s21_sqrt(double x) {
    double result = 0;
    union ieee754_double x754, x754_full = {0};

    x754.d = x;

    // (1 << 11) - 1 = 2047
    x754_full.ieee.exponent = (1 << 11) - 1;

    // Проверка на отрицательную бесконечность 
    if (x754.ieee.negative && (x754.ieee.exponent == x754_full.ieee.exponent) &&
           (x754.ieee.mantissa0 == 0))
        result = -S21_NAN;

    else 
        result = (double)s21_pow(x, 0.5);
    
    return result; 
}