#include <stdio.h>

#define SIZE 6

void printArray(int array[], int length);

int main() {
  int array[SIZE] = {2, 3, 11, 4, 8, 9};
  printArray(array, SIZE - 1);
  printf("\n");
}

void printArray(int array[], int length) {
  if (length == 0) {
    printf("%d", array[length]);
    return;
  }
  printArray(array, length - 1);
  printf("%d", array[length]);
}
