#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0;
  union ieee754_double copy_x, copy_y, x754_full = {0};

  // Создаем копии преходящих аргументов
  copy_x.d = x;
  copy_y.d = y;

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка на x / 0
  if (s21_fabs(copy_y.d - 0) < S21_MIN_VAL)
    result = S21_NAN;

  // Проверка х = nan
  else if ((copy_x.ieee_nan.negative == 0) &&
           (copy_x.ieee_nan.exponent == x754_full.ieee.exponent) &&
           (copy_x.ieee_nan.quiet_nan))
    result = x;

  // Проверка х = +-inf
  else if ((copy_x.ieee_nan.exponent == x754_full.ieee.exponent) &&
           (copy_x.ieee_nan.mantissa0 == 0))
    result = S21_NAN;

  // Проверка y = +-nan
  else if ((copy_y.ieee_nan.exponent == x754_full.ieee.exponent) &&
           (copy_y.ieee_nan.quiet_nan))
    result = y;

  // Проверка y = +-inf
  else if ((copy_y.ieee_nan.exponent == x754_full.ieee.exponent) &&
           (copy_y.ieee_nan.mantissa0 == 0))
    result = x;

  // Любой другой вариант
  else {
    long long int mod = (long long int)(copy_x.d / copy_y.d);
    result = copy_x.d - (long double)mod * copy_y.d;
  }

  return (double)result;
}