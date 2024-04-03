#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(X,Y) (X)<(Y)?X:Y

typedef struct sNodo{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
}tNodo;

typedef struct{
    tNodo* pri;
    tNodo* ult;
}tCola;

void crearCola(tCola* cola);

int colaLlena(const tCola* cola, unsigned cantBytes);

int colaVacia(const tCola* cola);

int ponerEnCola(tCola* cola, const void* dato, unsigned cantBytes);

int sacarDeCola(tCola* cola, void* dato, unsigned cantBytes);

int verPrimero(const tCola* cola, void* dato, unsigned cantBytes);

void vaciarCola(tCola* cola);

#endif // HEADER_H_INCLUDED
