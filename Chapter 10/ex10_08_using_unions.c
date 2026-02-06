#include <stdio.h>

union integer {
  char c;
  short s;
  int i;
  long b;
};

int main() {
  union integer c, s, i, b;
  printf("Insert a char: \n");
  scanf("%c", &c.c);
  printf("Insert a short: \n");
  scanf("%hd", &s.s);
  printf("Insert an int: \n");
  scanf("%d", &i.i);
  printf("Insert a long: \n");
  scanf("%ld", &b.b);
  printf("Printing the char %c\n", c);
  printf("Char = %c\nShort = %hd\nInt = %i\nLong = %ld\n", c, c, c, c);
  printf("Printing the short %hd\n", s);
  printf("Char = %c\nShort = %hd\nInt = %i\nLong = %ld\n", s, s, s, s);
  printf("Printing the int %d\n", i);
  printf("Char = %c\nShort = %hd\nInt = %i\nLong = %ld\n", i, i, i, i);
  printf("Printing the long int %ld\n", b);
  printf("Char = %c\nShort = %hd\nInt = %i\nLong = %ld\n", b, b, b, b);
  // No, the values won't always be printed correctly.
}
