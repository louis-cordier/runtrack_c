#include "album_list.h"
#include <stdio.h>

void print_album(t_album_list *list) {
    while (list) {
        printf("\"%s\" by \"%s\" released in %d.\n", list->title, list->artist, list->year);
        list = list->next;
    }
}
