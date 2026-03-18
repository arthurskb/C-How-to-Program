#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  char value;
  struct stack* prevPtr;
} StackNode;

void reverseSentence();

int main() { reverseSentence(); }

void reverseSentence() {
  printf("Input a sentence:\n");

  char c = getchar();
  if (c == '\0' || c == '\n' || c == EOF) return;
  StackNode* head = malloc(sizeof(StackNode));
  head->value = c;
  head->prevPtr = NULL;

  while ((c = getchar()) != '\0' && c != '\n' && c != EOF) {
    StackNode* newNode = malloc(sizeof(StackNode));
    newNode->value = c;
    newNode->prevPtr = head;
    head = newNode;
  }

  while (head != NULL) {
    printf("%c", head->value);
    StackNode* temp = head;
    head = head->prevPtr;
    free(temp);
  }
  printf("\n");
}
