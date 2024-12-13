#ifndef HISTORICO_H
#define HISTORICO_H
#include <stdio.h>

extern FILE *arquivo;
typedef struct {
    int ciclos;
    int totalMinutos;
} CicloSono;

typedef struct {
    CicloSono sonoLeve;
    CicloSono sonoPesado;
    CicloSono sonoREM;
} HistoricoSono;

void armazenarHistorico(HistoricoSono historico);
void calcularMediaTempo(HistoricoSono historico);

#endif
