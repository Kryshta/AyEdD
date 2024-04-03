#ifndef EJ2_7_H_INCLUDED
#define EJ2_7_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "../pila_estatica/pila_estatica.h"

#define FAIL 0
#define OK 1

int cargarNumerosEnPila(tPilaEstatica* pila, int* vec, unsigned cant);
void desapilarMostrandoEnteros(tPilaEstatica* pila);
void sumarNumerosGrandes(tPilaEstatica* pila1, tPilaEstatica* pila2, tPilaEstatica* resultado);

#endif // EJ2_7_H_INCLUDED
