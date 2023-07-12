#include "s21_math.h"

long double s21_log(const double x) {
  double result = 0, prev_result = 0, epsilon = 1e-10, count = 0;
  union ieee754_double x754, x754_full = {0};

  x754.d = x;

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка на отрицательное число
  if (x754.ieee.negative != 0) result = -S21_NAN;

  // Проверка на бесконечность
  else if ((x754.ieee.exponent == x754_full.ieee.exponent) &&
           (x754.ieee.mantissa0 == 0))
    result = S21_INF;

  // Проверка на минимальное допустимое значение
  else if (x754.d < S21_MIN_VAL)
    result = -S21_INF;

  // В любом другом случае будет число > 0
  else {
    while (x754.d > S21_M_E) {
      x754.d /= S21_M_E;
      count++;
    }

    result = x754.d - 1;

    while ((double)s21_fabs((result - prev_result)) > epsilon) {
      prev_result = result;
      result = prev_result + 2.0 * (x754.d - (double)s21_exp((prev_result))) /
                                 (x754.d + (double)s21_exp((prev_result)));
    }

    result += count;
  }

  return result;
}