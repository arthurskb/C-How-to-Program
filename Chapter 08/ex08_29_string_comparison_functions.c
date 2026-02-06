#include <stdio.h>

int strcmp(const char *s1, const char *s2);
int strcmpa(const char s1[], const char s2[]);
int strncmp(const char *s1, const char *s2, size_t n);
int strncmpa(const char s1[], const char s2[], size_t n);

int main() {
  char a[] = "This is a message";
  char b[] = "This is a message";
  char c[] = "This is a mess!!!";
  printf("'%s' and '%s' = %d\n", a, b, strcmp(a, b));
  printf("'%s' and '%s' = %d\n", a, c, strcmp(a, c));
  printf("'%s' and '%s' = %d\n", a, b, strcmpa(a, b));
  printf("'%s' and '%s' = %d\n", b, c, strcmpa(b, c));
  printf("'%s' and '%s' up to 10 chars = %d\n", b, c, strncmp(b, c, 10));
  printf("'%s' and '%s' up to 15 chars = %d\n", b, c, strncmpa(b, c, 15));
  printf("'%s' and '%s' up to 10 chars = %d\n", b, c, strncmp(b, c, 10));
  printf("'%s' and '%s' up to 15 chars = %d\n", b, c, strncmpa(b, c, 15));
}

int strcmp(const char *s1, const char *s2) {
  int s1sum = 0;
  int s2sum = 0;
  while (*s1 != '\0') {
    int num = *s1;
    s1sum += num;
    s1++;
  }
  while (*s2 != '\0') {
    int num = *s2;
    s2sum += num;
    s2++;
  }
  return s1sum - s2sum;
}

int strcmpa(const char s1[], const char s2[]) {
  int s1sum = 0;
  int s2sum = 0;
  for (size_t i = 0; s1[i] != '\0'; i++) {
    int num = s1[i];
    s1sum += num;
  }
  for (size_t i = 0; s2[i] != '\0'; i++) {
    int num = s2[i];
    s2sum += num;
  }
  return s1sum - s2sum;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  int s1sum = 0;
  int s2sum = 0;
  for (size_t i = 0; i <= n; i++) {
    if (*s1 == '\0') break;
    int num = *s1;
    s1sum += num;
    s1++;
  }
  for (size_t i = 0; i <= n; i++) {
    if (*s2 == '\0') break;
    int num = *s2;
    s2sum += num;
    s2++;
  }
  return s1sum - s2sum;
}

int strncmpa(const char s1[], const char s2[], size_t n) {
  int s1sum = 0;
  int s2sum = 0;
  for (size_t i = 0; i <= n; i++) {
    if (s1[i] == '\0') break;
    int num = s1[i];
    s1sum += num;
  }
  for (size_t i = 0; i <= n; i++) {
    if (s2[i] == '\0') break;
    int num = s2[i];
    s2sum += num;
  }
  return s1sum - s2sum;
}
