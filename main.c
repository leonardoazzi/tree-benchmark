#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"
#include "avl.h"
#include "dataGen.h"

#define QUANTI 1000

int main()
{
   int *ord;
   int *nonOrd;
   int i;

   ord = generateOrderedDataset(QUANTI);
   nonOrd = generateNonOrderedDataset(QUANTI);

   pNodoA *ABP1 = NULL;
   pNodoA *ABP2 = NULL;

   // Cria uma ABP com os dados ordenados
   for(i = 0; i < QUANTI; i++){
      ABP1 = InsereArvoreABP(ABP1, ord[i]);
   }

   // Cria uma ABP com os dados não ordenados
   for(i = 0; i < QUANTI; i++){
      ABP2 = InsereArvoreABP(ABP2, nonOrd[i]);
   }

   pNodoAVL *AVL1 = NULL;
   pNodoAVL *AVL2 = NULL;
   int ok;

   // Cria uma AVL com os dados ordenados
   for(i = 0; i < QUANTI; i++){
      AVL1 = InsereArvoreAVL(AVL1, ord[i], &ok);
   }

   // Cria uma AVL com os dados não ordenados
   for(i = 0; i < QUANTI; i++){
      AVL2 = InsereArvoreAVL(AVL2, nonOrd[i], &ok);
   }

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

   deletaABP(&ABP1);
   deletaABP(&ABP2);
   deletaAVL(&AVL1);
   deletaAVL(&AVL2);

   return 0;
}


