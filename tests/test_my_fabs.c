#include "my_tests.h"

START_TEST(test_fabs_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(my_fabs(x), fabs(x), my_EPSILON);
}
END_TEST

START_TEST(test_fabs_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(my_fabs(x), fabs(x), my_EPSILON);
}
END_TEST

START_TEST(test_fabs_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(my_fabs(x), fabs(x), my_EPSILON);
}
END_TEST

START_TEST(test_fabs_4) {
  double x = 999999999999;
  ck_assert_ldouble_eq_tol(my_fabs(x), fabs(x), my_EPSILON);
}
END_TEST

START_TEST(test_fabs_5) {
  double x = -999999999999;
  ck_assert_ldouble_eq_tol(my_fabs(x), fabs(x), my_EPSILON);
}
END_TEST

START_TEST(test_fabs_6) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(my_fabs(x), fabs(x), my_EPSILON);
}
END_TEST

START_TEST(test_fabs_7) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(my_fabs(x), fabs(x), my_EPSILON);
}
END_TEST

START_TEST(test_fabs_8) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq_tol(my_fabs(x), fabs(x), my_EPSILON);
}
END_TEST

START_TEST(test_fabs_9) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq_tol(my_fabs(x), fabs(x), my_EPSILON);
}
END_TEST

START_TEST(test_fabs_10) {
  double x = NAN;
  ck_assert_ldouble_nan(my_fabs(x));
  ck_assert_ldouble_nan(fabs(x));
}
END_TEST

START_TEST(test_fabs_11) {
  double x = INFINITY;
  ck_assert_ldouble_infinite(my_fabs(x));
  ck_assert_ldouble_infinite(fabs(x));
}
END_TEST

Suite* suite_fabs(void) {
  Suite* suite = suite_create("my_fabs");
  TCase* tc_my_fabs;

  tc_my_fabs = tcase_create("tc_my_fabs");
  tcase_add_test(tc_my_fabs, test_fabs_1);
  tcase_add_test(tc_my_fabs, test_fabs_2);
  tcase_add_test(tc_my_fabs, test_fabs_3);
  tcase_add_test(tc_my_fabs, test_fabs_4);
  tcase_add_test(tc_my_fabs, test_fabs_5);
  tcase_add_test(tc_my_fabs, test_fabs_6);
  tcase_add_test(tc_my_fabs, test_fabs_7);
  tcase_add_test(tc_my_fabs, test_fabs_8);
  tcase_add_test(tc_my_fabs, test_fabs_9);
  tcase_add_test(tc_my_fabs, test_fabs_10);
  tcase_add_test(tc_my_fabs, test_fabs_11);

  suite_add_tcase(suite, tc_my_fabs);

  return suite;
}