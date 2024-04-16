#include "cola_de_banco.h"


int main()
{
    t_cola colaNormal;
    t_cola colaPrioritaria;
    tCliente cliente;

    crearCola(&colaNormal);
    crearCola(&colaPrioritaria);

    generarArchivo("clientes.dat");
    procesarArchivo("clientes.dat", &colaNormal, &colaPrioritaria);

    puts("Movimientos de clientes normales");
    printf("%10s %20s %10s\n", "ID", "Tipo de movimiento", "Importe");
    while(!colaVacia(&colaNormal)){
        desacolar(&colaNormal, &cliente, sizeof(tCliente));
        printf("%10d %20c %10d\n", cliente.id, cliente.tipo_mov, cliente.importe);
    }

    puts("Movimientos de clientes prioritarios");
    printf("%10s %20s %10s\n", "ID", "Tipo de movimiento", "Importe");
    while(!colaVacia(&colaPrioritaria)){
        desacolar(&colaPrioritaria, &cliente, sizeof(tCliente));
        printf("%10d %20c %10d\n", cliente.id, cliente.tipo_mov, cliente.importe);
    }

    printf("Hello world!\n");
    return 0;
}
