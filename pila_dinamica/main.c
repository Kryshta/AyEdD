#include "pila_dinamica.h"

int main()
{
    t_pila pila;

    crearPila(&pila);

    if(pilaVacia(&pila)){
      printf("Pila vacia\n");
    }
    else{
      printf("Pila no vacia\n");
    }

    //printf("Hello world!\n");
    return 0;
}
