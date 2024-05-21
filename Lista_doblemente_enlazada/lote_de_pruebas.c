#include "lote_de_pruebas.h"

void mostrarEmpleado(const void* empleado){
    printf("%3d - %20s, %-20s - %7d.%02d\n", ((tEmpleado*)empleado)->id, ((tEmpleado*)empleado)->apellido, ((tEmpleado*)empleado)->nombre, ((tEmpleado*)empleado)->sueldo.entero, ((tEmpleado*)empleado)->sueldo.decimal);
}

void sumarSueldos(void* sueldoDestino, const void* sueldoOrigen){
    int auxDecimal,
        auxEntero,
        carry;
    carry = 0;

    auxDecimal = ((tEmpleado*)sueldoOrigen)->sueldo.decimal + ((tEmpleado*)sueldoDestino)->sueldo.decimal;
    if(auxDecimal>=100){
        carry = 1;
        auxDecimal -= 100;
    }
    auxEntero = ((tEmpleado*)sueldoOrigen)->sueldo.entero + ((tEmpleado*)sueldoDestino)->sueldo.entero;
    ((tEmpleado*)sueldoDestino)->sueldo.entero = auxEntero + carry;
    ((tEmpleado*)sueldoDestino)->sueldo.decimal = auxDecimal;
}

int compararIDEmpleados(const void* estructura, const void* clave){
    return ((tEmpleado*)estructura)->id - *((int*)clave);
}
