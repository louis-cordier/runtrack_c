#include "char_is_digit.c"

int str_is_digit(char *str) {
    if (*str == '\0') { // Vérifie si la chaîne est vide
        return 0;
    }

    while (*str) {
        if (!char_is_digit(*str)) {
            return 0;
        }
        str++;
    }

    return 1;
}
