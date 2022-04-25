#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "avl.h"

pNodoAVL* InsereArvore(pNodoAVL* a, TipoInfo ch){
  if (a == NULL)
  {
    a = (pNodoAVL*) malloc(sizeof(pNodoAVL));
    a->info = ch;
    a->esq = NULL;
    a->dir = NULL;
    a->FB = 0; // o nodo � sempre inserido como folha ent�o seu fator de balanceamento � 0
  }
  else
  if (ch < (a->info))
    a->esq = InsereArvore(a->esq,ch);
  else
    a->dir = InsereArvore(a->dir,ch);
    return a;
}

int Altura (pNodoAVL *a){
    int Alt_Esq, Alt_Dir;
    if (a == NULL)
      return 0;
    else
    {
       Alt_Esq = Altura (a->esq);
       Alt_Dir = Altura (a->dir);
       if (Alt_Esq > Alt_Dir)
         return (1 + Alt_Esq);
       else
         return (1 + Alt_Dir);
     }
}

int Calcula_FB(pNodoAVL *a){
    return (Altura(a->esq) - Altura(a->dir));
}

void DesenhaAVL(pNodoAVL *a , int nivel){
int x;

 if (a !=NULL)
 {
   for (x=1; x<=nivel; x++)
      printf("--");
  printf("%d\n", a->info);
   if (a->esq != NULL) DesenhaAVL(a->esq, (nivel+1));
   if (a->dir != NULL) DesenhaAVL(a->dir, (nivel+1));
 }
}

int is_avl(pNodoAVL *a){
  int alt_esq, alt_dir;

  if (a!=NULL)
  {
     alt_esq = Altura(a->esq);
     alt_dir = Altura(a->dir);
     return ( (alt_esq - alt_dir <2) && (alt_dir - alt_esq <2) && (is_avl(a->esq)) && (is_avl(a->dir)) );
  }
  else
  return 1;
}


pNodoAVL* rotacao_direita(pNodoAVL *pt){
   pNodoAVL* ptu;

   ptu = pt->esq; 
   pt->esq = ptu->dir; 
   ptu->dir = pt; 
   pt->FB = 0;
   pt = ptu; 
   return pt;
}

pNodoAVL* rotacao_esquerda(pNodoAVL *pt){
   pNodoAVL* ptu;

   ptu = pt->dir; 
   pt->dir = ptu->esq; 
   ptu->esq = pt; 
   pt->FB = 0;
   pt = ptu; 
   return pt;
} 

pNodoAVL* rotacao_dupla_direita (pNodoAVL* pt){
   pNodoAVL* ptu, *ptv;

   ptu = pt->esq; 
   ptv = ptu->dir; 
   ptu->dir = ptv->esq; 
   ptv->esq = ptu; 
   pt->esq = ptv->dir; 
   ptv->dir = pt; 
   if (ptv->FB == 1)   pt->FB = -1;
      else pt->FB = 0;
   if (ptv->FB == -1)  ptu->FB = 1;
      else ptu->FB = 0;
   pt = ptv; 
   return pt;
} 

pNodoAVL* rotacao_dupla_esquerda (pNodoAVL* pt){
   pNodoAVL *ptu, *ptv;

   ptu = pt->dir; 
   ptv = ptu->esq; 
   ptu->esq = ptv->dir; 
   ptv->dir = ptu; 
   pt->dir = ptv->esq; 
   ptv->esq = pt; 
   if (ptv->FB == -1) pt->FB = 1;
     else pt->FB = 0;
   if (ptv->FB == 1) ptu->FB = -1;
      else ptu->FB = 0;
   pt = ptv; 
   return pt;
}


pNodoAVL* Caso1 (pNodoAVL* a , int *ok){
   pNodoAVL *ptu; 

	ptu = a->esq;
	if (ptu->FB == 1) 
    {    
        //printf("fazendo rotacao direita em %d\n",a->info);
        a = rotacao_direita(a);
     }
    else
    {
        //printf("fazendo rotacao dupla direita em %d\n",a->info);
        a = rotacao_dupla_direita(a);
    }
	
    a->FB = 0;
	*ok = 0;
	return a;
}

pNodoAVL* Caso2 (pNodoAVL *a , int *ok){
    pNodoAVL *ptu; 

	ptu = a->dir;
	if (ptu->FB == -1) 
    {
       //DesenhaAVL(a,1);
       //printf("fazendo rotacao esquerda em %d\n",a->info);
       a=rotacao_esquerda(a);
    }
    else
    {
       //DesenhaAVL(a,1);
       //printf("fazendo rotacao dupla esquerda em %d\n",a->info);
       a=rotacao_dupla_esquerda(a);
    }
	a->FB = 0;
	*ok = 0;
	return a;
}

pNodoAVL* InsereArvoreAVL (pNodoAVL *a, TipoInfo x, int *ok){
/* Insere nodo em uma Árvore AVL, onde A representa a raiz da Árvore,
  x, a chave a ser inserida e h a altura da Árvore */

     if (a == NULL) 
     {
     	a = (pNodoAVL*) malloc(sizeof(pNodoAVL));
        a->info = x;
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0; 
	    *ok = 1;
     }
     else
     if (x < a->info) 
     {
		a->esq = InsereArvoreAVL(a->esq,x,ok);
        if (*ok) 
        {
   		    switch (a->FB) {
        	  case -1:  a->FB = 0; *ok = 0; break;
			  case  0:  a->FB = 1;  break;
			  case  1:  a=Caso1(a,ok); break;
            }
         }
     }
	 else
     {
  		    a->dir = InsereArvoreAVL(a->dir,x,ok);
            if (*ok)
            { 
              switch (a->FB) {
                case  1:  a->FB = 0; *ok = 0; break;
                case  0:  a->FB = -1; break;
			    case -1:  a = Caso2(a,ok); break;
             }
            }
     }
     return a;
}

void _deletaAVL(pNodoAVL* arv){
    if (arv == NULL) return;

    _deletaAVL(arv->esq);
    _deletaAVL(arv->dir);

    free(arv);
}

void deletaAVL(pNodoAVL **arv){
   _deletaAVL(*arv);

   *arv = NULL;
}

void CentralE_AVL(pNodoAVL *a)
{
     if (a!= NULL)
     {
          CentralE_AVL(a->esq);
          printf("%d - ",a->info);
          CentralE_AVL(a->dir);
      }
}

pNodoAVL* consultaAVL(pNodoAVL *a, TipoInfo chave) {
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
