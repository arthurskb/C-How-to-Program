#include <ctype.h>
#include <stdio.h>
#include <string.h>

void sort(char array[][12], int size, int order[]);
void alphabetize(char *names[], char *alphabetizedNames[]);
void adjustNames(char name[]);

int main() {
  char *names[] = {"London",    "Paris",   "New York", "Madrid",   "New Mexico",
                   "Sao Paulo", "Toronto", "Pequim",   "Istambul", "Budapeste"};
  char *alphabetizedNames[10];
  alphabetize(names, alphabetizedNames);
}

void sort(char array[][12], int size, int order[]) {
  int cmpValue, holdValue;
  char holdChar[12];
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = i + 1; j < size; j++) {
      cmpValue = strncmp(array[i], array[j], 1);
      if (cmpValue == 0) {
        int index = 2;
        while (cmpValue == 0) {
          cmpValue = strncmp(array[i], array[j], index);
          index++;
        }
      }
      if (cmpValue > 0) {
        holdValue = order[j];
        strcpy(holdChar, array[j]);
        order[j] = order[i];
        strcpy(array[j], array[i]);
        order[i] = holdValue;
        strcpy(array[i], holdChar);
      }
    }
  }
}

void alphabetize(char *names[], char *alphabetizedNames[]) {
  char auxNames[10][12];
  int order[10];
  for (size_t i = 0; i < 10; i++) strcpy(auxNames[i], names[i]);
  for (size_t i = 0; i < 10; i++) adjustNames(auxNames[i]);
  for (size_t i = 0; i < 10; i++) order[i] = i;
  sort(auxNames, 10, order);
  for (size_t i = 0; i < 10; i++) {
    alphabetizedNames[i] = names[order[i]];
    printf("%s\n", alphabetizedNames[i]);
  }
}

void adjustNames(char name[]) {
  int size = strlen(name);
  int count = 1;
  for (size_t i = 0; i < size + 1; i++) {
    if (name[i] == ' ') {
      for (size_t j = i; j < size + 1 - count; j++) {
        name[j] = name[j + 1];
      }
      count++;
    }
  }
  for (size_t i = 0; i < size; i++) name[i] = tolower(name[i]);
}
