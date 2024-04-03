#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_PILA 50

typedef struct{
    char pila[TAM_PILA];
    unsigned tope_de_pila;
} pila;

void crear_vector(pila* nueva_pila);
int vector_lleno(pila* pila1, unsigned cantBytes);
int vector_vacio(pila* pila1);
int insertar_elemento(pila* pila1, unsigned cantBytes, const void* elemento);
int eliminar_elemento(pila* pila1);
void eliminar_vector(pila* pila1);

typedef struct{
    void* info;
    unsigned tam;
    struct tNodo* siguiente;
} tNodo;

typedef tNodo* pilaDinamica;

void crear_pila_dinamica(pilaDinamica* pila1);
int pila_dinamica_llena(const pilaDinamica* pila1, unsigned cantBytes);
int pila_dinamica_vacia(const pilaDinamica* pila1);
int insertar_en_pila_dinamica(pilaDinamica* pila1, unsigned cantBytes, void* info);
int sacar_de_pila_dinamica(pilaDinamica* pila1, void* destino, unsigned cantBytes);
int tope_de_pila_dinamica(const pilaDinamica* pila1, void* destino, unsigned cantBytes);
int vaciar_pila_dinamica(pilaDinamica* pila1);

#endif // HEADER_H_INCLUDED
