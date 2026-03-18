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
void removeBlankSpaces(char input[], char output[]);
int evaluatePostfixExpression(char *expr);
int calculate(int op1, int op2, char operator);

int main() {
  printf("Insert a valid postfix expression: ");
  char postfixInput[1024], postfix[1024];
  fgets(postfixInput, 1024, stdin);
  removeBlankSpaces(postfixInput, postfix);
  int result = evaluatePostfixExpression(postfix);
  printf("Postfix result is: %d\n", result);
}

int evaluatePostfixExpression(char *expr) {
  int i = 0;
  StackNode *topPtr = NULL;
  while (expr[i] != '\0') {
    if (isdigit(expr[i])) {
      int value = expr[i] - '0';
      push(&topPtr, value);
    } else {
      int x = pop(&topPtr);
      int y = pop(&topPtr);
      int result = calculate(y, x, expr[i]);
      push(&topPtr, result);
    }
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

void removeBlankSpaces(char input[], char output[]) {
  int i = 0, j = 0;
  while (input[i] != '\n') {
    if (input[i] == ' ') {
      i++;
    } else {
      output[j] = input[i];
      i++;
      j++;
    }
  }
  output[j] = '\0';
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
