#include <stdio.h>

int main(){

         int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
         int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
         int board[8][8] = {{0}};
         int dAccessibility[8][8] = {{2, 3, 4, 4, 4, 4, 3, 2}, {3, 4, 6, 6, 6, 6, 4, 3}, {4, 6, 8, 8, 8, 8, 6, 4}, {4, 6, 8, 8, 8, 8, 6, 4},
                             {4, 6, 8, 8, 8, 8, 6, 4}, {4, 6, 8, 8, 8, 8, 6, 4}, {3, 4, 6, 6, 6, 6, 4, 3}, {2, 3, 4, 4, 4, 4, 3, 2}};
         int currentRow = 0;
         int currentCollum = 0;
         int accessibility[8][8];
         int nextRow = 0, nextCollum = 0;
         int nextMove, moveFound, moveCounter;
         int nextNextRow = 0, nextNextCollum = 0;
         int smallest = 0;
         int minFutureAccess, bestTieBreak;
         for (int r = 0; r < 8; r++) {
                 for (int c = 0; c < 8; c++) {
                         currentRow = r, currentCollum = c;
                         printf("%s%d%s%d\n", "Starting row: ", currentRow, " Starting collum: ", currentCollum);

                         for (size_t i = 0; i < 8; i++) {
                                 for (size_t j = 0; j < 8; j++) {
                                      board[i][j] = 0;
                                 }
                         }

                         for (size_t i = 0; i < 8; i++) {
                                 for (size_t j = 0; j < 8; j++){
                                         accessibility[i][j] = dAccessibility[i][j];
                                 }

                         }

                         board[currentRow][currentCollum] = 1;
                         moveCounter = 0;

                         for (size_t i = 0; i < 8; i++){
                                 for(size_t j = 0; j < 8; j++){
                                    printf("%d ", board[i][j]);
                                 }
                                 printf("\n");
                         }
                         printf("--------------------------------------------------\n");

                         for (size_t i = 0; i < 63; i++) {
                                 nextMove = 0;
                                 smallest = 10;
                                 moveFound = 0;

                                 for (size_t j = 0; j < 8; j++) {
                                         nextRow = currentRow;
                                         nextCollum = currentCollum;
                                         nextRow += vertical[j];
                                         nextCollum += horizontal[j];
                                         if ((nextRow >= 0 && nextRow <= 7) && (nextCollum >= 0 && nextCollum <= 7) && (board[nextRow][nextCollum] == 0)) {
                                            accessibility[nextRow][nextCollum]--;
                                         }
                                 }

                                  for (size_t j = 0; j < 8; j++) {
                                         nextRow = currentRow;
                                         nextCollum = currentCollum;
                                         nextRow += vertical[j];
                                         nextCollum += horizontal[j];
                                         if (((nextRow >= 0 && nextRow <= 7) && (nextCollum >= 0 && nextCollum <= 7)) && (board[nextRow][nextCollum] == 0)) {
                                             minFutureAccess = 9;
                                                 for (size_t k = 0; k < 8; k++) {
                                                         nextNextRow = nextRow;
                                                         nextNextCollum = nextCollum;
                                                         nextNextRow += vertical[k];
                                                         nextNextCollum += horizontal[k];
                                                         if (((nextNextRow >= 0 && nextNextRow <= 7) && (nextNextCollum >= 0 && nextNextCollum <= 7)) && (board[nextNextRow][nextNextCollum] == 0)) {
                                                                    if (accessibility[nextNextRow][nextNextCollum] < minFutureAccess){
                                                                         minFutureAccess = accessibility[nextNextRow][nextNextCollum];
                                                                 }
                                                        }
                                                 }
                                               if (accessibility[nextRow][nextCollum] < smallest) {
                                                         nextMove = j;
                                                         smallest = accessibility[nextRow][nextCollum];
                                                         moveFound = 1;
                                                         bestTieBreak = minFutureAccess;
                                                 } else if (accessibility[nextRow][nextCollum] == smallest) {
                                                      if (minFutureAccess < bestTieBreak) {
                                                                bestTieBreak = minFutureAccess;
                                                                nextMove = j;
                                                                moveFound = 1;
                                                         }
                                               }
                                         }
                                 }

                                     if (moveFound == 0){
                                         moveCounter = i+1;
                                         break;
                                 }

                                 currentRow += vertical[nextMove];
                                 currentCollum += horizontal[nextMove];
                                 board[currentRow][currentCollum] = i+2;

                         }

                         if (moveCounter != 0) {
                                 printf("%s%d%s\n", "Deadend found after ", moveCounter, " moves.");
                         }
	                     if (currentRow == r && currentCollum == c) printf("%s\n", "That's a closed tour!");
                         for (size_t i = 0; i < 8; i++){
                                 for(size_t j = 0; j < 8; j++){
                                   printf("%2d ", board[i][j]);
                                 }
                                 printf("\n");
                         }
                         printf("--------------------------------------------------\n");
                 }
         }

         return 0;
 }