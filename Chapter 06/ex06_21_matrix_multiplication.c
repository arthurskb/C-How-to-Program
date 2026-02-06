#include <stdio.h>

int check_cond(int collums, int rows) {
  if (collums == rows) return 1;
  return 0;
}

int main() {
  int m1rows, m1collums, m2rows, m2collums;

  printf("%s", "Insert first matrix rows size: ");
  scanf("%d", &m1rows);
  printf("%s", "Insert first matrix collums size: ");
  scanf("%d", &m1collums);

  printf("%s", "Insert second matrix rows size: ");
  scanf("%d", &m2rows);
  printf("%s", "Insert second matrix collums size: ");
  scanf("%d", &m2collums);

  int m1[m1rows][m1collums];
  int m2[m2rows][m2collums];

  int condition = check_cond(m1collums, m2rows);
  if (condition == 0) return 0;

  printf("%s", "Now, lets insert first matrix elements: ");
  for (size_t i = 0; i < m1rows; i++) {
    printf("\n%ld%s", i + 1, "º row elements: ");
    for (size_t j = 0; j < m1collums; j++) {
      printf("%ld%s", j + 1, "º collum element = ");
      scanf("%d", &m1[i][j]);
    }
  }

  printf("%s", "\nNow, lets insert second matrix elements: ");
  for (size_t i = 0; i < m2rows; i++) {
    printf("\n%ld%s", i + 1, "º row elements: ");
    for (size_t j = 0; j < m2collums; j++) {
      printf("%ld%s", j + 1, "º collum element = ");
      scanf("%d", &m2[i][j]);
    }
  }

  int m3[m1rows][m2collums];

  for (size_t i = 0; i < m1rows; i++) {
    for (size_t j = 0; j < m2collums; j++) {
      m3[i][j] = 0;
    }
  }

  for (size_t i = 0; i < m1rows; i++) {
    for (size_t j = 0; j < m2collums; j++) {
      for (size_t k = 0; k < m1collums; k++) {
        m3[i][j] += (m1[i][k] * m2[k][j]);
      }
    }
  }

  printf("\n");

  for (size_t i = 0; i < m1rows; i++) {
    for (size_t j = 0; j < m2collums; j++) {
      printf("%d ", m3[i][j]);
    }
    printf("\n");
  }
}