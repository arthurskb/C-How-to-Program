#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
#define MAXLEN 100

void convertStrToInt(char str[SIZE][MAXLEN], long nums[SIZE]);
void calculations(long nums[SIZE]);

int main() {
  char str[SIZE][MAXLEN];
  long nums[SIZE];
  convertStrToInt(str, nums);
  calculations(nums);
}

void convertStrToInt(char str[SIZE][MAXLEN], long nums[SIZE]) {
  char *remainderPtr;
  for (size_t i = 0; i < SIZE; i++) {
    remainderPtr = str[i];
    while (remainderPtr == str[i]) {
      printf("%s%ld%s\n", "Insert the ", i + 1,
             "º number(which is going to be read as a string, and converted to "
             "an integer)");
      fgets(str[i], MAXLEN, stdin);
      nums[i] = strtol(str[i], &remainderPtr, 0);
    }
  }
}

void calculations(long nums[SIZE]) {
  long sum = 0;
  for (size_t i = 0; i < SIZE; i++) {
    sum += nums[i];
  }
  printf("%s%ld%s%.2lf\n", "Sum = ", sum, " Avrg = ", (double)sum / 6);
}
