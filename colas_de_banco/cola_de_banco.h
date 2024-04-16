#ifndef COLA_DE_BANCO_H_INCLUDED
#define COLA_DE_BANCO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cola_estatica/cola_estatica.h"

typedef struct{
    int id;
    char tipo_mov;
    int importe;
} tCliente;

void generarArchivo(char* filename);
void procesarArchivo(char* filename, t_cola* colaNormal, t_cola* colaPrioritaria);


#endif // COLA_DE_BANCO_H_INCLUDED
