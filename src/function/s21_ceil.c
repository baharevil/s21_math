#include "../s21_math.h"

long double s21_ceil(double x) {
    double mod = (double)s21_fmod(x, 1.0), result = x - mod;

    if ((s21_fabs((double)mod) > 0) && x > 0) 
        result++;

    return result;
}