#include "my_tests.h"

START_TEST(test_exp_1) {
  double x = 1;

  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_exp_2) {
  double x = -1;

  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_exp_3) {
  double x = 0;
  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_exp_4) {
  double x = 999999999999;

  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_infinite(my_result);
  ck_assert_ldouble_infinite(system_result);
}
END_TEST

START_TEST(test_exp_5) {
  double x = -999999999999;

  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_exp_6) {
  double x = DBL_MAX;

  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_infinite(my_result);
  ck_assert_ldouble_infinite(system_result);
}
END_TEST

START_TEST(test_exp_7) {
  double x = DBL_MIN;

  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_exp_8) {
  double x = 1e-9;

  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_exp_9) {
  double x = -1e-9;

  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_exp_10) {
  double x = NAN;

  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_nan(my_result);
  ck_assert_ldouble_nan(system_result);
}
END_TEST

START_TEST(test_exp_11) {
  double x = INFINITY;

  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_infinite(my_result);
  ck_assert_ldouble_infinite(system_result);
}
END_TEST

START_TEST(test_exp_12) {
  double x = -INFINITY;

  long double my_result = my_exp(x);
  long double system_result = exp(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

Suite* suite_exp(void) {
  Suite* suite = suite_create("my_exp");
  TCase* tc_my_exp;

  tc_my_exp = tcase_create("tc_my_exp");
  tcase_add_test(tc_my_exp, test_exp_1);
  tcase_add_test(tc_my_exp, test_exp_2);
  tcase_add_test(tc_my_exp, test_exp_3);
  tcase_add_test(tc_my_exp, test_exp_4);
  tcase_add_test(tc_my_exp, test_exp_5);
  tcase_add_test(tc_my_exp, test_exp_6);
  tcase_add_test(tc_my_exp, test_exp_7);
  tcase_add_test(tc_my_exp, test_exp_8);
  tcase_add_test(tc_my_exp, test_exp_9);
  tcase_add_test(tc_my_exp, test_exp_10);
  tcase_add_test(tc_my_exp, test_exp_11);
  tcase_add_test(tc_my_exp, test_exp_12);

  suite_add_tcase(suite, tc_my_exp);

  return suite;
}