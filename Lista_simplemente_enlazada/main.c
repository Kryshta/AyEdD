#include "lista_simplemente_enlazada.h"

int main()
{
    tLista lista1;

    int arrEnteros[10] = {2,6,8,1,9,10,1523,88,12,5};
    int i;

    crearLista(&lista1);

    for(i=0;i<10;i++){
        listaIFinal(&lista1, arrEnteros+i, sizeof(int));
    }

    mostrarLista(&lista1, mostrarEntero);
    vaciarLista(&lista1);
    for(i=0;i<5;i++){
        listaIFinal(&lista1, arrEnteros+i, sizeof(int));
    }

    mostrarLista(&lista1, mostrarEntero);    eliminarUltimosN(&lista1, 2);
    mostrarLista(&lista1, mostrarEntero);
    //ordenarListav2(&lista1, &cmpEnteros);
    //puts("Lista ordenada");
    //listaVacia(&lista1)?printf("Lista vacia"):printf("Lista no vacia");

    printf("Hello world!\n");
    return 0;
}
