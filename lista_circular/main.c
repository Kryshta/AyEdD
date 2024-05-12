#include "lista_circular.h"

int main()
{
    int arrEnteros[10] = {2,6,8,1,9,10,1523,88,12,5};
    tLista lista1;
    int i;

    crearListaCircular(&lista1);

    for(i=0;i<10;i++){
        listaIFinal(&lista1, arrEnteros+i, sizeof(int));
    }

    puts("Lista: ");
    mostrarLista(&lista1, mostrarEntero);

    vaciarLista(&lista1);
    for(i=0;i<5;i++){
        listaIFinal(&lista1, arrEnteros+i, sizeof(int));
    }
    mostrarLista(&lista1, mostrarEntero);

    eliminarUltimosN(&lista1, 2);

    mostrarLista(&lista1, mostrarEntero);

    printf("Hello world!\n");
    return 0;
}
