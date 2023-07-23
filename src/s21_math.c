#include "s21_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double arg1 = 0;
  double arg2 = 0;
  if (argc - 1 == 2) {
    sscanf(argv[1], "%lf", &arg1);
    sscanf(argv[2], "%lf", &arg2);
    /*
      ! При значение аргумента pi/2 функции tan and sin
      ! Выдают ошибочные значения
    */
    // arg1 = S21_M_PI_2;

    // printf("\ns21_cos(%lf) = %.25Lf\n", arg1, s21_cos(arg1));
    // printf("    cos(%lf) = %.25lf\n", arg1, cos(arg1));
    // printf("\ns21_sin(%lf) = %.25Lf\n", arg1, s21_sin(arg1));
    // printf("    sin(%lf) = %.25lf\n", arg1, sin(arg1));
    // printf("\ns21_tan(%lf) = %.25Lf\n", arg1, s21_tan(arg1));
    // printf("    tan(%lf) = %.25lf\n", arg1, tan(arg1));
    // printf("\ns21_log(%lf) = %.25Lf\n", arg1, s21_log(arg1));
    // printf("    log(%lf) = %.25lf\n", arg1, log(arg1));
    // printf("\ns21_fmod(%lf, %lf) = %.25Lf\n", arg1, arg2, s21_fmod(arg1,
    // arg2)); printf("    fmod(%lf, %lf) = %.25f\n", arg1, arg2, fmod(arg1,
    // arg2)); printf("\ns21_pow(%lf, %lf) = %.25Lf\n", arg1, arg2,
    // s21_pow(arg1, arg2)); printf("    pow(%lf, %lf) = %.25f\n", arg1, arg2,
    // pow(arg1, arg2));

    printf("\ns21_atan(%lf) = %.25Lf\n", arg1, s21_atan(arg1));
    printf("    atan(%lf) = %.25lf\n", arg1, atan(arg1));
    printf("\ns21_asin(%lf) = %.25Lf\n", arg1, s21_asin(arg1));
    printf("    asin(%lf) = %.25lf\n", arg1, asin(arg1));
    printf("\ns21_acos(%lf) = %.25Lf\n", arg1, s21_acos(arg1));
    printf("    acos(%lf) = %.25lf\n", arg1, acos(arg1));

  } else {
    printf("No arguments. Exit.\n");
  }
  return 0;
}