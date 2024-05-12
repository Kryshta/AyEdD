<<<<<<< HEAD
#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X,Y) (((X)<(Y))?(X):(Y))
#define EXITO 1
#define FRACASO 0

typedef struct sNodo{
    unsigned tam;
    void* dato;
    struct sNodo* siguiente;
}tNodo;

typedef struct{
    tNodo* pri;
    tNodo* ult;
}tCola;

void crearColaDinamica(tCola* cola);
int colaVacia(const tCola* cola);
int colaLlena(const tCola* cola);
int verPrimeroEnCola(const tCola* cola, void* datoDestino, unsigned tam);
int acolar(tCola* cola, const void* datoOrigen, unsigned tam);
int desacolar(tCola* cola, void* datoDestino, unsigned tam);
int vaciarCola(tCola* cola);

#endif // COLA_DINAMICA_H_INCLUDED
=======
#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X,Y) (((X)<(Y))?(X):(Y))
#define EXITO 1
#define FRACASO 0

typedef struct sNodo{
    unsigned tam;
    void* dato;
    struct sNodo* siguiente;
}tNodo;

typedef struct{
    tNodo* pri;
    tNodo* ult;
}tCola;

void crearColaDinamica(tCola* cola);
int colaVacia(const tCola* cola);
int colaLlena(const tCola* cola);
int verPrimeroEnCola(const tCola* cola, void* datoDestino, unsigned tam);
int acolar(tCola* cola, const void* datoOrigen, unsigned tam);
int desacolar(tCola* cola, void* datoDestino, unsigned tam);
int vaciarCola(tCola* cola);

#endif // COLA_DINAMICA_H_INCLUDED
>>>>>>> 138f8c91317c85473a156d87c2b53a17c6040156
