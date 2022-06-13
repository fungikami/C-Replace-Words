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