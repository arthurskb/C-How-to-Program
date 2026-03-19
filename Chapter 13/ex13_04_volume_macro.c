#include <stdio.h>

#define PI 3.14159

#define SPHERE_VOLUME(r) ((4.0 / 3) * PI * (r * r * r))

int main() {
  double volume[10];
  for (size_t i = 0; i < 10; i++) {
    double r = (double)i;
    volume[i] = SPHERE_VOLUME(r);
  }
  printf("%s%10s\n", "RADIUS", "VOLUME");
  for (size_t i = 0; i < 10; i++) {
    printf("%6d%10.2lf\n", i + 1, volume[i]);
  }
}
