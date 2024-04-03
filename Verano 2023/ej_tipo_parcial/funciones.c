#include "header.h"

void crearLoteBinario(){
    FILE* binario;
    stock nuevoStock;

    binario = fopen("stock.bin","wb");

    strcpy(nuevoStock.codProd, "OFO01");
    nuevoStock.stock=15;
    nuevoStock.ptoRep=10;
    fwrite(&nuevoStock, sizeof(stock),1,binario);

    strcpy(nuevoStock.codProd, "ABC2");
    nuevoStock.stock=138;
    nuevoStock.ptoRep=40;
    fwrite(&nuevoStock, sizeof(stock),1,binario);

    strcpy(nuevoStock.codProd, "LRM3");
    nuevoStock.stock=64;
    nuevoStock.ptoRep=12;
    fwrite(&nuevoStock, sizeof(stock),1,binario);


    strcpy(nuevoStock.codProd, "");
    nuevoStock.stock=0;
    nuevoStock.ptoRep=0;
    for(int i=4;i<23;i++){
        fwrite(&nuevoStock, sizeof(stock),1,binario);
    }

    //linea 23
    strcpy(nuevoStock.codProd, "XS23");
    nuevoStock.stock=85;
    nuevoStock.ptoRep=50;
    fwrite(&nuevoStock, sizeof(stock),1,binario);

    fclose(binario);
}

void leerPedido(FILE* pedidos, pedido* pedidoLeido){
    fscanf(pedidos,"%[^|]|%[^|]|%[^|]|%d",pedidoLeido->sector, pedidoLeido->solicitante, pedidoLeido->codProd,&(pedidoLeido->cant));
}

int decidirCola(int subtotal, int cantStock, int puntoReposicion){
    //mayor/igual: atender
    //menor: reponer
    if(cantStock-subtotal>=puntoReposicion)
        return 1;
    return -1;
}
