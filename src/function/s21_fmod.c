#include "../s21_math.h"

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

    // ВАРИАНТ_2
    // long double mod = -1, temp = 0;//, result = 0;
    // long double copy = s21_fabs(x);

    // while (temp < copy) {
    //   mod++;
    //   temp += y;
    // }

    // result = copy - mod * y;

    // if (x < 0)
    //   result *= -1;

    // ВАРИАНТ_3 
    // long int degree = 0;
    // union ieee754_double int_part = {0}, temp = {0};
    // int_part.d = x / y;
    
    // // Получаем степень сдвига в экспоненте
    // degree = int_part.ieee.exponent - 1023;

    // // Инвертируем чтобы все биты стали 1
    // temp.ieee.mantissa0 = ~temp.ieee.mantissa0; 
    
    // // Сдвигаемся вправо на количетсво степеней (все забивается 0 из-за правого сдвига)
    // temp.ieee.mantissa0 >>= degree;

    // // Производим обратную инверсию, так чтобы 0 стали 1 (это и есть наша целая часть), а 1 стали 0
    // temp.ieee.mantissa0 = ~temp.ieee.mantissa0; 
    
    // // Производим логическое и чтобы убрать хвостик и оставить только целую часть от деления х / у
    // int_part.ieee.mantissa0 &= temp.ieee.mantissa0;
    
    // // В конце просто получаем хвостик х
    // result = x - y * int_part.d;
  }

  return result;
}