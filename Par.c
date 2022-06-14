/**
 * Par de punteros de char
 * Autor: Ka Fung (1810492)
 * Fecha: 17/06/2020 
 */
#include <stdio.h>
#include <stdlib.h>
#include "Par.h"

/**
 * Crear un nuevo par de palabras
 * Parametros:
 *     - x: palabra1
 *     - y: palabra2
 * Retorno:
 *    - par: par de palabras
 */
Par* crear_par(char* x, char* y) {
    Par* par = (Par*)malloc(sizeof(Par));
    par->x = x;
    par->y = y;
    return par;
}

/**
 * Imprimir un par de palabras
 * Parametros:
 *    - par: par de palabras
 */ 
void print_par(Par* par) {
    printf("(%s, %s)\n", par->x, par->y);
}

/**
 * Libera la memoria asignada de un par de palabras
 * Parametros:
 *   - par: par de palabras
 */
void liberar_par(Par* par) {
    free(par->x);
    free(par->y);
    free(par);
}