#include "my_tests.h"

START_TEST(test_cos_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(my_cos(x), cos(x), my_EPSILON);
}
END_TEST

START_TEST(test_cos_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(my_cos(x), cos(x), my_EPSILON);
}
END_TEST

START_TEST(test_cos_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(my_cos(x), cos(x), my_EPSILON);
}
END_TEST

START_TEST(test_cos_4) {
  double x = 99999999;
  ck_assert_ldouble_eq_tol(my_cos(x), cos(x), my_EPSILON);
}
END_TEST

START_TEST(test_cos_5) {
  double x = -999999999;
  ck_assert_ldouble_eq_tol(my_cos(x), cos(x), my_EPSILON);
}
END_TEST

START_TEST(test_cos_6) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(my_cos(x), cos(x), my_EPSILON);
}
END_TEST

START_TEST(test_cos_7) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(my_cos(x), cos(x), my_EPSILON);
}
END_TEST

START_TEST(test_cos_9) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq_tol(my_cos(x), cos(x), my_EPSILON);
}
END_TEST

START_TEST(test_cos_10) {
  double x = NAN;
  ck_assert_ldouble_nan(my_cos(x));
  ck_assert_ldouble_nan(cos(x));
}
END_TEST

START_TEST(test_cos_11) {
  double x = INFINITY;
  ck_assert_ldouble_nan(my_cos(x));
  ck_assert_ldouble_nan(cos(x));
}
END_TEST

Suite* suite_cos(void) {
  Suite* suite = suite_create("my_cos");
  TCase* tc_my_cos;

  tc_my_cos = tcase_create("tc_my_cos");
  tcase_add_test(tc_my_cos, test_cos_1);
  tcase_add_test(tc_my_cos, test_cos_2);
  tcase_add_test(tc_my_cos, test_cos_3);
  tcase_add_test(tc_my_cos, test_cos_4);
  tcase_add_test(tc_my_cos, test_cos_5);
  tcase_add_test(tc_my_cos, test_cos_6);
  tcase_add_test(tc_my_cos, test_cos_7);
  tcase_add_test(tc_my_cos, test_cos_9);
  tcase_add_test(tc_my_cos, test_cos_10);
  tcase_add_test(tc_my_cos, test_cos_11);

  suite_add_tcase(suite, tc_my_cos);

  return suite;
}