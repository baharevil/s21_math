#include "../s21_math.h"

long double s21_cos(double x) {
    long double result = 1, prev_result = 0, temp = 1, epsilon = 1e-20, n = 1;
    union ieee754_double copy_x, x754_full = {0};

    // Создаем копию преходящего аргумента
    copy_x.d = x;

    // (1 << 11) - 1 = 2047
    x754_full.ieee.exponent = (1 << 11) - 1;

    // Проверка на +-NaN
    if ((copy_x.ieee_nan.exponent == x754_full.ieee.exponent) &&
        (copy_x.ieee_nan.quiet_nan))
        result = x;

    // В люом другом случае х число
    else {
        // Метод подсчета: разложение в ряд Тейлора
        long double square_x = s21_pow((double)s21_fmod(x, 2.0 * S21_M_PI), 2);

        while (s21_fabs((double)(result - prev_result)) > epsilon) {
            prev_result = result;
            temp *= -1.0 * square_x / (n * (n + 1));
            result += temp;
            n += 2;
        }
    }

    return (double)result;
}