#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataGen.h"
#include "abp.h"

#define QUANTI 5000

// Gera um conjunto de dados ordenados
int * generateOrderedDataset(int quant){

    static generatedData data;

    for (int i = 0; i < quant; i++){     // fill array
        data[i] = i;

    }

    printf("\n=======================================\n\n");
    printf(" Ordered Numbers Dataset \n\n");
    printf("=======================================\n\n");

    // for (int i = 0; i < quant; i++){    // print array
    //     printf("%d,",data[i]);

    // }

    return data;

}

// Gera um conjunto de dados não ordenados
int * generateNonOrderedDataset(int quant){

    static generatedData data;

    int j = quant;
    for (int i = 0; i < quant; i++){     // fill array
        data[i] = j;
        j++;

    }

    printf("\n\n=======================================\n\n");
    printf(" Non-Ordered Numbers Dataset \n\n");
    printf("=======================================\n\n");

    for (int i = 0; i < quant; i++){    // shuffle array
        int temp = data[i];
        int randomIndex = rand() % quant;

        data[i]           = data[randomIndex];
        data[randomIndex] = temp;

    }


    // for (int i = 0; i < quant; i++){    // print array
    //     printf("%d,",data[i]);

    // }

    return data;

}

int main(){

    int *ord;
    int *nonOrd;

    ord = generateOrderedDataset(QUANTI);
    nonOrd = generateNonOrderedDataset(QUANTI);

    pNodoA *arv1 = NULL;
    pNodoA *arv2 = NULL;

    // Cria uma árvore com os dados ordenados
    for(int i = 0; i < QUANTI; i++){
        
        arv1 = InsereArvore(arv1, ord[i]);

    }

    // Cria uma árvore com os dados não ordenados
    for(int i = 0; i < QUANTI; i++){
        
        arv2 = InsereArvore(arv2, nonOrd[i]);

    }

    printf("-- Árvore com dados ordenados: Pre Esquerda --\n");
    CentralE(arv1);
    printf("\n\n");

    // Teste consulta
    pNodoA *arvC = NULL;
    arvC = consultaABP(arv1, 4995);
    CentralE(arvC);

    printf("-- Árvore com dados não ordenados: Pre Esquerda --\n");
    CentralE(arv2);
    printf("\n\n");
    
    
    return 0;

}