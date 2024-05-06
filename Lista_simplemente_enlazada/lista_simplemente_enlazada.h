#ifndef LISTA_SIMPLEMENTE_ENLAZADA_H_INCLUDED
#define LISTA_SIMPLEMENTE_ENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X,Y) ((X)<(Y))?(X):(Y)
#define EXITO 1
#define FRACASO 0
#define SIN_MEMORIA 0
#define LISTA_LLENA 1
#define LISTA_NO_LLENA 0

typedef struct sNodo{
    unsigned tam;
    void* dato;
    struct sNodo* sig;
} tNodo;

typedef tNodo* tLista;

void crearLista(tLista* lista);
int listaVacia(const tLista* lista);
int listaLlena(const tLista* lista, unsigned tam);
int mostrarLista(const tLista* lista, void (mostrarDato(void*)));
void vaciarLista(tLista* lista);
int listaIInicio(tLista* lista, const void* dato, unsigned tam);
int listaIFinal(tLista* lista, const void* dato, unsigned tam);
void mostrarEntero(void* numero);
int buscarClave(tLista* pl, void* pd, unsigned cantBytes, int(*cmp)(const void* a, const void* b));
int cmpEnteros(const void* a, const void* b);
tLista* buscarClaveSubLista(tLista* pl, const void* elemClave, unsigned cantBytes, int(*cmp)(const void* a, const void* b));
int insertarEnOrden(tLista* lista, void* elemento, unsigned cantBytes, int (*cmp)(const void* a, const void* b));
int contarElementosEnLista(const tLista* pl);
void ordenarLista(tLista* pl, int (*cmp) (const void* a, const void* b));
void eliminarPrimerOcurrenciaEnLista(tLista* pl, void* clave, int (*cmp) (const void* a, const void* b));
void eliminarTodasOcurrenciasEnLista(tLista* pl, void* clave, int (*cmp) (const void* a, const void* b));
void eliminarUltimaOcurrenciaEnLista(tLista* pl, void* clave, int (*cmp) (const void* a, const void* b));
int insertarEnPosicionN(tLista* pl, const void* dato, unsigned tam, unsigned n);
int eliminarPosicionN(tLista* pl, unsigned n);
int eliminarUltimosN(tLista* pl, unsigned n);
void ordenarListav2(tLista* pl, int (*cmp) (const void* a, const void* b));

#endif // LISTA_SIMPLEMENTE_ENLAZADA_H_INCLUDED
