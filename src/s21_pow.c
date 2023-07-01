#include "s21_math.h"
#include <stdio.h>

long double s21_pow(double base, double pow) {
    long double result = base, prev_pow = 0;//, epsilon = 1e-20;
    int n = 1;
    while (pow - prev_pow > 1.0) {
        result = result * base;
        prev_pow = n++;
    }
    // while (pow - prev_pow > epsilon) {
    //     result = result * (base * epsilon);
    //     prev_pow = prev_pow + epsilon;
    // }
    return (double)result;
}
