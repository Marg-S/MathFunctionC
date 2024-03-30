#include "my_tests.h"

int main(void) {
  int failed = 0;
  Suite *suite[15];
  SRunner *runner;

  suite[0] = suite_abs();
  suite[1] = suite_acos();
  suite[2] = suite_asin();
  suite[3] = suite_atan();
  suite[4] = suite_ceil();
  suite[5] = suite_cos();
  suite[6] = suite_exp();
  suite[7] = suite_fabs();
  suite[8] = suite_floor();
  suite[9] = suite_fmod();
  suite[10] = suite_log();
  suite[11] = suite_pow();
  suite[12] = suite_tan();
  suite[13] = suite_sin();
  suite[14] = suite_sqrt();
  runner = srunner_create(suite[0]);

  srunner_add_suite(runner, suite[1]);
  srunner_add_suite(runner, suite[2]);
  srunner_add_suite(runner, suite[3]);
  srunner_add_suite(runner, suite[4]);
  srunner_add_suite(runner, suite[5]);
  srunner_add_suite(runner, suite[6]);
  srunner_add_suite(runner, suite[7]);
  srunner_add_suite(runner, suite[8]);
  srunner_add_suite(runner, suite[9]);
  srunner_add_suite(runner, suite[10]);
  srunner_add_suite(runner, suite[11]);
  srunner_add_suite(runner, suite[12]);
  srunner_add_suite(runner, suite[13]);
  srunner_add_suite(runner, suite[14]);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}