#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    int arr[] = {-5, 3, -7, 2, -9, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    float average;
    int max_neg = arr[0];
    int divisor = 3;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (arr[i] < 0 && fabs(arr[i]) > fabs(max_neg)) {
            max_neg = arr[i];
        }
    }

    average = (float)sum / size;
    float result = (float)max_neg / divisor;

    printf("Среднее арифметическое: %.2f\n", average);
    printf("Макс. по модулю отрицательный элемент (%d) разделённый на %d: %.2f\n", max_neg, divisor, result);

    return 0;
}
