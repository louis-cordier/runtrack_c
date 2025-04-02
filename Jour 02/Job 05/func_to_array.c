#include "func_to_array.h"

void func_to_array(char **strs, void (*fun)(char *)) {
    if (!strs || !fun) return;
    
    for (int i = 0; strs[i]; i++) {
        fun(strs[i]);
    }
}
