#include "ej2.7.h"


int main()
{
    int numero1[]={1,1,2,3,4,5},
        numero2[]={1,1,1,1,1,5};

    tPilaEstatica pila1;
    tPilaEstatica pila2;
    tPilaEstatica resultado;

    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&resultado);

    cargarNumerosEnPila(&pila1, numero1, sizeof(numero1)/sizeof(int));
    cargarNumerosEnPila(&pila2, numero2, sizeof(numero2)/sizeof(int));

    //desapilarMostrandoEnteros(&pila1);
    //desapilarMostrandoEnteros(&pila2);

    sumarNumerosGrandes(&pila1, &pila2, &resultado);

    desapilarMostrandoEnteros(&resultado);

    printf("Hello world!\n");
    return 0;
}
