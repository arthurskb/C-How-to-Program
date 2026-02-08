#include <stdio.h>

#define NUM 4

void displayBits(unsigned int v);

int main() {
  printf("Insert the unsigned int to display it: ");
  unsigned int v;
  scanf("%u", &v);
  printf("The unsigned int in bits = ");
  displayBits(v);
}

void displayBits(unsigned int v) {
  unsigned int mask = 1;
  mask <<= (8*(sizeof(int))-1);
  for (size_t j = 1; j <= 8*(sizeof(int)); j++) {
    printf("%c", v & mask ? '1' : '0');
    mask >>= 1;
    if(j % 8 == 0) printf(" ");
  }
  printf("\n");
}
