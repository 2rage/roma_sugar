#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void zeroNonDiagonalElements(int **matrix, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i != j) matrix[i][j] = 0;
        }
    }
}

void changeSignMaxAbsInRow(int **matrix, int size) {
    for(int i = 0; i < size; i++) {
        int max_idx = 0;
        for(int j = 1; j < size; j++) {
            if(abs(matrix[i][j]) > abs(matrix[i][max_idx])) {
                max_idx = j;
            }
        }
        matrix[i][max_idx] = -matrix[i][max_idx];
    }
}

int main() {
    int size;
    printf("Введите размер матрицы: ");
    scanf("%d", &size);

    int **matrix = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Введите элементы матрицы:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    changeSignMaxAbsInRow(matrix, size);
    zeroNonDiagonalElements(matrix, size);

    printf("Результирующая матрица:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
