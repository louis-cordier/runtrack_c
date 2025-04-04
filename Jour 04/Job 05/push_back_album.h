#ifndef PUSH_BACK_ALBUM_H
#define PUSH_BACK_ALBUM_H

typedef struct album_list {
    char *artist;
    char *title;
    int year;
    struct album_list *next;
} t_album_list;

void push_back_album(t_album_list *list, t_album_list *album);

#endif // PUSH_BACK_ALBUM_H
