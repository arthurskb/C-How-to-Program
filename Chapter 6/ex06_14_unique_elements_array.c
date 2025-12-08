6.14
// I honestly don't like this code in terms of optimization, but i thought of a
// way to use the smallest possible array to display all the unique
// elements(which is no array at all) PS: I came back after reading 6.15, and
// read that we were reading already two sets of numbers, not arrays. lol!
// Anyways, i'm keeping the code since i liked the problem and solution that i
// first thought about
#include <stdio.h>

    int
    main(void) {
  int array1[10], array2[10];
  printf("%s", "Insert 10 nums for array 1: ");
  for (size_t i = 0; i < 10; i++) {
    scanf("%d", &array1[i]);
  }
  printf("%s", "Insert 10 nums for array 2: ");
  for (size_t i = 0; i < 10; i++) {
    scanf("%d", &array2[i]);
  }

  int flag1, flag11, flag2, flag22;

  printf("%s", "The unique numbers are:\n");

  for (size_t i = 0; i < 10; i++) {
    flag1 = 1;
    flag11 = 1;
    flag2 = 1;
    flag22 = 1;
    for (size_t j = 0; j < 10; j++) {
      if (array1[i] == array2[j]) flag1 = 0;
      if (array2[i] == array1[j]) flag2 = 0;
      if (i != j) {
        if (array1[i] == array1[j]) flag11 = 0;
        if (array2[i] == array2[j]) flag22 = 0;
      }
    }
    if (flag1 == 1 && flag11 == 1) printf("%d ", array1[i]);
    if (flag2 == 1 && flag22 == 1) printf("%d ", array2[i]);
  }

  return 0;
}
