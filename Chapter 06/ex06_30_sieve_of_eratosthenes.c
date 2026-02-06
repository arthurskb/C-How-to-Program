#include <stdio.h>

#define SIZE 1000

int main() {
  int array[SIZE];
  for (size_t i = 0; i < SIZE; i++) {
    array[i] = 1;
  }
  for (size_t i = 2; i < SIZE; i++) {
    if (array[i] == 1) {
      for (size_t j = 2; i * j < SIZE; j++) {
        array[i * j] = 0;
        // printf("%ld\n", i*j);
      }
    }
  }
  for (size_t i = 2; i < SIZE; i++) {
    if (array[i] == 1) printf("%ld%s\n", i, " is a prime number.");
  }
  return 0;
}
