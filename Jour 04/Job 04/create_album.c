#include "create_album.h"

t_album_list *create_album(char *artist, char *title, int year) {
    t_album_list *new_album = (t_album_list *)malloc(sizeof(t_album_list));
    if (!new_album) {
        return NULL; // Allocation échouée
    }

    new_album->artist = artist;
    new_album->title = title;
    new_album->year = year;
    new_album->next = NULL;

    return new_album;
}
