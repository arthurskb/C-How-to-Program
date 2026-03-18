#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linkedList {
  struct linkedList* nextPtr;
  int value;
} ListNode;

void initializeList(ListNode** head);
void freeList(ListNode** head);

int main() {
  srand(time(NULL));
  ListNode* head = NULL;
  initializeList(&head);
  ListNode* curr = head;
  while (curr != NULL) {
    printf("%d -> ", curr->value);
    curr = curr->nextPtr;
  }
  printf("NULL\n");
  freeList(&head);
  return 0;
}

void initializeList(ListNode** head) {
  *head = malloc(sizeof(ListNode));
  (*head)->value = rand() % 100;
  printf("Head value = %d\n", (*head)->value);
  (*head)->nextPtr = NULL;
  ListNode* curr = *head;
  ListNode* prev = NULL;
  for (size_t i = 1; i < 25; i++) {
    ListNode* newNode = malloc(sizeof(ListNode));
    newNode->value = rand() % 100;
    printf("New value = %d\n", newNode->value);
    newNode->nextPtr = NULL;
    if (newNode->value < curr->value) {
      *head = newNode;
      (*head)->nextPtr = curr;
    } else {
      prev = *head;
      curr = prev->nextPtr;
      while (curr != NULL && newNode->value > curr->value) {
        prev = curr;
        curr = curr->nextPtr;
      }
      prev->nextPtr = newNode;
      newNode->nextPtr = curr;
    }
    curr = *head;
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
