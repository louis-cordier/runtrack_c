#ifndef SORT_ALBUM_BY_H
#define SORT_ALBUM_BY_H

typedef struct album_list {
    char *artist;
    char *title;
    int year;
    struct album_list *next;
} t_album_list;

void sort_album_by(t_album_list *list, int (*fun)(t_album_list*, t_album_list*));

#endif // SORT_ALBUM_BY_H
