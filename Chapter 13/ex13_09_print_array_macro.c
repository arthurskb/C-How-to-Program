#include <stdio.h>

#define PRINTARRAY(array, size) \
  for (size_t i = 0; i < size; i++) printf("%d\n", array[i])

int main() {
  int array[] = {1, 3, 5, 7, 9, 11, 13, 15};
  PRINTARRAY(array, 8);
}
