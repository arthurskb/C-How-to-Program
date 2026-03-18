// Fig. 12.19: fig12_19.c
// Creating and traversing a binary tree
// preorder, inorder, and postorder
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// self-referential structure
struct treeNode {
  struct treeNode *leftPtr;   // pointer to left subtree
  char *string;               // node value
  struct treeNode *rightPtr;  // pointer to right subtree
};

typedef struct treeNode TreeNode;  // synonym for struct treeNode
typedef TreeNode *TreeNodePtr;     // synonym for TreeNode*

// prototypes
void insertNode(TreeNodePtr *treePtr, char *word);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

// function main begins program execution
int main(void) {
  TreeNodePtr rootPtr = NULL;  // tree initially empty

  puts("Insert a sentence: ");
  char sentence[1024];
  fgets(sentence, 1024, stdin);
  int aux = strlen(sentence);
  sentence[aux - 1] = '\0';  // removes endofline
  char *tokenPtr = strtok(sentence, " ");
  while (tokenPtr != NULL) {
    insertNode(&rootPtr, tokenPtr);
    tokenPtr = strtok(NULL, " ");
  }

  // traverse the tree preOrder
  puts("\n\nThe preOrder traversal is:");
  preOrder(rootPtr);

  // traverse the tree inOrder
  puts("\n\nThe inOrder traversal is:");
  inOrder(rootPtr);

  // traverse the tree postOrder
  puts("\n\nThe postOrder traversal is:");
  postOrder(rootPtr);
  printf("\n");
}

// insert node into tree
void insertNode(TreeNodePtr *treePtr, char *word) {
  // if tree is empty
  if (*treePtr == NULL) {
    *treePtr = malloc(sizeof(TreeNode));

    // if memory was allocated, then assign data
    if (*treePtr != NULL) {
      (*treePtr)->string = word;
      (*treePtr)->leftPtr = NULL;
      (*treePtr)->rightPtr = NULL;
    } else {
      printf("%s not inserted. No memory available.\n", word);
    }
  } else {  // tree is not empty
    // data to insert is less than data in current node
    if (word < (*treePtr)->string) {
      insertNode(&((*treePtr)->leftPtr), word);
    }

    // data to insert is greater or equal than data in current node
    else if (word >= (*treePtr)->string) {
      insertNode(&((*treePtr)->rightPtr), word);
    }
  }
}

// begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr) {
  // if tree is not empty, then traverse
  if (treePtr != NULL) {
    inOrder(treePtr->leftPtr);
    printf("%s ", treePtr->string);
    inOrder(treePtr->rightPtr);
  }
}

// begin preorder traversal of tree
void preOrder(TreeNodePtr treePtr) {
  // if tree is not empty, then traverse
  if (treePtr != NULL) {
    printf("%s ", treePtr->string);
    preOrder(treePtr->leftPtr);
    preOrder(treePtr->rightPtr);
  }
}

// begin postorder traversal of tree
void postOrder(TreeNodePtr treePtr) {
  // if tree is not empty, then traverse
  if (treePtr != NULL) {
    postOrder(treePtr->leftPtr);
    postOrder(treePtr->rightPtr);
    printf("%s ", treePtr->string);
  }
}

/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
