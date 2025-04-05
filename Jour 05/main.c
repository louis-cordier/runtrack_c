#include "album_list.h"
#include "sort_album.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        write(2, "Usage: ./music <filename> <sort_method>\n", 39);
        return 1;
    }

    t_album_list *list = NULL;
    if (read_file(argv[1], &list) == -1) {
        return 1;
    }

    if (strcmp(argv[2], "artist") == 0) {
        sort_album_by(list, compare_by_artist);
    } else if (strcmp(argv[2], "title") == 0) {
        sort_album_by(list, compare_by_title);
    } else if (strcmp(argv[2], "year") == 0) {
        sort_album_by(list, compare_by_year);
    } else {
        write(2, "Sort method does not exist.\n", 27);
        return 1;
    }

    print_album(list);
    return 0;
}
