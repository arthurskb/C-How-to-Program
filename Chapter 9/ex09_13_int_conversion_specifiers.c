#include <stdio.h>

int main() {
  int d, i, o, x, u;

  printf("Please input the number 437 five times, pressing Enter after each insertion:\n");
  scanf("%d", &d);
  scanf("%i", &i);
  scanf("%o", &o);
  scanf("%x", &x);
  scanf("%u", &u);

  printf("------------------------------------------------------------\n");
  printf("Specifier | Decimal | Octal | Hex (lower) | Hex (UPPER)\n");
  printf("------------------------------------------------------------\n");
  printf("Scanned %%d:%6d%9o%11x%14X\n", d, d, d, d);
  printf("Scanned %%i:%6d%9o%11x%14X\n", i, i, i, i);
  printf("Scanned %%o:%6d%9o%11x%14X\n", o, o, o, o);
  printf("Scanned %%x:%6d%9o%11x%14X\n", x, x, x, x);
  printf("Scanned %%u:%6d%9o%11x%14X\n", u, u, u, u);

}
