#include "Lista_doblemente_enlazada.h"
#include "lote_de_pruebas.h"

int main()
{
    tLista lista1;
    int i;
    int vectorEnteros[10]={10,20,30,40,50,60,70,80,90,100};
    int clave;

    crearLista(&lista1);

    for(i=0;i<10;i++){
        insertarEnListaOrdenado(&lista1, vectorEnteros+i, sizeof(int), compararEnteros);
    }

    mostrarListaIzqDer(&lista1, mostrarEntero);
    puts("\n");
    recorrerListaDerIzq(&lista1, mostrarEntero);
    puts("\n");

    clave = 10;
    eliminarPorClave(&lista1, &clave, sizeof(int), compararEnteros);
    mostrarListaIzqDer(&lista1, mostrarEntero);
    puts("\n");
    recorrerListaDerIzq(&lista1, mostrarEntero);
    clave = 20;
    printf("\nSe eliminaron %d ocurrencia(s)\n", eliminarOcurrencias(&lista1, &clave, compararEnteros));

    mostrarListaIzqDer(&lista1, mostrarEntero);
    puts("\n");
    recorrerListaDerIzq(&lista1, mostrarEntero);
    puts("\n");


    tEmpleado vecEmpleados[]= {
        {1, "Alex", "Armstrong", {1000,1}},
        {2, "Bruce", "Banner", {2000,2}},
        {3, "Charles", "Chaplin", {3000,3}},
        {4, "Danny", "DeVito", {4000,4}},
        {5, "Edward", "Elric", {5000,5}},
        {7, "Giorno", "Giovanna", {7000,7}},
        {8, "Helga", "Hufflepuff", {8000,8}},
        {10, "Jonathan", "Joestar",{10000,10}},
        {11, "Keira", "Knightley", {11000,11}},
        {12, "Lex", "Luthor", {12000,12}},
        {10, "Marylin", "Monroe", {13000,13}},
        {15, "Ozzy", "Ozbourne", {15000,15}},
        {16, "Peter", "Parker", {16000,16}},
        {18, "Rita", "Repulsa", {18000,18}},
        {19, "Steven", "Spielberg", {19000,19}},
        {20, "Tina", "Turner", {20000,20}},
        {22, "Vincent", "Valentine", {22000,22}},
        {23, "Walter", "White", {23000,23}}
    };
    //sumarSueldos(vecEmpleados+11,vecEmpleados+7);
    //compararIDEmpleados(vecEmpleados+15, &clave)?puts("No son iguales"):puts("Son iguales");

    tEmpleado dummy = {10, "dummy", "dummy",{100000,00}};

    /*
    for(i=0;i<sizeof(vecEmpleados)/sizeof(vecEmpleados[0]);i++){
        mostrarEmpleado(vecEmpleados+i);
    }
    */

    tLista lista2;
    crearLista(&lista2);

    for(i=0;i<sizeof(vecEmpleados)/sizeof(vecEmpleados[0]);i++){
        insertarEnListaOrdenado(&lista2, vecEmpleados+i, sizeof(tEmpleado),compararIDEmpleados);
    }
    mostrarListaIzqDer(&lista2, mostrarEmpleado);

    resumirOcurrencias(&lista2, &dummy, compararIDEmpleados, sumarSueldos);

    mostrarListaIzqDer(&lista2, mostrarEmpleado);

    printf("Hello world!\n");




    return 0;
}
