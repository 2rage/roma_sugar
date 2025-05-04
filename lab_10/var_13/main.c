#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Считает количество символов между первой открывающей и последней закрывающей скобкой
int count_inside_parentheses(char *str) {
    int start = -1, end = -1;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(' && start == -1)
            start = i;
        else if (str[i] == ')')
            end = i;
    }
    if (start != -1 && end != -1 && end > start)
        return end - start - 1;
    return 0;
}

// Формирует строку: сначала все буквы в обратном порядке, потом цифры в прямом
void reorder_string(char *src, char *dst) {
    char letters[256], digits[256];
    int l = 0, d = 0;

    for (int i = 0; src[i]; i++) {
        if (isdigit((unsigned char)src[i]))
            digits[d++] = src[i];
        else if (isalpha((unsigned char)src[i]))
            letters[l++] = src[i];
    }

    int j = 0;
    for (int i = l - 1; i >= 0; i--)
        dst[j++] = letters[i];
    for (int i = 0; i < d; i++)
        dst[j++] = digits[i];
    dst[j] = '\0';
}

int main() {
    char str[256], result[256];

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    int inside = count_inside_parentheses(str); 
    reorder_string(str, result);

    printf("Преобразованная строка: %s\n", result);
    printf("Символов внутри скобок: %d\n", inside);

    return 0;
}
