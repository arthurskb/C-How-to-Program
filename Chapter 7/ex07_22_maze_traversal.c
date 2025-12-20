#include <stdio.h>

#define DIMENSIONS 12

typedef enum {NORTH, EAST, SOUTH, WEST} Direction;

int mazeTraverse(char maze[][DIMENSIONS], const int rowStartingLocation, const int columnStartingLocation);
void printMaze(char (*maze)[DIMENSIONS]);

int main() {
  int rowStartingLocation = 2;
  int columnStartingLocation = 0;
  char maze[DIMENSIONS][DIMENSIONS] = {
        "############",
        "#...#......#",
        "..#.#.####.#",
        "###.#....#.#",
        "#....###.#..",
        "####.#.#.#.#",
        "#..#.#.#.#.#",
        "##.#.#.#.#.#",
        "#........#.#",
        "######.###.#",
        "#......#...#",
        "############"
    };
  int result = mazeTraverse(maze, rowStartingLocation, columnStartingLocation);
  if (result == 1) printf("An exit was found!\n");
  else printf("There's no exit\n");
  return 0;
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
  }
  else if ((currentX == initialX) && (currentY == initialY)) {
    return 0;
  }
  else if ((currentX == 0 || currentX == 11) || (currentY == 0 || currentY == 11)) {
    return 1;
  }

  for (size_t i = 0; i < 4; i++) {
    int dir = (currentFace+i)%4;
    int newX = currentX + moveX[dir];
    int newY = currentY + moveY[dir];

    if (checkTraverseMove(maze, newX, newY)) {
      currentFace = (dir + 3) % 4;
      return mazeTraverse(maze, newX, newY);
    }
  }


}

int checkTraverseMove(char maze[][DIMENSIONS], int newX, int newY) {
  if (newX < 0 || newX >= 12 || newY < 0 || newY >= 12) return 0;
  char check = maze[newX][newY];
  if (check == '#') return 0;
  if (check == '.' || check == 'X') return 1;
}

void printMaze(char (*maze)[DIMENSIONS]) {
  for (size_t i = 0; i < DIMENSIONS; i++) {
    for (size_t j = 0; j < DIMENSIONS; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
  printf("------------\n");
}
