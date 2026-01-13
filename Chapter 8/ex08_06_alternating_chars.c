#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100

void alternateLetters(char s[SIZE]);

int main() {
  printf("Insert some text: ");
  char s[SIZE];
  fgets(s, SIZE, stdin);
  alternateLetters(s);
}

void alternateLetters(char s[SIZE]) {
  for (size_t i = 0; i < strlen(s); i++) {
    if (i % 2 == 0)
      printf("%c", toupper(s[i]));
    else
      printf("%c", tolower(s[i]));
  }
}
