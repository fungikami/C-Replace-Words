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

/* Insertar un nuevo nodo en frente de la lista */
void push_list(struct Node** head, Pair* words) {
    /* Reserva memoria */
    int length = strlen(words->x);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error al reservar memoria\n");
        return;
    }

    /* Asigna datos y actualiza punteros */
    new_node->data = words;
    new_node->length = length;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = new_node;
    }

    /* Actualiza head */
    (*head) = new_node;
}

void sorted_insert_list(struct Node** head, Pair* words) {
    int word_length = strlen(words->x);
    struct Node* current;
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
        current = *head;
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

void print_list(struct Node* node) {
    struct Node* last;

    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        print_pair(node->data);
        last = node;
        node = node->next;
    }
    
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        print_pair(last->data);
        last = last->prev;
    }
}
