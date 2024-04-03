#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct sNodo{
    void* info;
    unsigned tam;
    struct sNodo* sig;
} tNodo;

typedef tNodo* tLista;

void crearLista(tLista* pl);
void recorrerLista(tLista* pl, void accion(void* func));
int insertarAlPrincipio(tLista* pl, void* dato, unsigned cantBytes);
int insertarAlFinal(tLista* pl, void* dato, unsigned cantBytes);
int insertarPorPosicion(tLista* pl, void* info, unsigned cantBytes, unsigned posicion);
int insertarOrdenado(tLista* pl, void* info, unsigned cantBytes);
int eliminarInfo(tLista* pl, void* info, unsigned cantBytes);
int filtrarLista(tLista* pl, int ffiltro(void* dato));
int reduceLista(tLista* pl, void freduccion(void* acumulador, const void* dato));

#endif // LISTA_H_INCLUDED
