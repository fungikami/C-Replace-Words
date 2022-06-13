#ifndef LISTA_H
    #define LISTA_H
     
    /* Estructura de Par(palabra1, palabra2) */
    typedef struct {
        char *x;
        char *y;
    } Pair;

    /* Estructura de Nodo(par, anterior, siguiente) */
    struct Node {
        Pair* dato;
        struct Node* prev;
        struct Node* next;
    };
    
    Pair* createPair(char* x, char* y);
    void printPair(Pair* pair);
    void push(struct Node **head, Pair *words);
    void sortedInsert(struct Node** head, Pair* words);
    void printList(struct Node* node);

#endif