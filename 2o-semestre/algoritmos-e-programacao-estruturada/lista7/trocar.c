#include <stdio.h>

#define TROCAR(a, b) { int aux = a; a = b; b = aux;}

char *main(void)
{
    int a = 1;
    int b = 2;

    TROCAR(a, b);

    printf("%i e %i\n", a, b);
}