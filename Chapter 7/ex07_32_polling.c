#include <stdio.h>

#define NUM 5
#define PEOPLE 10

void getResponses(char *causes[NUM], int responses[NUM][PEOPLE]);
void getAverage(int responses[NUM][PEOPLE], double average[NUM]);
void getCriticals(int responses[NUM][PEOPLE], int *max, int *maxNUM, int *min,
                  int *minNUM);
void printResponses(int responses[NUM][PEOPLE], char *causes[NUM],
                    double average[NUM], int max, int maxNUM, int min,
                    int minNUM);

int main() {
  char *causes[NUM] = {"Education", "Healthcare", "Nature Preservation",
                       "Economy", "Safety"};
  int responses[NUM][PEOPLE];
  getResponses(causes, responses);
  double average[NUM] = {0};
  getAverage(responses, average);
  int max, min, maxNUM, minNUM;
  getCriticals(responses, &max, &maxNUM, &min, &minNUM);
  printResponses(responses, causes, average, max, maxNUM, min, minNUM);
}

void getResponses(char *causes[NUM], int responses[NUM][PEOPLE]) {
  printf(
      "%s\n",
      "Welcome, the goal of this program, is to rate five social-consciousness "
      "issues, from 1(least important) to 10(most important).");
  for (size_t i = 0; i < PEOPLE; i++) {
    printf("%s%ld%s\n", "You are the ", i + 1,
           "º person! Now, rate each issue:");
    for (size_t j = 0; j < NUM; j++) {
      printf("%s%s", causes[j], ": ");
      scanf("%d", &responses[j][i]);
    }
  }
}

void getAverage(int responses[NUM][PEOPLE], double average[NUM]) {
  for (size_t i = 0; i < NUM; i++) {
    for (size_t j = 0; j < PEOPLE; j++) {
      average[i] += responses[i][j];
    }
    average[i] /= PEOPLE;
  }
}

void getCriticals(int responses[NUM][PEOPLE], int *max, int *maxNUM, int *min,
                  int *minNUM) {
  int sum[5] = {0};
  for (size_t i = 0; i < NUM; i++) {
    for (size_t j = 0; j < PEOPLE; j++) {
      sum[i] += responses[i][j];
    }
  }
  *max = sum[0];
  *min = sum[0];
  *maxNUM = 0;
  *minNUM = 0;
  for (size_t i = 1; i < NUM; i++) {
    if (sum[i] > *max) {
      *max = sum[i];
      *maxNUM = i;
    }
    if (sum[i] < *min) {
      *min = sum[i];
      *minNUM = i;
    }
  }
}

void printResponses(int responses[NUM][PEOPLE], char *causes[NUM],
                    double average[NUM], int max, int maxNUM, int min,
                    int minNUM) {
  printf("\nTable of Responses:\n");
  printf("%21s", " ");
  for (size_t i = 0; i < PEOPLE; i++) printf("%s%ld%-4s", " ", (i + 1), "º");
  printf("%4s", "AVG");
  printf("\n");
  for (size_t i = 0; i < NUM; i++) {
    printf("%-19s", causes[i]);
    for (size_t j = 0; j < PEOPLE; j++) {
      printf("%3s%02d", " ", responses[i][j]);
    }
    printf("%4s%.2lf", " ", average[i]);
    printf("\n");
  }
  printf("%s%s%s%d%s\n", "The highest rated cause was: ", causes[maxNUM],
         " with ", max, " total evaluation.");
  printf("%s%s%s%d%s\n", "The lowest rated cause was: ", causes[minNUM],
         " with ", min, " total evaluation.");
}
