#ifndef ESTATISTICASONO_H
#define ESTATISTICASONO_H
#include <stdio.h>

extern FILE *arquivo;
typedef struct {
    int totalCiclos;
    int totalTempoSono;
    float mediaTempoPorCiclo;
    int porcentagemSonoLeve;
    int porcentagemSonoPesado;
    int porcentagemSonoREM;
} EstatisticasSono;

// Funções CRUD para EstatisticasSono
EstatisticasSono criarEstatisticasSono(int totalCiclos, int totalTempoSono, float mediaTempoPorCiclo,
                                       int porcentagemSonoLeve, int porcentagemSonoPesado, int porcentagemSonoREM);
void exibirEstatisticasSono(const EstatisticasSono* estatisticas);
void atualizarEstatisticasSono(EstatisticasSono* estatisticas, int totalCiclos, int totalTempoSono, float mediaTempoPorCiclo,
                               int porcentagemSonoLeve, int porcentagemSonoPesado, int porcentagemSonoREM);
void excluirEstatisticasSono(EstatisticasSono* estatisticas);
EstatisticasSono calcularEstatisticas();

#endif // ESTATISTICASONO_H
