#include "s21_math.h"

long double s21_log(double x) {
    long double result = 1/x, prev_result = 0, epsilon = 1e-20;
    while (result - prev_result > epsilon) {
        prev_result = result;
        result = prev_result + (long double)2 * ((x - s21_exp((double)prev_result)) / (x + s21_exp((double)prev_result)));
    }
    return (double)result;
}