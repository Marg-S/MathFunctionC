#include "my_math.h"

long double my_fmod(double x, double y) {
  long double fmod_result = my_NAN;

  if ((my_is_inf(y) || my_is_inf_minus(y)) && !my_is_inf(x)) {
    fmod_result = x;
  } else if (y != 0 && !my_is_inf(x) && !my_is_NAN(x) && !my_is_NAN(y)) {
    fmod_result = x - y * (long long)(x / y);
  }

  return fmod_result;
}
