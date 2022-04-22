#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

pNodoA* InsereArvore(pNodoA *a, tipoinfo ch)
{
     if (a == NULL)
     {
         a =  (pNodoA*) malloc(sizeof(pNodoA));
         a->info = ch;
         a->esq = NULL;
         a->dir = NULL;
         return a;
     }
     else
          if (ch < a->info)
              a->esq = InsereArvore(a->esq,ch);
          else if (ch > a->info)
              a->dir = InsereArvore(a->dir,ch);
     return a;
}

void preFixadoE(pNodoA *a)
{
     if (a!= NULL)
     {
          printf("%d - ",a->info);
          preFixadoE(a->esq);
          preFixadoE(a->dir);
      }
}

void preFixadoD(pNodoA *a)
{
     if (a!= NULL)
     {
          printf("%d - ",a->info);
          preFixadoD(a->dir);
          preFixadoD(a->esq);
      }
}

void posFixadoE(pNodoA *a)
{
     if (a!= NULL)
     {
          posFixadoE(a->esq);
          posFixadoE(a->dir);
          printf("%d - ",a->info);
      }
}

void posFixadoD(pNodoA *a)
{
     if (a!= NULL)
     {
          posFixadoD(a->dir);
          posFixadoD(a->esq);
          printf("%d - ",a->info);
      }
}

void CentralE(pNodoA *a)
{
     if (a!= NULL)
     {
          CentralE(a->esq);
          printf("%d - ",a->info);
          CentralE(a->dir);
      }
}

void CentralD(pNodoA *a)
{
     if (a!= NULL)
     {
          CentralD(a->dir);
          printf("%d - ",a->info);
          CentralD(a->esq);
      }
}


pNodoA* consultaABP(pNodoA *a, tipoinfo chave) {

    while (a!=NULL){
          if (a->info == chave )
             return a; //achou entao retorna o ponteiro para o nodo
          else
            if (a->info > chave)
               a = a->esq;
            else
               a = a->dir;
            }
            return NULL; //se nao achou
}

pNodoA* consultaABP2(pNodoA *a, tipoinfo chave) {
    if (a!=NULL) {
       if (a->info == chave)
         return a;
       else
           if (a->info > chave)
                return consultaABP2(a->esq,chave);
            if (a->info < chave)
                return consultaABP2(a->dir,chave);

            else return a;
       }
       else return NULL;
}


