#ifndef EJ3_5_H_INCLUDED
#define EJ3_5_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dni;
    char nyap[60];
} tCliente;

typedef struct{
    int hora;
    int minutos;
}tHora;

void testGeneradorAleatorios();
void testGenerarNombresAleatorios(tCliente* cliente);
void adelantarMinuto(tHora* horaActual);
void ejecutarSimulacion();

#endif // EJ3_5_H_INCLUDED
