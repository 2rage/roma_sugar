#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    int a[6] = { 3, -1, 5, -7, 9, -4 };
    int sum_neg = 0;
    int n = 6;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) sum_neg += a[i];
    }

    for (int i = 1; i < n; i += 2) {
        a[i] *= a[0];
    }

    printf("Сумма отрицательных элементов: %d\n", sum_neg);
    printf("Изменённый массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}
