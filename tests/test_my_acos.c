#include "my_tests.h"

START_TEST(test_acos_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(my_acos(x), acos(x), my_EPSILON);
}
END_TEST

START_TEST(test_acos_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(my_acos(x), acos(x), my_EPSILON);
}
END_TEST

START_TEST(test_acos_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(my_acos(x), acos(x), my_EPSILON);
}
END_TEST

START_TEST(test_acos_4) {
  double x = 99999999999;
  ck_assert_ldouble_nan(my_acos(x));
  ck_assert_ldouble_nan(acos(x));
}
END_TEST

START_TEST(test_acos_5) {
  double x = -99999999999;
  ck_assert_ldouble_nan(my_acos(x));
  ck_assert_ldouble_nan(acos(x));
}
END_TEST

START_TEST(test_acos_6) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(my_acos(x), acos(x), my_EPSILON);
}
END_TEST

START_TEST(test_acos_7) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(my_acos(x), acos(x), my_EPSILON);
}
END_TEST

START_TEST(test_acos_9) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq_tol(my_acos(x), acos(x), my_EPSILON);
}
END_TEST

START_TEST(test_acos_10) {
  double x = NAN;
  ck_assert_ldouble_nan(my_acos(x));
  ck_assert_ldouble_nan(acos(x));
}
END_TEST

START_TEST(test_acos_11) {
  double x = INFINITY;
  ck_assert_ldouble_nan(my_acos(x));
  ck_assert_ldouble_nan(acos(x));
}
END_TEST

START_TEST(test_acos_12) {
  double x = -INFINITY;
  ck_assert_ldouble_nan(my_acos(x));
  ck_assert_ldouble_nan(acos(x));
}
END_TEST

START_TEST(test_acos_13) {
  double x = 0.234;

  long double my_result = my_acos(x);
  long double system_result = acos(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_acos_14) {
  double x = -0.234;

  long double my_result = my_acos(x);
  long double system_result = acos(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_acos_15) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(my_acos(x), acos(x), my_EPSILON);
}
END_TEST

Suite *suite_acos(void) {
  Suite *suite = suite_create("my_acos_suite");
  TCase *tc_my_acos;

  tc_my_acos = tcase_create("tc_my_acos");
  tcase_add_test(tc_my_acos, test_acos_1);
  tcase_add_test(tc_my_acos, test_acos_2);
  tcase_add_test(tc_my_acos, test_acos_3);
  tcase_add_test(tc_my_acos, test_acos_4);
  tcase_add_test(tc_my_acos, test_acos_5);
  tcase_add_test(tc_my_acos, test_acos_6);
  tcase_add_test(tc_my_acos, test_acos_7);
  tcase_add_test(tc_my_acos, test_acos_9);
  tcase_add_test(tc_my_acos, test_acos_10);
  tcase_add_test(tc_my_acos, test_acos_11);
  tcase_add_test(tc_my_acos, test_acos_12);
  tcase_add_test(tc_my_acos, test_acos_13);
  tcase_add_test(tc_my_acos, test_acos_14);
  tcase_add_test(tc_my_acos, test_acos_15);

  suite_add_tcase(suite, tc_my_acos);

  return suite;
}