#include "my_math.h"

long double my_cos(double x) {
  long double cos_result = 1;

  x = my_fmod(x, 2 * my_PI);

  long double item = 1;
  for (int i = 1; i < 4000; i++) {
    item = -item * x * x / ((2 * i - 1) * (2 * i));
    cos_result += item;
  }

  return cos_result;
}
