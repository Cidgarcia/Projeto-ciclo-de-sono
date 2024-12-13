#ifndef CICLOSONO_H
#define CICLOSONO_H
#include <stdio.h>

extern FILE *arquivo;
typedef struct {
    int ciclos;
    int totalMinutos;
} CicloSono;

// Funções CRUD para CicloSono
CicloSono criarCicloSono(int ciclos, int totalMinutos);
void exibirCicloSono(const CicloSono* ciclo);
void atualizarCicloSono(CicloSono* ciclo, int ciclos, int totalMinutos);
void excluirCicloSono(CicloSono* ciclo);

#endif // CICLOSONO_H
