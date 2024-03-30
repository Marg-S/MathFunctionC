#include "my_math.h"

// Taylor series approximations
long double my_log(double x) {
  long double result = 0.0;

  if (my_is_inf(x) || my_is_NAN(x)) {
    result = x;
  } else if (x < 0) {
    result = my_NAN;
  } else if (x == 0) {
    result = my_inf_minus;
  } else if (x == 1) {
    result = 0;
  } else {
    int iterations = 1000, exponent = 0;
    long double precision = 1e-8;

    while (x >= 10.0) {
      x /= 10.0;
      exponent++;
    }
    while (x < 1.0) {
      x *= 10.0;
      exponent--;
    }

    long double y = (x - 1.0) / (x + 1.0);
    long double y_next = 1.0, sum = 1.0;
    double current = 0.0;
    int n = 1;

    while (iterations && (my_fabs(current) >= precision || !current)) {
      y_next *= y * y;
      current = y_next / (2.0 * n + 1.0);
      sum += current;
      n++;
      iterations--;
    }

    result = 2.0 * y * sum + exponent * my_ln10;
  }

  return result;
}