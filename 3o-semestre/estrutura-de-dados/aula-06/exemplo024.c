#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int chave;
    struct Item * Proximo; // Ponteiro para o próximo item da lista
    
} Item;

Item * CriarItem(int chave)
{
    Item * I = (Item *) malloc(sizeof(Item));

    if (!I) { perror("Naum foi possivel alocar memohria para o item"); return NULL; }

    I->chave = chave;
    I->Proximo = NULL;
}

void ExibirLista(Item * inicio, int tamanho)
{
    Item * atual = inicio;

    printf("\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("%X \t %d \t %X \n", atual, atual->chave, atual->Proximo);
        atual = atual->Proximo;
    }
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
    D->Proximo = A;

    ExibirLista(A, 4);

    return 0;
}