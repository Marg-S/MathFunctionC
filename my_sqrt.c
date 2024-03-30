#include "my_math.h"

long double my_sqrt(double x) {
  long double sqrt_result = 1;
  long double epsilon = 1e-25;
  double iterations = 5e7;

  if (x < 0 || my_is_NAN(x))
    sqrt_result = my_NAN;
  else if (x == 0)
    sqrt_result = 0;
  else
    while (my_fabs(sqrt_result * sqrt_result - x) > epsilon && iterations) {
      sqrt_result = (sqrt_result + x / sqrt_result) / 2.;
      iterations--;
    }

  return sqrt_result;
}
