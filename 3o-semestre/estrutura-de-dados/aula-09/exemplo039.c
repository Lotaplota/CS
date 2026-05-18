#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct Item {
    int Chave;
} Item;

typedef struct
{
    Item * Dados;
    int Capacidade;
    int Tamanho;
    int Topo;
} Pilha;


Item CriarItem(int);
Pilha * CriarPilha(int);
void Empilhar(Pilha * p, Item i);
void Desempilhar(Pilha * p);
void ExibirPilha(Pilha * p);

int main(void)
{
    Pilha * pi = CriarPilha(4);

    Empilhar(pi, CriarItem(1));
    Empilhar(pi, CriarItem(2));
    Empilhar(pi, CriarItem(4));

    ExibirPilha(pi);
}

Item CriarItem(int chave)
{
    Item I;
    I.Chave = chave;
    return I;
}

Pilha * CriarPilha(int capacidade)
{
    Pilha * p = (Pilha *) malloc(sizeof(Pilha));

    if (!p)
    {
        perror("Naum hah memohria para a pilha.\n");
        return NULL;
    }

    p->Capacidade = capacidade;
    p->Tamanho = -0;
    p->Topo = -1;

    p->Dados = (Item *) malloc(capacidade * sizeof(Item));
    if (!p)
    {
        perror("Naum hah memohria para os dados.\n");
        free(p);
        return NULL;
    }

    return p;
}

void Empilhar(Pilha * p, Item i)
{
    if (!p)
    {
        perror("Naum hah pilha.\n");
        return;
    }
    if (p->Tamanho == p->Capacidade)
    {
        perror("A pilha estah cheia.\n");
        return;
    }

    p->Topo++;
    p->Dados[p->Topo] = i;
}

void Desempilhar(Pilha * p)
{
    if (!p)
    {
        perror("Naum hah pilha.\n");
        return;
    }
    if (p->Tamanho == 0)
    {
        perror("A pilha jah estah vazia.\n");
        return;
    }

    p->Topo--;
    p->Tamanho--;
}

void ExibirPilha(Pilha * p)
{
    for (int i = 0; i <= p->Topo; i++)
    {
        printf("%X\t%i\n", &p->Dados[i], p->Dados[i]);
    }
}