#include <stdlib.h>

char *my_itoa(int n) {
    int len = (n <= 0) ? 1 : 0, temp = n;
    while (temp) {
        temp /= 10;
        len++;
    }
    
    char *str = malloc(len + 1);
    if (!str) return NULL;
    
    str[len] = '\0';
    if (n == 0) return str[0] = '0', str;
    
    int is_negative = (n < 0);
    if (is_negative) n = -n;
    
    while (n) {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    
    if (is_negative) str[0] = '-';
    
    return str;
}
