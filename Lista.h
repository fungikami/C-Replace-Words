/**
 * Lista.h
 * Lista Doblemente Enlazada de Pares de palabras
 * Autor: Ka Fung (1810492)
 * Fecha: 16/06/2020 
 */

#ifndef __LISTA_H__
    #define __LISTA_H__
    #include "Par.h"

    /* Estructura de Nodo */
    struct Nodo {
        Par* dato;
        int len;
        struct Nodo* prev;
        struct Nodo* next;
    };
    
    void insertar_ordenado_lista(struct Nodo** cabeza, Par* palabras);
    void print_list(struct Nodo* nodo);
    void liberar_lista(struct Nodo* nodo);
#endif