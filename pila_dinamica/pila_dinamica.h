#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIN_MEM 1
#define OK 0

typedef struct s_nodo{
  unsigned cantBytes;
  void* dato;
  struct s_nodo* siguiente;
}t_nodo;

typedef t_nodo* t_pila;

void crearPila(t_pila* pila);
int pilaVacia(t_pila* pila);



#endif // PILA_DINAMICA_H_INCLUDED
