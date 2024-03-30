#include "my_math.h"

long double my_floor(double x) {
  long double result = 0.0;
  if (x == DBL_MIN || my_is_inf(x) || my_is_inf_minus(x) || my_is_NAN(x) ||
      my_fabs(x - DBL_MAX) <= 10) {
    result = x;
  } else {
    char str[1000];
    sprintf(str, "%.15f", x);

    int dot_position = -1;
    size_t i = 0;
    while (i < strlen(str) && str[i] != '.') {
      i++;
    }

    if (str[i] != '\0') {
      dot_position = i;
    }

    if (dot_position != -1) {
      str[dot_position] = '\0';
    }

    result = atof(str);
    if (my_fabs(x - result) > my_EPSILON && x < 0) {
      result--;
    }
  }

  return result;
}
