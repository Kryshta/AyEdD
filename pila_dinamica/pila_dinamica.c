#include "pila_dinamica.h"

void crearPila(t_pila* pila){
  *pila = NULL;
}

int pilaVacia(t_pila* pila){
  return *pila == NULL;
}

int pilaLlena(const t_pila* pila, unsigned tamDato){
  void* nodo;
  nodo = malloc(sizeof(t_nodo));
  if(!nodo){
    return SIN_MEM;
  }

  ((t_nodo*) nodo )->dato = malloc(tamDato);
  if( ((t_nodo*) nodo )->dato == NULL){
    free(nodo);
    return SIN_MEM;
  }

  free(((t_nodo*) nodo )->dato);
  free(nodo);

  return OK;
}

int apilar(t_pila* pila, void* dato, unsigned cantBytes){
  t_nodo* nue;

  nue = malloc(sizeof(t_nodo));
  if(!nue){
    return 0;
  }

  nue->dato = malloc(cantBytes);

  if(!(nue->dato)){
    return 0;
  }

  memcpy(nue->dato, dato, cantBytes);
  memcpy( &(nue->cantBytes), &cantBytes, sizeof(cantBytes));

  nue->siguiente = *pila;
  *pila = nue;

  return 1;

}

int desapilar(t_pila* pila, void* dato, unsigned cantBytes){
  if(*pila == NULL){
    return 0;
  }
  //TO BE CONTINUED
  return 1;
}
