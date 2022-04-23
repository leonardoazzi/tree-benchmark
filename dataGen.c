#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataGen.h"
#include "abp.h"

#define QUANTI 5000

// Gera um conjunto de dados ordenados
int * generateOrderedDataset(int quant){

    static generatedData data;
    int i;

    for (i = 0; i < quant; i++){     // fill array
        data[i] = i;

    }

    /*
    printf("\n=======================================\n\n");
    printf(" Ordered Numbers Dataset \n\n");
    printf("=======================================\n\n");

    for (i = 0; i < quant; i++){    // print array
         printf("%d,",data[i]);

    }
    */

    return data;

}

// Gera um conjunto de dados não ordenados
int * generateNonOrderedDataset(int quant){

    static generatedData data;

    int j = quant;
    int i;

    for (i = 0; i < quant; i++){     // fill array
        data[i] = j;
        j++;

    }


    for (i = 0; i < quant; i++){    // shuffle array
        int temp = data[i];
        int randomIndex = rand() % quant;

        data[i]           = data[randomIndex];
        data[randomIndex] = temp;

    }

    /*
    printf("\n\n=======================================\n\n");
    printf(" Non-Ordered Numbers Dataset \n\n");
    printf("=======================================\n\n");

    for (i = 0; i < quant; i++){    // print array
         printf("%d,",data[i]);

    }
    */

    return data;

}