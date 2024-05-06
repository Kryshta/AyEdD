#include "lista_simplemente_enlazada.h"

void crearLista(tLista* lista){
    *lista = NULL;
}

int listaVacia(const tLista* lista){
    return (*lista == NULL);
}

int listaLlena(const tLista* lista, unsigned tam){
    tNodo* aux;

    aux = malloc(sizeof(tNodo));
    if(!aux){
        return LISTA_LLENA;
    }
    aux->dato = malloc(tam);
    if(!aux->dato){
        free(aux);
        return LISTA_LLENA;
    }
    free(aux->dato);
    free(aux);
    return LISTA_NO_LLENA;
}

int listaIInicio(tLista* lista, const void* dato, unsigned tam){
    tNodo* nue;

    nue = malloc(sizeof(tNodo));
    if(!nue){
        return SIN_MEMORIA;
    }
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return SIN_MEMORIA;
    }

    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->sig = *lista;
    *lista = nue;
    return EXITO;
}

int listaIFinal(tLista* lista, const void* dato, unsigned tam){
    tNodo* nue;

    while((*lista) != NULL){
        lista = & (*lista)->sig;
    }
    nue = malloc(sizeof(tNodo));
    if(!nue){
        return SIN_MEMORIA;
    }
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return SIN_MEMORIA;
    }

    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    *lista = nue;
    nue->sig = NULL;
    return EXITO;
}

void vaciarLista(tLista* lista){
    tNodo* elim;

    while((*lista) != NULL){
        elim = *lista;
        *lista = elim->sig;
        free(elim->dato);
        free(elim);
    }
}

int mostrarLista(const tLista* lista, void (mostrarDato(void*))){
    if(*lista == NULL){
        return 0;
    }

    while((*lista) != NULL){
        mostrarDato( (*lista)->dato);
        lista = & (*lista)->sig;
    }
    printf("\n");
    return EXITO;
}

void mostrarEntero(void* numero){
    printf("%d\t", * ((int*)numero));
}

int buscarClave(tLista* pl, void* pd, unsigned cantBytes, int(*cmp)(const void* a, const void* b)){
    while(*pl && cmp((*pl)->dato, pd)){
        pl = &(*pl)->sig;
    }
    if(!*pl)
        return 0;
    memcpy(pd, (*pl)->dato, MINIMO((*pl)->tam, cantBytes));
    return EXITO;
}

tLista* buscarClaveSubLista(tLista* pl, const void* elemClave, unsigned cantBytes, int(*cmp)(const void* a, const void* b)){
    while(*pl && cmp((*pl)->dato, elemClave)){
        pl = &(*pl)->sig;
    }
    if(!*pl)
        return NULL;

    return pl;
}

