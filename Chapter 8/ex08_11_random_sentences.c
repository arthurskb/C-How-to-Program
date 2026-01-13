#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void createSentence(char sentence[35], char const *article[],
                    char const *noun[], char const *verb[],
                    char const *preposition[]);

int main() {
  srand(time(NULL));
  char const *article[] = {"the", "a", "one", "some", "any"};
  char const *noun[] = {"boy", "girl", "dog", "town", "car"};
  char const *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
  char const *preposition[] = {"to", "from", "over", "under", "on"};
  printf("Generating 20 random sentences:\n");
  for (size_t i = 0; i < 20; i++) {
    char sentence[35] = "";
    createSentence(sentence, article, noun, verb, preposition);
    printf("%s\n", sentence);
  }
  printf("\nNow, generating a random text:\n");
  int paragraphs = rand() % 5 + 5;
  int sentences;
  for (size_t i = 0; i < paragraphs; i++) {
    sentences = rand() % 20 + 10;
    printf("  ");
    for (size_t j = 0; j < sentences; j++) {
      char sentence[35] = "";
      createSentence(sentence, article, noun, verb, preposition);
      printf("%s ", sentence);
    }
    printf("\n");
  }
}

void createSentence(char sentence[35], char const *article[],
                    char const *noun[], char const *verb[],
                    char const *preposition[]) {
  int randNums[6];
  for (size_t i = 0; i < 6; i++) {
    randNums[i] = rand() % 5;
  }
  strcat(sentence, article[randNums[0]]);
  sentence[0] = toupper(sentence[0]);
  strcat(sentence, " ");
  strcat(sentence, noun[randNums[1]]);
  strcat(sentence, " ");
  strcat(sentence, verb[randNums[2]]);
  strcat(sentence, " ");
  strcat(sentence, preposition[randNums[3]]);
  strcat(sentence, " ");
  strcat(sentence, article[randNums[4]]);
  strcat(sentence, " ");
  strcat(sentence, noun[randNums[5]]);
  strcat(sentence, ".");
}
