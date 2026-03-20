#include <stdarg.h>
#include <stdio.h>

void product(int size, ...);

int main() {
  product(5, 1, 2, 3, 4, 5);
  product(3, 3, 3, 3);
  product(2, 4, 4);
  product(4, 10, 4, 4, 10);
}

void product(int size, ...) {
  int result = 1;
  va_list ap;
  va_start(ap, size);
  for (size_t i = 0; i < size; i++) {
    int curr = va_arg(ap, int);
    printf("%d ", curr);
    result *= curr;
  }
  printf("\nMultiplying all elements = %d\n", result);
}
