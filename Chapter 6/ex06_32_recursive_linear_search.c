#include <stdio.h>

int linearSearch(int array[], int length, int key);

int main() {
  int arraySize;
  printf("%s ", "Insert the size of the array:");
  scanf("%d", &arraySize);
  int array[arraySize];
  for (int i = 0; i < arraySize; i++) {
    printf("%s%d%s", "Insert the ", i + 1, "º element: ");
    scanf("%d", &array[i]);
  }
  int key;
  printf("%s ", "Insert the key number you want to find:");
  scanf("%d", &key);
  int index = linearSearch(array, arraySize - 1, key);
  if (index == -1)
    printf("%s%d%s\n", "Sorry, the number ", key, " wasn't found.");
  else
    printf("%s%d%s%d%s\n", "The number ", key, " was found on the ", index,
           "º position!");
}

int linearSearch(int array[], int length, int key) {
  if (length < 0)
    return -1;
  else if (array[length] == key)
    return length + 1;
  else
    return linearSearch(array, length - 1, key);
}
