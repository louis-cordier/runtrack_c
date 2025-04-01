#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *trim(char *src) {
    if (!src) return NULL;
    
    // Trouver le début non-espace
    while (*src && isspace((unsigned char)*src)) {
        src++;
    }
    
    // Si la chaîne ne contient que des espaces
    if (*src == '\0') {
        char *empty = malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }
    
    // Trouver la fin non-espace
    char *end = src + strlen(src) - 1;
    while (end > src && isspace((unsigned char)*end)) {
        end--;
    }
    
    // Allouer la mémoire pour la nouvelle chaîne
    size_t len = end - src + 1;
    char *trimmed = malloc(len + 1);
    if (!trimmed) return NULL;
    
    // Copier la chaîne sans les espaces
    strncpy(trimmed, src, len);
    trimmed[len] = '\0';
    
    return trimmed;
}