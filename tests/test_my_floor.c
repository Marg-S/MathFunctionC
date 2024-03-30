#include "my_tests.h"

START_TEST(test_floor_1) {
  double x = 1.2345678;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_2) {
  double x = -1.2345678;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_3) {
  double x = 987654321.01234567;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_4) {
  double x = -987654321.01234567;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_5) {
  double x = 0;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_6) {
  double x = -0;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_7) {
  double x = 1234567;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_8) {
  double x = -1234567;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_9) {
  double x = 0.1234567;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_10) {
  double x = -0.1234567;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_11) {
  double x = DBL_MAX;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_12) {
  double x = DBL_MIN;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_13) {
  double x = 9999999999999.999;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_14) {
  double x = -9999999999999.999;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_floor_15) {
  double x = -INFINITY;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq(system_result, my_result);
}
END_TEST

START_TEST(test_floor_16) {
  double x = NAN;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_nan(system_result);
  ck_assert_ldouble_nan(my_result);
}
END_TEST

START_TEST(test_floor_17) {
  double x = DBL_MAX / 9;

  long double my_result = my_floor(x);
  long double system_result = floor(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

Suite* suite_floor(void) {
  Suite* suite = suite_create("my_floor");
  TCase* tc_my_floor;

  tc_my_floor = tcase_create("tc_my_floor");
  tcase_add_test(tc_my_floor, test_floor_1);
  tcase_add_test(tc_my_floor, test_floor_2);
  tcase_add_test(tc_my_floor, test_floor_3);
  tcase_add_test(tc_my_floor, test_floor_4);
  tcase_add_test(tc_my_floor, test_floor_5);
  tcase_add_test(tc_my_floor, test_floor_6);
  tcase_add_test(tc_my_floor, test_floor_7);
  tcase_add_test(tc_my_floor, test_floor_8);
  tcase_add_test(tc_my_floor, test_floor_9);
  tcase_add_test(tc_my_floor, test_floor_10);
  tcase_add_test(tc_my_floor, test_floor_11);
  tcase_add_test(tc_my_floor, test_floor_12);
  tcase_add_test(tc_my_floor, test_floor_13);
  tcase_add_test(tc_my_floor, test_floor_14);
  tcase_add_test(tc_my_floor, test_floor_15);
  tcase_add_test(tc_my_floor, test_floor_16);
  tcase_add_test(tc_my_floor, test_floor_17);

  suite_add_tcase(suite, tc_my_floor);

  return suite;
}