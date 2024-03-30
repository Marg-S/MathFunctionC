#include "my_math.h"

// Taylor series approximations
long double my_exp(double x) {
  long double result = 1.0;

  if (my_is_inf(x) || my_is_NAN(x)) {
    result = x;
  } else if (my_is_inf_minus(x)) {
    result = 0;
  } else if (x >= 0.0) {
    double precision = 1e-6;
    long double next = 1;
    int n = 1;
    int iterations = 2000;

    do {
      next *= x / n;
      n += 1;
      result += next;
      iterations--;
    } while (next >= precision && iterations);
  } else {
    result = 1.0 / my_exp(-x);
  }

  return result;
}
