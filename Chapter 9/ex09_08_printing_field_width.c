#include <stdio.h>

int main() {
  printf("%10d\n", 12345);
  printf("%-10d\n", 12345);
  printf("%3d\n", 12345); //value is entirely printed, the field width is basically ignored
  printf("%-3d\n", 12345); //value is entirely printed, the field width is basically ignored
  printf("%10f\n", 1.2345);
  printf("%-10f\n", 1.2345);
  printf("%3f\n", 1.2345); //value is entirely printed, the field width is basically ignored
  printf("%-3f\n", 1.2345); //value is entirely printed, the field width is basically ignored
}
