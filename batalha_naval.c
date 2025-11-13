#include <stdio.h>

int main() {

    // Criação da matriz 10x10 para o tabuleiro
    
    char x[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int y[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tabuleiro[10][10];

    // Inicialização do tabuleiro com água (0), usando loop aninhados para gerar toda a matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // Inicializa todas as posições com 0, já que 0 representa água
        }
    }

    // Impressão do tabuleiro formatado

    // Impressão do cabeçalho com letras
    for (int i = 0; i < 10; i++) {
            if (i == 0) {
            printf("    %c ", x[i]);
            } else {
            printf(" %c ", x[i]);
    }
    }

    // Impressão das linhas do tabuleiro com números e valores
    for (int i = 0; i < 10; i++) {
            if (i < 9) {
            printf("\n %d ", y[i]);
            } else {
            printf("\n%d ", y[i]);
            }
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
    }


   return 0;
}