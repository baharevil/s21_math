#include <stdio.h>

#include "s21_math.h"

long double s21_log(const double x) {
  double result = 0;
  union ieee754_double copy_x, x754_full = {0};

  copy_x.d = x;

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка на отрицательный 0
  if (copy_x.ieee.negative && s21_fabs((double)(x - 0)) < S21_MIN_VAL)
    result = -S21_INF;

  // Проверка на 1
  else if (s21_fabs((double)(x - 1)) < S21_MIN_VAL)
    result = 0;

  // Проверка на отрицательное число
  else if (copy_x.ieee.negative != 0)
    result = -S21_NAN;

  // Проверка на бесконечность
  else if ((copy_x.ieee.exponent == x754_full.ieee.exponent) &&
           (copy_x.ieee.mantissa0 == 0))
    result = S21_INF;

  // Проверка на минимальное допустимое значение
  else if (copy_x.d < S21_MIN_VAL)
    result = -S21_INF;

  // В любом другом случае будет число > 0
  else {
    // инициализируем необходимые переменные
    double prev_result = 0, epsilon = 1e-10, count = 0;

    while (copy_x.d > S21_M_E) {
      copy_x.d /= S21_M_E;
      count++;
    }

    result = copy_x.d - 2;

    while ((double)s21_fabs((result - prev_result)) > epsilon) {
      prev_result = result;
      result = prev_result + 2.0 * (copy_x.d - (double)s21_exp((prev_result))) /
                                 (copy_x.d + (double)s21_exp((prev_result)));
    }

    result += count;
  }

  return result;
}