#include "historicosono.h"
#include "ciclosono.h"
#include "estatisticassono.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void exibirHistorico() {
    FILE *arquivo = fopen("historico_sono.txt", "r");
    if (arquivo == NULL) {
        printf("Nao ha registros de sono.\n");
        return;
    }
    char linha[256];
    printf("\n========== Historico de Sono ==========\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    printf("=======================================\n");
    fclose(arquivo);

    EstatisticasSono estatisticas = calcularEstatisticas();
    exibirEstatisticasSono(&estatisticas);
}

void excluirRegistro() {
    // Lógica original
}
