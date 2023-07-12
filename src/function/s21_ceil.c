#include "../s21_math.h"

long double s21_ceil(double x) {
  double mod = 0, result = 0;
  union ieee754_double copy_x, x754_full = {0};

  // Создаем копию
  copy_x.d = x;

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка х = +-inf
  if ((copy_x.ieee_nan.exponent == x754_full.ieee.exponent) &&
      (copy_x.ieee_nan.mantissa0 == 0))
    result = x;

  else {
    mod = (double)s21_fmod(x, 1.0);
    result = x - mod;
    if ((s21_fabs((double)mod) > 0) && x > 0) result++;
  }
  return result;
}