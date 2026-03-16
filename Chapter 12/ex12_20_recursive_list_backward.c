#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList{
  struct linkedList* nextPtr;
  char value;
} ListNode;

void initializeList(ListNode** head, int i);
void freeList(ListNode** head);
void printListBackward(ListNode* node);

int main() {
  ListNode* listOneHead = NULL;
  initializeList(&listOneHead, 65);
  ListNode* curr = listOneHead;
  while (curr != NULL) {
    printf("%c -> ", curr->value);
    curr = curr->nextPtr;
  }
  printf("NULL\n");
  printListBackward(listOneHead);
  freeList(&listOneHead);
  return 0;
}

void printListBackward(ListNode* node) {
  if (node == NULL) {
    printf("NULL <-");
    return;
  } else {
    printListBackward(node->nextPtr);
    printf(" %c <-", node->value);
  }
}

void initializeList(ListNode** head, int i) {
  *head = malloc(sizeof(ListNode));
  (*head)->value = i;
  (*head)->nextPtr = NULL;
  ListNode* curr = *head;
  for (size_t j = i+1; j < i+10; j++) {
    ListNode* newNode = malloc(sizeof(ListNode));
    newNode->value = j;
    newNode->nextPtr = NULL;
    curr->nextPtr = newNode;
    curr = newNode;
  }
}

void freeList(ListNode** head) {
  ListNode* curr = *head;
  while (curr != NULL) {
    ListNode* temp = curr;
    curr = curr->nextPtr;
    free(temp);
  }
  *head = NULL;
}
