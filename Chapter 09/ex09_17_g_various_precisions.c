#include <stdio.h>

int main() {
  printf("Insert the value 9876.12345: ");
  double val;
  scanf("%lf", &val);
  for (size_t i = 1; i <= 9; i++) {
    printf("Printing val %lf with %ld precision: %.*lg\n", val, i, (int)i, val);
  }
}
