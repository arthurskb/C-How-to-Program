#include <stdio.h>

// do while(0) macro logic protection
#define SUMARRAY(array, size, result)                     \
  do {                                                    \
    result = 0;                                           \
    for (size_t i = 0; i < size; i++) result += array[i]; \
  } while (0)

int main() {
  int array[] = {1, 3, 5, 7, 9, 11, 13, 15};
  int sum;
  SUMARRAY(array, 8, sum);
  printf("%d\n", sum);
}
