#include "../s21_math.h"

// В данной функции не реализлваны проверки на nan и inf
// в связи с тем, что все проверки реализованы в sin и cos
long double s21_tan(double x) {
  long double present_x = s21_fmod(x, 2 * S21_M_PI);
  long double result = s21_sin((double)present_x) / s21_cos((double)present_x);
  return (double)result;
}