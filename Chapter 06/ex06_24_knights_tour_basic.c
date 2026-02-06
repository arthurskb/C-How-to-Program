#include <stdio.h>

int main() {
  int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
  int board[8][8] = {{0}};
  int currentRow = 3;
  int currentCollum = 4;
  size_t moves = 0;
  int deadEndFlag;
  int nextRow = 0, nextCollum = 0;
  for (size_t i = 0; i < 64; i++) {
    nextRow = currentRow;
    nextCollum = currentCollum;
    deadEndFlag = 1;
    for (size_t j = 0; j < 8; j++) {
      nextRow += vertical[j];
      nextCollum += horizontal[j];
      if ((nextRow >= 0 && nextRow <= 7) &&
          (nextCollum >= 0 && nextCollum <= 7)) {
        if (board[nextRow][nextCollum] == 0) {
          board[currentRow][currentCollum] = 1;
          currentRow = nextRow;
          currentCollum = nextCollum;
          deadEndFlag = 0;
          break;
        }
      }
    }
    if (deadEndFlag == 1) {
      moves = i + 1;
      break;
    }
  }

  printf("%s%ld\n", "The number of moves made were: ", moves);

  return 0;
}