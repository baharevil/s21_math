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
    printf("    log(%lf) = %.25lf\n", arg2, log(arg2));
    printf("s21_log(%lf) = %.25Lf\n", arg2, s21_log(arg2));
    printf("\n    pow(%lf, %lf) = %.25lf\n", arg1, arg2, pow(arg1, arg2));
    printf("s21_pow(%lf, %lf) = %.25Lf\n", arg1, arg2, s21_pow(arg1, arg2));
    printf("\n    sqrt(%lf) = %.25lf\n", arg1, sqrt(arg1));
    printf("s21_sqrt(%lf) = %.25Lf\n", arg1, s21_sqrt(arg1));
    printf("\n    fmod(%lf, %lf) = %.25lf\n", arg1, arg2, fmod(arg1, arg2));
    printf("s21_fmod(%lf, %lf) = %.25Lf\n", arg1, arg2, s21_fmod(arg1, arg2));
    printf("\n    ceil(%lf) = %.25lf\n", arg1, ceil(arg1));
    printf("s21_ceil(%lf) = %.25Lf\n", arg1, s21_ceil(arg1));
    printf("\n    floor(%lf) = %.25lf\n", arg1, floor(arg1));
    printf("s21_floor(%lf) = %.25Lf\n", arg1, s21_floor(arg1));

    
  } else {
    printf("No arguments. Exit.\n");
  }
  return 0;
}