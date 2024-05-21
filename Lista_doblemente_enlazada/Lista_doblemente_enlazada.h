#ifndef LISTA_DOBLEMENTE_ENLAZADA_H_INCLUDED
#define LISTA_DOBLEMENTE_ENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo{
    struct sNodo* ant;
    struct sNodo* sig;
    unsigned tam;
    void* dato;
} tNodo;

typedef tNodo* tLista;
typedef void (*accion)(const void*);

void crearLista(tLista* pl);
int insertarEnListaOrdenado(tLista* pl, const void* dato, unsigned tam, int (*cmp)(const void* a, const void* b));
int compararEnteros(const void* a, const void* b);
void mostrarListaIzqDer(const tLista* pl, void mostrarDato(const void* dato));
void mostrarEntero(const void* a);
void recorrerListaDerIzq(const tLista *pl, accion acc);
int eliminarPorClave(tLista* pl, void* dato, unsigned tam, int(*cmp)(const void* a, const void* b));
int eliminarOcurrencias(tLista *pl, void* dato, int (*cmp) (const void* a, const void* b));
void resumirOcurrencias(tLista *pl, void* dato, int (*cmp) (const void* a, const void* b), void (*agregar) (void* a, const void* b));

#endif // LISTA_DOBLEMENTE_ENLAZADA_H_INCLUDED
