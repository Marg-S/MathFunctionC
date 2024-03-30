#include "my_math.h"

long double my_atan(double x) {
  long double atan_result = 0;

  if (my_is_inf(x)) {
    atan_result = my_PI / 2;
  } else if (my_is_inf_minus(x)) {
    atan_result = -my_PI / 2;
  } else if (my_is_NAN(x)) {
    atan_result = my_NAN;
  } else if (x == 1 || x == -1) {
    atan_result = x * my_PI / 4;
  } else if (x > -1. && x < 1.) {
    for (int i = 1; i < 5000; i++)
      atan_result += my_pow(-1, i - 1) * my_pow(x, 2 * i - 1) / (2 * i - 1);
  } else if (x > 1. || x < -1.) {
    if (x > 1.) {
      atan_result = my_PI / 2 - my_atan(1 / x);
    }
    if (x < -1.) {
      atan_result = -my_PI / 2 - my_atan(1 / x);
    }
  }

  return atan_result;
}
