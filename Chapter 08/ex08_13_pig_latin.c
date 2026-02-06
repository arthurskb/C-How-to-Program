#include <stdio.h>
#include <string.h>

#define MAXLENGTH 100

void printLatinWords(char phrase[MAXLENGTH]);

int main() {
  char phrase[MAXLENGTH];
  printf("%s\n", "Insert a phrase with at maximum 99 characters:");
  fgets(phrase, MAXLENGTH, stdin);
  int excludeNewLineChar = strlen(phrase);
  phrase[excludeNewLineChar - 1] = '\0';
  printLatinWords(phrase);
}

void printLatinWords(char phrase[MAXLENGTH]) {
  printf("%s\n", "Converted to pigLatin:");
  char *tokenPtr = strtok(phrase, " ");
  unsigned int length = 0;
  char saveToken[MAXLENGTH + 2];
  while (tokenPtr != NULL) {
    length = strlen(tokenPtr);
    for (size_t i = 0; i < length; i++) {
      saveToken[i] = *(tokenPtr + i);
    }
    char holdLastChar = saveToken[length - 1];
    saveToken[length - 1] = saveToken[0];
    saveToken[0] = holdLastChar;
    saveToken[length] = 'a';
    saveToken[length + 1] = 'y';
    tokenPtr = strtok(NULL, " ");
    for (size_t i = 0; i < length + 2; i++) {
      printf("%c", saveToken[i]);
      saveToken[i] = ' ';
    }
    printf(" ");
  }
  printf("\n");
}
