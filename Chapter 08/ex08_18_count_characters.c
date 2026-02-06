#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLENGTH 101

void searchStr(char string[]);
void readString(char string[]);

int main() {
  char string[MAXLENGTH];
  printf("%s\n", "Insert a String: (max 100 characters)");
  readString(string);
  searchStr(string);
}

void readString(char string[]) {
  fgets(string, MAXLENGTH, stdin);
  int length = strlen(string);
  string[length - 1] = '\0';
}

void searchStr(char string[]) {
  char currentChar;
  int vowelsNum = 0, consosNum = 0, digitsNum = 0, wspacesNum = 0;
  int length = strlen(string);
  char vowels[] = {'a', 'e', 'i', 'o', 'u'};
  for (size_t i = 0; i < length; i++) {
    currentChar = string[i];
    if (isalpha(currentChar)) {
      currentChar = tolower(currentChar);
      int vowelFlag = 0;
      for (size_t i = 0; i < 5; i++) {
        if (currentChar == vowels[i]) {
          vowelFlag = 1;
          break;
        }
      }
      if (vowelFlag) {
        vowelsNum++;
      } else {
        consosNum++;
      }
    } else if (isdigit(currentChar)) {
      digitsNum++;
    } else if (isspace(currentChar)) {
      wspacesNum++;
    }
  }
  printf(
      "Within the String: \"%s\", there are:\n%d vowels\n%d consonants\n%d "
      "digits\n%d white spaces\n",
      string, vowelsNum, consosNum, digitsNum, wspacesNum);
}
