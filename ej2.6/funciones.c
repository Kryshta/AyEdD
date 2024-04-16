#include "ej2.6.h"

int generarArchivo(char* filename){
    //int intArray[] = {10,20,30,15,5,1};
    //int intArray[] = {9,8,7,6,5,4,3,2};
    //int intArray[] = {0,1,2,3,4,5,6,7};
    int intArray[] = {1,1,2,2,3,3,4,4,1,1};

    int i;

    FILE* pArchivo;
    pArchivo = fopen(filename, "wb");
    if(!pArchivo){
        printf("%s", "Error al escribir el archivo\n");
        return FAIL;
    }
    for(i=0;i<sizeof(intArray)/sizeof(intArray[i]);i++){
        fwrite(&intArray[i],sizeof(int),1,pArchivo);
    }
    fclose(pArchivo);

    return OK;
}

int leerArchivo(char* filename){
    int lectura;
    FILE* pArchivo;

    pArchivo = fopen(filename, "rb");
    if(!pArchivo){
        printf("%s", "Error al leer el archivo\n");
        return FAIL;
    }

    while(!feof(pArchivo)){
        fread(&lectura,sizeof(int),1,pArchivo);
        if(!feof(pArchivo)){
            printf("%d ", lectura);
        }
    }
    fclose(pArchivo);
    return OK;
}
int comparacionEnteros(void* elemento1, void* elemento2){
    return *((int*)elemento2) - *((int*)elemento1);
}

int ordenarArchivo(char* filename, tPilaEstatica* pila1, tPilaEstatica* pila2, unsigned tamElem, int comparacion(void* elem1, void* elem2), unsigned orden){
    char elementoDesarchivado[MAX_ELEM_SIZE],
        topePila1[MAX_ELEM_SIZE],
        topePila2[MAX_ELEM_SIZE],
        elementoProvisorio[MAX_ELEM_SIZE];
    int pila1novacia,
        pila2novacia;
    FILE* pArchivo;

    pArchivo = fopen(filename, "rb");
    if(!pArchivo){
        printf("%s", "Error al leer el archivo\n");
        return FAIL;
    }

    fread(&elementoDesarchivado,tamElem,1,pArchivo);
    if(!feof(pArchivo)){
        apilar(pila1,&elementoDesarchivado,tamElem);
    }

    fread(&elementoDesarchivado,tamElem,1,pArchivo);
    if(!feof(pArchivo)){
        verTope(pila1,topePila1,tamElem);

        if(comparacion(&topePila1, &elementoDesarchivado)>0){
            apilar(pila2,&elementoDesarchivado,tamElem);
        }
        else{
            desapilar(pila1,&elementoProvisorio,tamElem);
            apilar(pila2,&elementoProvisorio,tamElem);
            apilar(pila1,&elementoDesarchivado,tamElem);
        }
    }

    fread(&elementoDesarchivado,tamElem,1,pArchivo);
    while(!feof(pArchivo)){
        pila1novacia = verTope(pila1,&topePila1,tamElem);
        pila2novacia = verTope(pila2,&topePila2,tamElem);

        while(pila1novacia && comparacion(&topePila1,&elementoDesarchivado)<0){
            desapilar(pila1,&elementoProvisorio,tamElem);
            apilar(pila2,&elementoProvisorio,tamElem);
            pila1novacia = verTope(pila1,&topePila1,tamElem);
        }

        while(pila2novacia && comparacion(&topePila2,&elementoDesarchivado)>0){
            desapilar(pila2,&elementoProvisorio,tamElem);
            apilar(pila1,&elementoProvisorio,tamElem);
            pila2novacia = verTope(pila2,&topePila2,tamElem);
        }

        apilar(pila1,&elementoDesarchivado,tamElem);
        fread(&elementoDesarchivado,tamElem,1,pArchivo);
    }

    if(orden == DESCENDENTE){
        while(!pilaVacia(pila2)){
            desapilar(pila2,&elementoProvisorio,tamElem);
            apilar(pila1,&elementoProvisorio,tamElem);
        }
    }

    if(orden == ASCENDENTE){
        while(!pilaVacia(pila1)){
            desapilar(pila1,&elementoProvisorio,tamElem);
            apilar(pila2,&elementoProvisorio,tamElem);
        }
    }

    return OK;
}

void desapilarMostrandoEnteros(tPilaEstatica* pila, unsigned tamElem){
    int enteroDesapilado;

    printf("%s", "\nPILA ORDENADA:\n");
    while(!pilaVacia(pila)){
        desapilar(pila,&enteroDesapilado,tamElem);
        printf("%d\n", enteroDesapilado);
    }
    printf("%s", "\n---------------\n");
}
