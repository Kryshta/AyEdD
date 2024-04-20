#include "ej3.5.h"
#include "../cola_dinamica/cola_dinamica.h"

void testGeneradorAleatorios(){
    //tarda unos 13 segundos
    unsigned i,
             result;
    unsigned resultVector[3]= {0,0,0};

    printf( "2147483647 numeros generados aleatoriamente: \n\n" );
    for( i=1; i<2147483647; i++ ){
        result = rand()%3;
        resultVector[result]++;
    }

    printf("Porcentaje de ceros: %.7f\n", ((float) resultVector[0]/ (float) (resultVector[0]+resultVector[1]+resultVector[2]) )*100.0);
    printf("Porcentaje de unos: %.7f\n", ((float) resultVector[1]/ (float) (resultVector[0]+resultVector[1]+resultVector[2]) )*100.0);
    printf("Porcentaje de dos: %.7f\n", ((float) resultVector[2]/ (float) (resultVector[0]+resultVector[1]+resultVector[2]) )*100.0);
}

int generarNumeroAleatorio(){
    //puede retornar 0, 1 o 2
    return rand()%3;
}

void adelantarMinuto(tHora* horaActual){
    horaActual->minutos++;
    if (horaActual->minutos>59){
        horaActual->hora++;
        horaActual->minutos = 0;
    }
}

void generarClienteAleatorio(tCliente* cliente){
    char nombres[10][20];
    strcpy(nombres[0], "Bernard Arnault");
    strcpy(nombres[1], "Elon Musk");
    strcpy(nombres[2], "Jeff Bezos");
    strcpy(nombres[3], "Marck Zuckerberg");
    strcpy(nombres[4], "Larry Elison");
    strcpy(nombres[5], "Warren Buffett");
    strcpy(nombres[6], "Bill Gates");
    strcpy(nombres[7], "Steve Ballmer");
    strcpy(nombres[8], "Mukesh Ambani");
    strcpy(nombres[9], "Larry Page");

    cliente->dni = 1000 * rand();
    strcpy(cliente->nyap, nombres[rand()%10]);
}

void testGenerarNombresAleatorios(tCliente* cliente){
    int i;
    for(i=0;i<10;i++){
        generarClienteAleatorio(cliente);
        printf("DNI: %10d - Nombre y Apellido: %s\n", cliente->dni, cliente->nyap);
    }
}

void ejecutarSimulacion(){
    unsigned demoraAtencion[3] = {1,3,5};
    unsigned intervaloArribo[3] = {1,5,9};
    tHora horaActual;
    tCliente clienteSiendoAtendido,
             clienteNuevo;
    int contadorVecesColaVacia,
        booleanAtendiendo,
        remanenteAtencion,
        minutosHastaProximoCliente;
    tCola cola;

    horaActual.hora = 9;
    horaActual.minutos = 0;
    contadorVecesColaVacia = 0;
    booleanAtendiendo = 0;
    minutosHastaProximoCliente = 0;
    crearColaDinamica(&cola);

    while(contadorVecesColaVacia<=5){
        if(horaActual.hora>14){
            puts("Cerro el banco!");
            return;
        }
        printf("Hora actual: %02d:%02d\n", horaActual.hora, horaActual.minutos);
        adelantarMinuto(&horaActual);
        if(booleanAtendiendo){
            printf("Atendiendo a %s durante los proximos %d minutos\n", clienteSiendoAtendido.nyap, remanenteAtencion);
            remanenteAtencion--;
            if(!remanenteAtencion){
                desacolar(&cola, &clienteSiendoAtendido, sizeof(tCliente));
                if(colaVacia(&cola)){
                    puts("Se vacio la cola!");
                    contadorVecesColaVacia++;
                    booleanAtendiendo = 0;
                }
            }
        }
        else{
            if(!colaVacia(&cola)){
                verPrimeroEnCola(&cola, &clienteSiendoAtendido, sizeof(tCliente));
                remanenteAtencion = demoraAtencion[generarNumeroAleatorio()];
                booleanAtendiendo = 1;
            }
        }
        if(minutosHastaProximoCliente == 0){
            generarClienteAleatorio(&clienteNuevo);
            acolar(&cola, &clienteNuevo, sizeof(tCliente));
            minutosHastaProximoCliente = intervaloArribo[generarNumeroAleatorio()];
        }
        else{
            minutosHastaProximoCliente--;
        }
    }
    puts("La cola se vacio 5 veces! Fin de la simulacion!");
}
