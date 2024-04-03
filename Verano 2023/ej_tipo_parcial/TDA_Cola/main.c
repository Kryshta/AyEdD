#include "header.h"

int main()
{
    printf("Hello world!\n");

    tCola cola;
    int test;

    crearCola(&cola);
    test = 10;

    printf("\nCola llena?: %d",colaLlena(&cola,sizeof(int)));
    printf("\nCola vacia?: %d",colaVacia(&cola));
    ponerEnCola(&cola, &test, sizeof(int));
    ponerEnCola(&cola, &test, sizeof(int));
    printf("\nCola llena?: %d",colaLlena(&cola,sizeof(int)));
    printf("\nCola vacia?: %d",colaVacia(&cola));
    vaciarCola(&cola);
    printf("\nCola llena?: %d",colaLlena(&cola, sizeof(int)));
    printf("\nCola vacia?: %d",colaVacia(&cola));

    return 0;
}
