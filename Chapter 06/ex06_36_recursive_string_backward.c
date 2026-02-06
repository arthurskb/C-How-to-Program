#include <stdio.h>

void stringReverse(char string[]);

int main() {
  char string[] = "123456789";
  stringReverse(string);
  printf("\n");
  return 0;
}

void stringReverse(char string[]) {
  char *c = string;
  if (*c == '\0') return;
  string++;
  stringReverse(string);
  printf("%c", *c);
}
