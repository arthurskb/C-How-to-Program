#include <stdio.h>

void writeNumbers(FILE *fPtr, char charNumber[]);

int main() {
  FILE *fPtr;
  if (((fPtr = fopen("words.txt", "w")) == NULL)) {
    printf("Failed to open file\n");
    return 1;
  }
  printf("Insert the number which you would like to see a combination: (Use format XXX-XXXX)\n");
  char number[9];
  fgets(number, 9, stdin);
  number[9] = '\0';
  writeNumbers(fPtr, number);
  fclose(fPtr);
}

void writeNumbers(FILE *fPtr, char charNumber[]) {
  char digit[8][3] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
  long intNumber[7];
  char aux;
  for (size_t i = 0; i < 3; i++) {
    aux = charNumber[i];
    intNumber[i] = aux - '0' - 2;
  }
  for (size_t i = 4; i < 8; i++) {
    aux = charNumber[i];
    intNumber[i-1] = aux - '0' - 2;
  }
  fprintf(fPtr, "The combinations to number %s are:\nThere might be some redundancy if there are repeated digits in the number inserted\n", charNumber);
  int value = 1;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      for (size_t k = 0; k < 3; k++) {
        for (size_t l = 0; l < 3; l++) {
          for (size_t m = 0; m < 3; m++) {
            for (size_t n = 0; n < 3; n++) {
              for (size_t p = 0; p < 3; p++) {
                fprintf(fPtr, "%d - %c%c%c%c%c%c%c\n", value, digit[intNumber[0]][i], digit[intNumber[1]][j], digit[intNumber[2]][k], digit[intNumber[3]][l], digit[intNumber[4]][m], digit[intNumber[5]][n], digit[intNumber[6]][n]);
                value++;
              }
            }
          }
        }
      }
    }
  }
}
