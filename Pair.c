/**
 * Par de punteros de char
 * Autor: Ka Fung (1810492)
 * Fecha: 17/06/2020 
 */
#include <stdio.h>
#include <stdlib.h>
#include "Pair.h"

/**
 * Crear un nuevo par de palabras
 * Parametros:
 *     - x: palabra1
 *     - y: palabra2
 * Retorno:
 *    - pair: par de palabras
 */
Pair* create_pair(char* x, char* y) {
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair->x = x;
    pair->y = y;
    return pair;
}

/**
 * Imprimir un par de palabras
 * Parametros:
 *    - pair: par de palabras
 */ 
void print_pair(Pair* pair) {
    printf("(%s, %s)\n", pair->x, pair->y);
}