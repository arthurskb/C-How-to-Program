#include <ctype.h>
#include <stdio.h>

void printAll(int c);

int main() {
  printf("%s\n", "Welcome, insert a character: ");
  int c;
  c = getchar();
  printAll(c);
}

void printAll(int c) {
  printf("'%c'%sblank.\n", c, isblank(c) ? " is " : " is not ");
  printf("'%c'%sdigit.\n", c, isdigit(c) ? " is a " : " is not a ");
  printf("'%c'%sletter.\n", c, isalpha(c) ? " is a " : " is not a ");
  printf("'%c'%sdigit or a letter.\n", c, isalnum(c) ? " is a " : " is not a ");
  printf("'%c'%shex digit char.\n", c, isxdigit(c) ? " is a " : " is not a ");
  printf("'%c'%slowercase letter.\n", c, islower(c) ? " is a " : " is not a ");
  printf("'%c'%suppercase letter.\n", c, isupper(c) ? " is a " : " is not an ");
  printf("If '%c' is a lowercase letter, now it is '%c' uppercase.\n", c,
         toupper(c));
  printf("If '%c' is an uppercase letter, now it is '%c' lowercase.\n", c,
         tolower(c));
  printf("'%c'%swhitespace char.\n", c, isspace(c) ? " is a " : " is not a ");
  printf("'%c'%scontrol char.\n", c, iscntrl(c) ? " is a " : " is not a ");
  printf("'%c'%sprinting(other than a space, a letter or a digit) char.\n", c,
         ispunct(c) ? " is a " : " is not a ");
  printf(
      "'%c'%sprinting(it's visible on the screen, including a space) char.\n",
      c, isprint(c) ? " is a " : " is not a ");
  printf(
      "'%c'%sprinting(it's visible on the screen, other than a space) char.\n",
      c, isgraph(c) ? " is a " : " is not a ");
}
