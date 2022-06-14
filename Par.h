/**
 * Par de punteros de char
 * Autor: Ka Fung (1810492)
 * Fecha: 17/06/2020 
 */

#ifndef __PAR_H__
    #define __PAR_H__
     
    /* Estructura de Par(palabra1, palabra2) */
    typedef struct {
        char *x;
        char *y;
    } Par;

    Par* crear_par(char* x, char* y);
    void print_par(Par* par);
    void liberar_par(Par* par);
#endif