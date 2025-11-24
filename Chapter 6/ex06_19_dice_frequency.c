#include <stdio.h>
#include <stdlib.h>

int rollAndSums(void);

int main(void) {

        int rolls[13] = {0};
        int result = 0;

        for (size_t i = 0; i < 36000; i++) {
                result = rollAndSums();
                switch (result) {
                        case 2:
                                rolls[2]++;
                                break;
                        case 3:
                                rolls[3]++;
                                break;
                        case 4:
                                rolls[4]++;
                                break;
                        case 5:
                                rolls[5]++;
                                break;
                        case 6:
                                rolls[6]++;
                                break;
                        case 7:
                                rolls[7]++;
                                break;
                        case 8:
                                rolls[8]++;
                                break;
                        case 9:
                                rolls[9]++;
                                break;
                        case 10:
                                rolls[10]++;
                                break;
                        case 11:
                                rolls[11]++;
                                break;
                        case 12:
                                rolls[12]++;
                }

        }
        printf("%s", "The numbers of dices sums registered are: \n");
        for (size_t i = 2; i < 13; i++) {
                printf("%2lu%10d\n", i, rolls[i]);
        }

        return 0;
}

int rollAndSums(void) {
        int sum, dice1, dice2;
        dice1 = 1 + rand()%6;
        dice2 = 1 + rand()%6;
        sum = dice1 + dice2;
        return sum;
}