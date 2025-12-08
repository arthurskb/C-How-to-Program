// NOTE: Could be better, by just using the index and excluding smallest
// variable selection sort
#include <stdio.h>

void sort(int array[], int size);

int main(void) {
  printf("%s", "Hi, insert the size of your array: ");
  int size = 0;
  scanf("%d", &size);
  printf("%s", "Now, insert the numbers of your array: ");
  int array[size];
  for (size_t i = 0; i < size; i++) {
    scanf("%d", &array[i]);
    printf(" ");
  }

  printf("%s", "This is your array before sort: ");
  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  sort(array, size);

  printf("%s", "This is your array sorted: ");
  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}

void sort(int array[], int size) {
  int smallest, aux;
  for (size_t i = 0; i < size; i++) {
    smallest = array[i];
    for (size_t j = i + 1; j < size; j++) {
      if (array[j] < smallest) {
        smallest = array[j];
        aux = j;
      }
    }
    if (array[i] != smallest) {
      array[aux] = array[i];
      array[i] = smallest;
    }
  }
}