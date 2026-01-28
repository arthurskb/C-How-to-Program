#include <stdio.h>
#include <string.h>

char *convertDateFormat(const char *s);

int main() {
  char date[] = "07/21/2003";
  printf("Initial date = %s\n", date);
  char *convertedDate = convertDateFormat(date);
  if (convertedDate == NULL) return 1;
  printf("Converted date = %s", convertedDate);
  return 0;
}

char *convertDateFormat(const char *s) {
  char *monthsNames[12] = {"January",   "February", "March",    "April",
                           "May",       "June",     "July",     "August",
                           "September", "October",  "November", "December"};
  char *tokenPtr = NULL;
  tokenPtr = strtok((char *)s, "/");
  int month;
  sscanf(tokenPtr, "%d", &month);
  tokenPtr = strtok(NULL, "/");
  if (month < 1 || month > 12) {
    printf("Invalid month input\n");
    return NULL;
  }
  int day;
  sscanf(tokenPtr, "%d", &day);
  if (day < 1 || day > 31) {
    printf("Invalid day input\n");
    return NULL;
  }
  switch (month) {
    case 2:
      if (day > 29) {
        printf("Invalid day input\n");
        return NULL;
      }
      break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if (day > 31) {
        printf("Invalid day input \n");
        return NULL;
      }
      break;
    default:
      if (day > 30) {
        printf("Invalid day input \n");
        return NULL;
      }
  }
  tokenPtr = strtok(NULL, " ");
  int year;
  sscanf(tokenPtr, "%d", &year);
  if (month == 2) {
    if (year % 4 != 0) {
      if (day > 28) {
        printf("Invalid day input\n");
        return NULL;
      } else {
        if ((year % 100 == 0) || (year % 400 != 0)) {
          printf("Invalid day input\n");
          return NULL;
        }
      }
    }
  }
  static char result[19];
  sprintf(result, "%s %d, %d\n", monthsNames[month - 1], day, year);
  result[19] = '\0';
  return result;
}
