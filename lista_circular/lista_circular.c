#include "lista_circular.h"

void crearListaCircular(tLista* pl){
    *pl = NULL;
}

int aPilarCircular(t_pila* pp, void* dato, unsigned tam){
    tNodo* nue;

    nue = malloc(sizeof(tNodo));
    if(!nue){
        return FRACASO;
    }

    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return FRACASO;
    }

    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = (*pp)->sig;
    (*pp)->sig = nue;
    return EXITO;
}

int desaPilarCircular(t_pila* pp, void* dato, unsigned tam){
    tNodo* elim;

    if(*pp == NULL){
        return FRACASO;
    }

    elim = (*pp)->sig;
    memcpy(dato, elim->dato, MINIMO(elim->tam, tam));
    free(elim->dato);
    free(elim);

    (*pp)->sig = (*pp)->sig->sig;
    return EXITO;
}

int acolarCircular(tLista* pl, void* dato, unsigned tam){
    tNodo* nue;

    nue = malloc(sizeof(tNodo));
    if(!nue){
        return FRACASO;
    }
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return FRACASO;
    }

    memcpy(nue->dato, dato, tam);
    nue->tam = tam;

    nue->sig = (*pl)->sig;
    *pl = nue;
    return EXITO;
}

int desacolarCircular(tLista* pl, void* dato, unsigned tam){
    tNodo* elim;

    if(*pl == NULL){
        return FRACASO;
    }

    elim = (*pl)->sig;
    (*pl)->sig = (*pl)->sig->sig;

    memcpy(dato, elim->dato, MINIMO(elim->tam, tam));
    free(elim->dato);
    free(elim);
    return EXITO;
}

void mostrarEntero(const void* dato){
    printf("%d\t", * ((int*) dato));
}
int mostrarLista(const tLista* pl, void (mostrarDato(const void* dato))){
    tNodo* inicio;

    if(*pl == NULL){
        return FRACASO;
    }

    inicio = *pl;

    while( (*pl)->sig != inicio){
        mostrarDato((*pl)->dato);
        pl = & (*pl)->sig;
    }
    mostrarDato((*pl)->dato);
    printf("\n");

    return EXITO;
}

void vaciarLista(tLista* pl){
    tNodo* elim;
    tNodo* inicio;

    if(*pl == NULL){
        return;
    }

    inicio = *pl;

    while( (*pl)->sig != inicio){
        elim = *pl;
        *pl = (*pl)->sig;
        free(elim->dato);
        free(elim);
    }
    *pl = NULL;
}

int listaIFinal(tLista* pl, void* dato, unsigned tam){
    tNodo* inicio;
    tNodo* nue;

    nue = malloc(sizeof(tNodo));
    if(!nue){
        return FRACASO;
    }

    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return FRACASO;
    }

    memcpy(nue->dato,dato,tam);
    nue->tam = tam;

    if(*pl == NULL){
        nue->sig = nue;
        *pl = nue;
    }
    else{
        inicio = *pl;
        while( (*pl)->sig != inicio){
            pl = & (*pl)->sig;
        }
        (*pl)->sig = nue;
        nue->sig = inicio;
    }
    //mostrarEntero((*pl)->dato);
    return EXITO;
}

int eliminarUltimosN(tLista* pl, unsigned n){
    tLista* inicio;
    tLista* elim;
    int contador;

    if(*pl == NULL){
        return FRACASO;
    }

    contador = 1;
    inicio = pl;

    while( (*pl)->sig != *inicio){
        contador++;
        pl = & (*pl)->sig;
    }

    if(contador<n){
        return FRACASO;
    }
    elim = inicio;
    if(contador==n){
        vaciarLista(inicio);
    }
    else{
        while( (contador--) > n+1){
            elim = & (*elim)->sig;
        }
        (*pl)->sig = (*elim)->sig;

        vaciarLista(& (*elim)->sig);
        (*elim)->sig = *inicio;
    }

    return EXITO;
}
