#include "cola_dinamica.h"

int main()
{

    typedef struct{
        int dni;
        char nombre[20];
        int edad;
    }tPersona;


    tCola cola1;
    tPersona personaInsertada;
    tPersona personaExtraida;

    personaInsertada.dni = 11222333;
    strcpy(personaInsertada.nombre, "Pepito");
    personaInsertada.edad = 21;
    crearColaDinamica(&cola1);

    puts("testsColaDinamica");
    (cola1.pri == NULL)?puts("Crear cola funciona correctamente"):puts("Error en crear cola");
    colaVacia(&cola1)?puts("Cola vacia funciona correctamente"):puts("Error en cola vacia");
    colaLlena(&cola1)?puts("Error en cola llena"):puts("Cola llena funcionando correctamente");
    acolar(&cola1, &personaInsertada, sizeof(tPersona));
    cola1.pri!=NULL?puts("Acolar funcionando correctamente"):puts("Error en acolar");
    verPrimeroEnCola(&cola1, &personaExtraida, sizeof(tPersona));
    personaExtraida.dni==11222333?puts("Ver primero funciona correctamente"):puts("Error en ver primero");
    personaExtraida.dni=1;
    desacolar(&cola1,&personaExtraida,sizeof(tPersona));
    personaExtraida.dni==11222333?puts("Desacolar funciona correctamente"):puts("Error en desacolar");
    colaVacia(&cola1)?puts("Cola vacia funciona correctamente"):puts("Error en cola vacia");
    acolar(&cola1, &personaInsertada, sizeof(tPersona));
    acolar(&cola1, &personaInsertada, sizeof(tPersona));
    vaciarCola(&cola1);
    colaVacia(&cola1)?puts("Desacolar funciona correctamente"):puts("Error en desacolar");

    return 0;
}
