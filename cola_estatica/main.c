
#include "cola_estatica.h"

int main()
{
    t_cola cola1;
    char dato[25];
    char datoDevuelto[25];

    crearCola(&cola1);
    colaVacia(&cola1)?printf("Cola vacia\n"):printf("Cola no vacia\n");

    strcpy(dato, "Hola");
    puts(dato);

    acolar(&cola1, &dato, 25);
    colaVacia(&cola1)?printf("Cola vacia\n"):printf("Cola no vacia\n");

    primeroEnCola(&cola1, &datoDevuelto, 25);
    colaVacia(&cola1)?printf("Cola vacia\n"):printf("Cola no vacia\n");

    desacolar(&cola1, &datoDevuelto, 25);
    colaVacia(&cola1)?printf("Cola vacia\n"):printf("Cola no vacia\n");
    puts(datoDevuelto);

    printf("Hello world!\n");
    return 0;
}
