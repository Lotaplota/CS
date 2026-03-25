#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

int main(void)
{
    // Usando a struct tarefa

    // SEM PONTEIRO
    Tarefa t1 = {"tarefinha", "eu_mesmo", EM_ANDAMENTO, .4, 2};
    printf("%s; %s; %i; %f; %i\n", t1.titulo, t1.responsavel, t1.status, t1.progresso, t1.avaliacao); // DONKEY

    // COM PONTEIRO
    Tarefa * t2 = (Tarefa *) malloc(sizeof(Tarefa));

    strcpy(t2->titulo, "testar variáveis");
    strcpy(t2->responsavel, "meua_migo");
    t2->status = FEITO;
    t2->progresso = 1;
    t2->avaliacao = 3;
    printf("%s; %s; %i; %f; %i", t2->titulo, t2->responsavel, t2->status, t2->progresso, t2->avaliacao); // DONKEY
}