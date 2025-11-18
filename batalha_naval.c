#include <stdio.h>

#define LINHAS 15
#define COLUNAS 15
#define NAVIOS 4
#define TAMANHO_NAVIO 3
#define TENTATIVAS 25

// Função para inicializar o tabuleiro (vai se repetir mais tarde várias vezes, chamando a cada tentativa do jogador)

void inicializarTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    int x[LINHAS];
    char y[COLUNAS];

    for (int i = 0; i < LINHAS; i++) {
        x[i] = i + 1; // Preenche os números para as linhas
        if (i == 0) {
            printf(" "); // Espaço inicial para o cabeçalho
        }
        printf(" %2d", x[i]); // Imprime o cabeçalho das linhas
    }
    printf("\n");
    for (int i = 0; i < LINHAS; i++) {
        if (i < COLUNAS) {
            y[i] = 'A' + i; // Preenche as letras para as colunas
            printf("%c ", y[i]); // Imprime o cabeçalho das colunas
    }
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = '~'; // Inicializa o tabuleiro com água
            printf(" %c ", tabuleiro[i][j]); // Imprime o tabuleiro inicializado
        }
    printf("\n");
    }
     printf("\nlegenda: ~ = água, # = navio, X = acerto, O = erro\n\n");
}

int main() {

    // Criação do cabeçalho da matriz
    
    int tabuleiro[LINHAS][COLUNAS];
    char x[LINHAS];
    int y[COLUNAS];
    int tentativas = TENTATIVAS;
    int navios = NAVIOS;
    int tamanho_navio = TAMANHO_NAVIO;

    // Impressão do tabuleiro em branco

    printf("*** Tabuleiro de Batalha Naval ***\n\n");
    printf("**********Desafio Novato**********\n\n");

    printf("Você terá ao todo %d tentativas para afundar os %d navios inimigos, cada um com tamanho %d espaços.\n\n", tentativas, navios, tamanho_navio);
    printf("Boa sorte, comandante!\n\n");


    inicializarTabuleiro(tabuleiro);


    



   return 0;
}