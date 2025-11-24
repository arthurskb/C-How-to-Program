/*c - 
The exhaustive technique was way harder and confuse to make, since it required a lot of attention for the nested loops and checks. It also needs more computational power.

d -
The pro from the exhaustive technique is that it can obtain all the 92 solutions easily, and the con is its harder to develop and it takes more time/computational power.*/

#include <stdio.h>

int checkCollisions(int board[][8]) {
        int queenRow[8];
        int queenCollum[8];
        int aux = 0;
        for (size_t i = 0; i < 8; i++) {
                for (size_t j = 0; j < 8; j++) {
                        if(board[i][j] == 8) {
                                  if(aux < 8) {
                                        queenRow[aux] = i;
                                        queenCollum[aux] = j;
                                        aux++;
                                }
                        }
                }
        }

        for (size_t i = 0; i < aux; i++) {
                for (int a = queenCollum[i] + 1; a < 8; a++){
                        if (board[queenRow[i]][a] == 8) return 1;
                }
                for (int a = queenCollum[i] - 1; a >= 0; a--){
                        if (board[queenRow[i]][a] == 8) return 1;
                }
                for (int a = queenRow[i] + 1; a < 8; a++){
                        if (board[a][queenCollum[i]] == 8) return 1;
                }
                for (int a = queenRow[i] - 1; a >= 0; a--){
                        if (board[a][queenCollum[i]] == 8) return 1;
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

        int board[8][8] = {{0}};
        int collisionFlag = 1;
        int solutions = 0;
        for (size_t j = 0; j < 8; j++){
                board[0][j] = 8;
                for (size_t k = 0; k < 8; k++) {
                        board[1][k] = 8;
                        for (size_t l = 0; l < 8; l++) {
                                board[2][l] = 8;
                                for (size_t m = 0; m < 8; m++) {
                                        board[3][m] = 8;
                                        for (size_t n = 0; n < 8; n++) {
                                                board[4][n] = 8;
                                                for (size_t o = 0; o < 8; o++) {
                                                       board[5][o] = 8;
                                                        for (size_t p = 0; p < 8; p++) {
                                                                board[6][p] = 8;
                                                                for (size_t q = 0; q < 8; q++) {
                                                                        board[7][q] = 8;
                                                                        collisionFlag = checkCollisions(board);
                                                                        if (collisionFlag != 1) {
                                                                                   solutions++;
                                                                                printf("%s%d%s\n", "Solution number ", solutions, " found!");
                                                                                for (size_t ii = 0; ii < 8; ii++){
                                                                                        for (size_t jj = 0; jj < 8; jj++){
                                                                                                    printf("%d ", board[ii][jj]);
                                                                                        }
                                                                                        printf("\n");
                                                                                }
                                                                                printf("-------------------------\n");
                                                                        }
                                                                        board[7][q] = 0;
                                                                }
                                                                board[6][p] = 0;
                                                        }
                                                       board[5][o] = 0;
                                                }
                                                board[4][n] = 0;
                                        }
                                        board[3][m] = 0;
                                }
                                board[2][l] = 0;
                        }
                        board[1][k] = 0;
                }
                board[0][j] = 0;
        }
        printf("%s%d%s\n", "We found ", solutions, " solutions.");
        return 0;
}