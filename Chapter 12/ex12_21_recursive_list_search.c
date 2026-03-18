#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList {
  struct linkedList* nextPtr;
  int value;
} ListNode;

void initializeList(ListNode** head, int i);
void freeList(ListNode** head);
ListNode* searchList(ListNode* node, int target);

int main() {
  ListNode* listOneHead = NULL;
  initializeList(&listOneHead, 65);
  ListNode* curr = listOneHead;
  while (curr != NULL) {
    printf("%d -> ", curr->value);
    curr = curr->nextPtr;
  }
  printf("NULL\n");
  printf("Insert a num to search: ");
  int target;
  scanf("%d", &target);
  ListNode* search = searchList(listOneHead, target);
  if (search == NULL) {
    printf("%d was not found in the list.\n", target);
  } else {
    printf("%d was found in the list!\n", search->value);
  }
  freeList(&listOneHead);
  return 0;
}

ListNode* searchList(ListNode* node, int target) {
  if (node == NULL) {
    return NULL;
  } else if (node->value == target) {
    return node;
  } else {
    searchList(node->nextPtr, target);
  }
}

void initializeList(ListNode** head, int i) {
  *head = malloc(sizeof(ListNode));
  (*head)->value = i;
  (*head)->nextPtr = NULL;
  ListNode* curr = *head;
  for (size_t j = i + 1; j < i + 10; j++) {
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
