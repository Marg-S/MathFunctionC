#include "my_math.h"

// Taylor series approximations
long double my_sin(double x) {
  long double result = 0.0;
  if (my_is_inf(x) || my_is_inf_minus(x) || my_is_NAN(x)) {
    result = my_NAN;
  } else {
    x = my_fmod(x, 2 * my_PI);
    double precision = 1e-7;

    double next = x;
    int n = 1;
    int iterations = 2000;
    do {
      result += next;
      next = my_pow(-1, n) * my_pow(x, 2 * n + 1) / my_factorial(2 * n + 1);
      n += 1;
      iterations--;
    } while ((my_fabs(next) >= precision && iterations));
  }

  return result;
}