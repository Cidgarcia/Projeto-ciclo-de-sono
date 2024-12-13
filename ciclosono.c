#include "ciclosono.h"
#include <stdio.h>

// Declarações para acessar diretamente o arquivo global
extern FILE *arquivo;
void inicializarArquivo(const char *modo);
void finalizarArquivo();

void usarArquivoCiclos() {
    inicializarArquivo("a");
    if (arquivo != NULL) {
        fprintf(arquivo, "Escrevendo dados de ciclos...\n");
    }
    finalizarArquivo();
}


CicloSono criarCicloSono(int ciclos, int totalMinutos) {
    CicloSono ciclo = { ciclos, totalMinutos };
    return ciclo;
}

void exibirCicloSono(const CicloSono* ciclo) {
    printf("Ciclos: %d, Total Minutos: %d\n", ciclo->ciclos, ciclo->totalMinutos);
}

void atualizarCicloSono(CicloSono* ciclo, int ciclos, int totalMinutos) {
    ciclo->ciclos = ciclos;
    ciclo->totalMinutos = totalMinutos;
}

void excluirCicloSono(CicloSono* ciclo) {
    ciclo->ciclos = 0;
    ciclo->totalMinutos = 0;
}
