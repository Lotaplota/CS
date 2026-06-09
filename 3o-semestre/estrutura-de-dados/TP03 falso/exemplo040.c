#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item
{
    char Chave[4];
    struct Item * Anterior;
} Item;

typedef struct Pilha
{
    int Tamanho;
    struct Item * Topo;
} Pilha;

// Protohtipos
Item * CriarItem(char *);
Pilha * CriarPilha();
void Empilhar(Pilha *, Item *);
void Desempilhar(Pilha *);
void ExibirPilha(Pilha *);

int main(void)
{
    system("cls");

    Pilha * pi = CriarPilha();

    Empilhar(pi, CriarItem("2"));
    Empilhar(pi, CriarItem("3"));
    Empilhar(pi, CriarItem("4"));
    Empilhar(pi, CriarItem("*"));
    Empilhar(pi, CriarItem("+"));
}

Item * CriarItem(char * c)
{
    Item * I = (Item *) malloc(sizeof(Item));

    I->Anterior = NULL;
    strcpy(I->Chave, c);

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

    printf("%i this is what strtol returned\n", strtol(I->Chave, NULL, 10)); // DONKEY
    if (!strtol(I->Chave, NULL, 10))
    {
        printf("%s is not a number!\n", I->Chave); // DONKEY 1
        Calcular(p, I->Chave);
    }

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
        printf("%X\t%s\n", atual, atual->Chave);
        atual = atual->Anterior;
    }
}

void Calcular(Pilha * p, char * operador)
{
    float a = strtol(p->Topo->Chave, NULL, 10);
    float b = strtol(p->Topo->Anterior->Chave, NULL, 10);
    float res = Operar(a, b, operador);

    Desempilhar(p);
    strcpy(p->Topo->Chave, ) // CONTINUE
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