#ifndef S21_MATH_TEST_H
#define S21_MATH_TEST_H

#include "../s21_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <check.h>

Suite *suite_abs(void);
Suite *suite_acos(void);
Suite *suite_asin(void);
Suite *suite_atan(void);
Suite *suite_ceil(void);

void run_test(void);
void run_testcase(Suite *testcase);

#endif