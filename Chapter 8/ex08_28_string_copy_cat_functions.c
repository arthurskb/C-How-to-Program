#include <stdio.h>

char *strcpy(char *s1, const char *s2);
char *strcpya(char s1[], const char s2[]);
char *strcat(char *s1, const char *s2);
char *strcata(char s1[], const char s2[]);

int main() {
  char a[] = "testing a";
  char b[11];
  printf("a = %s\n", a);
  printf("b = %s\n", b);
  printf("b copied = %s\n", strcpy(b, a));
  printf("b = %s\n", b);
  char c[] = "testing c";
  char d[11];
  printf("c = %s\n", c);
  printf("d = %s\n", d);
  printf("d copied = %s\n", strcpya(d, c));
  printf("d = %s\n", d);
  char e[22] = "testing e";
  printf("e = %s\n", e);
  printf("e concatenated with d = %s\n", strcat(e, d));
  printf("e = %s\n", e);
  char f[22] = "testing f";
  printf("f = %s\n", f);
  printf("f concatenated with b = %s\n", strcat(f, b));
  printf("f = %s\n", f);
}

char *strcpy(char *s1, const char *s2) {
  char *aux;
  aux = s1;
  while (*s2 != '\0') {
    *s1 = *s2;
    s1++;
    s2++;
  }
  *s1 = '\0';
  return aux;
}

char *strcpya(char s1[], const char s2[]) {
  int i = 0;
  while (s2[i] != '\0') {
    s1[i] = s2[i];
    i++;
  }
  s1[i] = '\0';
  return s1;
}

char *strcat(char *s1, const char *s2) {
  char *aux;
  aux = s1;
  while (*s1 != '\0') {
    s1++;
  }
  while (*s2 != '\0') {
    *s1 = *s2;
    s1++;
    s2++;
  }
  *s1 = '\0';
  return aux;
}

char *strcata(char s1[], const char s2[]) {
  int i = 0;
  while (s1[i] != '\0') {
    i++;
  }
  while (s2[i] != '\0') {
    s1[i] = s2[i];
    i++;
  }
  s1[i] = '\0';
  return s1;
}
