#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <string.h>
#define TAM_COLA 50
#define MINIMO(X,Y) (X)<(Y)?(X):(Y)

typedef struct{
    char dato[TAM_COLA];
    unsigned pri;
    unsigned ult;
    unsigned tamDisp;
} tCola;

void crearCola(tCola* cola);

int colaLlena(const tCola* cola, unsigned cantBytes);

int colaVacia(const tCola* cola);

int ponerEnCola(tCola* cola, const void* dato, unsigned cantBytes);

int sacarDeCola(tCola* cola, void* dato, unsigned cantBytes);

int verPrimero(const tCola* cola, void* dato, unsigned cantBytes);

void vaciarCola(tCola* cola);

#endif // HEADER_H_INCLUDED
