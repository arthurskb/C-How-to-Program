#include <stdio.h>

#define STUDENTS 5
#define TESTS 3

void printGrades(int grades[][TESTS]);
void minGrades(int grades[][TESTS]);
void maxGrades(int grades[][TESTS]);
void avgGrades(int grades[][TESTS]);

int main() {

  void (*processGrades[4])(int [][TESTS]) = {printGrades, minGrades, maxGrades, avgGrades};
  printf("Welcome to the Grades program\n");
  int choice = 0;
  int grades[STUDENTS][TESTS] = {{10, 9, 8}, {6, 6, 6}, {8, 4, 10}, {2, 9, 7}, {2, 3, 4}};

  while (1) {
    printf("Enter a choice:\n");
    printf("0 Print the array of grades\n");
    printf("1 Find the minimum grade\n");
    printf("2 Find the maximum grade\n");
    printf("3 Print the average on all tests for each student\n");
    printf("4 End program\n");
    scanf("%d", &choice);

    switch (choice) {
      case 0:
      case 1:
      case 2:
      case 3:
        (*processGrades[choice])(grades);
        break;
      default:
        printf("Thank you, see you later.\n");
        return 0;
    }
  }
}

void printGrades(int grades[][TESTS]) {
  for (size_t i = 0; i < STUDENTS; i++) {
    printf("Student %ld: ", i+1);
    for (size_t j = 0; j < TESTS; j++) {
      printf("Exam %ld = %d ", j+1, grades[i][j]);
    }
    printf("\n");
  }
}

void minGrades(int grades[][TESTS]) {
  int min = 10;
  for (size_t i = 0; i < STUDENTS; i++) {
    for (size_t j = 0; j < TESTS; j++) {
      if(grades[i][j] < min) {
        min = grades[i][j];
      }
    }
  }
  printf("Minimum grade = %d\n", min);
}

void maxGrades(int grades[][TESTS]) {
  int max = 0;
  for (size_t i = 0; i < STUDENTS; i++) {
    for (size_t j = 0; j < TESTS; j++) {
      if(grades[i][j] > max) {
        max = grades[i][j];
      }
    }
  }
  printf("Maximum grade = %d\n", max);
}

void avgGrades(int grades[][TESTS]) {
  int sum, avg;
  for (size_t i = 0; i < STUDENTS; i++) {
    sum = 0;
    avg = 0;
    for (size_t j = 0; j < TESTS; j++) {
      sum += grades[i][j];
    }
    avg = sum/TESTS;
    printf("The average on all tests for Student %ld is %d\n", i+1, avg);
  }
}
