#include <stdio.h>
#include <stdlib.h>
#include "pila_estatica.h"

int main()
{
    tPilaEstatica pila;
    int vectorEnteros[] = {10, 25, 30 , 99, 7, 8, 0};
    int i=0;
    int elementoDesapilado;

    crearPila(&pila);


    if( pilaVacia(&pila)){
        printf("Pila vacia\n");
    }
    else{
        printf("Pila con datos\n");
    }

    if( pilaLlena(&pila, 40)){
        printf("Pila llena\n");
    }
    else{
        printf("Pila no llena\n");
    }

    for(i=0; i<sizeof(vectorEnteros)/sizeof(vectorEnteros[0]); i++){
        //apilar(&pila, &vectorEnteros[i], sizeof(int));
        apilar(&pila, vectorEnteros+i, sizeof(int));
    }

    if( pilaVacia(&pila)){
        printf("Pila vacia\n");
    }
    else{
        printf("Pila con datos\n");
    }

    if( pilaLlena(&pila, 40)){
        printf("Pila llena\n");
    }
    else{
        printf("Pila no llena\n");
    }

    if (desapilar(&pila,&elementoDesapilado, sizeof(int))){
        printf("\n%d\n", elementoDesapilado);
    }

    if( verTope(&pila, &elementoDesapilado, sizeof(int)) ){
        printf("\n%d\n", elementoDesapilado);
    }

    if (desapilar(&pila,&elementoDesapilado, sizeof(int))){
        printf("\n%d\n", elementoDesapilado);
    }

    if( verTope(&pila, &elementoDesapilado, sizeof(int)) ){
        printf("\n%d\n", elementoDesapilado);
    }

    return 0;
}
