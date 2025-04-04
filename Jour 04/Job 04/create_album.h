#ifndef CREATE_ALBUM_H
#define CREATE_ALBUM_H

#include <stdlib.h>

typedef struct album_list {
    char *artist;
    char *title;
    int year;
    struct album_list *next;
} t_album_list;

t_album_list *create_album(char *artist, char *title, int year);

#endif // CREATE_ALBUM_H
