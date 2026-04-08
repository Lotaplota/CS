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

    printf("%X \t %d \t %X \n", I, I->chave, I->Proximo);
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

    return 0;
}