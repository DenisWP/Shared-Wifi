#include "index.h"

int page_index(char buffer[], int size_buffer){
    char index[] = "web/index.html";
    char ch;
    int x;
    FILE *arq;

    buffer[0] = '\x0';

    arq = fopen(index, "r");

    if ( arq == NULL ) {
        printf("[Erro]: nao foi possivel abrir o arquivo web/index.html\n");
        return 0;
    } else {
        for ( x = 0; (ch = fgetc(arq)) != EOF && x < size_buffer ; x++ ) {
            buffer[x] = ch;
        }
        buffer[x] = '\0';

        if(fclose(arq) == EOF){
            printf("[Erro]: nao foi possivel fechar o arquivo web/index.html\n");
            return 0;
        }
    }

    return 1;
}