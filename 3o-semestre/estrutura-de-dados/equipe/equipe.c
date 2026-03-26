#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

typedef struct {
    int posicao;
    char estado[TAM_STRING];
    char time[TAM_STRING];
    int pontos;
    int qt_jogos;
    int qt_vitorias;
    int qt_empates;
    int qt_derrotas;
    int qt_gols_pro;
    int qt_gols_con;
    int saldo_gols;
    float aproveitamento;
} Equipe;

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