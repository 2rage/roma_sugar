
#include <stdio.h>
#include <limits.h>

void inputMatrix(int matrix[50][50], int rows, int cols) {
    printf("Введите элементы матрицы:\n");
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            scanf("%d", &matrix[i][j]);
}

int countNonZeroRows(int matrix[50][50], int rows, int cols) {
    int count = 0;
    for(int i=0; i<rows; i++) {
        int zero_found = 0;
        for(int j=0; j<cols; j++)
            if(matrix[i][j] == 0) zero_found = 1;
        if(!zero_found) count++;
    }
    return count;
}

int findMaxRepeatingElement(int matrix[50][50], int rows, int cols) {
    int freq[100] = {0}, max_repeat = INT_MIN;
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            freq[matrix[i][j] + 50]++;
    
    for(int i=0; i<100; i++)
        if(freq[i] > 1 && (i-50) > max_repeat)
            max_repeat = i-50;

    return max_repeat;
}

int main() {
    int matrix[50][50], rows, cols;
    printf("Введите размер матрицы (rows cols): ");
    scanf("%d%d", &rows, &cols);
    inputMatrix(matrix, rows, cols);

    printf("Строк без нулей: %d\n", countNonZeroRows(matrix, rows, cols));
    int max_repeat = findMaxRepeatingElement(matrix, rows, cols);
    if(max_repeat != INT_MIN)
        printf("Максимальный повторяющийся элемент: %d\n", max_repeat);
    else
        printf("Повторяющиеся элементы отсутствуют.\n");

    return 0;
}
