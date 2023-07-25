#include <stdio.h>

#include "../s21_math.h"

// Если нужно будет посмотреть подетальнее на работу ВАРИАНТА_3
// вызывайте следующую функцию.

// Показывает бинарное представление числа типа double в формате:
// знак(1) - экспонента(11) - мантисса0(20) - мантисса1(32)
void bin_double(double x) {
  union ieee754_double x754;
  x754.d = x;

  int size = 64;
  int arr[size];
  int i = 63;

  printf("the number is %.25f\n", x);

  for (; i != 31; i--, x754.ieee.mantissa1 >>= 1) {
    *(arr + i) = x754.ieee.mantissa1 & 0x1;
  }

  for (; i != 11; i--, x754.ieee.mantissa0 >>= 1) {
    *(arr + i) = x754.ieee.mantissa0 & 0x1;
  }

  for (; i != 0; i--, x754.ieee.exponent >>= 1) {
    *(arr + i) = x754.ieee.exponent & 0x1;
  }

  *(arr + i) = x754.ieee.negative & 0x1;

  for (; i < size; i++) {
    printf("%d", *(arr + i));
    // if (((i == 0) || (i == 11)) || ((i > 13) && (i % 13 == 0))) printf(" ");
    if (((i == 0) || (i == 11)) || (i == 31)) printf(" ");
  }

  printf("\n");
}

long double s21_fmod(double x, double y) {
  long double result = 0;
  union ieee754_double copy_x, copy_y, x754_full = {0};

  // Создаем копии преходящих аргументов
  copy_x.d = x;
  copy_y.d = y;

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка на 0 / 0
  if ((s21_fabs(copy_x.d - 0) < S21_MIN_VAL) &&
      (s21_fabs(copy_y.d - 0) < S21_MIN_VAL))
    result = -S21_NAN;

  // Проверка х = nan
  else if ((copy_x.ieee_nan.negative == 0) &&
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

  // Проверка y = +-inf
  else if ((copy_y.ieee_nan.exponent == x754_full.ieee.exponent) &&
           (copy_y.ieee_nan.mantissa0 == 0))
    result = x;

  // Любой другой вариант
  else {
    // ВАРИАНТ_1
    // long long int mod = (long long int)(x / y);
    // result = x - (long double)mod * y;

    // ВАРИАНТ_2 - медленный
    // long double temp = x / y;
    // long int temp_1 = 0;

    // if (temp > 1.0)
    //   while (temp > temp_1)
    //     temp_1 += 1;

    // result = x - (long double)(temp_1 - 1) * y;

    // ВАРИАНТ_3
    long int degree = 0;
    union ieee754_double int_part = {0}, temp = {0};
    int_part.d = (double)s21_fabs(copy_x.d / copy_y.d);

    // Это необходимо чтобы в экспоненте было 1023
    temp.d = 1.0;

    // printf("\nint_part.d = x / y before the modifications\n");
    // bin_double(int_part.d);  // Для того чтобы посмотреть что там с битами

    // (s21_fabs((double)(int_part.d - 1)) < 1e-60) -
    // эквивалентно int_part.d ==1
    if ((int_part.d > 1) || (s21_fabs((double)(int_part.d - 1)) < 1e-60)) {
      // Получаем степень сдвига в экспоненте
      // degree = int_part.ieee.exponent(степень сдвига в числе x / y) -
      // temp.ieee.exponent(1023);
      degree = (int_part.ieee.exponent - temp.ieee.exponent);

      while (degree > 52) degree -= 52;

      // Если степень == 52, то нам понадобятся все биты с мантиссы
      if (degree == 52) {
        // Инвертируем чтобы все биты стали 1
        temp.ieee.mantissa0 = ~temp.ieee.mantissa0;
        temp.ieee.mantissa1 = ~temp.ieee.mantissa1;
      }

      // Если степень больше 20, то нам понадобится вся мантисса0 и степень
      // минус 20 бит мантиссы1
      else if (degree > 20) {
        // Инвертируем чтобы все биты стали 1
        temp.ieee.mantissa0 = ~temp.ieee.mantissa0;
        temp.ieee.mantissa1 = ~temp.ieee.mantissa1;

        // Сдвигаемся вправо на количетсво степеней (забивается 0 из-за правого
        // сдвига)
        temp.ieee.mantissa1 >>= (degree - 20);

        // Производим обратную инверсию, так чтобы 0 стали 1, а 1 стали 0
        temp.ieee.mantissa1 = ~temp.ieee.mantissa1;
      }

      // Если степень <= 20, то нам хватит только мантиссы0
      else {
        // Инвертируем чтобы все биты стали 1
        temp.ieee.mantissa0 = ~temp.ieee.mantissa0;

        // Сдвигаемся вправо на количетсво степеней (все забивается 0 из-за
        // правого сдвига)
        temp.ieee.mantissa0 >>= degree;

        // Производим обратную инверсию, так чтобы 0 стали 1 (это и есть наша
        // целая часть), а 1 стали 0
        temp.ieee.mantissa0 = ~temp.ieee.mantissa0;
      }

      // printf("\nthis is temp\n");
      // bin_double(temp.d);  // Для того чтобы посмотреть что там с битами

      // Производим логическое "и" чтобы убрать дробную часть и оставить только
      // целую часть от деления х / у
      int_part.ieee.mantissa0 &= temp.ieee.mantissa0;
      int_part.ieee.mantissa1 &= temp.ieee.mantissa1;

      // printf("\nint_part.d = x / y after the modifications\n");
      // bin_double(int_part.d);  // Для того чтобы посмотреть что там с битами

    } else {
      int_part.d = 0;
    }

    // В конце получаем подсчитываем остаток от деления
    result =
        (double)s21_fabs(copy_x.d) - ((double)s21_fabs(copy_y.d) * int_part.d);

    if (copy_x.ieee_nan.negative) result *= -1;
  }

  return (double)result;
}