#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sono.h"
#include "ciclosono.h"
#include "historicosono.h"


// Declarações para acessar diretamente o arquivo global
extern FILE *arquivo;
void inicializarArquivo(const char *modo);
void finalizarArquivo();




void registrarSono() {
    int horaDormir, minutoDormir, horaAcordar, minutoAcordar;
    int minutosTotais;
    HistoricoSono historico;

    printf("Informe o horario que voce vai dormir (HH:MM): ");
    if (scanf("%d:%d", &horaDormir, &minutoDormir) != 2) {
        printf("Formato invalido. Por favor, insira no formato HH:MM.\n");
        return;
    }

    printf("Informe o horario maximo que voce pode acordar (HH:MM): ");
    if (scanf("%d:%d", &horaAcordar, &minutoAcordar) != 2) {
        printf("Formato invalido. Por favor, insira no formato HH:MM.\n");
        return;
    }

    // Calculando minutos totais de sono disponíveis
    minutosTotais = (horaAcordar * 60 + minutoAcordar) - (horaDormir * 60 + minutoDormir);
    if (minutosTotais <= 0) {
        minutosTotais += 24 * 60; // Ajusta para o próximo dia
    }

    historico.sonoLeve.totalMinutos = minutosTotais * 0.3;
    historico.sonoPesado.totalMinutos = minutosTotais * 0.4;
    historico.sonoREM.totalMinutos = minutosTotais * 0.3;

    historico.sonoLeve.ciclos = historico.sonoLeve.totalMinutos / 90;
    historico.sonoPesado.ciclos = historico.sonoPesado.totalMinutos / 90;
    historico.sonoREM.ciclos = historico.sonoREM.totalMinutos / 90;

    armazenarHistorico(historico);
    printf("Registro de sono salvo com sucesso!\n");

    // Calculando o melhor horário para acordar
    int inicioMinutos = horaDormir * 60 + minutoDormir;
    int fimMinutos = horaAcordar * 60 + minutoAcordar;

    // Ajustar para o próximo dia, se necessário
    if (fimMinutos <= inicioMinutos) {
        fimMinutos += 24 * 60;
    }

    int melhorHorarioMinutos = inicioMinutos;

    // Avançar em ciclos de 90 minutos até ultrapassar ou alcançar o limite
    while (melhorHorarioMinutos + 90 <= fimMinutos) {
        melhorHorarioMinutos += 90;
    }

    // O último ciclo completo antes do limite
    int melhorHora = (melhorHorarioMinutos / 60) % 24;
    int melhorMinuto = melhorHorarioMinutos % 60;
    printf("O melhor horario para acordar e as %02d:%02d horas.\n", melhorHora, melhorMinuto);
}
