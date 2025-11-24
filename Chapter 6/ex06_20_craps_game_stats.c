//a - Obtained from the code below, but the wins almost always comes from first roll(241)
//b - Obtained from the code below, but the loses almost always comes from first(110), second(109) and third roll(86)
//c - Its close to 50/50
//d - 3 rolls
//e - No, the chances of winning decrease with the length of the game.
#include <stdio.h>
#include <stdlib.h>

int rollDices(void);

int craps(void);

int main(void) {

        int wins[26] = {0}, loses[26] = {0};
        int totalWins = 0, totalLoses = 0, averageLength = 0;
        int result;
        printf("%s\n", "Rolling 1000 craps games, wait for results please.");
        printf("%s\n", "Note: The maximum roll attempts are 25 per game.");

        for (size_t i = 0; i < 1000; i++){
                result = craps();
                if (result < 26 && result > 0) {
                        totalWins++;
                        wins[result]++;
                        averageLength += result;
                }
                else if (result > -26) {
                        result *= -1;
                        totalLoses++;
                        loses[result]++;
                        averageLength += result;
                }
        }

        averageLength /= 1000;

        printf("%s\n", "Here are the results: ");
        printf("%s%d\n", "Number of games won: ", totalWins);
        printf("%s%d\n", "Number of games lost: ", totalLoses);
        printf("%s%d%s\n", "Average length of the games: ", averageLength, " rolls.");
        printf("%s\n", "Now, lets see the length of games won and lost");
        printf("%s%26s\n", "WINS: Length", "Num of Games");
        for (size_t i = 1; i < 26; i++) {
                printf("%12lu%26d\n", i, wins[i]);
        }
        printf("%s%26s\n", "LOSES: Length", "Num of games");
        for (size_t i = 1; i < 26; i++) {
                printf("%12lu%26d\n", i, loses[i]);
        }

        printf("\n");

        return 0;
}

int craps(void) {

        int new_point, sum, counter = 1;
        sum = rollDices();
        switch (sum) {
                case 7:
                case 11:
                        return 1;
                case 2:
                case 3:
                case 12:
                        return -1;
                default:
                        new_point = sum;

        }

        while(1) {
                sum = rollDices();
                counter++;
                if (sum == new_point) return counter;
                else if (sum == 7) return (-1*counter);
        }
}

int rollDices(void){
        int sum, dice1, dice2;
        dice1 = 1 + rand()%6;
        dice2 = 1 + rand()%6;
        sum = dice1 + dice2;
        return sum;
}