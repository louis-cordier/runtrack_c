#include <stdlib.h>  // Pour malloc et NULL

char *my_strdup(char *src)
{
    char *dest;
    int len;
    int i;

    // Calcul de la longueur de la chaîne source
    len = 0;
    while (src[len] != '\0')
        len++;

    // Allocation mémoire pour la nouvelle chaîne (+1 pour le '\0')
    dest = (char *)malloc(sizeof(char) * (len + 1));
    
    // Vérification si l'allocation a réussi
    if (dest == NULL)
        return NULL;

    // Copie de la chaîne source vers la destination
    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Ajout du caractère de fin

    return dest;
}