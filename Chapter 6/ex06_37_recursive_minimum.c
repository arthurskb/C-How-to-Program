#include <stdio.h>

#define SIZE 10

int recursiveMinimum(int array[], int length);

int main() {
  int array[] = {1, 2, 3, 4, 15, 11, 90, 12, 31, 10};
  int smallest = recursiveMinimum(array, SIZE - 1);
  printf("%s%d\n", "Smallest number = ", smallest);

  return 0;
}

int recursiveMinimum(int array[], int length) {
  if (length == 0) {
    return array[0];
  }
  int compare = recursiveMinimum(array, length - 1);
  if (compare < array[length]) {
    return compare;
  } else {
    return array[length];
  }
}
