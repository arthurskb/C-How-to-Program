#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stackNode {
  int data;
  struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int value);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
int evaluatePostfixExpression(char *expr);
int calculate(int op1, int op2, char operator);

int main() {
  printf("Insert a valid postfix expression: ");
  char postfix[1024];
  fgets(postfix, 1024, stdin);
  int result = evaluatePostfixExpression(postfix);
  printf("Postfix result is: %d\n", result);
}

int evaluatePostfixExpression(char *expr) {
  int i = 0;
  StackNode *topPtr = NULL;
  while (expr[i] != '\n') {
    if (isdigit(expr[i])) {
      int currDigit = expr[i] - '0';
      int finalValue = currDigit;
      i++;
      while (isdigit(expr[i])) {
        currDigit = expr[i] - '0';
        finalValue *= 10;
        finalValue += currDigit;
        i++;
      }
      push(&topPtr, finalValue);
    } else if (expr[i] != ' ') {  // operator
      int x = pop(&topPtr);
      int y = pop(&topPtr);
      int result = calculate(y, x, expr[i]);
      push(&topPtr, result);
      i++;
    } else
      i++;
  }
  int finalResult = pop(&topPtr);
  return finalResult;
}

int calculate(int op1, int op2, char operator) {
  switch (operator) {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
    case '%':
      return op1 % op2;
    case '^':
      if (op2 == 0) return 1;
      int r = op1;
      for (int i = 1; i < op2; i++) r *= op1;
      return r;
  }
}

void push(StackNodePtr *topPtr, int value) {
  StackNodePtr newPtr = malloc(sizeof(StackNode));

  if (newPtr != NULL) {
    newPtr->data = value;
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr;
  } else {
    printf("%d not inserted. No memory available.\n", value);
  }
}

int pop(StackNodePtr *topPtr) {
  StackNodePtr tempPtr = *topPtr;
  int popValue = (*topPtr)->data;
  *topPtr = (*topPtr)->nextPtr;
  free(tempPtr);
  return popValue;
}

void printStack(StackNodePtr currentPtr) {
  if (currentPtr == NULL) {
    puts("The stack is empty.\n");
  } else {
    puts("The stack is:");

    while (currentPtr != NULL) {
      printf("%d --> ", currentPtr->data);
      currentPtr = currentPtr->nextPtr;
    }

    puts("NULL\n");
  }
}

int isEmpty(StackNodePtr topPtr) { return topPtr == NULL; }
