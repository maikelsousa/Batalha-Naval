#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {
        {0,3,0,0,0,0,0,0,0,0},
        {0,0,3,0,0,0,0,0,0,0},
        {0,0,0,3,0,0,0,0,0,0},
        {0,0,0,0,3,3,3,3,0,0},
        {0,0,0,0,0,0,0,0,3,0},
        {0,0,0,3,0,0,0,3,0,0},
        {0,0,0,3,0,0,3,0,0,0},
        {0,0,0,3,0,3,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Cabeçalho das colunas
    printf("    ");
    for (int c = 0; c < 10; c++) {
        printf(" %c", colunas[c]);
    }
    printf("\n");

    // Exibe o tabuleiro com números das linhas à esquerda
    for (int row = 0; row < 10; row++) {
        printf("%2d |", row + 1);  // Identificador à esquerda
        for (int col = 0; col < 10; col++) {
            printf(" %d", tabuleiro[row][col]);
        }
        printf("\n");
    }

    return 0;
}
