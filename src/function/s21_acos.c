#include "../s21_math.h"

long double s21_acos(double x) {
  long double result = 0;

  /*
    Область значения косинуса находять на промежутке от -1 до 1 включительно,
    поэтому х должен быть в данном прбежутке.

    Самое важное проверить область значние.
    Остальная валидация на +-NAN, +-INF и +-1
    пройдут в функции s21_asin.
  */
  if ((x > -1 && x < 1) || (s21_fabs((double)s21_fabs(x) - 1) < 1e-60))
    //Основная формула расчета: acos = pi/2 - atan(x / sqrt(1 - x^2))
    result = S21_M_PI_2 -
             s21_atan(x / (double)s21_sqrt(1.0 - (double)s21_pow(x, 2)));
  else
    // define NAN возвращается отрицательным, поэтому юзаем fabs
    result = s21_fabs(S21_NAN);

  return (double)result;
}