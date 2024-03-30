#include <stdio.h>

#include "my_tests.h"

START_TEST(test_sqrt_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(my_sqrt(x), sqrt(x), my_EPSILON);
}
END_TEST

START_TEST(test_sqrt_2) {
  double x = -1;
  ck_assert_ldouble_nan(my_sqrt(x));
  ck_assert_ldouble_nan(sqrt(x));
}
END_TEST

START_TEST(test_sqrt_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(my_sqrt(x), sqrt(x), my_EPSILON);
}
END_TEST

START_TEST(test_sqrt_4) {
  double x = 999999999999;
  ck_assert_ldouble_eq_tol(my_sqrt(x), sqrt(x), my_EPSILON);
}
END_TEST

START_TEST(test_sqrt_5) {
  double x = -999999999999;
  ck_assert_ldouble_nan(my_sqrt(x));
  ck_assert_ldouble_nan(sqrt(x));
}
END_TEST

START_TEST(test_sqrt_6) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(my_sqrt(x), sqrt(x), my_EPSILON);
}
END_TEST

START_TEST(test_sqrt_7) {
  double x = -1e-9;
  ck_assert_ldouble_nan(my_sqrt(x));
  ck_assert_ldouble_nan(sqrt(x));
}
END_TEST

START_TEST(test_sqrt_8) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq_tol(my_sqrt(x), sqrt(x), 1e139);
}
END_TEST

START_TEST(test_sqrt_9) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq_tol(my_sqrt(x), sqrt(x), my_EPSILON);
}
END_TEST

START_TEST(test_sqrt_10) {
  double x = NAN;
  ck_assert_ldouble_nan(my_sqrt(x));
  ck_assert_ldouble_nan(sqrt(x));
}
END_TEST

START_TEST(test_sqrt_11) {
  double x = INFINITY;
  ck_assert_ldouble_infinite(my_sqrt(x));
  ck_assert_ldouble_infinite(sqrt(x));
}
END_TEST

Suite* suite_sqrt(void) {
  Suite* suite = suite_create("my_sqrt");
  TCase* tc_my_sqrt;

  tc_my_sqrt = tcase_create("tc_my_sqrt");
  tcase_add_test(tc_my_sqrt, test_sqrt_1);
  tcase_add_test(tc_my_sqrt, test_sqrt_2);
  tcase_add_test(tc_my_sqrt, test_sqrt_3);
  tcase_add_test(tc_my_sqrt, test_sqrt_4);
  tcase_add_test(tc_my_sqrt, test_sqrt_5);
  tcase_add_test(tc_my_sqrt, test_sqrt_6);
  tcase_add_test(tc_my_sqrt, test_sqrt_7);
  tcase_add_test(tc_my_sqrt, test_sqrt_8);
  tcase_add_test(tc_my_sqrt, test_sqrt_9);
  tcase_add_test(tc_my_sqrt, test_sqrt_10);
  tcase_add_test(tc_my_sqrt, test_sqrt_11);

  suite_add_tcase(suite, tc_my_sqrt);

  return suite;
}