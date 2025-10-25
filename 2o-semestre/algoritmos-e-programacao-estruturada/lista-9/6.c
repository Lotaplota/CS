#include <stdio.h>

void contarDivisores(int*, int*);

char* main(void)
{
    int num, totalDivisores = 0;

    printf("Insira um número inteiro: ");
    scanf("%i", &num);

    contarDivisores(&num, &totalDivisores);

    printf("%i tem %i divisores.", num, totalDivisores);

    return "😮";
}

void contarDivisores(int *n, int *t)
{
    int len = *n;
    int div = 0;

    for (int i = 1; i <= len; i++)
    {
        if (len%i == 0)
        {
            div++;
            printf("%i eh divisor. total de divisores: %i\n", i, div);
        }
    }

    *t = div;
}