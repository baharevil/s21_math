#include "../s21_math.h"

long double s21_acos(double x) {
  long double result = 0;
  unsigned is_valid = 0;

  /*
      Область значения косинса находять на промежутке от -1 до 1 включительно,
      поэтому х должен быть в данном прбежутке.
  */
  if ((x > -1 && x < 1) || (s21_fabs((double)s21_fabs(x) - 1) < 1e-60))
    is_valid = 1;

  /*
      Самое важное проверить область значние.
      Остальная валидация на +-NAN, +-INF и +-1
      пройдут в функции s21_asin.
  */
  if (is_valid)
    //Основная формула расчета: acos = pi/2 - asin(x)
    result = S21_M_PI_2 - s21_asin(x);
  else
    // define NAN возвращается отрицательным, поэтому юзаем fabs
    result = s21_fabs(S21_NAN);

  return (double)result;
}