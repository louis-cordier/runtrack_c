#include "sort.h"

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

char **sort(char **strs) {
    if (!strs) return NULL;
    
    int i, j;
    for (i = 0; strs[i]; i++) {
        for (j = 0; strs[j + 1]; j++) {
            char *s1 = strs[j], *s2 = strs[j + 1];
            while (*s1 && *s1 == *s2) {
                s1++;
                s2++;
            }
            if ((unsigned char)*s1 > (unsigned char)*s2) {
                swap(&strs[j], &strs[j + 1]);
            }
        }
    }
    
    return strs;
}
