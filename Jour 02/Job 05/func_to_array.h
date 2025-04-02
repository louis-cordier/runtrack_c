#include "func_to_array.h"

void func_to_array(char **strs, void (*fun)(char *)) {
    for (int i = 0; strs && strs[i]; i++) {
        fun(strs[i]);
    }
}
