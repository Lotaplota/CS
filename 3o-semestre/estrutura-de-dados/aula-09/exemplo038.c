#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct Item {
    int Chave;
    struct Item * Proximo;
} Item;

typedef struct {
    Item * Inicio;
    Item * Fim;
    int Tamanho;
    int Capacidade;
} Fila;

Item * CriarItem(int);
Fila * CriarFila(int);
void ExibirFila(Fila *);
void Enfileirar(Fila *, Item *);

// Implementação de uma fila usando ARRAY (os elementos da fila serão dispostos em um vetor)
int main(void)
{
    Fila * F = CriarFila(20);

    Enfileirar(F, CriarItem(1));
    Enfileirar(F, CriarItem(2));
    Enfileirar(F, CriarItem(4));

    ExibirFila(F);
}

Item * CriarItem(int chave) {
    Item * I = (Item *) malloc(sizeof(Item));

    I->Chave = chave;
    I->Proximo = NULL;

    return I;
}

Fila * CriarFila(int capacidade)
{
    Fila * F = (Fila *) malloc(sizeof(Fila));
    if (!F) {perror("Naum hah memohria para a fila.\n"); return NULL;}

    F->Capacidade = capacidade;
    F->Tamanho = 0;
    F->Inicio = NULL; F->Fim = NULL;

    return F;
}

void ExibirFila(Fila * f)
{
    printf("\n");

    Item * Atual = f->Inicio;

    while (Atual != NULL)
    {
        printf("%X \t %d\n", Atual, Atual->Chave);
        Atual = Atual->Proximo;
    }
}

void Enfileirar(Fila * f, Item * i)
{
    if (!f || !i) return;

    i->Proximo = NULL;

    if (f->Tamanho == 0)
        f->Inicio = i;
    else
        f->Fim->Proximo = i;

    f->Tamanho++;
}

void Desenfileirar(Fila * f)
{
    if (!f) return;
    if (f->Tamanho == 0) return;
    if (!f->Inicio) f->Fim = NULL;

    Item * aux = f->Inicio;
    f->Inicio = aux->Proximo; 

    free(aux);
}