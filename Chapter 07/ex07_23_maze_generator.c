#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIMENSIONS 12
typedef enum { NORTH, EAST, SOUTH, WEST } Direction;

int mazeGenerator(char maze[][DIMENSIONS], int startingPoint[],
                  int endingPoint[]);
void printMaze(char (*maze)[DIMENSIONS]);

int main() {
  int startingPoint[2] = {-1, -1};
  int endingPoint[2] = {-1, -1};
  char maze[DIMENSIONS][DIMENSIONS];
  srand(time(NULL));
  mazeGenerator(maze, startingPoint, endingPoint);
  printMaze(maze);
  printf("StartingPoint = {%d, %d}\n", startingPoint[0], startingPoint[1]);
  printf("EndingPoint = {%d, %d}\n", endingPoint[0], endingPoint[1]);
}

void printMaze(char (*maze)[DIMENSIONS]) {
  for (size_t i = 0; i < DIMENSIONS; i++) {
    for (size_t j = 0; j < DIMENSIONS; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int mazeGenerator(char maze[][DIMENSIONS], int startingPoint[],
                  int endingPoint[]) {
  void initializeMaze(char(*maze)[DIMENSIONS]);
  int checkMove(int newX, int newY);
  void shuffleDir(Direction dirs[]);

  static int initialized = 0;

  static int currentX = 1;
  static int currentY = 1;
  maze[1][1] = '.';

  if (!initialized) {
    initializeMaze(maze);
    initialized = 1;
  }

  printMaze(maze);

  Direction dirs[] = {NORTH, EAST, SOUTH, WEST};
  shuffleDir(dirs);

  for (size_t i = 0; i < 4; i++) {
    int moveX = 0;
    int moveY = 0;
    if (dirs[i] == NORTH)
      moveX = -2;
    else if (dirs[i] == EAST)
      moveY = 2;
    else if (dirs[i] == SOUTH)
      moveX = 2;
    else if (dirs[i] == WEST)
      moveY = -2;
    int nextX = currentX + moveX;
    int nextY = currentY + moveY;
    int midX = currentX + moveX / 2;
    int midY = currentY + moveY / 2;
    if (checkMove(nextX, nextY) && maze[nextX][nextY] == '#') {
      maze[nextX][nextY] = '.';
      maze[midX][midY] = '.';
      currentX += moveX;
      currentY += moveY;
      return mazeGenerator(maze, startingPoint, endingPoint);
      currentX -= moveX;
      currentY -= moveY;
    }
  }
  int entranceRow = 0;
  for (size_t i = 1; i < 11; i++) {
    if (maze[i][1] == '.') {
      entranceRow = i;
    }
  }
  maze[entranceRow][0] = '.';
  startingPoint[0] = entranceRow;
  startingPoint[1] = 0;
  int exitRow = -1;
  for (size_t i = 1; i < 11; i++) {
    if (maze[i][9] == '.') {
      exitRow = i;
    }
  }
  if (exitRow > 0) {
    maze[exitRow][10] = '.';
    maze[exitRow][11] = '.';
    endingPoint[0] = exitRow;
    endingPoint[1] = 11;
  }
  return 1;
}

void shuffleDir(Direction dirs[]) {
  int auxRand;
  int auxDirs[4] = {-1, -1, -1, -1};
  for (size_t i = 0; i < 4; i++) {
    while (1) {
      auxRand = rand() % 4;
      if (auxDirs[auxRand] == -1) {
        auxDirs[auxRand] = i;
        break;
      }
    }
  }
  for (size_t i = 0; i < 4; i++) {
    dirs[i] = auxDirs[i];
  }
}

int checkMove(int newX, int newY) {
  if (newX < 1 || newX >= DIMENSIONS - 1 || newY < 1 || newY >= DIMENSIONS - 1)
    return 0;
  return 1;
}

void initializeMaze(char (*maze)[DIMENSIONS]) {
  for (size_t i = 0; i < DIMENSIONS; i++) {
    for (size_t j = 0; j < DIMENSIONS; j++) {
      maze[i][j] = '#';
    }
  }
}
