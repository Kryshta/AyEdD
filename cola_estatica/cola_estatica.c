#include "cola_estatica.h"

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))
#define COLA_LLENA 0
#define BIEN_APILADO 1
#define NADA_PARA_DESAPILAR 0
#define ELEMENTO_DESACOLADO 1
#define ELEMENTO_COPIADO 1

void crearCola(t_cola* cola){
    cola->disponible=MAX;
    cola->pri = 0;
    cola->ult = 0;
}

int colaVacia(const t_cola* cola){
    return cola->disponible == MAX;
}

int colaLlena(const t_cola* cola, unsigned tamElem){
    return cola->disponible < (tamElem+sizeof(unsigned));
}

void vaciarCola(t_cola* cola){
    cola->disponible = MAX;
    cola->pri = cola->ult;
}

int acolar(t_cola* cola, const void* dato, unsigned tamElem){
    unsigned ini,
             fin;

    if(tamElem > (cola->disponible+sizeof(unsigned)) ){
        return COLA_LLENA;
    }
    cola->disponible -= tamElem + sizeof(unsigned);
    ini = MINIMO( MAX-cola->ult, sizeof(unsigned) );
    if(ini!=0){
        memcpy(cola->vec+cola->ult, &tamElem, ini);
    }
    fin = sizeof(unsigned)-ini;
    if(fin!=0){
        memcpy(cola->vec, ( (char*) (&tamElem) )+ini, fin);
    }
    cola->ult = fin?fin:cola->ult+ini;

    ini = MINIMO(MAX-cola->ult, tamElem);
    if(ini!=0){
        memcpy(cola->vec+cola->ult, dato, ini);
    }
    fin = tamElem-ini;
    if(fin!=0){
        memcpy(cola->vec, ((char*) dato)+ini, fin);
    }
    cola->ult = fin?fin:cola->ult+ini;

    return BIEN_APILADO;
}

int desacolar(t_cola* cola, void* destinoDato, unsigned tamElem){
    unsigned ini,
             fin,
             tamAux,
             tamRecup;

    if(cola->disponible == MAX){
        return NADA_PARA_DESAPILAR;
    }

    ini = MINIMO(MAX-cola->pri, sizeof(unsigned));
    if(ini){
        memcpy(&tamAux, cola->vec + cola->pri, ini);
    }
    fin = sizeof(unsigned) - ini;
    if(fin){
        memcpy(&tamAux+ini, cola->vec, fin);
    }
    cola->pri = fin?fin:ini+cola->pri;
    tamRecup = MINIMO(tamElem, tamAux);
    ini = MINIMO(MAX - cola->pri, tamRecup);
    if(ini){
        memcpy(destinoDato, cola->vec + cola->pri, ini);
    }
    fin = tamRecup - ini;
    if(fin){
        memcpy( (char*) destinoDato + ini, cola->vec, fin);
    }

    cola->disponible += sizeof(unsigned) + tamAux;
    cola->pri += tamAux;

    return ELEMENTO_DESACOLADO;
}

int primeroEnCola(const t_cola* cola, void* destinoDato, unsigned tamElem){
    unsigned ini,
             fin,
             tamAux,
             tamRecup,
             colaPriAux;

    if(cola->disponible == MAX){
        return NADA_PARA_DESAPILAR;
    }

    ini = MINIMO(MAX-cola->pri, sizeof(unsigned));
    if(ini){
        memcpy(&tamAux, cola->vec + cola->pri, ini);
    }
    fin = sizeof(unsigned) - ini;
    if(fin){
        memcpy(&tamAux+ini, cola->vec, fin);
    }
    colaPriAux = fin?fin:ini+cola->pri;
    tamRecup = MINIMO(tamElem, tamAux);
    ini = MINIMO(MAX - colaPriAux, tamRecup);
    if(ini){
        memcpy(destinoDato, cola->vec + colaPriAux, ini);
    }
    fin = tamRecup - ini;
    if(fin){
        memcpy( (char*) destinoDato + ini, cola->vec, fin);
    }

    return ELEMENTO_COPIADO;
}
