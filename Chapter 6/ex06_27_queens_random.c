#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkCollisions(int board[][8]){
	int queenRow[8];
	int queenCollum[8];
	int aux = 0;
    //if (board[0][0] == 0) return 1;
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (board[i][j] == 8) {
				queenRow[aux] = i;
                queenCollum[aux] = j;
				aux++;
			}
		}
	}
	
	for (size_t i = 0; i < 8; i++) {
		for (int a = queenCollum[i] + 1; a < 8; a++){
			if (board[queenRow[i]][a] == 8) return 1;
        }
		for (int a = queenCollum[i] - 1; a >= 0; a--){
			if (board[queenRow[i]][a] == 8) return 1;
        }
		for (int a = queenRow[i] + 1, b = queenCollum[i] + 1; ((a < 8) && (b < 8)); a++, b++){
			if (board[a][b] == 8) return 1;
        }
		for (int a = queenRow[i] + 1, b = queenCollum[i] - 1; ((a < 8) && (b >= 0)); a++, b--){
			if (board[a][b] == 8) return 1;
        }
		for (int a = queenRow[i] - 1, b = queenCollum[i] + 1; ((a >= 0) && (b < 8)); a--, b++){
			if (board[a][b] == 8) return 1;
        }
		for (int a = queenRow[i] - 1, b = queenCollum[i] - 1; ((a >= 0) && (b >= 0)); a--, b--){
			if (board[a][b] == 8) return 1;
        }
	}
	return 0;
}

int main() {
	srand(time(NULL));
	int board[8][8] = {{0}};
	int randomRow[8] = {0};
	int randomnum;
	int collisionFlag = 1;
    while (collisionFlag == 1) {	
		for (size_t i = 0; i < 8; i++) {
			for (size_t j = 0; j < 8; j++) {
				board[i][j] = 1;
            }
		}

		for (size_t i = 0; i < 8; i++) {
			randomnum = rand() % 8;
            if (randomRow[randomnum] == 1){
				while(randomRow[randomnum] != 0) {
					randomnum = rand() % 8;
				}	
				randomRow[randomnum] = 1;
			} 
			board[randomnum][i] = 8;
        }
		
		collisionFlag = checkCollisions(board);

	}

	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			printf("%d ", board[i][j]);
        }
		printf("\n");
	}

	//collisionFlag = checkCollisions(board);
	printf("%d\n", collisionFlag);

	return 0;
}