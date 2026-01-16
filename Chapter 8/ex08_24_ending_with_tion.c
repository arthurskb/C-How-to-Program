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
  char tion[] = "tion";
  int len;
  while (tokenPtr != NULL) {
    len = strlen(tokenPtr);
    if (strncmp(tion, &tokenPtr[len - 4], 2) == 0) {
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
