#include <stdio.h>
#include <stdlib.h>

char *writeAmount(const char *amount);

int main() {
  printf("Insert an amount between 0 and 100: ");
  char readAmount[7];
  fgets(readAmount, 7, stdin);
  char *printAmount = writeAmount(readAmount);
  printf("Your amount is:\n%s\n", printAmount);
}

char *writeAmount(const char *amount) {
  char *tens[10] = {"",      "",      "Twenty",  "Thirty", "Forty",
                    "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
  char *teens[10] = {"Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                     "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  char *units[10] = {"",     "One", "Two",   "Three", "Four",
                     "Five", "Six", "Seven", "Eight", "Nine"};
  char *endPtr;
  unsigned long dollars = strtoul(amount, &endPtr, 10);
  unsigned long cents = strtoul((endPtr + 1), NULL, 10);
  static char stringAmount[25];
  if (dollars >= 10 && dollars <= 19) {
    sprintf(stringAmount, "%s and %ld/100", teens[dollars - 10], cents);
  } else if (dollars < 0 || dollars > 99) {
    printf("Please, insert a value between 0 and 100\n");
  } else if (dollars == 0) {
    sprintf(stringAmount, "ZERO and %ld/100", cents);
  } else {
    int tensNum, unitsNum;
    tensNum = dollars / 10;
    unitsNum = dollars % 10;
    sprintf(stringAmount, "%s %s and %ld/100", tens[tensNum], units[unitsNum],
            cents);
  }
  return stringAmount;
}
