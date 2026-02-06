#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLENGTH 201

void readString(char string[]);
void processAscii(char ascii[], int len);

int main() {
  printf(
      "Insert ASCII Code text, using hexadecimals and XX model: (MAX 100 "
      "Characters)\n");
  char ascii[MAXLENGTH];
  readString(ascii);
  int length = strlen(ascii);
  int flag = 0;
  for (size_t i = 0; i < length; i++) {
    if (!isxdigit(ascii[i])) {
      flag = 1;
      break;
    }
  }
  if ((strlen(ascii) % 2 != 0) || flag) {
    printf("Invalid Input\n");
    return 1;
  }
  processAscii(ascii, length);
}

void processAscii(char ascii[], int len) {
  char digit[2];
  int hex;
  for (int i = 0; i < len; i += 2) {
    digit[0] = ascii[i];
    digit[1] = ascii[i + 1];
    sscanf(digit, "%x", &hex);
    printf("%c", hex);
  }
  printf("\n");
}

void readString(char string[]) {
  fgets(string, MAXLENGTH, stdin);
  int length = strlen(string);
  string[length - 1] = '\0';
}
