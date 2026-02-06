#include <stdio.h>

int isBlank(int c) {
  if (c == 32) return 1;
  return 0;
}

int isDigit(int c) {
  if ((c >= 48) && (c <= 57)) return 1;
  return 0;
}

int isAlpha(int c) {
  if ((c >= 65) && (c <= 90)) return 1;
  if ((c >= 97) && (c <= 122)) return 1;
  return 0;
}

int isAlNum(int c) {
  if ((c >= 48) && (c <= 57)) return 1;
  if ((c >= 65) && (c <= 90)) return 1;
  if ((c >= 97) && (c <= 122)) return 1;
  return 0;
}

int isXDigit(int c) {
  if ((c >= 48) && (c <= 57)) return 1;
  if ((c >= 65) && (c <= 70)) return 1;
  if ((c >= 97) && (c <= 102)) return 1;
  return 0;
}

int isUpper(int c) {
  if ((c >= 65) && (c <= 90)) return 1;
  return 0;
}

int isLower(int c) {
  if ((c >= 97) && (c <= 122)) return 1;
  return 0;
}

int toUpper(int c) {
  int check = isLower(c);
  if (check) {
    c -= 32;
  }
  return c;
}

int toLower(int c) {
  int check = isUpper(c);
  if (check) {
    c += 32;
  }
  return c;
}

int isSpace(int c) {
  if ((c >= 9) && (c <= 13)) return 1;
  if (c == 32) return 1;
  return 0;
}

int isCntrl(int c) {
  if ((c >= 0) && (c <= 32)) return 1;
  if (c == 127) return 1;
  return 0;
}

int isPunct(int c) {
  if ((c >= 33) && (c <= 47)) return 1;
  if ((c >= 58) && (c <= 64)) return 1;
  if ((c >= 91) && (c <= 96)) return 1;
  if ((c >= 123) && (c <= 126)) return 1;
  return 0;
}

int isPrint(int c) {
  if ((c >= 32) && (c <= 126)) return 1;
  return 0;
}

int isGraph(int c) {
  if ((c >= 33) && (c <= 126)) return 1;
  return 0;
}

void printAll(int c) {
  printf("'%c'%sblank.\n", c, isBlank(c) ? " is " : " is not ");
  printf("'%c'%sdigit.\n", c, isDigit(c) ? " is a " : " is not a ");
  printf("'%c'%sletter.\n", c, isAlpha(c) ? " is a " : " is not a ");
  printf("'%c'%sdigit or a letter.\n", c, isAlNum(c) ? " is a " : " is not a ");
  printf("'%c'%shex digit char.\n", c, isXDigit(c) ? " is a " : " is not a ");
  printf("'%c'%slowercase letter.\n", c, isLower(c) ? " is a " : " is not a ");
  printf("'%c'%suppercase letter.\n", c, isUpper(c) ? " is a " : " is not an ");
  printf("If '%c' is a lowercase letter, now it is '%c' uppercase.\n", c,
         toUpper(c));
  printf("If '%c' is an uppercase letter, now it is '%c' lowercase.\n", c,
         toLower(c));
  printf("'%c'%swhitespace char.\n", c, isSpace(c) ? " is a " : " is not a ");
  printf("'%c'%scontrol char.\n", c, isCntrl(c) ? " is a " : " is not a ");
  printf("'%c'%sprinting(other than a space, a letter or a digit) char.\n", c,
         isPunct(c) ? " is a " : " is not a ");
  printf(
      "'%c'%sprinting(it's visible on the screen, including a space) char.\n",
      c, isPrint(c) ? " is a " : " is not a ");
  printf(
      "'%c'%sprinting(it's visible on the screen, other than a space) char.\n",
      c, isGraph(c) ? " is a " : " is not a ");
}

int main() {
  printf("Insert a char: \n");
  int c = getchar();
  printAll(c);
}
