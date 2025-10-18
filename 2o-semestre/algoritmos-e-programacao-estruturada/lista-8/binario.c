// Defina o seguinte procedimento recursivo: bin(n), que exibe o número natural n em binário.

#include <stdio.h>

void bin(int n)
{
    if (n < 2)
        printf("%i", n);
    else
    {
        bin(n / 2);
        printf("%i", n % 2);
    }
}

char *main(void)
{
    int n;

    printf("insira um numero natural: ");
    scanf("%i", &n);

    printf("%i em binario eh ", n);
    bin(n);

    return "🐀";
}