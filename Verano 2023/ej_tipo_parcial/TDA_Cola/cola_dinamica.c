#include "header.h"
#include "../TDA_Cola/header.h"

void crearCola(tCola* cola){
    cola->pri = NULL;
    cola->ult = NULL;
}

int colaVacia(const tCola* cola){
    return cola->pri==NULL;
}

int colaLlena(const tCola* cola, unsigned cantBytes){
    int result=0;
    char* aux1=NULL;

    aux1 = (char*) malloc(cantBytes);
    result += aux1==NULL;
    free(aux1);

    aux1 = (char*) malloc(sizeof(tNodo));
    result += aux1==NULL;
    free(aux1);

    return result;
}

int ponerEnCola(tCola* cola, const void* dato, unsigned cantBytes){
    tNodo* nuevo_nodo=NULL;

    nuevo_nodo = (tNodo*) malloc(sizeof(tNodo));
    nuevo_nodo->info = malloc(cantBytes);

    if(nuevo_nodo==NULL || nuevo_nodo->info ==NULL)
        return 0;

    memcpy(nuevo_nodo->info, dato, cantBytes);
    nuevo_nodo->tamInfo = cantBytes;
    nuevo_nodo->sig = NULL;

    if(cola->pri==NULL){
        cola->pri = nuevo_nodo;
    }
    else{
    cola->ult->sig = nuevo_nodo;
    }
    cola->ult = nuevo_nodo;

    return 1;
}

int sacarDeCola(tCola* cola, void* destino, unsigned cantBytes){
    tNodo* aux_primero;

    if(cola->pri==NULL)
        return 0;

    aux_primero = cola->pri->sig;
    memcpy(destino, cola->pri->info, MINIMO(cantBytes, cola->pri->tamInfo));
    free(cola->pri->info);
    free(cola->pri);
    cola->pri = aux_primero;

    //para exquisitos
    if(cola->pri == NULL)
        cola->ult = NULL;

    return 1;
}

int verPrimero(const tCola* cola, void* destino, unsigned cantBytes){
    if(cola->pri==NULL)
        return 0;

    memcpy(destino, cola->pri->info, MINIMO(cantBytes, cola->pri->tamInfo));
    return 1;
}

void vaciarCola(tCola* cola){
    tNodo* aux_siguiente;

    while(cola->pri!=NULL){
        aux_siguiente = cola->pri->sig;
        free(cola->pri->info);
        free(cola->pri);
        cola->pri = aux_siguiente;
    }
    //para exquisitos
    cola->ult = NULL;

    return;
}
