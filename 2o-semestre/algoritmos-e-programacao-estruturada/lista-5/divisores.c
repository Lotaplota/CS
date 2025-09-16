// Escreva um programa que leia um número N e calcule a soma de seus divisores, excluindo o próprio número. A estrutura while deve ser utilizada para verificar os divisores.
#include <stdio.h>

char *main(void)
{
    int n, soma = 1;

    printf("insira um numero inteiro: ");
    scanf("%i", &n);

    int div = 2;

    while (div <= n/2)
    {
        if (n%div == 0)
        {
            soma += div;
        }

        div++;
    }

    printf("a soma dos divisores eh: %i", soma);

    return "🦒";
}