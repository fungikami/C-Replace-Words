#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

void extract_words(char* archivo, struct Node** head);

int main(int argc, char **argv)
{
    /*A TOMAR EN CUENTA
    SIEMPRE VERIFICAR QUE ABRA/LEA/ASIGNEMEMORIA
    VER COMO FREE()
    */
    struct Node* head, *node;
    FILE *ifp;
    char ch, read[100];
    int word_len, i, p = 0;

    /* Revisar que se recibe los argumentos ARREGLAR */
    if (argc < 2) {
        printf("Uso: %s <archivo_entrada> <archivo_salida>\n", argv[0]);
        return 1;
    }

    /* Extraer palabras y almacenarlas en la lista doblemente enlazada*/
    head = NULL;
    extract_words(argv[1], &head);
    
    ifp = fopen("Archivo1.txt", "r");

    if (ifp == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    while (1) {
        ch = fgetc(ifp);
        if (ch == EOF) {
            break;
        }
        printf("%c", ch);
    }

    
    rewind(ifp);
    while (!feof(ifp)) {
        fscanf(ifp, "%s", read);
        node = head;
        while (node != NULL) {
            /* printf("%s\n", node->dato->x); */
            if (strcmp(read, node->dato->x) == 0) {
                strcpy(read, node->dato->y);
                break;
            }
            node = node->next;
        }
        printf("%s", read);
    }
    return 0;
}

void extract_words(char* archivo, struct Node** head) {
    FILE* ptr;
    char temp1[50];
    char temp2[50];
    char* word1;
    char* word2;

    ptr = fopen(archivo, "r");
    if (ptr == NULL) {
        printf("El archivo no puede ser abierto\n");
        return;
    }

    while(fscanf(ptr, "%[^:]:%s\n", temp1, temp2) != EOF) {
        word1 = (char *)malloc(sizeof(char) * strlen(temp1) + 1);
        word2 = (char *)malloc(sizeof(char) * strlen(temp2) + 1);
        strcpy(word1, temp1);
        strcpy(word2, temp2);
        sortedInsert(head, createPair(word1, word2));
    }
    printList(*head);
    fclose(ptr);
}

void replace_words(struct Node** head) {
    
}