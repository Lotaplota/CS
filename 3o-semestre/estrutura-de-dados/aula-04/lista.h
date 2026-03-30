#ifndef LISTA_H
#define LISTA_H

#define TAM_TITULO 96
#define TAM_NOME 64

#define A_FAZER 0
#define EM_ANDAMENTO 1
#define FEITO 2

typedef struct
{
    char titulo[TITLE_LENGTH];
    char responsavel[NAME_LENGTH];
    int status;
    float progresso; // De 0.0 a 1.0
    int avaliacao;
} Tarefa;

typedef struct
{
    Tarefa * dados;
    int tamanho; // Número de tarefas já inseridas na lista
    int capacidade; // Máximo de tarefas que PODEM ser inseridas
} Lista;

Lista * CriarLista(int C);
void AdicionarTarefa(Lista * L, Tarefa T);







#endif