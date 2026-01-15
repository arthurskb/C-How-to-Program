#include <stdio.h>
#include <string.h>

void processNumber(char string[]);

int main() {
  char number[15];
  printf("%s", "Insert a number in format (XXX) XXX-XXXX:\n");
  fgets(number, 15, stdin);
  processNumber(number);
}

void processNumber(char string[]) {
  int areaCode;
  long number;
  char *tokenPtr = strtok(string, " ");
  char areaCodeStr[4];
  for (size_t i = 1; i <= 3; i++) areaCodeStr[i - 1] = *(tokenPtr + i);
  areaCodeStr[3] = '\0';
  tokenPtr = strtok(NULL, "-");
  char firstNumber[4];
  for (size_t i = 0; i < 3; i++) firstNumber[i] = *(tokenPtr + i);
  firstNumber[3] = '\0';
  tokenPtr = strtok(NULL, " ");
  char secondNumber[5];
  for (size_t i = 0; i < 4; i++) secondNumber[i] = *(tokenPtr + i);
  secondNumber[4] = '\0';
  char fullNumber[8] = "";
  strcat(fullNumber, firstNumber);
  strcat(fullNumber, secondNumber);
  sscanf(areaCodeStr, "%d", &areaCode);
  sscanf(fullNumber, "%ld", &number);
  printf("%s%d\n", "Area Code = ", areaCode);
  printf("%s%ld\n", "Number = ", number);
}
