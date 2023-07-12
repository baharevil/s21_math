#include <ieee754.h>
#include <stdio.h>

#include "s21_math.h"

long double s21_pow(double base, double exp) {
  double result = 1, epsilon = 1e-10;
  union ieee754_double x754_base, x754_exp, x754_full = {0};
  // union ieee754_double x754_base, x754_full = {0};

  x754_base.d = (double)s21_fabs(base);
  x754_exp.d = exp;

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка на бесконечность в base
  if ((x754_base.ieee.exponent == x754_full.ieee.exponent) &&
      (x754_base.ieee.mantissa0 == 0))
    result = S21_INF;

  // Проверка на бесконечность в exp
  else if ((x754_exp.ieee.exponent == x754_full.ieee.exponent) &&
      (x754_exp.ieee.mantissa0 == 0) && x754_base.d > 1.0) {
      if(x754_exp.ieee.negative) 
        result = 0.0;
      else 
        result = S21_INF;
      }

  // Проверка на 1 как в pow так и в base
  else if (s21_fabs((double)(exp - 1.0)) < epsilon ||
           s21_fabs((double)(base - 1.0)) < epsilon)
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

    result *= (double)s21_exp((exp * (double)s21_log(x754_base.d)));

    if ((base < 0) && (s21_fabs((double)s21_fmod(exp, 2.0) - 1.0) < epsilon))
      result *= -1;
  }

  return result;
}