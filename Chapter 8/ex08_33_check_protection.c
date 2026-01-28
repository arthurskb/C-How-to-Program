#include <ctype.h>
#include <stdio.h>

#define MAXSPACES 9

char *checkProtection();

int main() {
  printf("Insert the amount to be printed: ");
  char *amount = checkProtection();
  if (amount == NULL) return 1;
  printf("%s\n", amount);
  printf("---------\n");
  printf("123456789\n");
}

char *checkProtection() {
  char inputValue[MAXSPACES + 1];
  fgets(inputValue, MAXSPACES + 1, stdin);
  int len = 0;
  for (size_t i = 0; i < MAXSPACES + 1; i++) {
    if (inputValue[i] == '\n') {
      inputValue[i] = '\0';
      break;
    } else if (i == MAXSPACES) {
      inputValue[MAXSPACES] = '\0';
      break;
    }
    len++;
  }
  int aux = MAXSPACES - len;
  static char checkInput[MAXSPACES + 1];
  size_t i = 0;
  for (; i < aux; i++) {
    checkInput[i] = '*';
  }
  for (; i < MAXSPACES + 1; i++) {
    checkInput[i] = inputValue[i - aux];
  }
  for (i = MAXSPACES - 1; i > aux - 1; i--) {
    if (i == 6) {
      if (checkInput[i] != '.') {
        printf("Invalid Input\n");
        return NULL;
      }
    } else if (i == 2) {
      if (checkInput[i] != ',') {
        printf("Invalid Input\n");
        return NULL;
      }
    } else {
      if (isdigit(checkInput[i]) == 0) {
        printf("Invalid Input\n");
        return NULL;
      }
    }
  }
  return checkInput;
}
