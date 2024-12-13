#include <stdio.h>
#include <time.h>
#include "historico.h"

void armazenarHistorico(HistoricoSono historico) {
    time_t t = time(NULL);
    struct tm *horarioLocal = localtime(&t);

    char dataHora[100];
    strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", horarioLocal);

    FILE *arquivo = fopen("historico_sono.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "========== Resumo do Sono ==============================\n");
        fprintf(arquivo, "Data e Horario do Registro: %s\n", dataHora);
        fprintf(arquivo, "Sono Leve:    %3d ciclos (%3d minutos)\n", historico.sonoLeve.ciclos, historico.sonoLeve.totalMinutos);
        fprintf(arquivo, "Sono Pesado:  %3d ciclos (%3d minutos)\n", historico.sonoPesado.ciclos, historico.sonoPesado.totalMinutos);
        fprintf(arquivo, "Sono REM:     %3d ciclos (%3d minutos)\n", historico.sonoREM.ciclos, historico.sonoREM.totalMinutos);
        fprintf(arquivo, "========================================================\n\n");
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo de historico para escrita.\n");
    }
}

void calcularMediaTempo(HistoricoSono historico) {
    printf("\n========== Media de Tempo por Ciclo ==========\n\n");
//Por exemplo, se o tempo total de sono leve for 120 minutos e houver 4 ciclos, a média será 120 / 4 = 30 minutos por ciclo.
    if (historico.sonoLeve.ciclos > 0) {
        printf("Sono Leve:   %d minutos por ciclo\n", historico.sonoLeve.totalMinutos / historico.sonoLeve.ciclos); //
    } else {
        printf("Sono Leve:   0 minutos por ciclo\n");
    }

    if (historico.sonoPesado.ciclos > 0) {
        printf("Sono Pesado: %d minutos por ciclo\n", historico.sonoPesado.totalMinutos / historico.sonoPesado.ciclos);
    } else {
        printf("Sono Pesado: 0 minutos por ciclo\n");
    }

    if (historico.sonoREM.ciclos > 0) {
        printf("Sono REM:    %d minutos por ciclo\n", historico.sonoREM.totalMinutos / historico.sonoREM.ciclos);
    } else {
        printf("Sono REM:    0 minutos por ciclo\n");
    }
}
