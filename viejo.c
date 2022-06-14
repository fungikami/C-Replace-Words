void extract_words(char* archivo, struct Node** head) {
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
            push(head, createPair(temp, word));
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

    printList(*head);
}



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