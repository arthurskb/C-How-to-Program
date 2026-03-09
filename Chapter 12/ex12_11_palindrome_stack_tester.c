#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack {
  char value;
  struct stack* prevPtr;
} StackNode;

int checkPalindrome();

int main() {
  int result = checkPalindrome();
  if (result) {
    printf("Palindrome found\n");
  } else {
    printf("This isn't a Palindrome\n");
  }
}

int checkPalindrome() {
  printf("Input a sentence:\n");

  char c;
  char str[1024];
  int strI = 0;

  while (c = getchar()) {
    if (c == '\n' || c == '\0' || c == EOF) return 0;
    else if (isalnum(c)) break;
  }
  StackNode* head = malloc(sizeof(StackNode));
  head->value = c;
  str[strI] = c;
  head->prevPtr = NULL;

  while ((c = getchar()) != '\0' && c != '\n' && c != EOF) {
    if (!isalnum(c)) continue;
    strI++;
    str[strI] = c;
    StackNode* newNode = malloc(sizeof(StackNode));
    newNode->value = c;
    newNode->prevPtr = head;
    head = newNode;
  }

  StackNode* curr = head;
  int result = 1;

  for (size_t i = 0; i <= strI; i++) {
    if (curr->value != str[i]) {
      result = 0;
      break;
    }
    curr = curr->prevPtr;
  }

  while (head != NULL) {
    StackNode* temp = head;
    head = head->prevPtr;
    free(temp);
  }

  return result;
}
