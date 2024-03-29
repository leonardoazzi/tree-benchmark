#include <stdio.h>
#include <stdlib.h>
#include "abp.h"
#include "lse.h"

pNodoA* InsereArvoreABP(pNodoA *a, tipoinfo ch)
{
    pNodoA **pp = &a;
    while(*pp != NULL){
        if(ch > (*pp)->info){
            pp = &(*pp)->dir;
        } else{
            pp = &(*pp)->esq;
        }
    }

    *pp =  (pNodoA*) malloc(sizeof(pNodoA));
    (*pp)->info = ch;
    (*pp)->dir = NULL;
    (*pp)->esq = NULL;

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


int consultaABP(pNodoA *a, tipoinfo chave) {

    int comp = 0;
    while (a!=NULL){
        comp++;
        if(a->info == chave ){
            comp++;
            return comp; //achou entao retorna
        
        }else{

            if(a->info > chave){
                comp++;
                a = a->esq;
            }else{
                comp++;
                a = a->dir;
            }
            
        } 
    }

    return comp;
}

void DesenhaABP(pNodoA *a , int nivel){
    int x;

    if (a !=NULL){
        for (x=1; x<=nivel; x++)
            printf("--");

        printf("%d\n", a->info);
        if (a->esq != NULL) DesenhaABP(a->esq, (nivel+1));
        if (a->dir != NULL) DesenhaABP(a->dir, (nivel+1));
    }
}

void _deletaABP(pNodoA* arv)
{
    if (arv == NULL) return;

    _deletaABP(arv->esq);
    _deletaABP(arv->dir);

    free(arv);
}

void deletaABP(pNodoA **arv){
    _deletaABP(*arv);

    *arv = NULL;
}

int eBusca(pNodoA *a){
    int a1;
    int a2;
    int a3;
    int a4;

    if(a == NULL){
        return 1;
    } else {
        if(a->dir == NULL){
            a1 = 1;
        } else a1 = a->info < a->dir->info;

        if(a->esq == NULL){
            a2 = 1;
        } else a2 = a->info > a->esq->info;

        a3 = eBusca(a->dir);

        a4 = eBusca(a->esq);

        //return ((a->info < a->dir->info) && (a->info > a->esq->info) && eBusca(a->dir) && eBusca(a->esq));
        return a1 && a2 && a3 && a4;
    }
}
