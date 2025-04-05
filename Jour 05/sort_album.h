#ifndef SORT_ALBUM_H
#define SORT_ALBUM_H

#include "album_list.h"

int compare_by_artist(t_album_list *a, t_album_list *b);
int compare_by_title(t_album_list *a, t_album_list *b);
int compare_by_year(t_album_list *a, t_album_list *b);

#endif // SORT_ALBUM_H
