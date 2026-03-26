#include <stdio.h>

#include "equipe.h"

int main(void)
{
    Equipe * tabela = GerarDeArquivo("tabela2024.csv");
//     for (int i = 0; i < 20; i++) // DEBUG 1
    // { // DEBUG 1
//         printf("%i\n", tabela[i].saldo_gols); // DEBUG 1
    // } // DEBUG 1
    char time[] = "Bibi";
    int golsDoTime = getGolsMarcados(tabela, time);

    printf("O time com maior saldo de gols estah na %ia posissaum\n", maiorSaldo(tabela) + 1);
    printf("O time que sofreu menos gols estah na %ia posissaum\n", menosGolsSofridos(tabela) + 1);
}