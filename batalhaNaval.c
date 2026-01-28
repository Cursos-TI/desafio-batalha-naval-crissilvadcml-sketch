#include <stdio.h>


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

   //*** Nível Mestre com habilidades ***

   int cone[5][5];
   int cruz[5][5];
   int octaedro[5][5];

   int centro = 2; // centro da matriz 5x5

   // Inicializar matrizes de habilidades com 0

   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
         cone[i][j] = 0;
         cruz[i][j] = 0;
         octaedro[i][j] = 0;
      }
   }


   //======== Habilidade cone ========

   // cone apontando para baixo

   for (int i = 0; i < 5; i++){
      for (int j = 0; j< 5; j++) {
         if (j >= centro - i && j <= centro + i) {
            cone[i][j] = 1;

         }
      }
   }


   // **** Habilidade cruz ****
   
   for (int i = 0; i< 5; i++) {
      for (int j = 0; j < 5; j++) {
         if (i == centro || j == centro) {
            cruz[i][j] = 1;

         }
      }
   }


   //###### Habilidade octaedro ######

   for (int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
         if (((i - centro) < 0 ? -(i - centro) : (i - centro)) +
    ((j - centro) < 0 ? -(j - centro) : (j - centro)) <= centro) {
    octaedro[i][j] = 1;
       
         }
      }
   }



   // ================= ORIGEM DAS HABILIDADES =================

   int origemConeLinha = 3; int origemConeColuna = 3;
   int origemCruzLinha = 6; int origemCruzColuna = 2;
   int origemOctLinha = 6;  int origemOctColuna = 7;


   int tabLinha, tabColuna;


   // SOBREPOSIÇÃO DO CONE NO TABULEIRO
   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {


         tabLinha = origemConeLinha + i - centro;
         tabColuna = origemConeColuna + j - centro;

         if (tabLinha >= 0 && tabLinha < 10 && 
             tabColuna >= 0 && tabColuna < 10) {

            if (cone[i][j] == 1 && tabuleiro[tabLinha][tabColuna] == 0) {
               tabuleiro[tabLinha][tabColuna] = 5;
            }
         }
      }
   }


   // SOBREPOSIÇÃO DA CRUZ NO TABULEIRO

   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {

         tabLinha = origemCruzLinha + i - centro;
         tabColuna = origemCruzColuna + j - centro;

         if (tabLinha >= 0 && tabLinha < 10 && 
             tabColuna >= 0 && tabColuna < 10) {

            if (cruz[i][j] == 1 && tabuleiro[tabLinha][tabColuna] == 0) {
               tabuleiro[tabLinha][tabColuna] = 5;
            }
         }
      }
   }

   // SOBREPOSIÇÃO DO OCTAEDRO NO TABULEIRO

   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {

         tabLinha = origemOctLinha + i - centro;
         tabColuna = origemOctColuna + j - centro;

         if (tabLinha >= 0 && tabLinha < 10 && 
             tabColuna >= 0 && tabColuna < 10) {

            if (octaedro[i][j] == 1 && tabuleiro[tabLinha][tabColuna] == 0) {
               tabuleiro[tabLinha][tabColuna] = 5;
            }
         }
      }
   }
   // ================= EXIBIÇÃO FINAL DO TABULEIRO =================

   printf("\n=== Tabuleiro com Navios e Habilidades ===\n");

   for(int linha = 0; linha < 10; linha++) {
      for(int coluna = 0; coluna < 10; coluna++) {
         
         if (tabuleiro[linha][coluna] == 0) {
            printf("0 "); // Água
         } else if (tabuleiro[linha][coluna] == 3) {
            printf("3 "); // Navio
         } else if (tabuleiro[linha][coluna] == 5) {
            printf("5 "); // Habilidade
         }
      }
      printf("\n");
   }

   return 0;
}
