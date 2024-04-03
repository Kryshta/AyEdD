#ifndef RECURSIVIDAD_HEADER_H_INCLUDED
#define RECURSIVIDAD_HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCONTRADO 1
#define NO_ENCONTRADO 0

int calcularFactorial(int n);
int esCadenaCapicua(char* cadena);
int busquedaBinaria(int* array, int elem, unsigned tam);
int funcionRecursiva(char* cadena, unsigned cantLetras);


#endif // RECURSIVIDAD_HEADER_H_INCLUDED
