#include "ej2.7.h"

int cargarNumerosEnPila(tPilaEstatica* pila, int* vec, unsigned cant){
    int i,
        resultado;

    for(i=0;i<cant;i++){
        resultado = apilar(pila,vec+i,sizeof(int));
        if (resultado == 0){
            return FAIL;
        }
    }
    return OK;
}

void desapilarMostrandoEnteros(tPilaEstatica* pila){
    int enteroExtraido;

    printf("%s", "\nNUMEROS EN LA PILA:\n");
    while(!pilaVacia(pila)){
        desapilar(pila,&enteroExtraido,sizeof(int));
        printf("%d\n", enteroExtraido);
    }
}

void sumarNumerosGrandes(tPilaEstatica* pila1, tPilaEstatica* pila2, tPilaEstatica* resultado){
    int carry,
        digito1,
        digito2,
        sumaDigitos;

    carry = 0;

    while(!pilaVacia(pila1) && !pilaVacia(pila2)){
        desapilar(pila1,&digito1,sizeof(int));
        desapilar(pila2,&digito2,sizeof(int));
        sumaDigitos = (digito1+digito2+carry)%10;
        carry = (digito1+digito2+carry)/10;
        apilar(resultado,&sumaDigitos,sizeof(int));
    }

    if(pilaVacia(pila1)){
        while(!pilaVacia(pila2)){
            desapilar(pila2,&digito2,sizeof(int));
            sumaDigitos = (digito2+carry)%10;
            carry = (digito2+carry)/10;
            apilar(resultado,&sumaDigitos,sizeof(int));
        }
    }

    if(pilaVacia(pila2)){
        while(!pilaVacia(pila1)){
            desapilar(pila1,&digito1,sizeof(int));
            sumaDigitos = (digito1+carry)%10;
            carry = (digito1+carry)/10;
            apilar(resultado,&sumaDigitos,sizeof(int));
        }
    }
}
