#include <stdio.h>
#include "print_album.h"

void print_album(album *a) {
    if (a) {
        printf("\"%s\" by \"%s\" released in %d.\n", a->title, a->artist, a->year);
    }
}
