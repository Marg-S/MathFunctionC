#include "my_math.h"

long double my_pow(double base, double exp) {
  long double pow_result = 1;
  long double buf_base = base;

  if (exp == 0)
    pow_result = 1;
  else if (base < 0 && my_fmod(exp, 1) != 0) {
    pow_result = my_NAN;
  } else {
    if (base < 0) buf_base = -buf_base;

    pow_result = my_exp(exp * my_log(buf_base));
    if (my_fmod(exp, 2) != 0 && base != buf_base) pow_result = -pow_result;
  }

  return pow_result;
}
