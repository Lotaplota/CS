#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

Equipe * GerarDeArquivo(char * filename)
{
    FILE * arq = fopen(filename, "r");

    Equipe * equipes = malloc(20 * sizeof(Equipe));

    char buffer[1024];
    int n = 0;

    fgets(buffer, sizeof(buffer), arq);
    while (fgets(buffer, sizeof(buffer), arq) != NULL)
    {
        sscanf(buffer, "%i,%[^,],%[^,],%i,%i,%i,%i,%i,%i,%i,%i",
            &equipes[n].posicao,
            equipes[n].estado,
            equipes[n].time,
            &equipes[n].pontos,
            &equipes[n].qt_jogos,
            &equipes[n].qt_vitorias,
            &equipes[n].qt_empates,
            &equipes[n].qt_derrotas,
            &equipes[n].qt_gols_pro,
            &equipes[n].qt_gols_con,
            &equipes[n].saldo_gols
        );

    equipes[n].aproveitamento = 100 * equipes[n].pontos / (3 * equipes[n].qt_jogos);

        n++;
    }

    fclose(arq);

    return equipes;
}

int getGolsMarcados(Equipe * tb, char * time)
{
    for (int i = 0; i < 20; i++)
    {
        if (!strcmp(tb[i].time, time))
        {
            return tb[i].qt_gols_pro;
        }
    }

    printf("%s was not found in the list.\n", time);
    return -1;
}

int maiorSaldo(Equipe * tb)
{
    int max = 0;
    int pos = -1;

    for (int i = 0; i < TAM_TABELA; i++)
    {
        if (tb[i].saldo_gols > max)
        {
            max = tb[i].saldo_gols;
            pos = i;
        }
    }

    return pos;
}

int menosGolsSofridos(Equipe * tb)
{
    int min = INT_MAX;
    int pos = -1;

    for (int i = 0; i < TAM_TABELA; i++)
    {
        if (tb[i].qt_gols_con < min)
        {
            min = tb[i].qt_gols_con;
            pos = i;
        }
    }

    return pos;
}