/* 
Lista Doblemente Enlazada
Autor: Ka Fung (1810492)
Fecha: 03/06/2020 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Pair* createPair(char* x, char* y) {
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair->x = x;
    pair->y = y;
    return pair;
}

void printPair(Pair* pair) {
    printf("(%s, %s)\n", pair->x, pair->y);
}

/* Insertar un nuevo nodo en frente de la lista */
void push(struct Node** head, Pair* words) {
    /* Reserva memoria */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error al reservar memoria\n");
        return;
    }

    /* Asigna datos */
    new_node->dato = words;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = new_node;
    }

    /* Actualiza head */
    (*head) = new_node;
}

void sortedInsert(struct Node** head, Pair* words) {
    struct Node* current;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error al reservar memoria\n");
        return;
    }

    /* Crea nuevo nodo */
    new_node->dato = words;

    if (*head == NULL) {
        /* Si la lista esta vacia, simplemente se agrega */
        *head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    } else if (strlen(words->x) > strlen((*head)->dato->x)) {
        /* Si la palabra es mayor que la primera, se agrega al inicio */
        new_node->next = *head;
        new_node->prev = NULL;
        (*head)->prev = new_node;
        *head = new_node;
    } else {
        /* En cambio, se busca en donde insertar */
        current = *head;
        while (current->next != NULL && 
                strlen(words->x) < strlen(current->next->dato->x)) {
            current = current->next;
        }
        new_node->next = current->next;
        
        /* Si el nuevo nodo no va al final de la lista, actualiza previo del sig */
        if (current->next != NULL) {
            current->next->prev = new_node;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

void printList(struct Node* node) {
    struct Node* last;

    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printPair(node->dato);
        last = node;
        node = node->next;
    }
    
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printPair(last->dato);
        last = last->prev;
    }
}
