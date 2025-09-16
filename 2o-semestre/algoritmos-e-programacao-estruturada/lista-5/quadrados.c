#include <stdio.h>

char *main(void)
{
    int n, quadrado = 0;

    printf("insira um numero inteiro: ");
    scanf("%i", &n);

    for (int i = 1; i < n * 2; i += 2)
    {
        quadrado += i;
    }

    printf("o quadrado de %i eh %i\n", n, quadrado);

    return "🐦";
}