#ifndef EQUIPE_H
#define EQUIPE_H

#define TAM_STRING 32
#define TAM_TABELA 20

typedef struct {
    int posicao;
    char estado[32];
    char time[32];
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

Equipe * GerarDeArquivo(char *);
int getGolsMarcados(Equipe *, char *);
int maiorSaldo(Equipe *);
int menosGolsSofridos(Equipe *);

#endif