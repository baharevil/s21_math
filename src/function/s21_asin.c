#include "../s21_math.h"

long double s21_asin(double x) {
  long double result = 0;
  unsigned is_valid = 0;

  /*
      Область значения синуса находять на промежутке от -1 до 1 включительно,
      поэтому х должен быть в данном прбежутке.
  */
  if ((x > -1 && x < 1) || (s21_fabs((double)s21_fabs(x) - 1) < 1e-60))
    is_valid = 1;

  /*
      Самое важное проверить область значние.
      Остальная валидация на +-NAN, +-INF и +-1
      пройдут в функции s21_atan.
  */
  if (is_valid)
    //Основная формула расчета: asin = atan(x / sqrt(1 - x^2))
    result = s21_atan(x / (double)s21_sqrt(1.0 - (double)s21_pow(x, 2)));
  else
    // define NAN возвращается отрицательным, поэтому юзаем fabs
    result = s21_fabs(S21_NAN);

  return (double)result;
}