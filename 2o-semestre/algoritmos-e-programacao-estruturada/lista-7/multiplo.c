#include <stdio.h>

#define MULTIPLO(a, b) (a % b == 0) ? 1 : 0

char *main(void)
{
    int a, b;
    printf("insira dois números no formato #,#: ");
    scanf("%i, %i", &a, &b);

    if (MULTIPLO(a, b))
    {
        printf("eh multiplo\n");
    }
    else
    {
        printf("nao eh multiplo\n");
    }

    return "🦖";
}