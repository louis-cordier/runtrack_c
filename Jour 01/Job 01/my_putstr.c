#include "my_putchar.c"

void my_putstr(char *str) {
    while (*str) {
        my_putchar(*str);
        str++;
    }
}
