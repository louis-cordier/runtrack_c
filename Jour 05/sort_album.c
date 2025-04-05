#include "album_list.h"
#include <string.h>

int compare_by_artist(t_album_list *a, t_album_list *b) {
    return strcmp(a->artist, b->artist);
}

int compare_by_title(t_album_list *a, t_album_list *b) {
    return strcmp(a->title, b->title);
}

int compare_by_year(t_album_list *a, t_album_list *b) {
    return a->year - b->year;
}
