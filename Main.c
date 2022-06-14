#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

FILE* open_file(char* file);
void extract_words(char* file, struct Node** head);
void replace_words(char* file, struct Node* head);

int main(int argc, char **argv) {
    /*A TOMAR EN CUENTA
    SIEMPRE VERIFICAR QUE ABRA/LEA/ASIGNEMEMORIA
    VER COMO FREE()
    */
    struct Node* head;
    int i;

    /* Revisar que se recibe los argumentos ARREGLAR */
    if (argc < 3) {
        printf("Usage: sustituir palabras.txt Archivo1.txt ... \n");
        return 1;
    }

    /* Extraer palabras y almacenarlas en la lista doblemente enlazada */
    head = NULL;
    extract_words(argv[1], &head);
    /* print_list(head); */
    
    /* Por cada archivo, reemplazar las palabras */
    for (i = 2; i < argc; i++) {
        replace_words(argv[i], head);
    }

    /* Liberar memoria */
    /* free_list(head); */

    return 0;
}

/**
 * Reemplaza las palabras en el archivo dado
 *  
 */
void replace_words(char* file, struct Node* head) {
    FILE* ptr;
    struct Node* current;
    int i;
    char ch;
    
    ptr = open_file(file);

    ch = fgetc(ptr);
    while (ch != EOF) {
        printf ("%c", ch);
        ch = fgetc(ptr);
    }

    rewind(ptr);

    ch = fgetc(ptr);
    current = head;
    i = 0;
    while (ch != EOF) {    
        while (current != NULL) {
            /* Itera mientras coincidan los chars */
            while (ch == current->data->x[i]) {
                ch = fgetc(ptr);
                i++;
            }

            if (i == current->length) {
                /* Si coincide toda la palabra, se imprime */
                printf("%s", current->data->y);
                break;
            } else {
                /* Si no coincide toda la palabra, se 
                    verifica con la siguiente palabra de la lista*/
                printf("%d", i);
                fseek(ptr, -i, SEEK_CUR);
                current = current->next;
                i = 0;
            }
        }
        i = 0;
        if (current == NULL) {
            printf("%c", ch);
            ch = fgetc(ptr);
        } 
        current = head;  
    }
}

FILE* open_file(char* file) {
    FILE* ifp = fopen(file, "r");
    if (!ifp) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    return ifp;
}

void extract_words(char* file, struct Node** head) {
    FILE* ptr;
    char temp1[60], temp2[60];

    /* Abre el archivo */
    ptr = open_file(file);

    /* Extrae las palabras y las guarda en la lista enlazada */
    while(fscanf(ptr, "%[^:]:%[^\n]\n", temp1, temp2) != EOF) {
        char* word1 = (char *)malloc(sizeof(char) * strlen(temp1) + 1);
        char* word2 = (char *)malloc(sizeof(char) * strlen(temp2) + 1);

        if (!word1 || !word2) {
            printf("Error al reservar memoria\n");
            exit(1);
        }

        strcpy(word1, temp1);
        strcpy(word2, temp2);
        sorted_insert_list(head, create_pair(word1, word2));
    }

    fclose(ptr);
}