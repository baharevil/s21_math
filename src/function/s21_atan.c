#include "s21_ieee754.h"
#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0;
  union ieee754_double copy_x, x754_full = {0};

  // Создаем копию преходящего аргумента
  copy_x.d = x;

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Максмально допустимое значение x 1е16.
  if (copy_x.d > 1e16) copy_x.d = S21_INF;

  // Проверка на +-NAN
  if ((copy_x.ieee_nan.exponent == x754_full.ieee.exponent) &&
      (copy_x.ieee_nan.quiet_nan))
    result = x;

  // Проверка на +-INF
  else if ((copy_x.ieee.exponent == x754_full.ieee.exponent) &&
           (copy_x.ieee.mantissa0 == 0))
    result = (double)(-1 + 2 * !copy_x.ieee.negative) * S21_M_PI_2;

  // Проверка на +-1
  else if ((s21_fabs((double)s21_fabs(copy_x.d) - 1) < S21_MIN_VAL))
    result = (double)(-1 + 2 * !copy_x.ieee.negative) * S21_M_PI_4;

  else {
    // Проверяем валидность
    unsigned short is_valid = (copy_x.d > -1 && copy_x.d < 1);

    if (is_valid)
      result = x;
    else
      result = 1 / x;

    // Создаем необходимые перменые
    long double prev_result = 0, epsilon = 1e-20, n = 2, temp = result,
                square_x = s21_pow((double)temp, 2);

    // Метод расчета: ряд Тейлора
    while (s21_fabs((double)(result - prev_result)) > epsilon) {
      prev_result = result;
      temp *= -square_x;
      result += temp / (2 * n - 1);
      n++;
    }

    if (!is_valid) result = (S21_M_PI * s21_fabs(x) / (2 * x)) - result;
  }

  return (double)result;
}