#ifndef GERENCIADOR_ARQUIVO_H
#define GERENCIADOR_ARQUIVO_H

#include <stdio.h>

// Declaração externa da variável global
extern FILE *arquivo;

// Funções para inicializar e finalizar o arquivo
void inicializarArquivo(const char *modo);
void finalizarArquivo();

#endif
