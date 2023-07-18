#include "../s21_math.h"

long double s21_floor(double x) {
  double mod = 0, result = 0;
  // double result = 0;
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
    // Versio_1
    mod = (double)s21_fmod(x, 1.0);
    result = x - mod;

    if ((x < 0) && (s21_fabs(mod) > 0)) result--;

    // Versio_2
    // long long copy_x = (long long)x;
    // result = (double)copy_x ;

    // if ((x < 0) && !(s21_fabs(result - x) < 1e-6)) result--;
  }

  return result;
}