#ifndef PRINT_ALBUM_H
#define PRINT_ALBUM_H

typedef struct {
    char *title;
    char *artist;
    int year;
} album;

void print_album(album *a);

#endif // PRINT_ALBUM_H
