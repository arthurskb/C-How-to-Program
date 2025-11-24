#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

        int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int board[8][8] = {{0}};
        int bestBoard[8][8] = {{0}};
        int currentRow = 0;
        int currentCollum = 0;
        int nextRow = 0, nextCollum = 0;
        int moveFound, moveCounter;
        unsigned int nextMove;
        int biggestCounter = 0;

        printf("%s%d%s%d\n", "Starting row: ", currentRow, " Starting collum: ", currentCollum);
        moveCounter = 0;
        srand((unsigned int)time(NULL));

        for (size_t try = 0; try < 1000; try++) {

                moveCounter = 1;

                for (size_t i = 0; i < 8; i++) {
                        for (size_t j = 0; j < 8; j++) {
                                board[i][j] = 0;
                        }
                }

                currentRow = 0;
                currentCollum = 0;
                board[currentRow][currentCollum] = 1;
                for (size_t i = 0; i < 63; i++) {
                        nextMove = rand() % 8;
                        moveFound = 0;
                        nextRow = currentRow;
                        nextCollum = currentCollum;
                        nextRow += vertical[nextMove];
                        nextCollum += horizontal[nextMove];
                        if (((nextRow >= 0 && nextRow <= 7) && (nextCollum >= 0 && nextCollum <= 7)) && (board[nextRow][nextCollum] == 0)) {
                                moveFound = 1;
                        }

                        if (moveFound == 0){
                                break;
                        }

                        moveCounter++;
                        currentRow += vertical[nextMove];
                        currentCollum += horizontal[nextMove];
                        board[currentRow][currentCollum] = i+2;

                }


                if (moveCounter > biggestCounter) {
                        biggestCounter = moveCounter;
                        for (size_t i = 0; i < 8; i++) {
                                for (size_t j = 0; j < 8; j++){
                                          bestBoard[i][j] = board[i][j];
                                }
                        }
                }

        }

        printf("%s%d%s", "The best try achieved ", biggestCounter, " movements, and here is the board: \n");
        for (size_t i = 0; i < 8; i++){
                for(size_t j = 0; j < 8; j++){
                        printf("%2d ", bestBoard[i][j]);
                }
                printf("\n");
        }

        return 0;
}