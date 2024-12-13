#ifndef GERENCIADOR_ARQUIVO_H
#define GERENCIADOR_ARQUIVO_H

#include <stdio.h>

// Declara��o externa da vari�vel global
extern FILE *arquivo;

// Fun��es para inicializar e finalizar o arquivo
void inicializarArquivo(const char *modo);
void finalizarArquivo();

#endif
