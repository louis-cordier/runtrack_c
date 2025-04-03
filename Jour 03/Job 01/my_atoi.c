#include "my_atoi.h"

int my_atoi(char *str) {
    int result = 0;
    int sign = 1;

    // Gérer les espaces blancs
    while (*str == ' ' || *str == '\t' || *str == '\n') {
        str++;
    }

    // Vérifier le signe
    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }

    // Convertir en entier
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}
