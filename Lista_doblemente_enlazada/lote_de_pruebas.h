#ifndef LOTE_DE_PRUEBAS_H_INCLUDED
#define LOTE_DE_PRUEBAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int entero;
    int decimal;
} tDecimal;

typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    tDecimal sueldo;
} tEmpleado;

void mostrarEmpleado(const void* empleado);
void sumarSueldos(void* sueldoDestino, const void* sueldoOrigen);
int compararIDEmpleados(const void* estructura, const void* clave);

#endif // LOTE_DE_PRUEBAS_H_INCLUDED
