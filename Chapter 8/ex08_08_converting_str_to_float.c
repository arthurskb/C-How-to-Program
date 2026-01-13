#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
#define MAXLEN 100

void convertStrToInt(char str[SIZE][MAXLEN], double nums[SIZE]);
void calculations(double nums[SIZE]);

int main() {
  char str[SIZE][MAXLEN];
  double nums[SIZE];
  convertStrToInt(str, nums);
  calculations(nums);
}

void convertStrToInt(char str[SIZE][MAXLEN], double nums[SIZE]) {
  char *remainderPtr;
  for (size_t i = 0; i < SIZE; i++) {
    remainderPtr = str[i];
    while (remainderPtr == str[i]) {
      printf("%s%ld%s\n", "Insert the ", i + 1,
             "º number(which is going to be read as a string, and converted to "
             "a double)");
      fgets(str[i], MAXLEN, stdin);
      nums[i] = strtod(str[i], &remainderPtr);
    }
  }
}

void calculations(double nums[SIZE]) {
  double sum = 0;
  for (size_t i = 0; i < SIZE; i++) {
    sum += nums[i];
  }
  printf("%s%.2lf%s%.2lf\n", "Sum = ", sum, " Avrg = ", (sum / 6));
}
