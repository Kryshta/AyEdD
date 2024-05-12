<<<<<<< HEAD
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
=======
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
>>>>>>> 138f8c91317c85473a156d87c2b53a17c6040156
