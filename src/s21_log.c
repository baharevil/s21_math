#include <ieee754.h>
#include <stdio.h>

#include "s21_math.h"

// Замечание 1: есть какие-то аномальные числа, при которых падает точность
//              например 0.8 - 1.4, 3, 10, 100, 10000,

// Замечание 2: считает до числа с 19 нулями, после этого обваливается
//              (максимально рассчитаное число 900_000_000_000_000_000_000)

// Замечание 3: после ниже приведенного числа уходит в inf
//              .00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000009

long double s21_log(const double x) {
  long double result = 0, prev_result = 0, epsilon = 1e-20;
  union ieee754_double x754, x754_full = {0};

  x754.d = x;
  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка на отрицательное число
  if ((x754.ieee.negative && x754.ieee.mantissa0 != 0)) result = S21_NAN;

  // Проверка на бесконечность отрицательную
  else if ((x754.ieee.negative != 0 &&
            (x754.ieee.exponent == x754_full.ieee.exponent) &&
            x754.ieee.mantissa0 == 0))
    result = S21_NAN;

  // Проверка на бесконечность положительную
  else if ((x754.ieee.negative == 0 &&
            (x754.ieee.exponent == x754_full.ieee.exponent) &&
            (x754.ieee.mantissa0 == 0)))
    result = S21_INF;

  // Проверка на 0
  else if (x754.ieee.exponent == 0 && x754.ieee.mantissa0 == 0)
    result = -S21_INF;

  // В любом другом случае будет число > 0
  else {
    if (s21_fabs((double)(x - 1)) > 1) {
      result = 1 / x754.d;  // Для случая когда х больше 1
      while ((result - prev_result) > epsilon) {
        prev_result = result;
        result = prev_result +
                 (long double)2 * ((x754.d - s21_exp((double)prev_result)) /
                                   (x754.d + s21_exp((double)prev_result)));
      }
    } else {
      result = x754.d - 1.0;  // Для случая когда х меньше 1 соответсвенно
      do {
        prev_result = result;
        result = prev_result + 2 * ((x754.d - s21_exp((double)prev_result)) /
                                    (x754.d + s21_exp((double)prev_result)));
      } while ((prev_result - result) > epsilon);
    }
  }

  return (double)result;
}