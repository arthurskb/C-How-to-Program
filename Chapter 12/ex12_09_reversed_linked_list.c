#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList{
  struct linkedList* nextPtr;
  char value;
} ListNode;

void initializeList(ListNode** head, int i);
void freeList(ListNode** head);
ListNode* reverseList(ListNode* head);

int main() {
  ListNode* listOneHead = NULL;
  initializeList(&listOneHead, 65);
  ListNode* curr = listOneHead;
  while (curr != NULL) {
    printf("%c -> ", curr->value);
    curr = curr->nextPtr;
  }
  printf("NULL\n");
  ListNode* reversedHead = reverseList(listOneHead);
  curr = reversedHead;
  while (curr != NULL) {
    printf("%c -> ", curr->value);
    curr = curr->nextPtr;
  }
  printf("NULL\n");
  freeList(&listOneHead);
  freeList(&reversedHead);
  return 0;
}

ListNode* reverseList(ListNode* head) {
  ListNode* curr = head;
  char aux[10];
  int i = 9;
  while (curr != NULL) {
    aux[i] = curr->value;
    curr = curr->nextPtr;
    i--;
  }
  ListNode* headReverse = malloc(sizeof(ListNode));
  headReverse->value = aux[0];
  curr = headReverse;
  for (i = 1; i < 10; i++) {
    ListNode* newNode = malloc(sizeof(ListNode));
    newNode->value = aux[i];
    curr->nextPtr = newNode;
    curr = curr->nextPtr;
  }
  return headReverse;
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
