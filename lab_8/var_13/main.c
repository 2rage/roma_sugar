#include <stdio.h>
#include <math.h>

void inputMatrix(int matrix[50][50], int size) {
    printf("Введите элементы матрицы:\n");
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            scanf("%d", &matrix[i][j]);
}

void zeroNonDiagonalElements(int matrix[50][50], int size) {
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            if(i != j) matrix[i][j] = 0;
}

void changeSignMaxAbsInRow(int matrix[50][50], int size) {
    for(int i=0; i<size; i++) {
        int max_idx = 0;
        for(int j=1; j<size; j++)
            if(fabs(matrix[i][j]) > fabs(matrix[i][max_idx]))
                max_idx = j;
        matrix[i][max_idx] = -matrix[i][max_idx];
    }
}

int main() {
    int matrix[50][50], size;
    printf("Введите размер матрицы: ");
    scanf("%d", &size);
    inputMatrix(matrix, size);

    changeSignMaxAbsInRow(matrix, size);  // сначала меняем знаки
    zeroNonDiagonalElements(matrix, size);  // затем обнуляем элементы вне диагонали

    printf("Результирующая матрица:\n");
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
