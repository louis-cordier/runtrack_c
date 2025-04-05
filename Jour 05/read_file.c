#include "album_list.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

t_album_list *create_album_node(char *artist, char *title, int year) {
    t_album_list *new_album = malloc(sizeof(t_album_list));
    if (!new_album)
        return NULL;
    
    new_album->artist = strdup(artist);
    new_album->title = strdup(title);
    new_album->year = year;
    new_album->next = NULL;
    return new_album;
}

int read_file(const char *filename, t_album_list **list) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        write(2, "File not found.\n", 16);
        return -1;
    }

    char buffer[1024];
    int bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';

        char *line = strtok(buffer, "\n");
        while (line) {
            char *artist = strtok(line, ",");
            char *title = strtok(NULL, ",");
            char *year_str = strtok(NULL, ",");
            if (!artist || !title || !year_str) {
                write(2, "Incorrect format.\n", 18);
                close(fd);
                return -1;
            }

            int year = atoi(year_str);
            t_album_list *new_node = create_album_node(artist, title, year);
            if (!new_node) {
                write(2, "Memory allocation error.\n", 24);
                close(fd);
                return -1;
            }

            new_node->next = *list;
            *list = new_node;

            line = strtok(NULL, "\n");
        }
    }

    close(fd);
    return 0;
}
