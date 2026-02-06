#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIMENSIONS 20
typedef enum { NORTH, EAST, SOUTH, WEST } Direction;

int mazeGenerator(char maze[][DIMENSIONS], int startingPoint[],
                  int endingPoint[]);
int mazeTraverse(char maze[][DIMENSIONS], const int rowStartingLocation,
                 const int columnStartingLocation);
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
  int result = mazeTraverse(maze, startingPoint[0], startingPoint[1]);
  if (result == 1)
    printf("An exit was found!\n");
  else
    printf("There's no exit\n");
  return 0;
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
  for (size_t i = 1; i < DIMENSIONS - 1; i++) {
    if (maze[i][1] == '.') {
      entranceRow = i;
    }
  }
  maze[entranceRow][0] = '.';
  startingPoint[0] = entranceRow;
  startingPoint[1] = 0;
  int exitRow = -1;
  for (size_t i = 1; i < DIMENSIONS - 1; i++) {
    if (maze[i][DIMENSIONS - 3] == '.') {
      exitRow = i;
    }
  }
  if (exitRow > 0) {
    maze[exitRow][DIMENSIONS - 2] = '.';
    maze[exitRow][DIMENSIONS - 1] = '.';
    endingPoint[0] = exitRow;
    endingPoint[1] = DIMENSIONS - 1;
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

int mazeTraverse(char maze[][DIMENSIONS], int currentX, int currentY) {
  int checkTraverseMove(char maze[][DIMENSIONS], int newX, int newY);
  static int initialized = 0;
  static Direction currentFace;
  static int initialX = -1;
  static int initialY = -1;
  static int moveX[] = {-1, 0, 1, 0};
  static int moveY[] = {0, 1, 0, -1};

  maze[currentX][currentY] = 'X';
  printf("initialX = %d e initialY = %d\n", initialX, initialY);
  printf("currentX = %d e currentY = %d\n", currentX, currentY);
  printMaze(maze);

  if (!initialized) {
    currentFace = EAST;
    initialX = currentX;
    initialY = currentY;
    initialized = 1;
  } else if ((currentX == initialX) && (currentY == initialY)) {
    return 0;
  } else if ((currentX == 0 || currentX == DIMENSIONS - 1) ||
             (currentY == 0 || currentY == DIMENSIONS - 1)) {
    return 1;
  }

  for (size_t i = 0; i < 4; i++) {
    int dir = (currentFace + i) % 4;
    int newX = currentX + moveX[dir];
    int newY = currentY + moveY[dir];

    if (checkTraverseMove(maze, newX, newY)) {
      currentFace = (dir + 3) % 4;
      return mazeTraverse(maze, newX, newY);
    }
  }
}

int checkTraverseMove(char maze[][DIMENSIONS], int newX, int newY) {
  if (newX < 0 || newX >= DIMENSIONS || newY < 0 || newY >= DIMENSIONS)
    return 0;
  char check = maze[newX][newY];
  if (check == '#') return 0;
  if (check == '.' || check == 'X') return 1;
}

void initializeMaze(char (*maze)[DIMENSIONS]) {
  for (size_t i = 0; i < DIMENSIONS; i++) {
    for (size_t j = 0; j < DIMENSIONS; j++) {
      maze[i][j] = '#';
    }
  }
}
