#include "header.h"
#include "header_ejercicio.h"

int main()
{
    pilaDinamica pila1;
    pilaDinamica pilaOrdenada;
    FILE* pFile;
    int seleccion, status;

    crear_pila_dinamica(&pila1);

    do{
        printf("Seleccione una opcion: \n1.Crear pila \n2.Cargar elemento en pila manualmente \n3.Cargar elementos desde archivo \n4.Ordenar pila \n5.Vaciar y mostrar pila \n6.Salir\n");
        scanf("%d", &seleccion);

        switch (seleccion){
            case 1: crear_pila_dinamica(&pila1);
                break;
            case 2: status = cargarElemento(&pila1);
                    if(status==1){
                                printf("\nElemento cargado satisfactoriamente!\n");
                    }
                    else{
                        printf("\nError en la carga!\n");
                    }
                break;
            case 3: status = cargarArchivo(&pila1, pFile);
                    if(status==1){
                        printf("\nArchivo cargado satisfactoriamente!\n");
                    }
                    else{
                        printf("\nError en la carga!\n");
                    }
                break;
            case 4: ordenarPila(&pila1, &pilaOrdenada);
                break;
            case 5: desapilar_y_mostrar(&pilaOrdenada);
                break;
            case 6:
                break;
            default: printf("\nOpcion invalida\n");
        }

    }while(seleccion!=6);
    return 0;
}
