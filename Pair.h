/**
 * Par de punteros de char
 * Autor: Ka Fung (1810492)
 * Fecha: 17/06/2020 
 */

#ifndef __PAIR_H__
    #define __PAIR_H__
     
    /* Estructura de Par(palabra1, palabra2) */
    typedef struct {
        char *x;
        char *y;
    } Pair;

    Pair* create_pair(char* x, char* y);
    void print_pair(Pair* pair);
#endif