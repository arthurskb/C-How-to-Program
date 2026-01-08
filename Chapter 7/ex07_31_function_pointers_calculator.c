#include <stdio.h>

void add(double a, double b);
void sub(double a, double b);
void mul(double a, double b);
void div(double a, double b);

int main() {
  void (*functionPtr[4])(double, double) = {add, sub, mul, div};
  printf("Welcome, select which operation to perform:\n");
  printf("1 = +\n2 = -\n3 = *\n4 = /\n");
  int choice;
  scanf("%d", &choice);
  if (choice > 0 && choice <= 4) {
    double a, b;
    printf("Insert first number: ");
    scanf("%lf", &a);
    printf("Insert second number: ");
    scanf("%lf", &b);
    (*functionPtr[choice - 1])(a, b);
  } else
    printf("Invalid option, program terminated.\n");
}

void add(double a, double b) {
  double result = a + b;
  printf("%lf%s%lf%s%lf\n", a, " + ", b, " = ", result);
}

void sub(double a, double b) {
  double result = a - b;
  printf("%lf%s%lf%s%lf\n", a, " - ", b, " = ", result);
}
void mul(double a, double b) {
  double result = a * b;
  printf("%lf%s%lf%s%lf\n", a, " * ", b, " = ", result);
}
void div(double a, double b) {
  double result = a / b;
  printf("%lf%s%lf%s%lf\n", a, " / ", b, " = ", result);
}
