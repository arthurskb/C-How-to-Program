#include <stdio.h>
#include <string.h>

#define MAXLENGTH 101

void searchSubStr(char string[], char subString[]);
void readString(char string[]);

int main() {
  char string[MAXLENGTH];
  printf("%s\n", "Insert a String: (max 99 characters)");
  readString(string);
  char subString[MAXLENGTH];
  printf("%s\n", "Insert a SubString to be searched: (max 99 characters)");
  readString(subString);
  searchSubStr(string, subString);
}

void readString(char string[]) {
  fgets(string, MAXLENGTH, stdin);
  int length = strlen(string);
  string[length - 1] = '\0';
}

void searchSubStr(char string[], char subString[]) {
  char *searchPtr = strstr(string, subString);
  int i = 0;
  if (searchPtr != NULL) {
    while (searchPtr != NULL) {
      printf("\n%dº match found:\n", ++i);
      printf(
          "Substring: \"%s\" was found in\nString: \"%s\"\nThe remainder is: "
          "\"%s\"\n",
          subString, string, searchPtr + strlen(subString));
      searchPtr = strstr(searchPtr + strlen(subString), subString);
    }
  } else {
    printf("SubString: \"%s\" was not found in\nString: \"%s\"\n", subString,
           string);
  }
  printf("\nWe found a total of %d ocurrences of SubString \"%s\"\n", i,
         subString);
}
