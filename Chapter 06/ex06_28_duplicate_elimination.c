#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int array[20] = {0};
  int holdnum;
  for (size_t i = 0; i < 20; i++) {
    holdnum = rand() % 20;
    array[holdnum]++;
  }
  printf("%s\n", "The unique values are: ");
  for (int i = 0; i < 20; i++) {
    if (array[i] == 1) printf("%d ", i + 1);
  }
  printf("\n");
}