#include <ctype.h>
#include <stdio.h>

#define WORDLEN 26

void countWords(const char *s, int wordLen[]);

int main() {
  int wordLen[WORDLEN] = {0};
  const char a[] = "How many words are writen in this text?";
  countWords(a, wordLen);
  printf("%s\n", a);
  for (size_t i = 1; i < WORDLEN; i++) {
    char c = (char)'a' + i;
    printf("There are %d words of length %ld\n", wordLen[i], i);
  }
}

void countWords(const char *s, int wordLen[]) {
  int aux = 0;
  while (*s != '\0') {
    if (isspace(*s)) {
      wordLen[aux]++;
      aux = 0;
    } else if (isalpha(*s)) {
      aux++;
    }
    s++;
  }
  wordLen[aux]++;
}
