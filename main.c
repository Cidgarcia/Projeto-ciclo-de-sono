#include <stdio.h>
#include "menu.h"
#include "sono.h"
#include "historicosono.h" // Assumindo que esse é o arquivo que contém as funções de CRUD de HistoricoSono

int main() {
    int opcao;

    do {
        mostrarMenu();

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Por favor, insira um numero.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch (opcao) {
            case 1:
                registrarSono();
                break;
            case 2:
                exibirHistorico();
                break;
            case 3: {
                EstatisticasSono estatisticas = calcularEstatisticas();
                printf("\n========== Estatisticas do Sono ==========\n");
                printf("Total de Ciclos: %d\n", estatisticas.totalCiclos);
                printf("Tempo Total de Sono: %d minutos\n", estatisticas.totalTempoSono);
                printf("Media de Tempo por Ciclo: %.2f minutos\n", estatisticas.mediaTempoPorCiclo);
                printf("Percentual Sono Leve: %d%%\n", estatisticas.porcentagemSonoLeve);
                printf("Percentual Sono Pesado: %d%%\n", estatisticas.porcentagemSonoPesado);
                printf("Percentual Sono REM: %d%%\n", estatisticas.porcentagemSonoREM);
                printf("=========================================\n");
                break;
            }
            case 4:
                excluirRegistro();
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao entre 1 e 5.\n");
        }
    } while (opcao != 5);

    return 0;
}