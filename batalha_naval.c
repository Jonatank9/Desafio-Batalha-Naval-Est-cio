#include <stdio.h>

#define LINHAS 15
#define COLUNAS 15

int main() {

    // Criação do cabeçalho da matriz 10x10 para o tabuleiro
    
    int tabuleiro[LINHAS][COLUNAS];
    char x[LINHAS];
    int y[COLUNAS];

    // Inicialização do tabuleiro com água (0), usando loop aninhados para gerar toda a matriz
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
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
 
    for (int i = 0; i < LINHAS; i++) {
        x[i] = 'A' + i; // Preenche o array x com letras
        if (i == 0) {
            printf("   "); // Espaço inicial para alinhar o cabeçalho
        }
        printf(" %c ", x[i]); // Imprime as letras do cabeçalho
    }
   

    // Impressão das linhas do tabuleiro com números e valores
    for (int i = 0; i < COLUNAS; i++) {
            y[i] = i + 1; // Preenche o array y com números
            if (i < 9 ) {
            printf("\n %d ", y[i]);
            } else {
            printf("\n%d ", y[i]);
            }
        for (int j = 0; j < LINHAS; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
    }



   return 0;
}