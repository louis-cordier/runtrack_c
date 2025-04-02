#include <stdlib.h>
#include "delete_str_array.h"

void delete_str_array(char ***strs) {
    if (!strs || !*strs) return;
    
    for (int i = 0; (*strs)[i]; i++) {
        free((*strs)[i]);
    }
    free(*strs);
    *strs = NULL;
}
