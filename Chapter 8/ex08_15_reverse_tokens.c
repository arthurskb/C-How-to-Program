#include <stdio.h>
#include <string.h>

#define MAXLENGTH 101

void invertTokens(char string[]);

int main() {
  char string[MAXLENGTH];
  printf("%s", "Insert a string: (Max 99 characters)\n");
  fgets(string, MAXLENGTH, stdin);
  int length = strlen(string);
  string[length - 1] = '\0';
  printf("String = %s\n", string);
  invertTokens(string);
}

void invertTokens(char string[]) {
  char *tokenPtr = strtok(string, " ");
  char *tokens[33];
  int numberOfTokens = 0;
  tokens[numberOfTokens] = tokenPtr;
  while (tokenPtr != NULL) {
    tokenPtr = strtok(NULL, " ");
    numberOfTokens++;
    tokens[numberOfTokens] = tokenPtr;
  }
  printf("Inverted String = ");
  for (int i = numberOfTokens - 1; i >= 0; i--) {
    printf("%s ", tokens[i]);
  }
  printf("\n");
}
