void extract_palabras(char* archivo, struct Nodo** cabeza) {
    FILE* ptr;
    int i = 0;
    char ch;
    char* temp;
    char* word;

    ptr = fopen(archivo, "r");
    if (ptr == NULL) {
        printf("El archivo no puede ser abierto\n");
    }

    word = (char *)malloc(sizeof(char) * 100);
    if (word == NULL) {
        printf("Error al reservar memoria\n");
        return;
    }

    while (!feof(ptr)) {
        ch = fgetc(ptr);
        if (ch == ':') {
            word[i] = '\0';
            temp = word;
            word = (char *)malloc(sizeof(char) * 100);
            if (word == NULL) {
                printf("Error al reservar memoria\n");
                return;
            }
            i = 0;
        } else if (ch == ' ' || ch == '\n' || ch == '\t') {
            word[i] = '\0';
            push(cabeza, createPair(temp, word));
            word = (char *)malloc(sizeof(char) * 100);
            if (word == NULL) {
                printf("Error al reservar memoria\n");
                return;
            }
            i = 0;
        } else {
            word[i] = ch;
            i++;
        }
    }

    /*free(word);*/
    fclose(ptr);

    printList(*cabeza);
}



/* Insertar un nuevo nodo en frente de la lista */
void push_list(struct Nodo** cabeza, Par* palabras) {
    /* Reserva memoria */
    int length = strlen(palabras->x);
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al reservar memoria\n");
        return;
    }

    /* Asigna datos y actualiza punteros */
    nuevo->dato = palabras;
    nuevo->length = length;
    nuevo->next = *cabeza;
    nuevo->prev = NULL;

    if (*cabeza != NULL) {
        (*cabeza)->prev = nuevo;
    }

    /* Actualiza cabeza */
    (*cabeza) = nuevo;
}