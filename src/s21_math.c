#include "s21_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double arg1 = 0;
  double arg2 = 0;
  int n = 1;
  if (argc - 1 == 2) {
    sscanf(argv[1], "%lf", &arg1);
    sscanf(argv[2], "%lf", &arg2);

    /*
      ! При значение аргумента pi/2 функции tan and sin
      ! Выдают ошибочные значения
    */
    // arg1 = S21_M_PI_2;

    // abs
    printf("\n%d. ", n++);
    printf("s21_abs(%lf) = %d\n", arg1, s21_abs((int)arg1));
    printf("       abs(%lf) = %d\n", arg1, abs((int)arg1));

    // acos
    printf("\n%d. ", n++);
    printf("s21_acos(%lf) = %.25Lf\n", arg1, s21_acos(arg1));
    printf("       acos(%lf) = %.25lf\n", arg1, acos(arg1));

    // asin
    printf("\n%d. ", n++);
    printf("s21_asin(%lf) = %.25Lf\n", arg1, s21_asin(arg1));
    printf("       asin(%lf) = %.25lf\n", arg1, asin(arg1));

    // atan
    printf("\n%d. ", n++);
    printf("s21_atan(%lf) = %.25Lf\n", arg1, s21_atan(arg1));
    printf("       atan(%lf) = %.25lf\n", arg1, atan(arg1));

    // ceil
    printf("\n%d. ", n++);
    printf("s21_ceil(%lf) = %.25Lf\n", arg1, s21_ceil(arg1));
    printf("       ceil(%lf) = %.25f\n", arg1, ceil(arg1));

    // cos
    printf("\n%d. ", n++);
    printf("s21_cos(%lf) = %.25Lf\n", arg1, s21_cos(arg1));
    printf("       cos(%lf) = %.25lf\n", arg1, cos(arg1));

    // exp
    printf("\n%d. ", n++);
    printf("s21_exp(%lf) = %.25Lf\n", arg1, s21_exp(arg2));
    printf("       exp(%lf) = %.25lf\n", arg1, exp(arg2));

    // fabs
    printf("\n%d. ", n++);
    printf("s21_fabs(%lf) = %.25Lf\n", arg1, s21_fabs(arg1));
    printf("       fabs(%lf) = %.25lf\n", arg1, fabs(arg1));

    // floor
    printf("\n%d. ", n++);
    printf("s21_floor(%lf) = %.25Lf\n", arg1, s21_floor(arg1));
    printf("       floor(%lf) = %.25lf\n", arg1, floor(arg1));

    // fmod
    printf("\n%d. ", n++);
    printf("s21_fmod(%lf, %lf) = %.25Lf\n", arg1, arg2, s21_fmod(arg1, arg2));
    printf("        fmod(%lf, %lf) = %.25f\n", arg1, arg2, fmod(arg1, arg2));

    // log
    printf("\n%d. ", n++);
    printf("s21_log(%lf) = %.25Lf\n", arg1, s21_log(arg1));
    printf("        log(%lf) = %.25lf\n", arg1, log(arg1));

    // pow
    printf("\n%d. ", n++);
    printf("s21_pow(%lf, %lf) = %.25Lf\n", arg1, arg2, s21_pow(arg1, arg2));
    printf("        pow(%lf, %lf) = %.25f\n", arg1, arg2, pow(arg1, arg2));

    // sin
    printf("\n%d. ", n++);
    printf("s21_sin(%lf) = %.25Lf\n", arg1, s21_sin(arg1));
    printf("        sin(%lf) = %.25lf\n", arg1, sin(arg1));

    // sqrt
    printf("\n%d. ", n++);
    printf("s21_sqrt(%lf) = %.25Lf\n", arg1, s21_sqrt(arg1));
    printf("        sqrt(%lf) = %.25lf\n", arg1, sqrt(arg1));

    // tan
    printf("\n%d. ", n++);
    printf("s21_tan(%lf) = %.25Lf\n", arg1, s21_tan(arg1));
    printf("        tan(%lf) = %.25lf\n", arg1, tan(arg1));

  } else {
    printf("No arguments. Exit.\n");
  }
  return 0;
}