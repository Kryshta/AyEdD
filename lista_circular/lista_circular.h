#ifndef LISTA_CIRCULAR_H_INCLUDED
#define LISTA_CIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X,Y) ((X)<(Y))?(X):(Y)
#define EXITO 1
#define FRACASO 0

typedef struct sNodo{
    unsigned tam;
    void* dato;
    struct sNodo* sig;
} tNodo;

typedef struct{
    tNodo* pri;
    tNodo* ult;
}tCola;

typedef tNodo* t_pila;

typedef tNodo* tLista;

void crearListaCircular(tLista* pl);
int aPilarCircular(t_pila* pp, void* dato, unsigned tam);
int desaPilarCircular(tLista* pl, void* dato, unsigned tam);
int acolarCircular(tLista* pl, void* dato, unsigned tam);
int desacolarCircular(tLista* pl, void* dato, unsigned tam);
void mostrarEntero(const void* dato);
int mostrarLista(const tLista* pl, void (mostrarDato(const void* dato)));
void vaciarLista(tLista* lista);
int listaIFinal(tLista* pl, void* dato, unsigned tam);
int eliminarUltimosN(tLista* pl, unsigned n);

#endif // LISTA_CIRCULAR_H_INCLUDED
