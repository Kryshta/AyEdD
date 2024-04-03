#include "header.h"
#include "lista.h"

int main()
{
    tLista pl;
    int foo;
    printf("Hello world!\n");

    foo=0;
    crearLista(&pl);
    insertarAlPrincipio(&pl, &foo, sizeof(int));
    foo=5;
    insertarAlPrincipio(&pl, &foo, sizeof(int));
    recorrerLista(&pl, mostrarEntero);

    return 0;
}
