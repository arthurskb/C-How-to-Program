#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define WORDLEN 26
#define WORDID 200

void countWords(const char *s, int wordCounter[WORDID],
                char holdWords[WORDID][WORDLEN], int *wordCounterAux);

int main() {
  int wordCounter[WORDID] = {0};
  int wordCounterAux = 0;
  char holdWords[WORDID][WORDLEN];
  for (size_t i = 0; i < WORDID; i++) holdWords[i][0] = '\0';
  const char a[] =
      "There is a huge frequency huge frequency huge frequency huge "
      "happenning.";
  countWords(a, wordCounter, holdWords, &wordCounterAux);
  printf("%s\n", a);
  printf("%-26s%s\n", "Word:", "Ocurrencies:");
  printf("\n");
  for (size_t i = 0; i < wordCounterAux; i++) {
    printf("%-26s%6d\n", holdWords[i], wordCounter[i]);
  }
}

void countWords(const char *s, int wordCounter[WORDID],
                char holdWords[WORDID][WORDLEN], int *wordCounterAux) {
  int aux = 0;
  char holdCurrentWord[WORDLEN];
  char *current = NULL;
  while (*s != '\0') {
    aux = 0;
    if (isalnum(*s) || *s == '\'') {
      current = (char *)s;
      s++;
      aux++;
      while (isalnum(*s) || *s == '\'') {
        s++;
        aux++;
      }
      size_t i = 0;
      for (; i < aux; i++) {
        holdCurrentWord[i] = tolower(*current);
        current++;
      }
      holdCurrentWord[i] = '\0';
      int flagExistingWord = 0;
      size_t j = 0;
      for (; j < *wordCounterAux; j++) {
        int strCMP = strcmp(holdCurrentWord, holdWords[j]);
        if (strCMP == 0) {
          wordCounter[j]++;
          flagExistingWord++;
          break;
        }
      }
      if (!flagExistingWord) {
        strcpy(holdWords[j], holdCurrentWord);
        wordCounter[j]++;
        *wordCounterAux += 1;
      }
    }
    s++;
  }
}
