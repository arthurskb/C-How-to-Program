#include <stdio.h>

#define NUM 4

void displayBits(unsigned int v);
void packCharacters(char c[NUM], unsigned int *var);
void clearInputBuffer();

int main() {
  char c[NUM];
  for (size_t i = 0; i < NUM; i++) {
    printf("Insert the %ld character: ", i+1);
    c[i] = getchar();
    clearInputBuffer();
  }
  printf("\n");
  for (size_t i = 0; i < NUM; i++) {
    printf("The character %c = ", c[i]);
    displayBits(c[i]);
  }
  unsigned int var;
  packCharacters(c, &var);
  printf("The packed unsigned int = ");
  displayBits(var);
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

void packCharacters(char c[NUM], unsigned int *var) {
  *var = c[0];
  for (size_t i = 1; i < NUM; i++) {
    *var <<= NUM*2;
    *var = *var | c[i];
  }
}

void clearInputBuffer() {
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}
