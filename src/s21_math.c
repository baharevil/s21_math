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
    printf("\ns21_cos(%lf) = %.25Lf\n", arg1, s21_cos(arg1));
    printf("    cos(%lf) = %.25lf\n", arg1, cos(arg1));
    printf("\ns21_sin(%lf) = %.25Lf\n", arg1, s21_sin(arg1));
    printf("    sin(%lf) = %.25lf\n", arg1, sin(arg1));
    printf("\ns21_tan(%lf) = %.25Lf\n", arg1, s21_tan(arg1));
    printf("    tan(%lf) = %.25lf\n", arg1, tan(arg1));
  } else {
    printf("No arguments. Exit.\n");
  }
  return 0;
}