#include <stdio.h>

void displayBits(unsigned int v);
void power2(unsigned int *number, unsigned int pow);

int main() {
  printf("Welcome to power 2 program, insert the initial number: ");
  unsigned int number;
  scanf("%u", &number);
  printf("Now, insert the pow argument: ");
  unsigned int pow;
  scanf("%u", &pow);
  printf("Value before pow2 = %u\n", number);
  displayBits(number);
  power2(&number, pow);
  printf("Value after pow2 = %u\n", number);
  displayBits(number);
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

void power2(unsigned int *number, unsigned int pow) {
  (*number) <<= pow;
}
