#include "../s21_math.h"

long double s21_floor(double x) {
    double mod = (double)s21_fmod(x, 1.0), result = x - mod;

    if ((x < 0) && (s21_fabs(mod) > 0))
        result--;

    return result;
}