/**
 * Lista Doblemente Enlazada
 * Autor: Ka Fung (1810492)
 * Fecha: 17/06/2020 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "Pair.h"

/**
 * Insertar un nuevo nodo, ordenada descendentemente, en la lista.
 * Se toma como comparación la longitud de la primera palabra del par
 * Parametros:
 *      - head: cabeza de la lista
 *      - words: palabras a insertar
 */ 
void sorted_insert_list(struct Node** head, Pair* words) {
    int word_length = strlen(words->x);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error al reservar memoria\n");
        return;
    }

    /* Crea nuevo nodo */
    new_node->data = words;
    new_node->length = word_length;

    if (*head == NULL) {
        /* Si la lista esta vacia, simplemente se agrega */
        *head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    } else if (word_length > (*head)->length) {
        /* Si la palabra es mayor que la primera, se agrega al inicio */
        new_node->next = *head;
        new_node->prev = NULL;
        (*head)->prev = new_node;
        *head = new_node;
    } else {
        /* En cambio, se busca en donde insertar */
        struct Node* current = *head;
        while (current->next != NULL && 
                word_length < current->next->length) {
            current = current->next;
        }
        
        /* Actualiza los punteros */
        new_node->next = current->next;
        if (current->next != NULL) {
            current->next->prev = new_node;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

/**
 * Imprime la lista doblemente enlazada
 * Parámetros:
 *     - node: puntero a la cabeza de la lista
 */
void print_list(struct Node* node) {
    while (node != NULL) {
        print_pair(node->data);
        node = node->next;
    }
}
