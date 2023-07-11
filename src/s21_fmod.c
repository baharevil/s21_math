#include "s21_math.h"

long double s21_fmod(double x, double y) {
  // ВАРИАНТ_1
  long long int mod = (long long int)(x / y);
  long double result = x - (double)mod * y;

  // ВАРИАНТ_2
  // long double mod = -1, temp = 0, result = 0;
  // long double copy = s21_fabs(x);

  // while (temp < copy) {
  //   mod++;
  //   temp += y;
  // }

  // result = copy - mod * y;

  // if (x < 0)
  //   result *= -1;

  return (double)result;
}