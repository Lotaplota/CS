#ifndef DMNGR_H
#define DMNGR_H

#define MAX_ARQUIVOS 32
#define TAM_NOME_ARQUIVO 20

typedef struct
{
    char sigla_tribunal[9];
    char procedimento[32];
    char ramo_justica[32];
    char sigla_grau[5];
    char uf_oj[5];
    char municipio_oj[32];
    int id_ultimo_oj;
    char nome[32];
    char mesano_cnm1[16];
    char mesano_sent[16];
    int casos_novos_2026;
    int julgados_2026;
    int prim_sent2026;
    int suspensos_2026;
    int dessobrestados_2026;
    int cumprimento_meta1;
    int distm2_a;
    int julgm2_a;
    int suspm2_a;
    int cumprimento_meta2a;
    int distm2_ant;
    int julgm2_ant;
    int suspm2_ant;
    int desom2_ant;
    int cumprimento_meta2ant;
    int distm4_a;
    int julgm4_a;
    int suspm4_a;
    int cumprimento_meta4a;
    int distm4_b;
    int julgm4_b;
    int suspm4_b;
    int cumprimento_meta4b;
} LinhaDados;

typedef struct
{
    int s_julgados_2026;
    int s_casos_novos_2026;
    int s_dessobrestados_2026;
    int s_suspensos_2026;
    int s_julgm2_a;
    int s_distm2_a;
    int s_suspm2_a;
    int s_julgm2_ant;
    int s_distm2_ant;
    int s_suspm2_ant;
    int s_desom2_ant;
    int s_julgm4_a;
    int s_distm4_a;
    int s_suspm4_a;
    int s_julgm4_b;
    int s_distm4_b;
    int s_suspm4_b;
} Somas;

typedef struct
{
    char sigla_tribunal[9];
    int julgados_2026;
    float Meta1;
    float Meta2A;
    float Meta2Ant;
    float Meta4A;
    float Meta4B;
} LinhaResumo;

int ConcatArquivos(char *, char *);
void GerarResumo(char *, int);

#endif