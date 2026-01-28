#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    //  Posicionamento dos Navios
    //### 1. Criar o tabuleiro 10x10 ###//
   int tabuleiro[10][10];

   //=== 2. Inicializar com água (0) ===//
   for (int linha = 0; linha < 10; linha++) {
       for(int coluna = 0; coluna < 10; coluna++){
          tabuleiro[linha][coluna] = 0;
       }
   }

   //--- 3. Navio horizontal ---//
   for(int i = 0; i < 3; i++) {
      if(tabuleiro[2][1 + i] == 0){
         tabuleiro[2][1 + i] = 3;
      }
   }

   //*** 4. Navio vertical ***//
   for(int i = 0; i < 3; i++){
      if(tabuleiro[4 + i][6] == 0){
         tabuleiro[4 + i][6] = 3;
      }
   }

   // Navio diagonal principal //
   for(int i = 0; i < 3; i++) {
      if(tabuleiro[i][i] == 0) {
         tabuleiro[i][i] = 3;
      }
   }



   // Navio diagonal secundaria //
   for(int i = 0; i < 3; i++){
      if(tabuleiro[1 + i][8 - i] == 0){
         tabuleiro[1 + i][8 - i] = 3;
      }
   } 
    // Exibir o tabuleiro
    for (int linha = 0; linha < 10; linha++) {
       for(int coluna = 0; coluna < 10; coluna++){
          printf("%d ", tabuleiro[linha][coluna]);
       }
       printf("\n");
    }
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
