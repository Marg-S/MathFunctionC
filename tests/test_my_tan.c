#include "my_tests.h"

START_TEST(test_tan_1) {
  double x = 0.234;

  long double my_result = my_tan(x);
  long double system_result = tan(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_tan_2) {
  double x = -0.234;

  long double my_result = my_tan(x);
  long double system_result = tan(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_tan_3) {
  double x = 0;

  long double my_result = my_tan(x);
  long double system_result = tan(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_tan_4) {
  double x = 987654321.1234;

  long double my_result = my_tan(x);
  long double system_result = tan(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_tan_5) {
  double x = -987654321.1234;

  long double my_result = my_tan(x);
  long double system_result = tan(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_tan_6) {
  double x = 0.12345678901234567890;

  long double my_result = my_tan(x);
  long double system_result = tan(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_tan_7) {
  double x = 1.000001;

  long double my_result = my_tan(x);
  long double system_result = tan(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_tan_8) {
  double x = -11111.000001;

  long double my_result = my_tan(x);
  long double system_result = tan(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_tan_9) {
  double x = M_PI;

  long double my_result = my_tan(x);
  long double system_result = tan(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_tan_10) {
  double x = 1;

  long double my_result = my_tan(x);
  long double system_result = tan(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

START_TEST(test_tan_11) {
  double x = -1;

  long double my_result = my_tan(x);
  long double system_result = tan(x);

  ck_assert_ldouble_eq_tol(system_result, my_result, my_EPSILON);
}
END_TEST

Suite* suite_tan(void) {
  Suite* suite = suite_create("my_tan");
  TCase* tc_my_tan;

  tc_my_tan = tcase_create("tc_my_tan");
  tcase_add_test(tc_my_tan, test_tan_1);
  tcase_add_test(tc_my_tan, test_tan_2);
  tcase_add_test(tc_my_tan, test_tan_3);
  tcase_add_test(tc_my_tan, test_tan_4);
  tcase_add_test(tc_my_tan, test_tan_5);
  tcase_add_test(tc_my_tan, test_tan_6);
  tcase_add_test(tc_my_tan, test_tan_7);
  tcase_add_test(tc_my_tan, test_tan_8);
  tcase_add_test(tc_my_tan, test_tan_9);
  tcase_add_test(tc_my_tan, test_tan_10);
  tcase_add_test(tc_my_tan, test_tan_11);

  suite_add_tcase(suite, tc_my_tan);

  return suite;
}