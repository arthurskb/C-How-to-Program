#include <stdio.h>

#define NUM 4

unsigned int reverseBits(unsigned int v);
void displayBits(unsigned int v);
void displayCBits(char v);

int main() {
  printf("Insert the unsigned int to reverse it: ");
  unsigned int v;
  scanf("%u", &v);
  printf("The unsigned int in bits = ");
  displayBits(v);
  unsigned int reversed_v = reverseBits(v);
  printf("The reversed unsigned int in bits = ");
  displayBits(reversed_v);
}

unsigned int reverseBits(unsigned int v) {
  unsigned int mask = 255;
  unsigned int reversed = 0;
  char aux;
  printf("Mask = ");
  displayBits(mask);
  aux = (v & mask);
  printf("Aux = ");
  displayCBits(aux);
  reversed |= aux;
  printf("Reversed = ");
  displayBits(reversed);
  for (size_t i = 1; i < NUM; i++) {
    mask <<= NUM*2;
    printf("Mask = ");
    displayBits(mask);
    aux = (v & mask) >> NUM*2*(i);
    printf("Aux = ");
    displayCBits(aux);
    reversed <<= NUM*2;
    reversed |= aux;
    printf("Reversed = ");
    displayBits(reversed);
  }
  return reversed;
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

void displayCBits(char v) {
  unsigned int mask = 1;
  mask <<= (8*(sizeof(char))-1);
  for (size_t j = 1; j <= 8*(sizeof(char)); j++) {
    printf("%c", v & mask ? '1' : '0');
    mask >>= 1;
    if(j % 8 == 0) printf(" ");
  }
  printf("\n");
}
