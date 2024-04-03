#include "header.h"
#include "lista.h"

void crearLista(tLista* pl){
    pl=NULL;
}

void recorrerLista(tLista* pl, void accion(void* dato)){
    while(*pl){
        accion((*pl)->info);
        pl = &(*pl)->sig;
    }
}

int insertarAlFinal(tLista* pl, void* dato, unsigned cantBytes){
    tNodo* nue;

    while(*pl){
        pl = &(*pl)->sig;
    }
    nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->info = malloc(cantBytes);
    if(nue->info==NULL){
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, cantBytes);
    nue->sig = NULL;
    *pl = nue;
    return 1;
}

int insertarAlPrincipio(tLista* pl, void* dato, unsigned cantBytes){
    tNodo* nue;

    nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->info = malloc(cantBytes);
    if(nue->info==NULL){
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, cantBytes);
    nue->sig = *pl;
    *pl = nue;
    return 1;
}

int insertarPorPosicion(tLista* pl, void* info, unsigned cantBytes, unsigned posicion){
    tNodo* nue;
    int i=0;

    nue = (tNodo*) malloc(sizeof(tNodo));
      if(!nue)
        return 0;
    nue->info = malloc(cantBytes);
    if(nue->info==NULL){
        free(nue);
        return 0;
    }

    while(*pl && i<posicion){
        pl = &(*pl)->sig;
        i++;
    }

    nue->sig = *pl;
    *pl = nue;
    return 1;
}

int insertarOrdenado(tLista* pl, void* info, unsigned cantBytes){
    tNodo* nue;

    nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->info = malloc(cantBytes);
    if(nue->info==NULL){
        free(nue);
        return 0;
    }

    while(*pl && memcmp(info,(*pl)->info,cantBytes)>0){ //deberia usar una comparacion generica
        pl = &(*pl)->sig;
    }

    nue->sig = *pl;
    *pl = nue;
    return 1;
}

int eliminarInfo(tLista* pl, void* info, unsigned cantBytes){
    tNodo* elim;
    int cantidadEliminada;

    cantidadEliminada=0;
    while(*pl){
        if (memcmp(info, (*pl)->info, cantBytes) ==0){
            elim = (*pl)->sig;
            free(elim->info);
            free(elim);
            *pl = elim;
            cantidadEliminada++;
        }
        pl = &(*pl)->sig;
    }

    return cantidadEliminada;
}

int filtrarLista(tLista* pl, int ffiltro(void* dato)){
    tNodo* elim;

    while(*pl){
        if (ffiltro( (*pl)->info) ==0){
            elim = (*pl)->sig;
            free(elim->info);
            free(elim);
            *pl = elim;
        }
        pl = &(*pl)->sig;
    }

    return 1;
}

int reduceLista(tLista* pl, void freduccion(void* acumulador, const void* dato)){
    return 1;
}
