#include "push_back_album.h"

void push_back_album(t_album_list *list, t_album_list *album) {
    if (!list || !album) {
        return; // Vérification des pointeurs
    }

    while (list->next) {
        list = list->next; // Parcours jusqu'au dernier élément
    }

    list->next = album; // Ajout de l'album à la fin
}
