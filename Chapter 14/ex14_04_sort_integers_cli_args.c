#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void order(int array[], int size, int choice);

int main(int argc, char *argv[]) {
  int choice;
  if (argc != 2) {
    printf("Please, insert the ordering argument -a or - d\n");
    exit(EXIT_FAILURE);
  }
  if (strcmp(argv[1], "-d") == 0) {
    printf("Descending order detected\n");
    choice = 0;
  } else if (strcmp(argv[1], "-a") == 0) {
    printf("Ascending order detected\n");
    choice = 1;
  } else {
    printf("Invalid argument, please try again using -a or -d\n");
    exit(EXIT_FAILURE);
  }
  printf("Insert how many values the array will contain: ");
  int size;
  scanf("%d", &size);
  int array[size];
  for (size_t i = 0; i < size; i++) {
    printf("Insert the %ldº element: ", i + 1);
    scanf("%d", &array[i]);
  }
  order(array, size, choice);
}

void order(int array[], int size, int choice) {
  printf("You array is: \n");
  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  if (choice == 0) {
    for (size_t i = 0; i < size; i++) {
      for (size_t j = i + 1; j < size; j++) {
        if (array[i] < array[j]) {
          int temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
      }
    }
  } else {
    for (size_t i = 0; i < size; i++) {
      for (size_t j = i + 1; j < size; j++) {
        if (array[i] > array[j]) {
          int temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
      }
    }
  }
  printf("You array after ordering is: \n");
  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
