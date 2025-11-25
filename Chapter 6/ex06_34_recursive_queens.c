#include <stdio.h>

int checkAvailability(int board[][8], int nextX, int nextY);

int nextMove(int board[][8], int collumn);

int main() {
	int board[8][8] = {{0}};
	nextMove(board, 0);

	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			printf("%d ", board[i][j]);
     		}	
		printf("\n");
	}
}

int nextMove(int board[][8], int collumn){
	int availability, check = 1;
	if (collumn == 8){
		return 0;
	}
	else {
		for (size_t i = 0; i < 8; i++) {
			int availability = checkAvailability(board, i, collumn);
			if (availability == 0){
				board[i][collumn] = 8;
				check = nextMove(board, collumn+1);
			}
			if (check == 1) {
				board[i][collumn] = 0;
			}
			else {
				return 0;
			}
		}
		return 1;
	}	
}

int checkAvailability(int board[][8], int nextX, int nextY) {
       	for (int a = nextY + 1; a < 8; a++) {
        	if (board[nextX][a] == 8) return -1;
        }
        for (int a = nextY - 1; a >= 0; a--){
        	if (board[nextX][a] == 8) return -2;
        }
        for (int a = nextX + 1, b = nextY + 1; ((a < 8) && (b < 8)); a++, b++){
                if (board[a][b] == 8) return -5;
        }
        for (int a = nextX + 1, b = nextY - 1; ((a < 8) && (b >= 0)); a++, b--){
                if (board[a][b] == 8) return -6;
        }
        for (int a = nextX - 1, b = nextY + 1; ((a >= 0) && (b < 8)); a--, b++){
                if (board[a][b] == 8) return -7;
        }
        for (int a = nextX - 1, b = nextY - 1; ((a >= 0) && (b >= 0)); a--, b--){
      	         if (board[a][b] == 8) return -8;
        }
        
        return 0;

}

