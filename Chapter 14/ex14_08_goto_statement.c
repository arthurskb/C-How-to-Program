#include <stdio.h>

int main() {
  int i = 0, j = 0, k = 0, p = 0;
asterisk:
  printf("%s", "*");
  i++;
  if (k == 1) {
    if (p == 3) {
      p = 0;
      goto endline;
    }
    goto whitespace;
  }
  if (i == 5) {
    k++;
    goto endline;
  }
  goto asterisk;
whitespace:
  printf("%s", " ");
  p++;
  if (p == 3) {
    goto asterisk;
  }
  goto whitespace;
endline:
  printf("%s", "\n");
  i = 0;
  j++;
  if (j == 4) {
    k = 0;
  }
  if (j != 5) {
    goto asterisk;
  }
}
