#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
    int Chave;
} Item;

typedef struct {
    Item * Dados;
    int Inicio;
    int Fim;
    int Tamanho;
    int Capacidade;
} Fila;

Item CriarItem(int);
Fila * CriarFila(int);
void Enfileirar(Fila *, Item);
void Desenfileirar(Fila *);
void DestruirFila(Fila *);
void ExibirFila(Fila *);

// Implementação de uma fila usando ARRAY (os elementos da fila serão dispostos em um vetor)
int main(void)
{
    Fila * F = CriarFila(20);

    Enfileirar(F, CriarItem(10));
    Enfileirar(F, CriarItem(20));
    Enfileirar(F, CriarItem(30));
    Enfileirar(F, CriarItem(40));

    ExibirFila(F);

    DestruirFila(F);
}

Item CriarItem(int chave) {
    Item I;
    I.Chave = chave;
    return I;
}

Fila * CriarFila(int capacidade)
{
    Fila * F = (Fila *) malloc(sizeof(Fila));
    if (!F) {perror("Naum hah memohria para a fila.\n"); return NULL;}

    F->Capacidade = capacidade;
    F->Tamanho = 0;
    F->Inicio = -1; F->Fim = -1;

    F->Dados = malloc(capacidade * sizeof(Item));
    if (!F->Dados)
    {
        perror("Naum hah memohria para a fila.\n");
        free(F);
        return NULL;
    }

    return F;
}

void DestruirFila(Fila * f)
{
    free(f->Dados);
    free(f);
}

void Enfileirar(Fila * f, Item i)
{
    if (f->Fim == f->Capacidade - 1) return;
    if (f->Inicio == -1) f->Inicio = 0;

    f->Fim++;
    f->Dados[f->Fim] = i;
    f->Tamanho++;
}

void Desenfileirar(Fila * f) // was this supposed to be unfinished?
{
    f->Inicio = f->Inicio + 1;
    f->Tamanho--;
}

void ExibirFila(Fila * f)
{
    for (int i = f->Inicio; i <= f->Inicio; i++)
    {
        printf("dfadfa %i\n", f->Dados[i].Chave);
    }
}