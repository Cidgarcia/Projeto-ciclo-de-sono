#include <stdio.h>

FILE *arquivo = NULL; // Definição única da variável global

void inicializarArquivo(const char *modo) {
    if (arquivo == NULL) {
        arquivo = fopen("historico_sono.txt", modo);
        if (arquivo == NULL) {
            perror("Erro ao abrir o arquivo");
        }
    }
}

void finalizarArquivo() {
    if (arquivo != NULL) {
        fclose(arquivo);
        arquivo = NULL;
    }
}
