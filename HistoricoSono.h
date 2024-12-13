#ifndef HISTORICOSONO_H
#define HISTORICOSONO_H
#include <stdio.h>

extern FILE *arquivo;
#include "ciclosono.h"
#include "estatisticassono.h"

typedef struct {
    CicloSono sonoLeve;
    CicloSono sonoPesado;
    CicloSono sonoREM;
} HistoricoSono;

// Funções CRUD para HistoricoSono
void armazenarHistorico(HistoricoSono historico);
void exibirHistorico();
void excluirRegistro();

#endif // HISTORICOSONO_H
