#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int createSentence(char sentence[35], char const *article[],
                   char const *noun[5][7], char const *verb[],
                   char const *preposition[]);
void createLimericks(char sentence[5][35], char const *noun[5][7],
                     char const *article[], char const *verb[],
                     char const *preposition[]);
void createSentenceRhyme(char sentence[35], char const *article[],
                         char const *noun[5][7], char const *verb[],
                         char const *preposition[], int nounRhymeIndex);

int main() {
  srand(time(NULL));
  char const *article[] = {"the", "a", "one", "some", "any"};
  char const *noun[5][7] = {
      {"boy", "envoy", "toy", "joy", "alloy", "buoy", "convoy"},
      {"girl", "pearl", "curl", "earl", "swirl", "squirrel", "whirl"},
      {"dog", "log", "frog", "fog", "blog", "catalog", "cog"},
      {"town", "crown", "gown", "clown", "frown", "noun", "breakdown"},
      {"car", "star", "jar", "bar", "guitar", "radar", "avatar"}};
  char const *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
  char const *preposition[] = {"to", "from", "over", "under", "on"};
  char sentence[5][35] = {"", "", "", "", ""};
  createLimericks(sentence, noun, article, verb, preposition);
}

int createSentence(char sentence[35], char const *article[],
                   char const *noun[5][7], char const *verb[],
                   char const *preposition[]) {
  int randNums[6];
  static int holdNounNum = -1;
  for (size_t i = 0; i < 6; i++) {
    randNums[i] = rand() % 5;
    if (i == 5) {
      while (holdNounNum == randNums[i]) randNums[i] = rand() % 5;
    }
  }
  holdNounNum = randNums[5];
  strcat(sentence, article[randNums[0]]);
  sentence[0] = toupper(sentence[0]);
  strcat(sentence, " ");
  strcat(sentence, noun[randNums[1]][0]);
  strcat(sentence, " ");
  strcat(sentence, verb[randNums[2]]);
  strcat(sentence, " ");
  strcat(sentence, preposition[randNums[3]]);
  strcat(sentence, " ");
  strcat(sentence, article[randNums[4]]);
  strcat(sentence, " ");
  strcat(sentence, noun[randNums[5]][0]);
  strcat(sentence, ".");
  return randNums[5];
}

void createSentenceRhyme(char sentence[35], char const *article[],
                         char const *noun[5][7], char const *verb[],
                         char const *preposition[], int nounRhymeIndex) {
  int randNums[6];
  static int holdNounNum = -1;
  for (size_t i = 0; i < 6; i++) {
    if (i == 5) {
      randNums[i] = rand() % 6 + 1;
      while (holdNounNum == randNums[i]) randNums[i] = rand() % 6 + 1;
    } else
      randNums[i] = rand() % 5;
  }
  holdNounNum = randNums[5];
  strcat(sentence, article[randNums[0]]);
  sentence[0] = toupper(sentence[0]);
  strcat(sentence, " ");
  strcat(sentence, noun[randNums[1]][0]);
  strcat(sentence, " ");
  strcat(sentence, verb[randNums[2]]);
  strcat(sentence, " ");
  strcat(sentence, preposition[randNums[3]]);
  strcat(sentence, " ");
  strcat(sentence, article[randNums[4]]);
  strcat(sentence, " ");
  strcat(sentence, noun[nounRhymeIndex][randNums[5]]);
  strcat(sentence, ".");
}

void createLimericks(char sentence[5][35], char const *noun[5][7],
                     char const *article[], char const *verb[],
                     char const *preposition[]) {
  int firstLineRhymeIndex =
      createSentence(sentence[0], article, noun, verb, preposition);
  int thirdLineRhymeIndex =
      createSentence(sentence[2], article, noun, verb, preposition);
  createSentenceRhyme(sentence[1], article, noun, verb, preposition,
                      firstLineRhymeIndex);
  createSentenceRhyme(sentence[4], article, noun, verb, preposition,
                      firstLineRhymeIndex);
  createSentenceRhyme(sentence[3], article, noun, verb, preposition,
                      thirdLineRhymeIndex);
  for (size_t i = 0; i < 5; i++) printf("%s\n", sentence[i]);
}
