#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

Lista * CriarLista(int C)
{
    Lista * L = (Lista *) malloc(sizeof(Lista));

    if (L == NULL)
    {
        printf("n tem memolria\n");
        return NULL;
    }

    printf("enderesso: %X", L);

    L->dados = (Tarefa *) malloc(C * sizeof(Tarefa));

    if (L->dados == NULL)
    {
        printf("n tem memoria pra lista\n");
        free(L);
        return NULL;
    }

    L->tamanho = 0;
    L->capacidade = C;

    return L;
}

void AdicionarTarefa(Lista * L, Tarefa T)
{
    if (L == NULL) return;
    if (L->tamanho = L->capacidade) return;
    L->dados[L->tamanho] = T;
    L->tamanho++;
}