// Implemente uma função recursiva que calcule a soma dos dígitos de um número inteiro positivo.
// Entrada Um número inteiro positivo n.
// Saída A soma dos dígitos de n.

#include <stdio.h>

int soma(int n)
{
    if (n % 10 == n)
    {
        return n;
    }
    else
    {
        return n % 10 + soma(n / 10);
    }
}

char *main(void)
{
    int a;

    printf("insira um numero natural: ");
    scanf("%i", &a);

    printf("a soma dos algarismos de %i eh %i.\n", a, soma(a));

    return "🦮";
}