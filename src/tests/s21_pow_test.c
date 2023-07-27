#include "s21_math_test.h"

#define TEST_EPS 1e-6l

START_TEST(pow_test1) {
  double x = 1.0;
  double y = 0.5;
  ck_assert_ldouble_eq_tol(s21_pow(x,y), pow(x,y), 6);
}
END_TEST

START_TEST(pow_test2) {
  double x = -1.0;
  double y = -0.5;
  long double orig = pow(x,y);
  long double mmyy = s21_pow(x,y);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

// START_TEST(pow_test3) {
//   double x = S21_INF;
//   double y = 56;
//   ck_assert_ldouble_nan(s21_pow(x,y));
//   ck_assert_ldouble_nan(pow(x,y));
// }
// END_TEST

// START_TEST(pow_test4) {
//   double x = -S21_INF;
//   double y = -56;
//   ck_assert_ldouble_nan(s21_pow(x,y));
//   ck_assert_ldouble_nan(pow(x,y));
// }
// END_TEST

// START_TEST(pow_test6) {
//   double x = S21_NAN;
//   double y = 7;
//   ck_assert_ldouble_nan(s21_pow(x, y));
// }
// END_TEST

START_TEST(pow_test7) {
  double x = 4.7;
  double y = 3.9;
  ck_assert_ldouble_eq_tol(s21_pow(x,y), pow(x,y), 6);
}
END_TEST

START_TEST(pow_test8) {
  double x = 4.7323234567890765;
  double y = 3.9567832323490765;
  ck_assert_ldouble_eq_tol(s21_pow(x,y), pow(x,y), 6);
}
END_TEST

// START_TEST(pow_test9) {
//   double x = 4732323456789076.5;
//   double y = 3956783232349076.5;
//   ck_assert_ldouble_eq(s21_pow(x,y), pow(x,y));
// }
// END_TEST

START_TEST(pow_test10) {
  double x = -4.7323234567890765;
  double y = -3.9567832323490765;
  long double orig = pow(x,y);
  long double mmyy = s21_pow(x,y);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

// START_TEST(test_x_inf_y_zero1) {
//   double x = -8743517471375471154.34143134134134;
//   double y = -8743547115417471375.13413434143134;
//   ck_assert_ldouble_eq(s21_pow(x,y), pow(x,y));
// }

START_TEST(test_neg) { ck_assert_ldouble_eq(pow(-1234, 4), s21_pow(-1234,4)); }
END_TEST

START_TEST(test_pos) { ck_assert_ldouble_eq(pow(1234, 4), s21_pow(1234,4)); }
END_TEST

START_TEST(test_pos_1) { ck_assert_ldouble_eq(pow(4, 2), s21_pow(4,2)); }
END_TEST

// START_TEST(test_dbl_min) {
//   double num = DBL_MIN*2;
//   double orig = pow(num, DBL_MIN);
//   double mmyy = (double)s21_pow(num, DBL_MIN);
//   ck_assert_ldouble_eq(orig, mmyy);
// }
// END_TEST

// START_TEST(test_dbl_max) {
//   double orig = pow(DBL_MAX*2, DBL_MAX);
//   double mmyy = (double)s21_pow(DBL_MAX*2, DBL_MAX);
//   ck_assert_ldouble_nan(orig);
//   ck_assert_ldouble_nan(mmyy);
// }
// END_TEST

Suite *suite_pow(void) {
  Suite *s = suite_create("suite_pow");
  TCase *tc = tcase_create("pow_tc");

  tcase_add_test(tc, pow_test1);
  tcase_add_test(tc, pow_test2);
  // tcase_add_test(tc, pow_test3);
  // tcase_add_test(tc, pow_test4);
  // tcase_add_test(tc, pow_test6);
  tcase_add_test(tc, pow_test7);
  tcase_add_test(tc, pow_test8);
  // tcase_add_test(tc, pow_test9);
  tcase_add_test(tc, pow_test10);
  // tcase_add_test(tc, test_x_inf_y_zero);
  // tcase_add_test(tc, test_x_inf_y_zero1);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, test_pos_1);
  // tcase_add_test(tc, test_dbl_min);
  // tcase_add_test(tc, test_dbl_max);
  suite_add_tcase(s, tc);
  return s;
}