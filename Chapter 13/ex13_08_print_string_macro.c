#include <stdio.h>

#define PRINT(x) printf(x)
#define PRINT2(x) printf(#x)

int main() {
  char sent[] = "HI TESTING\n";
  PRINT(sent);
  PRINT2(sent);
}
