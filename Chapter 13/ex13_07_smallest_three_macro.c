#include <stdio.h>

#define MINIMUM2(x, y) ((x) < (y) ? (x) : (y))
#define MINIMUM3(x, y, z) (MINIMUM2(MINIMUM2(x, y), z))

int main() {
  int x, y, z;

  printf("Insert three numbers: ");
  scanf("%d%d%d", &x, &y, &z);

  printf("%d is the smallest\n", MINIMUM3(x, y, z));
}
