#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculadora.h"

typedef struct Item
{
    char Chave[4];
    struct Item * Anterior;
} Item;

typedef struct Pilha
{
    struct Item * Topo;
    int Tamanho;
} Pilha;

Item * CriarItem(char * chave)
{
    Item * it = (Item *) malloc(sizeof(Item));

    if (!it) { perror("Naum hah memohria para um novo item"); return NULL; }

    strcpy(it->Chave, chave);
    it->Anterior = NULL;

    return it;
}

Pilha * CriarPilha()
{
    Pilha * p = (Pilha *) malloc(sizeof(Pilha));

    if (!p) { perror("Naum hah memohria para uma nova pilha"); return NULL; }

    p->Tamanho = 0;
    p->Topo = NULL;

    return p;
}

void Empilhar(Pilha * p, Item * novo)
{
    novo->Anterior = p->Topo;
    p->Topo = novo;
    p->Tamanho++;
}

void ExibirPilha(Pilha * p)
{
    printf("Pilha de tamanho %i\n", p->Tamanho);

    int index = 1;

    for (Item * atual = p->Topo; atual != NULL; atual = atual->Anterior)
    {
        printf("%i.\t%s\n", index, atual->Chave);
        index++;
    }
}

float getValor(char * Str)
{
    Pilha * P = CriarPilha();

    for (char * token = strtok(Str, " "); token != NULL; token = strtok(NULL, " "))
    {
        Item * item = CriarItem(token);
        Empilhar(P, item);
    }

    ExibirPilha(P);
}