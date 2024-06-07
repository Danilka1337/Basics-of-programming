#include <stdio.h>
#include <limits.h>

#define ROWS 4
#define COLS 4

void findSaddlePoints(int matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int current = matrix[i][j];
            int isMinInRow = 1;
            int isMaxInCol = 1;
            
            // Проверка на минимальность в строке
            for (int k = 0; k < cols; k++) {
                if (matrix[i][k] < current) {
                    isMinInRow = 0;
                    break;
                }
            }
            
            // Проверка на максимальность в столбце
            for (int k = 0; k < rows; k++) {
                if (matrix[k][j] > current) {
                    isMaxInCol = 0;
                    break;
                }
            }
            
            if (isMinInRow && isMaxInCol) {
                printf("Седловая точка найдена в строке %d и столбце %d со значением %d\n", i, j, current);
            }
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {3, 8, 4, 1},
        {9, 7, 2, 5},
        {6, 1, 3, 4},
        {2, 5, 7, 8}
    };
    
    findSaddlePoints(matrix, ROWS, COLS);
    
    return 0;
}
