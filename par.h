#ifndef PAR_H
    #define PAR_H
     
    /* Estructura de Par(palabra1, palabra2) */
    typedef struct {
        char *x;
        char *y;
    } Pair;

    Pair* createPair(char* x, char* y);
    void printPair(Pair* pair);
#endif