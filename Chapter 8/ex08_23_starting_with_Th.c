#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLENGTH 101

void readString(char string[]);
void printTH(char string[]);

int main() {
  printf("Insert a string: (Max 99 characters)\n");
  char string[MAXLENGTH];
  readString(string);
  printTH(string);
}

void printTH(char string[]) {
  char *tokenPtr = strtok(string, " ");
  char th[] = "Th";
  while (tokenPtr != NULL) {
    if (strncmp(th, tokenPtr, 2) == 0) {
      printf("%s\n", tokenPtr);
    }
    tokenPtr = strtok(NULL, " ");
  }
}

void readString(char string[]) {
  fgets(string, MAXLENGTH, stdin);
  int length = strlen(string);
  string[length - 1] = '\0';
}
