/**
 * Par de punteros de char
 * Autor: Ka Fung (1810492)
 * Fecha: 17/06/2020 
 */
#include <stdio.h>
#include <stdlib.h>
#include "Pair.h"

Pair* createPair(char* x, char* y) {
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair->x = x;
    pair->y = y;
    return pair;
}

void printPair(Pair* pair) {
    printf("(%s, %s)\n", pair->x, pair->y);
}