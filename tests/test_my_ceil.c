#include "my_tests.h"

START_TEST(test_ceil_1) {
  double x = 2.3456;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_2) {
  double x = -2.3456;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_3) {
  double x = 987654321.01234567;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_4) {
  double x = -987654321.01234567;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_5) {
  double x = 0;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_6) {
  double x = -0;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_7) {
  double x = 1234567;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_8) {
  double x = -1234567;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_9) {
  double x = 0.1234567;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_10) {
  double x = -0.1234567;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_11) {
  double x = DBL_MAX;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_12) {
  double x = DBL_MIN;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_13) {
  double x = 9999999999999.999;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_14) {
  double x = -9999999999999.999;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_ceil_15) {
  double x = INFINITY;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_eq(system_result, my_result);
}
END_TEST

START_TEST(test_ceil_16) {
  double x = NAN;

  long double my_result = my_ceil(x);
  long double system_result = ceil(x);

  ck_assert_ldouble_nan(system_result);
  ck_assert_ldouble_nan(my_result);
}
END_TEST

Suite* suite_ceil(void) {
  Suite* suite = suite_create("my_ceil");
  TCase* tc_my_ceil;

  tc_my_ceil = tcase_create("tc_my_ceil");
  tcase_add_test(tc_my_ceil, test_ceil_1);
  tcase_add_test(tc_my_ceil, test_ceil_2);
  tcase_add_test(tc_my_ceil, test_ceil_3);
  tcase_add_test(tc_my_ceil, test_ceil_4);
  tcase_add_test(tc_my_ceil, test_ceil_5);
  tcase_add_test(tc_my_ceil, test_ceil_6);
  tcase_add_test(tc_my_ceil, test_ceil_7);
  tcase_add_test(tc_my_ceil, test_ceil_8);
  tcase_add_test(tc_my_ceil, test_ceil_9);
  tcase_add_test(tc_my_ceil, test_ceil_10);
  tcase_add_test(tc_my_ceil, test_ceil_11);
  tcase_add_test(tc_my_ceil, test_ceil_12);
  tcase_add_test(tc_my_ceil, test_ceil_13);
  tcase_add_test(tc_my_ceil, test_ceil_14);
  tcase_add_test(tc_my_ceil, test_ceil_15);
  tcase_add_test(tc_my_ceil, test_ceil_16);

  suite_add_tcase(suite, tc_my_ceil);

  return suite;
}