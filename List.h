/**
 * Lista Doblemente Enlazada
 * Autor: Ka Fung (1810492)
 * Fecha: 17/06/2020 
 */

#ifndef LIST_H
    #define LIST_H
    #include "Pair.h"

    /* Estructura de Nodo(par, anterior, siguiente) */
    struct Node {
        Pair* dato;
        struct Node* prev;
        struct Node* next;
    };
    
    void push(struct Node **head, Pair *words);
    void sortedInsert(struct Node** head, Pair* words);
    void printList(struct Node* node);
#endif