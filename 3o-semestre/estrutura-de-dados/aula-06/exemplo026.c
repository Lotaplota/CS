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
    printf("\n");

    for ( Item * atual = inicio; atual != NULL; atual = atual->Proximo)
        printf("%X \t %d \t %X \n", atual, atual->chave, atual->Proximo);
}

int ContarPares(Item * inicio)
{
    Item * atual = inicio;
    int contador = 0;

    while (inicio != NULL)
    {
        if (inicio->chave % 2 == 0) contador++;
            atual = atual->Proximo;
    }

    return contador;
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

    ExibirLista(A, 4);
    printf("A lista contehm %i nuhmeros pares.\n", ContarPares(A));

    return 0;
}