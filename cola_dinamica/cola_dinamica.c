#include "cola_dinamica.h"

void crearColaDinamica(tCola* cola){
    cola->pri = NULL;
    cola->ult = NULL;
}

int colaVacia(const tCola* cola){
    return cola->pri == NULL;
}

int colaLlena(const tCola* cola){
    return 0;
}

int verPrimeroEnCola(const tCola* cola, void* datoDestino, unsigned tam){
    memcpy(datoDestino, cola->pri->dato, MINIMO(tam, cola->pri->tam));
    return EXITO;
}

int acolar(tCola* cola, const void* datoOrigen, unsigned tam){
    tNodo* nue;

    nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue){
        return FRACASO;
    }
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return FRACASO;
    }

    nue->tam = tam;
    nue->siguiente = NULL;
    memcpy(nue->dato, datoOrigen, tam);
    if(cola->pri == NULL){
        cola->pri = nue;
    }
    else{
        nue->siguiente = cola->pri;
    }
    cola->ult = nue;
    return EXITO;
}

int desacolar(tCola* cola, void* datoDestino, unsigned tam){
    tNodo* elim;

    if(cola->pri == NULL){
        return FRACASO;
    }
    elim = cola->pri;
    cola->pri = elim->siguiente;
    memcpy(datoDestino, elim->dato, MINIMO(elim->tam, tam));
    free(elim->dato);
    free(elim);
    return EXITO;
}

int vaciarCola(tCola* cola){
    tNodo* elim;

    if(cola->pri == NULL){
        return FRACASO;
    }

    while(cola->pri != NULL){
        elim = cola->pri;
        cola->pri = elim->siguiente;
        free(elim->dato);
        free(elim);
    }
    return EXITO;
}
