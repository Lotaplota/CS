#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int Chave;
    struct Item * Anterior;
} Item;

typedef struct Pilha
{
    int Tamanho;
    struct Item * Topo;
} Pilha;

// Protohtipos
Item * CriarItem(int);
Pilha * CriarPilha();
void Empilhar(Pilha *, Item *);
void Desempilhar(Pilha *);
void ExibirPilha(Pilha *);

int main(void)
{
    system("cls");

    Pilha * pi = CriarPilha();

    Empilhar(pi, CriarItem(137));
    Empilhar(pi, CriarItem(216));
    Empilhar(pi, CriarItem(419));
    Empilhar(pi, CriarItem(357));

    ExibirPilha(pi);

    Desempilhar(pi);

    ExibirPilha(pi);
}

Item * CriarItem(int c)
{
    Item * I = (Item *) malloc(sizeof(Item));

    I->Anterior = NULL;
    I->Chave = c;

    return I;
}

Pilha * CriarPilha()
{
    Pilha * p = (Pilha *) malloc(sizeof(Pilha));

    p->Tamanho = 0;
    p->Topo = NULL;

    return p;
}

void Empilhar(Pilha * p, Item * I)
{
    if (!p || !I)
    { perror("Naum hah pilha ou item."); return; }

    I->Anterior = p->Topo;
    p->Topo = I;
    p->Tamanho++;
}

void ExibirPilha(Pilha * p)
{
    printf("Pilha com %i elementos.\n", p->Tamanho);

    Item * atual = p->Topo;

    while (atual)
    {
        printf("%X\t%i\n", atual, atual->Chave);
        atual = atual->Anterior;
    }
}

void Desempilhar(Pilha * p)
{
    if (p->Tamanho <= 0)
    {
        perror("A pilha jah estah vazia");
        return;
    }

    Item * del = p->Topo;

    p->Topo = p->Topo->Anterior;
    p->Tamanho--;

    free(del);
}