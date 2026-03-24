#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int posicao;
    char estado[32];
    char nome[32];
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
            equipes[n].nome,
            &equipes[n].pontos,
            &equipes[n].qt_jogos,
            &equipes[n].qt_vitorias,
            &equipes[n].qt_empates,
            &equipes[n].qt_derrotas,
            &equipes[n].qt_gols_pro,
            &equipes[n].qt_gols_con,
            &equipes[n].saldo_gols
        );
        printf("%i\n", equipes[9].qt_derrotas); // DONKEY

        n++;
    }

    fclose(arq);

    return equipes;
}

int main(void)
{
    Equipe * tabela = GerarDeArquivo("tabela2024.csv");
    printf("%i", tabela[6].qt_gols_pro); // DONKEY
}