#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int countNonZeroRows(int **matrix, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        int zero_found = 0;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zero_found = 1;
                break;
            }
        }
        if (!zero_found)
            count++;
    }
    return count;
}

int findMaxRepeatingElement(int **matrix, int rows, int cols) {
    int freq[201] = {0};
    int max_repeat = INT_MIN;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            freq[matrix[i][j] + 100]++;

    for (int i = 0; i < 201; i++) {
        if (freq[i] > 1 && (i - 100) > max_repeat)
            max_repeat = i - 100;
    }
    return max_repeat;
}

int main() {
    int rows, cols;
    printf("Введите количество строк и столбцов: ");
    scanf("%d %d", &rows, &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    int count = countNonZeroRows(matrix, rows, cols);
    printf("Количество строк без нулей: %d\n", count);

    int max_repeat = findMaxRepeatingElement(matrix, rows, cols);
    if (max_repeat != INT_MIN)
        printf("Максимальный повторяющийся элемент: %d\n", max_repeat);
    else
        printf("Повторяющиеся элементы отсутствуют.\n");

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
