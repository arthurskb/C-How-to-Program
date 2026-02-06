#include <stdio.h>

size_t strlen(const char *s);
size_t strlena(const char s[]);

int main() {
  char a[] = "The length is: ";
  char b[] = "Thelengthis:";
  printf("%s %ld\n", a, strlen(a));
  printf("%s %ld\n", b, strlen(b));
  printf("%s %ld\n", a, strlena(a));
  printf("%s %ld\n", b, strlena(b));
}

size_t strlen(const char *s) {
  size_t len = 0;
  for (; *s != '\0'; s++) len++;
  return len;
}

size_t strlena(const char s[]) {
  size_t len;
  for (len = 0; s[len] != '\0'; len++);
  return len;
}
