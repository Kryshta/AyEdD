#include "header.h"
int ponerEnCola(tCola* pc, const void* pd, unsigned cantBytes){
    unsigned ini, fin;

    if(cantBytes+sizeof(unsigned)<pc->tamDisp)
        return 0;
    pc->tamDisp -= cantBytes+sizeof(unsigned);

    ini = MINIMO(sizeof(unsigned), TAM_COLA-pc->ult);
    fin = sizeof(unsigned)-ini;

    if(ini!=0){
        memcpy(pc->dato + pc->ult, &cantBytes, ini);
    }
    if(fin!=0){
        memcpy(pc->dato, ((char*) &cantBytes)+ini, fin);
    }
    pc->ult = fin?fin:pc->ult+ini;

    ini = MINIMO(cantBytes, TAM_COLA-pc->ult);
    fin = cantBytes-ini;

    if(ini!=0){
        memcpy(pc->dato+pc->ult, pd, ini);
    }
    if(fin!=0){
        memcpy(pc->dato, ((char*) pd)+ini, fin);
    }

    pc->ult = fin?fin:pc->ult+ini;

    return 1;
}

int sacarDeCola(tCola* pc, void* pd, unsigned cantBytes){
    unsigned ini, fin, tamAux, tamARecup;

    if(pc->tamDisp == TAM_COLA)
        return 0;

    ini = MINIMO(sizeof(unsigned), TAM_COLA-pc->pri);
    fin = sizeof(unsigned)-ini;

    if(ini)
        memcpy(&tamAux, pc->dato, ini);
    if(fin)
        memcpy( ((char*) &tamAux) + ini, pc->dato, fin);

    pc->pri = fin?fin:pc->pri + ini;
    pc->tamDisp += tamAux + sizeof(unsigned);

    tamARecup = MINIMO (cantBytes, tamAux);

    ini = MINIMO(cantBytes, TAM_COLA-pc->pri);
    fin = tamARecup - ini;

    if(ini)
        memcpy(pd, pc->dato+pc->pri, ini);
    if(fin)
        memcpy( ((char*)pd)+ini, pc->dato, fin);

    pc->pri = (pc->pri + tamAux) % TAM_COLA;

    return 1;
}

void vaciarCola(tCola* pc){
    pc->pri = pc->ult;
    pc->tamDisp = TAM_COLA;
}
