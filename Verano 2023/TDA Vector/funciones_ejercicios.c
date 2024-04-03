#include "header.h"
#include "header_ejercicio.h"

int cargarElemento(pilaDinamica* pila1){
    int input;
    printf("\nIngrese numero a cargar: ");
    scanf("%d", &input);
    return insertar_en_pila_dinamica(pila1, sizeof(int), &input);
}

int cargarArchivo(pilaDinamica* pila1, FILE* pFile){
    return 1;
}

void ordenarPila(pilaDinamica* pilaOrigen, pilaDinamica* pilaOrdenada){
    pilaDinamica ascendente, descendente;
    crear_pila_dinamica(&ascendente);
    crear_pila_dinamica(&descendente);
    int elemento, provisorio, status;
    int topeAscendente, topeDescendente;

    while(!pila_dinamica_vacia(pilaOrigen)){
        status= sacar_de_pila_dinamica(pilaOrigen,&elemento,sizeof(int));
        if (status==0)
            exit(-1);
        status = tope_de_pila_dinamica(&ascendente, &topeAscendente, sizeof(int));
        if(status==0)
            topeAscendente=0;
        status = tope_de_pila_dinamica(&descendente, &topeDescendente, sizeof(int));
            if(status==0)
                topeDescendente=MAX_ENTERO;
        memcpy(&elemento, pilaOrigen,sizeof(int));

        if(elemento<topeAscendente){
            while(elemento<topeAscendente){
                status = sacar_de_pila_dinamica(&ascendente, &provisorio,sizeof(int));
                if(status==0){
                    topeAscendente=0;
                }
                else{
                    insertar_en_pila_dinamica(&descendente,sizeof(int), &provisorio);
                }
                status = tope_de_pila_dinamica(&ascendente, &topeAscendente, sizeof(int));
                if(status==0){
                    topeAscendente=0;
                }
            }
        }
        if(elemento>topeDescendente){
            while(elemento>topeDescendente){
                status = sacar_de_pila_dinamica(&descendente, &provisorio,sizeof(int));
                if(status==0){
                    topeDescendente=MAX_ENTERO;
                }
                else{
                    status = insertar_en_pila_dinamica(&ascendente,sizeof(int), &provisorio);
                }
                status = tope_de_pila_dinamica(&descendente, &topeDescendente, sizeof(int));
                if(status==0){
                    topeDescendente=MAX_ENTERO;
                }
            }
        }
        insertar_en_pila_dinamica(&ascendente, sizeof(int), &elemento);
    }
    //Ordeno en forma ascendente en pilaordenada
    while(!pila_dinamica_vacia(&ascendente)){
        sacar_de_pila_dinamica(&ascendente, &provisorio, sizeof(int));
        insertar_en_pila_dinamica(&descendente,sizeof(int), &provisorio);
    }
    while(!pila_dinamica_vacia(&descendente)){
        sacar_de_pila_dinamica(&descendente,pilaOrdenada,sizeof(int));
    }
    return;
}


/*

|  |            |  |
|44|            |55|
|23|            |66|
|10|            |77|
|--|            |--|
ascendente      descendente

//Solo enteros positivos que quepan en un int de 32 bytes

*/


void desapilar_y_mostrar(pilaDinamica* pilaOrdenada){
    int elemento, status;
    while(!pila_dinamica_vacia(pilaOrdenada)){
        status = sacar_de_pila_dinamica(pilaOrdenada, &elemento, sizeof(int));
        if (status==0)
            exit(-1);
        printf("%d ", elemento);
    }
    return;
}
