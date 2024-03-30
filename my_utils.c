#include "my_math.h"

int my_is_inf(double x) { return x == my_inf; }

int my_is_inf_minus(double x) { return x == my_inf_minus; }

int my_is_NAN(double x) { return x != x; }

unsigned long long my_factorial(int n) {
  unsigned long long result = 0;
  if (n == 0 || n == 1) {
    result = 1;
  } else {
    result = n * my_factorial(n - 1);
  }

  return result;
}