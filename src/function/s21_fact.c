#include "../s21_math.h"

long double s21_fact(double x) {
  register long double result = 1;
  for (long double i = 1; i <= x; i++) result *= i;
  return result;
}