#include <stdio.h>
#include <stdlib.h>
#include "ej2.6.h"

int main()
{
    tPilaEstatica pila1;
    tPilaEstatica pila2;
    unsigned tamElem;

    crearPila(&pila1);
    crearPila(&pila2);
    tamElem = sizeof(int);

    generarArchivo(FILENAME);
    leerArchivo(FILENAME);

    ordenarArchivo(FILENAME, &pila1, &pila2, tamElem, comparacionEnteros, ASCENDENTE);
    desapilarMostrandoEnteros(&pila2,sizeof(int));

    ordenarArchivo(FILENAME, &pila1, &pila2, tamElem, comparacionEnteros, DESCENDENTE);
    desapilarMostrandoEnteros(&pila1,sizeof(int));


    printf("Hello world!\n");
    return 0;
}
