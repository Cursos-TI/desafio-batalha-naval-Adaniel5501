#include<stdio.h>          

#define LINHAS 10
#define COLUNAS 10

void ImprimirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    printf("   A B C D E F G H I J\n"); // Letras das colunas
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1); // Números das linhas
        for (int j = 0; j < COLUNAS; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ "); // Água
            } else if (tabuleiro[i][j] == 1) {
                printf("1 "); // Cone
            } else if (tabuleiro[i][j] == 2) {
                printf("2 "); // Cruz
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); // Octaedro
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[LINHAS][COLUNAS]; // declara o tabuleiro
    
    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posição dos pontos de origem das habilidades
    int linha_cone = 1, coluna_cone = 3;
    int linha_cruz = 5, coluna_cruz = 7;
    int linha_octaedro = 7, coluna_octaedro = 2;

    // Habilidade do cone 
    for (int i = 0; i < 3; i++) { // Altura do cone (3 linhas)
        for (int j = -i; j <= i; j++) { // Expande simetricamente para os lados
            int LINHA = linha_cone + i;
            int COLUNA = coluna_cone + j;
            if (LINHA >= 0 && LINHA < LINHAS && COLUNA >= 0 && COLUNA < COLUNAS) {
                tabuleiro[LINHA][COLUNA] = 1;
            }
        }
    }

    // Habilidade da cruz 
    for (int i = -2; i <= 2; i++) {
        if (linha_cruz + i >= 0 && linha_cruz + i < LINHAS) {
            tabuleiro[linha_cruz + i][coluna_cruz] = 2;
        }
        if (coluna_cruz + i >= 0 && coluna_cruz + i < COLUNAS) {
            tabuleiro[linha_cruz][coluna_cruz + i] = 2;
        }
    }

    // Habilidade do octaedro 
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if ((i + j >= -2) && (i + j <= 2) && (i - j >= -2) && (i - j <= 2)) {
                int linha = linha_octaedro + i;
                int coluna = coluna_octaedro + j;
                if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
                    tabuleiro[linha][coluna] = 3;
                }
            }
        }
    }

    ImprimirTabuleiro(tabuleiro); /// imprimir o tabuleiro,(dessa formato é bem mais facil!)

    return 0;
}