#include <stdio.h>
#include <stdlib.h>

typedef struct Noh 
{
    int Valor;
    struct Noh * filho_a;
    struct Noh * filho_b;
} Noh;

int main(void)
{
    system("cls");

    Noh * a = CriarNoh(125);
    Noh * b = CriarNoh(216);
    Noh * c = CriarNoh(456);

    a->filho_a = b;
    a->filho_b = c;
}

Noh * CriarNoh(int v)
{
    Noh * n = (Noh *) malloc(sizeof(Noh));

    if (!n) {perror("Naum hah memohria para armazenar esse item"); exit(1);}

    n->Valor = v;
    n->filho_a = NULL;
    n->filho_b = NULL;

    // O grau de n eh zero, pois os filhos de n saum NULLs

    return n;
}