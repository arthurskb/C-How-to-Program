#include <stdio.h>

union floatingPoint {
  float f;
  double d;
  long double x;
};

int main() {
  union floatingPoint f, d, x;
  printf("Insert a float: ");
  scanf("%f", &f.f);
  printf("Insert a double: ");
  scanf("%lf", &d.d);
  printf("Insert a long double: ");
  scanf("%Lf", &x.x);
  printf("\nPrinting the float %f\n", f);
  printf("Float = %f\nDouble = %lf\nLong Double = %Lf\n", f, f, f);
  printf("\nPrinting the double %lf\n", d);
  printf("Float = %f\nDouble = %lf\nLong Double = %Lf\n", d, d, d);
  printf("\nPrinting the long double %Lf\n", x);
  printf("Float = %f\nDouble = %lf\nLong Double = %Lf\n", x, x, x);
  //No, the values won't print correctly.
}
