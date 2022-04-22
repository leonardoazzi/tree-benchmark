#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"

int main()
{
   pNodoA *arv1 = NULL;

   arv1 = InsereArvore(arv1,30);
   arv1 = InsereArvore(arv1,45);
   arv1 = InsereArvore(arv1,25);
   arv1 = InsereArvore(arv1,90);
   arv1 = InsereArvore(arv1,80);
   arv1 = InsereArvore(arv1,95);
   
   printf("--Pre Esquerda --\n");
   CentralE(arv1);
   printf("\n\n");
    
   printf("--Pre Direita --\n");
   CentralD(arv1);
   printf("\n\n");

   printf("--Central Esquerda --\n");
   CentralE(arv1);
   printf("\n\n");
    
   printf("--Central Direita --\n");
   CentralD(arv1);
   printf("\n\n");
    
   printf("--Pos Esquerda --\n");
   posFixadoE(arv1);
   printf("\n\n");
    
   printf("--Pos Direita --\n");
   posFixadoD(arv1);
   printf("\n\n");
    
}


