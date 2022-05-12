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
#define QUANT_A 5000
#define QUANT_B 10000
#define QUANT_C 100000
#define QUANT_D 1000000

#define N_CONSULTS 4

void benchmark(int quant)
{
   int *ord;
   int *nonOrd;
   int i;

   srand(time(NULL));

   /*
      Função: gerar dois conjuntos de dados, com valores únicos: 
      dados ordenados e dados não ordenados.
   */
   ord = generateOrderedDataset(quant);
   nonOrd = generateNonOrderedDataset(quant);
   
   pNodoA *ABP1 = NULL;
   pNodoA *ABP2 = NULL;
   pNodoAVL *AVL1 = NULL;
   pNodoAVL *AVL2 = NULL;

   clock_t begin = clock();
   clock_t end = clock();

   // Setup benchmark
   InfoNo bench;
   PtNo* listaTempos;
   PtNo* listaInsere;
   listaInsere = cria_lista();
   listaTempos = cria_lista();

   int ok;

   //========================================================================================
   // INSERE ABP ORDENADA
   // Cria uma ABP com os dados ordenados
   //========================================================================================
   
   int insere_ORD_ABP = 0;
   begin = clock();

   // Insere
   for(i = 0; i < quant; i++){
      ABP1 = InsereArvoreABP(ABP1, ord[i]);
   }

   end = clock();
   double tempo_insere_ORD_ABP = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Insercao: %lf", tempo_insere_ORD_ABP);
   //printf("\nNumero de Comparacoes: %d", comp_ORD_ABP_3);
   
   // SALVA OS DADOS DO TESTE
   bench.tempo = tempo_insere_ORD_ABP;
   bench.compara = 0.000;
   strcpy(bench.arv, "ABP");
   strcpy(bench.ord, "ORD");

   listaInsere = insere_ord(listaInsere, bench);
   
   //========================================================================================
   // INSERE ABP NÃO ORDENADA
   // Cria uma ABP com os dados não ordenados
   //========================================================================================
   int insere_NORD_ABP = 0;
   begin = clock();

   for(i = 0; i < quant; i++){
      ABP2 = InsereArvoreABP(ABP2, nonOrd[i]);
   }

   end = clock();
   double tempo_insere_NORD_ABP = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Insercao: %lf", tempo_insere_NORD_ABP);
   //printf("\nNumero de Comparacoes: %d", comp_ORD_ABP_3);
   
   // SALVA OS DADOS DO TESTE
   bench.tempo = tempo_insere_NORD_ABP;
   strcpy(bench.arv, "ABP");
   strcpy(bench.ord, "NORD");

   listaInsere = insere_ord(listaInsere, bench);

   //========================================================================================
   // INSERE AVL NÃO ORDENADA
   // Cria uma AVL com os dados ordenados
   //========================================================================================
   int insere_ORD_AVL = 0;
   begin = clock();

   for(i = 0; i < quant; i++){
      AVL1 = InsereArvoreAVL(AVL1, ord[i], &ok);
   }

   end = clock();
   double tempo_insere_ORD_AVL = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Insercao: %lf", tempo_insere_ORD_AVL);
   //printf("\nNumero de Comparacoes: %d", comp_ORD_ABP_3);
   
   // SALVA OS DADOS DO TESTE
   bench.tempo = tempo_insere_ORD_AVL;
   strcpy(bench.arv, "AVL");
   strcpy(bench.ord, "ORD");

   listaInsere = insere_ord(listaInsere, bench);

   //========================================================================================
   // INSERE AVL NÃO ORDENADA
   // Cria uma AVL com os dados não ordenados
   //========================================================================================
   int insere_NORD_AVL = 0;
   begin = clock();

   for(i = 0; i < quant; i++){
      AVL2 = InsereArvoreAVL(AVL2, nonOrd[i], &ok);
   }

   end = clock();
   double tempo_insere_NORD_AVL = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Insercao: %lf", tempo_insere_NORD_AVL);
   //printf("\nNumero de Comparacoes: %d", comp_ORD_ABP_3);
   
   // SALVA OS DADOS DO TESTE
   bench.tempo = tempo_insere_NORD_AVL;
   strcpy(bench.arv, "AVL");
   strcpy(bench.ord, "NORD");

   listaInsere = insere_ord(listaInsere, bench);


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
   int comp_ORD_ABP_1 = 0;
   begin = clock();
   comp_ORD_ABP_1 = consultaABP(ABP1, 0);
   end = clock();
   double time_ORD_ABP_1 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Consulta: %lf", time_ORD_ABP_1);
   printf("\nNumero de Comparacoes: %d", comp_ORD_ABP_1);

   // 1.1.b. Meio
   int comp_ORD_ABP_2 = 0;
   begin = clock();
   comp_ORD_ABP_2 = consultaABP(ABP1, ((quant/2)-1));
   end = clock();
   double time_ORD_ABP_2 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Consulta: %lf", time_ORD_ABP_2);
   printf("\nNumero de Comparacoes: %d", comp_ORD_ABP_2);

   // 1.1.c. Fim
   int comp_ORD_ABP_3 = 0;
   begin = clock();
   comp_ORD_ABP_3 = consultaABP(ABP1, (quant-1));
   end = clock();
   double time_ORD_ABP_3 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Consulta: %lf", time_ORD_ABP_3);
   printf("\nNumero de Comparacoes: %d", comp_ORD_ABP_3);

   double time_ORD_ABP_MED = (time_ORD_ABP_1 + time_ORD_ABP_2 + time_ORD_ABP_3) / 3;
   int comp_ORD_ABP_MED = (comp_ORD_ABP_1 + comp_ORD_ABP_2 + comp_ORD_ABP_3) / 3;
   
   // SALVA OS DADOS DO TESTE
   bench.tempo = time_ORD_ABP_MED;
   bench.compara = comp_ORD_ABP_MED;
   strcpy(bench.arv, "ABP");
   strcpy(bench.ord, "ORD");

   listaTempos = insere_ord(listaTempos, bench);

   //-------------------------------------------------------------------
   // 1.2 AVL
   //-------------------------------------------------------------------
   printf("\n\n-> AVL Ordenada:");

   // 1.2.a. Primeiro
   int comp_ORD_AVL_1 = 0;
   begin = clock();
   comp_ORD_AVL_1 = consultaAVL(AVL1, 0);
   end = clock();
   double time_ORD_AVL_1 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Consulta: %lf", time_ORD_AVL_1);
   printf("\nNumero de Comparacoes: %d", comp_ORD_AVL_1);
   
   // 1.2.b. Meio
   int comp_ORD_AVL_2 = 0;
   begin = clock();
   comp_ORD_AVL_2 = consultaAVL(AVL1, ((quant/2)-1));
   end = clock();
   double time_ORD_AVL_2 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Consulta: %lf", time_ORD_AVL_2);
   printf("\nNumero de Comparacoes: %d", comp_ORD_AVL_2);

   // 1.2.c. Fim
   int comp_ORD_AVL_3 = 0;
   begin = clock();
   comp_ORD_AVL_3 = consultaAVL(AVL1, (quant-1));
   end = clock();
   double time_ORD_AVL_3 = (double)(end - begin) / CLOCKS_PER_SEC;

   printf("\nTempo de Consulta: %lf", time_ORD_AVL_3);
   printf("\nNumero de Comparacoes: %d", comp_ORD_AVL_3);

   double time_ORD_AVL_MED = (time_ORD_AVL_1 + time_ORD_AVL_2 + time_ORD_AVL_3) / 3.0;
   int comp_ORD_AVL_MED = (comp_ORD_AVL_1 + comp_ORD_AVL_2 + comp_ORD_AVL_3) / 3;
   
   // SALVA OS DADOS DO TESTE
   bench.tempo = time_ORD_AVL_MED;
   bench.compara = comp_ORD_AVL_MED;
   strcpy(bench.arv, "AVL");
   strcpy(bench.ord, "ORD");
   listaTempos = insere_ord(listaTempos, bench);

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

   int comp_NORD_ABP[10] = {};
   int comp_NORD_ABP_sum = 0;

   // 2.1.a. Consulta 10 valores aleatórios
   for(i=0; i<10; i++){

      int r = (rand() % quant) + quant;
      
      begin = clock();
      comp_NORD_ABP[i] = consultaABP(ABP2, r);
      end = clock();
      time_NORD_ABP[i] = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\nTempo de Consulta: %lf", time_NORD_ABP[i]);
      printf("\nNumero de Comparacoes: %d", comp_NORD_ABP[i]);

      time_NORD_ABP_sum = time_NORD_ABP[i] + time_NORD_ABP_sum;
      comp_NORD_ABP_sum = comp_NORD_ABP[i] + comp_NORD_ABP_sum;
      
   }

   double time_NORD_ABP_med = time_NORD_ABP_sum / 10;
   int comp_NORD_ABP_med = comp_NORD_ABP_sum / 10;

   // SALVA OS DADOS
   bench.tempo = time_NORD_ABP_med;
   bench.compara = comp_NORD_ABP_med;
   strcpy(bench.arv, "ABP");
   strcpy(bench.ord, "NORD");

   listaTempos = insere_ord(listaTempos, bench);

   //-------------------------------------------------------------------
   // 2.2 AVL
   //-------------------------------------------------------------------
   printf("\n\n-> AVL Desordenada:");

   double time_NORD_AVL[10] = {};
   double time_NORD_AVL_sum = 0;

   int comp_NORD_AVL[10] = {};
   int comp_NORD_AVL_sum = 0;

   // 2.2.a. Consulta 10 valores aleatórios
   for(i=0; i<10; i++){

      int r = (rand() % quant) + quant;

      begin = clock();
      comp_NORD_AVL[i] = consultaAVL(AVL2, r);
      end = clock();
      time_NORD_AVL[i] = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\nTempo de Consulta: %lf", time_NORD_AVL[i]);
      printf("\nNumero de Comparacoes: %d", comp_NORD_AVL[i]);

      time_NORD_AVL_sum = time_NORD_AVL[i] + time_NORD_AVL_sum;
      comp_NORD_AVL_sum = comp_NORD_AVL[i] + comp_NORD_AVL_sum;
   }

   double time_NORD_AVL_med = time_NORD_AVL_sum / 10;
   int comp_NORD_AVL_med = comp_NORD_AVL_sum / 10;

   // SALVA OS DADOS
   bench.tempo = time_NORD_AVL_med;
   bench.compara = comp_NORD_AVL_med;
   strcpy(bench.arv, "AVL");
   strcpy(bench.ord, "NORD");

   listaTempos = insere_ord(listaTempos, bench);

   //========================================================================================
   // BENCHMARK
   // Tempos para cada cenário dos casos de teste
   //========================================================================================
   printf("\n\n------- BENCHMARKING -------\n\n");
   printf("Cenário: %d dados\n", quant);

   printf("\n\n--------------------------------\n");
   printf("Resultados do Insere\n");
   printf("--------------------------------\n");
   imprime(listaInsere);

   printf("\n\n--------------------------------\n");
   printf("Resultados de Consulta\n");
   printf("--------------------------------\n");
   imprime(listaTempos);

   //========================================================================================
   // DELETA ÁRVORES
   // Fim
   //========================================================================================
   deletaABP(&ABP1);
   deletaABP(&ABP2);
   deletaAVL(&AVL1);
   deletaAVL(&AVL2);

}


int main()
{

   printf("=========================================\n");
   printf(" ABP/AVL BENCHMARK\n");
   printf(" Breno Morais e Leonardo A. Martins\n");
   printf("=========================================\n");
   printf("\n\n");

   // Cenário a: 5000 dados
   printf("\n\n-----------------------------------------\n");
   printf("CENÁRIO A: 5.000 dados\n");
   printf("-----------------------------------------\n");

   benchmark(QUANT_A);

   // Cenário b: 10.000 dados
   printf("\n\n-----------------------------------------\n");
   printf("CENÁRIO B: 10.000 dados\n");
   printf("-----------------------------------------\n");

   benchmark(QUANT_B);

   // Cenário c: 100.000 dados
   printf("\n\n-----------------------------------------\n");
   printf("CENÁRIO C: 100.000 dados\n");
   printf("-----------------------------------------\n");

   benchmark(QUANT_C);

   // Cenário d: 1.000.000 de dados
   printf("\n\n-----------------------------------------\n");
   printf("CENÁRIO D: 1.000.000 dados\n");
   printf("-----------------------------------------\n");

   benchmark(QUANT_D);

   return 0;
}

