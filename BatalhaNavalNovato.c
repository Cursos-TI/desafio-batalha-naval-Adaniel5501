#include <stdio.h>

#define TAMANHO 10 // Define o tamanho da matriz

int main() {
    int tabuleiro[TAMANHO][TAMANHO]; /// varial TAMANHO

    // Preenchendo o tabuleiro com agua (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definindo as posicoes iniciais dos navios
    int linha_horizontal = 2, coluna_horizontal = 3;
    int linha_vertical = 5, coluna_vertical = 6;

    // Posicionando o navio horizontal (3 casas)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Posicionando o navio vertical (3 casas)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }
        
    // Exibindo as letras das colunas
    printf("  A B C D E F G H I J\n");

    // Exibindo o tabuleiro com numeros na lateral
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i + 1); // Exibe os números de 1 a 10, mas mantém os índices corretos
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
