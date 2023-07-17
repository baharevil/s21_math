#include "../s21_math.h"

#include <stdio.h>

long double s21_fmod(double x, double y) {
  long double result = 0;

  union ieee754_double copy_x, copy_y, x754_full = {0};

  // Создаем копии преходящих аргументов
  copy_x.d = x;
  copy_y.d = y;

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка х = nan
  if ((copy_x.ieee_nan.negative == 0) &&
      (copy_x.ieee_nan.exponent == x754_full.ieee.exponent) &&
      (copy_x.ieee_nan.quiet_nan))
    result = x;

  // Проверка х = +-inf
  else if ((copy_x.ieee_nan.exponent == x754_full.ieee.exponent) &&
           (copy_x.ieee_nan.mantissa0 == 0))
    result = -S21_NAN;

  // Проверка y = +-nan
  else if ((copy_y.ieee_nan.exponent == x754_full.ieee.exponent) &&
           (copy_y.ieee_nan.quiet_nan))
    result = y;

  // Проверка y = +- inf
  else if ((copy_y.ieee_nan.exponent == x754_full.ieee.exponent) &&
           (copy_y.ieee_nan.mantissa0 == 0))
    result = x;

  // Любой другой вариант
  else {
    // ВАРИАНТ_1
    long long int mod = (long long int)(x / y);
    result = x - (long double)mod * y;

    // ВАРИАНТ_2 - медленный
    // long double temp = x / y;
    // long int temp_1 = 0;

    // if (temp > 1.0)
    //   while (temp > temp_1)
    //     temp_1 += 1;      

    // result = x - (long double)(temp_1 - 1) * y;
  }

  return result;
}