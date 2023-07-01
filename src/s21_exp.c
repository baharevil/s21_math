#include "s21_math.h"

long double s21_exp(double x) {
    long double result = 1, temp = 1, prev_result = 0, epsilon = 1e-20;
    int n = 1;
    if (x == S21_NAN) {
        result = S21_NAN;
    } else if (x == S21_INF) {
        result = S21_INF;
    } else {
        while (s21_fabs(result - prev_result) > epsilon) {
            prev_result = result;
            temp = temp * x / n++;
            result += temp;
        }
    }
    return (double)result;
}
