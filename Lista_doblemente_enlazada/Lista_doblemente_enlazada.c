#include "Lista_doblemente_enlazada.h"

void crearLista(tLista* pl){
    *pl = NULL;
}

int insertarEnListaOrdenado(tLista* pl, const void* dato, unsigned tam, int (*cmp)(const void* a, const void* b)){
    tNodo *actual,
          *auxAnt,
          *auxSig,
          *nue;

    if (*pl == NULL){
        auxAnt = NULL;
        auxSig = NULL;
    }
    else{
        actual = *pl;
        while(cmp (actual->dato, dato)>0 && actual->ant != NULL){
            actual = actual->ant;
        }
        while(cmp (actual->dato, dato)<0 && actual->sig != NULL){
            actual = actual->sig;
        }
        if(cmp (actual->dato, dato)<0){
            auxSig = actual->sig;
            auxAnt = actual;
        }
        else{
            auxSig = actual;
            auxAnt = actual->ant;
        }
    }
    nue = malloc(sizeof(tNodo));
    if(!nue){
        return 0;
    }
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = auxSig;
    nue->ant = auxAnt;
    if(auxSig!=NULL){
        auxSig->ant = nue;
    }
    if(auxAnt!=NULL){
        auxAnt->sig = nue;
    }
    *pl = nue;
    return 1;
}

int compararEnteros(const void* a, const void* b){
    return * ((int*) a) - * ((int*) b);
}

void mostrarListaIzqDer(const tLista* pl, void (*mostrarDato)(const void* dato)){
    tNodo* actual;
    if(*pl == NULL){
        return;
    }
    actual = *pl;
        while(actual->ant != NULL){
        actual = actual->ant;
    }
    while(actual != NULL){
        mostrarDato(actual->dato);
        actual = actual->sig;
    }
    return;
}

void recorrerListaDerIzq(const tLista *pl, accion acc)
{
    tNodo *act = *pl;
    while(act->sig)
        act = act->sig;
    while(act)
    {
        acc(act->dato);
        act = act->ant;
    }
}

void mostrarEntero(const void* a){
    printf("%d ", *((int*) a));
}

int eliminarPorClave(tLista* pl, void* dato, unsigned tam, int(*cmp)(const void* a, const void* b)){
    //lista doble sin duplicados ordenada
    tNodo *act,
          *auxSig,
          *auxAnt;
    act = *pl;

    if(*pl == NULL){
        return 0;
    }

    while(act->sig != NULL && cmp(act->dato, dato)<0){
        act = act->sig;
    }
    while(act->ant != NULL && cmp(act->dato, dato)>0){
        act = act->ant;
    }

    if(cmp(act->dato, dato) == 0){
        auxAnt = act->ant;
        auxSig = act->sig;

        if(auxAnt){
            auxAnt->sig = auxSig;

        }
        if(auxSig){
            auxSig->ant = auxAnt;
            *pl = auxSig;
        }
        else{
            *pl = auxAnt;
        }
        free(act->dato);
        free(act);
        return 1;
    }
    return 0;
}

int eliminarOcurrencias(tLista *pl, void* dato, int (*cmp) (const void* a, const void* b)){
    //lista desordenada
    tNodo *act,
          *elim;
    int cant;

    cant = 0;
    act = *pl;
    if(*pl == NULL){
        return 0;
    }

    while (act->ant != NULL){
        act = act->ant;
    }
    while(act->sig != NULL){
        if (cmp(dato, act->dato)==0){
            elim = act;
            act = act->sig;
            elim->sig->ant = elim->ant;
            if(elim->ant != NULL){
                elim->ant->sig = elim->sig;
            }
            else{
                *pl = act;
            }
            free(elim->dato);
            free(elim);
            cant++;
        }
        else{
            act = act->sig;
        }
    }
    if (cmp(dato, act->dato)==0){
        act->ant->sig = NULL;
        free(act->dato);
        free(act);
        cant++;
    }
    return cant;
}

void resumirOcurrencias(tLista *pl, void* dato, int (*cmp) (const void* a, const void* b), void (*acumular) (void* a, const void* b)){
    //lista desordenada, resumir todas las ocurrencias de una clave, dejar un solo nodo

    tNodo *act,
          *iterador,
          *elim;

    act = *pl;
    if(*pl == NULL){
        return;
    }
    while (act->ant != NULL){
        act = act->ant;
    }

    while(act->sig != NULL){
        if (cmp(dato, act->dato)==0){
            iterador = act;
            iterador = iterador->sig;
            while(iterador->sig != NULL){
                if (cmp(dato, iterador->dato)==0){
                    elim = iterador;
                    acumular(act->dato, iterador->dato);
                    iterador = iterador->sig;
                    elim->sig->ant = elim->ant;
                    elim->ant->sig = elim->sig;
                    free(elim->dato);
                    free(elim);
                }
                else{
                    iterador = iterador->sig;
                }
            }
            if (cmp(dato, iterador->dato)==0){
                acumular(act->dato, iterador->dato);
                iterador->ant->sig = NULL;
                free(iterador->dato);
                free(iterador);
            }
            return;
        }
        act = act->sig;
    }
    return;
}
