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
            
