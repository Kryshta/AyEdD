#include "header.h"
#include "TDA_Cola\header.h"

int main()
{
    printf("Hello world!\n");

//FILE *fPedidos, *fReponer, *fStock, *fAtender;

    //crearLoteBinario();
    FILE* fPedidos;
    FILE* fAtender;
    FILE* fReponer;
    FILE* fBinario;

    pedido pedidoLeido;
    int subtotal, decisionCola, cantStock, puntoReposicion;
    char codigoActual[10];

    fPedidos = fopen("pedidos.txt", "rt");
    if(!fPedidos)
        return -1;

    fAtender = fopen("atender.txt", "at");
    if(!fAtender)
        return -2;

    fReponer = fopen("reponer.txt", "at");
    if(!fAtender)
        return -3;

    fBinario = fopen("stock.bin", "rb");
    if(!fBinario)
        return -4;

    /*
    puts(pedidoLeido.sector);
    puts(pedidoLeido.solicitante);
    puts(pedidoLeido.codProd);
    printf("%d", pedidoLeido.cant);
    */

    while(!feof(fPedidos)){
        tCola colaPendientes;
        crearCola(&colaPendientes);
        subtotal=0;
        //Lectura inicial
        leerPedido(fPedidos, &pedidoLeido);
        subtotal+=pedidoLeido.cant;
        strcpy(codigoActual,pedidoLeido.codProd);

        while(strcmp(codigoActual,pedidoLeido.codProd)){
            leerPedido(fPedidos, &pedidoLeido);
            subtotal+=pedidoLeido.cant;
            //mandarlo a cola de pendientes
        }
    //leer stock y cantReposicion del codigo en el binario
    decisionCola = decidirCola(subtotal, cantStock, puntoReposicion);

    //mandar cola de pendientes al archivo que corresponda
    if(decisionCola==1){
        //while !colaVacia
        ///sacardecola(cola, &pedidoLeido, sizeof(pedido))
        ///fwrite(&pedidoLeido, sizeof(pedido),1, fAtender)
        //fclose(fAtender
    }

        if(decisionCola==-1){
        //while !colaVacia
        ///sacardecola(cola, &pedidoLeido, sizeof(pedido))
        ///fwrite(&pedidoLeido, sizeof(pedido),1, fAtender)
        //fclose(fAtender
    }

    }
    //cerrar archivos


    return 0;
}
