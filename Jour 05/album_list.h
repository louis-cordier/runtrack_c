#ifndef ALBUM_LIST_H
#define ALBUM_LIST_H

typedef struct album_list {
    char *artist;
    char *title;
    int year;
    struct album_list *next;
} t_album_list;

#endif // ALBUM_LIST_H
