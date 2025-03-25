#include<stdio.h>
 
#define linhas 10
#define colunas 10

int main(){

    int tabuleiro[linhas][colunas];

    /// prenchendo o tabuleiro com agua (0)
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            tabuleiro[i][j] = 0;  
        }    
    }
    //definindo as posições inciciais dos navios 
    int linha_horizontal = 2, coluna_horizontal = 3;
    int linha_vertical = 5, coluna_vertical = 6;
    int linha_diagonal1 = 1, coluna_diagonal1 = 1;
    int linha_diagonal2 = 6, coluna_diagonal2 = 8;

    for (int i = 0; i < 3; i++){
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }
    for (int j = 0; j < 3; j++){
        tabuleiro[linha_vertical + j][coluna_vertical] = 3;
    }
    // Posicionando o navio diagonal direita (3 casas)
    for (int i = 0; i < 3; i++){
        if (linha_diagonal1 + i < linhas && coluna_diagonal1 + i < colunas){
            tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = 3;
        }    
    }
    // Posicionando o navio diagonal esquerda (3 casas)
    for (int i = 0; i < 3; i++){
        if (linha_diagonal2 + i < linhas && coluna_diagonal2 - i >= 0){
            tabuleiro[linhas_diagonal2 + i][coluna_diagonal2 - i] = 3;
        }      
    }
    //Exibindo as letras das colunas
    printf(" A B C D E F G H I J\n");

    //Exibindo o tabuleiro com numeros na lateral
        for (int i = 0; i < linhas; i++){
            printf("%d ", i + 1);
            for (int j = 0; j < colunas; j++){
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
        
    
    
    return 0;
}