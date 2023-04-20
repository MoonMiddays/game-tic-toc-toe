#include <stdio.h>

char grid[3][3]; // game field

// function initial of the game
void init_grid() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}

// print the part of game
void print_grid() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", grid[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
}

// who wins or loses ?
int verif_victory(char symbol) {
    int i;
    for (i = 0; i < 3; i++) {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
            return 1;
        }
        if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol) {
            return 1;
        }
    }
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
        return 1;
    }
    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
        return 1;
    }
    return 0;
}

int main() {
    int tour = 0;
    int i, j;
    char symbol = 'X'; 
    
    init_grid();
    print_grid();
    
    // main part of game
    while (tour < 9) {
        printf("player %c, enter the number of your (line column): ", symbol);
        scanf("%d %d", &i, &j);
        
        if (i < 1 || i > 3 || j < 1 || j > 3) {
            printf("wrong coordinate.\n");
            continue;
        }
        
        if (grid[i-1][j-1] != ' ') {
            printf("this case had taken, try again.\n");
            continue;
        }
        
        grid[i-1][j-1] = symbol;
        print_grid();
        
        if (verif_victory(symbol)) {
            printf("Le joueur %c a gagne la partie !\n", symbol);
            return 0;
        }
        
        tour++;
        symbol = (symbol == 'X') ? 'O' : 'X'; // change player
    }
    
    printf("tie score.\n");
    return 0;
}
