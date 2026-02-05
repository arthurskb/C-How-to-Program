#include <stdio.h>

int main() {
  double val = 100.453627;
  long aux = 1;
  for (size_t i = 0; i <= 4; i++) {
    long valaux = val*aux+0.5;
    printf("%.*lf\n", (int) i, (double) valaux / aux);
    aux *= 10;
  }
}
