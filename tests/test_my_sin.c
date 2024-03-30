#include "my_tests.h"

START_TEST(test_sin_1) {
  double x = 0.234;

  long double my_result = my_sin(x);
  long double system_result = sin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_sin_2) {
  double x = -0.234;

  long double my_result = my_sin(x);
  long double system_result = sin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_sin_3) {
  double x = 0;

  long double my_result = my_sin(x);
  long double system_result = sin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_sin_4) {
  double x = 987654321;

  long double my_result = my_sin(x);
  long double system_result = sin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_sin_5) {
  double x = -987654321;

  long double my_result = my_sin(x);
  long double system_result = sin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_sin_6) {
  double x = NAN;

  long double my_result = my_sin(x);
  long double system_result = sin(x);

  ck_assert_ldouble_nan(system_result);
  ck_assert_ldouble_nan(my_result);
}
END_TEST

START_TEST(test_sin_7) {
  double x = INFINITY;

  long double my_result = my_sin(x);
  long double system_result = sin(x);

  ck_assert_ldouble_nan(system_result);
  ck_assert_ldouble_nan(my_result);
}
END_TEST

START_TEST(test_sin_8) {
  double x = 0.12345678901234567890;

  long double my_result = my_sin(x);
  long double system_result = sin(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_sin_9) {
  for (int i = 1; i < 1000; i++) {
    long double my_result = my_sin(M_PI / i);
    long double system_result = sin(M_PI / i);

    ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
  }
}

END_TEST

START_TEST(test_sin_10) {
  for (int i = 1; i < 10; i++) {
    long double my_result = my_sin(M_PI * i);
    long double system_result = sin(M_PI * i);

    ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
  }
}
END_TEST

Suite* suite_sin(void) {
  Suite* suite = suite_create("my_sin");
  TCase* tc_my_sin;

  tc_my_sin = tcase_create("tc_my_sin");
  tcase_add_test(tc_my_sin, test_sin_1);
  tcase_add_test(tc_my_sin, test_sin_2);
  tcase_add_test(tc_my_sin, test_sin_3);
  tcase_add_test(tc_my_sin, test_sin_4);
  tcase_add_test(tc_my_sin, test_sin_5);
  tcase_add_test(tc_my_sin, test_sin_6);
  tcase_add_test(tc_my_sin, test_sin_7);
  tcase_add_test(tc_my_sin, test_sin_8);
  tcase_add_test(tc_my_sin, test_sin_9);
  tcase_add_test(tc_my_sin, test_sin_10);

  suite_add_tcase(suite, tc_my_sin);

  return suite;
}