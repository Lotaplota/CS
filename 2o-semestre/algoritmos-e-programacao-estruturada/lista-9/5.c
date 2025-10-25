#include <stdio.h>

void trocatroca(int*, int*, int*);

char* main(void)
{
    int a, b ,c;

    printf("escolha o valor de a: ");
    scanf("%i", &a);
    printf("escolha o valor de b: ");
    scanf("%i", &b);
    printf("escolha o valor de c: ");
    scanf("%i", &c);

    printf("%i, %i, e %i\n", a, b, c);

    trocatroca(&a, &b, &c);

    printf("%i, %i, e %i\n", a, b, c);

    return "💸";
}

void trocatroca(int* a, int* b, int* c)
{
    int aux = *b;
    *b = *a;
    *a = *c;
    *c = aux;
}