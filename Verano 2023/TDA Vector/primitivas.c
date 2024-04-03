#include "header.h"

///ESTATICO
void crear_vector(pila* nueva_pila){
    nueva_pila->tope_de_pila = TAM_PILA-1;
}

int vector_lleno(pila* pila1, unsigned cantBytes){
    return pila1->tope_de_pila < cantBytes + sizeof(unsigned);
}

int vector_vacio(pila* pila1){
    return pila1->tope_de_pila == TAM_PILA-1;
}

int insertar_elemento(pila* pila1, unsigned cantBytes, const void* elemento){
    if (pila1->tope_de_pila < cantBytes+sizeof(unsigned))
        return 0;
    pila1->tope_de_pila -= cantBytes;
    memcpy(pila1 + pila1->tope_de_pila, elemento,cantBytes);
    pila1->tope_de_pila -= sizeof(unsigned);
    memcpy(pila1 + pila1->tope_de_pila, &cantBytes,sizeof(unsigned));
    return 1;
}

int eliminar_elemento(pila* pila1){
    unsigned cantBytes;

    if (pila1->tope_de_pila == TAM_PILA-1)
        return 0;
    memcpy(&cantBytes, pila1, sizeof(unsigned));
    pila1->tope_de_pila += sizeof(unsigned) + cantBytes;
    return 1;
}

void eliminar_vector(pila* pila1){
    pila1->tope_de_pila = TAM_PILA-1;
}


///DINAMICO
void crear_pila_dinamica(pilaDinamica* pila1){
    *pila1 = NULL;
}

int pila_dinamica_llena(const pilaDinamica* pila1, unsigned cantBytes){
    tNodo* aux;
    int result = 0;
    aux = (tNodo*) malloc(sizeof(tNodo));
    aux->info = malloc(cantBytes);
    result = (aux == NULL || aux->info == NULL);
    free(aux);
    free(aux->info);
    return result;
}

int pila_dinamica_vacia(const pilaDinamica* pila1){
    return *pila1 == NULL;
}

int insertar_en_pila_dinamica(pilaDinamica* pila1, unsigned cantBytes, void* info){
    tNodo* nuevo_nodo;

    nuevo_nodo = (tNodo*) malloc(sizeof(tNodo));
    if(nuevo_nodo==NULL)
        return 0;

    nuevo_nodo->info = malloc(cantBytes);
    if(nuevo_nodo->info==NULL)
        return 0;

    nuevo_nodo->siguiente = (struct tNodo*) *pila1;
    nuevo_nodo->tam = cantBytes;
    *pila1 = nuevo_nodo;
    memcpy(nuevo_nodo->info,info,cantBytes);
    return 1;
}

int sacar_de_pila_dinamica(pilaDinamica* pila1, void* destino, unsigned cantBytes){
    tNodo* aux;

    if(*pila1 == NULL)
        return 0;

    memcpy(destino, (*pila1)->info, cantBytes);
    aux = (tNodo*) (*pila1)->siguiente;
    free( (*pila1)->info);
    free(*pila1);
    *pila1 = aux;
    return 1;
}

int tope_de_pila_dinamica(const pilaDinamica* pila1, void* destino, unsigned cantBytes){
    unsigned minimo;

    if(*pila1 == NULL)
        return 0;

    if(cantBytes<((*pila1)->tam))
    {
        minimo=cantBytes;
    }
    else
    {
        minimo=(*pila1)->tam;
    }
    memcpy(destino, (*pila1)->info, minimo);
    return 1;
}

int vaciar_pila_dinamica(pilaDinamica* pila1){
    if(*pila1 == NULL)
        return 0;

    while(pila1!=NULL){
        tNodo* aux = (tNodo*) (*pila1)->siguiente;
        free((*pila1)->info);
        free(*pila1);
        *pila1=aux;
    }
    return 1;
}
