#include <stdio.h>
#include <stdlib.h>
#include <ieee754.h>
#include <math.h>
#include "s21_math.h"


int main (int argc, char *argv[]) {
    double arg1 = 0;
    double arg2 = 0;
    if (argc - 1 == 2) {
        sscanf(argv[1], "%lf", &arg1);
        sscanf(argv[2], "%lf", &arg2);
        printf("abs(%0.lf) = %d\n", arg1, abs((int)arg1));
        printf("s21_abs(%0.lf) = %d\n", arg1, s21_abs((int)arg1));
        printf("fabs(%lf) = %.25lf\n", arg1, fabs(arg1));
        printf("s21_fabs(%lf) = %.25Lf\n", arg1, s21_fabs(arg1));
        printf("exp(%lf) = %.25lf\n", arg1, exp(arg1));
        printf("s21_exp(%lf) = %.25Lf\n", arg1, s21_exp(arg1));
        printf("pow(%lf, %lf) = %.25lf\n", arg1, arg2, pow(arg1, arg2));
        printf("s21_pow(%lf, %lf) = %.25Lf\n", arg1, arg2, s21_pow(arg1, arg2));
    } else {
        printf("No arguments. Exit.\n");
    }
    return 0;
}