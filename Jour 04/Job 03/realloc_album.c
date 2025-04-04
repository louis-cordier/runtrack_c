#include "realloc_album.h"
#include <string.h>

t_album *realloc_album(t_album *albums, int size, int newsize) {
    if (newsize <= 0) {
        free(albums);
        return NULL;
    }

    t_album *new_albums = (t_album *)malloc(newsize * sizeof(t_album));
    if (!new_albums) {
        return NULL; // Allocation échouée
    }

    int min_size = (size < newsize) ? size : newsize;

    for (int i = 0; i < min_size; i++) {
        new_albums[i] = albums[i]; // Copie des données (shallow copy)
    }

    free(albums);
    return new_albums;
}
