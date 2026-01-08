#include <stdio.h>

void circumference(double radius);
void area(double radius);
void volume(double radius);

int main() {
  void (*functionPtr[3])(double) = {circumference, area, volume};
  printf("%s", "Hi, select which calculation to perform:\n1 - circumference\n2 - area\n3 - volume\n");
  int choice = 0;
  scanf("%d", &choice);
  if (choice > 0 && choice <= 3) {
    printf("Insert the radius to be calculated\n");
    double radius;
    scanf("%lf", &radius);
    (*functionPtr[choice-1])(radius);
  }
  else printf("Invalid choice, program terminated.\n");
}

void circumference(double radius) {
  double result = radius * 2 * 3.14;
  printf("%s%lf\n%s%lf\n", "Radius = ", radius, "Circumference = ", result);
}

void area(double radius) {
  double result = radius * radius * 3.14;
  printf("%s%lf\n%s%lf\n", "Radius = ", radius, "Area = ", result);
}

void volume(double radius) {
  double result = radius * radius * radius * 3.14;
  result = result * 4;
  result = result / 3;
  printf("%s%lf\n%s%lf\n", "Radius = ", radius, "Volume = ", result);
}
