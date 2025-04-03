#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Vérifier si un argument a été fourni
    if (argc != 2) {
        return 0; // Ne rien faire si aucun argument
    }

    // Convertir l'argument en entier
    int n = atoi(argv[1]);

    // Calculer le nombre de Fibonacci
    int a = 0, b = 1, temp;
    
    if (n == 0) {
        printf("%d\n", a);
        return 0;
    }
    
    for (int i = 2; i <= n; i++) {
        temp = b;
        b = a + b;
        a = temp;
    }

    // Afficher le résultat
    printf("%d\n", b);

    return 0;
}