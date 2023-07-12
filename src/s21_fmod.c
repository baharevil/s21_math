#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long long int mod = 0;
  long double result = 0;


  // ВАРИАНТ_1
  mod = (long long int)(x / y);
  result = x - (double)mod * y;

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