#include <stdio.h>

enum Direction {EAST, SOUTH, WEST, NORTH};

int main() {

        int floor[50][50] = {{0}};

        int array[] = {2, 5, 12, 3, 5, 12, 3, 5, 12, 3, 5, 12, 3, 5, 12, 3, 5, 12, 1, 6, 9};
        int ref = sizeof(array)/4;
        int command = 0;
        int end_flag = 0;
        int pen_flag = 0;
        enum Direction dir = EAST;
        int turtle_x = 15, turtle_y = 15;
        int movement_size = 0;
        for (size_t i = 0; i < ref; i++){
                command = array[i];
                switch (command) {
                        case 1:
                                pen_flag = 0;
                                break;
                        case 2:
                                pen_flag = 1;
                                break;
                        case 3:
                                dir += 1;
                                break;
                        case 4:
                                dir -= 1;
                                break;
                        case 5:
                                i++;
                                movement_size = array[i];
                                switch (dir) {
                                        case 0:
                                                if (pen_flag == 1){
                                                        for (size_t i = turtle_x; i < turtle_x + movement_size; i++) {
                                                                floor[i][turtle_y] = 1;
                                                        }
                                                }
                                                turtle_x += movement_size;
                                                break;
                                        case 1:
                                                if (pen_flag == 1){
                                                     for (size_t i = turtle_y; i < turtle_y + movement_size; i++){
                                                            floor[turtle_x][i] = 1;
                                                        }
                                                }
                                                turtle_y += movement_size;
                                                break;
                                        case 2:
                                                if (pen_flag == 1){
                                                     for (size_t i = turtle_x; i > turtle_x - movement_size; i--){
                                                            floor[i][turtle_y] = 1;
                                                        }
                                                }
                                                turtle_x -= movement_size;
                                                break;
                                        case 3:
                                                if (pen_flag == 1){
                                                     for (size_t i = turtle_y; i > turtle_y - movement_size; i--){
                                                            floor[turtle_x][i] = 1;
                                                        }
                                                }
                                                turtle_y -= movement_size;
                                                break;
                                }
                                break;
                        case 6:
                                for (size_t i = 0; i < 50; i++){
                                          for (size_t j = 0; j < 50; j++){
                                                if (floor[i][j] == 1) printf("*");
                                                else printf(" ");
                                        }
                                        printf("\n");
                                }
                                break;
                        case 9:
                                end_flag = 1;
                }
        if (end_flag == 1) break;
        }
}