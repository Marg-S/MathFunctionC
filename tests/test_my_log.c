#include "my_tests.h"

START_TEST(test_log_1) {
  double x = 1;

  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_log_2) {
  double x = -1;

  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_nan(my_result);
  ck_assert_ldouble_nan(system_result);
}
END_TEST

START_TEST(test_log_3) {
  double x = 0;
  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_infinite(my_result);
  ck_assert_ldouble_infinite(system_result);
}
END_TEST

START_TEST(test_log_4) {
  double x = 999999999999;

  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_log_5) {
  double x = -999999999999;

  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_nan(my_result);
  ck_assert_ldouble_nan(system_result);
}
END_TEST

START_TEST(test_log_6) {
  double x = DBL_MAX;

  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_log_7) {
  double x = 4.5678;

  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_log_8) {
  double x = 1e-9;

  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_log_9) {
  double x = DBL_MIN;

  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_eq_tol(my_result, system_result, my_EPSILON);
}
END_TEST

START_TEST(test_log_10) {
  double x = NAN;

  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_nan(my_result);
  ck_assert_ldouble_nan(system_result);
}
END_TEST

START_TEST(test_log_11) {
  double x = INFINITY;

  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_infinite(my_result);
  ck_assert_ldouble_infinite(system_result);
}
END_TEST

START_TEST(test_log_12) {
  double x = -INFINITY;

  long double my_result = my_log(x);
  long double system_result = log(x);

  ck_assert_ldouble_nan(my_result);
  ck_assert_ldouble_nan(system_result);
}
END_TEST

Suite* suite_log(void) {
  Suite* suite = suite_create("my_log");
  TCase* tc_my_log;

  tc_my_log = tcase_create("tc_my_log");
  tcase_add_test(tc_my_log, test_log_1);
  tcase_add_test(tc_my_log, test_log_2);
  tcase_add_test(tc_my_log, test_log_3);
  tcase_add_test(tc_my_log, test_log_4);
  tcase_add_test(tc_my_log, test_log_5);
  tcase_add_test(tc_my_log, test_log_6);
  tcase_add_test(tc_my_log, test_log_7);
  tcase_add_test(tc_my_log, test_log_8);
  tcase_add_test(tc_my_log, test_log_9);
  tcase_add_test(tc_my_log, test_log_10);
  tcase_add_test(tc_my_log, test_log_11);
  tcase_add_test(tc_my_log, test_log_12);

  suite_add_tcase(suite, tc_my_log);

  return suite;
}