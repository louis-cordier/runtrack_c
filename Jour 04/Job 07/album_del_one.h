#ifndef ALBUM_DEL_ONE_H
#define ALBUM_DEL_ONE_H

typedef struct album_list {
    char *artist;
    char *title;
    int year;
    struct album_list *next;
} t_album_list;

void album_del_one(t_album_list ***list, t_album_list *elem);

#endif // ALBUM_DEL_ONE_H
