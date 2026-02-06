#include <stdio.h>

int isDigit(int c);
int isSpace(int c);
int isAlpha(int c);
int isLower(int c);
int toUpper(int c);
double strtod(const char *nPtr, char **endPtr);
long strtol(const char *nPtr, char **endPtr, int base);
unsigned long strtoul(const char *nPtr, char **endPtr, int base);

int main() {
  const char *str = "Hello -testing-123.24daaaaaaa";
  char *strPtr = NULL;
  double d = strtod(str, &strPtr);
  printf("The string is %s\n", str);
  printf("The number is %lf and the rest of the string is %s\n", d, strPtr);
  str = "        -53A2Ehellohello";
  long c = strtol(str, &strPtr, 16);
  printf("The string is %s\n", str);
  printf("The number is %ld and the rest of the string is %s\n", c, strPtr);
  str = "  62testing hi";
  unsigned long b = strtoul(str, &strPtr, 0);
  printf("The string is %s\n", str);
  printf("The number is %lu and the rest of the string is %s\n", b, strPtr);
  str = "  -62testing hi";
  b = strtoul(str, &strPtr, 0);
  printf("The string is %s\n", str);
  printf("The number is %lu and the rest of the string is %s\n", b, strPtr);
}

int isLower(int c) {
  if ((c >= 97) && (c <= 122)) return 1;
  return 0;
}

int toUpper(int c) {
  int check = isLower(c);
  if (check) {
    c -= 32;
  }
  return c;
}

int isDigit(int c) {
  if ((c >= 48) && (c <= 57)) return 1;
  return 0;
}

int isSpace(int c) {
  if ((c >= 9) && (c <= 13)) return 1;
  if (c == 32) return 1;
  return 0;
}

int isAlpha(int c) {
  if ((c >= 65) && (c <= 90)) return 1;
  if ((c >= 97) && (c <= 122)) return 1;
  return 0;
}

double strtod(const char *nPtr, char **endPtr) {
  if (nPtr == NULL) return 0;
  int flag = 0;
  char *numStart;
  *endPtr = (char *)nPtr;
  int c = **endPtr;
  while (c != '\0') {
    if (c == '-') {
      int next = (*endPtr)[1];
      if (isDigit(next) || (next == '.')) {
        numStart = *endPtr;
        flag = 1;
        (*endPtr)++;
        c = **endPtr;
        while ((isDigit(c)) || (c == '.')) {
          (*endPtr)++;
          c = **endPtr;
        }
        break;
      }
    }
    if (isDigit(c)) {
      numStart = *endPtr;
      flag = 1;
      while ((isDigit(c)) || (c == '.')) {
        (*endPtr)++;
        c = **endPtr;
      }
      break;
    }
    (*endPtr)++;
    c = **endPtr;
  }
  double result = 0;
  if (flag) {
    sscanf(numStart, "%lf", &result);
  }
  return result;
}

long strtol(const char *nPtr, char **endPtr, int base) {
  if (nPtr == NULL) return 0;
  char *aux = (char *)nPtr;
  int flagNegative = 0;
  int flagValidNumber = 0;
  long result = 0;
  while (isSpace(*aux)) aux++;

  if (*aux == '-') {
    flagNegative = 1;
    aux++;
  }

  if ((base == 0 || base == 16) && *aux == '0' &&
      (*(aux + 1) == 'x' || *(aux + 1) == 'X')) {
    aux += 2;
    base = 16;
  }
  if (base == 0) {
    base = (*aux == '0') ? 8 : 10;
  }

  for (;; aux++) {
    int digit;
    if (isDigit(*aux)) {
      digit = *aux - '0';
    } else if (isAlpha(*aux)) {
      digit = toUpper(*aux);
      digit = digit - 'A' + 10;
    } else
      break;

    if (digit >= base) break;

    flagValidNumber = 1;
    result = result * base + digit;
  }

  if (*endPtr != NULL) {
    *endPtr = (char *)(flagValidNumber ? aux : nPtr);
  }

  return flagNegative ? -result : result;
}

unsigned long strtoul(const char *nPtr, char **endPtr, int base) {
  if (nPtr == NULL) return 0;
  char *aux = (char *)nPtr;
  int flagNegative = 0;
  int flagValidNumber = 0;
  unsigned long result = 0;
  while (isSpace(*aux)) aux++;

  if (*aux == '-') {
    flagNegative = 1;
    aux++;
  }

  if ((base == 0 || base == 16) && *aux == '0' &&
      (*(aux + 1) == 'x' || *(aux + 1) == 'X')) {
    aux += 2;
    base = 16;
  }
  if (base == 0) {
    base = (*aux == '0') ? 8 : 10;
  }

  for (;; aux++) {
    int digit;
    if (isDigit(*aux)) {
      digit = *aux - '0';
    } else if (isAlpha(*aux)) {
      digit = toUpper(*aux);
      digit = digit - 'A' + 10;
    } else
      break;

    if (digit >= base) break;

    flagValidNumber = 1;
    result = result * base + digit;
  }

  if (*endPtr != NULL) {
    *endPtr = (char *)(flagValidNumber ? aux : nPtr);
  }

  if (flagNegative) {
    long long aux = -result;
    result = aux;
  }

  return result;
}
