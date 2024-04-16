#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))
#define SIN_MEM 1
#define PILA_NO_LLENA 0
#define OK 1
#define PILA_VACIA 0



typedef struct s_nodo{
  unsigned cantBytes;
  void* dato;
  struct s_nodo* siguiente;
}t_nodo;

typedef t_nodo* t_pila;

void crearPila(t_pila* pila);
int pilaVacia(t_pila* pila);
int pilaLlena(const t_pila* pila, unsigned tamDato);
int desapilar(t_pila* pila, void* dato, unsigned cantBytes);
int vaciarPila(t_pila* pila);
int apilar(t_pila* pila, void* dato, unsigned cantBytes);
int verTope(t_pila* pila, void* dato, unsigned cantBytes);


#endif // PILA_DINAMICA_H_INCLUDED
