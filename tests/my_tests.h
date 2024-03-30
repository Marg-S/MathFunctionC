#ifndef MY_TESTS_MATH
#define MY_TESTS_MATH

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#include <check.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "../my_math.h"

Suite *suite_abs(void);
Suite *suite_acos(void);
Suite *suite_asin(void);
Suite *suite_atan(void);
Suite *suite_ceil(void);
Suite *suite_cos(void);
Suite *suite_exp(void);
Suite *suite_fabs(void);
Suite *suite_floor(void);
Suite *suite_fmod(void);
Suite *suite_log(void);
Suite *suite_pow(void);
Suite *suite_tan(void);
Suite *suite_sin(void);
Suite *suite_sqrt(void);

#endif  // MY_TESTS_MATH
