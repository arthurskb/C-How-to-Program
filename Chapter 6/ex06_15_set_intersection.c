#include <stdio.h>

int main(void) {
        int array1[10], array2[10], intersection[10], intersection_aux = 0;
        printf("%s", "Insert 10 nums for set 1: ");
        for (size_t i = 0; i < 10; i++) {
                scanf("%d", &array1[i]);
        }
        printf("%s", "Insert 10 nums for set 2: ");
        for (size_t i = 0; i < 10; i++) {
                scanf("%d", &array2[i]);
                //uses this for to already check for intersection, just trying different ideas lol
                for (size_t j = 0; j < 10; j++) {
                        if (array2[i] == array1[j]) {
                                intersection[i] = array2[i];
                                intersection_aux++;
                        }
                }
        }
        printf("%s", "The intersection numbers are: ");
        for (size_t i = 0; i < intersection_aux; i++) {
                printf("%d ", intersection[i]);
        }

        printf("\n");

        return 0;
}