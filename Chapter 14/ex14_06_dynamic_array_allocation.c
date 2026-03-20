#include <stdio.h>
#include <stdlib.h>

void allocateArray(int** array, int size);
void reallocateArray(int** array, int size);

int main() {
  printf("What is the size of the array? ");
  int size;
  scanf("%d", &size);
  int* array = NULL;
  allocateArray(&array, size);
  reallocateArray(&array, size);
  free(array);
}

void allocateArray(int** array, int size) {
  *array = calloc(size, sizeof(int));
  for (size_t i = 0; i < size; i++) {
    printf("Insert the %ldº element: ", i + 1);
    scanf("%d", *array + i);
  }
  printf("You array is: \n");
  for (size_t i = 0; i < size; i++) {
    printf("%d ", (*array)[i]);
  }
  printf("\n");
}

void reallocateArray(int** array, int size) {
  size = size / 2;
  *array = realloc(*array, size * sizeof(int));
  printf("The halfed array is:  \n");
  for (size_t i = 0; i < size; i++) {
    printf("%d ", (*array)[i]);
  }
  printf("\n");
}
