#include <stdio.h>

#define SIZE 10
#define KEY 101

int binarySearch(int array[], int startingIndex, int endingIndex, int key);

int main() {
  int array[SIZE] = {1, 4, 3, 6, 9, 22, 90, 99, 101, 200};
  int index = binarySearch(array, 0, SIZE - 1, KEY);
  if (index == -1)
    printf("%s%d%s\n", "Sorry, the number ", KEY, " wasn't found.");
  else
    printf("%s%d%s%d%s\n", "The number ", KEY, " was found! It's the ", index,
           "º element.");
}

int binarySearch(int array[], int startingIndex, int endingIndex, int key) {
  int middle = (endingIndex + startingIndex) / 2;
  // printf("%d %d\n", middle, array[middle]);
  if (array[middle] == key)
    return middle + 1;
  else if (startingIndex >= endingIndex)
    return -1;
  else if (array[middle] < key)
    return binarySearch(array, middle + 1, endingIndex, key);
  else
    binarySearch(array, startingIndex, middle - 1, key);
}
