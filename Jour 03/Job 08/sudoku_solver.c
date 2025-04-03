#include <stdio.h>

int is_valid(int grid[9][9], int row, int col, int num) {
    // Vérifie la ligne
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num)
            return 0;

    // Vérifie la colonne
    for (int x = 0; x < 9; x++)
        if (grid[x][col] == num)
            return 0;

    // Vérifie le bloc 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return 0;

    return 1;
}

int find_empty_cell(int grid[9][9], int *row, int *col) {
    for (*row = 0; *row < 9; (*row)++)
        for (*col = 0; *col < 9; (*col)++)
            if (grid[*row][*col] == 0)
                return 1;
    return 0;
}

int sudoku_solver(int grid[9][9]) {
    int row, col;

    if (!find_empty_cell(grid, &row, &col))
        return 1; // Toutes les cellules sont remplies

    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;

            if (sudoku_solver(grid))
                return 1;

            grid[row][col] = 0; // Backtrack
        }
    }
    return 0; // Pas de solution
}

/*********************/
/* CODE DE TEST CI-DESSOUS */
/*********************/

void print_grid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0)
            printf("------+-------+------\n");
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0)
                printf("| ");
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void test_sudoku(int grid[9][9], int expected) {
    printf("Grille initiale:\n");
    print_grid(grid);
    
    // Créer une copie pour ne pas modifier l'original
    int grid_copy[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            grid_copy[i][j] = grid[i][j];
    
    int result = sudoku_solver(grid_copy);
    
    if (result == expected) {
        printf("Test %s!\n", result ? "réussi" : "échoué (comme attendu)");
        if (result) {
            printf("Solution trouvée:\n");
            print_grid(grid_copy);
        }
    } else {
        printf("Test inattendu! Obtenu: %d, Attendue: %d\n", result, expected);
    }
    printf("--------------------------------\n");
}

int main() {
    // Test 1: Grille facile avec solution
    int grid1[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    test_sudoku(grid1, 1);

    // Test 2: Grille déjà complète
    int grid2[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };
    test_sudoku(grid2, 1);

    // Test 3: Grille impossible
    int grid3[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 0, 0}
    };
    grid3[0][0] = 6; // Crée un conflit avec le 6 en dessous
    test_sudoku(grid3, 0);

    // Test 4: Grille vide (doit trouver une solution)
    int grid4[9][9] = {0};
    test_sudoku(grid4, 1);

    return 0;
}