#include <stdio.h>
#include <limits.h>

int main() {
    int matrix[3][4] = {{1, 2, 3, 4}, {5, 0, 7, 8}, {9, 2, 3, 0}};
    int rows = 3, cols = 4, count_non_zero_rows = 0, max_repeat = INT_MIN;
    int freq[100] = {0}, i, j;

    for(i = 0; i < rows; i++) {
        int zero_found = 0;
        for(j = 0; j < cols; j++) {
            if(matrix[i][j] == 0) zero_found = 1;
            freq[matrix[i][j] + 50]++;
        }
        if(!zero_found) count_non_zero_rows++;
    }

    for(i = 0; i < 100; i++) {
        if(freq[i] > 1 && (i - 50) > max_repeat) {
            max_repeat = i - 50;
        }
    }

    printf("Количество строк без нулей: %d\n", count_non_zero_rows);
    if(max_repeat != INT_MIN)
        printf("Максимальный повторяющийся элемент: %d\n", max_repeat);
    else
        printf("Повторяющиеся элементы отсутствуют.\n");

    return 0;
}
