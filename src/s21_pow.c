#include <ieee754.h>

#include "s21_math.h"

long double s21_pow(double base, double exp) {
  double result = 1, epsilon = 1e-10;
  union ieee754_double x754, x754_full = {0};

  x754.d = (double)s21_fabs(base);

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка на бесконечность в base
  if ((x754.ieee.exponent == x754_full.ieee.exponent) &&
      (x754.ieee.mantissa0 == 0))
    result = S21_INF;

  // Проверка на 1 как в pow так и в base
  else if (s21_fabs((double)(exp - 1)) < epsilon ||
           s21_fabs((double)(base - 1)) < epsilon)
    result = base;

  // Проверка на 0 в pow
  else if (s21_fabs((double)(exp - 0)) < epsilon)
    result = 1;

  else if ((s21_fmod(exp, 1.0) > 1e-323) && (base < 0))
    result = -S21_NAN;

  else {
    while (exp > 1.0) {
      result *= base;
      exp--;
    }

    result *= (double)s21_exp((exp * (double)s21_log(x754.d)));

    if ((base < 0) && (s21_fabs((double)s21_fmod(exp, 2.0) - 1) <
                       epsilon))  // Необходимо исправить и написать свой fmod
      result *= -1;
  }

  return result;
}