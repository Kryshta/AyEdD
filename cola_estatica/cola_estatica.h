#ifndef COLA_ESTATICA_H_INCLUDED
#define COLA_ESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct{
    char vec[MAX];
    unsigned pri,
             ult,
             disponible;

}t_cola;

void crearCola(t_cola* cola);
int colaVacia(const t_cola* cola);
int colaLlena(const t_cola* cola, unsigned tamElem);
void vaciarCola(t_cola* cola);
int acolar(t_cola* cola, const void* dato, unsigned tamElem);
int desacolar(t_cola* cola, void* destinoDato, unsigned tamElem);
int primeroEnCola(const t_cola* cola, void* destinoDato, unsigned tamElem);


#endif // COLA_ESTATICA_H_INCLUDED
