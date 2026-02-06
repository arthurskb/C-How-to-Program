#include <stdio.h>

int main() {
  char s1[10], s2[10], s3[10];
  printf("Insert suzy: ");
  fgets(s1, 10, stdin);
  printf("Insert \"suzy\": ");
  fgets(s2, 10, stdin);
  printf("Insert \'suzy\': ");
  fgets(s3, 10, stdin);
  printf("suzy = %s\'suzy\' = %s\"suzy\" = %s", s1, s3, s2);
  //the ' and " are not been ingnored by C, but rather being read as part of the string.
}
