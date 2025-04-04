#include "album_del_one.h"
#include <stdlib.h>

void album_del_one(t_album_list ***list, t_album_list *elem) {
    if (!list || !*list || !elem) {
        return; // Vérification des pointeurs
    }

    t_album_list *current = **list;
    t_album_list *previous = NULL;

    // Si l'élément à supprimer est le premier de la liste
    if (current == elem) {
        **list = current->next; // La tête de la liste devient le suivant
        free(current);           // Libération de l'élément
        return;
    }

    // Parcours de la liste pour trouver l'élément
    while (current && current != elem) {
        previous = current;
        current = current->next;
    }

    // Si l'élément n'a pas été trouvé
    if (!current) {
        return;
    }

    // L'élément est dans la liste, on le supprime
    previous->next = current->next; // Le précédent pointe vers le suivant
    free(current);                   // Libération de l'élément
}
