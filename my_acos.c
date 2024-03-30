#include "my_math.h"

long double my_acos(double x) {
  long double acos_result = my_NAN;

  if (x > -1 && x < 1) {
    if (x == -0.) x = 0;

    acos_result = my_atan(my_sqrt(1 - x * x) / x);
    if (x > -1 && x < 0) {
      acos_result += my_PI;
    }
  } else if (x == 1) {
    acos_result = 0;
  } else if (x == -1) {
    acos_result = my_PI;
  }

  return acos_result;
}