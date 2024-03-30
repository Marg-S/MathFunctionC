#include "my_tests.h"

START_TEST(test_asin_1) {
  double x = 0.234;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_asin_2) {
  double x = -0.234;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_asin_3) {
  double x = 0;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_asin_4) {
  double x = 9;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_nan(system_result);
  ck_assert_ldouble_nan(my_result);
}
END_TEST

START_TEST(test_asin_5) {
  double x = -9;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_nan(system_result);
  ck_assert_ldouble_nan(my_result);
}
END_TEST

START_TEST(test_asin_6) {
  double x = NAN;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_nan(system_result);
  ck_assert_ldouble_nan(my_result);
}
END_TEST

START_TEST(test_asin_7) {
  double x = INFINITY;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_nan(system_result);
  ck_assert_ldouble_nan(my_result);
}
END_TEST

START_TEST(test_asin_8) {
  double x = 0.12345678901234567890;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_asin_9) {
  double x = -0.0;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}

END_TEST

START_TEST(test_asin_10) {
  double x = -INFINITY;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_nan(system_result);
  ck_assert_ldouble_nan(my_result);
}
END_TEST

START_TEST(test_asin_11) {
  double x = 1.00000000000001;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_nan(system_result);
  ck_assert_ldouble_nan(my_result);
}
END_TEST

START_TEST(test_asin_12) {
  double x = -1.00000000000001;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_nan(system_result);
  ck_assert_ldouble_nan(my_result);
}
END_TEST

START_TEST(test_asin_13) {
  double x = 1.0;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_asin_14) {
  double x = -1.0;

  long double my_result = my_asin(x);
  long double system_result = asin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

Suite* suite_asin(void) {
  Suite* suite = suite_create("my_asin");
  TCase* tc_my_asin;

  tc_my_asin = tcase_create("tc_my_asin");
  tcase_add_test(tc_my_asin, test_asin_1);
  tcase_add_test(tc_my_asin, test_asin_2);
  tcase_add_test(tc_my_asin, test_asin_3);
  tcase_add_test(tc_my_asin, test_asin_4);
  tcase_add_test(tc_my_asin, test_asin_5);
  tcase_add_test(tc_my_asin, test_asin_6);
  tcase_add_test(tc_my_asin, test_asin_7);
  tcase_add_test(tc_my_asin, test_asin_8);
  tcase_add_test(tc_my_asin, test_asin_9);
  tcase_add_test(tc_my_asin, test_asin_10);
  tcase_add_test(tc_my_asin, test_asin_11);
  tcase_add_test(tc_my_asin, test_asin_12);
  tcase_add_test(tc_my_asin, test_asin_13);
  tcase_add_test(tc_my_asin, test_asin_14);

  suite_add_tcase(suite, tc_my_asin);

  return suite;
}