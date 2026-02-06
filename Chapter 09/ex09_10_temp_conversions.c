#include <stdio.h>

int main() {
  double f;
  printf("Insert the Fahrenheint temperature: (Between 0 and 212 degrees) ");
  scanf("%lf", &f);
  if (f < 0 || f > 212) {
    printf("Invalid input\n");
    return 1;
  }
  double c = 5.0 / 9.0 * (f - 32);
  printf("%10s\n", "Celsius");
  printf("%10.3lf\n", c);
}
