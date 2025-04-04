#include "push_front_album.h"

void push_front_album(t_album_list **list, t_album_list *album) {
    if (!list || !album) {
        return; // Vérification des pointeurs
    }

    album->next = *list; // L'album pointe vers l'ancienne tête de liste
    *list = album;       // L'album devient la nouvelle tête de liste
}
