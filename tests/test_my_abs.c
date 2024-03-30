#include "my_tests.h"

START_TEST(test_abs_1) {
  int num = -10;

  int my_result = my_abs(num);
  int system_result = abs(num);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_abs_2) {
  int num = 10;

  int my_result = my_abs(num);
  int system_result = abs(num);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_abs_3) {
  int num = -2147483647;

  int my_result = my_abs(num);
  int system_result = abs(num);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_abs_4) {
  int num = -0;

  int my_result = my_abs(num);
  int system_result = abs(num);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_abs_5) {
  int num = -0xAB11;

  int my_result = my_abs(num);
  int system_result = abs(num);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_abs_6) {
  int num = 0;

  int my_result = my_abs(num);
  int system_result = abs(num);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_abs_7) {
  int num = -000000000234;

  int my_result = my_abs(num);
  int system_result = abs(num);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

Suite* suite_abs(void) {
  Suite* suite = suite_create("my_abs");
  TCase* tc_my_abs;

  tc_my_abs = tcase_create("tc_my_abs");
  tcase_add_test(tc_my_abs, test_abs_1);
  tcase_add_test(tc_my_abs, test_abs_2);
  tcase_add_test(tc_my_abs, test_abs_3);
  tcase_add_test(tc_my_abs, test_abs_4);
  tcase_add_test(tc_my_abs, test_abs_5);
  tcase_add_test(tc_my_abs, test_abs_6);
  tcase_add_test(tc_my_abs, test_abs_7);
  // tcase_add_test(tc_my_abs, test_abs_8);
  // tcase_add_test(tc_my_abs, test_abs_9);
  // tcase_add_test(tc_my_abs, test_abs_10);
  // tcase_add_test(tc_my_abs, test_abs_11);
  // tcase_add_test(tc_my_abs, test_abs_12);

  suite_add_tcase(suite, tc_my_abs);

  return suite;
}