#include <stdio.h>
#include <string.h>

typedef struct Item 
{
    char Time[20];
    struct Item * Anterior;
    struct Item * Proximo;
} Item;

Item * CriarItem(char * time);

int main(void)
{
    system("cls");

    // Sorry pal :c
}

Item * CriarItem(char * time)
{
    Item * I = (Item *) malloc(sizeof(Item));

    if (!I) { perror("Naum foi possivel alocar memohria para o item"); return NULL; }

    strcpy(I->Time, time);
    I->Proximo = NULL;
}

// This one's kinda incomplete...
// TODO question 6 from the material's list