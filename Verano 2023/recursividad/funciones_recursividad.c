#include "recursividad_header.h"

int calcularFactorial(int n){
    if(n==1)
        return 1;
    return n *= calcularFactorial(n-1);

}

int esCadenaCapicua(char* cadena){
    char* recorridoInverso;
    int i=0,
        resultado=1;

    while(*(cadena+i) != '\0'){
        i++;
    }
    recorridoInverso = cadena+i-1;

    while(resultado==1 && cadena<recorridoInverso){
        if(*cadena != *recorridoInverso){
            resultado=0;
        }
        cadena++;
        recorridoInverso--;
    }
    return resultado;
}


int esCadenaCapicuaRecursiva(char* cadena){
    unsigned cantLetras=0;

    while(*(cadena+cantLetras) != '\0'){
        cantLetras++;
    }

    return funcionRecursiva(cadena, cantLetras);

}

int funcionRecursiva(char* cadena, unsigned cantLetras){
    if(cantLetras<=0){
        return 1;
    }

    //INCOMPLETO
    return 0;
}

int busquedaBinaria(int* array, int elem, unsigned tam){
    int* pInicio;
    int* pFin;
    int* medio;

    pInicio = array;
    pFin = array+tam-1;

    while(pInicio<pFin){
        medio = pInicio + (pFin-pInicio)/2;
        if(*medio == elem || *pInicio==elem || *pFin==elem)
            return ENCONTRADO;
        if(*medio<elem){
            pInicio = medio;
            pInicio++;
        }
        if(*medio>elem){
            pFin = medio;
            pFin--;
        }
    }

    return NO_ENCONTRADO;
}
