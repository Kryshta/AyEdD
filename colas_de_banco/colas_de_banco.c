#include "cola_de_banco.h"


void generarArchivo(char* filename){
    int i;
    FILE* pFile;

    tCliente vectorClientes[] = {
                        {1, 'E', 100},
                        {1, 'E', 250},
                        {1, 'D', 200},
                        {2, 'D', 50},
                        {2, 'E', 50},
                        {3, 'D', 1000}
    };

    /*
    //TEST
    for(i=0; i < sizeof(vectorClientes)/sizeof(vectorClientes[0]); i++){
        printf("%d\t%c\t%d\n", vectorClientes[i].id, vectorClientes[i].tipo_mov, vectorClientes[i].importe);
    }

    */

    pFile = fopen(filename,"wb");
    if(!pFile){
        printf("Nose pudo crear el archivo");
        exit(-1);
    }

    for(i=0; i < sizeof(vectorClientes)/sizeof(vectorClientes[0]); i++){
        fwrite(vectorClientes+i, sizeof(tCliente),1,pFile);
    }

    fclose(pFile);
}

void procesarArchivo(char* filename, t_cola* colaNormal, t_cola* colaPrioritaria){
    tCliente clienteAuxiliar;
    tCliente clienteAuxiliar2;
    t_cola colaProvisoria;
    FILE* pFile;
    int importeTotal,
        clientePrevio;

    crearCola(&colaProvisoria);
    pFile = fopen(filename, "rb");
    if(!pFile){
        printf("No se pudo abrir wel archivo\n");
        exit(-1);
    }
    importeTotal=0;

    fread(&clienteAuxiliar, sizeof(tCliente), 1, pFile);
    clientePrevio = clienteAuxiliar.id;

    while(!feof(pFile)){
        while(clienteAuxiliar.id==clientePrevio && !feof(pFile)){
            clientePrevio = clienteAuxiliar.id;
            importeTotal += clienteAuxiliar.importe;
            acolar(&colaProvisoria, &clienteAuxiliar, sizeof(tCliente));
            fread(&clienteAuxiliar, sizeof(tCliente), 1, pFile);
        }
        if(importeTotal>500){
            while(!colaVacia(&colaProvisoria)){
                desacolar(&colaProvisoria, &clienteAuxiliar2, sizeof(tCliente));
                acolar(colaPrioritaria, &clienteAuxiliar2, sizeof(tCliente));
            }
        }
        else{
            while(!colaVacia(&colaProvisoria)){
                desacolar(&colaProvisoria, &clienteAuxiliar2, sizeof(tCliente));
                acolar(colaNormal, &clienteAuxiliar2, sizeof(tCliente));
            }
        }
        importeTotal=0;
        clientePrevio = clienteAuxiliar.id;
    }
    fclose(pFile);
}
