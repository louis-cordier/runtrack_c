#include <stdlib.h> // Pour malloc

char *itoa_hex(int n)
{
    // Cas particulier pour 0
    if (n == 0)
    {
        char *str = malloc(2);
        if (str == NULL)
            return NULL;
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    // Déterminer la longueur nécessaire
    unsigned int num = (unsigned int)n;
    int length = 0;
    unsigned int temp = num;
    
    while (temp != 0)
    {
        temp /= 16;
        length++;
    }

    // Allouer la mémoire (length + 1 pour le '\0')
    char *str = malloc(length + 1);
    if (str == NULL)
        return NULL;

    // Remplir la chaîne à l'envers
    str[length] = '\0';
    int i = length - 1;
    
    while (num != 0)
    {
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