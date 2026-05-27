#include <stdio.h>
#include <stdlib.h>

#define QT_FILHOS 6

typedef struct Noh 
{
    int Valor;
    struct Noh * filho[QT_FILHOS];
} Noh;

int main(void)
{
    system("cls");

    
}

Noh * CriarNoh(int v)
{
    Noh * n = (Noh *) malloc(sizeof(Noh));

    if (!n) {perror("Naum hah memohria para armazenar esse item"); exit(1);}

    n->Valor = v;
    
    for (int i; i < QT_FILHOS; i++) n->filho[i] = NULL;

    // O grau de n eh zero, pois os filhos de n saum NULLs

    return n;
}