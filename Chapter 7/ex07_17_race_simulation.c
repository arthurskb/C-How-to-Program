#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 70

int moveHare(int *harePosition);
int moveTortoise(int *tortoisePosition);
void printPositions(const unsigned int harePosition, const unsigned int tortoisePosition);

int main() {
  srand(time(NULL));
  int harePosition = 0;
  int tortoisePosition = 0;
  printf("BANG !!!!!\nAND THEY'RE OFF !!!!!\n");
  do {
    moveHare(&harePosition);
    moveTortoise(&tortoisePosition);
    printPositions(harePosition, tortoisePosition);
  } while ((harePosition < SIZE) && (tortoisePosition < SIZE));
  if ((harePosition >= SIZE) && (tortoisePosition >= SIZE)) {
    printf("It's a tie.\n");
  } else if (harePosition >= SIZE) {
    printf("Hare wins. Yuch.\n");
  } else {
    printf("TORTOISE WINS!!! YAY!!!\n");
  }
}

int moveHare(int *harePosition) {
  int movement = rand() % 10;
  if (movement < 2) {
    *harePosition += 9;
  } else if (movement < 3) {
    *harePosition -= 12;
  } else if (movement < 6) {
    *harePosition += 1;
  } else if (movement < 8) {
    *harePosition -= 2;
  }
  if (*harePosition < 0) *harePosition = 0;
}

int moveTortoise(int *tortoisePosition) {
  int movement = rand() % 10;
  if (movement < 5) {
    *tortoisePosition += 3;
  } else if (movement < 7) {
    *tortoisePosition -= 6;
  } else {
    *tortoisePosition += 1;
  }
  if (*tortoisePosition < 0) *tortoisePosition = 0;
}

void printPositions(const unsigned int harePosition, const unsigned int tortoisePosition) {
  for (size_t i = 0; i < SIZE; i++) {
    if ((i == harePosition) && (i == tortoisePosition)) {
      printf(" OUCH!!!");
    } else if (i == harePosition) {
      printf("H");
    } else if (i == tortoisePosition) {
      printf("T");
    } else {
      printf(" ");
    }
  }
  if (harePosition >= SIZE) {
    printf("H");
  }
  if (tortoisePosition >= SIZE) {
    printf("T");
  }
  printf("\n");
}
