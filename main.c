#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "abp.h"
#include "avl.h"
#include "dataGen.h"
#include "lse.h"

/*
 Quantidade de dados: 5.000, 10.000, 100.000, 1.000.000
*/
#define QUANTI 1000000
#define N_CONSULTS 4

int main()
{
   int *ord;
   int *nonOrd;
   int i;

   srand(time(NULL));

   /*
      Função: gerar dois conjuntos de dados, com valores únicos: 
      dados ordenados e dados não ordenados.
   */
   ord = generateOrderedDataset(QUANTI);
   nonOrd = generateNonOrderedDataset(QUANTI);

   clock_t begin = clock();
   clock_t end = clock();

   // Setup benchmark
   InfoNo tempos;
   PtNo* listaTempos;
   listaTempos = cria_lista();

   //========================================================================================
   // CRIAÇÃO DAS ÁRVORES
   // ABP e AVL, com dados ordenados e não ordenados
   //========================================================================================
   
   pNodoA *ABP1 = NULL;
   pNodoA *ABP2 = NULL;
   pNodoAVL *AVL1 = NULL;
   pNodoAVL *AVL2 = NULL;

   int ok;

   // Cria uma ABP com os dados ordenados
   for(i = 0; i < QUANTI; i++){
      ABP1 = InsereArvoreABP(ABP1, ord[i]);
   }

   // Cria uma ABP com os dados não ordenados
   for(i = 0; i < QUANTI; i++){
      ABP2 = InsereArvoreABP(ABP2, nonOrd[i]);
   }

   // Cria uma AVL com os dados ordenados
   for(i = 0; i < QUANTI; i++){
      AVL1 = InsereArvoreAVL(AVL1, ord[i], &ok);
   }

   // Cria uma AVL com os dados não ordenados
   for(i = 0; i < QUANTI; i++){
      AVL2 = InsereArvoreAVL(AVL2, nonOrd[i], &ok);
   }

   //========================================================================================
   // CENÁRIO 1: CONSULTA ORDENADA
   //    1.1 Caso ABP
   //       - Primeiro valor
   //       - Valor do meio
   //       - Último valor
   //    1.2 Caso AVL
   //       - Primeiro valor
   //       - Valor do meio
   //       - Último valor
   //========================================================================================

   printf("\n\n------- CONSULTA ORDENADA -------\n");
   printf("Primeiro, do meio e ultimo valor");

   //-------------------------------------------------------------------
   // 1.1 ABP
   //-------------------------------------------------------------------
   printf("\n\n-> ABP Ordenada:");
   pNodoA* resulABP;

   // 1.1.a. Primeiro
   begin = clock();
   resulABP = consultaABP(ABP1, 0);
   end = clock();
   double time_ORD_ABP_1 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Insercao: %lf", time_ORD_ABP_1);

   // 1.1.b. Meio
   begin = clock();
   resulABP = consultaABP(ABP1, ((QUANTI/2)-1));
   end = clock();
   double time_ORD_ABP_2 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Insercao: %lf", time_ORD_ABP_2);

   // 1.1.c. Fim
   begin = clock();
   resulABP = consultaABP(ABP1, (QUANTI-1));
   end = clock();
   double time_ORD_ABP_3 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Insercao: %lf", time_ORD_ABP_3);

   double time_ORD_ABP_MED = (time_ORD_ABP_1 + time_ORD_ABP_2 + time_ORD_ABP_3) / 3;
   
   // SALVA OS DADOS DO TESTE
   tempos.valor = time_ORD_ABP_MED;
   strcpy(tempos.arv, "ABP");
   strcpy(tempos.ord, "ORD");

   listaTempos = insere_ord(listaTempos, tempos);

   //-------------------------------------------------------------------
   // 1.2 AVL
   //-------------------------------------------------------------------
   printf("\n\n-> AVL Ordenada:");

   // 1.2.a. Primeiro
   begin = clock();
   consultaAVL(AVL1, 0);
   end = clock();
   double time_ORD_AVL_1 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Insercao: %lf", time_ORD_AVL_1);
   
   // 1.2.b. Meio  
   begin = clock();
   consultaAVL(AVL1, ((QUANTI/2)-1));
   end = clock();
   double time_ORD_AVL_2 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Insercao: %lf", time_ORD_AVL_2);

   // 1.2.c. Fim
   begin = clock();
   consultaAVL(AVL1, (QUANTI-1));
   end = clock();
   double time_ORD_AVL_3 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Insercao: %lf", time_ORD_AVL_3);

   double time_ORD_AVL_MED = (time_ORD_AVL_1 + time_ORD_AVL_2 + time_ORD_AVL_3) / 3.0;
   
   // SALVA OS DADOS DO TESTE
   tempos.valor = time_ORD_AVL_MED;
   strcpy(tempos.arv, "AVL");
   strcpy(tempos.ord, "ORD");
   listaTempos = insere_ord(listaTempos, tempos);

   //========================================================================================
   // CENÁRIO 2: CONSULTA DESORDENADA
   //    2.1 Caso ABP
   //       - 10 valores aleatórios
   //    2.2 Caso AVL
   //       - 10 valores aleatórios
   //========================================================================================

   printf("\n\n------- CONSULTA DESORDENADA -------\n");
   printf("10 valores aleatorios");

   //-------------------------------------------------------------------
   // 2.1 ABP
   //-------------------------------------------------------------------
   printf("\n\n-> ABP Desordenada:");

   double time_NORD_ABP[10] = {};
   double time_NORD_ABP_sum = 0;

   // 2.1.a. Consulta 10 valores aleatórios
   for(i=0; i<10; i++){

      int r = (rand() % QUANTI) + QUANTI;
      
      begin = clock();
      consultaABP2(ABP2, r);
      end = clock();
      time_NORD_ABP[i] = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\nTempo de Insercao: %lf", time_NORD_ABP[i]);

      time_NORD_ABP_sum = time_NORD_ABP[i] + time_NORD_ABP_sum;
      
   }

   double time_NORD_ABP_med = time_NORD_ABP_sum / 10;

   // SALVA OS DADOS
   tempos.valor = time_NORD_ABP_med;
   strcpy(tempos.arv, "ABP");
   strcpy(tempos.ord, "NORD");

   listaTempos = insere_ord(listaTempos, tempos);

   //-------------------------------------------------------------------
   // 2.2 AVL
   //-------------------------------------------------------------------
   printf("\n\n-> AVL Desordenada:");

   double time_NORD_AVL[10] = {};
   double time_NORD_AVL_sum = 0;

   // 2.2.a. Consulta 10 valores aleatórios
   for(i=0; i<10; i++){

      int r = (rand() % QUANTI) + QUANTI;

      begin = clock();
      consultaAVL(AVL2, r);

      end = clock();
      time_NORD_AVL[i] = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\nTempo de Insercao: %lf", time_NORD_AVL[i]);

      time_NORD_ABP_sum = time_NORD_ABP[i] + time_NORD_ABP_sum;
   }

   double time_NORD_AVL_med = time_NORD_AVL_sum / 10;

   // SALVA OS DADOS
   tempos.valor = time_NORD_AVL_med;
   strcpy(tempos.arv, "AVL");
   strcpy(tempos.ord, "NORD");

   listaTempos = insere_ord(listaTempos, tempos);

   //========================================================================================
   // BENCHMARK
   // Tempos para cada cenário dos casos de teste
   //========================================================================================
   printf("\n\n------- BENCHMARKING -------\n\n");

   printf("\nExibindo a lista...\n");
   imprime(listaTempos);

   //========================================================================================
   // DELETA ÁRVORES
   // Fim
   //========================================================================================

   deletaABP(&ABP1);
   deletaABP(&ABP2);
   deletaAVL(&AVL1);
   deletaAVL(&AVL2);

   return 0;
}


