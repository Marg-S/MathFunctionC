#include "my_math.h"

long double my_ceil(double x) {
  long double result = 0.0;
  if (x == DBL_MAX || my_is_inf(x) || my_is_inf_minus(x) || my_is_NAN(x)) {
    result = x;
  } else {
    result = (long double)(long long)x;
    if (result < x) {
      result += 1;
    }
  }

  return result;
}
