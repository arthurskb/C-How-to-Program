#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1001

int countWords(char string[]);
void readString(char string[]);

int main() {
  char string[MAXLENGTH];
  printf("%s\n", "Insert a BIG String: (max 999 characters)");
  readString(string);
  int wordsNum = countWords(string);
  printf("We found %d words\n", wordsNum);
}

void readString(char string[]) {
  fgets(string, MAXLENGTH, stdin);
  int length = strlen(string);
  string[length - 1] = '\0';
}

int countWords(char string[]) {
  char stringCpy[MAXLENGTH];
  strcpy(stringCpy, string);
  char *searchPtr = strtok(stringCpy, " \n");
  printf("%s\n", string);
  int wordsNum = 0;
  while (searchPtr != NULL) {
    wordsNum++;
    searchPtr = strtok(NULL, " \n");
  }
  return wordsNum;
}
