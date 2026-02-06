#include <ctype.h>
#include <stdio.h>

#define ALPHANUM 26

void countLetters(const char *s, int alphabet[]);

int main() {
  int alphabet[ALPHANUM] = {0};
  const char a[] = "How many letters?";
  countLetters(a, alphabet);
  printf("%s\n", a);
  for (size_t i = 0; i < ALPHANUM; i++) {
    char c = (char)'a' + i;
    printf("There are %d of the letter %c\n", alphabet[i], c);
  }
}

void countLetters(const char *s, int alphabet[]) {
  while (*s != '\0') {
    if (isalpha(*s)) {
      int letter = tolower(*s) - 'a';
      alphabet[letter]++;
    }
    s++;
  }
}
