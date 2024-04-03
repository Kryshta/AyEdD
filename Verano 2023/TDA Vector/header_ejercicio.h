#ifndef HEADER_EJERCICIO_H_INCLUDED
#define HEADER_EJERCICIO_H_INCLUDED

#define MAX_ENTERO 2147483647
int cargarArchivo(pilaDinamica* pila1, FILE* pFile);
int cargarElemento(pilaDinamica* pila1);
void ordenarPila(pilaDinamica* pilaOrigen, pilaDinamica* pilaOrdenada);
void desapilar_y_mostrar(pilaDinamica* pilaOrdenada);

#endif // HEADER_EJERCICIO_H_INCLUDED
