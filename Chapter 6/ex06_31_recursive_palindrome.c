#include <stdio.h>

#define SIZE 50

int testPalindrome(char phrase[], int beginningCursor, int endCursor) {
  // printf("%d %d\n", beginningCursor, endCursor);
  if ((beginningCursor == endCursor) || (beginningCursor > endCursor)) {
    return 1;
  } else if (phrase[beginningCursor] != phrase[endCursor]) {
    return 0;
  } else {
    return testPalindrome(phrase, beginningCursor + 1, endCursor - 1);
  }
}

int main() {
  char phrase[SIZE];
  printf("%s\n", "Insert a phrase with at least 49 characteres!");
  fgets(phrase, SIZE, stdin);
  printf("%s", phrase);
  int length = 0;
  char testPhrase[SIZE];
  int i = 0, j = 0;
  while (phrase[i] != '\0') {
    // printf("%c", phrase[i]);
    if ((phrase[i] != ' ') && (phrase[i] != ',') && (phrase[i] != '.')) {
      length++;
      testPhrase[j] = phrase[i];
      j++;
    }
    i++;
  }
  // printf("\n");
  testPhrase[j] = '\0';
  int result = testPalindrome(testPhrase, 0, length - 2);
  if (result == 1)
    printf("is a palindrome!\n");
  else
    printf("is not a palindrome!\n");
}
