#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED
#define TAM 1000
#include <string.h>

typedef struct{
    int tope;
    char pila[TAM];
}tPilaEstatica;

void crearPila(tPilaEstatica* pila);
int pilaVacia(const tPilaEstatica* pila);
int pilaLlena(const tPilaEstatica* pila, unsigned tamDato);
int apilar(tPilaEstatica* pila, const void* dato, unsigned tamElem);
int desapilar(tPilaEstatica* pila, void* destino, unsigned tamElem);
int verTope(const tPilaEstatica* pila, void* destino, unsigned tamElem);

#endif // PILA_ESTATICA_H_INCLUDED
