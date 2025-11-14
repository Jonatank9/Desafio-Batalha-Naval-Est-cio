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

        // Posicionamento de dois navios com valor 3 na matriz
    for (int i = 3; i < 6; i++) {
        tabuleiro[2][i] = 3; // Navio horizontal na linha 3, colunas D a F
    }

    for (int i = 5; i < 8; i++) {
        tabuleiro[i][7] = 3; // Navio vertical na coluna H, linhas 6 a 8
    }

    // Impressão do tabuleiro formatado

    printf("*** Tabuleiro de Batalha Naval ***\n\n");
    printf("**********Desafio Novato**********\n\n");

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