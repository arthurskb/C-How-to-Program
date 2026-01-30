#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conversionProgram(const char *question);

int main() {
  printf(
      "Insert a convertion to be done, for example:\n\"How many inches are in "
      "2 meters?\"\n");
  printf(
      "Use at max 99 characters to ask, and follow the input example to get an "
      "answer\n");
  char question[100];
  fgets(question, 99, stdin);
  conversionProgram(question);
}

void conversionProgram(const char *question) {
  char *metricDistance[4] = {"milimeters", "centimeters", "meters",
                             "kilometers"};
  char *imperialDistance[4] = {"inches", "feet", "yards", "miles"};
  char *metricMass[3] = {"miligrams", "grams", "kilograms"};
  char *imperialMass[3] = {"ounces", "pounds", "stones"};
  char *metricVolume[2] = {"mililiters", "liters"};
  char *imperialVolume[4] = {"cups", "pints", "quarts", "gallons"};
  char *tokenPtr = strtok((char *)question, " ");
  char *toConvert = NULL;
  size_t toConvertIndex = -1;
  double num;
  char *toBeConverted = NULL;
  size_t toBeConvertedIndex = -1;
  int flagType = 0;
  int flagValidConversion = 0;
  while (tokenPtr != NULL) {
    size_t m = 0;
    size_t p = 0;
    size_t mm = 0;
    size_t pp = 0;
    size_t mmm = 0;
    size_t ppp = 0;
    for (size_t i = 0; tokenPtr[i] != '\0'; i++) {
      tokenPtr[i] = tolower(tokenPtr[i]);
    }
    for (; m < 4; m++) {
      int cmp = strcmp(tokenPtr, metricDistance[m]);
      if (cmp == 0) break;
    }
    for (; p < 4; p++) {
      int cmp = strcmp(tokenPtr, imperialDistance[p]);
      if (cmp == 0) break;
    }
    for (; mm < 3; mm++) {
      int cmp = strcmp(tokenPtr, metricMass[mm]);
      if (cmp == 0) break;
    }
    for (; pp < 3; pp++) {
      int cmp = strcmp(tokenPtr, imperialMass[pp]);
      if (cmp == 0) break;
    }
    for (; mmm < 2; mmm++) {
      int cmp = strcmp(tokenPtr, metricVolume[mmm]);
      if (cmp == 0) break;
    }
    for (; ppp < 4; ppp++) {
      int cmp = strcmp(tokenPtr, imperialVolume[ppp]);
      if (cmp == 0) break;
    }
    if (m < 4) {
      toConvert = metricDistance[m];
      flagType = 1;
      toConvertIndex = m;
      tokenPtr = strtok(NULL, " ");
      break;
    } else if (p < 4) {
      toConvert = imperialDistance[p];
      flagType = 2;
      toConvertIndex = p;
      tokenPtr = strtok(NULL, " ");
      break;
    } else if (mm < 3) {
      toConvert = metricMass[mm];
      flagType = 3;
      toConvertIndex = mm;
      tokenPtr = strtok(NULL, " ");
      break;
    } else if (pp < 3) {
      toConvert = imperialMass[pp];
      flagType = 4;
      toConvertIndex = pp;
      tokenPtr = strtok(NULL, " ");
      break;
    } else if (mmm < 2) {
      toConvert = metricVolume[mmm];
      flagType = 5;
      toConvertIndex = mmm;
      tokenPtr = strtok(NULL, " ");
      break;
    } else if (ppp < 4) {
      toConvert = imperialVolume[ppp];
      flagType = 6;
      toConvertIndex = ppp;
      tokenPtr = strtok(NULL, " ");
      break;
    }
    tokenPtr = strtok(NULL, " ");
  }

  while (tokenPtr != NULL) {
    int flagTryConvertion = 0;
    size_t i = 0;
    for (; tokenPtr[i] != '\0'; i++) {
      char c = tokenPtr[i];
      if (isdigit(c)) {
        flagTryConvertion = 1;
        break;
      }
    }
    if (flagTryConvertion) {
      num = strtod(&tokenPtr[i], NULL);
      tokenPtr = strtok(NULL, " ");
      break;
    }
    tokenPtr = strtok(NULL, " ");
  }

  while (tokenPtr != NULL) {
    for (size_t i = 0; tokenPtr[i] != '\0'; i++) {
      tokenPtr[i] = tolower(tokenPtr[i]);
      if (tokenPtr[i] == '?' || tokenPtr[i] == '\n') tokenPtr[i] = '\0';
    }
    switch (flagType) {
      case 1:
        for (size_t i = 0; i < 4; i++) {
          int cmp = strcmp(tokenPtr, imperialDistance[i]);
          if (cmp == 0) {
            toBeConverted = imperialDistance[i];
            toBeConvertedIndex = i;
            flagValidConversion = 1;
          }
        }
        break;
      case 2:
        for (size_t i = 0; i < 4; i++) {
          int cmp = strcmp(tokenPtr, metricDistance[i]);
          if (cmp == 0) {
            toBeConverted = metricDistance[i];
            toBeConvertedIndex = i;
            flagValidConversion = 1;
          }
        }
        break;
      case 3:
        for (size_t i = 0; i < 3; i++) {
          int cmp = strcmp(tokenPtr, imperialMass[i]);
          if (cmp == 0) {
            toBeConverted = imperialMass[i];
            toBeConvertedIndex = i;
            flagValidConversion = 1;
          }
        }
        break;
      case 4:
        for (size_t i = 0; i < 3; i++) {
          int cmp = strcmp(tokenPtr, metricMass[i]);
          if (cmp == 0) {
            toBeConverted = metricMass[i];
            toBeConvertedIndex = i;
            flagValidConversion = 1;
          }
        }
        break;
      case 5:
        for (size_t i = 0; i < 4; i++) {
          int cmp = strcmp(tokenPtr, imperialVolume[i]);
          if (cmp == 0) {
            toBeConverted = imperialVolume[i];
            toBeConvertedIndex = i;
            flagValidConversion = 1;
          }
        }
        break;
      case 6:
        for (size_t i = 0; i < 2; i++) {
          int cmp = strcmp(tokenPtr, metricVolume[i]);
          if (cmp == 0) {
            toBeConverted = metricVolume[i];
            toBeConvertedIndex = i;
            flagValidConversion = 1;
          }
        }
        break;
      default:
        printf("Invalid input\n");
    }
    tokenPtr = strtok(NULL, " ");
  }

  if (flagValidConversion) {
    switch (flagType) {
      double result;

      case 1:
        double inches;
        switch (toBeConvertedIndex) {
          case 0:
            inches = num;
            break;
          case 1:
            inches = 12 * num;
            break;
          case 2:
            inches = 36 * num;
            break;
          case 3:
            inches = 63360 * num;
        }
        switch (toConvertIndex) {
          case 0:
            result = inches * 25.4;
            printf("%.2f %s\n", result, metricDistance[toConvertIndex]);
            break;
          case 1:
            result = inches * 2.54;
            printf("%.2f %s\n", result, metricDistance[toConvertIndex]);
            break;
          case 2:
            result = inches * 0.0254;
            printf("%.2f %s\n", result, metricDistance[toConvertIndex]);
            break;
          case 3:
            result = inches * 0.0000254;
            printf("%.2f %s\n", result, metricDistance[toConvertIndex]);
        }
        break;

      case 2:
        double meters;
        switch (toBeConvertedIndex) {
          case 0:
            meters = num / 1000;
            break;
          case 1:
            meters = num / 100;
            break;
          case 2:
            meters = num;
            break;
          case 3:
            meters = num * 1000;
        }
        switch (toConvertIndex) {
          case 0:
            result = meters / 0.0254;
            printf("%.2f %s\n", result, imperialDistance[toConvertIndex]);
            break;
          case 1:
            result = meters / 0.3048;
            printf("%.2f %s\n", result, imperialDistance[toConvertIndex]);
            break;
          case 2:
            result = meters / 0.9144;
            printf("%.2f %s\n", result, imperialDistance[toConvertIndex]);
            break;
          case 3:
            result = meters / 1609.344;
            printf("%.2f %s\n", result, imperialDistance[toConvertIndex]);
            break;
        }
        break;

      case 3:
        double pounds;
        switch (toBeConvertedIndex) {
          case 0:
            pounds = num / 16;
            break;
          case 1:
            pounds = num;
            break;
          case 2:
            pounds = num * 14;
        }
        switch (toConvertIndex) {
          case 0:
            result = pounds * 453592.37;
            printf("%.2f %s\n", result, metricMass[toConvertIndex]);
            break;
          case 1:
            result = pounds * 453.592;
            printf("%.2f %s\n", result, metricMass[toConvertIndex]);
            break;
          case 2:
            result = pounds * 0.453592;
            printf("%.2f %s\n", result, metricMass[toConvertIndex]);
        }
        break;

      case 4:
        double grams;
        switch (toBeConvertedIndex) {
          case 0:
            grams = num * 1000;
            break;
          case 1:
            grams = num;
            break;
          case 2:
            grams = num / 1000;
        }
        switch (toConvertIndex) {
          case 0:
            result = grams / 28.3495;
            printf("%.2f %s\n", result, imperialMass[toConvertIndex]);
            break;
          case 1:
            result = grams / 453.592;
            printf("%.2f %s\n", result, imperialMass[toConvertIndex]);
            break;
          case 2:
            result = grams / 6350.29;
            printf("%.2f %s\n", result, imperialMass[toConvertIndex]);
        }
        break;

      case 5:
        double quarts;
        switch (toBeConvertedIndex) {
          case 0:
            quarts = num / 4;
            break;
          case 1:
            quarts = num / 2;
            break;
          case 2:
            quarts = num;
            break;
          case 3:
            quarts = num * 4;
        }
        switch (toConvertIndex) {
          case 0:
            result = quarts * 946.353;
            printf("%.2f %s\n", result, metricVolume[toConvertIndex]);
            break;
          case 1:
            result = quarts * 0.946353;
            printf("%.2f %s\n", result, metricVolume[toConvertIndex]);
        }
        break;

      case 6:
        double liters;
        switch (toBeConvertedIndex) {
          case 0:
            liters = num * 1000;
            break;
          case 1:
            liters = num;
        }
        switch (toConvertIndex) {
          case 0:
            result = liters / 0.236588;
            printf("%.2f %s\n", result, imperialVolume[toConvertIndex]);
            break;
          case 1:
            result = liters / 0.473176;
            printf("%.2f %s\n", result, imperialVolume[toConvertIndex]);
            break;
          case 2:
            result = liters / 0.946353;
            printf("%.2f %s\n", result, imperialVolume[toConvertIndex]);
            break;
          case 3:
            result = liters / 3.78541;
            printf("%.2f %s\n", result, imperialVolume[toConvertIndex]);
        }
        break;
    }
  } else {
    printf("Invalid input or conversion.\n");
  }
}
