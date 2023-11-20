#include "s21_ieee754.h"
#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0;
  union ieee754_double copy_x, x754_full = {0};

  // Создаем копию преходящего аргумента
  copy_x.d = x;

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка на +-NaN
  if ((copy_x.ieee_nan.exponent == x754_full.ieee.exponent) &&
      (copy_x.ieee_nan.quiet_nan))
    result = x;

  // В люом другом случае х число
  else {
    // Метод подсчета: разложение в ряд Тейлора

    // В результат кладем приведенный х
    result = (double)s21_fmod(copy_x.d, 2 * S21_M_PI);

    // Создаем необходимы дополнительные перменные
    long double temp = result, square_x = s21_pow((double)temp, 2),
                prev_result = 0, epsilon = 1e-20, n = 2;

    while (s21_fabs((double)(result - prev_result)) > epsilon) {
      prev_result = result;
      temp *= -1.0 * square_x / (n * (n + 1));
      result += temp;
      n += 2;
    }
  }

  return (double)result;
}