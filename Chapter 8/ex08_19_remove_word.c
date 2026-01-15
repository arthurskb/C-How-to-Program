#include <stdio.h>
#include <string.h>

#define MAXLENGTH 101

int countWords(char string[]);
void readString(char string[]);
void removeWord(char string[], char word[], char newString[]);

int main() {
  char string[MAXLENGTH];
  printf("%s\n", "Insert a String: (max 99 characters)");
  readString(string);
  countWords(string);
  char word[MAXLENGTH];
  printf("%s\n", "Insert a word to be removed: (max 99 characters)");
  readString(word);
  countWords(word);
  char newString[MAXLENGTH];
  removeWord(string, word, newString);
  printf("Initial String: \"%s\" with %d words\n", string, countWords(string));
  printf("Final String: \"%s\" with %d words\n", newString,
         countWords(newString));
}

void readString(char string[]) {
  fgets(string, MAXLENGTH, stdin);
  int length = strlen(string);
  string[length - 1] = '\0';
}

int countWords(char string[]) {
  char stringCpy[MAXLENGTH];
  strcpy(stringCpy, string);
  char *searchPtr = strtok(stringCpy, " ");
  int i = 0;
  while (searchPtr != NULL) {
    i++;
    searchPtr = strtok(NULL, " ");
  }
  return i;
}

void removeWord(char string[], char word[], char newString[]) {
  char *strPtr = string;
  char *strCurrentPtr = string;
  int numOfChars = 0;
  int wordSize = strlen(word);
  int stringSize = strlen(string);
  size_t i = 0;
  for (; i < stringSize - wordSize; i++) {
    int flag = strncmp(strCurrentPtr, word, wordSize);
    if (flag == 0) {
      strncpy(newString, strPtr, numOfChars);
      strCurrentPtr += wordSize;
      strPtr = strCurrentPtr;
      newString += numOfChars;
      numOfChars = 0;
    } else {
      numOfChars++;
      strCurrentPtr++;
    }
  }
  newString[i] = '\0';
}
