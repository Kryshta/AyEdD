#include "pila_estatica.h"
#define PILA_LLENA 0
#define PILA_VACIA 0
#define OK 1
#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))

void crearPila(tPilaEstatica* pila){
    pila->tope = TAM;
}

int pilaVacia(const tPilaEstatica* pila){
    return pila->tope == TAM;
}

int pilaLlena(const tPilaEstatica* pila, unsigned tamDato){
    return pila->tope < sizeof(unsigned) + tamDato;
}

void vaciarPila(tPilaEstatica* pila){
    pila->tope = TAM;
}

int apilar(tPilaEstatica* pila, const void* dato, unsigned tamElem){
    if(pila->tope < sizeof(unsigned) + tamElem){
        return PILA_LLENA;
    }
    pila->tope -= tamElem;
    memcpy(pila->pila+pila->tope, dato, tamElem);
    pila->tope -= sizeof(unsigned);
    memcpy(pila->pila+pila->tope, &tamElem, sizeof(unsigned));
    return OK;
}

int desapilar(tPilaEstatica* pila, void* destino, unsigned tamElem){
    unsigned tamAExtraer;

    if (pila->tope == TAM){
        return PILA_VACIA;
    }
    memcpy(&tamAExtraer, pila->pila + pila->tope, sizeof(unsigned));
    pila->tope+=sizeof(unsigned);
    memcpy(destino, pila->pila + pila->tope, MINIMO(tamElem,tamAExtraer));
    pila->tope+=tamAExtraer;
    return OK;
}

int verTope(const tPilaEstatica* pila, void* destino, unsigned tamElem){
    unsigned tamAExtraer;

    if (pila->tope == TAM){
        return PILA_VACIA;
    }
    memcpy(&tamAExtraer, pila->pila + pila->tope, sizeof(unsigned));
    memcpy(destino, pila->pila + sizeof(unsigned) + pila->tope, MINIMO(tamElem,tamAExtraer));
    return OK;
}
