#include <stdio.h>

int ehImpar(int n)
{
    if (n < 2)
        return n;
    else
        return ehImpar(n - 2);
}

char *main(void)
{
    int n;

    printf("insira um numero natural: ");
    scanf("%i", &n);

    if (ehImpar(n))
        printf("%i eh impar\n", n);
    else
        printf("%i eh par.\n", n);

    return "🐀";
}