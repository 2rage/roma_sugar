#include <stdio.h>
#include <math.h>

int main() {
    int matrix[3][3] = {{1, -3, 2}, {4, -6, 5}, {7, -8, 9}};
    int size = 3, i, j, max_idx;

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if(i != j) matrix[i][j] = 0;
        }
    }

    for(i = 0; i < size; i++) {
        max_idx = 0;
        for(j = 1; j < size; j++) {
            if(fabs(matrix[i][j]) > fabs(matrix[i][max_idx]))
                max_idx = j;
        }
        matrix[i][max_idx] = -matrix[i][max_idx];
    }

    printf("Результирующая матрица:\n");
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
