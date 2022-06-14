/**
 * Lista Doblemente Enlazada
 * Autor: Ka Fung (1810492)
 * Fecha: 17/06/2020 
 */

#ifndef __LIST_H__
    #define __LIST_H__
    #include "Pair.h"

    /* Estructura de Nodo(par, anterior, siguiente) */
    struct Node {
        Pair* data;
        int length;
        struct Node* prev;
        struct Node* next;
    };
    
    void push(struct Node **head, Pair *words);
    void sorted_insert_list(struct Node** head, Pair* words);
    void print_list(struct Node* node);
#endif