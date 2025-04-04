#include "sort_album_by.h"
#include <stddef.h>  // Assurez-vous d'inclure cette bibliothèque pour NULL

void sort_album_by(t_album_list *list, int (*fun)(t_album_list*, t_album_list*)) {
    if (!list || !fun) {
        return; // Vérification des pointeurs
    }

    t_album_list *current = list;
    t_album_list *min = NULL;
    t_album_list *temp;

    // Parcours de la liste
    while (current != NULL) {
        min = current; // On commence avec l'élément actuel comme minimum

        // Recherche de l'élément minimum selon la fonction de comparaison
        t_album_list *next = current->next;
        while (next != NULL) {
            if (fun(min, next) > 0) {
                min = next;
            }
            next = next->next;
        }

        // Si l'élément minimum n'est pas l'élément actuel, on échange
        if (min != current) {
            // Échanger les valeurs des albums
            temp = current->artist;
            current->artist = min->artist;
            min->artist = temp;

            temp = current->title;
            current->title = min->title;
            min->title = temp;

            int temp_year = current->year;
            current->year = min->year;
            min->year = temp_year;
        }

        current = current->next;
    }
}
