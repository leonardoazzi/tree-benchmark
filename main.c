#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "abp.h"
#include "avl.h"
#include "dataGen.h"

#define QUANTI 50000

int main()
{
   int *ord;
   int *nonOrd;
   int i;

   srand(time(NULL));

   ord = generateOrderedDataset(QUANTI);
   nonOrd = generateNonOrderedDataset(QUANTI);

   pNodoA *ABP1 = NULL;
   pNodoA *ABP2 = NULL;

   // Cria uma ABP com os dados ordenados
   clock_t begin_ABP_ORD_INS = clock();

   for(i = 0; i < QUANTI; i++){
      ABP1 = InsereArvoreABP(ABP1, ord[i]);
   }
   clock_t end_ABP_ORD_INS = clock();
   double time_ABP_ORD_INS = (double)(end_ABP_ORD_INS - begin_ABP_ORD_INS) / CLOCKS_PER_SEC;

   // Cria uma ABP com os dados não ordenados
   clock_t begin_ABP_NON_INS = clock();

   for(i = 0; i < QUANTI; i++){
      ABP2 = InsereArvoreABP(ABP2, nonOrd[i]);
   }
   clock_t end_ABP_NON_INS = clock();
   double time_ABP_NON_INS = (double)(end_ABP_NON_INS - begin_ABP_NON_INS) / CLOCKS_PER_SEC;

   pNodoAVL *AVL1 = NULL;
   pNodoAVL *AVL2 = NULL;
   int ok;

   // Cria uma AVL com os dados ordenados
   clock_t begin_AVL_ORD_INS = clock();

   for(i = 0; i < QUANTI; i++){
      AVL1 = InsereArvoreAVL(AVL1, ord[i], &ok);
   }
   clock_t end_AVL_ORD_INS = clock();
   double time_AVL_ORD_INS = (double)(end_AVL_ORD_INS - begin_AVL_ORD_INS) / CLOCKS_PER_SEC;

   // Cria uma AVL com os dados não ordenados
   clock_t begin_AVL_NON_INS = clock();

   for(i = 0; i < QUANTI; i++){
      AVL2 = InsereArvoreAVL(AVL2, nonOrd[i], &ok);
   }
   clock_t end_AVL_NON_INS = clock();
   double time_AVL_NON_INS = (double)(end_AVL_NON_INS - begin_AVL_NON_INS) / CLOCKS_PER_SEC;

   /*
   printf("======== Arvore BP Ordenada ========\n\n");
   CentralE(ABP1);
   printf("\n\n\n");

   printf("\n======== Arvore BP Desordenada ========\n\n");
   preFixadoD(ABP2);
   printf("\n\n\n");

   printf("======== Arvore AVL Ordenada ========\n\n");
   CentralE_AVL(AVL1);
   printf("\n\n\n");

   printf("\n======== Arvore AVL Desordenada ========\n\n");
   CentralE_AVL(AVL2);
   printf("\n\n\n");

   printf("\nABP1 e busca: %d\n", eBusca(ABP1));
   printf("\nABP2 e busca: %d\n", eBusca(ABP2));
   */

   // Consulta ABP Ordenada
   printf("\nABP Ordenada");
   pNodoA* resulABP;

   resulABP = consultaABP(ABP1, 0);
   if(resulABP != NULL) printf("\nAchou 0");

   resulABP = consultaABP(ABP1, ((QUANTI/2)-1));
   if(resulABP != NULL) printf("\nAchou %d", ((QUANTI/2)-1));

   resulABP = consultaABP(ABP1, (QUANTI-1));
   if(resulABP != NULL) printf("\nAchou %d", (QUANTI-1));


   printf("\nTempo de Insercao: %lf", time_ABP_ORD_INS);

   // Consulta AVL Ordenada
   printf("\n\nAVL Ordenada");
   if((consultaAVL(AVL1, 0)) != NULL) printf("\nAchou 0");
   if(consultaAVL(AVL1, ((QUANTI/2)-1)) != NULL) printf("\nAchou %d", ((QUANTI/2)-1));
   if(consultaAVL(AVL1, (QUANTI-1))!= NULL) printf("\nAchou %d", (QUANTI-1));
   printf("\nTempo de Insercao: %lf", time_AVL_ORD_INS);

   // Consulta ABP Desordenada
   printf("\n\nABP Desordenada");
   for(i=0; i<10; i++){
      int r = (rand() % QUANTI) + QUANTI;
      if((consultaABP2(ABP2, r)) != NULL) printf("\nAchou %d", r);
   }
   printf("\nTempo de Insercao: %lf", time_ABP_NON_INS);

   // Consulta AVL Desordenada
   printf("\n\nAVL Desordenada");
   for(i=0; i<10; i++){
      int r = (rand() % QUANTI) + QUANTI;
      if((consultaAVL(AVL2, r)) != NULL) printf("\nAchou %d", r);
   }
   printf("\nTempo de Insercao: %lf", time_AVL_NON_INS);

   deletaABP(&ABP1);
   deletaABP(&ABP2);
   deletaAVL(&AVL1);
   deletaAVL(&AVL2);

   return 0;
}


