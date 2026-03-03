#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linkedList{
  struct linkedList* nextPtr;
  int value;
} ListNode;

void initializeList(ListNode** head);
void freeList(ListNode** head);
void orderList(ListNode* head);
ListNode* merge(ListNode* listOneHead, ListNode* listTwoHead);

int main() {
  srand(time(NULL));
  ListNode* listOneHead = NULL;
  ListNode* listTwoHead = NULL;
  initializeList(&listOneHead);
  initializeList(&listTwoHead);
  orderList(listOneHead);
  orderList(listTwoHead);
  ListNode* curr = listOneHead;
  while (curr != NULL) {
    printf("%d -> ", curr->value);
    curr = curr->nextPtr;
  }
  printf("NULL\n");
  curr = listTwoHead;
  while (curr != NULL) {
    printf("%d -> ", curr->value);
    curr = curr->nextPtr;
  }
  printf("NULL\n");
  ListNode* list = merge(listOneHead, listTwoHead);
  curr = list;
  while (curr != NULL) {
    printf("%d -> ", curr->value);
    curr = curr->nextPtr;
  }
  printf("NULL\n");
  freeList(&list);
  return 0;
}

ListNode* merge(ListNode* listOneHead, ListNode* listTwoHead) {
  ListNode* node1 = listOneHead;
  ListNode* node2 = listTwoHead;
  ListNode* head;
  if (node1->value < node2->value) {
    head = node1;
    node1 = node1->nextPtr;
  } else {
    head = node2;
    node2 = node2->nextPtr;
  }
  ListNode* curr = head;
  while (node1 != NULL && node2 != NULL) {
    if (node1->value < node2->value) {
      curr->nextPtr = node1;
      node1 = node1->nextPtr;
    } else {
      curr->nextPtr = node2;
      node2 = node2->nextPtr;
    }
    curr = curr->nextPtr;
  }
  while (node1 != NULL) {
    curr->nextPtr = node1;
    node1 = node1->nextPtr;
    curr = curr->nextPtr;
  }
  while (node2 != NULL) {
    curr->nextPtr = node2;
    node2 = node2->nextPtr;
    curr = curr->nextPtr;
  }
  return head;
}

void initializeList(ListNode** head) {
  *head = malloc(sizeof(ListNode));
  (*head)->value = rand() % 100;
  (*head)->nextPtr = NULL;
  ListNode* curr = *head;
  for (size_t j = 1; j < 10; j++) {
    ListNode* newNode = malloc(sizeof(ListNode));
    newNode->value = rand() % 100;
    newNode->nextPtr = NULL;
    curr->nextPtr = newNode;
    curr = newNode;
  }
}

void orderList(ListNode* head) {
  ListNode* curr = head;
  while (curr != NULL) {
    ListNode* traverse = curr->nextPtr;
    while (traverse != NULL) {
      if (traverse->value < curr->value) {
        int aux = traverse->value;
        traverse->value = curr->value;
        curr->value = aux;
      }
      traverse = traverse->nextPtr;
    }
    curr = curr->nextPtr;
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
