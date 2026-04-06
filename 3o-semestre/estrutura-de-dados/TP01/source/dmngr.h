#ifndef DMNGR_H
#define DMNGR_H

#define MAX_ARQUIVOS 32      // Quantidade máxima de arquivos iniciais
#define TAM_NOME_ARQUIVO 20  // Tamanho máximo do nome dos arquivos iniciais

// Cabeçalho dos arquivos .csv que contém os dados
#define CABECALHO "\"sigla_tribunal\",\"procedimento\",\"ramo_justica\",\"sigla_grau\",\"uf_oj\",\"municipio_oj\",\"id_ultimo_oj\",\"nome\",\"mesano_cnm1\",\"mesano_sent\",\"casos_novos_2026\",\"julgados_2026\",\"prim_sent2026\",\"suspensos_2026\",\"dessobrestados_2026\",\"cumprimento_meta1\",\"distm2_a\",\"julgm2_a\",\"suspm2_a\",\"cumprimento_meta2a\",\"distm2_ant\",\"julgm2_ant\",\"suspm2_ant\",\"desom2_ant\",\"cumprimento_meta2ant\",\"distm4_a\",\"julgm4_a\",\"suspm4_a\",\"cumprimento_meta4a\",\"distm4_b\",\"julgm4_b\",\"suspm4_b\",\"cumprimento_meta4b\"\n"
// bem longo né professor...

// Interpolador de strings
extern char tmp[256];
#define scratch(s, ...) (snprintf(tmp, sizeof(tmp), s, __VA_ARGS__), tmp)
// ai q sdds de C#...

// Será utilizada para armazenar os dados de cada linha do arquivo de dados
typedef struct
{
    char sigla_tribunal[9];
    char procedimento[32];
    char ramo_justica[32];
    char sigla_grau[5];
    char uf_oj[5];
    char municipio_oj[64];
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

// Armazenará os somatórios dos valores escritos no arquivo de dados
// Será utilizada na geração das linhas do arquivo resumo
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

// Armazenará os dados a serem escritos nas linhas do arquivo resumo
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

// Funções do main.c
int ConcatArquivos(char *);
void GerarResumo(int);
char * gerarOcorrencias(char *);
void Bye();

#endif