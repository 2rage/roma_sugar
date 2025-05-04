#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_punctuation(char c) {
    return ispunct(c);
}

void remove_punctuation(char *src, char *dst) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (!is_punctuation(src[i]))
            dst[j++] = src[i];
    }
    dst[j] = '\0';
}

int count_words_with_char(char *str, char target) {
    int count = 0, in_word = 0, has_letter = 0;
    for (int i = 0; str[i]; i++) {
        if (!isspace(str[i])) {
            if (!in_word) {
                in_word = 1;
                has_letter = 0;
            }
            if (tolower(str[i]) == tolower(target)) {
                has_letter = 1;
            }
        } else {
            if (in_word && has_letter)
                count++;
            in_word = 0;
        }
    }
    if (in_word && has_letter)
        count++;
    return count;
}

int main() {
    char str[256], cleaned[256], ch;
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    printf("Введите букву для поиска в словах: ");
    scanf(" %c", &ch);

    remove_punctuation(str, cleaned);
    int result = count_words_with_char(cleaned, ch);

    printf("Строка без знаков препинания: %s\n", cleaned);
    printf("Количество слов с буквой '%c': %d\n", ch, result);

    return 0;
}
