#ifndef MY_MATH
#define MY_MATH

#ifndef my_PI
#define my_PI 3.141592653589793238
#endif  // my_PI

#ifndef my_inf
#define my_inf 1.0 / 0.0
#endif  // my_inf

#ifndef my_inf_minus
#define my_inf_minus 1.0 / -0.0
#endif  // my_inf_minus

#ifndef my_NAN
#define my_NAN 0.0 / 0.0
#endif  // my_NAN

#ifndef my_EPSILON
#define my_EPSILON 1e-6
#endif  // my_EPSILON

#ifndef my_e
#define my_e 2.718281828459045
#endif  // my_e

#ifndef my_ln10
#define my_ln10 2.3025850929940456
#endif  // my_ln10

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_abs(int x);
long double my_acos(double x);
long double my_asin(double x);
long double my_atan(double x);
long double my_ceil(double x);
long double my_cos(double x);
long double my_exp(double x);
long double my_fabs(double x);
long double my_floor(double x);
long double my_fmod(double x, double y);
long double my_log(double x);
long double my_pow(double base, double exp);
long double my_sin(double x);
long double my_sqrt(double x);
long double my_tan(double x);

unsigned long long my_factorial(int n);
int my_is_inf(double x);
int my_is_inf_minus(double x);
int my_is_NAN(double x);
#endif  // MY_MATH
