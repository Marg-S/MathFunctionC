#include "my_tests.h"

START_TEST(test_pow_1) {
  double base = 1;
  double exp = 1;
  ck_assert_ldouble_eq_tol(my_pow(base, exp), pow(base, exp), my_EPSILON);
}
END_TEST

START_TEST(test_pow_2) {
  double base = -1;
  double exp = -1;
  ck_assert_ldouble_eq_tol(my_pow(base, exp), pow(base, exp), my_EPSILON);
}
END_TEST

START_TEST(test_pow_3) {
  double base = 0;
  double exp = 0;
  ck_assert_ldouble_eq_tol(my_pow(base, exp), pow(base, exp), my_EPSILON);
}
END_TEST

START_TEST(test_pow_4) {
  double base = 999999999999;
  double exp = 999999999999;
  ck_assert_ldouble_infinite(my_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(test_pow_5) {
  double base = -999999999999;
  double exp = -999999999999;
  ck_assert_ldouble_eq_tol(my_pow(base, exp), pow(base, exp), my_EPSILON);
}
END_TEST

START_TEST(test_pow_6) {
  double base = 1e-9;
  double exp = 1e-9;
  ck_assert_ldouble_eq_tol(my_pow(base, exp), pow(base, exp), my_EPSILON);
}
END_TEST

START_TEST(test_pow_7) {
  double base = -1e-9;
  double exp = -1e-9;
  ck_assert_ldouble_nan(my_pow(base, exp));
  ck_assert_ldouble_nan(pow(base, exp));
}
END_TEST

START_TEST(test_pow_8) {
  double base = DBL_MAX;
  double exp = 0;
  ck_assert_ldouble_eq_tol(my_pow(base, exp), pow(base, exp), my_EPSILON);
}
END_TEST

START_TEST(test_pow_9) {
  double base = DBL_MIN;
  double exp = 999999999999;
  ck_assert_ldouble_eq_tol(my_pow(base, exp), pow(base, exp), my_EPSILON);
}
END_TEST

START_TEST(test_pow_10) {
  double base = NAN;
  double exp = 999999999999;
  ck_assert_ldouble_nan(my_pow(base, exp));
  ck_assert_ldouble_nan(pow(base, exp));
}
END_TEST

START_TEST(test_pow_11) {
  double base = INFINITY;
  double exp = 0;
  ck_assert_ldouble_eq_tol(my_pow(base, exp), pow(base, exp), my_EPSILON);
}
END_TEST

Suite* suite_pow(void) {
  Suite* suite = suite_create("my_pow");
  TCase* tc_my_pow;

  tc_my_pow = tcase_create("tc_my_pow");
  tcase_add_test(tc_my_pow, test_pow_1);
  tcase_add_test(tc_my_pow, test_pow_2);
  tcase_add_test(tc_my_pow, test_pow_3);
  tcase_add_test(tc_my_pow, test_pow_4);
  tcase_add_test(tc_my_pow, test_pow_5);
  tcase_add_test(tc_my_pow, test_pow_6);
  tcase_add_test(tc_my_pow, test_pow_7);
  tcase_add_test(tc_my_pow, test_pow_8);
  tcase_add_test(tc_my_pow, test_pow_9);
  tcase_add_test(tc_my_pow, test_pow_10);
  tcase_add_test(tc_my_pow, test_pow_11);

  suite_add_tcase(suite, tc_my_pow);

  return suite;
}