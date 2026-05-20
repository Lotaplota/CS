#include <stdio.h>
#include <stdlib.h>
#include "caminho.h"

void ExibirHistorico(Posicao *P) {
    while (P != NULL) {
        printf("(%d, %d)", P->X, P->Y);
        if (P->Proximo != NULL) printf(" -> ");
        P = P->Proximo;
    }
    printf("\n");
}

int main() {
    Caminho * C;
    Posicao * Fim;
    Posicao * Historico;

    // Sequência escolhida: LLLLLLLNNNNN
    // Posição inicial: (2, 2)
    // Movimentos:
    //     7 comandos Leste  -> x aumenta de 2 para 9
    //     5 comandos Norte  -> y aumenta de 2 para 7
    // Posição final esperada: (9, 7)

    C = InicializarCaminho("LLLLLLLNNNNN", 2, 2);

    if (C == NULL) {
        printf("Erro ao inicializar o caminho.\n");
        return 1;
    }

    // Teste da função DeterminarFim(C), cujo resultado esperado é Fim = (9, 7)
    Fim = DeterminarFim(C);
    if (Fim != NULL) printf("Posicao final: (%d, %d)\n", Fim->X, Fim->Y);

    // Teste da função HistoricoPosicoes(C), cujo resultado esperado é (2, 2) -> (3, 2) -> (4, 2) -> (5, 2) -> (6, 2) -> (7, 2) -> (8, 2) -> (9, 2) -> (9, 3) -> (9, 4) -> (9, 5) -> (9, 6) -> (9, 7)
    Historico = HistoricoPosicoes(C);
    printf("Historico de posicoes:\n");
    ExibirHistorico(Historico);

    // Teste da função CalcularDistanciaTotal(C): Como existem 12 comandos unitários, o resultado esperado é 12.
    printf("Distancia total percorrida: %d\n", CalcularDistanciaTotal(C));

    // Teste da função CalcularDistanciaGeometrica(C): no caso, a distância euclidiana entre (2,2) e (9,7) é sqrt((9 - 2)^2 + (7 - 2)^2) = 8.60
    printf("Distancia geometrica: %.2f\n", CalcularDistanciaGeometrica(C));

    // Teste da função CalcularDistanciaManhattan(C): no caso, o valor esperado é |9 - 2| + |7 - 2| = 7 + 5 = 12
    printf("Distancia de Manhattan: %d\n", CalcularDistanciaManhattan(C));

    // Teste da função ContarInstrucoes(C): A sequência LLLLLLLNNNNN possui 12 comandos.
    printf("Quantidade de instrucoes: %d\n", ContarInstrucoes(C));

    // Teste da função DestruirCaminho(C): o resultado esperado envolve a liberação de toda a memória alocada para o caminho, posições e comandos
    DestruirCaminho(C);

    return 0;
}