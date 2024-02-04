#include "s21_ieee754.h"
#include "s21_math.h"

long double s21_pow(double base, double exp) {
  double result = 1, mod_exp = (double)s21_fabs((double)s21_fmod(exp, 1.0));
  union ieee754_double copy_base, copy_exp, x754_full = {0};

  // Создаем копии преходящих аргументов
  copy_base.d = base;
  copy_exp.d = (double)s21_fabs(exp);

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Проверка на 1 как в pow так и в base
  if ((s21_fabs(copy_exp.d - 1.0) < S21_MIN_VAL) ||
      (base > 0 && s21_fabs(copy_base.d - 1.0) < S21_MIN_VAL)) {
    if (exp > 0)
      result = base;
    else
      result = 1 / base;
  }

  // Проверка на 0 в exp
  else if (s21_fabs((double)(copy_exp.d - 0)) < S21_MIN_VAL)
    result = 1;

  // Проверка на base = +-nan
  else if ((copy_base.ieee.exponent == x754_full.ieee.exponent) &&
           (copy_base.ieee_nan.quiet_nan))
    result = base;

  // Проверка на exp = +-nan
  else if ((copy_exp.ieee.exponent == x754_full.ieee.exponent) &&
           (copy_exp.ieee_nan.quiet_nan))
    result = exp;

  // Проверка на base = +-inf
  else if ((copy_base.ieee.exponent == x754_full.ieee.exponent) &&
           (copy_base.ieee.mantissa0 == 0)) {
    if (exp > 0)
      result = base;
    else
      result = 0;
  }

  // Проверка на exp = +-inf
  else if ((copy_exp.ieee.exponent == x754_full.ieee.exponent) &&
           (copy_exp.ieee.mantissa0 == 0)) {
    // Если base = -1
    if (s21_fabs((double)(copy_base.d + 1)) < S21_MIN_VAL)
      result = 1.0;
    else if ((exp < 0 && s21_fabs(base) > 1) || (exp > 0 && s21_fabs(base) < 1))
      result = 0.0;
    else
      result = S21_INF;
  }

  // Проверка на случай если base < 0 и exp не целое число
  else if ((base < 0) && (mod_exp > 0))
    result = -S21_NAN;

  /*
    После всех валидаций, производиться подсчет результата.
    Метод расчета: "Быстрое возведение" целой части exp +
    + домножение на e^(exp * log(base)) дроб. части exp.
  */
  else {
    // Получаем целую часть числа
    unsigned long long int exp_round = (unsigned long long int)copy_exp.d;

    // Проверяем, равняется ли целая часть 0
    unsigned short int stop = (exp_round == 0);

    /*
      Далее в зависимости от проверки, есть 2 случая:
        1. Если целая часть равна 0, то result остается равен 1, а exp_ask = 0.
        2. Если целая часть не равна 0, то инициализируемся для геом.прогрессии.
      Геом. прогрессию начинаем со второй степени (т.е. base ^ 2).
    */
    unsigned long long int exp_ask = 2 * !stop;
    result = (copy_base.d * copy_base.d) * !stop + stop;

    /*Временные переменные для оптимизации счета*/
    double result_temp = 0;
    unsigned long long int exp_temp = 0;

    /*
      Далее производим быстрое приближение к итоговому результату
      циклами while. Методы расчета, в каждом из циклов while,
      описаны ниже.

      В каждом из циклов while проверяем условия остановки, которое
      сигнализирует о том, что мы приближаемся к inf
      (с точки зрения того, что мы превышаем макс допустимое double'ое
      значение).
    */

    // 1. Домножаемся в геометрической прогрессии
    // (т.е. base ^ exp_ask, где exp_ask будет равна: 2, 4, 8, 16, 32 ...)
    while (!stop && (exp_temp = exp_ask * 2) <= exp_round) {
      result_temp = (double)s21_fabs(result * result);
      stop = (result_temp > S21_DBL_MAX);
      exp_ask = exp_temp;
      result = result_temp;
    }

    // 2. Домножаемся квадратами base
    // (т.е. base ^ exp_ask, где exp_ask будет равна: 32, 34, 36, 38, 40 ...)
    while (!stop && (exp_temp = exp_ask + 2) <= exp_round) {
      result_temp = (double)s21_fabs((result * (copy_base.d * copy_base.d)));
      stop = (result_temp > S21_DBL_MAX);
      exp_ask = exp_temp;
      result = result_temp;
    }

    // 3. Домножаемся просто base
    // (т.е. base ^ exp_ask, где exp_ask будет равна: 40, 41)
    while (!stop && (exp_temp = exp_ask + 1) <= exp_round) {
      result_temp = (double)s21_fabs((result * copy_base.d));
      stop = (result_temp > S21_DBL_MAX);
      exp_ask = exp_temp;
      result = result_temp;
    }

    // В случае если циклы while отрабатывают, и при этом stop == 1,
    // то мы приблизились к бесконечности
    if (exp_ask != 0 && stop) result = S21_INF;

    // Выполняем домножение если существует дробная часть exp
    if (mod_exp > 0)
      result *= (double)s21_exp((mod_exp * (double)s21_log(copy_base.d)));

    // Если степень отрицательная
    if (exp < 0) result = 1 / result;
  }

  return result;
}
