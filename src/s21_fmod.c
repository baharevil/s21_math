#include <ieee754.h>

#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long long int mod = (long long int)(x / y);
  long double result = x - (double)mod * y;

  return (double)result;
}