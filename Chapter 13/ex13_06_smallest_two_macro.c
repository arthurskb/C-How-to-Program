#include <stdio.h>

#define MINIMUM2(x, y) ((x) < (y) ? (x) : (y))

int main() {
  int x, y;

  printf("Insert two numbers: ");
  scanf("%d%d%d", &x, &y, &z);

  printf("%d is the smallest\n", MINIMUM2(x, y));
}
