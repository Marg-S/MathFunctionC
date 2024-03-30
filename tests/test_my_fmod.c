#include "my_tests.h"

START_TEST(test_fmod_1) {
  double x = 1;
  double y = 1;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), my_EPSILON);
}
END_TEST

START_TEST(test_fmod_2) {
  double x = -1;
  double y = -1;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), my_EPSILON);
}
END_TEST

START_TEST(test_fmod_3) {
  double x = 0;
  double y = 0;
  ck_assert_ldouble_nan(my_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(test_fmod_4) {
  double x = 999999999999;
  double y = 9;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), my_EPSILON);
}
END_TEST

START_TEST(test_fmod_5) {
  double x = -999999999999;
  double y = 9;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), my_EPSILON);
}
END_TEST

START_TEST(test_fmod_6) {
  double x = 1e-9;
  double y = 9;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), my_EPSILON);
}
END_TEST

START_TEST(test_fmod_7) {
  double x = -1e-9;
  double y = 9;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), my_EPSILON);
}
END_TEST

START_TEST(test_fmod_9) {
  double x = DBL_MIN;
  double y = 9;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), my_EPSILON);
}
END_TEST

START_TEST(test_fmod_10) {
  double x = NAN;
  double y = 9;
  ck_assert_ldouble_nan(my_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(test_fmod_11) {
  double x = INFINITY;
  double y = 9;
  ck_assert_ldouble_nan(my_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(test_fmod_12) {
  double x = INT_MAX;
  double y = 9;
  ck_assert_ldouble_eq_tol(my_fmod(x, y), fmod(x, y), my_EPSILON);
}
END_TEST

START_TEST(test_fmod_13) {
  double x = 9999999999;
  double y = 0;
  ck_assert_ldouble_nan(my_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

Suite* suite_fmod(void) {
  Suite* suite = suite_create("my_fmod");
  TCase* tc_my_fmod;

  tc_my_fmod = tcase_create("tc_my_fmod");
  tcase_add_test(tc_my_fmod, test_fmod_1);
  tcase_add_test(tc_my_fmod, test_fmod_2);
  tcase_add_test(tc_my_fmod, test_fmod_3);
  tcase_add_test(tc_my_fmod, test_fmod_4);
  tcase_add_test(tc_my_fmod, test_fmod_5);
  tcase_add_test(tc_my_fmod, test_fmod_6);
  tcase_add_test(tc_my_fmod, test_fmod_7);
  tcase_add_test(tc_my_fmod, test_fmod_9);
  tcase_add_test(tc_my_fmod, test_fmod_10);
  tcase_add_test(tc_my_fmod, test_fmod_11);
  tcase_add_test(tc_my_fmod, test_fmod_12);
  tcase_add_test(tc_my_fmod, test_fmod_13);

  suite_add_tcase(suite, tc_my_fmod);

  return suite;
}