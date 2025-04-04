#ifndef REALLOC_ALBUM_H
#define REALLOC_ALBUM_H

#include <stdlib.h>

typedef struct {
    char *title;
    char *artist;
    int year;
} t_album;

t_album *realloc_album(t_album *albums, int size, int newsize);

#endif // REALLOC_ALBUM_H
