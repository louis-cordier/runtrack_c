#include <stdio.h>
#include <stdlib.h>

char *itoa_hex(int n)
{
    if (n == 0) {
        char *str = malloc(2);
        if (str == NULL) return NULL;
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    unsigned int num = (unsigned int)n;
    int length = 0;
    unsigned int temp = num;
    
    while (temp != 0) {
        temp /= 16;
        length++;
    }

    char *str = malloc(length + 1);
    if (str == NULL) return NULL;

    str[length] = '\0';
    int i = length - 1;
    
    while (num != 0) {
        int remainder = num % 16;
        if (remainder < 10)
            str[i] = remainder + '0';
        else
            str[i] = remainder - 10 + 'A';
        num /= 16;
        i--;
    }

    return str;
}

int main()
{
    // Test cases
    int tests[] = {255, 0, -42, 305441741};
    for (int i = 0; i < 4; i++) {
        char *hex = itoa_hex(tests[i]);
        printf("%d en hexadécimal: %s\n", tests[i], hex);
        free(hex);
    }
    return 0;
}