int cmpEnteros(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int insertarEnOrden(tLista* lista, void* elemento, unsigned cantBytes, int (*cmp)(const void* a, const void* b)){
    tNodo* nue;
    while(*lista && cmp(elemento, (*lista)->dato)>0){
        lista = & (*lista)->sig;
    }

    nue = malloc(sizeof(tNodo));
    if(!nue){
        return 0;
    }
    nue->dato = malloc(cantBytes);
    if(!nue->dato){
        free(nue);
        return 0;
    }
    if(*lista == NULL){
        *lista = nue;
        nue->sig = NULL;
    }
    else{
        (*lista)->sig = nue->sig;
        *lista = nue;
    }
    return EXITO;
}

int contarElementosEnLista(const tLista* pl){
    int cant;

    cant=0;

    while(*pl!=NULL){
        cant++;
        pl = & (*pl)->sig;
    }
    return cant;
}

void ordenarLista(tLista* pl, int (*cmp) (const void* a, const void* b)){
    tNodo *pNodoIterador,
          *pNodoMenor,
          *pInicioSublista;

    if(*pl == NULL){
        return;
    }
    pNodoIterador = *pl;
    if( pNodoIterador->sig == NULL){
        return;
    }

    while(*pl != NULL){
        pNodoMenor = *pl;
        while(pNodoIterador->sig != NULL){
            if(cmp(pNodoMenor->dato, pNodoIterador->sig->dato)>0){
                pNodoMenor = pNodoIterador->sig;
            }
            pNodoIterador = pNodoIterador->sig;
        }
        pInicioSublista = *pl;
        *pl = pNodoMenor;
        pl = & (*pl)->sig;

        pNodoIterador = pInicioSublista;

        while(pNodoIterador->sig != pNodoMenor){//aca se tilda
            pNodoIterador = pNodoIterador->sig;
        }
        pNodoIterador->sig = NULL;

        pNodoIterador = pNodoMenor;
        while(pNodoIterador->sig != NULL){
            pNodoIterador = pNodoIterador->sig;
        }
        pNodoIterador->sig = pInicioSublista;
        mostrarLista(pl, mostrarEntero);
    }
}

void eliminarPrimerOcurrenciaEnLista(tLista* pl, void* clave, int (*cmp) (const void* a, const void* b)){
    tNodo* elim;

    if( cmp( (*pl)->dato, clave) == 0){
            elim = *pl;
            *pl = (*pl)->sig;
            free(elim->dato);
            free(elim);
            return;
    }
    while( (*pl)->sig != NULL){
        if( cmp( (*pl)->sig->dato, clave) == 0){
            elim = (*pl)->sig;
            (*pl)->sig = (*pl)->sig->sig;
            free(elim->dato);
            free(elim);
            return;
        }
        pl = & (*pl)->sig;
    }
}

void eliminarTodasOcurrenciasEnLista(tLista* pl, void* clave, int (*cmp) (const void* a, const void* b)){
    tNodo* elim;

    if( cmp( (*pl)->dato, clave) == 0){
            elim = *pl;
            *pl = (*pl)->sig;
            free(elim->dato);
            free(elim);
    }
    while( (*pl)->sig != NULL){
        if( cmp( (*pl)->sig->dato, clave) == 0){
            elim = (*pl)->sig;
            (*pl)->sig = (*pl)->sig->sig;
            free(elim->dato);
            free(elim);
            return;
        }
        pl = & (*pl)->sig;
    }
}

void eliminarUltimaOcurrenciaEnLista(tLista* pl, void* clave, int (*cmp) (const void* a, const void* b)){
    tNodo* elim;
    tNodo* preElim;

    while( (*pl)->sig != NULL){
        if( cmp( (*pl)->sig->dato, clave) == 0){
            elim = (*pl)->sig;
            preElim = *pl;
        }
        pl = & (*pl)->sig;
    }
    if(elim==*pl){
        elim = *pl;
        *pl = (*pl)->sig;
    }
    else{
        preElim->sig = elim->sig;
    }
    free(elim->dato);
    free(elim);
}

int insertarEnPosicionN(tLista* pl, const void* dato, unsigned tam, unsigned n){
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

    while(n--){
        pl = & (*pl)->sig;
    }

    nue->sig = (*pl)->sig;
    *pl = nue;
    return EXITO;
}

int eliminarPosicionN(tLista* pl, unsigned n){
    tNodo* elim;

    if(*pl == NULL){
        return FRACASO;
    }
    while(n--){
        pl = & (*pl)->sig;
        if((*pl) == NULL){
            return FRACASO;
        }
    }

    elim = *pl;
    *pl = elim->sig;
    free(elim->dato);
    free(elim);
    return EXITO;
}

int eliminarUltimosN(tLista* pl, unsigned n){
    tLista* inicio;
    tNodo* elim;
    int contador;

    contador=0;
    if(*pl == NULL){
        return FRACASO;
    }
    inicio = pl;
    while(*pl != NULL){
        contador++;
        pl = & (*pl)->sig;
    }
    if(contador<n){
        return FRACASO;
    }

    while( (contador--) - n){
        inicio = & (*inicio)->sig;
    }

    while(*inicio !=NULL){
        elim = *inicio;
        free(elim->dato);
        free(elim);
        *inicio = elim->sig;
    }
    return EXITO;

}

void ordenarListav2(tLista* pl, int (*cmp) (const void* a, const void* b)){
    tLista *sublista,
           *menor,
           *iterador;

    if(*pl == NULL){
        return;
    }

    while( (*pl)->sig != NULL){
        menor = pl;
        iterador = pl;
        while( *iterador !=NULL){
            //printf("\nmenor:%d --- iterador:%d\n", *((int*) (*menor)->dato), *((int*) (*iterador)->dato));
            if( cmp( (*menor)->dato, (*iterador)->dato )>0){
                menor = &(*iterador);
            }
            iterador = & (*iterador)->sig;
        }
        sublista = pl;
        pl = menor;

        iterador = sublista;
        if(sublista != menor){
            while( (*iterador)->sig != *menor){
                iterador = & (*iterador)->sig;
            }
            (*iterador) = NULL;
        }

        iterador = menor;
        if(sublista != menor){
            while( *iterador != NULL){
                //printf("\nmenor:%d --- iterador:%d\n", *((int*) (*menor)->dato), *((int*) (*iterador)->dato));
                iterador = & (*iterador)->sig;
            }
            *iterador = *sublista;
        }
        pl = & (*pl)->sig;
        mostrarLista(pl, mostrarEntero);
    }
}
