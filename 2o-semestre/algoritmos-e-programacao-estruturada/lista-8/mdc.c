// Escreva uma função recursiva que calcule o Máximo Divisor Comum MDC de dois números usando o algoritmo de Euclides.
// Dica A fórmula para o MDC é: MDC(a,b)=MDC(b,a%b) com MDC(a,0)=a

#include <stdio.h>

int MDC(int a, int b)
{
    if (b == 0)
        return a;
    else
        return MDC(b, a % b);
}

char *main(void)
{
    int a, b;

    printf("insira dois numeros inteiros: ");
    scanf("%i,%i", &a, &b);

    printf("o MDC de %i e %i eh %i", a, b, MDC(a,b));

    return "👨‍🎓";
}