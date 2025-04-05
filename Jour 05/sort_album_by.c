#include "album_list.h"
#include <stdlib.h>

void sort_album_by(t_album_list *list, int (*cmp)(t_album_list*, t_album_list*)) {
    if (!list || !cmp)
        return;

    t_album_list *current = list;
    t_album_list *index = NULL;
    t_album_list *temp;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (cmp(current, index) > 0) {
                temp = current;
                current = index;
                index = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}
