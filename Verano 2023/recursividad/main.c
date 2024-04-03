#include <stdio.h>
#include <stdlib.h>
#include "recursividad_header.h"

int main()
{

/*
    char cadena[50];
    printf("Escriba cadena: ");
    fflush(stdin);
    gets(cadena);
    printf("\nLa cadena es capicua?: %d", esCadenaCapicua(cadena));
*/

    #define TAM 10
    int arrayEnteros[TAM] = {1,2,3,4,5,6,7,8,9,10};

    printf("Resultado: %d", busquedaBinaria(arrayEnteros,10,TAM));


    return 0;
}
