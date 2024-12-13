#include "estatisticassono.h"
#include "historicosono.h" // Para o tipo HistoricoSono
#include <string.h>        // Para strstr
#include <stdio.h>

// Declarações para acessar diretamente o arquivo global
extern FILE *arquivo;
void inicializarArquivo(const char *modo);
void finalizarArquivo();

void lerEstatisticasDoArquivo() {
    inicializarArquivo("r");
    if (arquivo != NULL) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), arquivo)) {
            printf("Lendo: %s", buffer);
        }
    }
    finalizarArquivo();
}

EstatisticasSono criarEstatisticasSono(int totalCiclos, int totalTempoSono, float mediaTempoPorCiclo,
                                       int porcentagemSonoLeve, int porcentagemSonoPesado, int porcentagemSonoREM) {
    EstatisticasSono estatisticas = { totalCiclos, totalTempoSono, mediaTempoPorCiclo, porcentagemSonoLeve, porcentagemSonoPesado, porcentagemSonoREM };
    return estatisticas;
}

void exibirEstatisticasSono(const EstatisticasSono* estatisticas) {
    printf("Total de Ciclos: %d\n", estatisticas->totalCiclos);
    printf("Total de Tempo de Sono: %d minutos\n", estatisticas->totalTempoSono);
    printf("Média de Tempo por Ciclo: %.2f minutos\n", estatisticas->mediaTempoPorCiclo);
    printf("Porcentagem de Sono Leve: %d%%\n", estatisticas->porcentagemSonoLeve);
    printf("Porcentagem de Sono Pesado: %d%%\n", estatisticas->porcentagemSonoPesado);
    printf("Porcentagem de Sono REM: %d%%\n", estatisticas->porcentagemSonoREM);
}

EstatisticasSono calcularEstatisticas() {
    EstatisticasSono estatisticas = {0};
    HistoricoSono historicoAcumulado = {0};

    FILE *arquivo = fopen("historico_sono.txt", "r");
    if (arquivo == NULL) {
        printf("Nao ha registros de sono.\n");
        return estatisticas;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strstr(linha, "Sono Leve:")) {
            sscanf(linha, "Sono Leve: %d ciclos (%d minutos)", &historicoAcumulado.sonoLeve.ciclos, &historicoAcumulado.sonoLeve.totalMinutos);
            estatisticas.totalCiclos += historicoAcumulado.sonoLeve.ciclos;
            estatisticas.totalTempoSono += historicoAcumulado.sonoLeve.totalMinutos;
        } else if (strstr(linha, "Sono Pesado:")) {
            sscanf(linha, "Sono Pesado: %d ciclos (%d minutos)", &historicoAcumulado.sonoPesado.ciclos, &historicoAcumulado.sonoPesado.totalMinutos);
            estatisticas.totalCiclos += historicoAcumulado.sonoPesado.ciclos;
            estatisticas.totalTempoSono += historicoAcumulado.sonoPesado.totalMinutos;
        } else if (strstr(linha, "Sono REM:")) {
            sscanf(linha, "Sono REM: %d ciclos (%d minutos)", &historicoAcumulado.sonoREM.ciclos, &historicoAcumulado.sonoREM.totalMinutos);
            estatisticas.totalCiclos += historicoAcumulado.sonoREM.ciclos;
            estatisticas.totalTempoSono += historicoAcumulado.sonoREM.totalMinutos;
        }
    }
    fclose(arquivo);

    estatisticas.mediaTempoPorCiclo = estatisticas.totalCiclos > 0 ? (float)estatisticas.totalTempoSono / estatisticas.totalCiclos : 0;

    if (estatisticas.totalTempoSono > 0) {
        estatisticas.porcentagemSonoLeve = (historicoAcumulado.sonoLeve.totalMinutos * 100) / estatisticas.totalTempoSono;
        estatisticas.porcentagemSonoPesado = (historicoAcumulado.sonoPesado.totalMinutos * 100) / estatisticas.totalTempoSono;
        estatisticas.porcentagemSonoREM = (historicoAcumulado.sonoREM.totalMinutos * 100) / estatisticas.totalTempoSono;
    }

    return estatisticas;
}
