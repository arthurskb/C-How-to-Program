// Fig. 12.19: fig12_19.c
// Creating and traversing a binary tree
// preorder, inorder, and postorder
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// self-referential structure
struct treeNode {
  struct treeNode *leftPtr;   // pointer to left subtree
  int data;                   // node value
  struct treeNode *rightPtr;  // pointer to right subtree
};

typedef struct treeNode TreeNode;  // synonym for struct treeNode
typedef TreeNode *TreeNodePtr;     // synonym for TreeNode*

// prototypes
void insertNode(TreeNodePtr *treePtr, int value);
void outputTree(TreeNodePtr treePtr, int totalSpaces);

// function main begins program execution
int main(void) {
  TreeNodePtr rootPtr = NULL;  // tree initially empty

  srand(time(NULL));
  puts("The numbers being placed in the tree are:");

  // insert random values between 0 and 14 in the tree
  for (unsigned int i = 1; i <= 15; ++i) {
    int item = rand() % 100;
    printf("%3d", item);
    insertNode(&rootPtr, item);
  }
  printf("\n");
  outputTree(rootPtr, 0);
  printf("\n");
}

// insert node into tree
void insertNode(TreeNodePtr *treePtr, int value) {
  // if tree is empty
  if (*treePtr == NULL) {
    *treePtr = malloc(sizeof(TreeNode));

    // if memory was allocated, then assign data
    if (*treePtr != NULL) {
      (*treePtr)->data = value;
      (*treePtr)->leftPtr = NULL;
      (*treePtr)->rightPtr = NULL;
    } else {
      printf("%d not inserted. No memory available.\n", value);
    }
  } else {  // tree is not empty
    // data to insert is less than data in current node
    if (value < (*treePtr)->data) {
      insertNode(&((*treePtr)->leftPtr), value);
    }

    // data to insert is greater or equal than data in current node
    else if (value >= (*treePtr)->data) {
      insertNode(&((*treePtr)->rightPtr), value);
    }
  }
}

void outputTree(TreeNodePtr treePtr, int totalSpaces) {
  if (treePtr != NULL) {
    outputTree(treePtr->rightPtr, totalSpaces + 5);
    for (size_t i = 1; i < totalSpaces; i++) {
      printf(" ");
    }
    printf("%d\n", treePtr->data);
    outputTree(treePtr->leftPtr, totalSpaces + 5);
  }
}
