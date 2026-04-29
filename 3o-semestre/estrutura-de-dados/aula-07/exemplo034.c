#include <stdio.h>
#include <string.h>

typedef struct Item 
{
    char Titulo[50];
    char Autor[100];
    int Ano;

    FILE * Letra;
    struct Item * Anterior;
    struct Item * Proximo;
} Item;

typedef Item Musica; // Musica eh um apelido para Item

Item * CriarItem(char *, char *, int);

int main(void)
{
    Musica * m1 = CriarItem("Aquarela", "Toquinho", 1983);
    Musica * m2 = CriarItem("Romaria", "Renato Teixeira", 1978);
    Musica * m3= CriarItem(Eu   nasci   há   dez   mil   anos   atrás ”,   escrita   por   “ Raul   Seixas ”   em   1976 );
    Musica * m4 = CriarItem("Cálice", "Chico Buarque e Gilberto Gil", 1978);
    Musica * m5 = CriarItem(""); // TODO FIX THIS DUDE
}

Item * CriarItem(char * titulo, char * autor, int ano)
{
    Item * I = (Item *) malloc(sizeof(Item));

    if (!I) { perror("Naum foi possivel alocar memohria para o item"); return NULL; }

    strcpy(I->Titulo, titulo);
    strcpy(I->Autor, autor);
    I->Ano = ano;
    I->Proximo = NULL;
}

void ExibirLista(Item * I)
{
    Item * atual = I;
    // Didn't get the rest of the part
}