#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int chave;
    struct Item * Proximo; // Ponteiro para o próximo item da lista
    
} Item;

typedef struct Lista
{
    Item * Inicio;
    int Tamanho;
} Lista;

Item * CriarItem(int chave)
{
    Item * I = (Item *) malloc(sizeof(Item));

    if (!I) { perror("Naum foi possivel alocar memohria para o item"); return NULL; }

    I->chave = chave;
    I->Proximo = NULL;
}

Lista * CriarLista()
{
    Lista * L = (Lista *) malloc(sizeof(Lista));
    if (!L) {perror("ponteiro eh nulo"); return NULL;}

    L->Tamanho = 0;
    L->Inicio = NULL;

    return L;
}

int main(void)
{
    system("cls");

    Item * A = CriarItem(25);
    Item * B = CriarItem(36);
    Item * C = CriarItem(40);
    Item * D = CriarItem(10);

    A->Proximo = C;
    C->Proximo = D;
    D->Proximo = B;

    Lista * MinhaLista = CriarLista();

    return 0;
}