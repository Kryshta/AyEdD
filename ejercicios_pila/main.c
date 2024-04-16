#include "ejercicios_pila.h"
#include "../pila_dinamica/pila_dinamica.h"

int main()
{
    /*
    1- Crear/cargar Pila1 por teclado con 5 elementos. Poner los primeros tres elementos de la PilaAux1 y los restantes a otra PilaAux2, ambas inicializadas en null/vacias.
    */

    t_pila pilaAux1,
            pilaAux2;
    int i;
    int elemento;

    crearPila(&pilaAux1);
    crearPila(&pilaAux2);

    for(i=1; i<=5; i++){
        printf("\nIngrese elemento a cargar:");
        scanf("%d", &elemento);
        if(i<=3){
            apilar(&pilaAux1, &elemento, sizeof(int));
        }
        else{
            apilar(&pilaAux2, &elemento, sizeof(int));
        }
    }

    //Pruebas varias
    /*
    printf("%d", pilaLlena(&pilaAux1,sizeof(int)));
    printf("%d", pilaVacia(&pilaAux1));
    verTope(&pilaAux2, &elemento, sizeof(int));
    desapilar(&pilaAux2, &elemento, sizeof(int));
    printf("\n---\n%d", elemento);
    verTope(&pilaAux2, &elemento, sizeof(int));
    printf("\n---\n%d", elemento);
    desapilar(&pilaAux2, &elemento, sizeof(int));
    printf("\n---\n%d", elemento);
    printf("\n---\n%d", pilaVacia(&pilaAux2));
    vaciarPila(&pilaAux2);
    printf("\n---\n%d", pilaVacia(&pilaAux2));
    */

    /*
    2- Cargar PilaOrigen por teclado e inicializar en vacio PilaDestino. Pasar todos los elementos de PilaOrigen a la PilaDestino.
    */

    t_pila pilaOrigen;
    t_pila pilaDestino;
    int elemento2;

    crearPila(&pilaOrigen);
    crearPila(&pilaDestino);

    for(i=1; i<=5; i++){
        printf("\nIngrese elemento a cargar:");
        scanf("%d", &elemento2);
        apilar(&pilaOrigen, &elemento, sizeof(int));
    }

    while(!pilaVacia(&pilaOrigen)){
        desapilar(&pilaOrigen, &elemento2, sizeof(int));
        apilar(&pilaDestino, &elemento2, sizeof(int));
    }


    return 0;
}
