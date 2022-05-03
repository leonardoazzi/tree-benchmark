#include <stdio.h>
#include <stdlib.h>  //necessaria para o malloc
#include <string.h> //necessaria para o strcmp
#include "lse.h"

PtNo* cria_lista(void)
{
       return NULL;
}

// Funcao para inserir um numero no inicio da lista
PtNo* insereIni(PtNo* ptLista, InfoNo dados) {

    PtNo *novo;

    novo = (PtNo*) malloc(sizeof(PtNo));
    novo->info = dados;

    novo->prox = ptLista;
    ptLista = novo;

    return ptLista;
}

// Function to insert a given node at its correct sorted position into a given
// list sorted in increasing order
void sortedInsert(PtNo* ptLista, PtNo* novo)
{

 
    while (ptLista->prox != NULL &&  (ptLista->info.tempo < novo->info.tempo) ) {
        ptLista = ptLista->prox;
    }
 
    novo->prox = ptLista->prox;
    ptLista->prox = novo;
    ptLista = ptLista->prox;


}

PtNo* insere_ord (PtNo* ptLista, InfoNo dados)
{
    PtNo *novo; //novo elemento
    PtNo *ant = NULL; //ponteiro auxiliar para a posição anterior
    PtNo *ptaux = ptLista; //ponteiro auxiliar para percorrer a lista

    /*aloca um novo nodo */
    novo = (PtNo*) malloc(sizeof(PtNo));

    /*insere a informação no novo nodo*/
    novo->info = dados;

    if(ptLista == NULL){
        novo->prox = ptLista;
        ptLista = novo;

    } else {

        while(ptaux->prox != NULL) {
            ptaux = ptaux->prox;
        }

        ptaux->prox = novo;
        novo->prox = NULL;
    }


    return ptLista;
}

PtNo* classifica_lista(PtNo* ptLista){

    PtNo* ptaux;

    for (ptaux=ptLista; ptaux!=NULL; ptaux=ptaux->prox){
        if (ptaux->info.tempo > ptaux->prox->info.tempo){

        }

    }

}

void imprime(PtNo* l)
{
    PtNo* ptaux;

    printf("\nArvore \t Ordem \t Tempo \t\t Compara");
    for (ptaux=l; ptaux!=NULL; ptaux=ptaux->prox){
        printf("\n%s \t %s \t %lf \t %d\n",ptaux->info.arv, ptaux->info.ord, ptaux->info.tempo, ptaux->info.compara);

    }

}     

PtNo* remover(PtNo* l, char arv[40])
{
     PtNo *ant = NULL; //ponteiro auxiliar para a posição anterior
     PtNo *ptaux = l; //ponteiro auxiliar para percorrer a lista

     /*procura o elemento na lista*/
     while (ptaux !=NULL && (strcmp(ptaux->info.arv, arv)))
     {
          ant = ptaux;
          ptaux = ptaux->prox;
     }

     /*verifica se achou*/
     if (ptaux == NULL)
       return l; /*retorna a lista original*/

    if (ant == NULL) /*vai remover o primeiro elemento*/
      l = ptaux->prox;
    else /*vai remover do meio ou do final*/
      ant->prox = ptaux->prox;

    free(ptaux); /*libera a memória alocada*/

    return l;
}

PtNo* destroi(PtNo* l)
{
   PtNo *ptaux; //ponteiro auxiliar para percorrer a lista
   while (l != NULL)
   {
         ptaux = l;
         l = l->prox;
         free(ptaux);
   }
   free(l);
   return NULL;
}
