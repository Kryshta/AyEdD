#ifndef EJ2_6_H_INCLUDED
#define EJ2_6_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "../pila_estatica/pila_estatica.h"

#define FILENAME "data.dat"
#define TOPE 6
#define FAIL 0
#define OK 1
#define MAX_ELEM_SIZE 64
#define ASCENDENTE 1
#define DESCENDENTE 0

int generarArchivo(char* filename);
int leerArchivo(char* filename);
int comparacionEnteros(void* elemento1, void* elemento2);
int ordenarArchivo(char* filename, tPilaEstatica* pila1, tPilaEstatica* pila2, unsigned tamElem, int comparacion(void* elem1, void* elem2), unsigned orden);
void desapilarMostrandoEnteros(tPilaEstatica* pila, unsigned tamElem);

#endif // EJ2_6_H_INCLUDED
