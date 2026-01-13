#include <stdio.h>
#include <string.h>

#define MAXLENGTH 100

void readString(char str[]);
void printStringInfo(char str[]);

int main() {
  char s1[MAXLENGTH];
  char s2[MAXLENGTH];
  readString(s1);
  readString(s2);
  printStringInfo(s1);
  printStringInfo(s2);
  unsigned int num;
  int max = strlen(s2);
  printf(
      "How many characters of the second string, would you like to concatenate "
      "to the first one? (Max = %d)\n",
      max);
  scanf("%u", &num);
  if (num > max) {
    printf("The number inserted exceeds the maximum, program terminated.\n");
    return 1;
  }
  strncat(s1, s2, num);
  printStringInfo(s1);
}

void readString(char str[]) {
  printf("%s",
         "Insert a one-line string to be read: (Max size = 49 characters)\n");
  fgets(str, 50, stdin);
  int num = strlen(str);
  str[num - 1] = '\0';
}

void printStringInfo(char str[]) {
  printf("%s%s%s%lu%s", "The string is:\n", str, "\nWith a length of ",
         strlen(str), " characters.\n");
}
