#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stackNode {
   int data;
   struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, char value);
char pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void convertToPostfix(char infix[], char postfix[]);
int isOperator(char c);
int precedence(char operator1, char operator2);
char stackTop(StackNodePtr topPtr);
void removeBlankSpaces(char infixInput[], char infix[]);

int main () {
  printf("Insert an infix expression: ");
  char infix[1024], postfix[1024], infixInput[1024];
  fgets(infixInput, 1024, stdin);
  removeBlankSpaces(infixInput, infix);
  convertToPostfix(infix, postfix);
  printf("Postfix version is:\n");
  printf("%s\n", postfix);
}

void removeBlankSpaces(char infixInput[], char infix[]) {
  int i = 0, j = 0;
  while (infixInput[i] != '\n') {
    if (infixInput[i] == ' ') {
      i++;
    } else {
      infix[j] = infixInput[i];
      i++;
      j++;
    }
  }
  infix[j] = '\0';
}

int precedence(char operator1, char operator2) {
  int op1value, op2value;
  if (operator1 == '+' || operator1 == '-') op1value = 1;
  else if (operator1 == '*' || operator1 == '/' || operator1 == '%') op1value = 2;
  else if (operator1 == '^') op1value = 3;
  if (operator2 == '+' || operator2 == '-') op2value = 1;
  else if (operator2 == '*' || operator2 == '/' || operator2 == '%') op2value = 2;
  else if (operator2 == '^') op2value = 3;
  return op1value - op2value;
}

int isOperator(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%') {
    return 1;
  }
  return 0;
}

void convertToPostfix(char infix[], char postfix[]) {
  StackNodePtr topPtr = NULL;
  push(&topPtr, '(');
  int len = strlen(infix);
  infix[len] = ')';
  infix[len+1] = '\0';
  int i = 0, p = 0;
  char topValue;
  while (!isEmpty(topPtr)) {
    if (isdigit(infix[i])) {
      postfix[p] = infix[i];
      p++;
      i++;
    }
    else if (infix[i] == '(') {
      push(&topPtr, infix[i]);
      i++;
    }
    else if (isOperator(infix[i])) {
      int compare;
      do {
        topValue = stackTop(topPtr);
        if (isOperator(topValue)) {
          compare = precedence(infix[i], topValue);
          if (compare <= 0) {
            postfix[p] = pop(&topPtr);
            p++;
          }
        } else {
          compare = 1;
        }
      } while (compare <= 0);
      push(&topPtr, infix[i]);
      i++;
    }
    else if (infix[i] == ')') {
      while ((topValue = stackTop(topPtr)) != '(') {
        postfix[p] = pop(&topPtr);
        p++;
      }
      pop(&topPtr);
      i++;
    }
  }
  postfix[p] = '\0';
}

char stackTop(StackNodePtr topPtr) {
  return topPtr->data;
}

void push(StackNodePtr *topPtr, char value)
{
   StackNodePtr newPtr = malloc(sizeof(StackNode));

   if (newPtr != NULL) {
      newPtr->data = value;
      newPtr->nextPtr = *topPtr;
      *topPtr = newPtr;
   }
   else {
      printf("%d not inserted. No memory available.\n", value);
   }
}

char pop(StackNodePtr *topPtr)
{
   StackNodePtr tempPtr = *topPtr;
   char popValue = (*topPtr)->data;
   *topPtr = (*topPtr)->nextPtr;
   free(tempPtr);
   return popValue;
}

void printStack(StackNodePtr currentPtr)
{
   if (currentPtr == NULL) {
      puts("The stack is empty.\n");
   }
   else {
      puts("The stack is:");

      while (currentPtr != NULL) {
         printf("%d --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      }

      puts("NULL\n");
   }
}

int isEmpty(StackNodePtr topPtr)
{
   return topPtr == NULL;
}

