/*c - Firstly i tried for a full tour which took too much time, so i changed for
30 movements, and still didn't happen in 20minutes. So it takes A LOT OF TIME.

d - Of course the accessibility-heuristic needed more careful study, and was
harder to develop. But it provided better results, and took way less computer
power to execute. The accessibility-heuristic approach isn't 100% guaranteed to
obtain a full tour, while the brute-force IS, but it would take A LOT of time.
Pros and cons in comparison are all around: time to develop, time to execute,
computer power required, chance to obtain an answer.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
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

  printf("%s%d%s%d\n", "Starting row: ", currentRow,
         " Starting collum: ", currentCollum);
  moveCounter = 0;
  srand((unsigned int)time(NULL));
  int loopCounter = 0;
  while (biggestCounter < 63) {
    moveCounter = 1;
    loopCounter++;
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
      if (((nextRow >= 0 && nextRow <= 7) &&
           (nextCollum >= 0 && nextCollum <= 7)) &&
          (board[nextRow][nextCollum] == 0)) {
        moveFound = 1;
      }

      if (moveFound == 0) {
        break;
      }

      moveCounter++;
      currentRow += vertical[nextMove];
      currentCollum += horizontal[nextMove];
      board[currentRow][currentCollum] = i + 2;
    }

    if (moveCounter > biggestCounter) {
      biggestCounter = moveCounter;
      for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
          bestBoard[i][j] = board[i][j];
        }
      }
    }
  }

  printf("%s%d%s", "The best try achieved ", biggestCounter,
         " movements, and here is the board: \n");
  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 8; j++) {
      printf("%2d ", bestBoard[i][j]);
    }
    printf("\n");
  }
  printf("%d%s", loopCounter, " tries were made until reaching full board\n");

  return 0;
}