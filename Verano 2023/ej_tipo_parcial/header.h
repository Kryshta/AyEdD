#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA_Cola/header.h"

typedef struct {
    char sector[50];
    char solicitante[50];
    char codProd[10];
    int cant;
}pedido;

typedef struct {
    char codProd[10];
    int stock;
    int ptoRep;
}stock;

void crearLoteBinario();
void leerPedido(FILE* pedidos, pedido* pedidoLeido);
int decidirCola(int subtotal, int cantStock, int puntoReposicion);

#endif // HEADER_H_INCLUDED
