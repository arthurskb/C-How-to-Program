#include <stdio.h>

void displayBits(unsigned int v);

int main() {
  printf("Insert a positive int: ");
  unsigned int v;
  scanf("%u", &v);
  displayBits(v);
}

void displayBits(unsigned int v) {
  unsigned int mask = 1;
  mask <<= (8*(sizeof(int))-1);
  printf("Value before shift = %u\n", v);
  printf("Value in binary before shift = ");
  for (size_t j = 1; j <= 8*(sizeof(int)); j++) {
    printf("%c", v & mask ? '1' : '0');
    mask >>= 1;
    if(j % 8 == 0) printf(" ");
  }
  printf("\n");
  v >>= 4;
  mask = 1;
  mask <<= (8*(sizeof(int))-1);
  printf("Value after shift = %u\n", v);
  printf("Value in binary after shift =  ");
  for (size_t j = 1; j <= 8*(sizeof(int)); j++) {
    printf("%c", v & mask ? '1' : '0');
    mask >>= 1;
    if(j % 8 == 0) printf(" ");
  }
  printf("\n");
}

//The system replaces vacated bits with 0s if i use a unsigned int mask, and with 1s if i use a signed int mask
