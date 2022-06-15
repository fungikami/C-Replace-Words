/**
 * Lista Doblemente Enlazada de Pares de palabras
 * Autor: Ka Fung (1810492)
 * Fecha: 16/06/2020 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Par.h"

/**
 * Inserta un nuevo nodo en una lista ordenada descendentemente.
 * Se toma como comparación la longitud de la primera palabra del par.
 * Parametros:
 *      - cabeza: cabeza de la lista
 *      - palabras: palabras a insertar
 */ 
void insertar_ordenado_lista(struct Nodo** cabeza, Par* palabras) {
    int len_palabra = strlen(palabras->x);
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (!nuevo) {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    /* Crea nuevo nodo */
    nuevo->dato = palabras;
    nuevo->len = len_palabra;

    if (!(*cabeza)) {
        /* Si la lista esta vacia, simplemente se agrega */
        *cabeza = nuevo;
        nuevo->next = NULL;
        nuevo->prev = NULL;
    } else if (len_palabra > (*cabeza)->len) {
        /* Si la palabra es mayor que la primera, se agrega al inicio */
        nuevo->next = *cabeza;
        nuevo->prev = NULL;
        (*cabeza)->prev = nuevo;
        *cabeza = nuevo;
    } else {
        /* En cambio, se busca en donde insertar */
        struct Nodo* actual = *cabeza;
        while (actual->next != NULL && len_palabra < actual->next->len) {
            actual = actual->next;
        }
        
        /* Actualiza los punteros */
        nuevo->next = actual->next;
        if (actual->next != NULL) {
            actual->next->prev = nuevo;
        }
        actual->next = nuevo;
        nuevo->prev = actual;
    }
}

/**
 * Imprime la lista doblemente enlazada
 * Parámetros:
 *     - nodo: puntero a la cabeza de la lista
 */
void print_list(struct Nodo* nodo) {
    while (nodo != NULL) {
        print_par(nodo->dato);
        nodo = nodo->next;
    }
}

/**
 * Libera la memoria asignada de la lista doblemente enlazada
 * Parámetros:
 *    - nodo: puntero a la cabeza de la lista
 */ 
void liberar_lista(struct Nodo* nodo) {
    while (nodo != NULL) {
        struct Nodo* temp = nodo;
        nodo = nodo->next;
        liberar_par(temp->dato);
        free(temp);
    }
}
