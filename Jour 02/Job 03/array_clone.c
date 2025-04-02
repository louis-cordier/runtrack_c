#include <stdlib.h>
#include <string.h>
#include "array_clone.h"

char **array_clone(char **strs, int n) {
    if (!strs || n <= 0) return NULL;
    
    char **clone = malloc((n + 1) * sizeof(char *));
    if (!clone) return NULL;
    
    int i;
    for (i = 0; i < n && strs[i] != NULL; i++) {
        clone[i] = strdup(strs[i]);
        if (!clone[i]) {
            while (--i >= 0) free(clone[i]);
            free(clone);
            return NULL;
        }
    }
    
    clone[i] = NULL;
    return clone;
}
