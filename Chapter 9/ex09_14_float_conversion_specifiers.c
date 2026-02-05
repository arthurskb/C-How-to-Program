#include <stdio.h>

int main() {
  float e, f, g;
  printf("Please input the number 1.2345 three times, pressing Enter after each insertion:\n");
  scanf("%e", &e);
  scanf("%f", &f);
  scanf("%g", &g);
  printf("-------------------------------------------------\n");
  printf("Specifier   | Printing e | Printing f | Printing g  \n");
  printf("-------------------------------------------------\n");
  printf("Scanned %%e:%14e%12f%11g\n", e, e, e);
  printf("Scanned %%f:%14e%12f%11g\n", f, f, f);
  printf("Scanned %%g:%14e%12f%11g\n", g, g, g);
}
