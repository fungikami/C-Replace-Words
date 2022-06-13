/**
 * Par de punteros de char
 * Autor: Ka Fung (1810492)
 * Fecha: 17/06/2020 
 */

#ifndef PAIR_H
    #define PAIR_H
     
    /* Estructura de Par(palabra1, palabra2) */
    typedef struct {
        char *x;
        char *y;
    } Pair;

    Pair* createPair(char* x, char* y);
    void printPair(Pair* pair);
#endif