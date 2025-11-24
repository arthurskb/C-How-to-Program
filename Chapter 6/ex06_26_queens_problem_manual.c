/*Yeah, it is appealing to try always the smallest elimination number, but the problem is you do not account for future moves and overlaps, which are essential to solve this problem.
The code below is the last one i made while trying different approaches for this heuristic.
I think the only way to make it work, would be to implement some kind of backtracking, or "tried" boards to guide the algorithm into trying different things next.
Since it started to get messy, i will leave this last sample, and go for a better way to solve it(which i think is the next one).*/
#include <stdio.h>

void fillBoard(int board[][8], int t, int k){
	for (int j = t + 1; j < 8; j++) {
		board[j][k] = -1;
	}
	for (int j = t - 1; j >= 0; j--) {
		board[j][k] = -1;
	}
	for (int j = k + 1; j < 8; j++) {
		board[t][j] = -1;
	}
	for (int j = k - 1; j >= 0; j--) {
		board[t][j] = -1;
	} 
	for (int j = t + 1, i = k + 1; ((j < 8) && (i < 8)); j++, i++) {
		board[j][i] = -1;
	}
	for (int j = t - 1, i = k - 1; ((j >= 0) && (i >= 0)); j--, i--) {	
		board[j][i] = -1;
	}
	for (int j = t + 1, i = k - 1; ((j < 8) && (i >= 0)); j++, i--) {	
		board[j][i] = -1;
	}
	for (int j = t - 1, i = k + 1; ((j >= 0) && (i < 8)); j--, i++) {	
		board[j][i] = -1;
	}
}

int isBoardFull(int board[][8]){
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (board[i][j] == 0) return 0;
	    }
	}
	return 1;
}

int updateCounterBoard(int board[][8], int counterBoard[][8]){
	int counter;

	for (size_t t = 0; t < 8; t++) {
		for (size_t k = 0; k < 8; k++) {	
			
			counter = 1;
            for (int j = t + 1; j < 8; j++) {
				if(board[j][k] == 0) counter++;
            }
			for (int j = t - 1; j >= 0; j--) {
				if(board[j][k] == 0) counter++;
            }
			for (int j = k + 1; j < 8; j++) {
				if(board[t][j] == 0) counter++;
            }
			for (int j = k - 1; j >= 0; j--) {
				if(board[t][j] == 0) counter++;
            } 
			for (int j = t + 1, i = k + 1; ((j < 8) && (i < 8)); j++, i++) {
				if(board[j][i] == 0) counter++;
            }
			for (int j = t - 1, i = k - 1; ((j >= 0) && (i >= 0)); j--, i--) {	
				if(board[j][i] == 0) counter++;
            }
			for (int j = t + 1, i = k - 1; ((j < 8) && (i >= 0)); j++, i--) {	
				if(board[j][i] == 0) counter++;
            }
			for (int j = t - 1, i = k + 1; ((j >= 0) && (i < 8)); j--, i++) {	
				if(board[j][i] == 0) counter++;
            }

			counterBoard[t][k] = counter;

		}
	}
}

int counterMinus1(int board[][8], int t, int k){

	int counter = 0;
    for (int j = t + 1; j < 8; j++) {
		if(board[j][k] == -1) counter++;
    }
	for (int j = t - 1; j >= 0; j--) {
		if(board[j][k] == -1) counter++;
    }
	for (int j = k + 1; j < 8; j++) {
		if(board[t][j] == -1) counter++;
    }
	for (int j = k - 1; j >= 0; j--) {
		if(board[t][j] == -1) counter++;
    } 
	for (int j = t + 1, i = k + 1; ((j < 8) && (i < 8)); j++, i++) {
		if(board[j][i] == -1) counter++;
    }
	for (int j = t - 1, i = k - 1; ((j >= 0) && (i >= 0)); j--, i--) {	
		if(board[j][i] == -1) counter++;
    }
	for (int j = t + 1, i = k - 1; ((j < 8) && (i >= 0)); j++, i--) {	
		if(board[j][i] == -1) counter++;
    }
	for (int j = t - 1, i = k + 1; ((j >= 0) && (i < 8)); j--, i++) {	
		if(board[j][i] == -1) counter++;
    }

	return counter;
}


int main() {
	
	int board[8][8] = {{0}};
	int counterBoard[8][8] = {{0}};
	int counter;

	updateCounterBoard(board, counterBoard);
    for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			printf("%2d ", counterBoard[i][j]);
        }
		printf("\n");
	}	
	
	printf("%s", "Posição inicial da rainha linha 0, coluna 0\n");
	board[0][0] = 5;
	fillBoard(board, 0, 0);
	int queensOnBoard = 1;
    int smallestElimination = 28;
	updateCounterBoard(board, counterBoard);		
	int smallestEliminationX, smallestEliminationY;
	int counterminus1a, counterminus1b;
    while(queensOnBoard < 8) {
		smallestEliminationX = 0, smallestEliminationY = 0;
		smallestElimination = 28;
        for (size_t i = 0; i < 8; i++) {
			for (size_t j = 0; j < 8; j++) {
				printf("%2d ", board[i][j]);
            }
			printf("\n");
		}		
		printf("---------------------------\n");
		for (size_t i = 0; i < 8; i++) {
			for (size_t j = 0; j < 8; j++) {
				printf("%2d ", counterBoard[i][j]);
            }
			printf("\n");
		}
		printf("---------------------------\n");

		for (size_t i = 0; i < 8; i++) {
			for (size_t j = 0; j < 8; j++){
				if (board[i][j] == 0){
					if (counterBoard[i][j] < smallestElimination) {
						smallestElimination = counterBoard[i][j];
                        smallestEliminationX = i;
						smallestEliminationY = j;
					} else if (counterBoard[i][j] == smallestElimination) {
						counterminus1a = counterMinus1(board, i, j);
                        counterminus1b = counterMinus1(board, smallestEliminationX, smallestEliminationY);
							if (counterminus1a < counterminus1b) {
								smallestElimination = counterBoard[i][j];
								smallestEliminationX = i;
								smallestEliminationY = j;
                            }
					}
				}
			}
		}												
			
		printf("%s%d %d\n", "small x and y = ", smallestEliminationX, smallestEliminationY);
		board[smallestEliminationX][smallestEliminationY] = 5;
		fillBoard(board, smallestEliminationX, smallestEliminationY);
		updateCounterBoard(board, counterBoard);
		queensOnBoard++;
    }

		
	return 0;
}