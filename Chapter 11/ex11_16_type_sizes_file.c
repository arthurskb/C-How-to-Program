#include <stdio.h>

void printDataSize(FILE *fPtr);

int main() {
  FILE *fPtr;
  if ((fPtr = fopen("data-size.dat", "w")) == NULL) {
    printf("Error opening the file\n");
    return 1;
  }
  printDataSize(fPtr);
  fclose(fPtr);
}

void printDataSize(FILE *fPtr) {
  fprintf(fPtr, "%-25s%s\n", "Data Type", "Size");
  fprintf(fPtr, "%-25s%4lu\n", "char", sizeof(char));
  fprintf(fPtr, "%-25s%4lu\n", "unsigned char", sizeof(unsigned char));
  fprintf(fPtr, "%-25s%4lu\n", "short int", sizeof(short int));
  fprintf(fPtr, "%-25s%4lu\n", "unsigned short int", sizeof(unsigned short int));
  fprintf(fPtr, "%-25s%4lu\n", "int", sizeof(int));
  fprintf(fPtr, "%-25s%4lu\n", "unsigned int", sizeof(unsigned int));
  fprintf(fPtr, "%-25s%4lu\n", "long int", sizeof(long int));
  fprintf(fPtr, "%-25s%4lu\n", "unsigned long int", sizeof(unsigned long int));
  fprintf(fPtr, "%-25s%4lu\n", "float", sizeof(float));
  fprintf(fPtr, "%-25s%4lu\n", "double", sizeof(double));
  fprintf(fPtr, "%-25s%4lu\n", "long double", sizeof(long double));
}
