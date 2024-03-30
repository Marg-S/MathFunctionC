#include "my_tests.h"

START_TEST(test_atan_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

START_TEST(test_atan_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

START_TEST(test_atan_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

START_TEST(test_atan_4) {
  double x = 999999999999;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

START_TEST(test_atan_5) {
  double x = -999999999999;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

START_TEST(test_atan_6) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

START_TEST(test_atan_7) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

START_TEST(test_atan_8) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

START_TEST(test_atan_9) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

START_TEST(test_atan_10) {
  double x = NAN;
  ck_assert_ldouble_nan(my_atan(x));
  ck_assert_ldouble_nan(atan(x));
}
END_TEST

START_TEST(test_atan_11) {
  double x = INFINITY;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

START_TEST(test_atan_12) {
  double x = -INFINITY;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

START_TEST(test_atan_13) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(my_atan(x), atan(x), my_EPSILON);
}
END_TEST

Suite* suite_atan(void) {
  Suite* suite = suite_create("my_atan");
  TCase* tc_my_atan;

  tc_my_atan = tcase_create("tc_my_atan");
  tcase_add_test(tc_my_atan, test_atan_1);
  tcase_add_test(tc_my_atan, test_atan_2);
  tcase_add_test(tc_my_atan, test_atan_3);
  tcase_add_test(tc_my_atan, test_atan_4);
  tcase_add_test(tc_my_atan, test_atan_5);
  tcase_add_test(tc_my_atan, test_atan_6);
  tcase_add_test(tc_my_atan, test_atan_7);
  tcase_add_test(tc_my_atan, test_atan_8);
  tcase_add_test(tc_my_atan, test_atan_9);
  tcase_add_test(tc_my_atan, test_atan_10);
  tcase_add_test(tc_my_atan, test_atan_11);
  tcase_add_test(tc_my_atan, test_atan_12);
  tcase_add_test(tc_my_atan, test_atan_13);

  suite_add_tcase(suite, tc_my_atan);

  return suite;
}