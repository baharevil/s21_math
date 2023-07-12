#include <ieee754.h>
#include <stdio.h>

#include "s21_math.h"

long double s21_pow(double base, double exp) {
  double result = 1, epsilon = 1e-10,
         mod = (double)s21_fabs((double)s21_fmod(exp, 1.0));
  union ieee754_double copy_base, copy_exp, x754_full = {0};

  // Создаем копии преходящих аргументов
  copy_base.d = (double)s21_fabs(base);
  copy_exp.d = (double)s21_fabs(exp);

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка на бесконечность в exp
  if ((copy_exp.ieee.exponent == x754_full.ieee.exponent) &&
      (copy_exp.ieee.mantissa0 == 0) && copy_base.d > 1.0) {
    if (exp < 0)
      result = 0.0;
    else
      result = S21_INF;
  }

  // Проверка на 1 как в pow так и в base
  else if (s21_fabs((double)(copy_exp.d - 1.0)) < epsilon ||
           s21_fabs((double)(copy_base.d - 1.0)) < epsilon)
    result = base;

  // Проверка на 0 в pow
  else if (s21_fabs((double)(copy_exp.d - 0)) < epsilon)
    result = 1;

  // Проверка на случай если base < 0 и exp не целое число
  else if ((base < 0) && (mod > 0))
    result = -S21_NAN;

  else {
    // Шагаем в циклое целыми шагами
    while ((copy_exp.d - mod) > 0) {
      result *= copy_base.d;
      copy_exp.d--;
    }

    // Выполняем домножение если в exp существует что-то после запятой
    if (mod > 0)
      result *= (double)s21_exp((copy_exp.d * (double)s21_log(copy_base.d)));

    // Второе условие проверяет четность exp
    if ((base < 0) && (s21_fabs((double)s21_fmod(exp, 2.0) - 1.0) < epsilon))
      result *= -1;

    if (exp < 0) result = 1 / result;
  }

  return result;
}